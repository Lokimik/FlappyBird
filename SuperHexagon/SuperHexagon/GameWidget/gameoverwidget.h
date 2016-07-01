#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include <QGLWidget>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

#include "GameElement/ebackgroundback.h"
#include "GameElement/ebackgroundfore.h"
#include "GameElement/ecentralhexagon.h"
#include "GameElement/ecursor.h"
#include "GameElement/eoverboard.h"

class GameOverWidget : public QGLWidget
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;
    EBackGroundFore *backgroundFore;
    EBackGroundBack *backgroundBack;
    ECentralHexagon *centralHexagon;
    ECursor *cursor;
    EOverBoard *overBoard;

public:
    explicit GameOverWidget(QWidget *parent = 0);
    ~GameOverWidget();

    void initialize();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
    void KEY_ESCAPE();
    void KEY_SPACE();
public slots:
};

#endif // GAMEOVERWIDGET_H
