#pragma once

#include <QThread>
#include "ffmpegDecode.h"
#include <QQueue>
#include "CommonStructHeader.h"
#include <qdatetime.h>
using namespace cw;


class DecoderThread : public QThread
{
	Q_OBJECT

public:
	DecoderThread(QObject *parent);
	DecoderData getDecoderData() { return imagedata;}
	int getSize() { return imgdata.size(); }
	void run();
	void setUrl(string urls) { url = urls; }
	~DecoderThread();

private:
	QQueue<DecoderData> imgdata;
	DecoderData imagedata;
	string url;
signals:

private slots:

};
