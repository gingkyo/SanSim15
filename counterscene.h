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
    GraphicsWidget* gameItem;
    GamesManager* gamesManager;
    QVector<GraphicsWidget*> counterItems;
    bool isPressed=false;
    bool isValid=false;

public:
    CounterScene ();
    void buildScene(GamesManager* gameLoader);
    void buildCounter(GamesManager* gameLoader,int counterType);
    void buildItemList();
    //    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void setGraphicsWidget(QString widgetName, int x, int y);
};

#endif // COUNTERSCENE_H
