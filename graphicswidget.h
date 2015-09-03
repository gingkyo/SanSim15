#ifndef GRAPHICSWIDGET_H
#define GRAPHICSWIDGET_H
#include <QGraphicsWidget>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "counterscene.h"

class GraphicsWidget :public QGraphicsWidget {
    Q_OBJECT
private:
    QPixmap pm;
public:
    QString name;
    QGraphicsScene* scene;
    QRectF boundingRect() const;
    GraphicsWidget(QString fileName,int scaleW,int scaleH,QGraphicsScene* scene);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~GraphicsWidget(){
    }
signals:
     void getNewFood(QString,int,int);
};

#endif // GRAPHICSWIDGET_H
