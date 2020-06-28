#include "SplitScreen.h"


SplitScreen::SplitScreen(): scrnum(1)
{
	for(int i = 0; i < MAXSCREEN; i++)
	{
		label[i] = nullptr;
	}
	layout = nullptr;
}

bool SplitScreen::changeScreen(Ui::mediaoptionClass ws)
{
	if (layout ==nullptr)
	{
		layout = new QGridLayout(ws.playwidget);
		layout->setSpacing(5);
	}

	for (int i = 0; i < scrnum; i++)
	{
		if (label[i] == nullptr)
		{
			//qDebug() << "=========" << i;
			label[i] = new PlayQlabel(ws.playwidget);
			label[i]->setObjectName(QString("lable_%1").arg(i));
			label[i]->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
			label[i]->setStyleSheet("background-color: rgb(62, 62, 62);");
			PlayQlabel::setlay(label[i]);
		}
	}
	
	switch (scrnum)
	{
		case 1:
		{
			layout->addWidget(label[0], 0, 0);
			break;
		}
		case 4:
		{
			//layout = new QGridLayout(ws.playwidget);
			//layout->setSpacing(1);
			//layout->setRowStretch(2, 2);
			int n = 0;
			for (int j = 0; j < 2; j++)
			{

				for (int q = 0; q < 2; q++)
				{
					layout->addWidget(label[n], j, q);
					n = n + 1;
				}

			}
			break;
		}
		case 6:
		{
			layout->addWidget(label[0], 0, 0, 2, 2);
			int n = 1;
			for (int q = 0; q < 2; q++)
			{
				layout->addWidget(label[n], 2, q);
				n = n + 1;
			}
			for (int j = 0; j < 3; j++)
			{
				layout->addWidget(label[n], j, 2);
				n = n + 1;
			}
			break;
		}
		case 9:
		{
			int n = 0;
			for (int j = 0; j < 3; j++)
			{

				for (int q = 0; q < 3; q++)
				{
					layout->addWidget(label[n], j, q);
					n = n + 1;
				}

			}
			break;
		}
		case 16:
		{
			int n = 0;
			for (int j = 0; j < 4; j++)
			{

				for (int q = 0; q < 4; q++)
				{
					layout->addWidget(label[n], j, q);
					n = n + 1;
				}

			}
			break;
		}
		default:
			break;
	}
	return true;
}


bool SplitScreen::deletelayout() 
{
	for (int i = 0; i <  MAXSCREEN; i++ )
	{
		if (label[i] != nullptr)
		{
			delete label[i];
			label[i] = nullptr;
			//qDebug() << "======================";
		}
	}
	if (layout != nullptr)
	{
		delete layout;
		layout = nullptr;
	}
	return true;
	
}
void SplitScreen::setScrnum(int& n) 
{ 
	scrnum = n; 
}

SplitScreen::~SplitScreen()
{
}

