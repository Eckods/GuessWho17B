#include "gamemanager.h"
#include "mainwindow.h"

GameManager *GameManager::m_Instance=0;

Person characterProfile;

GameManager::GameManager(){
    replyBox = new QTextBrowser;
    replyBox->setFixedSize(300,400);
}

//void GameManager::start(){
//    isRunning=true;
//}

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

void GameManager::guessEyeColor(QString sendGuess){
    if(sendGuess!=NULL){
        recieveEyeCheck(sendGuess);
    }
}

void GameManager::guessFacialHair(QString sendGuess){
    if(sendGuess!=NULL){
        recieveFacialHairCheck(sendGuess);
    }
}

void GameManager::guessGender(QString sendGuess){
    if(sendGuess!=NULL){
        recieveGenderCheck(sendGuess);
    }
}

void GameManager::guessHeadWear(){
    recieveHeadWearCheck();
}

void GameManager::guessHair(QString sendGuess){
    if(sendGuess!=NULL){
        recieveHairCheck(sendGuess);
    }
}

void GameManager::recieveEyeCheck(QString recieveGuess){
    QString sendAnswer;
    int x = QString::compare(recieveGuess,
                             characterProfile.getEyeColor(),
                             Qt::CaseInsensitive);
    cout<<"X = "<<x<<std::endl;
    QString A = recieveGuess;
    QString B = characterProfile.getEyeColor();
    std::cout<<"A: "<<A.toStdString()<<std::endl;
    std::cout<<"B: "<<B.toStdString()<<std::endl;
    if(x==0){
        sendAnswer = "<font color='red'>Opponent says</font>: Yes";
    }
    else{
        sendAnswer = "<font color='blue'>Opponent says</font>: No";
    }
    chatBox(sendAnswer);
}

void GameManager::recieveFacialHairCheck(QString recieveGuess){
    QString sendAnswer;
    if(characterProfile.hasFacialHair()){
        int x = QString::compare(recieveGuess,
                                 characterProfile.getFacialHairType(),
                                 Qt::CaseInsensitive);
        cout<<"X = "<<x<<std::endl;
        QString A = recieveGuess;
        QString B = characterProfile.getFacialHairType();
        std::cout<<"A: "<<A.toStdString()<<std::endl;
        std::cout<<"B: "<<B.toStdString()<<std::endl;
        if(x==0){
            sendAnswer = "<font color='red'>Opponent says</font>: Yes";
        }
        else{
            sendAnswer = "<font color='blue'>Opponent says</font>: No";
        }
    }
    else if(!characterProfile.hasFacialHair()){
        sendAnswer = "<font color='blue'>Opponent says</font>: No";
    }
    chatBox(sendAnswer);
}

void GameManager::recieveGenderCheck(QString recieveGuess){
    QString sendAnswer;
    int x = QString::compare(recieveGuess,
                             characterProfile.getGender(),
                             Qt::CaseInsensitive);
    cout<<"X = "<<x<<std::endl;
    QString A = recieveGuess;
    QString B = characterProfile.getGender();
    std::cout<<"A: "<<A.toStdString()<<std::endl;
    std::cout<<"B: "<<B.toStdString()<<std::endl;
    if(x==0){
        sendAnswer = "<font color='red'>Opponent says</font>: Yes";
    }
    else{
        sendAnswer = "<font color='blue'>Opponent says</font>: No";
    }
    //    std::cout<<"C: "<<characterProfile.getName().toStdString()<<std::endl;
    chatBox(sendAnswer);
}

void GameManager::recieveHairCheck(QString recieveGuess){
    QString sendAnswer;
    int x = QString::compare(recieveGuess,
                             characterProfile.getHairColor(),
                             Qt::CaseInsensitive);
    cout<<"X = "<<x<<std::endl;
    QString A = recieveGuess;
    QString B = characterProfile.getHairColor();
    std::cout<<"A: "<<A.toStdString()<<std::endl;
    std::cout<<"B: "<<B.toStdString()<<std::endl;
    if(x==0){
        sendAnswer = "<font color='red'>Opponent says</font>: Yes";
    }
    else{
        sendAnswer = "<font color='blue'>Opponent says</font>: No";
    }
    chatBox(sendAnswer);
}

void GameManager::recieveHeadWearCheck(){
    QString sendAnswer;
    if(characterProfile.hasHat()){
        sendAnswer = "<font color='red'>Opponent says</font>: Yes";
    }
    else if(!characterProfile.hasHat()){
        sendAnswer = "<font color='blue'>Opponent says</font>: No";
    }
    chatBox(sendAnswer);
}

void GameManager::setPlayerPerson(Person Mycharacter){
    characterProfile=Mycharacter;
}

void GameManager::chatBox(QString incoming){
    GameManager::instance()->replyBox->append(incoming);
}




