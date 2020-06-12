#include "PlayQlabel.h"

PlayQlabel::PlayQlabel(QWidget* parent) : QLabel(parent)
{

}

void PlayQlabel::mousePressEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		emit leftclick();
		qDebug() << this->objectName();
	}
	
}

void PlayQlabel::mouseReleaseEvent(QMouseEvent* ev)
{

}

void PlayQlabel::mouseMoveEvent(QMouseEvent* ev)
{

}

