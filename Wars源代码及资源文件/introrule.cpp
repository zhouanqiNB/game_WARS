#include "introrule.h"
#include"mypushbutton.h"
#include"mypushbutton2.h"
#include<QPainter>

introRule::introRule(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);
    bg[0]=":/resource/rule1.png";
    bg[1]=":/resource/rule2.png";
    bg[2]=":/resource/rule3.png";
    bg[3]=":/resource/rule4.png";
    bg[4]=":/resource/rule5.png";
    bg[5]=":/resource/rule6.png";

    p[0]=":/resource/page1.png";
    p[1]=":/resource/page2.png";
    p[2]=":/resource/page3.png";
    p[3]=":/resource/page4.png";
    p[4]=":/resource/page5.png";
    p[5]=":/resource/page6.png";


    myPushButton*left=new myPushButton(":/resource/left1.png",":/resource/left2.png");
    left->resize(QSize(left->pix.width()*0.90,left->pix.height()*0.90));
    left->setIconSize(QSize(left->pix.width()*0.90,left->pix.height()*0.90));
    left->setParent(this);
    left->move(78,350);
    connect(left,&myPushButton::clicked,[=](){
        if(page!=0)
            page--;
        update();
    });

    myPushButton*right=new myPushButton(":/resource/right1.png",":/resource/right2.png");
    right->resize(QSize(right->pix.width()*0.90,right->pix.height()*0.90));
    right->setIconSize(QSize(right->pix.width()*0.90,right->pix.height()*0.90));
    right->setParent(this);
    right->move(1400,350);
    connect(right,&myPushButton::clicked,[=](){
        if(page!=5)
            page++;
        update();
    });

    myPushButton*homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setParent(this);
    homeBtn->move(834+200,130);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->Home();
    });
    myPushButton*backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setParent(this);
    backBtn->move(1000+200,130);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->Back();
    });

}

void introRule::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(bg[page]);
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(p[page]);
    painter.drawPixmap(760,782,pix2.width(),pix2.height(),pix2);
}
