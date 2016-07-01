#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QGLWidget>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

#include "gameinfo.h"
#include "GameElement/ebackgroundback.h"
#include "GameElement/ebackgroundfore.h"
#include "GameElement/emenubutton.h"

class MainMenuWidget : public QGLWidget
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    EBackGroundFore *backgroundFore;
    EBackGroundBack *backgroundBack;
    EMenuButton *menuButton;

public:
    explicit MainMenuWidget(QWidget *parent = 0);
    ~MainMenuWidget();
    void initialize();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
    void START_GAME();
    void OPTIONS();
    void CREDITS();
    void QUIT();

public slots:

};

#endif // MAINMENUWIDGET_H
