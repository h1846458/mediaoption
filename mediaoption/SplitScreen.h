#pragma once
#include "ui_mediaoption.h"
#include <qdebug.h>
#include "PlayQlabel.h"
#include <QVBoxLayout>
#define MAXSCREEN 16
class SplitScreen :public QWidget //Ui::mediaoptionClass
{
	Q_OBJECT;
public:
	explicit SplitScreen(QWidget* parent = 0);
	virtual ~SplitScreen();
public:
	PlayQlabel* label[MAXSCREEN];
	void setScrnum(int& n);
	bool changeScreen(Ui::mediaoptionClass ws);
	bool deletelayout();
	int getScrnum() { return scrnum; };
private:
	int scrnum;
	QGridLayout* layout;
};

