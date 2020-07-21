#pragma once

#include <QObject>
#include <QtWidgets>
#include <QTableView>
#include <time.h>
#include "HeaderView.h"

class PushTable : public QTableView
{
	Q_OBJECT

public:
	PushTable(QObject *parent);
	~PushTable();
public:
	void set_table();
	void getobject(QList<QPushButton*>& bts) { bts = btlist; }
	void getobject(QList<QCheckBox*>& checks) { checks = checkblist; }

private:
	QStandardItemModel* tb_item;
	QList<QCheckBox*> checkblist;
	QList<QPushButton*> btlist;
	HeaderView* tabHeader;
	QString getTime();
};
