#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;

class AboutWindow : public QDialog
{
public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

private:
    QLabel *label;
    QDialogButtonBox *buttonBox;
};
#endif // ABOUTWINDOW_H
