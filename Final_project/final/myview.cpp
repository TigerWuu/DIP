#include "myview.h"
#include <QKeyEvent>

myview::myview()
{

}
void myview::keyPressEvent(QKeyEvent *event)
{
   qDebug("*********MyView::keyPressEvent***************");
    switch (event->key())
    {
    case Qt::Key_Left :
        scale(1.2, 1.2);
        break;
    case Qt::Key_Right :
        scale(1 / 1.2, 1 / 1.2);
        break;
    case Qt::Key_Up :
        rotate(30);
        break;
    }
    QGraphicsView::keyPressEvent(event);
}

void myview::mousePressEvent(QMouseEvent *event)
{
    qDebug("************MyView::mousePressEvent*****************");
    QGraphicsView::mousePressEvent(event);
}

void myview::paintEvent(QPaintEvent *event)
{
    qDebug("************MyView::paintEvent*****************");
    QGraphicsView::paintEvent(event);
}

void myview::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug("************MyView::mouseMoveEvent*****************");
    QGraphicsView::mouseMoveEvent(event);
}
