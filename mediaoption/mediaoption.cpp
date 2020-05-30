#include "mediaoption.h"



mediaoption::mediaoption(QWidget *parent) : QMainWindow(parent)
{
 
	initWindow();
}
void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	url = "rtsp://admin:admin123@10.135.128.8:554/cam/realmonitor?channel=1&subtype=0";
	//decoder = new FFmpegDecoder();
	//qDebug() << QCameraInfo::availableCameras().at(0).description();
	timer = new QTimer(this);
	timer->start(33);
	if (decoder.Open(url))
	{
		connect(timer, SIGNAL(timeout()), SLOT(opencvdisplay()));
	}
	else
	{
		std::cout << "Cannot open file " << url << std::endl;
	}

	
}

void mediaoption::opencvdisplay(void)
{
	
	decoder.GetNextFrame(image);
	ui.label->setPixmap(QPixmap::fromImage(image));
}
mediaoption:: ~mediaoption() {

}
