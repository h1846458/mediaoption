#include "mediaoption.h"

mediaoption::mediaoption(QWidget* parent) :QMainWindow(parent), scrindex(0)
{
	QImage img;
	for (int i = 0; i < MAXSCREEN; i++)
	{
		decoderthread[i] = nullptr;
		timer[i] = nullptr;
		image[i] = img;
	}
	initWindow();
}

void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	//url = "rtsp://admin:admin123@10.135.128.8:554/cam/realmonitor?channel=1&subtype=0";
	//url = "D:\\code\\C++code\\videopusher\\001.avi";
	//url = "D:\CodeC++\FFMpeg2\MyVideo_1.avi";
	scr = new SplitScreen(ui);
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->changeScreen(ui);
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
	for (auto i = 0; i < index; i++)
	{
		
		QObject::connect(scr->label[i]->playbutton, &QPushButton::clicked, this, [=]() {
			if (scr->label[i]->getplayflag())
			{
				scr->label[i]->setplayflag(false);
			}
			else
			{
				scr->label[i]->setplayflag(true);
			}
			
			});
	}
	
}
 
void mediaoption::opencvdisplay(void)
{
	for (int v = 0; v < playlist.size(); v++)
	{
		image[playlist.at(v)] = decoderthread[playlist.at(v)]->getDecoderData().img;
		if (!image[v].isNull())
		{
			QPixmap pixmap = QPixmap::fromImage(image[playlist.at(v)]);
			int tmp = scr->getScrnum() - 1;
			if (scrindex <= tmp)
			{
				//QPixmap fitpixmap = pixmap.scaled(scr->label[scrindex]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
				QPixmap fitpixmap = pixmap.scaled(scr->label[playlist.at(v)]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
				scr->label[playlist.at(v)]->setPixmap(fitpixmap);
			}

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
}

mediaoption:: ~mediaoption()
{

}
