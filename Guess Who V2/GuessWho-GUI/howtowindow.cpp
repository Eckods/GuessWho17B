#include "howtowindow.h"
#include <QtGui>

HowToWindow::HowToWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the text labels for the How To Play information
    howToLabel = new QLabel(tr("Brief Guide to Guess Who"));
    howToLabel->setStyleSheet("QLabel{color: white}");
    howToLabel->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));

    // Creates a new process to be called
    QProcess *process = new QProcess;

    // Holds the path to the CreateText.exe
    QString path = "./debug";
    path.append("/CreateText.exe");

    // Displays the path to exe file
    //qDebug() << path;

    // Runs the CreateText.exe
    process->start("CreateText.exe");

    // If the program fails to start, display an error message and exit the program
    if (process->waitForStarted() == false){
        qDebug() << "Error starting CreateText.exe";
        qDebug() << process->errorString();
        exit (-1);
    }

    // If the program runs, display a message saying it ran fine
    if (process->waitForStarted() == true){
        qDebug() << "Running CreateText.exe";
    }

    // Close the .exe file after it has created the Guide text file needed
    qDebug() << "Closing CreateText.exe";
    process->close();

    // Creates a variable that will hold the path to the Instructions text file generated from process
    QFile text("C:/guide.txt");

    // Checks to see if file can be opened, if not, displays error
    if(!text.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::information(0, "Error", text.errorString());

    // Creates the guide label that will appear besides the game
    QLabel *guide = new QLabel;

    // Outputs all lines in the text file
    guide->setText(text.readAll());

    //QLabel *instructions = new QLabel(tr("Press Space to start the game. Move the paddle using the <b>left</b> and <b>right arrow keys</b> on the keyboard. "
    //                                     "Upon gameover and/or entry of high score, press <b>space</b> again to reset the game or click the reset button."));
    guide->setStyleSheet("QLabel{color: white}");
    //guide->setFont(QFont("MS Shell Dlg 2", 12));
    guide->setFixedWidth(340);
    guide->setWordWrap(true);

    /*
    howToText = new QLabel(tr("Each player is given a board with 24 characters and is assigned a random character"
                              " that their opponent will have to identify. Through a series of Yes and No questions"
                              "(which are provided), you will have to narrow down the character choices available so that"
                              " you can correctly identify your opponent's character. The player to identify the "
                              " opponent's character first wins."));
    howToText->setStyleSheet("QLabel{color: white}");
    howToText->setWordWrap(true);
    howToText->setFixedWidth(340);*/

    specificsLabel = new QLabel(tr("<b>Specifics:</b>"));
    specificsLabel->setStyleSheet("QLabel{color: white}");
    specificsLabel->setFixedHeight(30);

    specificsText = new QLabel(tr("<ul><li>When a question is asked, the opponent's response will be printed in the white"
                                  " space to the right of the board.</li>"
                                  " <li>At any time you are allowed to eliminate or gray-out a character from the board that"
                                  " you do not believe your opponent has (depending on their responses to questions of course).</li>"
                                  " <li>When you are ready to guess your opponent's character simply click the Guess Who button and"
                                  " click on the character you think they have.</li></ul>"));
    specificsText->setStyleSheet("QLabel{color: white}");
    specificsText->setWordWrap(true);
    specificsText->setFixedWidth(360);

    // Creates a button box with only a Cancel button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the About window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(howToLabel, 1, Qt::AlignHCenter);
    layout->addWidget(guide, 1, Qt::AlignHCenter);
    //layout->addWidget(howToText, 2, Qt::AlignHCenter);
    layout->addWidget(specificsLabel, 1, Qt::AlignHCenter);
    layout->addWidget(specificsText, 2, Qt::AlignLeft);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("How To Play Guess Who"));
    setFixedSize(400,400);
}

HowToWindow::~HowToWindow(){}
