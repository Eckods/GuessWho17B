#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QPushButton;
class QGroupBox;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void SkinColorButtonClicked();
    void GenderButtonClicked();
    void EyeColorButtonClicked();
    //void HairButtonClicked();
    //void FacialHairButtonClicked();
    //void AccessoriesButtonClicked();
    void AboutButtonClicked();

private:
    void createCharGroupBox();
    void createQuestionGroupBox();
    void createMiscGroupBox();
    void createYourCharGroupBox();

    enum {NumGridRows = 4, NumGridCols = 6};

    QGroupBox *charGroupBox;
    QGroupBox *questionGroupBox;
    QGroupBox *miscGroupBox;
    QGroupBox *yourCharGroupBox;
    QPushButton *characters[NumGridRows][NumGridCols];
    QPushButton *yourCharacter;
    QPushButton *quit;
    QPushButton *about;
    QPushButton *guessWho;
    QPushButton *SkinColor;
    QPushButton *Gender;
    QPushButton *EyeColor;
    QPushButton *Hair;
    QPushButton *FacialHair;
    QPushButton *Accessories;
};
#endif // MAINWINDOW_H
