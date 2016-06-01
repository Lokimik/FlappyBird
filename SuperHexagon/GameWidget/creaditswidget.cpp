#include "creditswidget.h"

CreditsWidget::CreditsWidget(QWidget *parent)
    : QGLWidget(parent)
{
    this->resize(GameInfo::windowSize);
    this->bufferPixmap = new QPixmap(GameInfo::bufferPixmapSize);

    GameInfo::setGameStatus(Credits);
    this->setFocusPolicy(Qt::StrongFocus);
    //
    this->backgroundFore = new EBackGroundFore(this);
    this->backgroundBack = new EBackGroundBack(this);
    //
    connect(&GameInfo::mainTimer,SIGNAL(timeout()),this,SLOT(update()));

    connect(this,SIGNAL(KEY_ESCAPE()),parent,SLOT(mainMenu()));
}

void CreditsWidget::initialize()
{
    this->show();
    GameInfo::setGameStatus(Options);
    this->setFocus();
    this->backgroundFore->initElement();
    this->backgroundBack->initElement();
}

CreditsWidget::~CreditsWidget()
{
    delete this->backgroundFore;
    delete this->backgroundBack;
}


void CreditsWidget::paintEvent(QPaintEvent *)
{
//    GameInfo::UpdateColor();
    GameInfo::UpdateRotationAngle();

    QPainter painter(this->bufferPixmap);
    painter.save();
    painter.translate(GameInfo::bufferPixmapSize.width()/2,GameInfo::bufferPixmapSize.height()/2);
    /*Rotation Element */
    painter.rotate(GameInfo::rotationAngle);
    this->backgroundFore->updateElement();
    this->backgroundFore->drawElement(&painter);
    this->backgroundBack->updateElement();
    this->backgroundBack->drawElement(&painter);
    painter.rotate(-GameInfo::rotationAngle);

    /*Static Element*/
        QFont font;
        font.setPixelSize(100);
        painter.setFont(font);
        painter.setPen(QPen(Qt::white));
        painter.drawText(QRect(-380,-250,900,300),"CREDITS");

        font.setPixelSize(45);
        painter.setFont(font);
        painter.drawText(QRectF(-300,50,900,60),"Zhang ChengWu");

        font.setPixelSize(25);
        painter.setFont(font);
        painter.drawText(QRectF(-290,300,900,60),"THANKS FOR YOUR PLAYING");

        painter.setPen(QPen(Qt::gray));
        painter.drawText(QRectF(-90,10,900,60),"GAME BY");


    painter.translate(-GameInfo::bufferPixmapSize.width()/2,-GameInfo::bufferPixmapSize.height()/2);
    painter.restore();

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*bufferPixmap,GameInfo::bufferPixmapRect);
}

void CreditsWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        emit this->KEY_ESCAPE();
    }
}
