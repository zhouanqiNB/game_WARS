#include "mainwindow.h"
#include"player.h"
#include <QApplication>
#include<QFontDatabase>
#include <QFontDatabase>
#include <QIODevice>
#include<QFile>
#include<QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


QString loadFontFamilyFromFiles(const QString &strFontFilePath)
{
    QString font = "";

    QFile fontFile(strFontFilePath);
    if(!fontFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Open font file error";
        return font;
    }

    int loadedFontID = QFontDatabase::addApplicationFontFromData(fontFile.readAll());
    QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(loadedFontID);
    if(!loadedFontFamilies.empty())
    {
        font = loadedFontFamilies.at(0);
    }
    fontFile.close();
    return font;
}
