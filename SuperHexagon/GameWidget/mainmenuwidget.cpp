#include "mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->resize(GameInfo::windowSize);
    this->bufferPixmap = new QPixmap(GameInfo::bufferPixmapSize);

    GameInfo::setGameStatus(MainMenu);
    this->setFocusPolicy(Qt::StrongFocus);
    //
    this->backgroundFore = new EBackGroundFore(this);
    this->backgroundBack = new EBackGroundBack(this);
    this->menuButton = new EMenuButton(this);
    //
    connect(&GameInfo::mainTimer,SIGNAL(timeout()),this,SLOT(update()));

    connect(this,SIGNAL(START_GAME()),parent,SLOT(modeSelect()));
    connect(this,SIGNAL(OPTIONS()),parent,SLOT(options()));
    connect(this,SIGNAL(CREDITS()),parent,SLOT(credits()));
    connect(this,SIGNAL(QUIT()),parent,SLOT(quit()));
}

void MainMenuWidget::initialize()
{
    this->show();
    GameInfo::setGameStatus(MainMenu);
    this->setFocus();

    this->backgroundFore->initElement();
    this->backgroundBack->initElement();
    this->menuButton->initElement();
}

MainMenuWidget::~MainMenuWidget()
{
    delete this->backgroundFore;
    delete this->backgroundBack;

    delete this->menuButton;
}

void MainMenuWidget::paintEvent(QPaintEvent *)
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
    this->menuButton->updateElement();
    this->menuButton->drawElement(&painter);

    painter.translate(-GameInfo::bufferPixmapSize.width()/2,-GameInfo::bufferPixmapSize.height()/2);
    painter.restore();

    QPainter mainWindowPainter(this);
    mainWindowPainter.drawPixmap(QRect(0,0,this->width(),this->height()),*bufferPixmap,GameInfo::bufferPixmapRect);
}

void MainMenuWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->menuButton->optionLeft();
    }
    if(event->key() == Qt::Key_Right)
    {
        this->menuButton->optionRight();
    }
    if(event->key() == Qt::Key_Space)
    {
        switch (this->menuButton->getOption())
        {
        case 0:
            emit START_GAME();
            break;
        case 1:
            emit OPTIONS();
            break;
        case 2:
            emit CREDITS();
            break;
        case 3:
            emit QUIT();
            break;
        }
    }
}
