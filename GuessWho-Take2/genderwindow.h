#ifndef GENDERWINDOW_H
#define GENDERWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;

class GenderWindow : public QDialog
{
    Q_OBJECT
public:
    explicit GenderWindow(QWidget *parent = 0);
    ~GenderWindow();

private slots:

private:
    QLabel *label;
    QDialogButtonBox *buttonBox;
};
#endif // GENDERWINDOW_H
