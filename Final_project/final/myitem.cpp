#include "myitem.h"
#include<QDebug>


myitem::myitem()
{
    brushColor = Qt::red;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    //setAcceptHoverEvents(true);
}

QRectF myitem::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-10 - adjust, -10 - adjust,
                  20 + adjust, 20 + adjust);
}

void myitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{   qDebug("************MyItem::paint*****************");
    if(hasFocus()) {
        painter->setPen(QPen(QColor(255,255,255,200)));
    } else {
        painter->setPen(QPen(QColor(100,100,100,100)));
    }
    painter->setBrush(brushColor);
    painter->drawRect(-10, -10, 20, 20);
}
void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("************MyItem::mousePressEvent*****************");
    qDebug()<< scenePos().x();
    qDebug()<< scenePos().y();

}
