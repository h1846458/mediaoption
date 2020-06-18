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
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, [=]() mutable {
		if (scrindex == -1)
		{
			QMessageBox msgBox(this);
			msgBox.setWindowFlags(Qt::Widget);
			//msgBox.setStyleSheet("background-color:white");
			msgBox.setStyleSheet("QLabel{""min-width: 200px;""min-height: 100px; ""font-size:18px;""}");
			msgBox.setText(QString::fromLocal8Bit("请选择一个播放窗口"));
			msgBox.addButton(QMessageBox::Ok);
			msgBox.button(QMessageBox::Ok)->hide();
			QObjectList objChildList = msgBox.children();
			/*
			for (int i = 0; i < objChildList.size(); i++)
			{
				QObject* pObj = objChildList.at(i);
				if (pObj->inherits("QWidget"))
				{
					qDebug() << "+++++++++++++++++++";
					QWidget* pWidget = (QWidget*)pObj;
					pWidget->setStyleSheet("background-color:transparent");
				}
			}*/
			
			msgBox.show();
			msgBox.move(this->width() / 2, this->height() / 2);
			QTimer::singleShot(3000, &msgBox, &QMessageBox::close);
			msgBox.exec();	
		}
		else
		{	
			playlist.append(scrindex);
			decoderthread[scrindex] = new DecoderThread(this);
			string  url = ui.UrllineEdit->text().toStdString();
			decoderthread[scrindex]->setUrl(url);
			for (int y=0; y < playlist.size(); y++)
			{
				if (scr->label[playlist.at(y)] != nullptr)
				{
					scr->label[playlist.at(y)]->setlabelindex();
					if (!decoderthread[playlist.at(y)]->isRunning())
					{
						decoderthread[playlist.at(y)]->setLabel(scr->label[playlist.at(y)]);
						decoderthread[playlist.at(y)]->start();
					}
					
				}
				
			}
			
			scrindex = -1;
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
		
		/*
		else
		{
			if (scr->label[tmp] != nullptr)
			{
				QPixmap fitpixmap = pixmap.scaled(scr->label[tmp]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
				scr->label[tmp]->setPixmap(fitpixmap);
			}
		}*/

	}
	
	
	
}

void mediaoption::setScreen(int check)
{
	QString ind = ui.comboBox->currentText();
	int index = ind.mid(0, ind.length() - 2).toInt();
	scr->setScrnum(index);
	//scr->deletelayout();
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
