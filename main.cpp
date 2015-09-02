#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //w.show();




    GamesManager* gameLoader=new GamesManager();
    CustomGraphicsView*view=new CustomGraphicsView();
    //view->showFullScreen();
    CounterScene* counterScene=new CounterScene();
    counterScene->setSceneRect(0,0,view->width(),view->height());
    counterScene->buildScene(gameLoader);
    counterScene->buildCounter(gameLoader,1);
    //view->addSceneToMapper("meatCounter",counterScene);

    CounterScene* counterScene2=new CounterScene();
    counterScene2->setSceneRect(0,0,view->width(),view->height());
    counterScene2->buildScene(gameLoader);
    counterScene2->buildCounter(gameLoader,2);
    //view->addSceneToMapper("tempCounter",counterScene);

    view->setScene(counterScene);
    view->currentScene=counterScene;
//    CustomGraphicsView* view2=new CustomGraphicsView();
//    view2->setSceneRect(0,0,view2->width(),100);
//    view2->setScene(counterScene);

//    QWidget* widget=new QWidget();
//    QVBoxLayout* vlayout=new QVBoxLayout(widget);
//    //vlayout->setOrientation(Qt::Vertical);
//    vlayout->setSpacing(0);
//    vlayout->setContentsMargins(0,0,0,0);
//    vlayout->addWidget(view2);
//    vlayout->addWidget(view);


//     widget->show();
    view->show();
    delete gameLoader;

    return a.exec();
}
