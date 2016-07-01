#include "emodebutton.h"

EModeButton::EModeButton(QObject *parent):
    GameElement(parent)
{
    this->initElement();
    this->enabledUpdate = true;
    this->enabledDraw = true;
}

EModeButton::~EModeButton()
{
    delete this->leftArrow;
    delete this->RightArrow;
}

void EModeButton::initElement()
{
    GameInfo::setGameMode(Hexgon);

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
    this->font.setPixelSize(25);

    this->leftArrow = new QPixmap(":/other/resource/LeftArrow.png");
    this->RightArrow = new QPixmap(":/other/resource/RightArrow.png");
}

void EModeButton::updateElement()
{
    if( !this->enabledUpdate )
        return;
    this->pen.setColor(GameInfo::widgetBorderColor[GameInfo::colorPointer]);
    this->brush.setColor(GameInfo::widgetColor[GameInfo::colorPointer]);
}

void EModeButton::drawElement(QPainter *painter)
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
    painter->drawText(QRectF(-250,162,900,60),"PRESS SPACE TO START");
    painter->drawText(QRectF(-290,300,900,60),"PRESS ESC RETURN TO MENU");
}

void EModeButton::optionLeft()
{
    if(GameInfo::gameModeAnimeStatus != AnimeStatic)
        return;

    if(GameInfo::gameMode>0)
        GameInfo::setGameMode(GameMode(int(GameInfo::gameMode)-1));
    else
        GameInfo::setGameMode(GameMode(5));
    GameInfo::gameModeAnimeStatus = TurnLeft;
}

void EModeButton::optionRight()
{
    if(GameInfo::gameModeAnimeStatus != AnimeStatic)
        return;

    if(GameInfo::gameMode<5)
        GameInfo::setGameMode(GameMode(int(GameInfo::gameMode)+1));
    else
        GameInfo::setGameMode(GameMode(0));
    GameInfo::gameModeAnimeStatus = TurnRight;
}
