#include "counterscene.h"

CounterScene::CounterScene (){
    gamesManager=new GamesManager();
}
void CounterScene:: buildScene(GamesManager* gameLoader){
    QVector<QString> list=gamesManager->getNameList();

    gameItem=new GraphicsWidget(list.value(1)+".png",this->width(),this->height(),this);
    this->addItem(gameItem);
}
void CounterScene::buildCounter(GamesManager* gameLoader,int counterType){
    QString color;
    if(counterType==1){
        color="yellow";
    }else {
        color="red";
    }
    gameItem=new GraphicsWidget(color+".png",this->width(),this->height()/4,this);
    gameItem->setPos(QPointF(0,(this->height()/4)*3));

    QVector<QString>list=gamesManager->getFoodList();
    QGraphicsLinearLayout* layout=new QGraphicsLinearLayout;
    qreal layoutScale=Sqr(list.count());
    qreal tileSize=list.count()+1;
    layout->setSpacing(this->width()/layoutScale);

    foreach(QString name,list){
        GraphicsWidget* foodItem;
        foodItem=new GraphicsWidget(name+".png",this->width()/tileSize,100,this);
        layout->addItem(foodItem);
        counterItems.append(foodItem);
        connect(foodItem,SIGNAL(getNewFood(QString,int,int)),this,SLOT(setGraphicsWidget(QString,int,int)));
    }
    gameItem->setLayout(layout);
    this->addItem(gameItem);
}
void CounterScene:: setIsPressed(bool value){
    isPressed=value;
}
void CounterScene::buildItemList(){

}
//    void mousePressEvent(QGraphicsSceneMouseEvent *event){

//        isPressed=true;
//        gameItem=new GraphicsWidget("blue.png",this->width(),this->height()/4);
//        gameItem->setPos(QPointF(0,0));
//        this->addItem(gameItem);
//        GraphicsWidget* currentSelection = counterItems.at(0);
//        qreal shortestDist = currentSelection->sceneBoundingRect().height()/2;
//        foreach(GraphicsWidget* item, counterItems){
//            QLineF line(item->sceneBoundingRect().center(),
//                        event->scenePos());
//            if(line.length() < shortestDist){
//                isValid=true;
//                shortestDist = line.length();
//                currentSelection = item;
//                qDebug()<<currentSelection->parent()->;
//            }
//        }
//        if(isValid){
//            gameItem=new GraphicsWidget(currentSelection->name,this->height()/10,this->height()/10);
//            gameItem->setPos(event->scenePos().x(),event->scenePos().y());
//            this->addItem(gameItem);
//        }
//    }
void CounterScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(isPressed){
        gameItem->setPos(QPoint(event->scenePos().x(),event->scenePos().y()));
    }
}
void CounterScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    isPressed=false;
    int y=event->scenePos().y();
    if(y>=(this->height()/4)*3|y<=height()/4)
        delete(gameItem);
}
void CounterScene:: setGraphicsWidget(QString widgetName, int x, int y){
    gameItem=new GraphicsWidget(widgetName,this->height()/10,this->height()/10,this);
    gameItem->setPos(x,y);
    this->addItem(gameItem);
}


