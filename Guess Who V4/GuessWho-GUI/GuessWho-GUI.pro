#-------------------------------------------------
#
# Project created by QtCreator 2014-09-28T08:07:09
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
#LIBS+=-LC:\MySQL\MySQL51\lib\opt -lmysql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuessWho-Take2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    genderwindow.cpp \
    eyecolorwindow.cpp \
    aboutwindow.cpp \
    hairwindow.cpp \
    facialhairwindow.cpp \
    headwearwindow.cpp \
    howtowindow.cpp \
    highscorewindow.cpp

HEADERS  += mainwindow.h \
    genderwindow.h \
    eyecolorwindow.h \
    aboutwindow.h \
    hairwindow.h \
    facialhairwindow.h \
    headwearwindow.h \
    howtowindow.h \
    Person.h \
    TextFile.h \
    highscorewindow.h

FORMS    +=

RESOURCES += \
    Resource.qrc
