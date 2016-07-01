#ifndef ANIME_H
#define ANIME_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QLine>
#include <QRect>
#include <QVector>
#include <QtCore/qmath.h>
#include <math.h>

class Anime : public QWidget
{
    Q_OBJECT
private:
    enum AnimeStatus
    {
        SHOW,
        HIDE,
        SHOW_S,
        HIDE_S,
    };

    struct LineSection
    {
        QVector<QLine> lines; // 3 lines.
        int increase;
        int length;
        bool isSec1Drawing;
        bool isSec2Drawing;
    };

    struct ArcSection
    {
        QRect rect;
        int startAngle;
        int lengthAngle;
        int start;
        int end;
        int increase;
        int radius;
        bool isSec1Drawing;
        bool isSec2Drawing;
    };

    struct CircleSection
    {
        QRect rect;
        int startAngle;
        int lengthAngle;
        int start;
        int end;
        int increase;
        int radius;
        bool isDrawing;
    };

    struct LineSection lineSec;
    struct ArcSection arcSec;
    struct CircleSection circleSec;

    QPen pen;
    QPoint center;

    QTimer timer; // Main timer, refresh the interface.
    AnimeStatus status;


public:
    explicit Anime(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    bool setParameters(int , int );
    void init();


signals:

public slots:
    void show();
    void increaseCircle();
    void decreaseCircle();
    void increaseLine();
    void decreaseLine();
};

#endif // ANIME_H
