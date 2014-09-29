/* 
 * File:   GameManager.cpp
 * Author: Victoria
 * 
 * Created on September 22, 2014, 3:37 PM
 */

#include "GameManager.h"
#include <cstdlib>
#include <ctime>

GameManager::GameManager(){
    //Set random seed generator
    srand(static_cast<unsigned int>(time(0)));
    //initialize Computer and User person cards to not set= -1
    computer = -1;
    user = -1;
}

bool GameManager::gamePlay(int index,int qType,bool &gameOver){
    int turn=0;
    
    if(turn==0){
        //Computer's turn
        if(computer==-1){//i.e. if card not yet chosen
            //Randomly choose person card
            computer = rand()%24;
            turn+=1;
        }else{
            turn+=1;//Next player's turn
            return guess(turn,index,qType,gameOver);
        }
    }else{
        //User's turn
        if(user==-1){//i.e. if card not yet chosen
            //Randomly choose person card
            bool same;//test to see if user card chosen is same as computer
            do{
                same=false;
                user = rand()%24;
                if(user==computer){
                    same = true;
                }
            }while(same);
            turn-=1;
        }else{
            turn-=1;//Next player's turn
            return guess(turn,index,qType,gameOver);
        }
    }
}


//If questions in arrays are full questions, the == operator can be overloaded
//Input
//      int turn - determine computer or user turn
//      int index - the question from a particular array
//      int qType - refers to which question category (array)
//      bool &gameOver - assigned true if name guessed
//Output
//      bool - returns value to determine which cards to remove
bool GameManager::guess(int turn, int index, int qType,bool &gameOver){
    if(turn==0){
        //Computer's turn
        switch(qType){
            case 1:
                //Name
                if(names[index]==cards[user].basic.name){
                    gameOver = true;
                    return true;
                }else{
                    return false;
                }
                break;
            case 2:
                //Skin
                return skinQs[index]==cards[user].basic.skinColor;
                break;
            case 3:
                //Gender
                return genderQs[index]==cards[user].basic.gender;
                break;    
            case 4:
                //Eyes
                return eyeQs[index]==cards[user].basic.eyeColor;
                break;
            case 5:
                //Hair
                //Change to if statement to deal with ranges
                //array should have different (one element each type) hair types, 
                //followed by hair colors, followed by hair lengths, 
                switch(index){
                    case 0:
                        //Hair type
                        return hairQs[index]==cards[user].hair.hairType;
                        break;
                    case 1:
                        //Hair color
                        return hairQs[index]==cards[user].hair.hairColor;
                        break;
                    case 2:
                        //Hair length
                        return hairQs[index]==cards[user].hair.hairLength;
                        break;
                }
                break;
            case 6:
                //Facial Hair
                //Change to if statement to deal with ranges
                //array should have different (one element each type)
                //facial hair types, followed by the facial hair colors
                
                switch(index){
                    case 0:
                        //Facial Hair
                        return cards[user].facialHair.facialHair;
                        break;
                    case 1:
                        //Facial hair types
                        return faceHairQs[index]==cards[user].facialHair.facialHairType;
                        break;
                    case 2:
                        //Facial hair color
                        return faceHairQs[index]==cards[user].facialHair.facialHairColor;
                        break;
                }
                break;
            case 7:
                //Accessories
                //Change to if statement to deal with ranges
                //array should have different (one element each type)
                //hat-bool, list of hat colors, glasses-bool, earrings-bool
                switch(index){
                    case 0:
                        //Hat
                        return cards[user].accessories.hat;
                        break;
                    case 1:
                        //Hat Color
                        return accessoryQs[index]==cards[user].accessories.hatColor;
                        break;
                    case 2:
                        //Glasses
                        return cards[user].accessories.glasses;
                        break;
                    case 3:
                        //Earrings
                        return cards[user].accessories.earrings;
                        break;
                }
                break;
        }
    }else{
        //User's turn
        switch(qType){
            case 1:
                //Name
                if(names[index]==cards[computer].basic.name){
                    gameOver=true;
                    return true;
                }else{
                    return false;
                }
                break;
            case 2:
                //Skin
                return skinQs[index]==cards[computer].basic.skinColor;
                break;
            case 3:
                //Gender
                return genderQs[index]==cards[computer].basic.gender;
                break;    
            case 4:
                //Eyes
                return eyeQs[index]==cards[computer].basic.eyeColor;
                break;
            case 5:
                //Hair
                //Change to if statement to deal with ranges
                //array should have different (one element each type) hair types, 
                //followed by hair colors, followed by hair lengths, 
                switch(index){
                    case 0:
                        //Hair type
                        return hairQs[index]==cards[computer].hair.hairType;
                        break;
                    case 1:
                        //Hair color
                        return hairQs[index]==cards[computer].hair.hairColor;
                        break;
                    case 2:
                        //Hair length
                        return hairQs[index]==cards[computer].hair.hairLength;
                        break;
                }
                break;
            case 6:
                //Facial Hair
                //Change to if statement to deal with ranges
                //array should have different (one element each type)
                //facial hair types, followed by the facial hair colors
                switch(index){
                    case 0:
                        //Facial Hair
                        return cards[computer].facialHair.facialHair;
                        break;
                    case 1:
                        //Facial hair types
                        return faceHairQs[index]==cards[computer].facialHair.facialHairType;
                        break;
                    case 2:
                        //Facial hair color
                        return faceHairQs[index]==cards[computer].facialHair.facialHairColor;
                        break;
                }
                break;
            case 7:
                //Accessories
                //Change to if statement to deal with ranges
                //array should have different (one element each type)
                //hat-bool, list of hat colors, glasses-bool, earrings-bool
                switch(index){
                    case 0:
                        //Hat
                        return cards[computer].accessories.hat;
                        break;
                    case 1:
                        //Hat Color
                        return accessoryQs[index]==cards[computer].accessories.hatColor;
                        break;
                    case 2:
                        //Glasses
                        return cards[computer].accessories.glasses;
                        break;
                    case 3:
                        //Earrings
                        return cards[computer].accessories.earrings;
                        break;
                }
                break;
        }
    }
}