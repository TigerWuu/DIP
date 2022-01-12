#ifndef QGRAPHICSCIRCLEITEM_H
#define QGRAPHICSCIRCLEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

#include <QGraphicsSceneMouseEvent>

class QGraphicsCircleItem : public QGraphicsItem
{
public:
    QGraphicsCircleItem(double radius,int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int new_x;
    int new_y;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    double radius;
    int x;
    int y;


};

#endif // QGRAPHICSCIRCLEITEM_H
