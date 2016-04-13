#ifndef ELETITLEBOARD_H
#define ELETITLEBOARD_H

#include <QTimer>
#include"gameelement.h"

class EleTitleBoard : public GameElement
{
    Q_OBJECT
private:
    QTimer timer;
    int lastFrame;
    int currentFrame;
    void loadFrame();

public:
    explicit EleTitleBoard(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();

signals:

public slots:
    void updateFrame();

};

#endif // ELETITLEBOARD_H
