#ifndef HeadwearWINDOW_H
#define HeadwearWINDOW_H

#include <QDialog>

class QLabel;
class QRadioButton;
class QDialogButtonBox;

class HeadwearWindow : public QDialog
{
    Q_OBJECT
public:
    explicit HeadwearWindow(QWidget *parent = 0);
    ~HeadwearWindow();

private slots:
    void isAccepted();

private:
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QRadioButton *question1;
};
#endif // HeadwearWINDOW_H


