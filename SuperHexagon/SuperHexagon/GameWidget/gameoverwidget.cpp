#include "gameoverwidget.h"

GameOverWidget::GameOverWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(GameInfo::windowSize);
    this->bufferPixmap = new QPixmap(GameInfo::bufferPixmapSize);

    GameInfo::setGameStatus(GameOver);
    this->setFocusPolicy(Qt::StrongFocus);
    //
    this->backgroundFore = new EBackGroundFore(this);
    this->backgroundBack = new EBackGroundBack(this);
    this->centralHexagon = new ECentralHexagon(this);
    this->cursor = new ECursor(this);
    this->overBoard = new EOverBoard(this);
    //
    connect(&GameInfo::mainTimer,SIGNAL(timeout()),this,SLOT(update()));

    connect(this,SIGNAL(KEY_ESCAPE()),parent,SLOT(modeSelect()));
    connect(this,SIGNAL(KEY_SPACE()),parent,SLOT(gamePlay()));
}

GameOverWidget::~GameOverWidget()
{
    delete this->backgroundBack;
    delete this->backgroundFore;
    delete this->centralHexagon;
    delete this->cursor;
    delete this->overBoard;
}

void GameOverWidget::initialize()
{
    this->show();
    GameInfo::setGameStatus(GamePlay);
    this->setFocus();
    this->backgroundFore->initElement();
    this->backgroundBack->initElement();
    this->centralHexagon->initElement();
    this->cursor->initElement();
    this->overBoard->initElement();
}


void GameOverWidget::paintEvent(QPaintEvent *)
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
    this->overBoard->updateElement();
    this->overBoard->drawElement(&painter);

    painter.translate(-GameInfo::bufferPixmapSize.width()/2,-GameInfo::bufferPixmapSize.height()/2);
    painter.restore();

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*bufferPixmap,GameInfo::bufferPixmapRect);
}

void GameOverWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        emit this->KEY_ESCAPE();
    }
    if(event->key() == Qt::Key_Space)
    {
        emit this->KEY_SPACE();
    }
}
