#include "gamemanager.h"
#include "mainwindow.h"
#include "communicator.h"

GameManager::GameManager(){

}

GameManager::~GameManager(){

}

void GameManager::start(){
//    isRunning=true;
}

//void GameManager::changeState(GameManager *state){

//}

//void GameManager::pushState(GameManager *state){

//}

//void GameManager::popState(){

//}

//void GameManager::handleFunctions(){

//}

//void GameManager::update(){

//}

void GameManager::guessEyeColor(QString recievedGuess){
    if(recievedGuess!=NULL)
    std::cout << "Eye guess is "<< recievedGuess.toStdString()<<std::endl;
}

void GameManager::guessFacialHair(QString recievedGuess){
    if(recievedGuess!=NULL)
    std::cout << "Facial hair guess is "<< recievedGuess.toStdString()<<std::endl;
}

void GameManager::guessGender(QString recievedGuess){
    if(recievedGuess!=NULL)
    std::cout << "Gender guess is "<< recievedGuess.toStdString()<<std::endl;
}

void GameManager::guessHeadWear(QString recievedGuess){
    if(recievedGuess!=NULL)
    std::cout << "Hat guess is "<< recievedGuess.toStdString()<<std::endl;
}

void GameManager::guessHair(QString recievedGuess){
    if(recievedGuess!=NULL)
    std::cout << "Hair guess is "<< recievedGuess.toStdString()<<std::endl;
}



