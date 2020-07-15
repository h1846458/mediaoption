#pragma once

#include <QObject>
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

class PushTable : public QTableView
{
	Q_OBJECT

public:
	PushTable(QWidget* parent);
	~PushTable();
public:
	QStandardItemModel* item_model;
	void set_tabel();
	static void set_tabLayout(PushTable* u, QWidget* g);
private:
	//static QHBoxLayout* tablayout;
};
