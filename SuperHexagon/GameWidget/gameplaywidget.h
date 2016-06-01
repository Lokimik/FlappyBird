#ifndef GAMEPLAYWIDGET_H
#define GAMEPLAYWIDGET_H

#include <QGLWidget>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

#include "GameElement/ebackgroundback.h"
#include "GameElement/ebackgroundfore.h"
#include "GameElement/ecentralhexagon.h"
#include "GameElement/ecursor.h"
#include "GameElement/etimekeeper.h"

class GamePlayWidget : public QGLWidget
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;
    EBackGroundFore *backgroundFore;
    EBackGroundBack *backgroundBack;
    ECentralHexagon *centralHexagon;
    ECursor *cursor;
    ETimekeeper *timekeeper;

public:
    explicit GamePlayWidget(QWidget *parent = 0);
    ~GamePlayWidget();
    void initialize();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

signals:
    void KEY_ESCAPE();
    void GAMEOVER();
public slots:
};

#endif // GAMEPLAYWIDGET_H
