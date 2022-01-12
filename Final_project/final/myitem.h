#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

class myitem : public QGraphicsItem
{
public:
    myitem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
    void setColor(const QColor &color) { brushColor = color; }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QColor brushColor;
};

#endif // MYITEM_H
