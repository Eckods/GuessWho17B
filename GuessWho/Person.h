//
//  Person.h
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.


#ifndef GuessWho_Person_h
#define GuessWho_Person_h

#include <iostream>
using namespace std;

class Person
{
private:
    
    const string file = "Person Data";
    const int NUM_PEOPLE = 24;
    
    
    
    struct Basic
    {
        string name, gender, eyeColor;
    };
    
    
    struct Hair
    {
        string hairColor;
    };
    
    struct FacialHair
    {
        bool facialHair;
        string facialHairType;
    };
    
    struct Accessories
    {
        bool hat;
    };
    
    // initialize structs
    Basic basic;
    Hair hair;
    FacialHair facialHair;
    Accessories accessories;
    
public:
    Person(){}
    ~Person(){}
    
    void operator =(const Person& right)
    {
        basic = right.basic;
        hair = right.hair;
        facialHair = right.facialHair;
        accessories = right.accessories;
        
    }
    
    // Basic
    void setName(string n)
    {
        
        basic.name = n;
    }
    
    void setGender(string n)
    {
        
        basic.gender = n;
    }
    
    void setEyeColor(string s)
    {
        
        basic.eyeColor = s;
    }
    
    
    // Hair
    void setHairColor(string n)
    {
        
        hair.hairColor = n;
    }
  
    // Facial Hair
    void setFacialHair(bool n)
    {
        facialHair.facialHair = n;
    }
    
    void setFacialHairType(string n)
    {
        facialHair.facialHairType = n;
    }
    
    // Accessories
    void setHat(bool n)
    {
        accessories.hat = n;
    }
    
    // Get Basic
    string getName()
    {
        
        return basic.name;
    }
    
    string getGender()
    {
        
        return basic.gender;
    }
    
    string getEyeColor()
    {
        
        return basic.eyeColor;
    }
    
    
    // Get Hair
    string getHairColor()
    {
        
        return hair.hairColor;
    }
    
    // Get Facial Hair
    bool hasFacialHair()
    {
        return facialHair.facialHair;
    }
    string getFacialHairType()
    {
        return facialHair.facialHairType;
    }
    
    // Get Accessories
    bool hasHat()
    {
        return accessories.hat;
    }
    
    Person GetPeopleData()
    {
        Person person;
        
        fstream personData(file, ios::in | ios::binary); // stream to read data from file.
        if (personData.fail())
        {
            cout << "File failed....\n";
            exit(1);
        }
        personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                        sizeof(person));
        return person;
    }
    
    
    
    
};



#endif
