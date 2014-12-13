#include "Headwearwindow.h"
#include "gamemanager.h"
#include <QtGui>
#include <iostream>
using namespace std;

HeadwearWindow::HeadwearWindow(QWidget *parent)
    : QDialog(parent){
    // Creates a label for the Headwear question
    label = new QLabel(tr("Is the character..."));
    label->setStyleSheet("QLabel{color: white}");

    // Sets up 1 question
    question1 = new QRadioButton(tr("Wearing any headwear?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(isAccepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the Headwear window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 2, Qt::AlignVCenter);
    layout->addWidget(question1, 1, Qt::AlignTop);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("Headwear Questions"));
    setFixedSize(400,200);
}

HeadwearWindow::~HeadwearWindow(){}

void HeadwearWindow::isAccepted(){
    // Example for communication with the Game Manager class
    // Replace with variables once class is created

    QString systemMessage;
    if(GameManager::instance()->playerTurn){
        if (question1->isChecked()){
            GameManager::instance()->guessHeadWear();
            close();
        }
    }
    else{
        systemMessage = "<font color='green'>Message from the boss:</font> Not your move, bro";
        GameManager::instance()->chatBox(systemMessage);
    }
}
