#include "soldier.h"

Soldier::Soldier(QObject *parent) : QObject(parent)
{

}

void Soldier::setSoldier(QString na){
    if(na=="酒诗"){
        lifeValue=8;
        attackValue=4;
        distance=2;
        character=0;
        icon=":/soldier/jiushi1.png";
        emit lifeChanged("8");
        emit attackChanged("4");
        emit distanceChanged("2");
        return;
    }
    if(na=="据守"){
        lifeValue=10;
        attackValue=3;
        distance=2;
        character=1;
        icon=":/soldier/jushou1.png";
        emit lifeChanged("10");
        emit attackChanged("3");
        emit distanceChanged("2");
        return;
    }
    if(na=="狂镰"){
        lifeValue=24;
        attackValue=2;
        distance=1;
        character=2;
        icon=":/soldier/kuanglian1.png";
        emit lifeChanged("24");
        emit attackChanged("2");
        emit distanceChanged("1");
        return;
    }
    if(na=="烈弓"){
        lifeValue=10;
        attackValue=4;
        distance=5;
        character=3;
        icon=":/soldier/liegong1.png";
        emit lifeChanged("10");
        emit attackChanged("4");
        emit distanceChanged("5");
        return;
    }
    if(na=="密令"){
        lifeValue=10;
        attackValue=4;
        distance=5;
        character=4;
        icon=":/soldier/miling1.png";
        emit lifeChanged("10");
        emit attackChanged("4");
        emit distanceChanged("5");
        return;
    }
    if(na=="琴音"){
        lifeValue=10;
        attackValue=3;
        distance=2;
        character=5;
        icon=":/soldier/qinyin1.png";
        emit lifeChanged("10");
        emit attackChanged("3");
        emit distanceChanged("2");
        return;
    }
    if(na=="神速"){
        lifeValue=15;
        attackValue=3;
        distance=1;
        character=6;
        icon=":/soldier/shensu1.png";
        emit lifeChanged("15");
        emit attackChanged("3");
        emit distanceChanged("1");
        return;
    }
    if(na=="死吻"){
        lifeValue=8;
        attackValue=4;
        distance=2;
        character=7;
        icon=":/soldier/siwen1.png";
        emit lifeChanged("8");
        emit attackChanged("4");
        emit distanceChanged("2");
        return;
    }
    if(na=="无双"){
        lifeValue=24;
        attackValue=2;
        distance=1;
        character=8;
        icon=":/soldier/wushuang1.png";
        emit lifeChanged("24");
        emit attackChanged("2");
        emit distanceChanged("1");
        return;
    }
    if(na=="陷阵"){
        lifeValue=15;
        attackValue=3;
        distance=1;
        character=9;
        icon=":/soldier/xianzhen1.png";
        emit lifeChanged("15");
        emit attackChanged("3");
        emit distanceChanged("1");
        return;
    }

}

QString Soldier::getIcon()const{
    return icon;
}
void Soldier::setIcon(QString i){
    icon=i;
    emit iconChanged(icon);
}


QString Soldier::getName()const{
    return name;
}
void Soldier::setName(QString i){
    name=i;
    emit nameChanged(name);
}
void Soldier::lifeThing(){
    emit lifeChanged(QString(this->lifeValue));
}
