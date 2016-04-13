#include "elebackground.h"

EleBackground::EleBackground(QObject *parent) :
    GameElement(parent)
{
    this->init();
}

void EleBackground::init()
{
    this->loadFrame();
    this->currentFrame = 0;
    this->bindRect.setRect(0,0,288,512);
    this->enabledDraw = true;
}

void EleBackground::logic()
{
    if(!this->enabledLogic)
        return;
}

void EleBackground::draw(QPainter *painter)
{
    if(!this->enabledDraw)
        return;

    painter->drawPixmap(this->bindRect.x(),this->bindRect.y(),
                        this->bindRect.width(),this->bindRect.height(),
                        this->pixmapList[this->currentFrame]);
}

void EleBackground::loadFrame()
{
    this->clearAllFrame();
    if(qrand()%2)
    {
        this->addFrame(QPixmap(":/image/image/bg_day.png"));
    }
    else
    {
        this->addFrame(QPixmap(":/image/image/bg_night.png"));
    }
}

