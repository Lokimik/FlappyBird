#include "gameinfo.h"

QSize GameInfo::windowSize(1334,750);
QSize GameInfo::bufferPixmapSize(1530,1530);
QRect GameInfo::bufferPixmapRect(
        QPoint((GameInfo::bufferPixmapSize.width() - GameInfo::windowSize.width())/2,
               (GameInfo::bufferPixmapSize.height() - GameInfo::windowSize.height())/2),
        GameInfo::windowSize);
GameStatus GameInfo::gameStatus = MainMenu;
GameMode GameInfo::gameMode = Hexgon;
GameModeAnimeStatus GameInfo::gameModeAnimeStatus = AnimeStatic;
QTimer GameInfo::mainTimer;
float GameInfo::rotationAngle = 0;
bool GameInfo::sound = true;

QVector<QColor> GameInfo::widgetBorderColor;
QVector<QColor> GameInfo::widgetColor;
QVector<QColor> GameInfo::backGroundForeColor;
QVector<QColor> GameInfo::backGroundBackColor;

int GameInfo::colorPointer = 0;

GameInfo::GameInfo()
{
}

void GameInfo::InitColor()
{
    GameInfo::widgetBorderColor.clear();
    GameInfo::widgetColor.clear();
    GameInfo::backGroundForeColor.clear();
    GameInfo::backGroundBackColor.clear();

    switch(GameInfo::gameStatus)
    {
    case MainMenu:
    case Options:
    case Credits:
        GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0x797979),QColor(0x797979));
        GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0x525252),QColor(0x525252));
        GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0x303030),QColor(0x303030));
        GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(0x262626),QColor(0x262626));
        break;
    case ModeSelect:
    case GamePlay:
    case GameOver:
        switch(GameInfo::gameMode)
        {
        case Hexgon:
            GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0xE01B30),QColor(0xE0DD1C));
            GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0x7C0013),QColor(0x88760B));
            GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0x6A1907),QColor(0x5C4A08));
            GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(0x471105),QColor(0x3E2B05));
            break;
        case Hexgoner:
            GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0xFF8800),QColor(0x00FF80));
            GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0xFF8800),QColor(0x00FF80));
            GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0x281400),QColor(0x002814));
            GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(Qt::black),QColor(Qt::black));
            break;
        case Hexgonest:
            GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0x46F910),QColor(0x46F910));
            GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0x1FA600),QColor(0x1FA600));
            GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0x116300),QColor(0x116300));
            GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(0x0B5200),QColor(0x0B5200));
            break;
        case Hexgon_Hyper:
            GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0x0FB7B9),QColor(0x485ADF));
            GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0x097777),QColor(0x2A2480));
            GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0x006666),QColor(0x090969));
            GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(0x004444),QColor(0x060646));
            break;
        case Hexgoner_Hyper:
            GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0x007FFF),QColor(0xFF007F));
            GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0x007FFF),QColor(0xFF007F));
            GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0xD8ECFF),QColor(0xFFD8EC));
            GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(0xFFFFFF),QColor(0xFFFFFF));
            break;
        case Hexgonest_Hyper:
            GameInfo::InitColorVector(GameInfo::widgetBorderColor,QColor(0xFFFFFF),QColor(0xF2F2F2));
            GameInfo::InitColorVector(GameInfo::widgetColor,QColor(0xFFFFFF),QColor(0xA0A0A0));
            GameInfo::InitColorVector(GameInfo::backGroundForeColor,QColor(0xC0C0C0),QColor(0x606060));
            GameInfo::InitColorVector(GameInfo::backGroundBackColor,QColor(0x969696),QColor(0x4C4C4C));
            break;
        }
        break;
    }
}

void GameInfo::UpdateColor()
{
       if(GameInfo::colorPointer < 118)
           GameInfo::colorPointer++;
       else
           GameInfo::colorPointer = 0;
}

void GameInfo::InitColorVector(QVector<QColor> &vector, const QColor &head, const QColor &end)
{
    float increaseRed = (end.red() - head.red())/60.0;
    float increaseGreen = (end.green() - head.green())/60.0;
    float increaseBlue = (end.blue() - head.blue())/60.0;
    vector.clear();
    for(int i=1;i<60;i++)
    {
        vector.append(QColor(head.red()+i*increaseRed,
                             head.green()+i*increaseGreen,
                             head.blue()+i*increaseBlue));
    }
    for(int i=60;i>0;i--)
    {
        vector.append(QColor(head.red()+i*increaseRed,
                             head.green()+i*increaseGreen,
                             head.blue()+i*increaseBlue));
    }
}

void GameInfo::setGameMode(GameMode _mode)
{
    GameInfo::gameMode = _mode;
    GameInfo::InitColor();
}

void GameInfo::setGameStatus(GameStatus _status)
{
    GameInfo::gameStatus = _status;
    GameInfo::InitColor();
}

void GameInfo::UpdateRotationAngle()
{
    switch(GameInfo::gameStatus)
    {
    case MainMenu:
    case Options:
    case Credits:
        if(GameInfo::rotationAngle+0.8 > 360)
            GameInfo::rotationAngle -= 360;
        GameInfo::rotationAngle += 0.8;
        break;
    case ModeSelect:
        if (GameInfo::gameModeAnimeStatus == TurnLeft)
        {
            if (GameInfo::rotationAngle<60)
            {
                GameInfo::rotationAngle += 5;
            }
            else
            {
                GameInfo::gameModeAnimeStatus = AnimeStatic;
                GameInfo::rotationAngle = 0;
            }
        }
        else if (GameInfo::gameModeAnimeStatus == TurnRight)
        {
            if  (GameInfo::rotationAngle>-60)
            {
                GameInfo::rotationAngle -= 5;
            }
            else
            {
                GameInfo::gameModeAnimeStatus = AnimeStatic;
                GameInfo::rotationAngle = 0;
            }
        }
        break;
    case GamePlay:
        switch(GameInfo::gameMode)
        {
        case Hexgon:
            if(GameInfo::rotationAngle+0.8 > 360)
                GameInfo::rotationAngle -= 360;
            GameInfo::rotationAngle += 0.8;
            break;
        case Hexgoner:
            if(GameInfo::rotationAngle+0.8 > 360)
                GameInfo::rotationAngle -= 360;
            GameInfo::rotationAngle += 1.5;
            break;
        case Hexgonest:
            if(GameInfo::rotationAngle+0.8 > 360)
                GameInfo::rotationAngle -= 360;
            GameInfo::rotationAngle += 2.3;
            break;
        case Hexgon_Hyper:
            if(GameInfo::rotationAngle+0.8 > 360)
                GameInfo::rotationAngle -= 360;
            GameInfo::rotationAngle += 2.8;
            break;
        case Hexgoner_Hyper:
            if(GameInfo::rotationAngle+0.8 > 360)
                GameInfo::rotationAngle -= 360;
            GameInfo::rotationAngle += 3.3;
            break;
        case Hexgonest_Hyper:
            if(GameInfo::rotationAngle+0.8 > 360)
                GameInfo::rotationAngle -= 360;
            GameInfo::rotationAngle += 4.5;
            break;
        }
        break;
    case GameOver:
        if(GameInfo::rotationAngle+0.8 > 360)
            GameInfo::rotationAngle -= 360;
        GameInfo::rotationAngle += 0.8;
        break;
    }
}
