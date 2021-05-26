#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include"choosescene.h"
#include"player.h"
#include"mycharacter.h"
#include"mypushbutton.h"
#include"question.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //画界面
    void paintEvent(QPaintEvent *event);

    chooseScene* choose=NULL;

    myPushButton* startBtn=NULL;
    myPushButton* closeBtn=NULL;






private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
