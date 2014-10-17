#include "howtowindow.h"
#include <QtGui>

HowToWindow::HowToWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the label for the How To Play information
    label = new QLabel(tr("Filler information for now."));
    label->setStyleSheet("QLabel{color: white}");
    label->setWordWrap(true);

    // Creates a button box with only a Cancel button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the About window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 2, Qt::AlignVCenter);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("How To Play Guess Who"));
    setFixedSize(400,300);
}

HowToWindow::~HowToWindow(){}
