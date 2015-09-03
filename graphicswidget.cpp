#include "graphicswidget.h"


GraphicsWidget::GraphicsWidget(QString fileName,int scaleW,int scaleH,QGraphicsScene* scene){
    name=fileName;
    QPixmap original=QPixmap(":/images/"+fileName);
    pm=original.scaled(scaleW,scaleH);
    setGeometry(this->pos().x(),this->pos().y(),scaleW,scaleH);
    this->scene=scene;
}
void GraphicsWidget::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(QPoint(0,0),pm);
}
void GraphicsWidget::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit getNewFood(this->name,event->scenePos().x(),event->scenePos().y());
    CounterScene* widget = qobject_cast<CounterScene *>(scene);
    widget->setIsPressed(true);
}
QRectF GraphicsWidget:: boundingRect() const{
    return QRectF(0,0,pm.width(),pm.height());
}
