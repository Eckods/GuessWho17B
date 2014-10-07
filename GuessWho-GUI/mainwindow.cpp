#include <QtGui>
#include "mainwindow.h"
#include "genderwindow.h"
#include "eyecolorwindow.h"
#include "aboutwindow.h"
#include "hairwindow.h"
#include "facialhairwindow.h"
#include "headwearwindow.h"

MainWindow::MainWindow(){
    // Calls each group layout to be created
    createCharGroupBox();
    createQuestionGroupBox();
    createYourCharGroupBox();
    createMiscGroupBox();

    // Creates a push button for the Guess who button *** NEED TO INSERT GUESS WHO TITLE IMAGE & SET STYLESHEET ***
    guessWho = new QPushButton(tr(""));
    guessWho->setFixedSize(280,200);
    guessWho->setStyleSheet("QPushButton{background-image:url(:/program/images/Guess.png); border-style: none;}"
                             "QPushButton:hover{background-image:url(:/program/images/Guess-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/program/images/Guess-Clicked.png);}");

    // Creates a temp push button just to fill up the space for the chat box that may or may not be added
    QPushButton *chatBoxFiller = new QPushButton(tr("Replace w/ chat box"));
    chatBoxFiller->setFixedSize(300,400);

    // Sets up a grid layout for the main window
    QGridLayout *mainLayout = new QGridLayout;

    // Sets up vertical spacers to go occupy rows in grid layout
    QSpacerItem *vertSpacer = new QSpacerItem(0, 40, QSizePolicy::Fixed, QSizePolicy::Fixed);
    QSpacerItem *vertSpacer2 = new QSpacerItem(0, 40, QSizePolicy::Fixed, QSizePolicy::Fixed);
    QSpacerItem *vertSpacer3 = new QSpacerItem(0, 40, QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Sets up the layout
    mainLayout->addItem(vertSpacer, 0, 0, 1, 3);
    mainLayout->addWidget(charGroupBox, 1, 0, 3, 3);
    mainLayout->addItem(vertSpacer2, 4, 0, 1, 3);
    mainLayout->addWidget(questionGroupBox, 5, 0, 2, 2);
    mainLayout->addWidget(guessWho, 5, 2, 2, 1, Qt::AlignRight);
    mainLayout->addWidget(yourCharGroupBox, 1, 3, 1, 1, Qt::AlignHCenter);
    mainLayout->addWidget(chatBoxFiller, 2, 3, 2, 1, Qt::AlignHCenter);
    mainLayout->addWidget(miscGroupBox, 5, 3, 2, 1, Qt::AlignHCenter);
    mainLayout->addItem(vertSpacer3, 7, 0, 1, 3);
    setLayout(mainLayout);

    // Sets title to window, color, and size
    setWindowTitle(tr("Guess Who"));
    setStyleSheet("QWidget{background-color:#1d2020}");
    setFixedSize(1280,1024);
}

MainWindow::~MainWindow(){}

void MainWindow::createCharGroupBox(){
    // Creates a group box to hold the Character choices and adjusts styleSheet
    charGroupBox = new QGroupBox(tr("Characters"));
    charGroupBox->setStyleSheet("QGroupBox{color:white}");
    charGroupBox->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));

    QGridLayout *layout = new QGridLayout;

    // Holds count for # of character buttons (24)
    int count = 0;

    // Creates new character buttons until the 4x6 grid is filled
    for (int i = 0; i < NumGridRows; i++) {
        for (int j = 0; j < NumGridCols; j++){
            count++;
            characters[i][j] = new QPushButton(tr("Character %0").arg(count));
            characters[i][j]->setFixedSize(150,134);
            layout->addWidget(characters[i][j], i, j);
        }
    }
    charGroupBox->setLayout(layout);
    charGroupBox->setFixedHeight(700);
}

