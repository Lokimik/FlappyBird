#ifndef EBACKGROUNDFORE_H
#define EBACKGROUNDFORE_H

#include "gameelement.h"

class EBackGroundFore : public GameElement
{
    Q_OBJECT
public:
    explicit EBackGroundFore(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);
};

#endif // EBACKGROUNDFORE_H
