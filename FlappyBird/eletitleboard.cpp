#include "eletitleboard.h"

EleTitleBoard::EleTitleBoard(QObject *parent) :
    GameElement(parent)
{
    this->loadFrame();
    this->init();
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateFrame()));
    timer.start(150);
}

void EleTitleBoard::init()
{
    this->lastFrame = 0;
    this->currentFrame = 1;

}

void EleTitleBoard::logic()
{
    if(!this->enabledLogic)
        return;
}

void EleTitleBoard::draw(QPainter *painter)
{
    if(!this->enabledDraw)
        return;

    painter->drawPixmap(54.5,150.0,179.0,49.0,
                        this->pixmapList[3]);

    painter->drawPixmap(119.5,200.0,49.0,49.0,
                        this->pixmapList[this->currentFrame]);
}

void EleTitleBoard::updateFrame()
{
    if( !this->enabledDraw )
        return;

    if(this->currentFrame > this->lastFrame)
    {
        this->lastFrame = this->currentFrame;
        this->currentFrame++;
    }
    else if(this->currentFrame < this->lastFrame)
    {
        this->lastFrame = this->currentFrame;
        this->currentFrame--;
    }

    if(this->currentFrame<0 || this->currentFrame>2)
        this->currentFrame = 1;
}

void EleTitleBoard::loadFrame()
{
    this->clearAllFrame();
    this->addFrame(QPixmap(":/image/image/bird0_0.png"));
    this->addFrame(QPixmap(":/image/image/bird0_1.png"));
    this->addFrame(QPixmap(":/image/image/bird0_2.png"));
    this->addFrame(QPixmap(":/image/image/title.png"));
}
