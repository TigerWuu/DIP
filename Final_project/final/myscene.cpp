#include "myscene.h"
#include<QDebug>

myscene::myscene(QObject *parent) : QGraphicsScene(parent)
{
    clearFocus();
}

void myscene::keyPressEvent(QKeyEvent *event)
{
    qDebug("*********MyScene::keyPressEvent***************");
    return QGraphicsScene::keyPressEvent(event);
}

void myscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("*********MyScene::mousePressEvent***************");
    qDebug()<< event->scenePos().x();
    qDebug()<< event->scenePos().y();
    QGraphicsScene::mousePressEvent(event);
}
