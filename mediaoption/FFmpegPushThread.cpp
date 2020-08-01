#include "FFmpegPushThread.h"

FFmpegPushThread::FFmpegPushThread(QObject *parent): QThread(parent)
{
}

void FFmpegPushThread::run()
{
	FFmpegDecoder decoder;

	if (decoder.Open(url))
	{
		for (;;)
		{
			QImage image;
			decoder.GetNextFrame(image);
			if (!pusfflag)
			{
				break;
			}
			QThread::msleep(10);
		}
	}
	else
	{
		std::cout << "Cannot open file " << url << std::endl;
	}
}

FFmpegPushThread::~FFmpegPushThread()
{
}
