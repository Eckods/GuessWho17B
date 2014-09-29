//
//  PersonData.cpp
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//


//**************************************** READ THIS *************************************************************************
// As it stands these 2 files creates a specified number of people in a txt file filled with place holder data than you can then view or edit the person. Its just the beginning but its a good start for now

// your going to have to set the location of where the txt file is saved on your computer because its going to be different for everyone

//**********************************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cctype>
#include <stdlib.h>
#include "Person.h"
using namespace std;


void CreatePeople(); // creates a txt file that contains specifed list of people from the person class
void DisplayPeople(); // read from text file the list of people and output to console
void AddDataToPerson(); // allows you to select which person you want edit and updates the changes to file
void Prompt(); // Allows to display or add data to a person continuously

Person person;
const string file = "PersonData";
const int NUM_PEOPLE = 10;

int main()
{
    
    // first uncommment CreatePerson then run it to create a txt file that holds a place holder for 10 people
    // second comment CreatePerson then uncomment ReadInPersonData then run it to see the list of people. It will only contain numbers for now (just place holders)
    // third comment ReadInPersonData then uncomment AddDataToPerson then run it to add data to a person of ur choice
    
    CreatePeople();
    //DisplayPeople();
    //AddDataToPerson();
    Prompt();
    
    return 0;
}

void Prompt()
{
    DisplayPeople();
    bool quit = false;
    int choice = 0;
    while(!quit)
    {
        cout << "1) Add data to a person\n"
             << "2) Display People\n"
             << "3) Quit\n"
             << "choice: ";
        cin  >> choice;
        
        switch(choice)
        {
            case 1:
                //system("clear"); // doesnt work in Xcode
                AddDataToPerson();
                break;
            case 2:
                //system("clear"); // doesnt work in Xcode
                DisplayPeople();
                break;
            case 3:
                quit = true;
                break;
        }
    }
    cout << endl;
}

void DisplayPeople()
{
    fstream personData(file, ios::in | ios::binary); // stream to read data from file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                                      sizeof(person));
    int personCount = 0;
    while(!personData.eof())
    {
        personCount++;
        cout << "Person " << personCount
             << "\nName: " << person.basic.name << endl
             << "Gender: " << person.basic.gender
             << " Skin Color: " << person.basic.skinColor
             << " Eye Color: " << person.basic.eyeColor << endl;
        
        cout << "Hair Type: " << person.hair.hairType
             << " Hair Color: " << person.hair.hairColor
             << " Hair Length: " << person.hair.hairLength << endl;
        
        cout << "Facial Hair Type: " << person.facialHair.facialHairType
             << " Facial Hair Color: " << person.facialHair.facialHairColor
             << endl;
        
        cout << "Hat: " << person.accessories.hat
             << " HatColor: " << person.accessories.hatColor
             << " Glasses: " << person.accessories.glasses
             << " Earrings: " << person.accessories.earrings << endl << endl;
        
        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    }
    personData.close();
}


void CreatePeople()
{
    // creating space in each memeber of the structs.
    person.basic = {"","","",""};
    person.hair = {"","",""};
    person.facialHair = {false, "",""};
    person.accessories = {false,"", false, false};
    
    fstream personData(file, ios::out | ios::binary); // stream to write data to a file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    
    for (int i=0; i<NUM_PEOPLE; i++) // NUM_PEOPLE - can be changed to the desired amount of people we want to describe.
    {
        cout << "Now writing person " << i << endl;
        personData.write(reinterpret_cast<char *>(&person),sizeof(person));
        
    }
    cout << endl;
    personData.close();
}

