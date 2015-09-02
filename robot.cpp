#include "robot.h"
Robot::Robot() {}
Robot::Robot(QString imageFile){
    setFlag(ItemIsMovable);
    QPixmap original=QPixmap(":/images/"+imageFile);
    pm=original.scaled(100,100);
}
QRectF Robot:: boundingRect()const{
    return QRectF(0,0,pm.width(),pm.height());
}
void Robot::move() {
    this->setX(this->x()+1);
    this->setY(this->y()+1);
}
void Robot:: paint(QPainter* painter,const QStyleOptionGraphicsItem*
                   option,QWidget* widget,int x,int y){
    painter->drawPixmap(QPoint(x,y),pm);
}

