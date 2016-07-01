#include "emodeinfo.h"

EModeInfo::EModeInfo(QObject *parent):
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}


void EModeInfo::initElement()
{
    this->clearAllPolygon();
    QPolygon polygon;

    polygon.putPoints(0, 4,  -667,-280,  667,-280,    667,-100,  -667,-100);//central button
    this->addPolygon(polygon);

    this->pen.setWidth(1);
    this->pen.setJoinStyle(Qt::MiterJoin);
    this->brush.setStyle(Qt::SolidPattern);

    this->modeList.clear();
    this->modeList.append("HEXAGON");
    this->modeList.append("HEXAGONER");
    this->modeList.append("HEXAGONEST");
    this->modeList.append("HEXAGON_HYPER");
    this->modeList.append("HEXAGONER_HYPER");
    this->modeList.append("HEXAGONEST_HYPER");

    this->difficultyList.clear();
    this->difficultyList.append("HARD");
    this->difficultyList.append("HARDER");
    this->difficultyList.append("HARDEST");
    this->difficultyList.append("HARDESTER");
    this->difficultyList.append("HARDESTEST");
    this->difficultyList.append("HARDESTESTEST");

}

void EModeInfo::updateElement()
{
    if( !this->enabledUpdate )
        return;
}

void EModeInfo::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    painter->setPen(QPen(QColor(Qt::black)));
    painter->setBrush(QBrush(QColor(Qt::black)));
    for(int i=0;i<this->polygonListLength;i++)
        painter->drawPolygon(this->getPolygon(i),Qt::WindingFill);

    this->font.setPixelSize(23);
    painter->setFont(this->font);
    painter->setPen(QPen(QColor(Qt::gray)));
    painter->drawText(QRectF(-350,-190,260,50),"DIFFICULTY:");
    painter->drawText(QRectF(-350,-150,250,50),"BEST TIME:");
    painter->setPen(QPen(QColor(Qt::white)));
    painter->drawText(QRectF(-60,-190,330,50),this->difficultyList[GameInfo::gameMode]);
    //****  BEST TIME

    this->font.setPixelSize(45);
    painter->setFont(this->font);
    painter->setPen(QPen(GameInfo::widgetBorderColor[GameInfo::colorPointer]));
    painter->drawText(QRectF(-400,-260,800,100),this->modeList[GameInfo::gameMode]);
}

