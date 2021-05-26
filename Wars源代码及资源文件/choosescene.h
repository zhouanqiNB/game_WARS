#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include"mycharacter.h"
#include"player.h"
#include"introstory.h"
#include <QMainWindow>
#include"introsoldier.h"
#include"introrule.h"


class chooseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    /*选人物的界面
     *给自己取名：______
     * [____确定_____][][]
    */
;

    //五个按钮
    myPushButton* newBtn=NULL;
    myPushButton* introBtn=NULL;
    myPushButton* ruleBtn=NULL;
    myPushButton* soldierBtn=NULL;
    myPushButton* backBtn=NULL;



signals:

    void chooseSceneBack();

public slots:
};

#endif // CHOOSESCENE_H
