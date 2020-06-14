#include "PlayQlabel.h"

PlayQlabel::PlayQlabel(QWidget* parent) : QLabel(parent), labelindex(0)
{

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

