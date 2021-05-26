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


chooseIcon* chooseicon=NULL;

myCharacter::myCharacter(QWidget *parent) : QMainWindow(parent)
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
    chooseicon=new chooseIcon(0);
    connect(yesBtn,&QPushButton::clicked,[=](){
        A.setName(name->toPlainText());
        if(A.name==""){}
        else{
            qDebug()<<"A  "<<A.name;
            this->hide();
            chooseicon->show();
        }
    });

    //回到开始
    homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setParent(this);
    homeBtn->move(824+20,567);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->myCharacterHome();
    });

    //回到前一个
    backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setParent(this);
    backBtn->move(1000+20,567);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->myCharacterBack();
    });}

    //从选头像A界面回来
    connect(chooseicon,&chooseIcon::chooseIconBack,[=](){
        chooseicon->hide();
        this->show();
    });


}

void myCharacter::paintEvent(QPaintEvent *){
    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(":/resource/characword.png");
    painter.drawPixmap(420+20,200,pix2.width()*0.6,pix2.height()*0.6,pix2);
}
