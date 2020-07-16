#pragma once

#include <QThread>
#include "BasicUsageEnvironment.hh"
#include "DynamicRTSPServer.hh"
#include "version.hh"
#define ACCESS_CONTROL
class PushThread : public QThread
{
	Q_OBJECT

public:
	PushThread(QObject *parent);
	~PushThread();
	void run();
private:
	TaskScheduler* scheduler;
	UsageEnvironment* env;
	RTSPServer* rtspServer;
	UserAuthenticationDatabase* authDB;
	portNumBits rtspServerPortNum;
};
