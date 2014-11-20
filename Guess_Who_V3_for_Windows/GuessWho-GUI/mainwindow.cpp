#include <QtGui>
#include "mainwindow.h"
#include "genderwindow.h"
#include "eyecolorwindow.h"
#include "aboutwindow.h"
#include "hairwindow.h"
#include "facialhairwindow.h"
#include "headwearwindow.h"
#include "howtowindow.h"
#include <Person.h>
#include <TextFile.h>


Person people[row][col];
TextFile text;

void getPeopleData();

MainWindow::MainWindow(){
    // Calls each group layout & widget to be created
    createCharGroupBox();
    createQuestionGroupBox();
    createYourCharGroupBox();
    createMiscGroupBox();
    createGameWidget();
    createMainMenuWidget();

    // Creates a stacked widget to shift between the main menu and game
    stack = new QStackedWidget;
    stack->addWidget(mainMenuWidget);
    stack->addWidget(gameWidget);
    setCentralWidget(stack);

    // Creates the menu and status bar for the main window
    createActions();
    createMenu();
    createStatusBar();

    // Sets title to window, color, and size
    setWindowTitle(tr("Guess Who"));
    setStyleSheet("QMainWindow{background-color:#1d2020}");
    setFixedSize(1280,1000);
    showFullScreen();
}

MainWindow::~MainWindow(){}

void MainWindow::createMainMenuWidget(){
    // Sets up each menu button along with their styleSheet
    QPushButton *start = new QPushButton(tr("Start"));
    start->setFixedSize(172,48);
    start->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    start->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                        "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                        "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(start, SIGNAL(clicked()), this, SLOT(startButtonClicked()));

    QPushButton *howToPlay = new QPushButton(tr("How to Play"));
    howToPlay->setFixedSize(172,48);
    howToPlay->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    howToPlay->setStyleSheet("QPushButton{background-image:url(:/program/images/About.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                        "QPushButton:hover{background-image:url(:/program/images/About-Hover.png);}"
                        "QPushButton:pressed{background-image:url(:/program/images/About-Clicked.png);}"
                         "QPushButton:disabled{background-image:url(:/program/images/Quit.png);};");
    connect(howToPlay, SIGNAL(clicked()), this, SLOT(howToPlayButtonClicked()));

    QPushButton *about = new QPushButton(tr("About Guess Who"));
    about->setFixedSize(172,48);
    about->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    about->setStyleSheet("QPushButton{background-image:url(:/program/images/About.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                        "QPushButton:hover{background-image:url(:/program/images/About-Hover.png);}"
                        "QPushButton:pressed{background-image:url(:/program/images/About-Clicked.png);}");
    connect(about, SIGNAL(clicked()), this, SLOT(aboutButtonClicked()));

    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFixedSize(172,48);
    quit->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    quit->setStyleSheet("QPushButton{background-image:url(:/program/images/Quit.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                        "QPushButton:hover{background-image:url(:/program/images/Quit-Hover.png);}"
                        "QPushButton:pressed{background-image:url(:/program/images/Quit-Clicked.png);}");
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Creates the layout for the buttons
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addSpacing(20);
    buttonLayout->addWidget(start, 0, Qt::AlignHCenter);
    buttonLayout->addSpacing(15);
    buttonLayout->addWidget(howToPlay, 0, Qt::AlignHCenter);
    buttonLayout->addSpacing(15);
    buttonLayout->addWidget(about, 0, Qt::AlignHCenter);
    buttonLayout->addSpacing(15);
    buttonLayout->addWidget(quit, 0, Qt::AlignHCenter);
    buttonLayout->addSpacing(20);

    QGroupBox *choiceGroupBox = new QGroupBox(tr(""));
    choiceGroupBox->setStyleSheet("QGroupBox{color:white}");
    choiceGroupBox->setLayout(buttonLayout);
    choiceGroupBox->setFixedSize(260, 400);

    // Creates 2 labels that will hold images for the menu screen
    QLabel *leftLabel = new QLabel(tr(""));
    QPixmap leftImage(":/program/images/Left.png");
    leftLabel->setPixmap(leftImage);
    leftLabel->setFixedSize(480,570);

    QLabel *rightLabel = new QLabel(tr(""));
    QPixmap rightImage(":/program/images/Right.png");
    rightLabel->setPixmap(rightImage);
    rightLabel->setFixedSize(480,570);

    // Creates the bottom layout for the page
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(leftLabel, 0, Qt::AlignHCenter);
    bottomLayout->addWidget(choiceGroupBox);
    bottomLayout->addWidget(rightLabel, 0, Qt::AlignHCenter);

    // Creates the main layout for the page
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPixmap titleImage(":/program/images/Title.png");
    QLabel *titleName = new QLabel(tr(""));
    titleName->setPixmap(titleImage);
    titleName->setFixedSize(980,300);

    mainLayout->addSpacing(100);
    mainLayout->addWidget(titleName, 0, Qt::AlignHCenter);
    mainLayout->addLayout(bottomLayout);

    mainMenuWidget = new QWidget;
    mainMenuWidget->setLayout(mainLayout);
}

