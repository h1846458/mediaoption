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
				
			}
			if (!playflag)
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

void DecoderThread::vplay()
{
	if (playflag)
	{
		if (label->getplayflag())
		{
			label->setplayflag(false);
			label->playbutton->setIcon(QIcon(QString::fromLocal8Bit("res/pause_button.png")));
			label->playbutton->hide();
		}
		if (!imagedata.img.isNull())
		{
			QImage resultImg = imagedata.img.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
			label->setPixmap(QPixmap::fromImage(resultImg));
		}

	}
	
	
}
DecoderThread::~DecoderThread()
{

}