// Can go through one by one giving a Person's decription by inputting the diesired person you want to provide data with.
void AddDataToPerson()
{
    int i;
    bool correctInput = false;
    
    // Open the file in binary mode for input and output
    fstream personData(file, ios::in | ios::out | ios::binary); // stream to read and write to file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    do {
        // Get the person number of the desired record.
        cout << "Which person do you want to edit <1-10>? ";
        cin >> i;
        if (i > 0 && i <= NUM_PEOPLE)
            correctInput = true;
    }while(!correctInput);
    correctInput = false;
    cout << endl;
    
    if (i == 1)
        i--;
    else if (i == NUM_PEOPLE)
        i--;
    // Move to the person selected and read it.
    personData.seekg(i * sizeof(person), ios::beg);
    personData.read(reinterpret_cast<char *>(&person),
                    sizeof(person));
    
    // Display the person contents.
    cout << "Person Name: " << person.basic.name << endl
    << "Gender: " << person.basic.gender
    << " Skin Color: " << person.basic.skinColor
    << " Eye Color: " << person.basic.eyeColor << endl;
    
    cout << "Hair Type: " << person.hair.hairType
    << " Hair Color: " << person.hair.hairColor
    << " Hair Length: " << person.hair.hairLength << endl;
    
    cout << "Facial Hair Type: " << person.facialHair.facialHairType
    << " Facial Hair Color: " << person.facialHair.facialHairColor
    << endl;
    
    cout << "Hat: " << person.accessories.hat
    << " HatColor: " << person.accessories.hatColor
    << " Glasses: " << person.accessories.glasses
    << " Earrings: " << person.accessories.earrings << endl << endl;
    
    
    // Get the new person data.
    char answer = NULL;
    cout << "Enter the new data:\n";
    cout << "Person Name: ";
    cin.ignore();
    getline(cin, person.basic.name);
    cout << "Gender: ";
    //cin.ignore();
    cin  >> person.basic.gender;
    cout << "Skin Color: ";
    cin  >> person.basic.skinColor;
    cout << "Eye Color: ";
    cin  >> person.basic.eyeColor;
    cout << "Hair Type: ";
    cin >> person.hair.hairType;
    cout << "Hair Color: ";
    cin  >> person.hair.hairColor;
    cout << "Hair Length: ";
    cin  >> person.hair.hairLength;
    do
    {
        cout << "Facial Hair <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.facialHair.facialHair = true;
        }
        else if (tolower(answer) == 'n')
        {
            correctInput = true;
            person.facialHair.facialHair = false;
        }
        else
            correctInput = false;
    }while(!correctInput);
    correctInput = false;
    answer = NULL;
    if(person.facialHair.facialHair == true)
    {
        cout << "Facial hair type: ";
        cin  >> person.facialHair.facialHairType;
        cout << "Facial Hair Color: ";
        cin  >> person.facialHair.facialHairColor;
    }
    else
    {
        person.facialHair.facialHairType = "none";
        person.facialHair.facialHairColor = "none";
    }
    do
    {
        cout << "Hat <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.accessories.hat = true;
        }
        else if(tolower(answer) == 'n')
        {
            correctInput = true;
            person.accessories.hat = false;
        }
        else
            correctInput = false;
    }while(!correctInput);
    if (person.accessories.hat == true)
    {
        cout << "HatColor: ";
        cin  >> person.accessories.hatColor;
    }
    else
        person.accessories.hatColor = "none";
    do
    {
        cout << "Glasses <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.accessories.glasses = true;
        }
        else if (tolower(answer) == 'n')
        {
            correctInput = true;
            person.accessories.glasses = false;
        }
        else
            correctInput = false;
    }while(!correctInput);
    answer = NULL;
    do
    {
        cout << "Earrings <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.accessories.earrings = true;
        }
        else if(tolower(answer) == 'n')
        {
            correctInput = true;
            person.accessories.earrings = false;
        }
        else
            correctInput = false;
    }while(!correctInput);
    answer = NULL;
    cout << endl;
    
    // Move back to the beginning of this person's position.
    personData.seekp(i * sizeof(person), ios::beg);
    
    // Write the new person over the current person.
    personData.write(reinterpret_cast<char *>(&person),
                     sizeof(person));
    personData.close();
}

