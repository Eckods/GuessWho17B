//
//  Person.h
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//

#ifndef GuessWho_Person_h
#define GuessWho_Person_h

//
//  main.cpp
//  GuessWho
//
//  Created by Kory Brown on 9/19/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//

#include <iostream>

using namespace std;

class Person
{
private:
    
    struct Basic
    {
        string name, skinColor, gender, eyeColor;
    };
    
    
    struct Hair
    {
        string hairType, hairColor, hairLength;
    };
    
    struct FacialHair
    {
        string facialHairType, facialHairColor;
    };
    
    struct Accessories
    {
        string hat, hatColor, glasses, earrings;
    };
    
   public:
    Person(){}
    ~Person(){}
//    void setBasicFeatures(){}
//    void setHairFeatures(){}
//    void setFacialHairFeatures();
//    void setAccessoriesFeatures();
//    string getBasicFeature();
//    string getHairFeature();
//    string getFacialHairFeature();
//    string getAccessoriesFeature();
    void Print()
    {
        cout << basic.name << " " << basic.gender << " " << basic.eyeColor << endl
             << hair.hairType << " " << hair.hairColor << " " << hair.hairLength << endl
             << facialHair.facialHairType << " " << facialHair.facialHairColor << endl
             << accessories.hat << " " << accessories.hatColor << accessories.glasses
             << accessories.earrings << endl;
    }
    Basic basic;
    Hair hair;
    FacialHair facialHair;
    Accessories accessories;

};



#endif
