#include "DecoderThread.h"
#include <QAction>



DecoderThread::DecoderThread(QObject *parent): QThread(parent), url(""), playflag(true), label(nullptr)
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
				if (!image.isNull())
				{
					imgdata.enqueue(data);
				}
				
			}
			if(imgdata.size() == 5)
			{
				imagedata = imgdata.dequeue();
				QImage resultImg = imagedata.img.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
				label->setPixmap(QPixmap::fromImage(resultImg));
			}
			if (!playflag)
			{
				break;
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
