#pragma once
#include "ui_mediaoption.h"
#include <qdebug.h>
#include "PlayQlabel.h"
#include <QVBoxLayout>
#define MAXSCREEN 16
class SplitScreen :public Ui::mediaoptionClass
{
	//Q_OBJECT;
public:
	SplitScreen();
	virtual ~SplitScreen();
public:
	PlayQlabel* label[MAXSCREEN];
	void setScrnum(int& n) { scrnum = n;};
	bool changeScreen(Ui::mediaoptionClass ws);
	bool deletelayout();
	int getScrnum() { return scrnum; };
private:
	int scrnum;
	QGridLayout* layout;
	

};

