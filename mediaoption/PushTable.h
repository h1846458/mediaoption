#pragma once

#include <QObject>
#include <QtWidgets>
#include <QTableView>
#include <time.h>

class PushTable : public QTableView
{
	Q_OBJECT

public:
	PushTable(QObject *parent);
	~PushTable();
public:
	void set_table();

private:
	QStandardItemModel* tb_item;
	QString getTime();
};
