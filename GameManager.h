/* 
 * File:   GameManager.h
 * Author: Victoria
 *
 * Created on September 22, 2014, 3:37 PM
 */

#ifndef GAMEMANAGER_H
#define	GAMEMANAGER_H
#include "Person.h"
using namespace std;

class GameManager {
private:
    Person cards[24];//array of people and their descriptions 
    string *hairQs;//read in questions from a file, one question per element of array
    string *skinQs;
    string *eyeQs;
    string *faceHairQs;
    string *accessoryQs;
    string *genderQs;
    string *names;
    int computer;//index for computer's person card
    int user;//index for user's person card
public:
    GameManager();
    //void fillCards();//input descriptions of people from file
    void fillQuestions();//input questions from a file,
    //return pointer array of questions, to be used with GUI?
    bool gamePlay(int turn,int index,bool&gameOver);//calls computerTurn and userTurn functions,include loop until gameOver==true
    bool guess(int turn,int index,int qType,bool&gameOver);//0-computer turn,1-user , index is for question
};

#endif	/* GAMEMANAGER_H */