void MainWindow::startButtonClicked(){
    // Changes to the game menu page
    int nextPage = stack->currentIndex() + 1;
    if (nextPage >= stack->count())
        nextPage = 0;
    stack->setCurrentIndex(nextPage);
}

void MainWindow::createGameWidget(){
    // Creates a push button for the Guess who button *** NEED TO INSERT GUESS WHO TITLE IMAGE & SET STYLESHEET ***
    QPushButton *guessWho = new QPushButton(tr(""));
    guessWho->setFixedSize(280,200);
    guessWho->setStyleSheet("QPushButton{background-image:url(:/program/images/Guess.png); border-style: none;}"
                             "QPushButton:hover{background-image:url(:/program/images/Guess-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/program/images/Guess-Clicked.png);}");

    // Creates a textBrowser that loads in the opponent's replies
    replyBox = new QTextBrowser;
    replyBox->setFixedSize(300,400);

    // Sets up a grid layout for the main window
    QGridLayout *mainLayout = new QGridLayout;

    // Sets up vertical spacers to go occupy rows in grid layout
    QSpacerItem *vertSpacer = new QSpacerItem(0, 15, QSizePolicy::Fixed, QSizePolicy::Fixed);
    QSpacerItem *vertSpacer2 = new QSpacerItem(0, 40, QSizePolicy::Fixed, QSizePolicy::Fixed);
    QSpacerItem *vertSpacer3 = new QSpacerItem(0, 30, QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Sets up the layout
    mainLayout->addItem(vertSpacer, 0, 0, 1, 3);
    mainLayout->addWidget(charGroupBox, 1, 0, 3, 3);
    mainLayout->addItem(vertSpacer2, 4, 0, 1, 3);
    mainLayout->addWidget(questionGroupBox, 5, 0, 2, 2);
    mainLayout->addWidget(guessWho, 5, 2, 2, 1, Qt::AlignRight);
    mainLayout->addWidget(yourCharGroupBox, 1, 3, 1, 1, Qt::AlignHCenter);
    mainLayout->addWidget(replyBox, 2, 3, 2, 1, Qt::AlignHCenter);
    mainLayout->addWidget(miscGroupBox, 5, 3, 2, 1, Qt::AlignHCenter);
    mainLayout->addItem(vertSpacer3, 7, 0, 1, 3);

    gameWidget = new QWidget;
    gameWidget->setLayout(mainLayout);
}

void MainWindow::createCharGroupBox(){
    // Creates a group box to hold the Character choices and adjusts styleSheet
    charGroupBox = new QGroupBox(tr("Characters"));
    charGroupBox->setStyleSheet("QGroupBox{color:white}");
    charGroupBox->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));

    QGridLayout *layout = new QGridLayout;

    // Holds count for # of character buttons (24)
//    int count = 0;

    getPeopleData(); // populate people

