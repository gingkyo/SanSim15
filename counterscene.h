#ifndef COUNTERSCENE_H
#define COUNTERSCENE_H
#define Sqr(x) ((x)*(x))
#include <QGraphicsScene>
#include <QGraphicsLinearLayout>
#include <QGraphicsSceneMouseEvent>
#include "graphicswidget.h"
#include "gamesmanager.h"

class CounterScene :public QGraphicsScene {
    Q_OBJECT
private:
    QGraphicsWidget* gameItem;
    GamesManager* gamesManager;
    QVector<QGraphicsWidget*> counterItems;
    bool isPressed=false;
    bool isValid=false;

public:
    CounterScene ();
    void buildScene(GamesManager* gameLoader);
    void buildCounter(GamesManager* gameLoader,int counterType);
    void buildItemList();
    //    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    void setIsPressed(bool value);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void setGraphicsWidget(QString,int,int);
};

#endif // COUNTERSCENE_H
