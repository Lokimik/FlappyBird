#include "eoverboard.h"

EOverBoard::EOverBoard(QObject *parent):
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

void EOverBoard::initElement()
{
    this->clearAllPolygon();
    QPolygon polygon;

    polygon.putPoints(0, 4,  -667,-130,  -220,-130,  -120,90,  -667,90);
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  667,-130,  150,-130,  190,-60,  667,-60);
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  667,0,  230,0,  270,70,   677,70);
    this->addPolygon(polygon);

    this->pen.setWidth(6);
    this->pen.setJoinStyle(Qt::MiterJoin);
    this->pen.setColor(Qt::black);
    this->brush.setStyle(Qt::SolidPattern);
    this->brush.setColor(Qt::black);
}

void EOverBoard::updateElement()
{
    if( !this->enabledUpdate )
        return;
//    this->pen.setColor(GameInfo::widgetBorderColor[GameInfo::colorPointer]);
//    this->brush.setColor(GameInfo::widgetColor[GameInfo::colorPointer]);
}

void EOverBoard::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    painter->setFont(this->font);
    for(int i=0;i<this->polygonListLength;i++)
        painter->drawPolygon(this->getPolygon(i),Qt::WindingFill);

//    painter->setPen(QPen(Qt::white));
//    painter->drawText(QRectF(-250,162,900,60),"PRESS SPACE TO START");
//    painter->drawText(QRectF(-290,300,900,60),"PRESS ESC RETURN TO MENU");
}

