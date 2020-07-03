#pragma once
#include <QTreeView>
#include <QStandardItem>
#include <QHeaderView>
#include <QDebug>

class TreeView : public QTreeView
{
	Q_OBJECT

public:
	TreeView(QObject* parent);
	~TreeView();
	void iterateOverItems();
	QList<QStandardItem*> returnTheItems();
private:
	QStandardItemModel* model;
};
