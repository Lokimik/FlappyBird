#include "etimekeeper.h"

ETimekeeper::ETimekeeper(QObject *parent):
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

void ETimekeeper::initElement()
{
    this->milliSecond = 0;
    this->second = 0;
    this->isTenSecReset = false;
    this->isHundredSecReset = false;
    this->adjust = 0;

    this->clearAllPolygon();
    QPolygon polygon;

    polygon.putPoints(0, 4,  -667,-375,  -270,-375,  -320,-325,  -667,-325);
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  800,-375,  320,-375,  350,-325,   800,-325);
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  800,-375,  480,-375,  530,-275,   800,-275);
    this->addPolygon(polygon);

    this->pen.setWidth(6);
    this->pen.setJoinStyle(Qt::MiterJoin);
    this->pen.setColor(Qt::black);
    this->brush.setStyle(Qt::SolidPattern);
    this->brush.setColor(Qt::black);
}

void ETimekeeper::updateElement()
{
    if( !this->enabledUpdate )
        return;
    /* Timer */
    if(this->milliSecond > 983)
    {
        this->second++;
        this->milliSecond -= 984;
    }
    else
        this->milliSecond += 16;

    if(this->second > 9 && !this->isTenSecReset)
    {
        this->getPolygon(1).translate(QPoint(-60,0));
        this->getPolygon(2).translate(QPoint(-60,0));
        this->isTenSecReset = true;
        this->adjust += 55;
    }
    if(this->second > 99 && !this->isHundredSecReset)
    {
        this->getPolygon(1).translate(QPoint(-60,0));
        this->getPolygon(2).translate(QPoint(-60,0));
        this->isHundredSecReset = true;
        this->adjust += 55;
    }
}

void ETimekeeper::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    /*polygon*/
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    for(int i=0;i<this->polygonListLength;i++)
        painter->drawPolygon(this->getPolygon(i),Qt::WindingFill);

    /*Timer*/
    painter->setPen(QPen(Qt::white));
    this->font.setPixelSize(25);
    painter->setFont(this->font);
    painter->drawText(QRect(-630,-365,400,50),"BEST: 157:50");//
    painter->drawText(QRect(350-this->adjust,-365,110,50),"TIME");
    painter->drawText(QRect(590,-330,80,80),QString(":%1").arg(this->milliSecond/10));//

    this->font.setPixelSize(50);
    painter->setFont(this->font);
    painter->drawText(QRect(535-this->adjust,-355,170,60),QString("%1").arg(this->second));//
}
