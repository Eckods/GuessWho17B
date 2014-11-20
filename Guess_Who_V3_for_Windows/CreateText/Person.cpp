//
//  PersonData.cpp
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<iomanip>
#include <cctype>
#include <stdlib.h>
#include "Person.h"

using namespace std;

string name [] = {"Elena", "Sephiroth", "Haytham", "Peach", "Xion", "Dante", "Ocelot", "Lara",
                  "Luigi", "Rikku", "Adam", "Link", "Samus", "Geralt", "Waluigi", "Shiek",
                  "Connor", "Aerith", "Chloe", "Little Mac", "Lee", "Snake", "Faith",
                  "Dr. Mario"};
string hairColor [] = {"blonde", "white", "brown", "black"};
string eyeColor [] = {"brown", "green" , "blue"};
string facialHairType[] = {"mustache", "beard"};
string gender [] = {"male", "female"};
string image [] = {"background-image:url(:/program/Sheet/Characters1.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters1-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters1-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters1-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters2.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters2-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters2-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters2-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters3.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters3-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters3-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters3-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters4.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters4-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters4-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters4-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters5.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters5-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters5-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters5-Disabled.png);}",
                   "background-image:url(:/program/Sheet/Characters6.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters6-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters6-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters6-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters7.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters7-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters7-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters7-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters8.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters8-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters8-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters8-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters9.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters9-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters9-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters9-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters10.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters10-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters10-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters10-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters11.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters11-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters11-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters11-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters12.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters12-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters12-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters12-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters13.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters13-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters13-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters13-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters14.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters14-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters14-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters14-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters15.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters15-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters15-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters15-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters16.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters16-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters16-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters16-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters17.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters17-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters17-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters17-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters18.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters18-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters18-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters18-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters19.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters19-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters19-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters19-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters20.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters20-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters20-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters20-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters21.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters21-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters21-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters21-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters22.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters22-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters22-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters22-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters23.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters23-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters23-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters23-Disabled.png);}",

                   "background-image:url(:/program/Sheet/Characters24.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                   "QPushButton:hover{background-image:url(:/program/Sheet/Characters24-Hover.png);}"
                   "QPushButton:pressed{background-image:url(:/program/Sheet/Characters24-Disabled.png);}"
                   "QPushButton:disabled{background-image:url(:/program/Sheet/Characters24-Disabled.png);}"};


void CreatePeople(); // creates a txt file that contains specifed list of people from the person class
void DisplayPeople(); // read from text file the list of people and output to console
void AddDataToPerson(); // allows you to select which person you want edit and updates the changes to file
void Prompt(); // Allows to display or add data to a person continuously
void openTextFile();
void saveTextFile();

const string file = "c:/PersonData.txt";
const int NUM_PEOPLE = 24;
const int row = 4;
const int col = 6;
Person person;
Person people[row][col];
bool save = false;



int main()
{
    //    CreatePeople();
    Prompt();

    return 0;
}

