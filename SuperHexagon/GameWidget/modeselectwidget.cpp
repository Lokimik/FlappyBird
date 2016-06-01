#include "modeselectwidget.h"

ModeSelectWidget::ModeSelectWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(GameInfo::windowSize);
    this->bufferPixmap = new QPixmap(GameInfo::bufferPixmapSize);

    GameInfo::setGameStatus(ModeSelect);
    this->setFocusPolicy(Qt::StrongFocus);
    //
    this->backgroundFore = new EBackGroundFore(this);
    this->backgroundBack = new EBackGroundBack(this);
    this->modeButton = new EModeButton(this);
    this->centralHexagon = new ECentralHexagon(this);
    this->modeInfo = new EModeInfo(this);
    //
    connect(&GameInfo::mainTimer,SIGNAL(timeout()),this,SLOT(update()));

    connect(this,SIGNAL(KEY_ESCAPE()),parent,SLOT(mainMenu()));
    connect(this,SIGNAL(KEY_SPACE()),parent,SLOT(gamePlay()));
}

void ModeSelectWidget::initialize()
{
    this->show();
    GameInfo::setGameStatus(ModeSelect);
    GameInfo::rotationAngle = 0;
    this->setFocus();

    this->backgroundFore->initElement();
    this->backgroundBack->initElement();
    this->modeButton->initElement();
    this->centralHexagon->initElement();
    this->modeInfo->initElement();
}

ModeSelectWidget::~ModeSelectWidget()
{
    delete this->backgroundFore;
    delete this->backgroundBack;
    delete this->modeButton;
    delete this->centralHexagon;
    delete this->modeInfo;
}

void ModeSelectWidget::paintEvent(QPaintEvent *)
{
    GameInfo::UpdateColor();
    GameInfo::UpdateRotationAngle();

    QPainter painter(this->bufferPixmap);
    painter.save();
    painter.translate(GameInfo::bufferPixmapSize.width()/2,GameInfo::bufferPixmapSize.height()/2);
    /*Rotation Element */
    painter.rotate(GameInfo::rotationAngle);//Rotation Angles.
    this->backgroundFore->updateElement();
    this->backgroundFore->drawElement(&painter);
    this->backgroundBack->updateElement();
    this->backgroundBack->drawElement(&painter);
    this->centralHexagon->updateElement();
    this->centralHexagon->drawElement(&painter);
    painter.rotate(-GameInfo::rotationAngle);//Rotation Angles.

    /*Static Element*/
    this->modeButton->updateElement();
    this->modeButton->drawElement(&painter);
    this->modeInfo->updateElement();
    this->modeInfo->drawElement(&painter);

    painter.translate(-GameInfo::bufferPixmapSize.width()/2,-GameInfo::bufferPixmapSize.height()/2);
    painter.restore();

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*bufferPixmap,GameInfo::bufferPixmapRect);
}

void ModeSelectWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->modeButton->optionLeft();
    }
    if(event->key() == Qt::Key_Right)
    {
        this->modeButton->optionRight();
    }
    if(event->key() == Qt::Key_Space)
    {
        emit this->KEY_SPACE();
    }
    if(event->key() == Qt::Key_Escape)
    {
        emit this->KEY_ESCAPE();
    }
}

void ModeSelectWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->modeButton->optionLeft();
    }
    if(event->key() == Qt::Key_Right)
    {
        this->modeButton->optionRight();
    }
}
