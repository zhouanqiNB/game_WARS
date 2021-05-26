#include "mypushbutton2.h"
#include<QString>
#include<QPushButton>

myPushButton2::myPushButton2()
{
    this->setStyleSheet("QPushButton{border:0px}");
}
myPushButton2::myPushButton2(QString common,QString click)
{
    this->common=common;
    this->click=click;

    pix.load(common);

    this->resize(pix.width()*0.65,pix.height()*0.65);
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width()*0.65,pix.height()*0.65));

}

void myPushButton2::beClicked(){
    QPixmap pix1;
    pix1.load(click);
    this->setIcon(pix1);
    isClicked=true;
}
void myPushButton2::notClicked(){
    QPixmap pix1;
    pix1.load(common);
    this->setIcon(pix1);
    isClicked=false;
}
void myPushButton2::loadIcon(const QString &icon){
    pix.load(icon);
    this->setIcon(pix);
}


