#include "mediaoption.h"

mediaoption::mediaoption(QWidget* parent) :QMainWindow(parent), scrindex(0), sr(NULL)
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
	addstrm = new QDialog();
	addsr.setupUi(addser);
	addstr.setupUi(addstrm);
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
		if (sr != NULL)
		{
			if (sr->isRunning())
			{
				sr->stopser();
				sr->wait();
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

	QObject::connect(addstr.submitDevice, &QPushButton::clicked, this, [=]() {
		QString devicename = addstr.deviceName->text();
		QString devicetype = addstr.deviceType->currentText();
		QString	streamtype = addstr.streamType->currentText();
		QString deviceid = addstr.deviceId->text();
		QString username = addstr.userName->text();
		QString passwd = addstr.passWd->text();
		QString ipaddr = addstr.ipAddr->text();
		QString port = addstr.devicePort->text();
		QString sql = QString(QString::fromLocal8Bit("INSERT INTO  devicetab (name, devicetype,streamtype, deviceid, username, passwd, ipaddr, port) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7','%8')"))
			.arg(devicename)
			.arg(devicetype)
			.arg(streamtype)
			.arg(deviceid)
			.arg(username)
			.arg(passwd)
			.arg(ipaddr)
			.arg(port);
		DB->singleinsertdata(sql);
		addstr.deviceName->clear();
		addstr.deviceId->clear();
		addstr.devicePort->clear();
		addstr.userName->clear();
		addstr.passWd->clear();
		addstr.ipAddr->clear();
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

	QObject::connect(addstr.cancelDevice, &QPushButton::clicked, this, [=]() {
		addstr.deviceName->clear();
		addstr.deviceId->clear();
		addstr.devicePort->clear();
		addstr.userName->clear();
		addstr.passWd->clear();
		addstr.ipAddr->clear();
		addstrm->close();
		});

	QObject::connect(ui.addServer, &QPushButton::clicked, this, [=](){
		addser->setFixedSize(430,280);
		Qt::WindowFlags flags = Qt::Dialog; 
		flags |= Qt::WindowCloseButtonHint;
		addser->setWindowFlags(flags);
		addser->show();
		});

	QObject::connect(ui.addStream, &QPushButton::clicked, this, [=]() {
		addstrm->setFixedSize(400, 300);
		Qt::WindowFlags flags = Qt::Dialog;
		flags |= Qt::WindowCloseButtonHint;
		addstrm->setWindowFlags(flags);
		addstrm->show();
		});

	QObject::connect(addsr.cancelpushButton, &QPushButton::clicked, addser, [=](){
		addser->close();
		});

	QObject::connect(ui.startServer, &QPushButton::clicked, this, [=]() {
		
		sr = new PushThread(this);
		sr->start();
		QList<QPushButton*> bts;
		QList<QCheckBox*> checks;
		ui.pushTableView->getobject(bts);
		ui.pushTableView->getobject(checks);
		});

	QObject::connect(ui.pushAll, &QPushButton::clicked, this, [=]() {
		QList<QCheckBox*> checks;
		ui.pushTableView->getobject(checks);
		for (auto ck = checks.begin(); ck != checks.end(); ck++)
		{
			QCheckBox* chk = *ck;
			qDebug() << chk->isChecked();
		}
		
		
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
		addstr.deviceType->addItem(typelist.at(i));
	}
}

mediaoption:: ~mediaoption()
{
	delete DB;
}
