#ifndef EMENUBUTTON_H
#define EMENUBUTTON_H

#include "gameelement.h"

class EMenuButton : public GameElement
{
    Q_OBJECT
public:
    EMenuButton(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);

    void optionLeft();
    void optionRight();
//    void optionSelect();
    int getOption();

private:
    QPixmap *leftArrow;
    QPixmap *RightArrow;

    QVector<QString> optionList;
    int optionPointer;

signals:

};

#endif // EMENUBUTTON_H
