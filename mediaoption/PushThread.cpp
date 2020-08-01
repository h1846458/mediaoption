#include "PushThread.h"

PushThread::PushThread(QObject *parent): QThread(parent), authDB(NULL), rtspServerPortNum(554), stopserver(0)
{

}

void PushThread::run()
{
	scheduler = BasicTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);
#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("username1", "password1"); // replace these with real strings
#endif
	
	rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
	if (rtspServer == NULL)
	{
		rtspServerPortNum = 8554;
		rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
	}
	if (rtspServer == NULL)
	{
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		exit(1);
	}
	/*
	*env << "LIVE555 Media Server\n";
	*env << "\tversion " << MEDIA_SERVER_VERSION_STRING
		 << " (LIVE555 Streaming Media library version "
		 << LIVEMEDIA_LIBRARY_VERSION_STRING << ").\n";

	char* urlPrefix = rtspServer->rtspURLPrefix();
	*env << "Play streams from this server using the URL\n\t"
		 << urlPrefix << "<filename>\nwhere <filename> is a file present in the current directory.\n";
	*env << "Each file's type is inferred from its name suffix:\n";
	*env << "\t\".264\" => a H.264 Video Elementary Stream file\n";
	*env << "\t\".265\" => a H.265 Video Elementary Stream file\n";
	*env << "\t\".aac\" => an AAC Audio (ADTS format) file\n";
	*env << "\t\".ac3\" => an AC-3 Audio file\n";
	*env << "\t\".amr\" => an AMR Audio file\n";
	*env << "\t\".dv\" => a DV Video file\n";
	*env << "\t\".m4e\" => a MPEG-4 Video Elementary Stream file\n";
	*env << "\t\".mkv\" => a Matroska audio+video+(optional)subtitles file\n";
	*env << "\t\".mp3\" => a MPEG-1 or 2 Audio file\n";
	*env << "\t\".mpg\" => a MPEG-1 or 2 Program Stream (audio+video) file\n";
	*env << "\t\".ogg\" or \".ogv\" or \".opus\" => an Ogg audio and/or video file\n";
	*env << "\t\".ts\" => a MPEG Transport Stream file\n";
	*env << "\t\t(a \".tsx\" index file - if present - provides server 'trick play' support)\n";
	*env << "\t\".vob\" => a VOB (MPEG-2 video with AC-3 audio) file\n";
	*env << "\t\".wav\" => a WAV Audio file\n";
	*env << "\t\".webm\" => a WebM audio(Vorbis)+video(VP8) file\n";
	*env << "See http://www.live555.com/mediaServer/ for additional documentation.\n";

	*/
	// Also, attempt to create a HTTP server for RTSP-over-HTTP tunneling.
	// Try first with the default HTTP port (80), and then with the alternative HTTP
	// port numbers (8000 and 8080).

	if (rtspServer->setUpTunnelingOverHTTP(80) || rtspServer->setUpTunnelingOverHTTP(8000) || rtspServer->setUpTunnelingOverHTTP(8080))
	{
		*env << "(We use port " << rtspServer->httpServerPortNum() << " for optional RTSP-over-HTTP tunneling, or for HTTP live streaming (for indexed Transport Stream files only).)\n";
	}
	else
	{
		*env << "(RTSP-over-HTTP tunneling is not available.)\n";
	}

	env->taskScheduler().doEventLoop(&stopserver); // does not return
}

void PushThread::stopser()
{
	stopserver = 1;
	Medium::close(rtspServer);
}

PushThread::~PushThread()
{
}
