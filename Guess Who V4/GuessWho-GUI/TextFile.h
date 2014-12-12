#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<iomanip>
#include <cctype>
#include <stdlib.h>
#include "Person.h"
#include <QFile>
#include <QString>
#include <QMessageBox>

using namespace std;

const QString file =":/program/PersonData.txt";
const int row = 4;
const int col = 6;

class TextFile
{

public:
    void getDataFromFile(Person people[][col])
    {
        QFile path(file);
        if (!path.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(0, "error", path.errorString());
            exit(55);
        }

        QTextStream personData(&path);

        //        fstream personData(file.c_str(), ios::in | ios::binary);

        //        if (personData.fail())
        //        {
        //            cout << "File not detected...\n";
        //            exit(1);

        //        }
        int personCount = 0;
        Person temp;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if (!personData.atEnd())
                {
                    bool hasData = false;
                    QString data;
                    int boolean;
                    personData >> boolean;
                    if (boolean == 1)
                            hasData = true;
                    else
                           hasData = false;
                    personCount++;
                    if (hasData == true)
                    {

                        cout << "Loading Person " << personCount << endl;
                        temp.setData(hasData);

                        // read in data
                        QString garbage;
                        garbage = personData.readLine();  // moves the cursor to nextLine
                        data = personData.readLine();
                        temp.setName(data);
                        personData >> data;
                        temp.setGender(data);
                        personData >> data;
                        temp.setEyeColor(data);
                        personData >> data;
                        temp.setHairColor(data);
                        personData >> boolean;
                        if (boolean == 1)
                                temp.setFacialHair(true);
                        else
                               temp.setFacialHair(false);
                        personData >> data;
                        temp.setFacialHairType(data);
                        personData >> boolean;
                        if (boolean == 1)
                                temp.setHat(true);
                        else
                               temp.setHat(false);
                        garbage = personData.readLine();  // moves the cursor to nextLine
                        data = personData.readLine();  // moves the cursor to nextLine
                        temp.setImage(data);
                        temp.setData(true);

                        people[i][j] = temp;
                    }
                    else
                        cout << "No data for Person " << personCount << endl;

                }
            }
        }
        cout << endl;
        path.close();
    }
};
#endif // TEXTFILE_H
