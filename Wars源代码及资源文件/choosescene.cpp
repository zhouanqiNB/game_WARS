#include "choosescene.h"
#include"mypushbutton.h"
#include"introstory.h"
#include"player.h"
#include"mycharacter.h"
#include<QPainter>
#include "playtable.h"

myCharacter* charac=NULL;
introStory* intro=NULL;
introSoldier* soldier=NULL;
introRule* rule=NULL;

chooseScene::chooseScene(QWidget *parent) : QMainWindow(parent)
{
    //设置大小
    this->setFixedSize(1600,900);
    setWindowTitle("Wars");

    //按钮
    {//可以进入给人物命名界面
    newBtn=new myPushButton(":/resource/Bnew1.png",":/resource/Bnew2.png");
    newBtn->setParent(this);
    newBtn->move(315,130);
    charac=new myCharacter(0);
    connect(newBtn,&QPushButton::clicked,[=](){
        this->hide();
        charac->show();
    });

    //进入游戏背景介绍界面
    introBtn=new myPushButton(":/resource/Bintro1.png",":/resource/Bintro2.png");
    introBtn->setParent(this);
    introBtn->move(315,250);
    intro=new introStory(0);
    connect(introBtn,&QPushButton::clicked,[=](){
        this->hide();
        intro->show();
    });

    //进入游戏规则介绍界面
    ruleBtn=new myPushButton(":/resource/Brule1.png",":/resource/Brule2.png");
    ruleBtn->setParent(this);
    ruleBtn->move(315,370);
    rule=new introRule(0);
    connect(ruleBtn,&QPushButton::clicked,[=](){
        this->hide();
        rule->show();
    });

    //进入士兵画像界面
    soldierBtn=new myPushButton(":/resource/Bsoldier1.png",":/resource/Bsoldier2.png");
    soldierBtn->setParent(this);
    soldierBtn->move(315,490);
    soldier=new introSoldier(0);
    connect(soldierBtn,&QPushButton::clicked,[=](){
        this->hide();
        soldier->show();
    });

    //返回开始界面
    backBtn=new myPushButton(":/resource/Bback1.png",":/resource/Bback2.png");
    backBtn->setParent(this);
    backBtn->move(315,610);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->chooseSceneBack();
    });}

    //从选人物界面回来
    connect(charac,&myCharacter::myCharacterBack,[=](){
        charac->hide();
        this->show();
    });

    //从intro界面回来
    {connect(intro,&introStory::introBack,[=](){
        intro->hide();
        this->show();
    });

    connect(soldier,&introSoldier::Back,[=](){
        soldier->hide();
        this->show();
    });

    connect(rule,&introRule::Back,[=](){
        rule->hide();
        this->show();
    });}
}

void chooseScene::paintEvent(QPaintEvent *event){

    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);
}
