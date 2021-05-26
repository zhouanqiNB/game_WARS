#include "playtable.h"
#include"QPainter"
#include<QLabel>
#include<QFont>
#include<QPalette>
#include"mypushbutton.h"
#include"mypushbutton2.h"
#include"player.h"
#include<QDebug>
#include"mycharacter.h"
#include<math.h>
#include"mainwindow.h"
#include<time.h>
QString loadFontFamilyFromFiles(const QString &strFontFilePath);

player A;
player B;

int Anumber;
int Bnumber;

extern Question* que;


playTable::playTable(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);

    QString strFont =  loadFontFamilyFromFiles(":/方正像素12.TTF");
    QFont font(strFont);

    //中间的   “回合”
    QLabel*huihe=new QLabel(this);
    huihe->resize(200,200);
    huihe->setText("回合");
    huihe->setFont(font);
    huihe->setStyleSheet("font-size : 75px");
    huihe->move(684,-10);
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(80,48,0));
    huihe->setPalette(pa);

    //回合几


    QString Sround=QString::number(round);
    QLabel*Lround=new QLabel(this);
    Lround->resize(100,100);
    Lround->setText(Sround);
    Lround->setFont(font);
    Lround->setStyleSheet("font-size : 75px");
    Lround->move(840,45);
    Lround->setPalette(pa);

    //您本回合剩余点数为
    QLabel*text[2];
    for(int i=0;i<2;i++){
        text[i]=new QLabel(this);
        text[i]->resize(600,200);
        text[i]->setText("您本回合剩余\n点数为:");
        text[i]->setFont(font);
        text[i]->setStyleSheet("font-size : 50px");
        text[i]->setPalette(pa);
    }
    text[0]->move(100,-8);
    text[1]->move(1190,-8);

    //中下部按钮
    {
    int size=98;
    int x=99,y=547;

    attack=new myPushButton2(":/resource/attack.png",":/resource/attack2.png");
    attack->setParent(this);
    attack->setFixedSize(size,size);
    attack->setIconSize(QSize(size,size));
    attack->move(x,y);
    attack->setToolTip("攻击");

    skill=new myPushButton2(":/resource/skill2.png",":/resource/skill2.png");
    skill->setParent(this);
    skill->setFixedSize(size,size);
    skill->setIconSize(QSize(size,size));
    skill->move(x+size+9,y);
    skill->setToolTip("程序员在努力开发技能");

    again=new myPushButton2(":/resource/again.png",":/resource/again.png");
    again->setParent(this);
    again->setFixedSize(size,size);
    again->setIconSize(QSize(size,size));
    again->move(x+2*size+19,y);
    again->setToolTip("悔棋");

    int move=1087;
    attack1=new myPushButton2(":/resource/attack.png",":/resource/attack2.png");
    attack1->setParent(this);
    attack1->setFixedSize(size,size);
    attack1->setIconSize(QSize(size,size));
    attack1->move(x+move,y);
    attack1->setToolTip("攻击");

    skill1=new myPushButton2(":/resource/skill2.png",":/resource/skill2.png");
    skill1->setParent(this);
    skill1->setFixedSize(size,size);
    skill1->setIconSize(QSize(size,size));
    skill1->move(x+move+size+9,y);
    skill1->setToolTip("程序员在努力开发技能");

    again1=new myPushButton2(":/resource/again.png",":/resource/again.png");
    again1->setParent(this);
    again1->setFixedSize(size,size);
    again1->setIconSize(QSize(size,size));
    again1->move(x+move+2*size+19,y);
    again1->setToolTip("悔棋");

    end=new myPushButton2(":/resource/end.png",":/resource/end.png");
    end->setParent(this);
    end->setFixedSize(size*3+20,size);
    end->setIconSize(QSize(size*3+20,size));
    end->move(x,y+108);
    end->setToolTip("进入对方的回合");

    end1=new myPushButton2(":/resource/end.png",":/resource/end.png");
    end1->setParent(this);
    end1->setFixedSize(size*3+20,size);
    end1->setIconSize(QSize(size*3+20,size));
    end1->move(x+move,y+108);
    end1->setToolTip("进入对方的回合");
    }

    //soldier的头像

    myPushButton2*as0=NULL;
    myPushButton2*as1=NULL;
    myPushButton2*as2=NULL;
    myPushButton2*bs0=NULL;
    myPushButton2*bs1=NULL;
    myPushButton2*bs2=NULL;
    int sizesoldier=108;
    int plus=117;
    as0=new myPushButton2();
    as0->setParent(this);
    as0->setFixedSize(sizesoldier,sizesoldier);
    as0->setIconSize(QSize(sizesoldier,sizesoldier));
    as0->move(99,175);
    connect(&A.s[0],&Soldier::iconChanged,this,[this,as0](QString i){
        as0->common=i;
        as0->loadIcon(as0->common);
        as0->setToolTip(A.s[0].name);
    });
    as1=new myPushButton2();
    as1->setParent(this);
    as1->setFixedSize(sizesoldier,sizesoldier);
    as1->setIconSize(QSize(sizesoldier,sizesoldier));
    as1->move(99,176+plus);
    connect(&A.s[1],&Soldier::iconChanged,this,[this,as1](QString i){
        as1->common=i;
        as1->loadIcon(as1->common);
        as1->setToolTip(A.s[1].name);
    });
    as2=new myPushButton2();
    as2->setParent(this);
    as2->setFixedSize(sizesoldier,sizesoldier);
    as2->setIconSize(QSize(sizesoldier,sizesoldier));
    as2->move(99,176+2*plus);
    connect(&A.s[2],&Soldier::iconChanged,this,[this,as2](QString i){
        as2->common=i;
        as2->loadIcon(as2->common);
        as2->setToolTip(A.s[2].name);
    });

    int hori=1391;
    bs0=new myPushButton2();
    bs0->setParent(this);
    bs0->setFixedSize(sizesoldier,sizesoldier);
    bs0->setIconSize(QSize(sizesoldier,sizesoldier));
    bs0->move(hori,175);
    connect(&B.s[0],&Soldier::iconChanged,this,[this,bs0](QString i){
        bs0->common=i;
        bs0->loadIcon(bs0->common);
        bs0->setToolTip(B.s[0].name);
    });
    bs1=new myPushButton2();
    bs1->setParent(this);
    bs1->setFixedSize(sizesoldier,sizesoldier);
    bs1->setIconSize(QSize(sizesoldier,sizesoldier));
    bs1->move(hori,176+plus);
    connect(&B.s[1],&Soldier::iconChanged,this,[this,bs1](QString i){
        bs1->common=i;
        bs1->loadIcon(bs1->common);
        bs1->setToolTip(B.s[1].name);
    });
    bs2=new myPushButton2();
    bs2->setParent(this);
    bs2->setFixedSize(sizesoldier,sizesoldier);
    bs2->setIconSize(QSize(sizesoldier,sizesoldier));
    bs2->move(hori,176+2*plus);
    connect(&B.s[2],&Soldier::iconChanged,this,[this,bs2](QString i){
        bs2->common=i;
        bs2->loadIcon(bs2->common);
        bs2->setToolTip(B.s[2].name);
    });



    //玩家头像

    int size2=88;
    int y2=48;
    myPushButton2*head=new myPushButton2();
    head->setParent(this);
    head->setFixedSize(size2,size2);
    head->setIconSize(QSize(size2,size2));
    head->move(461,y2);

    myPushButton2*head1=new myPushButton2();
    head1->setParent(this);
    head1->setFixedSize(size2,size2);
    head1->setIconSize(QSize(size2,size2));
    head1->move(1049,y2);

    //为了实现头像可以改变
    connect(&A,&player::iconChanged,this,[this,head](QString i){
        qDebug()<<"head set";
        head->common=i;
        head->loadIcon(head->common);
        head->setToolTip(A.name);
    });
    connect(&B,&player::iconChanged,this,[this,head1](QString i){
        qDebug()<<"head set";
        head1->common=i;
        head1->loadIcon(head1->common);
        head1->setToolTip(B.name);
    });


    //棋盘上的25格子

    //每个格子的外观设置
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Square[i][j].square=new myPushButton2(":/resource/transparent.png",":/resource/transparant.png");
            Square[i][j].square->setFixedSize(128,128);
            Square[i][j].square->setParent(this);
            Square[i][j].square->setIconSize(QSize(128,128));
            Square[i][j].square->move(461+i*137,723-j*137);
        }
    }

    QString soldiername[10];
    soldiername[0]="酒诗";
    soldiername[1]="据守";
    soldiername[2]="狂镰";
    soldiername[3]="烈弓";
    soldiername[4]="密令";
    soldiername[5]="琴音";
    soldiername[6]="神速";
    soldiername[7]="死吻";
    soldiername[8]="无双";
    soldiername[9]="陷阵";

    QString pathsoldier[10];
    pathsoldier[0]=":/soldier/jiushi1.png";
    pathsoldier[1]=":/soldier/jushou1.png";
    pathsoldier[2]=":/soldier/kuanglian1.png";
    pathsoldier[3]=":/soldier/liegong1.png";
    pathsoldier[4]=":/soldier/miling1.png";
    pathsoldier[5]=":/soldier/qinyin1.png";
    pathsoldier[6]=":/soldier/shensu1.png";
    pathsoldier[7]=":/soldier/siwen1.png";
    pathsoldier[8]=":/soldier/wushuang1.png";
    pathsoldier[9]=":/soldier/xianzhen1.png";

    QString pathsoldier1[10];
    pathsoldier1[0]=":/soldier/jiushi3.png";
    pathsoldier1[1]=":/soldier/jushou3.png";
    pathsoldier1[2]=":/soldier/kuanglian3.png";
    pathsoldier1[3]=":/soldier/liegong3.png";
    pathsoldier1[4]=":/soldier/miling3.png";
    pathsoldier1[5]=":/soldier/qinyin3.png";
    pathsoldier1[6]=":/soldier/shensu3.png";
    pathsoldier1[7]=":/soldier/siwen3.png";
    pathsoldier1[8]=":/soldier/wushuang3.png";
    pathsoldier1[9]=":/soldier/xianzhen3.png";

    //每个格子的内里设置
    for(int k=0;k<3;k++){
        connect(&A.s[k],&Soldier::nameChanged,[this,pathsoldier,pathsoldier1,soldiername,k](QString i){
            for(int j=0;j<10;j++){
                //如果这个士兵的名字和第i个对上了，就用他的头像
                if(i==soldiername[j]){
                    Square[k+1][4].square->common=pathsoldier[j];
                    Square[k+1][4].square->click=pathsoldier1[j];
                    Square[k+1][4].soldi=new Soldier;
                    Square[k+1][4].soldi->name=i;
                    Square[k+1][4].soldi->setSoldier(i);
                    Square[k+1][4].ownerIsA=1;
                    qDebug()<<Square[k+1][4].soldi->lifeValue<<Square[k+1][4].soldi->attackValue<<Square[k+1][4].soldi->distance;
                    Square[k+1][4].isEmpty=0;
                    qDebug()<<Square[k+1][4].soldi->name;
                    this->Square[k+1][4].square->setIcon(QPixmap(Square[k+1][4].square->common));
                    break;
                }
            }
        });
    }
    for(int k=0;k<3;k++){
        connect(&B.s[k],&Soldier::nameChanged,[this,pathsoldier,pathsoldier1,soldiername,k](QString i){
            for(int j=0;j<10;j++){
                if(i==soldiername[j]){
                    Square[k+1][0].square->common=pathsoldier[j];
                    Square[k+1][0].square->click=pathsoldier1[j];
                    Square[k+1][0].soldi=new Soldier;
                    Square[k+1][0].soldi->name=i;
                    Square[k+1][0].soldi->setSoldier(i);
                    Square[k+1][0].ownerIsA=0;
                    Square[k+1][0].isEmpty=0;
                    qDebug()<<Square[k+1][4].soldi->name;
                    this->Square[k+1][0].square->setIcon(QPixmap(Square[k+1][0].square->common));
                    break;
                }
            }
        });
    }



    QPalette textColor;
    textColor.setColor(QPalette::WindowText,QColor(252,214,132));
    QPalette textColor2;
    textColor2.setColor(QPalette::WindowText,QColor(81,49,0));
    QFont font1(font);
    font1.setPointSize(12);
    text1=new QLabel(this);
    text2=new QLabel(this);
    APoint=new QLabel(this);
    BPoint=new QLabel(this);

    text1->resize(333,88);
    text1->move(89,773);
    text1->setFont(font1);
    text1->setText("");
    text1->setPalette(textColor);

    text2->resize(333,88);
    text2->move(1176,773);
    text2->setFont(font1);
    text2->setText("");
    text2->setPalette(textColor);

    QFont font2(font);
    font2.setPointSize(42);

    APoint->resize(100,88);
