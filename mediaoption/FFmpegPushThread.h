#pragma once

#include <QThread>
#include "ffmpegDecode.h"

class FFmpegPushThread : public QThread
{
	Q_OBJECT

public:
	FFmpegPushThread(QObject *parent);
	~FFmpegPushThread();
public:
	void run();
private:
	string url;
	bool pusfflag;
};
