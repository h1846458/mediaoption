#pragma once

#include <QObject>
<<<<<<< HEAD
#include <QTableView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QHeaderView>
#include <QString>
#include <QDebug>
#include <QStandardItem>
#include <QPushButton>
#include <QCheckBox>
=======
#include <QtWidgets>
#include <QTableView>
#include <time.h>
#include "HeaderView.h"
>>>>>>> dev1.0

class PushTable : public QTableView
{
	Q_OBJECT

public:
<<<<<<< HEAD
	PushTable(QWidget* parent);
	~PushTable();
public:
	QStandardItemModel* item_model;
	void set_tabel();
	static void set_tabLayout(PushTable* u, QWidget* g);
private:
	//static QHBoxLayout* tablayout;
=======
	PushTable(QObject *parent);
	~PushTable();
public:
	void set_table();
	void getobject(QList<QPushButton*>& bts) { bts = btlist; }
	void getobject(QList<QCheckBox*>& checks) { checks = checkblist; }
	bool getchkflag() { return chkflag; }

private:
	QStandardItemModel* tb_item;
	QList<QCheckBox*> checkblist;
	QList<QPushButton*> btlist;
	HeaderView* tabHeader;
	bool chkflag;
	QString getTime();
>>>>>>> dev1.0
};
