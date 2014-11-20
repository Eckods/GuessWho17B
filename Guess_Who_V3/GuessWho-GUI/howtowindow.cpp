#include "howtowindow.h"
#include <QtGui>

HowToWindow::HowToWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the text labels for the How To Play information
    howToLabel = new QLabel(tr("Brief Guide to Guess Who"));
    howToLabel->setStyleSheet("QLabel{color: white}");
    howToLabel->setFont(QFont("MS Shell Dlg 2", 11, QFont::Bold));

    howToText = new QLabel(tr("Each player is given a board with 24 characters and is assigned a random character"
                              " that their opponent will have to identify. Through a series of Yes and No questions"
                              "(which are provided), you will have to narrow down the character choices available so that"
                              " you can correctly identify your opponent's character. The player to identify the "
                              " opponent's character first wins."));
    howToText->setStyleSheet("QLabel{color: white}");
    howToText->setWordWrap(true);
    howToText->setFixedWidth(340);

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
    layout->addWidget(howToText, 2, Qt::AlignHCenter);
    layout->addWidget(specificsLabel, 1, Qt::AlignHCenter);
    layout->addWidget(specificsText, 2, Qt::AlignLeft);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("How To Play Guess Who"));
    setFixedSize(400,400);
}

HowToWindow::~HowToWindow(){}
