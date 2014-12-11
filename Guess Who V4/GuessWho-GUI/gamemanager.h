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

// Class Libraries
#include "Person.h"
#include "communicator.h"

using namespace std;

class GameManager
{

public:
    GameManager();
    ~GameManager();

    void start();
//{isRunning=true;}

//    // Control functions
//    void changeState(GameManager *state);
//    void pushState(GameManager *state);
//    void popState();

//    void handleFunctions();
//    void update();

//    bool running() {return isRunning;}
//    void quit() {isRunning = false;}

    // Guess Check Functions
    void guessEyeColor(QString sendGuess);
    void guessFacialHair(QString sendGuess);
    void guessGender(QString sendGuess);
    void guessHair(QString sendGuess);
    void guessHeadWear(QString sendGuess);

private:
//    Qvector<GameManager> states; // the stack of states
//    Communicator *c = new Communicator;
//    bool isRunning;
};

#endif // GAMEMANAGER_H
