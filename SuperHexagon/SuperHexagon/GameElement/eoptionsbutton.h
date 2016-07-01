#ifndef EOPTIONSBUTTON_H
#define EOPTIONSBUTTON_H

#include "gameelement.h"

class EOptionsButton : public GameElement
{
    Q_OBJECT
public:
    EOptionsButton(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);

    void optionUp();
    void optionDown();
    void optionSelect();

private:
    int optionPointer;
};

#endif // EOPTIONSBUTTON_H
