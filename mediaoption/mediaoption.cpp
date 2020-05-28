#include "mediaoption.h"
#include "ffmpegDecode.h"

mediaoption::mediaoption(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
}
void mediaoption::initWindow(void)
{
	ui.setupUi(this);
	
	//qDebug() << QCameraInfo::availableCameras().at(0).description();

	timer = new QTimer(this);
	timer->start(Capturetime);
	connect(timer, SIGNAL(timeout()), SLOT(opencvdisplay()));
}

void mediaoption::opencvdisplay(void)
{
	QImage image[4];
	cv::Mat frame[4];
	for (int i = 0; i < devicenum; i++)
	{
		(cap + i)->read(*(frame + i));
		*(image + i) = Mat2Qimage(frame + i);
		if (i == 0)
		{
			ui.label->setPixmap(QPixmap::fromImage(*(image + i)));
		}
		
	}
}
mediaoption:: ~mediaoption() {

}
