#include "gamesmanager.h"

    GamesManager::GamesManager() {
        nameList.append("blue");
        nameList.append("lime");
        nameList.append("beige");
        foodList.append("blue");
        foodList.append("red");
        foodList.append("green");
        foodList.append("blue");
    }
    QVector<QString>GamesManager:: getNameList(){
        return nameList;
    }
    QVector<QString>GamesManager:: getFoodList(){
        return foodList;
    }
    bool GamesManager:: nameListIsEmpty(){
        return nameList.count()==0;
    }
    bool GamesManager::foodListIsEmpty(){
        return foodList.count()==0;
    }
    void GamesManager::addItemToNameList(QString newItem){
        nameList.append(newItem);
    }
    void GamesManager::addItemToFoodList(QString newItem){
        foodList.append(newItem);
    }
    void GamesManager::buildMeatWidgets(QVector<QString>meatNames){

    }
    void GamesManager::buildSaladWidgets(QVector<QString>saladNames) {

    }
    void GamesManager::buildSauceWidgets(QVector<QString>sauceNames){

    }
