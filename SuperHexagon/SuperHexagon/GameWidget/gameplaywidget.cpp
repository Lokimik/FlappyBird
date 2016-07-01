#include "gameplaywidget.h"

GamePlayWidget::GamePlayWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(GameInfo::windowSize);
    this->bufferPixmap = new QPixmap(GameInfo::bufferPixmapSize);

    GameInfo::setGameStatus(GamePlay);
    this->setFocusPolicy(Qt::StrongFocus);
    //
    this->backgroundFore = new EBackGroundFore(this);
    this->backgroundBack = new EBackGroundBack(this);
    this->centralHexagon = new ECentralHexagon(this);
    this->cursor = new ECursor(this);
    this->timekeeper = new ETimekeeper(this);
    //
    connect(&GameInfo::mainTimer,SIGNAL(timeout()),this,SLOT(update()));

    connect(this,SIGNAL(KEY_ESCAPE()),parent,SLOT(gameOver()));
    connect(this,SIGNAL(GAMEOVER()),parent,SLOT(gameOver()));
}
void GamePlayWidget::initialize()
{
    this->show();
    GameInfo::setGameStatus(GamePlay);
    GameInfo::rotationAngle = 0;
    this->setFocus();

    this->backgroundFore->initElement();
    this->backgroundBack->initElement();
    this->centralHexagon->initElement();
    this->cursor->initElement();
    this->timekeeper->initElement();
}

GamePlayWidget::~GamePlayWidget()
{
    delete this->backgroundBack;
    delete this->backgroundFore;
    delete this->centralHexagon;
    delete this->cursor;
    delete this->timekeeper;
}

void GamePlayWidget::paintEvent(QPaintEvent *)
{
    GameInfo::UpdateColor();
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
    this->centralHexagon->updateElement();
    this->centralHexagon->drawElement(&painter);
    this->cursor->updateElement();
    this->cursor->drawElement(&painter);
    painter.rotate(-GameInfo::rotationAngle);

    /*Static Element*/
    this->timekeeper->updateElement();
    this->timekeeper->drawElement(&painter);

    painter.translate(-GameInfo::bufferPixmapSize.width()/2,-GameInfo::bufferPixmapSize.height()/2);
    painter.restore();

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*bufferPixmap,GameInfo::bufferPixmapRect);
}

void GamePlayWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->cursor->status = RotateLeft;
    }
    if(event->key() == Qt::Key_Right)
    {
        this->cursor->status = RotateRight;
    }
    if(event->key() == Qt::Key_Escape)
    {
        emit this->KEY_ESCAPE();
    }
}

void GamePlayWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right )
    {
        this->cursor->status = Static;
    }
}
