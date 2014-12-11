#include "mainwindow.h"
#include "gamemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainwindow;
    GameManager game;
    mainwindow.show();
    game.start();

    return app.exec();
}