void MainWindow::createQuestionGroupBox(){
    // Creates a group box to hold the Question choices and adjusts styleSheet
    questionGroupBox = new QGroupBox(tr("Question Selection"));
    questionGroupBox->setStyleSheet("QGroupBox{color:white}");
    questionGroupBox->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));

    QGridLayout *quesLayout = new QGridLayout;

    // Sets up each question button along with their styleSheet
    Hair = new QPushButton(tr("&Hair"));
    Hair->setFixedSize(172,48);
    Hair->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    Hair->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                        "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                        "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(Hair, SIGNAL(clicked()), this, SLOT(HairButtonClicked()));

    Gender = new QPushButton(tr("&Gender"));
    Gender->setFixedSize(172,48);
    Gender->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    Gender->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                          "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                          "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(Gender, SIGNAL(clicked()), this, SLOT(GenderButtonClicked()));

    EyeColor = new QPushButton(tr("&Eye Color"));
    EyeColor->setFixedSize(172,48);
    EyeColor->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    EyeColor->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                            "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                            "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(EyeColor, SIGNAL(clicked()), this, SLOT(EyeColorButtonClicked()));

    FacialHair = new QPushButton(tr("&Facial Hair"));
    FacialHair->setFixedSize(172,48);
    FacialHair->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    FacialHair->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                              "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                              "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(FacialHair, SIGNAL(clicked()), this, SLOT(FacialHairButtonClicked()));

    Headwear = new QPushButton(tr("&Headwear"));
    Headwear->setFixedSize(172,48);
    Headwear->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    Headwear->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                               "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                               "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(Headwear, SIGNAL(clicked()), this, SLOT(HeadwearButtonClicked()));

    // Sets up a 2x3 grid with each button occupying a space
    quesLayout->addWidget(Hair, 0, 0, 1, 1);
    quesLayout->addWidget(Gender, 0, 1, 2, 1);
    quesLayout->addWidget(EyeColor, 0, 2, 1, 1);
    quesLayout->addWidget(FacialHair, 1, 0, 1, 1);
    quesLayout->addWidget(Headwear, 1, 2, 1, 1);
    questionGroupBox->setLayout(quesLayout);
}

void MainWindow::createMiscGroupBox(){
    miscGroupBox = new QGroupBox(tr("Misc"));
    miscGroupBox->setStyleSheet("QGroupBox{color:white}");
    miscGroupBox->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));

    QVBoxLayout *miscLayout = new QVBoxLayout;

    about = new QPushButton(tr("A&bout"));
    about->setFixedSize(112,36);
    about->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));
    about->setStyleSheet("QPushButton{background-image:url(:/program/images/About.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/program/images/About-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/program/images/About-Clicked.png);}");
    connect(about, SIGNAL(clicked()), this, SLOT(AboutButtonClicked()));

    quit = new QPushButton(tr("&Quit"));
    quit->setFixedSize(112,36);
    quit->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));
    quit->setStyleSheet("QPushButton{background-image:url(:/program/images/Quit.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/program/images/Quit-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/program/images/Quit-Clicked.png);}");
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    miscLayout->addWidget(about, 0, Qt::AlignHCenter);
    miscLayout->addWidget(quit, 0, Qt::AlignHCenter);

    miscGroupBox->setLayout(miscLayout);
    miscGroupBox->setFixedWidth(160);
}

void MainWindow::createYourCharGroupBox(){
    yourCharGroupBox = new QGroupBox(tr("Your Character"));
    yourCharGroupBox->setStyleSheet("QGroupBox{color:white}");
    yourCharGroupBox->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));

    QVBoxLayout *yourCharLayout = new QVBoxLayout;
    yourCharacter = new QPushButton(tr("Your Character"));
    yourCharacter->setFixedSize(164,134);

    yourCharLayout->addWidget(yourCharacter, 0 , Qt::AlignHCenter);

    yourCharGroupBox->setLayout(yourCharLayout);
}

void MainWindow::HairButtonClicked(){
    // Creates a new window upon button click
    HairWindow hairWindow;
    hairWindow.setStyleSheet("QDialog{background-color:#1d2020}");

    // setModal set to true to prevent user from leaving window until choice is made or they exit
    hairWindow.setModal(true);
    hairWindow.exec();
}

void MainWindow::GenderButtonClicked(){
    GenderWindow genderWindow;
    genderWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    genderWindow.setModal(true);
    genderWindow.exec();
}

void MainWindow::EyeColorButtonClicked(){
    EyeColorWindow eyeColorWindow;
    eyeColorWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    eyeColorWindow.setModal(true);
    eyeColorWindow.exec();
}

void MainWindow::AboutButtonClicked(){
    AboutWindow aboutWindow;
    aboutWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    aboutWindow.setModal(true);
    aboutWindow.exec();
}

void MainWindow::FacialHairButtonClicked(){
    FacialHairWindow facialHairWindow;
    facialHairWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    facialHairWindow.setModal(true);
    facialHairWindow.exec();
}

void MainWindow::HeadwearButtonClicked(){
    HeadwearWindow HeadwearWindow;
    HeadwearWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    HeadwearWindow.setModal(true);
    HeadwearWindow.exec();
}
