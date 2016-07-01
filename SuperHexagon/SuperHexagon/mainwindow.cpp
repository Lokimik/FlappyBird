#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    GameInfo::mainTimer.start(16);
    GameInfo::InitColor();
    this->resize(GameInfo::windowSize);

    this->mainMenuWidget = new MainMenuWidget(this);
    this->optionsWidget = new OptionsWidget(this);
    this->creditsWidget = new CreditsWidget(this);
    this->modeSelectWidget = new ModeSelectWidget(this);
    this->gamePlayWidget = new GamePlayWidget(this);
    this->gameOverWidget = new GameOverWidget(this);

    this->widgetList.append(this->mainMenuWidget);
    this->widgetList.append(this->optionsWidget);
    this->widgetList.append(this->creditsWidget);
    this->widgetList.append(this->modeSelectWidget);
    this->widgetList.append(this->gamePlayWidget);
    this->widgetList.append(this->gameOverWidget);
    this->hideWidget();
    this->mainMenu();
}

MainWindow::~MainWindow()
{
    delete this->mainMenuWidget;
    delete this->optionsWidget;
    delete this->creditsWidget;
    delete this->modeSelectWidget;
    delete this->gamePlayWidget;
    delete this->gameOverWidget;
}

void MainWindow::hideWidget()
{
    for(int i=0;i<this->widgetList.length();i++)
    {
        if( !this->widgetList[i]->isHidden())
            this->widgetList[i]->hide();
    }
}

void MainWindow::mainMenu()
{
    this->hideWidget();
    this->mainMenuWidget->initialize();
}

void MainWindow::options()
{
    this->hideWidget();
    this->optionsWidget->initialize();
}

void MainWindow::credits()
{
    this->hideWidget();
    this->creditsWidget->initialize();
}

void MainWindow::modeSelect()
{
    this->hideWidget();
    this->modeSelectWidget->initialize();
}

void MainWindow::gamePlay()
{
    this->hideWidget();
    this->gamePlayWidget->initialize();
}

void MainWindow::gameOver()
{
    this->hideWidget();
    this->gameOverWidget->initialize();
}

void MainWindow::quit()
{
    this->close();
}

