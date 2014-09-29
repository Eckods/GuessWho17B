#ifndef EYECOLORWINDOW_H
#define EYECOLORWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;

class EyeColorWindow : public QDialog
{
    Q_OBJECT
public:
    explicit EyeColorWindow(QWidget *parent = 0);
    ~EyeColorWindow();

private slots:

private:
    QLabel *label;
    QDialogButtonBox *buttonBox;
};
#endif // EYECOLORWINDOW_H
