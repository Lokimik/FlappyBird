#ifndef ECENTRALHEXAGON_H
#define ECENTRALHEXAGON_H

#include "gameelement.h"

class ECentralHexagon : public GameElement
{
    Q_OBJECT
public:
    explicit ECentralHexagon(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);

private:
    bool isGameOver;
    bool isAnimeFinished;
//    void zoomPolygon(float);
};

#endif // ECENTRALHEXAGON_H
