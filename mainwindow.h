#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define Sqr(x) ((x)*(x))

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVector>
#include <QGraphicsLinearLayout>

class CounterScene;
class CustomGraphicsView;
class GamesManager;
class GraphicsWidget;

class GraphicsWidget: public QGraphicsWidget{
private:
    QPixmap pm;
public:
    QString name;
    QRectF boundingRect() const{
        return QRectF(0,0,pm.width(),pm.height());
    }
    GraphicsWidget(QString fileName,int scaleW,int scaleH){
        name=fileName;
        QPixmap original=QPixmap(":/images/"+fileName);
        pm=original.scaled(scaleW,scaleH);
        setGeometry(this->pos().x(),this->pos().y(),scaleW,scaleH);
    }
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget){
        painter->drawPixmap(QPoint(0,0),pm);
    }
    ~GraphicsWidget(){
    }
};
class GamesManager{
private:
    QVector<QString> nameList;
    QVector<QString> foodList;
public:
    GamesManager() {
        nameList.append("blue");
        nameList.append("lime");
        nameList.append("beige");
        foodList.append("blue");
        foodList.append("red");
        foodList.append("green");
        foodList.append("blue");
    }
    QVector<QString> getNameList(){
        return nameList;
    }
    QVector<QString> getFoodList(){
        return foodList;
    }
    bool nameListIsEmpty(){
        return nameList.count()==0;
    }
    bool foodListIsEmpty(){
        return foodList.count()==0;
    }
    void addItemToNameList(QString newItem){
        nameList.append(newItem);
    }
    void addItemToFoodList(QString newItem){
        foodList.append(newItem);
    }
    void buildMeatWidgets(QVector<QString>meatNames){

    }
    void buildSaladWidgets(QVector<QString>saladNames) {

    }
    void buildSauceWidgets(QVector<QString>sauceNames){

    }

};
class CustomGraphicsView:public QGraphicsView{
    Q_OBJECT
public:
    CounterScene* currentScene;
    CustomGraphicsView() {
    }

    void connectTestButton(){
        //        if(currentScene!=NULL){
        //            connect(currentScene,SIGNAL(mySignal(),this,SLOT(changeScene());
        //        }
    }
public slots:
    void changeScene(QString sceneName){
        //setScene(sceneMapper.value(sceneName));
        qDebug()<<"**clicked";
        //setScene(scene);
    }

};
class CounterScene:public QGraphicsScene{
    Q_OBJECT
private:
    GraphicsWidget* gameItem;
    GamesManager* gamesManager;
    QVector<GraphicsWidget*> counterItems;
    bool isPressed=false;
    bool isValid=false;

public:
    explicit CounterScene (QObject* parent=0){
        gamesManager=new GamesManager();
    }
    void buildScene(GamesManager* gameLoader){
        QVector<QString> list=gamesManager->getNameList();

        gameItem=new GraphicsWidget(list.value(1)+".png",this->width(),this->height());
        this->addItem(gameItem);

    }
    void buildCounter(GamesManager* gameLoader,int counterType){
        QString color;
        if(counterType==1){
            color="yellow";
        }else {
            color="red";
        }
        gameItem=new GraphicsWidget(color+".png",this->width(),this->height()/4);
        gameItem->setPos(QPointF(0,(this->height()/4)*3));

        QVector<QString>list=gamesManager->getFoodList();
        QGraphicsLinearLayout* layout=new QGraphicsLinearLayout;
        qreal layoutScale=Sqr(list.count());
        qreal tileSize=list.count()+1;
        layout->setSpacing(this->width()/layoutScale);

        foreach(QString name,list){
            GraphicsWidget* foodItem;
            foodItem=new GraphicsWidget(name+".png",this->width()/tileSize,100);
            layout->addItem(foodItem);
            counterItems.append(foodItem);
        }
        gameItem->setLayout(layout);
        this->addItem(gameItem);
    }
    void buildItemList(){

    }
    void mousePressEvent(QGraphicsSceneMouseEvent *event){

        isPressed=true;
        gameItem=new GraphicsWidget("blue.png",this->width(),this->height()/4);
        gameItem->setPos(QPointF(0,0));
        this->addItem(gameItem);
        GraphicsWidget* currentSelection = counterItems.at(0);
        qreal shortestDist = currentSelection->sceneBoundingRect().height()/2;
        foreach(GraphicsWidget* item, counterItems){
            QLineF line(item->sceneBoundingRect().center(),
                        event->scenePos());
            if(line.length() < shortestDist){
                isValid=true;
                shortestDist = line.length();
                currentSelection = item;
                qDebug()<<currentSelection->parent()->objectName();
            }
        }
        if(isValid){
            gameItem=new GraphicsWidget(currentSelection->name,this->height()/10,this->height()/10);
            gameItem->setPos(event->scenePos().x(),event->scenePos().y());
            this->addItem(gameItem);
        }
    }
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event){
        if(isPressed&& isValid){
            gameItem->setPos(QPoint(event->scenePos().x(),event->scenePos().y()));
            // mySignal(event->scenePos().x(),event->scenePos().y());
        }
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
        isPressed=false;
        isValid=false;
        int y=event->scenePos().y();
        if(y>=(this->height()/4)*3|y<=height()/4)
            delete(gameItem);
        emit mySignal();
    }
    QString mySignal(){
        return "works";
    }
signals:
    void mySignal(QString sceneName);
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    void mySlot(int x,int y){
    }
private slots:

};

#endif // MAINWINDOW_H
