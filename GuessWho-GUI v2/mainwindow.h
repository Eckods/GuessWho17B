#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QGroupBox;
class QTextBrowser;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void GenderButtonClicked();
    void EyeColorButtonClicked();
    void HairButtonClicked();
    void FacialHairButtonClicked();
    void HeadwearButtonClicked();
    void AboutButtonClicked();

private:
    void createCharGroupBox();
    void createQuestionGroupBox();
    void createMiscGroupBox();
    void createYourCharGroupBox();
    void createActions();
    void createMenu();
    void createStatusBar();

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
    QPushButton *Headwear;
    QAction *exitAct;
    QAction *aboutAct;
    QMenu *gameMenu;
    QMenu *aboutMenu;
    QTextBrowser *replyBox;
};
#endif // MAINWINDOW_H
