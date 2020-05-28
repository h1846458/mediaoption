/*
	It is FFmpeg decoder class. Sample for article from unick-soft.ru
*/

#include "ffmpegDecode.h"

#define min(a,b) (a > b ? b : a)

#define MAX_AUDIO_PACKET (2 * 1024 * 1024)

void FFmpegDecoder::ffmpeginit()
{
	av_register_all();
	avformat_network_init();
	av_log_set_level(AV_LOG_DEBUG);
}

int FFmpegDecoder::interrupt_cb(void* ctx)
{
	int  timeout = 10;
	//if (av_gettime_relative() - lastReadPacktTime > timeout * 1000 * 1000)
	//{
		//return -1;
	//}
	return 0;
}

bool FFmpegDecoder::Open(std::string& inputFile)
{
	Close();

	// Register all components
	this->ffmpeginit();
	pFormatCtx = avformat_alloc_context();
	pFormatCtx->interrupt_callback.opaque = this;
	pFormatCtx->interrupt_callback.callback = interrupt_cb;
	//lastReadPacktTime = av_gettime_relative();
	AVDictionary* options = nullptr;
	av_dict_set(&options, "rtsp_transport", "tcp", 0);  //以udp方式打开，如果以tcp方式打开将udp替换为tcp
	av_dict_set(&options, "stimeout", "3000000", 0);     //设置超时断开连接时间
	// Open media file.
	if (avformat_open_input(&pFormatCtx, inputFile.c_str(), NULL, &options) != 0)
	{
		
		Close();
		return false;
	}

	// Get format info.
	if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
	{
		Close();
		return false;
	}

	// open video and audio stream.
	bool hasVideo = OpenVideo();
	bool hasAudio = OpenAudio(); 

	if (!hasVideo)
	{
		Close();
		return false;
	}

	isOpen = true;

	// Get file information.
	if (videoStreamIndex != -1)
	{
		videoFramePerSecond = av_q2d(pFormatCtx->streams[videoStreamIndex]->r_frame_rate);

		// Need for convert time to ffmpeg time.
		videoBaseTime = av_q2d(pFormatCtx->streams[videoStreamIndex]->time_base); 
	}

	if (audioStreamIndex != -1)
	{
		audioBaseTime = av_q2d(pFormatCtx->streams[audioStreamIndex]->time_base);
	}

	return true;
}

bool FFmpegDecoder::OpenFile(std::string& inputurl, std::string proc)
{
	AVDictionary* options = nullptr;
	av_dict_set(&options, "rtsp_transport", proc.c_str(), 0);

	if (avformat_open_input(&pFormatCtx, inputurl.c_str(), nullptr, &options) != 0)
	{
		//av_strerror();
		av_log(NULL, AV_LOG_ERROR, "Input file open input failed\n");
		return  false;
	}
	
	if (avformat_find_stream_info(pFormatCtx, nullptr) !=0)
	{
		av_log(NULL, AV_LOG_ERROR, "Find input file stream inform failed\n");
		return false;
	}
	else
	{
		av_log(NULL, AV_LOG_FATAL, "Open input file  %s success\n", inputurl.c_str());
	}
	return true;
}

bool FFmpegDecoder::OpenOutput(std::string& outputurl)
{
	if (avformat_alloc_output_context2(&outputContext, nullptr, "RTSP", outputurl.c_str()) !=0)
	{
		av_log(NULL, AV_LOG_ERROR, "open output context failed\n");
		goto Error;
	}

	outputContext->max_interleave_delta = 1000000;

	/*if (avio_open2(&outputContext->pb, outputurl.c_str(), AVIO_FLAG_READ_WRITE, nullptr, nullptr) != 0)
	{
		av_log(NULL, AV_LOG_ERROR, "open avio failed");
		goto Error;

	}*/

	for (int i = 0; i < pFormatCtx->nb_streams; i++)
	{
		AVStream* stream = avformat_new_stream(outputContext, pFormatCtx->streams[i]->codec->codec);
		stream->time_base = { 1, 25 };
		if (avcodec_copy_context(stream->codec, pFormatCtx->streams[i]->codec) != 0)
		{
			av_log(NULL, AV_LOG_ERROR, "copy coddec context failed");
			goto Error;
			
		}
	}

	if (avformat_write_header(outputContext, nullptr) != 0)
	{
		av_log(NULL, AV_LOG_ERROR, "format write header failed");
		goto Error;
		
	}
	av_log(NULL, AV_LOG_FATAL, " Open output file success %s\n", outputurl.c_str());
	return true;
Error:
	if (outputContext)
	{
		for (int i = 0; i < outputContext->nb_streams; i++)
		{
			avcodec_close(outputContext->streams[i]->codec);
		}
		avformat_close_input(&outputContext);
	}
	return false;
}