//     character array with image loaded from linked list
    for (int i = 0; i < NumGridRows; i++){
         for (int j = 0; j < NumGridCols; j++){
             characters[i][j] = new QPushButton(tr(""));
             characters[i][j]->setFixedSize(150,134);
             characters[i][j]->setStyleSheet("QPushButton{"+people[i][j].getImage()+";");
             characters[i][j]->setToolTip(""+people[i][j].getName()+"");
             connect(characters[i][j], SIGNAL(clicked()), this, SLOT(characterButtonClicked()));
             layout->addWidget(characters[i][j], i, j);
//         increment through linked list
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
    QPushButton *hair = new QPushButton(tr("&Hair"));
    hair->setFixedSize(172,48);
    hair->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    hair->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                        "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                        "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    hair->setToolTip("Yo");
    connect(hair, SIGNAL(clicked()), this, SLOT(hairButtonClicked()));

    QPushButton *gender = new QPushButton(tr("&Gender"));
    gender->setFixedSize(172,48);
    gender->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    gender->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                          "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                          "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(gender, SIGNAL(clicked()), this, SLOT(genderButtonClicked()));

    QPushButton *eyeColor = new QPushButton(tr("&Eye Color"));
    eyeColor->setFixedSize(172,48);
    eyeColor->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    eyeColor->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                            "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                            "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(eyeColor, SIGNAL(clicked()), this, SLOT(eyeColorButtonClicked()));

    QPushButton *facialHair = new QPushButton(tr("&Facial Hair"));
    facialHair->setFixedSize(172,48);
    facialHair->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    facialHair->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                              "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                              "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(facialHair, SIGNAL(clicked()), this, SLOT(facialHairButtonClicked()));

    QPushButton *headwear = new QPushButton(tr("&Headwear"));
    headwear->setFixedSize(172,48);
    headwear->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));
    headwear->setStyleSheet("QPushButton{background-image:url(:/program/images/Default.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                               "QPushButton:hover{background-image:url(:/program/images/Hover.png);}"
                               "QPushButton:pressed{background-image:url(:/program/images/Clicked.png);}");
    connect(headwear, SIGNAL(clicked()), this, SLOT(headwearButtonClicked()));

    // Sets up a 2x3 grid with each button occupying a space
    quesLayout->addWidget(hair, 0, 0, 1, 1);
    quesLayout->addWidget(gender, 0, 1, 2, 1);
    quesLayout->addWidget(eyeColor, 0, 2, 1, 1);
    quesLayout->addWidget(facialHair, 1, 0, 1, 1);
    quesLayout->addWidget(headwear, 1, 2, 1, 1);
    questionGroupBox->setLayout(quesLayout);
}

void MainWindow::createMiscGroupBox(){
    miscGroupBox = new QGroupBox(tr("Misc"));
    miscGroupBox->setStyleSheet("QGroupBox{color:white}");
    miscGroupBox->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));

    QVBoxLayout *miscLayout = new QVBoxLayout;

    QPushButton *about = new QPushButton(tr("A&bout"));
    about->setFixedSize(112,36);
    about->setFont(QFont("MS Shell Dlg 2", 9, QFont::Bold));
    about->setStyleSheet("QPushButton{background-image:url(:/program/images/About.png); color: white; border-width: 3px; border-color: #181D1F; border-style: outset; border-radius: 7;}"
                             "QPushButton:hover{background-image:url(:/program/images/About-Hover.png);}"
                             "QPushButton:pressed{background-image:url(:/program/images/About-Clicked.png);}");
    connect(about, SIGNAL(clicked()), this, SLOT(aboutButtonClicked()));

    QPushButton *quit = new QPushButton(tr("&Quit"));
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
    yourCharacter->setFixedSize(150,134);
    // Testing out the character image
    /*yourCharacter->setStyleSheet("QPushButton{background-image:url(:/program/Sheet/Characters1.png); border-width: 1px; border-color: #181D1F; border-style: outset; border-radius: 5;}"
                                 "QPushButton:hover{background-image:url(:/program/Sheet/Characters1-Hover.png);}"
                                 "QPushButton:pressed{background-image:url(:/program/Sheet/Characters1-Disabled.png);}"
                                 "QPushButton:disabled{background-image:url(:/program/Sheet/Characters1-Disabled.png);}");*/

    yourCharLayout->addWidget(yourCharacter, 0 , Qt::AlignHCenter);

    yourCharGroupBox->setLayout(yourCharLayout);
}

void MainWindow::hairButtonClicked(){
    // Creates a new window upon button click
    HairWindow hairWindow;
    hairWindow.setStyleSheet("QDialog{background-color:#1d2020}");

    // setModal set to true to prevent user from leaving window until choice is made or they exit
    hairWindow.setModal(true);
    hairWindow.exec();
}

void MainWindow::genderButtonClicked(){
    GenderWindow genderWindow;
    genderWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    genderWindow.setModal(true);
    genderWindow.exec();
}

