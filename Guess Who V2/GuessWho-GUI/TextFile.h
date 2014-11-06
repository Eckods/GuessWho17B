#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<iomanip>
#include <cctype>
#include <stdlib.h>
#include "Person.h"

using namespace std;


const string file =":/program/PersonData.txt";
const int row = 4;
const int col = 6;

class TextFile
{

public:
    void getDataFromFile(Person people[][col])
    {
        fstream personData(file.c_str(), ios::in | ios::binary);

        if (personData.fail())
        {
            cout << "File not detected...\n";
            exit(1);

        }
        int personCount = 0;
        Person temp;
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
                        temp.setData(hasData);
                        personData >> temp;
                        people[i][j] = temp;
                    }
                    else
                        cout << "No data for Person " << personCount << endl;

                }
            }
        }
        cout << endl;
        personData.close();
    }
};
#endif // TEXTFILE_H
