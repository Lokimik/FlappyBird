#include "ecentralhexagon.h"

ECentralHexagon::ECentralHexagon(QObject *parent) :
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

void ECentralHexagon::initElement()
{
    /// init polygon ///
    this->clearAllPolygon();
    QPolygon polygon;

    polygon.putPoints(0, 6,  30,-50,  59,0,  30,50,  -30,50, -59,0, -30,-50);
    this->addPolygon(polygon);

    /// ///
    this->isAnimeFinished = false;
    if(GameInfo::gameStatus == GameOver)
    {
        this->isGameOver = true;
        this->zoomPolygon(4);
    }
    else
    {
        this->isGameOver = false;
    }

    this->pen.setWidth(6);
    this->pen.setJoinStyle(Qt::MiterJoin);
    this->brush.setStyle(Qt::SolidPattern);
}

void ECentralHexagon::updateElement()
{
    if( !this->enabledUpdate )
        return;
    this->pen.setColor(GameInfo::widgetBorderColor[GameInfo::colorPointer]);
    this->brush.setColor(GameInfo::backGroundBackColor[GameInfo::colorPointer]);
}

void ECentralHexagon::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    for(int i=0;i<this->polygonListLength;i++)
        painter->drawPolygon(this->getPolygon(i),Qt::WindingFill);
}

//void ECentralHexagon::zoomPolygon(float rate)
//{
//    if(polygonList.isEmpty())
//        return;
//    for(int i = 0; i<this->polygonList.length(); i++)
//    {
//        for(int j = 0; j< this->polygonList[i].length(); j++)
//        {
//            polygonList[0][j].operator *=(rate);
//        }
//    }
//}
