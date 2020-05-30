#ifndef __FFMPEG_DECODER__
#define __FFMPEG_DECODER__

#include "ffmpegInclude.h"
#include <string>
#include <QtGui\qimage.h>

class FFmpegDecoder
{ 
  // constructor.
  public: 
      FFmpegDecoder() : pImgConvertCtx(NULL), audioBaseTime(0.0), videoBaseTime(0.0), videoFramePerSecond(0.0), isOpen(false), audioStreamIndex(-1), videoStreamIndex(-1),
          pAudioCodec(NULL), pAudioCodecCtx(NULL), pVideoCodec(NULL), pVideoCodecCtx(NULL), pFormatCtx(NULL), outputContext(NULL){;}

  // destructor.
  public: virtual ~FFmpegDecoder() 
  {
    Close();
  }

  // Open file
  public: virtual bool Open(std::string& inputFile);

  public: virtual bool OpenFile(std::string& inputurl, std::string proc);

  public: virtual bool OpenOutput(std::string& outputurl);

  // Close file and free resourses.
  public: virtual bool Close();

  // Return next frame FFmpeg.
  public: virtual void GetNextFrame(cv::Mat &res);

  public: virtual void GetNextFrame(QImage& image);

  public:  shared_ptr<AVPacket> ReadPacketFromSource();
  
  public:  int WritePacket(shared_ptr<AVPacket> packet);

  public: int GetWidth()
  {
    return width;
  }

  public: int GetHeight()
  {
    return height;
  }

  private: void av_packet_rescale_ts(AVPacket* pkt, AVRational src_tb, AVRational dst_tb);

  private: void ffmpeginit();

  public: static int interrupt_cb(void* ctx);
  // open video stream.
  private: bool OpenVideo();

  // open audio stream.
  private: bool OpenAudio();

  // close video stream.
  private: void CloseVideo();

  // close audio stream.
  private: void CloseAudio();

  // return rgb image 
  private: void GetRGBAFrame(AVFrame *pFrameYuv, cv::Mat &pCvMat);

  private: void GetRGBAFrame(AVFrame* pFrameYuv, QImage &image);

  // Decode audio from packet.
  private: int DecodeAudio(int nStreamIndex, const AVPacket *avpkt, uint8_t* pOutBuffer, size_t nOutBufferSize);

  // Decode video buffer.
  private: bool DecodeVideo(const AVPacket *avpkt, AVFrame * pOutFrame);

         // FFmpeg file format.
  private: AVFormatContext* pFormatCtx;

  private: AVFormatContext* outputContext;

       // FFmpeg codec context.
  private: AVCodecContext* pVideoCodecCtx;

       // FFmpeg codec for video.
  private: AVCodec* pVideoCodec;

       // FFmpeg codec context for audio.
  private: AVCodecContext* pAudioCodecCtx;

       // FFmpeg codec for audio.
  private: AVCodec* pAudioCodec;

       // Video stream number in file.
  private: int videoStreamIndex;

       // Audio stream number in file.
  private: int audioStreamIndex;

       // File is open or not.
  private: bool isOpen;

       // Video frame per seconds.
  private: double videoFramePerSecond;

       // FFmpeg timebase for video.
  private: double videoBaseTime;

       // FFmpeg timebase for audio.
  private: double audioBaseTime;

       // FFmpeg context convert image.
  private: struct SwsContext* pImgConvertCtx;

       // Width of image
  private: int width;

       // Height of image
  private: int height;
       //Mat
  //public: static int64_t lastReadPacktTime;
  
};

#endif