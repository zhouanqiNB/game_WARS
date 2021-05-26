#include "introsoldier.h"
#include"mypushbutton.h"
#include"mypushbutton2.h"
#include<QPainter>

introSoldier::introSoldier(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600,900);

    QString path1[10];
    QString path3[10];

    myPushButton* left=NULL;
    myPushButton* right=NULL;
    myPushButton* backBtn=NULL;
    myPushButton* homeBtn=NULL;
    //赋值区
    {
        word[0]=":/word/jiushi.png";
        word[1]=":/word/jushou.png";
        word[2]=":/word/kuanglian.png";
        word[3]=":/word/liegong.png";
        word[4]=":/word/miling.png";
        word[5]=":/word/qinyin.png";
        word[6]=":/word/shensu.png";
        word[7]=":/word/siwen.png";
        word[8]=":/word/wushuang.png";
        word[9]=":/word/xianzhen.png";

        pic[0]=":/soldier/jiushi2.png";
        pic[1]=":/soldier/jushou2.png";
        pic[2]=":/soldier/kuanglian2.png";
        pic[3]=":/soldier/liegong2.png";
        pic[4]=":/soldier/miling2.png";
        pic[5]=":/soldier/qinyin2.png";
        pic[6]=":/soldier/shensu2.png";
        pic[7]=":/soldier/siwen2.png";
        pic[8]=":/soldier/wushuang2.png";
        pic[9]=":/soldier/xianzhen2.png";


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
    }



    picture=new myPushButton2(pic[0],pic[0]);
    picture->resize(QSize(520,520));
    picture->setIconSize(QSize(520,520));
    picture->setParent(this);
    picture->move(160,100);

    words=new myPushButton2(word[0],word[0]);
    words->resize(QSize(words->pix.width(),words->pix.height()));
    words->setIconSize(QSize(words->pix.width(),words->pix.height()));
    words->setParent(this);
    words->move(790,120);

    left=new myPushButton(":/resource/left1.png",":/resource/left2.png");
    left->resize(QSize(left->pix.width()*0.90,left->pix.height()*0.90));
    left->setIconSize(QSize(left->pix.width()*0.90,left->pix.height()*0.90));
    left->setParent(this);
    left->move(78,300);
    connect(left,&myPushButton::clicked,[=](){
        smallPic[page]->notClicked();
        if(page==0)
            page=9;
        else
            page--;
        smallPic[page]->beClicked();
        update();
    });

    right=new myPushButton(":/resource/right1.png",":/resource/right2.png");
    right->resize(QSize(right->pix.width()*0.90,right->pix.height()*0.90));
    right->setIconSize(QSize(right->pix.width()*0.90,right->pix.height()*0.90));
    right->setParent(this);
    right->move(680,300);
    connect(right,&myPushButton::clicked,[=](){
        smallPic[page]->notClicked();
        if(page==9)
            page=0;
        else
            page++;
        smallPic[page]->beClicked();
        update();
    });

    for(int i=0;i<10;i++){
        smallPic[i]=new myPushButton2(path1[i],path3[i]);
        if(i==0)
            smallPic[i]->beClicked();
        smallPic[i]->resize(QSize(110,110));
        smallPic[i]->setIconSize(QSize(110,110));
        smallPic[i]->setParent(this);
        smallPic[i]->move(200+i*121,691);
        connect(smallPic[i],&myPushButton2::clicked,[=](){
            smallPic[page]->notClicked();
            smallPic[i]->beClicked();
            page=i;
            update();
        });
    }
    homeBtn=new myPushButton(":/resource/Bbacktobegin1.png",":/resource/Bbacktobegin2.png");
    homeBtn->resize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setIconSize(QSize(homeBtn->pix.width()*0.85,homeBtn->pix.height()*0.85));
    homeBtn->setParent(this);
    homeBtn->move(834+250,130);
    connect(homeBtn,&QPushButton::clicked,[=](){
        emit this->Home();
    });
    backBtn=new myPushButton(":/resource/Bbacktochoose1.png",":/resource/Bbacktochoose2.png");
    backBtn->resize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setIconSize(QSize(backBtn->pix.width()*0.85,backBtn->pix.height()*0.85));
    backBtn->setParent(this);
    backBtn->move(1000+250,130);
    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->Back();
    });

}

void introSoldier::paintEvent(QPaintEvent *event){

    //设置背景
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/resource/backGround2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix1);

    QPixmap pix2;
    pix2.load(":/resource/square10.png");
    painter.drawPixmap(this->width()/2-pix2.width()*1.1/2,680,pix2.width()*1.1,pix2.height()*1.1,pix2);


}
void introSoldier::update(){
        picture->setIcon(QPixmap(pic[page]));
        words->setIcon(QPixmap(word[page]));
}
