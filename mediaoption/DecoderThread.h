#pragma once
#include <QThread>
#include "ffmpegDecode.h"
#include <QQueue>
#include "CommonStructHeader.h"
#include <qdatetime.h>
#include "PlayQlabel.h"
#include <qpixmap.h>
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
	void setFlag() { playflag = false; }
	void setLabel(PlayQlabel *lab) {label = lab;}
	void vplay();
	~DecoderThread();

private:
	QQueue<DecoderData> imgdata;
	DecoderData imagedata;
	PlayQlabel  *label;
	string url;
	bool playflag;
signals:

private slots:

};
