#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

// Included libraries
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

// Q Libraries
#include <QString>
#include <QTextStream>
#include <QMutex>
#include <QTextBrowser>

// Class Libraries
#include "Person.h"
#include "mainwindow.h"

using namespace std;

class GameManager
{

public:
    static GameManager *instance(){
        static QMutex mutex;
        if(!m_Instance){
            mutex.lock();

            if(!m_Instance)
                m_Instance=new GameManager;

            mutex.unlock();
        }

        return m_Instance;
    }

    static void drop(){
        static QMutex mutex;
        mutex.lock();
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

    // Main window
    void setPlayerPerson();

    //    void start();
    //{isRunning=true;}

    //    // Control functions
    //    void changeState(GameManager *state);
    //    void pushState(GameManager *state);
    //    void popState();

    //    void handleFunctions();
    //    void update();

    //    bool running() {return isRunning;}
    //    void quit() {isRunning = false;}

    // Guess check functions
    void guessEyeColor(QString sendGuess);
    void guessFacialHair(QString sendGuess);
    void guessGender(QString sendGuess);
    void guessHair(QString sendGuess);
    void guessHeadWear();

    // Recieve check functions
    void recieveEyeCheck(QString recieveGuess);
    void recieveFacialHairCheck(QString recieveGuess);
    void recieveGenderCheck(QString recieveGuess);
    void recieveHairCheck(QString recieveGuess);
    void recieveHeadWearCheck();

    // Mainwindow functions
    void setPlayerPerson(Person Mycharacter);
    void chatBox(QString incoming);
    void switchTurn(bool turn);

    QTextBrowser *replyBox;
    bool playerTurn=true;

private:
    //    Qvector<GameManager> states; // the stack of states
    //    Communicator *c = new Communicator;
    //    bool isRunning;
    GameManager();
    ~GameManager(); // Hidden Deconstructor
    GameManager(const GameManager &); // Hidden Copy Constructor
    GameManager& operator=(const GameManager &); // Hidden ass. op

    static GameManager *m_Instance;
};

#endif // GAMEMANAGER_H
