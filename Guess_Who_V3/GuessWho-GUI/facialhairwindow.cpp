#include "facialhairwindow.h"
#include <QtGui>
#include <iostream>
using namespace std;

FacialHairWindow::FacialHairWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the label for Facial hair questions
    facialHairLabel = new QLabel(tr("Does the character have..."));
    facialHairLabel->setStyleSheet("QLabel{color: white}");

    // Sets up 2 Facial Hair questions
    question1 = new QRadioButton(tr("a mustache?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    question2 = new QRadioButton(tr("a beard?"));
    question2->setStyleSheet("QRadioButton{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(isAccepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the Facial Hair window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(facialHairLabel, 2, Qt::AlignVCenter);
    layout->addWidget(question1, 1, Qt::AlignTop);
    layout->addWidget(question2, 1, Qt::AlignTop);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("Facial Hair Questions"));
    setFixedSize(400, 200);
}

FacialHairWindow::~FacialHairWindow(){}

void FacialHairWindow::isAccepted(){
    // Example for communication with the Game Manager class
    // Replace with variables once class is created
    if (question1->isChecked()){
        cout << "Mustache" << endl;
        close();
    }
    else if (question2->isChecked()){
        cout << "Beard" << endl;
        close();
    }
    else
        close();
}