//    APoint->setStyleSheet("background-color:red");
    APoint->move(286,79);
    APoint->setFont(font2);
    APoint->setText("0");
    APoint->setPalette(textColor2);

    BPoint->resize(100,88);
//    APoint->setStyleSheet("background-color:red");
    BPoint->move(1376,79);
    BPoint->setFont(font2);
    BPoint->setText("0");
    BPoint->setPalette(textColor2);


    srand((unsigned)time(NULL));
    point=rand()%11+2;
    QString pointStr1=QString::number(point);
    APoint->setText(pointStr1);

    text1->setText("    你的回合");

    /*主要算法区*************************************************/

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            connect(Square[i][j].square,&myPushButton2::clicked,[=](){
                if(isARound){
                    if(AreadyToAttack){
                        AreadyToAttack=0;
                        attack->notClicked();
                        if(Square[i][j].isEmpty){
                            text1->setText("    你不能攻击空格哦，\n    重来吧。");
                        }
                        else{
                            if(characHaveChosen){
                                characHaveChosen=0;
                                if(Square[i][j].ownerIsA){
                                    text1->setText("    你不能攻击自己哦，\n    重来吧。");
                                }
                                else{
                                    if(which_x!=i&&which_y!=j){
                                        text1->setText("    请攻击对的方向。");
                                    }
                                    if(which_x==i&&which_y!=j){
                                        if(abs(which_y-j)<=Square[which_x][which_y].soldi->distance){
                                            if(point-3>=0){
                                                text1->setText("    干得漂亮！");
                                                Square[i][j].soldi->lifeValue-=Square[which_x][which_y].soldi->attackValue;
                                                formerx=which_x;
                                                formery=which_y;
                                                laterx=i;
                                                latery=j;
                                                canAgain=1;
                                                action=1;

                                                for(int h=0;h<3;h++){
                                                    if(Square[i][j].soldi->name==B.s[h].name){
                                                        QString pointStr2=QString::number(Square[i][j].soldi->lifeValue);
                                                        bslife[h]->setText(pointStr2);
                                                        if(Square[i][j].soldi->lifeValue<=0){
                                                            bslife[h]->setText("0");
                                                            Square[i][j].square->setIcon(QPixmap(":/resource/transparent.png"));
                                                            Square[i][j].soldi=NULL;
                                                            Square[i][j].isEmpty=1;
                                                            B.s[h].lifeValue=0;
                                                            text1->setText("    你击败了一名敌人。");
                                                            if(B.s[0].lifeValue==0&&B.s[1].lifeValue==0&&B.s[2].lifeValue==0){
                                                                isARound=isBRound=0;
                                                                text1->setText("    你赢了！");
                                                                text2->setText("    你输了。");
                                                                que->setQues(0);
                                                                que->show();
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }
                                                point-=3;
                                                QString pointStr=QString::number(point);
                                                APoint->setText(pointStr);
                                            }
                                            else{
                                                text1->setText("    没点数了。");
                                            }
                                        }
                                        else{
                                            text1->setText("    太远了打不到啊");
                                        }
                                    }
                                    if(which_x!=i&&which_y==j){
                                        if(abs(which_x-i)<=Square[which_x][which_y].soldi->distance){
                                            if(point-3>=0){
                                                text1->setText("    干得漂亮！");
                                                Square[i][j].soldi->lifeValue-=Square[which_x][which_y].soldi->attackValue;
                                                formerx=which_x;
                                                formery=which_y;
                                                laterx=i;
                                                latery=j;
                                                canAgain=1;
                                                action=1;
                                                point-=3;
                                                for(int h=0;h<3;h++){
                                                    if(Square[i][j].soldi->name==B.s[h].name){
                                                        QString pointStr2=QString::number(Square[i][j].soldi->lifeValue);
                                                        bslife[h]->setText(pointStr2);
                                                        if(Square[i][j].soldi->lifeValue<=0){
                                                            bslife[h]->setText("0");
                                                            Square[i][j].square->setIcon(QPixmap(":/resource/transparent.png"));
                                                            Square[i][j].soldi=NULL;
                                                            Square[i][j].isEmpty=1;
                                                            B.s[h].lifeValue=0;

                                                            text1->setText("    你击败了一名敌人。");
                                                            if(B.s[0].lifeValue==0&&B.s[1].lifeValue==0&&B.s[2].lifeValue==0){
                                                                isARound=isBRound=0;
                                                                text1->setText("    你赢了！");
                                                                text2->setText("    你输了。");
                                                                que->setQues(0);
                                                                que->show();
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }
                                                QString pointStr=QString::number(point);
                                                APoint->setText(pointStr);
                                            }
                                            else{
                                                text1->setText("    没点数了。");
                                            }
                                        }
                                        else{
                                            text1->setText("    太远了打不到啊。");
                                        }
                                    }
                                }
                            }
                            else{
                                text1->setText("    请选择发起攻击方。");
                            }
                        }
                    }
                    else{
                        if(Square[i][j].isEmpty){
                            if(characHaveChosen){/*!!!!!!!!!!!!!!!!!!!!!!!!!*/
                                characHaveChosen=0;
                                if(i!=which_x&&j!=which_y){
                                    text1->setText("    不能斜着走哦。");
                                }
                                if(i==which_x&&j!=which_y){
                                    if(abs(j-which_y)+abs(j-which_y)<=point){
                                        text1->setText("    移动。");
                                        Square[which_x][which_y].square->setIcon(QPixmap(":/resouce/transparent.png"));
                                        Square[which_x][which_y].isEmpty=1;
                                        formerx=which_x;
                                        formery=which_y;
                                        laterx=i;
                                        latery=j;
                                        canAgain=1;
                                        action=0;

                                        Square[i][j].isEmpty=0;
                                        Square[i][j].ownerIsA=1;
                                        Square[i][j].soldi=Square[which_x][which_y].soldi;
                                        Square[which_x][which_y].soldi=NULL;
                                        Square[i][j].square->setIcon(QPixmap(Square[i][j].soldi->icon));

                                        point-=abs(j-which_y)+abs(j-which_y);
                                        QString pointStr=QString::number(point);
                                        APoint->setText(pointStr);
                                    }
                                    else{
                                        text1->setText("    点数不够。");
                                    }
                                }
                                if(i!=which_x&&j==which_y){
                                    if(abs(i-which_x)+abs(i-which_x)<=point){
                                        text1->setText("    移动。");
                                        Square[which_x][which_y].square->setIcon(QPixmap(":/resouce/transparent.png"));
                                        Square[which_x][which_y].isEmpty=1;
                                        formerx=which_x;
                                        formery=which_y;
                                        laterx=i;
                                        latery=j;
                                        canAgain=1;
                                        action=0;

                                        Square[i][j].isEmpty=0;
                                        Square[i][j].ownerIsA=1;
                                        Square[i][j].soldi=Square[which_x][which_y].soldi;
                                        Square[which_x][which_y].soldi=NULL;
                                        Square[i][j].square->setIcon(QPixmap(Square[i][j].soldi->icon));

                                        point-=abs(i-which_x)+abs(i-which_x);
                                        QString pointStr=QString::number(point);
                                        APoint->setText(pointStr);
                                    }
                                    else{
                                        text1->setText("    点数不够。");
                                    }
                                }
                            }
                            else{
                                text1->setText("    你点击的是空格。");
                            }
                        }
                        else{
                            if(Square[i][j].ownerIsA){
                                text1->setText("    选中了一个人物。");
                                characHaveChosen=1;
                            }
                            else{
                                text1->setText("    你不能让对方为你\n    作战。");
                            }
                        }
                    }

                }
                if(isBRound){
                    if(BreadyToAttack){
                        BreadyToAttack=0;
                        attack1->notClicked();
                        if(Square[i][j].isEmpty){
                            text2->setText("    你不能攻击空格哦，\n    重来吧。");
                        }
                        else{
                            if(!Square[i][j].ownerIsA){
                                text2->setText("    你不能攻击自己哦，\n    重来吧。");
                            }
                            else{
                                if(which_x!=i&&which_y!=j){
                                    text2->setText("    请攻击对的方向。");
                                }
                                if(which_x==i&&which_y!=j){
                                    if(abs(which_y-j)<=Square[which_x][which_y].soldi->distance){
                                        if(point-3>=0){
                                            text2->setText("    干得漂亮！");
                                            Square[i][j].soldi->lifeValue-=Square[which_x][which_y].soldi->attackValue;
                                            formerx=which_x;
                                            formery=which_y;
                                            laterx=i;
                                            latery=j;
                                            canAgain=1;
                                            action=1;
                                            for(int h=0;h<3;h++){
                                                if(Square[i][j].soldi->name==A.s[h].name){
                                                    QString pointStr2=QString::number(Square[i][j].soldi->lifeValue);
                                                    aslife[h]->setText(pointStr2);
                                                    if(Square[i][j].soldi->lifeValue<=0){
                                                        aslife[h]->setText("0");
                                                        Square[i][j].square->setIcon(QPixmap(":/resource/transparent.png"));
                                                        Square[i][j].soldi=NULL;
                                                        Square[i][j].isEmpty=1;
                                                        A.s[h].lifeValue=0;
                                                        text2->setText("    你击败了一名敌人。");
                                                        if(A.s[0].lifeValue==0&&A.s[1].lifeValue==0&&A.s[2].lifeValue==0){
                                                            isARound=isBRound=0;
                                                            text2->setText("    你赢了！");
                                                            text1->setText("    你输了。");
                                                            que->setQues(1);
                                                            que->show();
                                                        }
                                                    }
                                                    break;
                                                }
                                            }
                                            point-=3;
                                            QString pointStr=QString::number(point);
                                            BPoint->setText(pointStr);

                                        }
                                        else{
                                            text2->setText("    没点数了。");
                                        }
                                    }
                                    else{
                                        text2->setText("    太远了打不到啊");
                                    }
                                }
                                if(which_x!=i&&which_y==j){
                                    if(abs(which_x-i)<=Square[which_x][which_y].soldi->distance){
                                        if(point-3>=0){
                                            text2->setText("    干得漂亮！");
                                            Square[i][j].soldi->lifeValue-=Square[which_x][which_y].soldi->attackValue;
                                            formerx=which_x;
                                            formery=which_y;
                                            laterx=i;
                                            latery=j;
                                            canAgain=1;
                                            action=1;

                                            for(int h=0;h<3;h++){
                                                if(Square[i][j].soldi->name==A.s[h].name){
                                                    QString pointStr2=QString::number(Square[i][j].soldi->lifeValue);
                                                    aslife[h]->setText(pointStr2);
                                                    if(Square[i][j].soldi->lifeValue<=0){
                                                        aslife[h]->setText("0");
                                                        Square[i][j].square->setIcon(QPixmap(":/resource/transparent.png"));
                                                        Square[i][j].soldi=NULL;
                                                        Square[i][j].isEmpty=1;
                                                        A.s[h].lifeValue=0;
                                                        text2->setText("    你击败了一名敌人。");
                                                        if(A.s[0].lifeValue==0&&A.s[1].lifeValue==0&&A.s[2].lifeValue==0){
                                                            isARound=isBRound=0;
                                                            text2->setText("    你赢了！");
                                                            text1->setText("    你输了。");
                                                            que->setQues(1);
                                                            que->show();
                                                        }
                                                    }
                                                    break;
                                                }
                                            }
                                            point-=3;
                                            QString pointStr=QString::number(point);
                                            BPoint->setText(pointStr);
                                        }
                                        else{
                                            text2->setText("    没点数了。");
                                        }
                                    }
                                    else{
                                        text2->setText("    太远了打不到啊。");
                                    }
                                }

                            }
                        }

                    }
                    else{
                        if(Square[i][j].isEmpty){
                            if(characHaveChosen){/*!!!!!!!!!!!!!!!!!!!!!!!!!*/
                                characHaveChosen=0;
                                if(i!=which_x&&j!=which_y){
                                    text2->setText("    不能斜着走哦。");
                                }
                                if(i==which_x&&j!=which_y){
                                    if(abs(j-which_y)+abs(j-which_y)<=point){
                                        text2->setText("    移动。");
                                        Square[which_x][which_y].square->setIcon(QPixmap(":/resouce/transparent.png"));
                                        Square[which_x][which_y].isEmpty=1;
                                        formerx=which_x;
                                        formery=which_y;
                                        laterx=i;
                                        latery=j;
                                        canAgain=1;
                                        action=0;

                                        Square[i][j].isEmpty=0;
                                        Square[i][j].ownerIsA=0;
                                        Square[i][j].soldi=Square[which_x][which_y].soldi;
                                        Square[which_x][which_y].soldi=NULL;
                                        Square[i][j].square->setIcon(QPixmap(Square[i][j].soldi->icon));

                                        point-=abs(j-which_y)+abs(j-which_y);
                                        QString pointStr=QString::number(point);
                                        BPoint->setText(pointStr);
                                    }
                                    else{
                                        text2->setText("    点数不够。");
                                    }
                                }
                                if(i!=which_x&&j==which_y){
                                    if(abs(i-which_x)+abs(i-which_x)<=point){
                                        text2->setText("    移动。");
                                        Square[which_x][which_y].square->setIcon(QPixmap(":/resouce/transparent.png"));
                                        Square[which_x][which_y].isEmpty=1;
                                        formerx=which_x;
                                        formery=which_y;
                                        laterx=i;
                                        latery=j;
                                        canAgain=1;
                                        action=0;

                                        Square[i][j].isEmpty=0;
                                        Square[i][j].ownerIsA=0;
                                        Square[i][j].soldi=Square[which_x][which_y].soldi;
                                        Square[which_x][which_y].soldi=NULL;
                                        Square[i][j].square->setIcon(QPixmap(Square[i][j].soldi->icon));

                                        point-=abs(i-which_x)+abs(i-which_x);
                                        QString pointStr=QString::number(point);
                                        BPoint->setText(pointStr);
                                    }
                                    else{
                                        text2->setText("    点数不够。");
                                    }
                                }
                            }
                            else{}
                        }
                        else{
                            if(!Square[i][j].ownerIsA){
                                text2->setText("    选中了一个人物。");
                                characHaveChosen=1;
                            }
                            else{
                                text2->setText("    你不能让对方为你\n    作战。");
                            }
                        }
                    }
                }

                which_x=i;
                which_y=j;
            });
        }
    }

    connect(again,&myPushButton2::clicked,[=](){
        if(isARound){
            if(canAgain){
                if(action==0){
                    text1->setText("    悔棋。");
                    Square[laterx][latery].square->setIcon(QPixmap(":/resouce/transparent.png"));
                    Square[laterx][latery].isEmpty=1;

                    Square[formerx][formery].isEmpty=0;
                    Square[formerx][formery].ownerIsA=1;
                    Square[formerx][formery].soldi=Square[laterx][latery].soldi;
                    Square[laterx][latery].soldi=NULL;
                    Square[formerx][formery].square->setIcon(QPixmap(Square[formerx][formery].soldi->icon));

                    point+=abs(formerx-laterx)+abs(formery-latery)+abs(formerx-laterx)+abs(formery-latery);
                    QString pointStr=QString::number(point);
                    APoint->setText(pointStr);
                }
                if(action==1){
                    text1->setText("    悔棋。");
                    Square[laterx][latery].soldi->lifeValue+=Square[formerx][formery].soldi->attackValue;
                    point+=3;
                    QString pointStr=QString::number(point);
                    APoint->setText(pointStr);

                    for(int h=0;h<3;h++){
                        if(Square[laterx][latery].soldi->name==B.s[h].name){
                            QString pointStr2=QString::number(Square[laterx][latery].soldi->lifeValue);
                            bslife[h]->setText(pointStr2);
                        }
                    }
                }
                canAgain=0;
            }
            else{
                text1->setText("    每步只能悔棋一次。");
            }
        }
    });

    connect(again1,&myPushButton2::clicked,[=](){
        if(isBRound){
            if(canAgain){
                if(action==0){
                    text2->setText("    悔棋。");
                    Square[laterx][latery].square->setIcon(QPixmap(":/resouce/transparent.png"));
                    Square[laterx][latery].isEmpty=1;

                    Square[formerx][formery].isEmpty=0;
                    Square[formerx][formery].ownerIsA=0;
                    Square[formerx][formery].soldi=Square[laterx][latery].soldi;
                    Square[laterx][latery].soldi=NULL;
                    Square[formerx][formery].square->setIcon(QPixmap(Square[formerx][formery].soldi->icon));

                    point+=abs(formerx-laterx)+abs(formery-latery)+abs(formerx-laterx)+abs(formery-latery);
                    QString pointStr=QString::number(point);
                    BPoint->setText(pointStr);
                }
                if(action==1){
                    text2->setText("    悔棋。");
                    Square[laterx][latery].soldi->lifeValue+=Square[formerx][formery].soldi->attackValue;
                    point+=3;
                    QString pointStr=QString::number(point);
                    BPoint->setText(pointStr);

                    for(int h=0;h<3;h++){
                        if(Square[laterx][latery].soldi->name==A.s[h].name){
                            QString pointStr2=QString::number(Square[laterx][latery].soldi->lifeValue);
                            aslife[h]->setText(pointStr2);
                        }
                    }
                }
            }
            else{
                text2->setText("    每步只能悔棋一次。");
            }
        }
    });



    connect(que,&Question::quesClose,this,close);

    connect(end,&myPushButton2::clicked,[=](){
        if(isARound){
            AreadyToAttack=0;
            attack->notClicked();
            isARound=0;
            srand((unsigned)time(NULL));
            point=rand()%11+2;
            APoint->setText("");
            QString pointStr2=QString::number(point);
            BPoint->setText(pointStr2);
            text1->setText("");
            text2->setText("    你的回合。");
            isBRound=1;
        }
    });

    connect(end1,&myPushButton2::clicked,[=](){
        if(isBRound){
            BreadyToAttack=0;
            attack1->notClicked();
            isARound=1;
            srand((unsigned)time(NULL));
            point=rand()%11+2;
            BPoint->setText("");
            QString pointStr2=QString::number(point);
            APoint->setText(pointStr2);
            round++;
            pointStr2=QString::number(round);
            Lround->setText(pointStr2);
            text2->setText("");
            text1->setText("    你的回合。");
            isBRound=0;
        }
    });


    //您本轮的点数
//    point=rand()%11+2;

    //写攻击按钮
    connect(attack,&myPushButton2::clicked,[=](){
        if(isARound){
            if(characHaveChosen){
                AreadyToAttack=1;
                attack->beClicked();
                attack1->notClicked();
            }
        }
    });
    connect(attack1,&myPushButton2::clicked,[=](){
        if(!isARound){
            if(characHaveChosen){
                BreadyToAttack=1;
                attack1->beClicked();
                attack->notClicked();
            }
        }
    });

    QLabel* Aname,*Bname;
    Aname=new QLabel(this);
    Bname=new QLabel(this);

    QFont font3(font);
    font3.setPointSize(15);
    Aname->resize(98,68);
//    Aname->setStyleSheet("background-color:red");
    Aname->move(559,48);
    Aname->setFont(font3);
    Aname->setPalette(textColor);
    Bname->setAlignment(Qt::AlignLeft);

    Bname->resize(98,68);
//    Bname->setStyleSheet("background-color:red");
    Bname->move(941,48);
    Bname->setFont(font3);
    Bname->setPalette(textColor2);
    Bname->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

    connect(&A,&player::nameChanged,[this,Aname](QString i){
        Aname->setText(i);
    });
    connect(&B,&player::nameChanged,[this,Bname](QString i){
        Bname->setText(i);
    });



    //人物生命值显示

    QFont font4(font);
    font4.setPointSize(25);

    for(int i=0;i<3;i++){
        aslife[i]=new QLabel(this);
        aslife[i]->resize(80,88);
        aslife[i]->move(190,165+i*118);
        aslife[i]->setFont(font4);
        aslife[i]->setPalette(textColor);
        aslife[i]->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        connect(&A.s[i],&Soldier::lifeChanged,[=](QString j){
            aslife[i]->setText(j);
        });
        bslife[i]=new QLabel(this);
        bslife[i]->resize(80,88);
        bslife[i]->move(1323,165+i*118);
        bslife[i]->setFont(font4);
        bslife[i]->setPalette(textColor);
        connect(&B.s[i],&Soldier::lifeChanged,[=](QString j){
            bslife[i]->setText(j);
        });
    }

    //斜杠
    QLabel* xiegang[2][6];

    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            xiegang[i][j]=new QLabel(this);
            xiegang[i][j]->resize(60,88);
            xiegang[i][j]->move(272+i*60,165+j*118);
            xiegang[i][j]->setFont(font4);
            xiegang[i][j]->setPalette(textColor);
            xiegang[i][j]->setText("/");
            if(j>2){
                xiegang[i][j]->move(1237+i*60,165+(j-3)*118);
            }
        }
    }


    //攻击
    for(int i=0;i<3;i++){
        asattack[i]=new QLabel(this);
        asattack[i]->resize(80,88);
        asattack[i]->move(301,165+i*118);
        asattack[i]->setFont(font4);
        asattack[i]->setPalette(textColor);
        connect(&A.s[i],&Soldier::attackChanged,[=](QString j){
            asattack[i]->setText(j);
        });
        bsattack[i]=new QLabel(this);
        bsattack[i]->resize(80,88);
        bsattack[i]->move(1265,165+i*118);
        bsattack[i]->setFont(font4);
        bsattack[i]->setPalette(textColor);
        connect(&B.s[i],&Soldier::attackChanged,[=](QString j){
            bsattack[i]->setText(j);
        });
    }
    //距离
    for(int i=0;i<3;i++){
        asdistance[i]=new QLabel(this);
        asdistance[i]->resize(80,88);
        asdistance[i]->move(361,165+i*118);
        asdistance[i]->setFont(font4);
        asdistance[i]->setPalette(textColor);
        connect(&A.s[i],&Soldier::distanceChanged,[=](QString j){
            asdistance[i]->setText(j);
        });
        bsdistance[i]=new QLabel(this);
        bsdistance[i]->resize(80,88);
        bsdistance[i]->move(1210,165+i*118);
        bsdistance[i]->setFont(font4);
        bsdistance[i]->setPalette(textColor);
        connect(&B.s[i],&Soldier::distanceChanged,[=](QString j){
            bsdistance[i]->setText(j);
        });
    }





}




void playTable::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround6.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(":/resource/drawing.png");
    painter.drawPixmap((this->width()-pix2.width()*0.98)/2,(this->height()-pix2.height()*0.98)/2,pix2.width()*0.98,pix2.height()*0.98,pix2);


}


