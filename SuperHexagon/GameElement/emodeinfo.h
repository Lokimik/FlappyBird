#ifndef EMODEINFO_H
#define EMODEINFO_H

#include "gameelement.h"

class EModeInfo : public GameElement
{
    Q_OBJECT
public:
    EModeInfo(QObject *parent = 0);

    void initElement();
    void updateElement();
    void drawElement(QPainter *);

private:
    QVector<QString> difficultyList;
    QVector<QString> modeList;
};

#endif // EMODEINFO_H
