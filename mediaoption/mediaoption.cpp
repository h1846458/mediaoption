#include "mediaoption.h"

mediaoption::mediaoption(QWidget* parent) :QMainWindow(parent), scrindex(0)
{
	for (int i = 0; i < MAXSCREEN; i++)
	{
		decoderthread[i] = nullptr;
		timer[i] = nullptr;
	}
	initWindow();
}

void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	//url = "rtsp://admin:admin123@10.135.128.8:554/cam/realmonitor?channel=1&subtype=0";
	//url = "D:\\code\\C++code\\videopusher\\001.avi";
	//url = "D:\CodeC++\FFMpeg2\MyVideo_1.avi";
	scr = new SplitScreen();
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->changeScreen(ui);
	void(QComboBox:: * pcomboBox)(int) = &QComboBox::currentIndexChanged;
	QObject::connect(ui.comboBox, pcomboBox, this, &mediaoption::setScreen);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() mutable {
		timer[scrindex] = new QTimer(this);
		if (timer[scrindex]->isActive() == false)
		{
			timer[scrindex]->start(10);
		}
		decoderthread[scrindex] = new DecoderThread(this);
		if (scr->label[scrindex] != nullptr)
		{
			scr->label[scrindex]->setlabelindex();
			string  url = ui.UrllineEdit->text().toStdString();
			decoderthread[scrindex]->setUrl(url);
			decoderthread[scrindex]->start();
			QObject::connect(timer[scrindex], &QTimer::timeout, this, &mediaoption::opencvdisplay);
		}	
		});
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
}
 
void mediaoption::opencvdisplay(void)
{
	QImage image = decoderthread[scrindex]->getDecoderData().img;
	QPixmap pixmap = QPixmap::fromImage(image);
	int tmp = scr->getScrnum() - 1;
	if (scrindex <= tmp)
	{
		//QPixmap fitpixmap = pixmap.scaled(scr->label[scrindex]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		QPixmap fitpixmap = pixmap.scaled(scr->label[scrindex]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
		scr->label[scrindex]->setPixmap(fitpixmap);
	}
	else
	{
		if (scr->label[tmp] != nullptr) 
		{
			QPixmap fitpixmap = pixmap.scaled(scr->label[tmp]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
			scr->label[tmp]->setPixmap(fitpixmap);
		}
	}
	
	
}

void mediaoption::setScreen(int check)
{
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->deletelayout();
	scr->changeScreen(ui);
	for (int j = 0; j < scr->getScrnum(); j++)
	{
		QObject::connect(scr->label[j], &PlayQlabel::leftclick, this, [=]() mutable {
			scrindex = j;
			});
	}
	//timer[scrindex]->start(25);
}

mediaoption:: ~mediaoption()
{

}
