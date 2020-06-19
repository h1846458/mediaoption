#pragma once
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QPushbutton>
#include <QMessagebox>
#include <QDockWidget>
#include <QGridLayout>
#include <QSpacerItem>
class PlayQlabel :public QLabel
{
	Q_OBJECT;
public:
	explicit PlayQlabel(QWidget *parent = 0);
	int getlabelindex(){return labelindex;}
	void setlabelindex() { labelindex = 0;}
protected:
	void mousePressEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent* ev);
	void mouseMoveEvent(QMouseEvent* ev);
	void enterEvent(QEvent* ev);
	void leaveEvent(QEvent* ev);
	
private:
	int labelindex;
	QPushButton* playbutton;
	//QDockWidget	 *playevent;

signals:
	void leftclick();

private slots:
	//void sendclick();
};

