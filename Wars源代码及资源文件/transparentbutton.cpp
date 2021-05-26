#include "transparentbutton.h"
#include<QPushButton>
#include"mypushbutton2.h"

transparentButton::transparentButton(QString common,QString click) : myPushButton2(common,click)
{
    this->common=common;
    this->click=click;

    connect(this,&QPushButton::clicked,[=](){
        beClicked();
    });

}
