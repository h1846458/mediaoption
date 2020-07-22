#pragma once

#include <QHeaderView>
#include <QPainter>
#include <QPoint>
#include <QDebug>
#include <QMouseEvent>

class HeaderView : public QHeaderView
{
	Q_OBJECT

public:
	HeaderView(Qt::Orientation orientation, QWidget* parent = 0);
	~HeaderView();

protected:
	void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const;
	void mousePressEvent(QMouseEvent* event);

signals:
	void onChangeclicked(bool);

private:
	bool isOn;
};
