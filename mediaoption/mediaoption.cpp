#include "mediaoption.h"

mediaoption::mediaoption(QWidget* parent) :QMainWindow(parent), scrindex(0)
{
	QImage img;
	for (int i = 0; i < MAXSCREEN; i++)
	{
		decoderthread[i] = nullptr;
	}
	initWindow();
}

void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	//url = "rtsp://admin:admin123@10.135.128.8:554/cam/realmonitor?channel=1&subtype=0";
	//url = "D:\\code\\C++code\\videopusher\\001.avi";
	//url = "D:\CodeC++\FFMpeg2\MyVideo_1.avi";
	timer = new QTimer(this);
	scr = new SplitScreen(this);
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
					}
					scr->label[i]->setplayflag(true);
				}
				});
		}
		
	}
}

mediaoption:: ~mediaoption()
{

}