bool FFmpegDecoder::Close()
{
	isOpen = false;

	// Close video and audio.
	CloseVideo();
	CloseAudio();

	if (pFormatCtx)
	{
		avformat_free_context(pFormatCtx);
		pFormatCtx = NULL;
	}

	return true;
}


void FFmpegDecoder::GetNextFrame(cv::Mat &res)
{

	if (videoStreamIndex != -1)
	{
		AVFrame* pVideoYuv = av_frame_alloc();
		//shared_ptr<AVPacket> packet = nullptr;
		AVPacket packet;

		if (isOpen)
		{
			// Read packet.
			if(av_read_frame(pFormatCtx, &packet) >= 0)
			{
				int64_t pts = 0;
				pts = (packet.dts != AV_NOPTS_VALUE) ? packet.dts : 0;

				if(packet.stream_index == videoStreamIndex)
				{
					// Convert ffmpeg frame timestamp to real frame number.
					int64_t numberFrame = (double)((int64_t)pts - pFormatCtx->streams[videoStreamIndex]->start_time) *  videoBaseTime * videoFramePerSecond; 

					// Decode frame
					bool isDecodeComplite = DecodeVideo(&packet, pVideoYuv);
					if (isDecodeComplite)
					{
						GetRGBAFrame(pVideoYuv, res);
						
					}
					//break;
				} 
				else if (packet.stream_index == audioStreamIndex)
				{
					if (packet.dts != AV_NOPTS_VALUE)
					{
						int audioFrameSize = MAX_AUDIO_PACKET;
						uint8_t * pFrameAudio = new uint8_t[audioFrameSize];
						if (pFrameAudio)
						{
							double fCurrentTime = (double)(pts - pFormatCtx->streams[videoStreamIndex]->start_time) * audioBaseTime;
							double fCurrentDuration = (double)packet.duration * audioBaseTime;

							// Decode audio
							int nDecodedSize = DecodeAudio(audioStreamIndex, &packet, pFrameAudio, audioFrameSize);

							if (nDecodedSize > 0 && pAudioCodecCtx->sample_fmt == AV_SAMPLE_FMT_FLTP)
							{
								// Process audio here.
								/* Uncommend sample if you want write raw data to file.
								{
									int size = nDecodedSize / sizeof(float);
									signed short * ar = new signed short[nDecodedSize / sizeof(float)];
									float* pointer = (float*)pFrameAudio;
									// Convert float to S16.
									for (int i = 0; i < size / 2; i ++)
									{
										ar[i] = pointer[i] * 32767.0f;
									}

									FILE* file = fopen("c:\\temp\\AudioRaw.raw", "ab");
									fwrite(ar, 1, size * sizeof (signed short) / 2, file);
									fclose(file);
								}
								*/
							}
							
							// Delete buffer.
							delete[] pFrameAudio;
							pFrameAudio = NULL;
						}
					}
				}
				av_free_packet(&packet);
				av_freep(&pVideoYuv);
				packet = AVPacket();
			}

			av_free(pVideoYuv);
		}    
	}
}


