#include "skincolorwindow.h"
#include <QtGui>

SkinColorWindow::SkinColorWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up 3 questions about the skin color
    QRadioButton *question1 = new QRadioButton(tr("&Light-Skinned?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    QRadioButton *question2 = new QRadioButton(tr("&Middle-tone?"));
    question2->setStyleSheet("QRadioButton{color: white}");

    QRadioButton *question3 = new QRadioButton(tr("&Dark-Skinned?"));
    question3->setStyleSheet("QRadioButton{color: white}");

    // Sets up the label / question being asked
    label = new QLabel(tr("Is the character..."));
    label->setStyleSheet("QLabel{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the Skin Color window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 2, Qt::AlignVCenter);
    layout->addWidget(question1, 1, Qt::AlignTop);
    layout->addWidget(question2, 1, Qt::AlignTop);
    layout->addWidget(question3, 1, Qt::AlignTop);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("Skin Color Questions"));
    setFixedSize(400,200);
}

SkinColorWindow::~SkinColorWindow(){}
