#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QGroupBox;
class QTextBrowser;
class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void genderButtonClicked();
    void eyeColorButtonClicked();
    void hairButtonClicked();
    void facialHairButtonClicked();
    void headwearButtonClicked();
    void aboutButtonClicked();
    void startButtonClicked();
    void howToPlayButtonClicked();
    void backToMainMenu();
    void createText();
    void characterButtonClicked();
    void guessWhoClicked();
    void isAccepted();
    void isRejected();
    void isGuessed();
    void characterGuessClicked();

private:
    void createCharGroupBox();
    void createQuestionGroupBox();
    void createMiscGroupBox();
    void createYourCharGroupBox();
    void createActions();
    void createMenu();
    void createStatusBar();
    void createGameWidget();
    void createMainMenuWidget();
    void reenableCharacterSelection();

    enum {NumGridRows = 4, NumGridCols = 6};

    QGroupBox *charGroupBox;
    QGroupBox *questionGroupBox;
    QGroupBox *miscGroupBox;
    QGroupBox *yourCharGroupBox;
    QPushButton *characters[NumGridRows][NumGridCols];
    QPushButton *yourCharacter;
    QPushButton *facialHair;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *returnAct;
    QAction *createAct;
    QMenu *gameMenu;
    QMenu *aboutMenu;
    QMenu *miscMenu;
    QTextBrowser *replyBox;
    QStackedWidget *stack;
    QWidget *mainMenuWidget;
    QWidget *gameWidget;
    QString charName;
};
#endif // MAINWINDOW_H