void FFmpegDecoder::GetRGBAFrame(AVFrame *pFrameYuv, cv::Mat &pCvMat)
{
	AVFrame * frame = NULL;
	int width  = pVideoCodecCtx->width;
	int height = pVideoCodecCtx->height;
	int bufferImgSize = avpicture_get_size(AV_PIX_FMT_BGR24, width, height);
	frame = av_frame_alloc();
	uint8_t * buffer = (uint8_t*)av_mallocz(bufferImgSize);
	if (frame)
	{
		avpicture_fill((AVPicture*)frame, buffer, AV_PIX_FMT_BGR24, width, height);
		//frame->width  = width;
		//frame->height = height;
		//frame->data[0] = buffer;

		sws_scale(pImgConvertCtx, pFrameYuv->data, pFrameYuv->linesize, 0, height, frame->data, frame->linesize); 
		//av_free(frame->data[0]);
		av_frame_free(&frame);
	}
	
	if (pCvMat.empty())
	{
		pCvMat.create(cv::Size(width, height), CV_8UC3);
	}
	memcpy(pCvMat.data, buffer, bufferImgSize);
	av_freep(&buffer);
	

}

void FFmpegDecoder::GetRGBAFrame(AVFrame* pFrameYuv, QImage& image)
{
	AVFrame* frame = NULL;
	int width = pVideoCodecCtx->width;
	int height = pVideoCodecCtx->height;
	int bufferImgSize = avpicture_get_size(AV_PIX_FMT_RGBA, width, height);
	frame = av_frame_alloc();
	uint8_t* buffer = (uint8_t*)av_mallocz(bufferImgSize);
	if (frame)
	{
		avpicture_fill((AVPicture*)frame, buffer, AV_PIX_FMT_BGR24, width, height);
		//frame->width  = width;
		//frame->height = height;
		//frame->data[0] = buffer;

		sws_scale(pImgConvertCtx, pFrameYuv->data, pFrameYuv->linesize, 0, height, frame->data, frame->linesize);
		//av_free(frame->data[0]);
		av_frame_free(&frame);
	}
}


shared_ptr<AVPacket> FFmpegDecoder::ReadPacketFromSource()
{
	shared_ptr<AVPacket> packet(static_cast<AVPacket*>(av_malloc(sizeof(AVPacket))), [&](AVPacket* p) { av_packet_free(&p); av_freep(&p); });
	av_init_packet(packet.get());
	int ret = av_read_frame(pFormatCtx, packet.get());
	if (ret >= 0)
	{
		return packet;
	}
	else
	{
		return nullptr;
	}
}

void FFmpegDecoder::av_packet_rescale_ts(AVPacket* pkt, AVRational src_tb, AVRational dst_tb)
{
	if (pkt->pts != AV_NOPTS_VALUE)
	{
		pkt->pts = av_rescale_q(pkt->pts, src_tb, dst_tb);
	}
		
	if (pkt->dts != AV_NOPTS_VALUE)
	{
		pkt->dts = av_rescale_q(pkt->dts, src_tb, dst_tb);
	}

	if (pkt->duration > 0)
	{
		pkt->duration = av_rescale_q(pkt->duration, src_tb, dst_tb);
	}
		
}

int FFmpegDecoder::WritePacket(shared_ptr<AVPacket> packet)
{
	auto inputStream = pFormatCtx->streams[packet->stream_index];
	auto outputStream = outputContext->streams[packet->stream_index];
	av_packet_rescale_ts(packet.get(), inputStream->time_base, outputStream->time_base);
	return av_interleaved_write_frame(outputContext, packet.get());
}

bool FFmpegDecoder::OpenVideo()
{
	bool res = false;

	if (pFormatCtx)
	{
		videoStreamIndex = -1;

		for (unsigned int i = 0; i < pFormatCtx->nb_streams; i++)
		{
			if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
			{
				videoStreamIndex = i;
				pVideoCodecCtx = pFormatCtx->streams[i]->codec;
				pVideoCodec = avcodec_find_decoder(pVideoCodecCtx->codec_id);

				if (pVideoCodec)
				{
					res     = !(avcodec_open2(pVideoCodecCtx, pVideoCodec, NULL) < 0);
					width   = pVideoCodecCtx->coded_width;
					height  = pVideoCodecCtx->coded_height;
				}

				break;
			}
		}

		if (!res)
		{
			CloseVideo();
		}
		else
		{
			pImgConvertCtx = sws_getContext(pVideoCodecCtx->width, pVideoCodecCtx->height, pVideoCodecCtx->pix_fmt, 
				   pVideoCodecCtx->width, pVideoCodecCtx->height, AV_PIX_FMT_BGR24, SWS_BICUBIC, NULL, NULL, NULL);
		}
	}

	return res;
}

