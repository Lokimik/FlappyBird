#ifndef ELEBIRD_H
#define ELEBIRD_H

#include <QTimer>
#include <qmath.h>
#include "gameelement.h"

class EleBird : public GameElement
{
    Q_OBJECT
private:
    int lastFrame;
    int currentFrame;
    float speedY;
    float increaseY;
    float speedX;
    int angle;
    QTimer timer;

    void loadFrame();

public:
    explicit EleBird(QObject *parent = 0);
    void init();
    void logic();
    void draw(QPainter *);
    void birdUp();

signals:

public slots:
    void updateFrame();
};

#endif // ELEBIRD_H
