#ifndef SKINCOLORWINDOW_H
#define SKINCOLORWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;

class SkinColorWindow : public QDialog
{
    Q_OBJECT
public:
    explicit SkinColorWindow(QWidget *parent = 0);
    ~SkinColorWindow();

private slots:

private:
    QLabel *label;
    QDialogButtonBox *buttonBox;
};
#endif // SKINCOLORWINDOW_H
