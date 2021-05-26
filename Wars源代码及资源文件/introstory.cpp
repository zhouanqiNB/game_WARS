#include "introstory.h"
#include<QPainter>
#include"mypushbutton.h"



introStory::introStory(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);



    //回到开始
    homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setParent(this);
    homeBtn->move(824+180,677);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->introHome();
    });

    //回到chooseScene
    backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setParent(this);
    backBtn->move(1000+180,677);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->introBack();
    });

}

void introStory::paintEvent(QPaintEvent *event){

    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    //文字
    QPixmap pix2;
    pix2.load(":/resource/story.png");
    painter.drawPixmap((this->width()-pix2.width()*0.6)/2,(this->height()-pix2.height()*0.6)/2-40,pix2.width()*0.6,pix2.height()*0.6,pix2);
}
