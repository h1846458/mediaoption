#include "mediaoption.h"

mediaoption::mediaoption(QWidget* parent) :QMainWindow(parent), scrindex(0)
{
	initWindow();
}

void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	//url = "rtsp://admin:admin123@10.135.128.8:554/cam/realmonitor?channel=1&subtype=0";
	url = "D:\\CodeC++\\decode\\MyVideo_1-H264.avi";
	scr = new SplitScreen();
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->changeScreen(ui);
	timer = new QTimer(this);
	void(QComboBox:: * pcomboBox)(int) = &QComboBox::currentIndexChanged;
	QObject::connect(ui.comboBox, pcomboBox, this, &mediaoption::setScreen);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() mutable {
		
		timer->start(15);
		
		if (decoder.Open(url))
		{
			QObject::connect(timer, &QTimer::timeout,this, &mediaoption::opencvdisplay);
		}
		else
		{
			std::cout << "Cannot open file " << url << std::endl;
		}

		});
	//QObject::connect(ui.playwidget, &PlayQlabel::leftclick, this, [=]() {playlabel = })
}

void mediaoption::opencvdisplay(void)
{
	decoder.GetNextFrame(image);
	QPixmap pixmap = QPixmap::fromImage(image);
	int tmp = scr->getScrnum() - 1;
	if (scrindex <= tmp)
	{
		qDebug() << "===================================+++++++" << scr->label[scrindex]->height();
		//QPixmap fitpixmap = pixmap.scaled(scr->label[scrindex]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		QPixmap fitpixmap = pixmap.scaled(scr->label[scrindex]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
		scr->label[scrindex]->setPixmap(fitpixmap);
	}
	else
	{
		
		if (scr->label[tmp] != nullptr) 
		{
			QPixmap fitpixmap = pixmap.scaled(scr->label[tmp]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
			//QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			scr->label[tmp]->setPixmap(fitpixmap);
		}
		
	}
	
	
}

void mediaoption::setScreen(int check)
{
	
	timer->stop();
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
	timer->start(15);
}
mediaoption:: ~mediaoption()
{

}
