#ifndef EOVERBOARD_H
#define EOVERBOARD_H

#include "gameelement.h"

class EOverBoard : public GameElement
{
    Q_OBJECT
public:
    EOverBoard(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);
};

#endif // EOVERBOARD_H
