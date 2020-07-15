#include "mediaoption.h"

mediaoption::mediaoption(QWidget* parent) :QMainWindow(parent), scrindex(0)
{
	QImage img;
	for (int i = 0; i < MAXSCREEN; i++)
	{
		decoderthread[i] = nullptr;
	}
	initWindow();
	initDb();
}

void mediaoption::initDb()
{
	DB = new SqliteOperate();
	if (DB->openDb())
	{
		QString tabn = "rtspserver";
		if (!DB->IsTaBexists(tabn))
		{
			DB->createTable();
		}
		
	}
	setdevicetype();
}

void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	//url = "rtsp://admin:admin123@10.135.128.8:554/cam/realmonitor?channel=1&subtype=0";
	//url = "D:\\code\\C++code\\videopusher\\001.avi";
	//url = "D:\CodeC++\FFMpeg2\MyVideo_1.avi";
	timer = new QTimer(this);
	scr = new SplitScreen();
	addser = new QDialog();
	addsr.setupUi(addser);
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->changeScreen(ui); 
	initplay(index);

	void(QComboBox:: * pcomboBox)(int) = &QComboBox::currentIndexChanged;
	QObject::connect(ui.comboBox, pcomboBox, this, &mediaoption::setScreen);

	QObject::connect(this, &QMainWindow::destroyed, this, [=]() {
		for (int i = 0; i < MAXSCREEN; i++)
		{
			if (decoderthread[i] != nullptr)
			{
				decoderthread[i]->setFlag();
				decoderthread[i]->wait();
				delete decoderthread[i];
			}
		}
		});

	timer->start(0);
	QObject::connect(timer, &QTimer::timeout, this, [=]() {
		for (auto j = 0; j < MAXSCREEN; j++)
		{
			if (decoderthread[j] != nullptr)
			{
				if (decoderthread[j]->isRunning())
				{
					decoderthread[j]->vplay();
				}
			}
		}
		});

	QObject::connect(ui.submitDevice, &QPushButton::clicked, this, [=]() {
		QString devicename = ui.deviceName->text();
		QString devicetype = ui.deviceType->currentText();
		QString deviceid = ui.deviceId->text();
		QString username = ui.userName->text();
		QString passwd = ui.passWd->text();
		QString ipaddr = ui.ipAddr->text();
		QString port = ui.devicePort->text();
		QString sql = QString(QString::fromLocal8Bit("INSERT INTO  devicetab (name, devicetype, deviceid, username, passwd, ipaddr, port) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7')"))
			.arg(devicename)
			.arg(devicetype)
			.arg(deviceid)
			.arg(username)
			.arg(passwd)
			.arg(ipaddr)
			.arg(port);
		DB->singleinsertdata(sql);
		ui.deviceName->clear();
		ui.deviceId->clear();
		ui.devicePort->clear();
		ui.userName->clear();
		ui.passWd->clear();
		ui.ipAddr->clear();
		QMessageBox msgBox(this);
		msgBox.setWindowFlags(Qt::Widget);
		//msgBox.setStyleSheet("background-color:white");
		msgBox.setStyleSheet("QLabel{""min-width: 200px;""min-height: 100px; ""font-size:18px;""}");
		msgBox.setText(QString::fromLocal8Bit("<center><h4>添加设备成功</h4></center>"));
		msgBox.addButton(QMessageBox::Ok);
		msgBox.button(QMessageBox::Ok)->hide();
		msgBox.show();
		msgBox.move(this->width() / 2, this->height() / 2);
		QTimer::singleShot(3000, &msgBox, &QMessageBox::close);
		msgBox.exec();
		});

	QObject::connect(ui.cancelDevice, &QPushButton::clicked, this, [=]() {
		ui.deviceName->clear();
		ui.deviceId->clear();
		ui.devicePort->clear();
		ui.userName->clear();
		ui.passWd->clear();
		ui.ipAddr->clear();
		});

	QObject::connect(ui.addServer, &QPushButton::clicked, this, [=](){
		addser->setFixedSize(400,200);
		Qt::WindowFlags flags = Qt::Dialog; 
		flags |= Qt::WindowCloseButtonHint;
		addser->setWindowFlags(flags);
		addser->show();
		});

	QObject::connect(addsr.cancelpushButton, &QPushButton::clicked, addser, [=](){
		addser->close();
		});
}
 
void mediaoption::setScreen(int check)
{
	timer->stop();
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->deletelayout();
	scr->changeScreen(ui);
	for (auto i = 0; i < MAXSCREEN; i++)
	{
		if (decoderthread[i] != nullptr)
		{
			if (decoderthread[i]->isRunning())
			{
				if (i < index)
				{
					decoderthread[i]->setLabel(scr->label[i]);
					//scr->label[i]->setplayflag(false);
				}
				else
				{
					decoderthread[i]->setFlag();
					decoderthread[i]->wait();
					delete decoderthread[i];
					decoderthread[i] = nullptr;
				}
				
			}
		}
	}
	initplay(index);
	timer->start(0);
}

void mediaoption::initplay(int index)
{
	for (auto i = 0; i < index; i++)
	{
		if (scr->label[i] != nullptr)
		{
			QObject::connect(scr->label[i]->playbutton, &QPushButton::clicked, this, [=](){
				string  url = ui.UrllineEdit->text().toStdString();
				if (scr->label[i]->getplayflag())
				{
					if (decoderthread[i] == nullptr)
					{
						decoderthread[i] = new DecoderThread(this);
						decoderthread[i]->setUrl(url);
						if (!decoderthread[i]->isRunning())
						{
							decoderthread[i]->setLabel(scr->label[i]);
							decoderthread[i]->start();
						}
					}
					scr->label[i]->setplayflag(false);
				}
				else
				{
					if (decoderthread[i]->isRunning())
					{
						decoderthread[i]->setFlag();
						decoderthread[i]->wait();
						delete decoderthread[i];
						decoderthread[i] = nullptr;
						qDebug() << "fadsfadsfadsfasdf";
					}
					scr->label[i]->setplayflag(true);
					
				}
				});
		}
		
	}
}

void mediaoption::setdevicetype()
{
	QString sql = "SELECT * FROM devicetype";
	QList<QString> typelist;
	DB->queryTable(sql, typelist);
	for (auto i = 0; i < typelist.size(); i++)
	{
		ui.deviceType->addItem(typelist.at(i));
	}
}

void mediaoption::startserver()
{
	TaskScheduler* scheduler = BasicTaskScheduler::createNew();
	UsageEnvironment* env = BasicUsageEnvironment::createNew(*scheduler);

	UserAuthenticationDatabase* authDB = NULL;
#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("username1", "password1"); // replace these with real strings
#endif

	RTSPServer* rtspServer;
	portNumBits rtspServerPortNum = 554;
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

	env->taskScheduler().doEventLoop(); // does not return
}

mediaoption:: ~mediaoption()
{
	delete DB;
}
