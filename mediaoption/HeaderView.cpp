#include "HeaderView.h"

HeaderView::HeaderView(Qt::Orientation orientation, QWidget* parent) : QHeaderView(orientation, parent), isOn(false)
{
    this->setStyleSheet("QHeaderView::section{color: #505050;padding-left: 0px;border: 0.5px solid #E0E0E0; font-size: 12px; font-weight:bold;}");
    this->setSectionResizeMode(QHeaderView::Fixed);
    this->setStretchLastSection(true);
}

void HeaderView::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();
    if (logicalIndex == 0)
    {
        
        if (!isOn)
        {
            //painter->drawRect((5 + rect.width() / 3), rect.height()/6, 12, 12);
            QPixmap pix;
            painter->translate(0, 0);
            //qDebug() << rect.x() << rect.y();
            //qDebug() << rect.width() << rect.height();
            pix.load("res/checkbox_unchecked.png");//加载图片地址 可以是资源文件
            painter->drawPixmap((5 + rect.width() / 3), rect.height() / 6, 13, 13, pix);//绘制图片 横坐标、纵坐标、宽度、高度
        }
        else if (isOn)
        {
            QPixmap pix;
            painter->translate(0, 0);
            pix.load("res/checkbox_checked.png");//加载图片地址 可以是资源文件
            painter->drawPixmap((5 + rect.width() / 3), rect.height() / 6, 13, 13, pix);//绘制图片 横坐标、纵坐标、宽度、高度
        }
       

    }
}

void HeaderView::mousePressEvent(QMouseEvent* event)
{
    //QPoint p_ab = event->globalPos();
    QPoint m_re = event->pos();
    if ((40 <= m_re.x() &&  m_re.x() <= 53) && (4 <= m_re.y() &&  m_re.y() <= 27 ))
    {
       // qDebug() << m_re.x() << m_re.y();
        if (isOn)
        {
            
            isOn = false;
            emit onChangeclicked(isOn);

        }
        else
        {
            
            isOn = true;
            emit onChangeclicked(isOn);
        }
        this->update();
    }
    
    QHeaderView::mousePressEvent(event);
}

HeaderView::~HeaderView()
{
}
