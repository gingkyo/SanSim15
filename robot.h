#ifndef ROBOT_H
#define ROBOT_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QThread>
#include <QDebug>

class Robot :public QGraphicsItem
{
public:
    Robot();
    Robot(QString imageFile);
    QPixmap pm;
    QRectF boundingRect()const;
    void move();
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget,int x,int y);

};

#endif // ROBOT_H

