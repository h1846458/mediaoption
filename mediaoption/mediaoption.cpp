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
	for (int j = 0; j < scr->getScrnum(); j++)
	{
		QObject::connect(scr->label[j], &PlayQlabel::leftclick, this, [=]() {
			scrindex = j;
			});
	}

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() {
		timer->start(15);
		if (decoder.Open(url))
		{
			QObject::connect(timer, SIGNAL(timeout()), SLOT(opencvdisplay()));
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
	qDebug() << scrindex;
	decoder.GetNextFrame(image);
	QPixmap pixmap = QPixmap::fromImage(image);
	QPixmap fitpixmap = pixmap.scaled(scr->label[scrindex]->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	//QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	scr->label[scrindex]->setPixmap(fitpixmap);
}

void mediaoption::setScreen(int check)
{
	timer->stop();
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	scr->deletelayout();
	scr->changeScreen(ui);
	timer->start();
}
mediaoption:: ~mediaoption()
{

}
