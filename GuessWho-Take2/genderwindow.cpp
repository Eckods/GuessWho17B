#include "genderwindow.h"
#include <QtGui>

GenderWindow::GenderWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up 2 gender choices
    QRadioButton *question1 = new QRadioButton(tr("&Male?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    QRadioButton *question2 = new QRadioButton(tr("&Female?"));
    question2->setStyleSheet("QRadioButton{color: white}");

    // Sets up the label / question being asked
    label = new QLabel(tr("Is the character..."));
    label->setStyleSheet("QLabel{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the Gender window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 2, Qt::AlignVCenter);
    layout->addWidget(question1, 1, Qt::AlignTop);
    layout->addWidget(question2, 1, Qt::AlignTop);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("Gender Questions"));
    setFixedSize(400,200);
}

GenderWindow::~GenderWindow(){}
