#ifndef HAIRWINDOW_H
#define HAIRWINDOW_H

#include <QDialog>

class QDialogButtonBox;
class QLabel;
class QRadioButton;

class HairWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HairWindow(QWidget *parent = 0);
    ~HairWindow();

private slots:
    void isAccepted();

private:
    QLabel *hairColorLabel;
    QDialogButtonBox *buttonBox;
    QRadioButton *question1;
    QRadioButton *question2;
    QRadioButton *question3;
    QRadioButton *question4;
};
#endif // HAIRWINDOW_H
