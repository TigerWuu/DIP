#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

class myview : public QGraphicsView
{
public:
    explicit myview();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MYVIEW_H
