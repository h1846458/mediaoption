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
	QPushButton* playbutton;
	~PlayQlabel();
	int getlabelindex(){return labelindex;}
	void setlabelindex() { labelindex = 0;}
	void setplayflag(bool flag) { playflag = flag; }
	bool getplayflag() { return playflag; }
	static void setlay(PlayQlabel *lab);
protected:
	void mousePressEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent* ev);
	void mouseMoveEvent(QMouseEvent* ev);
	void enterEvent(QEvent* ev);
	void leaveEvent(QEvent* ev);
	bool eventFilter(QObject* watched, QEvent* ev);
	
	
private:
	int labelindex;
	QGridLayout* lay;
	bool playflag;
	
signals:
	void leftclick();

private slots:
	//void sendclick();
};