void MainWindow::eyeColorButtonClicked(){
    EyeColorWindow eyeColorWindow;
    eyeColorWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    eyeColorWindow.setModal(true);
    eyeColorWindow.exec();
}

void MainWindow::aboutButtonClicked(){
    AboutWindow aboutWindow;
    aboutWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    aboutWindow.setModal(true);
    aboutWindow.exec();
}

void MainWindow::facialHairButtonClicked(){
    FacialHairWindow facialHairWindow;
    facialHairWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    facialHairWindow.setModal(true);
    facialHairWindow.exec();
}

void MainWindow::headwearButtonClicked(){
    HeadwearWindow HeadwearWindow;
    HeadwearWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    HeadwearWindow.setModal(true);
    HeadwearWindow.exec();
}

void MainWindow::howToPlayButtonClicked(){
    HowToWindow howToPlayWindow;
    howToPlayWindow.setStyleSheet("QDialog{background-color:#1d2020}");
    howToPlayWindow.setModal(true);
    howToPlayWindow.exec();
}

void MainWindow::createMenu(){
    //menuBar()->setStyleSheet("QMenuBar{color:white}");
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(returnAct);
    gameMenu->addSeparator();
    gameMenu->addAction(exitAct);

    aboutMenu = menuBar()->addMenu(tr("A&bout"));
    aboutMenu->addAction(aboutAct);

    miscMenu= menuBar()->addMenu(tr("&Misc Menu"));
    miscMenu->addAction(createAct);
}

void MainWindow::createActions(){
    // Allows the user to return to menu
    returnAct = new QAction(tr("&Back to Main Menu"), this);
    returnAct->setShortcut(tr("Ctrl+Z"));
    returnAct->setStatusTip(tr("Return to main menu"));
    connect(returnAct, SIGNAL(triggered()), this, SLOT(backToMainMenu()));

    // Allows the user to exit the app through the menu bar
    exitAct = new QAction(tr("&Exit Guess Who"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    // Allows the user to see the About info about the application
    aboutAct = new QAction(tr("About Guess &Who"), this);
    aboutAct->setStatusTip(tr("Shows info about game"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutButtonClicked()));

    createAct = new QAction(tr("Create new character text file"), this);
    createAct->setStatusTip(tr("Create text file for characters"));
    connect(createAct, SIGNAL(triggered()), this, SLOT(createText()));
}

void MainWindow::createStatusBar(){
    statusBar()->showMessage(tr("Ready"));
    statusBar()->setStyleSheet("QStatusBar{color: white}");
}

void MainWindow::backToMainMenu(){
    int prevPage = stack->currentIndex() + 1;

    // Displays a message box asking user if they want to return to Main menu if on Game page
    if (prevPage >= stack->count()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Return",
                             "Are you sure you want to return to main menu?",
                             QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes){
            prevPage = 0;
            stack->setCurrentIndex(prevPage);
        }
    }
    // Leaves the user on Main menu if they are currently on it
    else
        prevPage = 0;
        stack->setCurrentIndex(prevPage);
}

//void MainWindow::characterButtonClicked()
//{
//    person->getName();
//}

void getPeopleData(){
    text.getDataFromFile(people);
}

void MainWindow::createText(){
    // Creates a new process to be called
    QProcess *process = new QProcess;

    #ifdef Q_WS_WIN
    // Runs the CreateText.exe
    process->startDetached("CreateText");

    // If the program runs, display a message saying it ran fine
    if (process->waitForStarted() == true){
        qDebug() << "\nRunning CreateText";
    }
    #endif

    #ifdef Q_WS_MACX
    // Holds the path to the CreateText.exe
    QString path = "open \"/Users/Teramino/Desktop/Qt/build-CreateText-Desktop_Qt_4_8_5-Debug/CreateText.app/Contents/MacOS/CreateText\"";

    // Runs the CreateText.exe
    process->start(path);

    // If the program fails to start, display an error message and exit the program
    if (process->waitForStarted() == false){
        qDebug() << "\nError starting CreateText";
        qDebug() << process->errorString();
        exit (-1);
    }

    // If the program runs, display a message saying it ran fine
    if (process->waitForStarted() == true){
        qDebug() << "\nRunning CreateText";
    }
    #endif
}
