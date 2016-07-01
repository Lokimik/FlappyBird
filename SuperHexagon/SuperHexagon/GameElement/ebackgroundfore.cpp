#include "ebackgroundfore.h"

EBackGroundFore::EBackGroundFore(QObject *parent) :
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

void EBackGroundFore::initElement()
{
    this->clearAllPolygon();
    QPolygon polygon;

//    switch(GameInfo::gameStatus)
//    {
//    case MainMenu:
//    case ModeSelect:
//    case GamePlay:
//    case GameOver:
        polygon.putPoints(0, 3,  0,0,   -884,0,     -442,-765);
        this->addPolygon(polygon);
        polygon.clear();
        polygon.putPoints(0, 3,  0,0,   442,-765,   884,0);
        this->addPolygon(polygon);
        polygon.clear();
        polygon.putPoints(0, 3,  0,0,   442,765,     -442,765);
        this->addPolygon(polygon);
        polygon.clear();
//        break;
//    }

    this->pen.setWidth(1);
    this->brush.setStyle(Qt::SolidPattern);
}

void EBackGroundFore::updateElement()
{
    if( !this->enabledUpdate )
        return;
    this->pen.setColor(GameInfo::backGroundForeColor[GameInfo::colorPointer]);
    this->brush.setColor(GameInfo::backGroundForeColor[GameInfo::colorPointer]);
}

void EBackGroundFore::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    for(int i=0;i < this->polygonListLength;i++)
        painter->drawPolygon(this->getPolygon(i),Qt::WindingFill);
}
