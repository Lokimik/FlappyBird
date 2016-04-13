#ifndef ELEBACKGROUND_H
#define ELEBACKGROUND_H

#include "gameelement.h"

class EleBackground : public GameElement
{
    Q_OBJECT
private:
    int currentFrame;
    void loadFrame();
public:
    explicit EleBackground(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
};

#endif // ELEBACKGROUND_H
