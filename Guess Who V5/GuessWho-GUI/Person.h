//
//  Person.h
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.


#ifndef GuessWho_Person_h
#define GuessWho_Person_h

#include <iostream>
#include <fstream>
#include <QString>
#include <QTextStream>
using namespace std;



struct Basic
{
    QString name, gender, eyeColor;
};


struct Hair
{
    QString hairColor;
};

struct FacialHair
{
    bool facialHair;
    QString facialHairType;
};

struct Accessories
{
    bool hat;
};


class Person
{
private:
    QString image;
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
        image = right.image;

    }

    void setData(bool a)
    {
        data = a;
    }
    bool getData()
    {
        return data;
    }

    // Image
    void setImage(QString n)
    {
        image = n;
    }

    // Basic
    void setName(QString n)
    {

        basic.name = n;
    }

    void setGender(QString n)
    {

        basic.gender = n;
    }

    void setEyeColor(QString s)
    {

        basic.eyeColor = s;
    }


    // Hair
    void setHairColor(QString n)
    {

        hair.hairColor = n;
    }

    // Facial Hair
    void setFacialHair(bool n)
    {
        facialHair.facialHair = n;
    }

    void setFacialHairType(QString n)
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
//        QString i = image.c_str();
        return image;
    }

    // Get Basic
    QString getName()
    {

        return basic.name;
    }

    QString getGender()
    {

        return basic.gender;
    }

    QString getEyeColor()
    {

        return basic.eyeColor;
    }


    // Get Hair
    QString getHairColor()
    {

        return hair.hairColor;
    }

    // Get Facial Hair
    bool hasFacialHair()
    {
        return facialHair.facialHair;
    }
    QString getFacialHairType()
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
