#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <QObject>
#include <QSize>
#include <QRect>
#include <QColor>
#include <QVector>
#include <QTimer>

enum GameMode
{
    Hexgon=0,
    Hexgoner=1,
    Hexgonest=2,
    Hexgon_Hyper=3,
    Hexgoner_Hyper=4,
    Hexgonest_Hyper =5
};

enum GameStatus
{
    MainMenu,
    Options,
    Credits,
    ModeSelect,
    GamePlay,
    GameOver
};

enum GameModeAnimeStatus
{
    TurnLeft,
    TurnRight,
    AnimeStatic,
};

class GameInfo : public QObject
{
public:
    GameInfo();
    static void UpdateRotationAngle();
    static void setGameMode(GameMode);
    static void setGameStatus(GameStatus);
    static void InitColor();
    static void InitColorVector(QVector<QColor>&,const QColor&,const QColor&);
    static void UpdateColor();

    static GameMode gameMode;
    static GameStatus gameStatus;
    static GameModeAnimeStatus gameModeAnimeStatus;
    static QSize windowSize;
    static QSize bufferPixmapSize;
    static QRect bufferPixmapRect;
    static QTimer mainTimer;
    static float rotationAngle;
    static bool sound;

    static QVector<QColor> widgetBorderColor;
    static QVector<QColor> widgetColor;
    static QVector<QColor> backGroundForeColor;
    static QVector<QColor> backGroundBackColor;
    static QVector<QColor> titleColor;

    static int colorPointer;
};

#endif // GAMEINFO_H
