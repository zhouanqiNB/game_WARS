#include "choosesoldiera.h"
#include<QPainter>
#include"mypushbutton2.h"
#include"mypushbutton.h"
#include<QString>
#include"player.h"
#include<QImage>
#include<transparentbutton.h>
#include<QDebug>
#include"introsoldier.h"
#include "playtable.h"
#include"mycharacter.h"
extern player A;
extern player B;


chooseSoldierb* chssdb=NULL;
chooseSoldierA::chooseSoldierA(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);


    //pushbuttons
    //图鉴

    myPushButton* bookBtn=new myPushButton(":/resource/Bbook1.png",":/resource/Bbook2.png");
    bookBtn->resize(QSize(bookBtn->pix.width()*0.90,bookBtn->pix.height()*0.90));
    bookBtn->setIconSize(QSize(bookBtn->pix.width()*0.90,bookBtn->pix.height()*0.90));
    bookBtn->setParent(this);
    bookBtn->move(797,597);
    in=new introSoldier(0);
    connect(bookBtn,&QPushButton::clicked,[=](){
        this->hide();
        in->show();
    });
    connect(in,&introSoldier::Back,[=](){
       in->hide();
       this->show();
    });

    myPushButton* yesBtn=new myPushButton(":/resource/Byes1.png",":/resource/Byes2.png");
    yesBtn->resize(QSize(yesBtn->pix.width()*0.90,yesBtn->pix.height()*0.90));
    yesBtn->setIconSize(QSize(yesBtn->pix.width()*0.90,yesBtn->pix.height()*0.90));
    yesBtn->setParent(this);
    yesBtn->move(643,597);
    chssdb=new chooseSoldierb(0);
    connect(yesBtn,&QPushButton::clicked,[=](){
        int test;
        for(test=0;test<3;test++){
            if(A.s[test].name=="")
                break;
        }
        if(test==3){
            qDebug()<<"a1"<<A.s[0].name<<A.s[0].icon;
            qDebug()<<"a2"<<A.s[1].name<<A.s[1].icon;
            qDebug()<<"a3"<<A.s[2].name<<A.s[2].icon;
            this->hide();
            chssdb->show();
        }
    });

    //回到开始

    myPushButton* homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.90,homeBtn->pix.height()*0.90));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.90,homeBtn->pix.height()*0.90));
    homeBtn->setParent(this);
    homeBtn->move(797+797-643,597);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->Home();
    });

    //回到前一个
    myPushButton* backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.90,backBtn->pix.height()*0.90));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.90,backBtn->pix.height()*0.90));
    backBtn->setParent(this);
    backBtn->move(1096,597);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->Back();
    });



//======================================================================================

    /* 先检查第一个框框是不是clicked状态，如果不是，那么在点击武将的时候不反应
     * 如果是，再点击武将之后，将player.soldier设置好
     * 点击武将后，先依次检测有没有拥有这个武将，如果已经有了，那么不反应
    */
    // 三个选择button，默认什么也不点的话，选择是改变第一个。


    QString tpath2=":/resource/transparent.png";
    QString tpath1=":/resource/black.png";
    for(int i=0;i<3;i++){
        t[i]=new transparentButton(tpath1,tpath2);
        t[i]->resize(QSize(120,120));
        t[i]->setIconSize(QSize(120,120));
        t[i]->setParent(this);
        t[i]->move(651+i*128,448);
        connect(t[i],&QPushButton::clicked,[=](){
            t[i]->beClicked();
            whichIsClicked=i;
        });
    }


    //icons
    QString path1[10];
    QString path3[10];
    path1[0]=":/soldier/jiushi1.png";
    path3[0]=":/soldier/jiushi3.png";
    path1[1]=":/soldier/jushou1.png";
    path3[1]=":/soldier/jushou3.png";
    path1[2]=":/soldier/kuanglian1.png";
    path3[2]=":/soldier/kuanglian3.png";
    path1[3]=":/soldier/liegong1.png";
    path3[3]=":/soldier/liegong3.png";
    path1[4]=":/soldier/miling1.png";
    path3[4]=":/soldier/miling3.png";
    path1[5]=":/soldier/qinyin1.png";
    path3[5]=":/soldier/qinyin3.png";
    path1[6]=":/soldier/shensu1.png";
    path3[6]=":/soldier/shensu3.png";
    path1[7]=":/soldier/siwen1.png";
    path3[7]=":/soldier/siwen3.png";
    path1[8]=":/soldier/wushuang1.png";
    path3[8]=":/soldier/wushuang3.png";
    path1[9]=":/soldier/xianzhen1.png";
    path3[9]=":/soldier/xianzhen3.png";


    for(int j=0;j<10;j++){
        icon[j]=new myPushButton2(path1[j],path3[j]);
        if(j%2==0){
            icon[j]->move(298,138+j/2*128);
        }
        else{
            icon[j]->move(298+128,138+j/2*128);
        }
        icon[j]->resize(QSize(120,120));
        icon[j]->setIconSize(QSize(120,120));
        icon[j]->setParent(this);
    }
    icon[0]->name="酒诗";
    icon[1]->name="据守";
    icon[2]->name="狂镰";
    icon[3]->name="烈弓";
    icon[4]->name="密令";
    icon[5]->name="琴音";
    icon[6]->name="神速";
    icon[7]->name="死吻";
    icon[8]->name="无双";
    icon[9]->name="陷阵";


    Soldier temp;
    for(int j=0;j<10;j++){
        temp.setSoldier(icon[j]->name);
        QString str1=QString::number(temp.lifeValue);
        QString str2=QString::number(temp.attackValue);
        QString str3=QString::number(temp.distance);
        icon[j]->setToolTip(icon[j]->name+"\n生命："+str1+"\n攻击："+str2+"\n范围："+str3);
        connect(icon[j],&QPushButton::clicked,[=](){
            /*先检查这个被点的方框有没有人了，有的话，让那个角色的框恢复正常
            再重新给这个框赋值*/
            if(icon[j]->isClicked){}
            else{
                for(int i=0;i<10;i++){
                    if(icon[i]->name==A.s[whichIsClicked].name)
                        icon[i]->notClicked();
                }
                A.s[whichIsClicked].setName(icon[j]->name);
                A.s[whichIsClicked].setSoldier(icon[j]->name);
                A.s[whichIsClicked].setIcon(icon[j]->common);
                icon[j]->beClicked();
                t[whichIsClicked]->setIcon(QPixmap(path1[j]));
                t[whichIsClicked]->isClicked=false;
            }
        });
    }

    connect(chssdb,&chooseSoldierb::Back,[=](){
        chssdb->hide();
        this->show();
    });
}
void chooseSoldierA::paintEvent(QPaintEvent *event){

    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    //大方格
    QPixmap pix2;
    pix2.load(":/resource/pic2.png");
    painter.drawPixmap(290,130,pix2.width()*0.8,pix2.height()*0.8,pix2);

    //字
    QPixmap pix;
    pix.load(":/resource/playerA.png");
    painter.drawPixmap(643,152,pix.width()*1.2,pix.height()*1.2,pix);

    pix.load(":/resource/pic3.png");
    painter.drawPixmap(648,324,pix.width()*1.2,pix.height()*1.2,pix);

    //小方格
    QPixmap pix3;
    pix3.load(":/resource/pic1.png");
    painter.drawPixmap(643,440,pix3.width()*0.8,pix3.height()*0.8,pix3);
}


