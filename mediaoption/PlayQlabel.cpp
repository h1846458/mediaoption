#include "PlayQlabel.h"

PlayQlabel::PlayQlabel(QWidget* parent) : QLabel(parent), labelindex(0)
{
	QGridLayout* lay = new QGridLayout(this);
	playbutton = new QPushButton(this);
	playbutton->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
	QIcon icon;
	icon.addFile(QStringLiteral("res/play_button.png"), QSize(), QIcon::Normal, QIcon::Off);
	playbutton->setIcon(icon);
	playbutton->setIconSize(QSize(60, 60));
	lay->setContentsMargins(this->width() * 4 / 5, 0 , this->width()*4 / 5, 0);
	lay->addWidget(playbutton);
	qDebug() << "dfadfasdfadsfasdfasdfads";
}

void PlayQlabel::mousePressEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		QString  lname = this->objectName();
		labelindex = lname.mid(lname.length() - 1, lname.length()).toInt();
		emit leftclick();
		//qDebug() << this->objectName();
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
	playbutton->hide();
}


