#include "player.h"
#include<QDebug>

player::player(QObject *parent) : QObject(parent)
{

}
QString player::getIcon()const{
    return headIcon;
}
void player::setIcon(QString i){
    headIcon=i;
    emit iconChanged(headIcon);
}

QString player::getName()const{
    return name;
}
void player::setName(QString i){
    name=i;
    emit nameChanged(name);
}
