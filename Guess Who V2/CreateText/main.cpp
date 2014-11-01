#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream outFile;
    string howToText = "Each player is given a board with 24 characters and is assigned a random character"
                       " that their opponent will have to identify. Through a series of Yes and No questions"
                       "(which are provided), you will have to narrow down the character choices available so that"
                       " you can correctly identify your opponent's character. The player to identify the "
                       " opponent's character first wins.";

    // Creates the output file
    outFile.open("C:\\guide.txt");

    // Validate that the files open
    if (outFile.fail()) {
        cout << "ERROR! Could not open file! Program closing..." << endl;
        exit(1);
    }

    // Writes what is stored in the instructions string to output
    outFile << howToText << endl << endl;

    cout << endl << "The guide.txt has been written"
         << endl << "Program closing..." << endl << endl;

    // Closes the file
    outFile.close();

    return 0;
}
