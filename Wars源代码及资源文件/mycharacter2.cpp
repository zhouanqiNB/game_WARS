#include"mycharacter2.h"
#include"mycharacter.h"
#include"mypushbutton.h"
#include"player.h"
#include<QPainter>
#include<QPixmap>
#include<QString>
#include<QFrame>
#include<QDebug>
#include "playtable.h"
#include"question.h"
QString loadFontFamilyFromFiles(const QString &strFontFilePath);
extern player A;
extern player B;

extern chooseIcon* chooseicon;
chooseIcon2* chooseicon2=NULL;
mycharacter2::mycharacter2(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);




    //输入角色名字
    name=new QTextEdit(this);
    name->resize(700,100);
    name->move(690+80,435);
    QString strFont =  loadFontFamilyFromFiles(":/方正像素12.TTF");
    QFont font(strFont);
    name->setFont(font);
    name->setStyleSheet("font-size : 90px");
    name->setTextColor(QColor(80,48,0));
    QPalette pal = name->palette();
    pal.setBrush(QPalette::Base, QColor(254,215,133));
    name->setPalette(pal);
    name->setFrameStyle(QFrame::NoFrame);


    //pushbuttons
    {//确认，获取角色的名字并且
//    **进入选择头像界面**
    yesBtn=new myPushButton(":/resource/Bcharac1.png",":/resource/Bcharac2.png");
    yesBtn->resize(QSize(yesBtn->pix.width()*0.85,yesBtn->pix.height()*0.85));
    yesBtn->setIconSize(QSize(yesBtn->pix.width()*0.85,yesBtn->pix.height()*0.85));
    yesBtn->setParent(this);
    yesBtn->move(415+20,565);
    chooseicon2=new chooseIcon2(0);
    connect(yesBtn,&QPushButton::clicked,[=](){
        B.setName(name->toPlainText());
        if(B.name==""){}
        else{
            qDebug()<<"B   "<<B.name;
            this->hide();
            chooseicon2->show();
        }
    });

    //回到开始
    homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setParent(this);
    homeBtn->move(824+20,567);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->myCharacter2Home();
    });

    //回到前一个
    backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setParent(this);
    backBtn->move(1000+20,567);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->myCharacter2Back();
    });}

    //从选头像B界面回来
    connect(chooseicon2,&chooseIcon2::chooseIconBack,[=](){
        chooseicon2->hide();
        this->show();
    });




}

void mycharacter2::paintEvent(QPaintEvent *){
    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(":/resource/characword2.png");
    painter.drawPixmap(420+20,200,pix2.width()*0.6,pix2.height()*0.6,pix2);
}
