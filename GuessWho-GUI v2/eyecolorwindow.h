#ifndef EYECOLORWINDOW_H
#define EYECOLORWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;
class QRadioButton;

class EyeColorWindow : public QDialog
{
    Q_OBJECT
public:
    explicit EyeColorWindow(QWidget *parent = 0);
    ~EyeColorWindow();

private slots:
    void isAccepted();

private:
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QRadioButton *question1;
    QRadioButton *question2;
    QRadioButton *question3;
};
#endif // EYECOLORWINDOW_H