bool FFmpegDecoder::DecodeVideo(const AVPacket *avpkt, AVFrame * pOutFrame)
{
	bool res = false;

	if (pVideoCodecCtx)
	{
		if (avpkt && pOutFrame)
		{
			int got_picture_ptr = 0;
			int videoFrameBytes = avcodec_decode_video2(pVideoCodecCtx, pOutFrame, &got_picture_ptr, avpkt);

//			avcodec_decode_video(pVideoCodecCtx, pOutFrame, &videoFrameBytes, pInBuffer, nInbufferSize);
			res = (videoFrameBytes > 0);
		}
	}

	return res;
}


bool FFmpegDecoder::OpenAudio()
{
	bool res = false;

	if (pFormatCtx)
	{   
		audioStreamIndex = -1;

		for (unsigned int i = 0; i < pFormatCtx->nb_streams; i++)
		{
			if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO)
			{
				audioStreamIndex = i;
				pAudioCodecCtx = pFormatCtx->streams[i]->codec;
				pAudioCodec = avcodec_find_decoder(pAudioCodecCtx->codec_id);
				if (pAudioCodec)
				{
					res = !(avcodec_open2(pAudioCodecCtx, pAudioCodec, NULL) < 0);       
				}
				break;
			}
		}

		if (! res)
		{
			CloseAudio();
		}
	}

	return res;
}


void FFmpegDecoder::CloseVideo()
{
	if (pVideoCodecCtx)
	{
		avcodec_close(pVideoCodecCtx);
		pVideoCodecCtx = NULL;
		pVideoCodec = NULL;
		videoStreamIndex = 0;
	}
}


void FFmpegDecoder::CloseAudio()
{    
	if (pAudioCodecCtx)
	{
		avcodec_close(pAudioCodecCtx);
		pAudioCodecCtx   = NULL;
		pAudioCodec      = NULL;
		audioStreamIndex = 0;
	}  
}


int FFmpegDecoder::DecodeAudio(int nStreamIndex, const AVPacket *avpkt, uint8_t* pOutBuffer, size_t nOutBufferSize)
{
	int decodedSize = 0;

	int packetSize = avpkt->size;
	uint8_t* pPacketData = (uint8_t*) avpkt->data;

	while (packetSize > 0)
	{
		int sizeToDecode = nOutBufferSize;
		uint8_t* pDest = pOutBuffer + decodedSize;
		int got_picture_ptr = 0;
		AVFrame* audioFrame = av_frame_alloc();//avcodec_alloc_frame();

		int packetDecodedSize = avcodec_decode_audio4(pAudioCodecCtx, audioFrame, &got_picture_ptr, avpkt);

		if (packetDecodedSize > 0)
		{
			sizeToDecode = av_samples_get_buffer_size(NULL, audioFrame->channels,
                                                       audioFrame->nb_samples,
													   (AVSampleFormat)audioFrame->format, 1);

			// Currenlty we process only AV_SAMPLE_FMT_FLTP.
			if ((AVSampleFormat)audioFrame->format == AV_SAMPLE_FMT_FLTP)
			{
				// Copy each channel plane.
				for (int i = 0; i < audioFrame->channels; i++)
				{
					memcpy(pDest + i * sizeToDecode / audioFrame->channels, 
						audioFrame->extended_data[i], sizeToDecode / audioFrame->channels);
				}
			}
		}

		if (packetDecodedSize < 0)
		{
			decodedSize = 0;
			break;
		}

		packetSize -= packetDecodedSize;
		pPacketData += packetDecodedSize;

		if (sizeToDecode <= 0)
		{
			continue;
		}

		decodedSize += sizeToDecode;
		av_frame_free(&audioFrame);//avcodec_free_frame(&audioFrame);
		audioFrame = NULL;
	}	

	return decodedSize;
}