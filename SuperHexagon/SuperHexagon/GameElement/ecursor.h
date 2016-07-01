#ifndef ECURSOR_H
#define ECURSOR_H

#include <QTimer>
#include <QtMath>
#include "math.h"
#include "gameelement.h"

enum CursorStatus{
    Static,
    RotateLeft,
    RotateRight
};

class ECursor : public GameElement
{
    Q_OBJECT
private:
    QTimer cursorListenTimer;

    void initPolygon();
    int rotationAngle;

public:
    explicit ECursor(QObject *parent = 0);

    CursorStatus status;    

    void initElement();
    void updateElement();
    void drawElement(QPainter *);

signals:

public slots:
    void updateRotation();
};

#endif // ECURSOR_H
