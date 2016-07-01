#ifndef EMODEBUTTON_H
#define EMODEBUTTON_H

#include "gameelement.h"

class EModeButton : public GameElement
{
    Q_OBJECT
public:
    EModeButton(QObject *parent = 0);
    ~EModeButton();
    void initElement();
    void updateElement();
    void drawElement(QPainter *);

    void optionLeft();
    void optionRight();
    void optionSelect();

private:
    QPixmap *leftArrow;
    QPixmap *RightArrow;
};

#endif // EMODEBUTTON_H
