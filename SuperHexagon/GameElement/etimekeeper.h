#ifndef ETIMEKEEPER_H
#define ETIMEKEEPER_H

#include "gameelement.h"

class ETimekeeper : public GameElement
{
public:
    ETimekeeper(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);

private:
    int milliSecond;
    int second;
    bool isTenSecReset;
    bool isHundredSecReset;
    int adjust;
};

#endif // ETIMEKEEPER_H
