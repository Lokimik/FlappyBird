#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "anime.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Anime *anime;
    QPushButton *showButton;
    QPushButton *increaseCircleButton;
    QPushButton *decreaseCircleButton;
    QPushButton *increaseLineButton;
    QPushButton *decreaseLineButton;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