void Prompt()
{
    openTextFile();

    bool quit = false;
    int choice = 0;
    while(!quit)
    {
        cout << "1) New Text File\n"
             << "2) Add data to a person\n"
             << "3) Display People\n"
             << "4) Save\n"
             << "5) Load\n"
             << "6) Quit\n"
             << "choice: ";
        cin  >> choice;
        cout << endl;

        bool correctInput = false;
        char a;
        switch(choice)
        {
        case 1:
            do
            {
                cout << "Are you sure you want to create a new text file <Y or N>: ";
                cin >> a;
                if ( tolower(a)== 'y') // change exisiting
                {
                    CreatePeople();
                    correctInput = true;
                    save = false;
                }
                else if (tolower(a) == 'n') // leave alone
                {
                    correctInput = true;
                }
                else
                    correctInput = false;
            }while(!correctInput);
            break;
        case 2:
            //system("clear"); // doesnt work in Xcode
            AddDataToPerson();
            save = false;
            break;
        case 3:
            //system("clear"); // doesnt work in Xcode
            DisplayPeople();
            break;
        case 4:
            saveTextFile();
            save = true;
            break;
        case 5:
            openTextFile();
            break;
        case 6:
            quit = true;
            if (!save)
            {
                correctInput = false;
                do
                {
                    cout << "Are you sure you want to quit? Do you want to OVERWRITE YOUR TEXT FILE<Y or N>: ";
                    cin >> a;
                    if ( tolower(a)== 'y') // change exisiting
                    {
                        cout << "Are you sure you? You may delete EVERYTHING!!!<Y or N>: ";
                        cin >> a;
                        if ( tolower(a)== 'y') // change exisiting
                        {
                            saveTextFile();
                            correctInput = true;
                        }
                        else if (tolower(a) == 'n') // leave alone
                        {
                            correctInput = true;
                        }
                    }
                    else if (tolower(a) == 'n') // leave alone
                    {
                        correctInput = true;
                    }
                    else
                        correctInput = false;
                }while(!correctInput);
            }
            break;
        }
    }
    cout << endl;


}

void GetPeopleData()
{
    fstream personData(file.c_str(), ios::in | ios::binary); // stream to read data from file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                    sizeof(person));


    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if (!!personData.eof())
            {
                people[i][j] = person;
                personData.read(reinterpret_cast<char *>(&person),sizeof(person));
            }
        }
        if (!personData.eof())
        {
            personData.read(reinterpret_cast<char *>(&person),sizeof(person));
        }
    }

    //    while(!personData.eof())
    //    {
    //        people.Append(person);

    //        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    //    }
    personData.close();
}

void DisplayPeople()
{

    int personCount = 0;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        {
            personCount++;
            cout << "Person " << personCount << endl
                 << setw(10) << people[i][j].getName() << endl;
            cout << setw(20) << "Gender: " << people[i][j].getGender() << endl;
            cout << setw(20) << "Eye Color: " << people[i][j].getEyeColor() << endl;
            cout << setw(20) << "Hair Color: " << people[i][j].getHairColor() << endl;
            cout << setw(20) << "Facial Hair: ";
            if (people[i][j].hasFacialHair())
                cout << "yes" << endl;
            else
                cout << "no" << endl;
            cout << setw(20) << "Facial Hair Type: " << people[i][j].getFacialHairType() << endl;
            cout << setw(20) << "Hat: ";
            if (people[i][j].hasHat())
                cout << "yes" << endl;
            else
                cout << "no"<< endl;
            cout<< setw(20) << "Image: " << people[i][j].getImage().toStdString() << endl << endl;
        }

}

void CreatePeople()
{

    fstream personData(file.c_str() , ios::out | ios:: trunc | ios::binary); // stream to write data to a file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }

    //    Person newPerson;
    //    int personCount = 0;
    //    for (int i=0; i<row; i++) // NUM_PEOPLE - can be changed to the desired amount of people we want to describe.
    //        for (int j=0; j<col; j++)
    //        {
    //            personCount++;
    //            cout << "Now writing person " << personCount << endl;
    //            people[i][j] = newPerson;
    //            personData >> people[i][j];
    //        }

    //    cout << endl;
    personData.close();
}

