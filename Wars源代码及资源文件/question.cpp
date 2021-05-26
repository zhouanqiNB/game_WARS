#include "question.h"
#include<QPainter>
#include<QLabel>
#include"player.h"
#include"mypushbutton.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"choosescene.h"
#include"myCharacter.h"
#include"chooseicon.h"
#include"choosesoldiera.h"
#include"introsoldier.h"
#include<QPainter>
#include"introrule.h"
#include "playtable.h"
#include"mycharacter2.h"
#include"soldier.h"

extern player A;
extern player B;

extern myCharacter* charac;
extern chooseIcon*chooseicon;
extern mycharacter2* charac2;
extern chooseIcon2*chooseicon2;
extern chooseSoldierA* chssd;
extern chooseSoldierb* chssdb;
extern playTable* pt;

QString loadFontFamilyFromFiles(const QString &strFontFilePath);
Question::Question()
{
    this->setFixedSize(640,360);
    setModal(true);

    QString strFont =  loadFontFamilyFromFiles(":/方正像素12.TTF");
    QFont font(strFont);

    QPalette textColor2;
    textColor2.setColor(QPalette::WindowText,QColor(81,49,0));

    QFont font1(font);
    font1.setPointSize(33);
    word=new QLabel(this);
    word->resize(360,208);
    word->move(this->width()/2-180,20);
    word->setFont(font1);
    word->setPalette(textColor2);
    word->setText(QString("小明")+"\n赢得了比赛");

    yesBtn=new myPushButton(":/resource/questionButton.png",":/resource/questionButton2.png");
    yesBtn->resize(QSize(yesBtn->pix.width()*0.65,yesBtn->pix.height()*0.65));
    yesBtn->setIconSize(QSize(yesBtn->pix.width()*0.65,yesBtn->pix.height()*0.65));
    yesBtn->setParent(this);
    yesBtn->move(130,200);
    connect(yesBtn,&QPushButton::clicked,[=](){
        this->close();
        emit quesClose();

    });
}

void Question::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);
}

void Question::setQues(int i){
    if(i==0){
        word->setText(A.name+"\n赢得了比赛");
    }
    if(i==1){
        word->setText(B.name+"\n赢得了比赛");
    }
}

