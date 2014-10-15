#ifndef FACIALHAIRWINDOW_H
#define FACIALHAIRWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;
class QRadioButton;

class FacialHairWindow : public QDialog
{
    Q_OBJECT
public:
    explicit FacialHairWindow(QWidget *parent = 0);
    ~FacialHairWindow();

private slots:

private:
    QLabel *facialHairLabel;
    QDialogButtonBox *buttonBox;
    QRadioButton *question1;
    QRadioButton *question2;

};
#endif // FACIALHAIRWINDOW_H
