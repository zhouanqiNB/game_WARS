#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mypushbutton.h"
#include"choosescene.h"
#include"myCharacter.h"
#include"player.h"
#include"chooseicon.h"
#include"choosesoldiera.h"
#include"introsoldier.h"
#include<QPainter>
#include"introrule.h"
#include "playtable.h"
#include"question.h"
#include"mycharacter2.h"

chooseScene* choose=NULL;

extern myCharacter* charac;
extern introStory* intro;
extern introSoldier* soldier;
extern introRule* rule;

extern chooseIcon*chooseicon;
extern chooseIcon2*chooseicon2;
extern mycharacter2* charac2;
extern chooseSoldierA* chssd;
extern chooseSoldierb* chssdb;



Question* que;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    que=new Question;
    connect(que,&Question::quesClose,[=](){

        this->show();
    });

    choose=new chooseScene(0);

    //设置主窗口大小,icon，名称
    this->setFixedSize(1600,900);
    setWindowTitle("Wars");

    //写按钮,开始，退出
    startBtn=new myPushButton(":/resource/Bstart1.png",":/resource/Bstart2.png");
    startBtn->setParent(this);
    startBtn->move(315,450);
    connect(startBtn,&QPushButton::clicked,[=](){this->hide();choose->show();});

    closeBtn=new myPushButton(":/resource/Bexit1.png",":/resource/Bexit2.png");
    closeBtn->setParent(this);
    closeBtn->move(315,576);
    connect(closeBtn,&QPushButton::clicked,this,&close);


    //从目录界面回来
    {
    connect(choose,&chooseScene::chooseSceneBack,[=](){choose->hide();this->show();});

    //从命名界面A回来
    connect(charac,&myCharacter::myCharacterHome,[=](){charac->hide();this->show();});

    //从选头像界面A回来
    connect(chooseicon,&chooseIcon::chooseIconHome,[=](){chooseicon->hide();this->show();});

    //从命名界面B回来
    connect(charac2,&mycharacter2::myCharacter2Home,[=](){charac2->hide();this->show();});

    //从选头像界面B回来
    connect(chooseicon2,&chooseIcon2::chooseIconHome,[=](){chooseicon2->hide();this->show();});

    //从choosesoldier回来
    connect(chssd,&chooseSoldierA::Home,[=](){chssd->hide();this->show();});

    //从choosesoldier的book回来
    connect(chssd->in,&introSoldier::Home,[=](){chssd->in->hide();this->show();});

    //从choosesoldierb回来
    connect(chssdb,&chooseSoldierb::Home,[=](){chssdb->hide();this->show();});

    //从choosesoldierb的book回来
    connect(chssdb->in,&introSoldier::Home,[=](){chssdb->in->hide();this->show();});


    //从介绍士兵回来
    connect(soldier,&introSoldier::Home,[=](){soldier->hide();this->show();});

    //从介绍规则回来
    connect(rule,&introRule::Home,[=](){rule->hide();this->show();});

    //从intro界面回来
    connect(intro,&introStory::introHome,[=](){intro->hide();this->show();});
    }




}

void MainWindow::paintEvent(QPaintEvent *event){

    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(":/resource/picture.png");
    painter.drawPixmap(0,0,pix2.width(),pix2.height(),pix2);

    QPixmap pix3;
    pix3.load(":/resource/title3.png");
    painter.drawPixmap(315,180,pix3.width()*0.65,pix3.height()*0.65,pix3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
