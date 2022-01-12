#include "qgraphicscircleitem.h"

QGraphicsCircleItem::QGraphicsCircleItem(double radius, int x,int y)
{
    this->radius = radius;
    this->x = x;
    this->y = y;
    this->new_x = x;
    this->new_y = y;
    qDebug()<< this->new_x;
    qDebug()<< this->new_y;
}

QRectF QGraphicsCircleItem::boundingRect() const{

    return QRectF(this->x-radius,this->y-radius,2*radius,2*radius);
}

void QGraphicsCircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPointF(this->x,this->y), radius, radius);
}
void QGraphicsCircleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    this->new_x = event->scenePos().x();
    this->new_y = event->scenePos().y();
    qDebug()<< this->new_x;
    qDebug()<< this->new_y;

    QGraphicsItem::mouseReleaseEvent(event);
}
