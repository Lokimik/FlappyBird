#include "emenubutton.h"

EMenuButton::EMenuButton(QObject *parent):
    GameElement(parent)
{
    this->optionList.clear();
    this->optionList.append("  START GAME");
    this->optionList.append("    OPTIONS");
    this->optionList.append("     CREDITS");
    this->optionList.append("       QUIT");
    this->optionPointer = 0;

    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

void EMenuButton::initElement()
{
    this->clearAllPolygon();
    QPolygon polygon;

    polygon.putPoints(0, 4,  -300,150,  300,150,    270,210,  -270,210);//central button
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  -600,140,   -450,140,     -400,240,     -550,240);//Left Button
    this->addPolygon(polygon);

    polygon.clear();
    polygon.putPoints(0, 4,  600,140,   450,140,     400,240,     550,240);//Right Button
    this->addPolygon(polygon);

    this->pen.setWidth(6);
    this->pen.setJoinStyle(Qt::MiterJoin);
    this->brush.setStyle(Qt::SolidPattern);

    this->leftArrow = new QPixmap(":/other/resource/LeftArrow.png");
    this->RightArrow = new QPixmap(":/other/resource/RightArrow.png");
}

void EMenuButton::updateElement()
{
    if( !this->enabledUpdate )
        return;
    this->pen.setColor(GameInfo::widgetBorderColor[GameInfo::colorPointer]);
    this->brush.setColor(GameInfo::widgetColor[GameInfo::colorPointer]);
}

void EMenuButton::drawElement(QPainter *painter)
{
    if( !this->enabledDraw )
        return;
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    painter->setFont(this->font);
    for(int i=0;i<this->polygonListLength;i++)
        painter->drawPolygon(this->getPolygon(i),Qt::WindingFill);

    painter->drawPixmap(-580,160,150,60,*this->leftArrow);
    painter->drawPixmap(430,160,150,60,*this->RightArrow);

    painter->setPen(QPen(Qt::white));
    this->font.setPixelSize(100);
    painter->setFont(this->font);
    painter->drawText(QRect(-400,-250,900,300),"SUPER \n HEXAGON");

    this->font.setPixelSize(25);
    painter->setFont(this->font);
    painter->drawText(QRectF(-150,162,900,60),this->optionList[this->optionPointer]);//-250,70,  250,70,    220,130,  -220,130
    painter->drawText(QRectF(-265,300,900,60),"PRESS SPACE TO SELECT");
}

void EMenuButton::optionLeft()
{
    if(this->optionPointer>0)
        this->optionPointer -= 1;
    else
        this->optionPointer = this->optionList.length()-1;
}

void EMenuButton::optionRight()
{
    if(this->optionPointer<this->optionList.length()-1)
        this->optionPointer += 1;
    else
        this->optionPointer = 0;
}

int EMenuButton::getOption()
{
    return this->optionPointer;
}
