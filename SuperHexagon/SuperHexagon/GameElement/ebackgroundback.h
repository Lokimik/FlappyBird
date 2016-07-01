#ifndef EBACKGROUNDBACK_H
#define EBACKGROUNDBACK_H

#include "gameelement.h"

class EBackGroundBack : public GameElement
{
    Q_OBJECT
public:
    explicit EBackGroundBack(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);
};

#endif // EBACKGROUNDBACK_H
