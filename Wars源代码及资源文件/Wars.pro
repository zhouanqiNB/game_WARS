#-------------------------------------------------
#
# Project created by QtCreator 2020-06-27T21:31:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wars
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mypushbutton.cpp \
    choosescene.cpp \
    mycharacter.cpp \
    chooseicon.cpp \
    mypushbutton2.cpp \
    mycharacter2.cpp \
    chooseicon2.cpp \
    introstory.cpp \
    choosesoldiera.cpp \
    transparentbutton.cpp \
    choosesoldierb.cpp \
    introsoldier.cpp \
    introrule.cpp \
    playtable.cpp \
    player.cpp \
    mysquare.cpp \
    soldier.cpp \
    question.cpp

HEADERS += \
        mainwindow.h \
    mypushbutton.h \
    choosescene.h \
    mycharacter.h \
    chooseicon.h \
    mypushbutton2.h \
    mycharacter2.h \
    chooseicon2.h \
    introstory.h \
    choosesoldiera.h \
    transparentbutton.h \
    choosesoldierb.h \
    introsoldier.h \
    introrule.h \
    playtable.h \
    player.h \
    mysquare.h \
    soldier.h \
    question.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc

RC_ICONS=icon.ico
