#include "DecoderThread.h"

DecoderThread::DecoderThread(QObject *parent): QThread(parent), url("")
{

}

void DecoderThread::run()
{
	 FFmpegDecoder decoder;

	if (decoder.Open(url))
	{
		for (;;)
		{
			QImage image;
			decoder.GetNextFrame(image);
			DecoderData data;
			data.nTimeStamp = QDateTime::currentMSecsSinceEpoch();
			data.img = image;
			if (imgdata.size() <= 5)
			{
				imgdata.enqueue(data);
			}
			if(imgdata.size() == 5)
			{
				imagedata = imgdata.dequeue();
			}
		}
	}
	else
	{
		std::cout << "Cannot open file " << url << std::endl;
	}
}

DecoderThread::~DecoderThread()
{

}
