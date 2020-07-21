#include "PlayQlabel.h"

PlayQlabel::PlayQlabel(QWidget* parent) : QLabel(parent), labelindex(0), playflag(true)
{
	playbutton = nullptr;
	lay = nullptr;
	
}

void PlayQlabel::setlay(PlayQlabel* lab)
{
	
	lab->playbutton = new QPushButton(lab);
	lab->playbutton->installEventFilter(lab);
	lab->lay= new QGridLayout(lab);
	lab->playbutton->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
	QIcon icon;
	icon.addFile(QStringLiteral("res/play_button.png"), QSize(), QIcon::Normal, QIcon::Off);
	lab->playbutton->setIcon(icon);
	lab->playbutton->setIconSize(QSize(60, 60));
	lab->lay->setContentsMargins(lab->width() * 4 / 5, 0, lab->width() * 4 / 5, 0);
	lab->lay->addWidget(lab->playbutton);
	
}

void PlayQlabel::mousePressEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		playbutton->hide();
	}
	
}

void PlayQlabel::mouseReleaseEvent(QMouseEvent* ev)
{

}

void PlayQlabel::mouseMoveEvent(QMouseEvent* ev)
{
	
	
}

void PlayQlabel::enterEvent(QEvent* ev)
{
		playbutton->show();
}

void PlayQlabel::leaveEvent(QEvent* ev)
{
	if (!playflag)
	{
		playbutton->hide();
	}
	
}

bool PlayQlabel::eventFilter(QObject* watched, QEvent* ev)
{
	if (watched == playbutton)
	{
		if (ev->type() == QEvent::MouseButtonPress)
		{
			if (playflag)
			{
				playbutton->setIcon(QIcon(QString::fromLocal8Bit("res/pause_button.png")));
				playbutton->hide();
				emit playbutton->click();
			}
			else if (!playflag)
			{
				playbutton->setIcon(QIcon(QString::fromLocal8Bit("res/play_button.png")));
				playbutton->hide();
				emit playbutton->click();
			}
		}
		
	}
	return QWidget::eventFilter(watched, ev);

}

PlayQlabel::~PlayQlabel()
{
	delete playbutton;
	delete lay;
}
