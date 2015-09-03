#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include <QGraphicsView>
#include "counterscene.h"

class CustomGraphicsView :public QGraphicsView
{
    Q_OBJECT
public:
    CounterScene* currentScene;
    CustomGraphicsView();
};

#endif // CUSTOMGRAPHICSVIEW_H
