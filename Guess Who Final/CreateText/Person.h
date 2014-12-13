//
//  Person.h
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.


#ifndef GuessWho_Person_h
#define GuessWho_Person_h

#include <iostream>
#include <QString>
using namespace std;


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


class Person
{
private:
    string image;
    bool data;

    // initialize structs
    Basic basic;
    Hair hair;
    FacialHair facialHair;
    Accessories accessories;

public:
    Person()
    {
        setImage(" ");
        setName(" ");
        setGender(" ");
        setEyeColor(" ");
        setHairColor(" ");
        setFacialHair(false);
        setFacialHairType(" ");
        setHat(false);
    }
    ~Person(){}

    void operator =(const Person& right)
    {
        basic = right.basic;
        hair = right.hair;
        facialHair = right.facialHair;
        accessories = right.accessories;
        image = right.image.c_str();

    }


    friend fstream &operator << (fstream & out,  Person &person)
    {
        out << person.getData() << endl;
        out << person.getName() << endl;
        out << person.getGender() << endl;
        out << person.getEyeColor() << endl;
        out << person.getHairColor() << endl;
        out << person.hasFacialHair() << endl;
        out << person.getFacialHairType() << endl;
        out << person.hasHat() << endl;
        out << person.getImage().toStdString() << endl;
        out << endl;

        return out;
    }

    friend fstream &operator >> (fstream & in,  Person &person)
    {
        string garbage;
        getline(in, garbage);  // moves the cursor to nextLine
        getline(in, person.basic.name);
        in >> person.basic.gender;
        in >> person.basic.eyeColor;
        in >> person.hair.hairColor;
        in >> person.facialHair.facialHair;
        in >> person.facialHair.facialHairType;
        in >> person.accessories.hat;
        getline(in, garbage); // moves the cursor to nextLine
        getline(in, person.image);
        person.data = true;

        return in;
    }
    //   void dataCheck()
    //   {
    //       if (basic.name != NULL && basic.gender != NULL && basic.eyeColor != NULL && hair.hairColor != NULL
    //               && facialHair.facialHair != NULL && facialHair.facialHairType != NULL && accessories.hat != NULL && image != NULL)
    //           data = true;
    //       else
    //           data = false;
    //   }

    void setData(bool a)
    {
        data = a;
    }
    bool getData()
    {
        return data;
    }

    // Image
    void setImage(string n)
    {
        image = n;
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

    // Get Image
    //    sring getImage()
    //    {
    //        return image;
    //    }
    QString getImage()
    {
        QString i = image.c_str();
        return i;
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

};



#endif
