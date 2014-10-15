#include "aboutwindow.h"
#include <QtGui>

AboutWindow::AboutWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the label for the About information
    label = new QLabel(tr("This program was a collaborative project developed by Victoria Hodnett, Khallid Coulter, Joel Bateman, Kory Brown, and Steve Sanchez."));
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

    setWindowTitle(tr("About Guess Who"));
    setFixedSize(400,200);
}

AboutWindow::~AboutWindow(){}
