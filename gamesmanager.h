#ifndef GAMESMANAGER_H
#define GAMESMANAGER_H
#include <QVector>
#include <QString>

class GamesManager
{
private:
    QVector<QString> nameList;
    QVector<QString> foodList;
public:
    GamesManager();
    QVector<QString> getNameList();
    QVector<QString> getFoodList();
    bool nameListIsEmpty();
    bool foodListIsEmpty();
    void addItemToNameList(QString newItem);
    void addItemToFoodList(QString newItem);
    void buildMeatWidgets(QVector<QString>meatNames);
    void buildSaladWidgets(QVector<QString>saladNames);
    void buildSauceWidgets(QVector<QString>sauceNames);
};

#endif // GAMESMANAGER_H
