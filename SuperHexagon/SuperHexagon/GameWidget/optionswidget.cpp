#include "optionswidget.h"

OptionsWidget::OptionsWidget(QWidget *parent)
    : QGLWidget(parent)
{
    this->resize(GameInfo::windowSize);
    this->bufferPixmap = new QPixmap(GameInfo::bufferPixmapSize);

    GameInfo::setGameStatus(Options);
    this->setFocusPolicy(Qt::StrongFocus);
    //
    this->backgroundFore = new EBackGroundFore(this);
    this->backgroundBack = new EBackGroundBack(this);
    this->optionsButton = new EOptionsButton(this);
    //
    connect(&GameInfo::mainTimer,SIGNAL(timeout()),this,SLOT(update()));

    connect(this,SIGNAL(KEY_ESCAPE()),parent,SLOT(mainMenu()));
}

void OptionsWidget::initialize()
{
    this->show();
    GameInfo::setGameStatus(Options);
    this->setFocus();
    this->backgroundFore->initElement();
    this->backgroundBack->initElement();
    this->optionsButton->initElement();
}

OptionsWidget::~OptionsWidget()
{
    delete this->backgroundFore;
    delete this->backgroundBack;
    delete this->optionsButton;
}

void OptionsWidget::paintEvent(QPaintEvent *)
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
    this->optionsButton->updateElement();
    this->optionsButton->drawElement(&painter);

    painter.translate(-GameInfo::bufferPixmapSize.width()/2,-GameInfo::bufferPixmapSize.height()/2);
    painter.restore();

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*bufferPixmap,GameInfo::bufferPixmapRect);
}

void OptionsWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        this->optionsButton->optionUp();
    }
    if(event->key() == Qt::Key_Down)
    {
        this->optionsButton->optionDown();
    }
    if(event->key() == Qt::Key_Space)
    {
        this->optionsButton->optionSelect();
    }
    if(event->key() == Qt::Key_Escape)
    {
        emit this->KEY_ESCAPE();
    }
}
