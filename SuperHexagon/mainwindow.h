#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QGLWidget>

#include "gameinfo.h"
#include "GameElement/ecentralhexagon.h"
#include "GameElement/ecursor.h"

#include "GameWidget/mainmenuwidget.h"
#include "GameWidget/optionswidget.h"
#include "GameWidget/creditswidget.h"
#include "GameWidget/modeselectwidget.h"
#include "GameWidget/gameplaywidget.h"
#include "GameWidget/gameoverwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainMenuWidget *mainMenuWidget;
    OptionsWidget *optionsWidget;
    CreditsWidget *creditsWidget;
    ModeSelectWidget *modeSelectWidget;
    GamePlayWidget *gamePlayWidget;
    GameOverWidget *gameOverWidget;

    QList<QGLWidget*> widgetList;
    void hideWidget();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void mainMenu();
    void options();
    void credits();
    void modeSelect();
    void gamePlay();
    void gameOver();
    void quit();
};

#endif // MAINWINDOW_H
