#include "chooseicon2.h"
#include"player.h"
#include<QPainter>
#include"mypushbutton.h"
#include"mypushbutton2.h"
#include<QDebug>
#include"mycharacter.h"
#include "playtable.h"

extern player A;
extern player B;
extern QString path1[16];
extern QString path2[16];

chooseSoldierA* chssd=NULL;
chooseIcon2::chooseIcon2(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);
    setWindowTitle("Wars");


    //pushbuttons
    {
    //确认，获取角色的头像并且
//    **进入B的取名界面**
    myPushButton* yesBtn=new myPushButton(":/resource/Bcharac1.png",":/resource/Bcharac2.png");
    yesBtn->resize(QSize(yesBtn->pix.width()*0.85,yesBtn->pix.height()*0.85));
    yesBtn->setIconSize(QSize(yesBtn->pix.width()*0.85,yesBtn->pix.height()*0.85));
    yesBtn->setParent(this);
    yesBtn->move(415+250,565+70);
    chssd=new chooseSoldierA(0);
    connect(yesBtn,&QPushButton::clicked,[=](){
        if(which==20){}
        else{
            qDebug()<<icon[which]->common;
            this->hide();
            chssd->show();
        }

    });

    //回到开始
    myPushButton* homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setParent(this);
    homeBtn->move(824+250,567+70);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->chooseIconHome();
    });

    //回到前一个
    myPushButton* backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setParent(this);
    backBtn->move(1000+250,567+70);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->chooseIconBack();
    });
}
    //icons

    for(int i=0;i<16;i++){
        icon[i]=new myPushButton2(path1[i],path2[i]);
        icon[i]->resize(QSize(138,138));
        icon[i]->setIconSize(QSize(138,138));
        icon[i]->setParent(this);
        icon[i]->move(216+(i%8)*147,307+i/8*147);
        connect(icon[i],&QPushButton::clicked,[=](){
            if(which==20){}
            else{
                icon[which]->notClicked();
            }
            which=i;
            B.setIcon(icon[i]->common);
            icon[i]->beClicked();
        });
    }
    //从下一个页面回来
    connect(chssd,&chooseSoldierA::Back,[=](){
        chssd->hide();
        this->show();
    });
}

void chooseIcon2::paintEvent(QPaintEvent *event){

    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(":/resource/icontext.png");
    painter.drawPixmap(180,130,pix2.width()*0.6,pix2.height()*0.6,pix2);

    QPixmap pix3;
    pix3.load(":/resource/iconsquare.png");
    painter.drawPixmap((this->width()-pix3.width()*1.05)/2,(this->height()-pix3.height()*1.05)/2,pix3.width()*1.05,pix3.height()*1.05,pix3);



}
