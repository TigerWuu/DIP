#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPaintEvent>
#include <QKeyEvent>

class myscene : public QGraphicsScene
{
public:
    explicit myscene(QObject *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSCENE_H
