#ifndef ELEPIPE_H
#define ELEPIPE_H

#include "gameelement.h"

enum PipeType{above=0,
              following=1};

class ElePipe : public GameElement
{
    Q_OBJECT
private:
    int currentFrame;
    int speedX;
    int startPosition;
    QRectF pipeRect[2];
    bool pipePassEmited;

    void loadFrame();
public:
    explicit ElePipe(int pos,QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();

    QRectF &getRect(PipeType);
signals:
    void pipePass();

};

#endif // ELEPIPE_H
