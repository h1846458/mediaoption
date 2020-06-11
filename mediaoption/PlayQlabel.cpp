#include "PlayQlabel.h"

PlayQlabel::PlayQlabel(QWidget* parent) : QLabel(parent)
{

}

void PlayQlabel::mousePressEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		emit leftclick();
		//int x = ev->x();
		//int y = ev->y();
		//qDebug() << x << y;
		qDebug() << this->objectName();
		
		//sendclick();
	}
	
}

void PlayQlabel::mouseReleaseEvent(QMouseEvent* ev)
{

}

void PlayQlabel::mouseMoveEvent(QMouseEvent* ev)
{

}

