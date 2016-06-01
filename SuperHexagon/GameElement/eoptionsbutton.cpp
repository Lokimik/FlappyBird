#include "eoptionsbutton.h"

EOptionsButton::EOptionsButton(QObject *parent):
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

void EOptionsButton::initElement()
{
    this->optionPointer = 0;

    this->clearAllPolygon();
    QPolygon polygon;

    polygon.putPoints(0, 4,  -300,0,  300,0,  300,50,  -300,50);
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  -300,80,  300,80,  300,130,   -300,130);
    this->addPolygon(polygon);

    this->pen.setWidth(6);
    this->pen.setJoinStyle(Qt::MiterJoin);
    this->brush.setStyle(Qt::SolidPattern);
}

void EOptionsButton::updateElement()
{
    if( !this->enabledUpdate )
        return;
    this->pen.setColor(GameInfo::widgetBorderColor[GameInfo::colorPointer]);
    this->brush.setColor(GameInfo::widgetColor[GameInfo::colorPointer]);
}

void EOptionsButton::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    /*option rectangle*/
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    painter->drawPolygon(this->getPolygon(this->optionPointer),Qt::WindingFill);

    /*title*/
    this->font.setPixelSize(100);
    painter->setFont(this->font);
    painter->setPen(QPen(Qt::white));
    painter->drawText(QRect(-390,-250,900,300),"OPTIONS");

    this->font.setPixelSize(25);
    painter->setFont(this->font);
    /*option 1 : sound*/
    if(GameInfo::sound)
        painter->drawText(QRectF(-150,10,900,60),"EABLE SOUND");
    else
        painter->drawText(QRectF(-170,10,900,60),"DISABLE SOUND");
    /*option 2 : delete records*/
    painter->drawText(QRectF(-185,90,900,60),"DELETE RECORDS");

    //
    painter->drawText(QRectF(-265,300,900,60),"PRESS SPACE TO SELECT");
}

void EOptionsButton::optionUp()
{
    if(this->optionPointer>0)
        this->optionPointer -= 1;
    else
        this->optionPointer = 2 -1;
}

void EOptionsButton::optionDown()
{
    if(this->optionPointer<2 -1)
        this->optionPointer += 1;
    else
        this->optionPointer = 0;
}

void EOptionsButton::optionSelect()
{
    switch(this->optionPointer)
    {
    case 0:
        GameInfo::sound = !GameInfo::sound;
        break;
    case 1:
        //
        break;
    }
}