// Can go through one by one giving a Person's decription by inputting the diesired person you want to provide data with.
void AddDataToPerson()
{
    int i;
    bool correctInput = false;

    do {
        // Get the person number of the desired record.
        cout << "Which person do you want to edit <1-" << NUM_PEOPLE <<">: ";
        cin >> i;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            correctInput = false;
        }
        else if (i > 0 && i <= NUM_PEOPLE)
            correctInput = true;
    }while(!correctInput);
    cout << endl;

    if (i > 0)
        i--;

    Person *_person;
    switch (i)
    {
    case 0:
        _person = &people[0][0];
        break;
    case 1:
        _person = &people[0][1];
        break;
    case 2:
        _person = &people[0][2];
        break;
    case 3:
        _person = &people[0][3];
        break;
    case 4:
        _person = &people[0][4];
        break;
    case 5:
        _person = &people[0][5];
        break;
    case 6:
        _person = &people[1][0];
        break;
    case 7:
        _person = &people[1][1];
        break;
    case 8:
        _person = &people[1][2];
        break;
    case 9:
        _person = &people[1][3];
        break;
    case 10:
        _person = &people[1][4];
        break;
    case 11:
        _person = &people[1][5];
        break;
    case 12:
        _person = &people[2][0];
        break;
    case 13:
        _person = &people[2][1];
        break;
    case 14:
        _person = &people[2][2];
        break;
    case 15:
        _person = &people[2][3];
        break;
    case 16:
        _person = &people[2][4];
        break;
    case 17:
        _person = &people[2][5];
        break;
    case 18:
        _person = &people[3][0];
        break;
    case 19:
        _person = &people[3][1];
        break;
    case 20:
        _person = &people[3][2];
        break;
    case 21:
        _person = &people[3][3];
        break;
    case 22:
        _person = &people[3][4];
        break;
    case 23:
        _person = &people[3][5];
        break;

    default:
        break;
    }

    // Display the person contents.
    cout << "\nName: " << _person->getName() << ":" << endl
         << "Gender: " << _person->getGender() << endl
         << "Eye Color: " << _person->getEyeColor() << endl
         << "Hair Color: " << _person->getHairColor() << endl
         << "Facial Hair: " << _person->hasFacialHair() << endl
         << "Facial Hair Type: " << _person->getFacialHairType() << endl
         << "Hat: " << _person->hasHat() << endl
         << "Image: " <<_person->getImage().toStdString()<< endl << endl;

    _person->setData(true);
    int selection = 0;
    // Get the new person data.
    char answer = NULL;
    do
    {
        cout << "\nName: " << _person->getName() << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Person Name: ";
            cin >> selection;
            if (selection >=0 || selection <= 23)
            {
                _person->setName(name[selection]);
                correctInput = true;
            }
            else
                correctInput = false;

        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);

    do
    {
        cout << "Gender: " << _person->getGender() << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Gender: ";
            cin >> selection;

            if (selection >=0 || selection <= 1)
            {
                _person->setGender(gender[selection]);
                correctInput = true;
            }
            else
                correctInput = false;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);

    do
    {
        cout  << "Hair Color: " << _person->getHairColor()  << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Hair Color: ";
            cin >> selection;

            if (selection >=0 || selection <= 3)
            {
                _person->setHairColor(hairColor[selection]);
                correctInput = true;
            }
            else
                correctInput = false;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);

    do
    {
        cout  << "Eye Color: " << _person->getEyeColor()  << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Eye Color: ";
            cin >> selection;

            if (selection >=0 || selection <= 2)
            {
                _person->setEyeColor(eyeColor[selection]);
                correctInput = true;
            }
            else
                correctInput = false;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);

    do
    {
        cout << "Facial Hair: " << _person->hasFacialHair() << " Change<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            do
            {
                cout << "Facial Hair <Y or N>: ";
                cin >> answer;
                if ( tolower(answer)== 'y')
                {
                    correctInput = true;
                    _person->setFacialHair(true);

                    cout << "Facial Hair Type: ";
                    cin >> selection;

                    switch (selection)
                    {
                    case 0:
                        _person->setFacialHairType(facialHairType[0]);
                        break;
                    case 1:
                        _person->setFacialHairType(facialHairType[1]);
                        break;
                    default:
                        break;
                    }
                    correctInput = true;
                }
                else if (tolower(answer) == 'n')
                {
                    correctInput = true;
                    _person->setFacialHair(false);
                    _person->setFacialHairType("none");
                }
                else
                    correctInput = false;
            }while(!correctInput);
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);
    do
    {
        cout  << "Hat: " << _person->hasHat()  << " Change<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            do
            {
                cout << "Hat <Y or N>: ";
                cin >> answer;
                if ( tolower(answer)== 'y')
                {
                    correctInput = true;
                    _person->setHat(true);
                }
                else if(tolower(answer) == 'n')
                {
                    correctInput = true;
                    _person->setHat(false);
                }
                else
                    correctInput = false;
            }while(!correctInput);
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);

    do
    {
        cout << "Image: " << _person->getImage().toStdString() << " Rename<Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y') // change exisiting
        {
            cout << "Image: ";
            cin >> selection;

            if (selection >=0 || selection <= 23)
            {
                _person->setImage(image[selection]);
                correctInput = true;
            }
            else
                correctInput = false;
        }
        else if (tolower(answer) == 'n') // leave alone
        {
            correctInput = true;
        }
        else
            correctInput = false;
    }while(!correctInput);

    cout << endl;

    switch (i)
    {
    case 0:
        cout << "\nNew name: " << people[0][0].getName() << endl;
        break;
    case 1:
        cout << "\nNew name: " << people[0][1].getName() << endl;
        break;
    case 2:
        cout << "\nNew name: " << people[0][2].getName() << endl;
        break;
    case 3:
        cout << "\nNew name: " << people[0][3].getName() << endl;
        break;
    case 4:
        cout << "\nNew name: " <<  people[0][4].getName() << endl;
        break;
    case 5:
        cout << "\nNew name: " <<  people[0][5].getName() << endl;
        break;
    case 6:
        cout << "\nNew name: " << people[1][0].getName() << endl;
        break;
    case 7:
        cout << "\nNew name: " << people[1][1].getName() << endl;
        break;
    case 8:
        cout << "\nNew name: " << people[1][2].getName() << endl;
        break;
    case 9:
        cout << "\nNew name: " << people[1][3].getName() << endl;
        break;
    case 10:
        cout << "\nNew name: " << people[1][4].getName() << endl;
        break;
    case 11:
        cout << "\nNew name: " << people[1][5].getName() << endl;
        break;
    case 12:
        cout << "\nNew name: " << people[2][0].getName() << endl;
        break;
    case 13:
        cout << "\nNew name: " << people[2][1].getName() << endl;
        break;
    case 14:
        cout << "\nNew name: " << people[2][2].getName() << endl;
        break;
    case 15:
        cout << "\nNew name: " << people[2][3].getName() << endl;
        break;
    case 16:
        cout << "\nNew name: " << people[2][4].getName() << endl;
        break;
    case 17:
        cout << "\nNew name: " << people[2][5].getName() << endl;
        break;
    case 18:
        cout << "\nNew name: " << people[3][0].getName() << endl;
        break;
    case 19:
        cout << "\nNew name: " << people[3][1].getName() << endl;
        break;
    case 20:
        cout << "\nNew name: " << people[3][2].getName() << endl;
        break;
    case 21:
        cout << "\nNew name: " << people[3][3].getName() << endl;
        break;
    case 22:
        cout << "\nNew name: " << people[3][4].getName() << endl;
        break;
    case 23:
        cout << "\nNew name: " << people[3][5].getName() << endl;
        break;

    default:
        break;
    }
    cout << endl;
}


void openTextFile()
{
    fstream personData(file.c_str(), ios::in | ios::binary);

    if (personData.fail())
    {
        cout << "File not detected...\n";
        cout << "Creating a new file...\n"<< endl;

        CreatePeople();
        personData.open(file.c_str(), ios::in | ios::binary);
        if (personData.fail())
        {
            cout << "Theres no hope\n";
            exit(1);
        }
    }
    int personCount = 0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if (!personData.eof())
            {
                bool hasData = false;
                personData >> hasData;
                personCount++;
                if (hasData == true)
                {

                    cout << "Loading Person " << personCount << endl;
                    person.setData(hasData);
                    personData >> person;
                    people[i][j] = person;
                }
                else
                    cout << "No data for Person " << personCount << endl;

            }
        }
    }
    cout << endl;
    personData.close();
}

void saveTextFile()
{
    fstream personData(file.c_str(), ios::out | ios::trunc  | ios::binary);
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }

    int personCount = 0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {

            personCount++;
            if (people[i][j].getData() == true)
            {
                cout << "Saving Person " << personCount << endl;
                personData << people[i][j];
            }
            else
                cout << "No data for Person " << personCount << endl;

        }
    }
    cout << endl;

    personData.close();
}

