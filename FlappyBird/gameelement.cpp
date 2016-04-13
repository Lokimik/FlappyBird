#include "gameelement.h"

GameElement::GameElement(QObject *parent) :
    QObject(parent)
{
    this->clearAllFrame();
    this->bindRect.setRect(0,0,0,0);
    this->enabledLogic = false;
    this->enabledDraw = false;
}

void GameElement::addFrame(QPixmap pixmap)
{
    if(pixmap.isNull())
        return;
    this->pixmapList.append(pixmap);
    this->frameCount++;
}

void GameElement::clearAllFrame()
{
    this->pixmapList.clear();
    this->frameCount = 0;
}

QRectF& GameElement::getBindRect()
{
    return this->bindRect;
}
