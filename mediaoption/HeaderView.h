#pragma once

#include <QHeaderView>
#include <QPainter>

class HeaderView : public QHeaderView
{
	Q_OBJECT

public:
	HeaderView(Qt::Orientation orientation, QWidget* parent = 0);
	~HeaderView();
protected:
	void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const;

	void mousePressEvent(QMouseEvent* event);

private:
	//checkbox的开启或关闭状态
	bool isOn;
};
