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
#include <vector>
#include "Person.h"
using namespace std;


void CreatePerson(); // creates a txt file that contains specifed list of people from the person class
void ReadInPersonData(); // read from text file the list of people and output to console
void AddDataToPerson(); // allows you to select which person you want edit and updates the changes to file

vector<Person> people;
Person person;
const string file = "PersonData";
const int NUM_PEOPLE = 10;

int main()
{
    
    // first uncommment CreatePerson then run it to create a txt file that holds a place holder for 10 people
    // second comment CreatePerson then uncomment ReadInPersonData then run it to see the list of people. It will only contain numbers for now (just place holders)
    // third comment ReadInPersonData then uncomment AddDataToPerson then run it to add data to a person of ur choice
    
    //CreatePerson();
    //ReadInPersonData();
    //AddDataToPerson();
    
    return 0;
}

void ReadInPersonData()
{
    fstream personData(file, ios::in | ios::binary);
    personData.read(reinterpret_cast<char *>(&person),
                                      sizeof(person));
    while(!personData.eof())
    {
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
        
        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    }
}


void CreatePerson()
{
    person.basic = {"","","",""};
    person.hair = {"","",""};
    person.facialHair = {"",""};
    person.accessories = {"","","",""};
    
    fstream personData(file, ios::out | ios::binary);
    
    for (int i=0; i<NUM_PEOPLE; i++)
    {
        cout << "Now writing person " << i << endl;
        personData.write(reinterpret_cast<char *>(&person),sizeof(person));
        
    }
    personData.close();
}

void AddDataToPerson()
{
    int i;
    // Open the file in binary mode for input and output
    fstream personData(file, ios::in | ios::out | ios::binary);
   // Get the record number of the desired record.
    cout << "Which person do you want to edit? ";
   cin >> i;
    
   // Move to the record and read it.
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


    // Get the new record data.
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
    cout << "Facial Hair Type: ";
    cin  >> person.facialHair.facialHairType;
    cout << "Facial Hair Color: ";
    cin  >> person.facialHair.facialHairColor;
    cout << "Hat: ";
    cin  >> person.accessories.hat;
    cout << "HatColor: ";
    cin  >> person.accessories.hatColor;
    cout << "Glasses: ";
    cin  >> person.accessories.glasses;
    cout << "Earrings: ";
    cin  >> person.accessories.earrings;

    // Move back to the beginning of this person's position.
    personData.seekp(i * sizeof(person), ios::beg);

    // Write the new record over the current record.
    personData.write(reinterpret_cast<char *>(&person),
                                         sizeof(person));
}
