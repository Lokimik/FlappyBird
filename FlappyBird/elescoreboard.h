#ifndef ELESCOREBOARD_H
#define ELESCOREBOARD_H

#include "gameelement.h"

class EleScoreBoard : public GameElement
{
    Q_OBJECT
private:
    int score;
    int tempUnit;
    int tempDecade;
    int tempHundred;
    void loadFrame();

public:
    explicit EleScoreBoard(QObject *parent = 0);
    void init();
    void draw(QPainter *);
    void logic();
    void setScore(int);

signals:

public slots:

};

#endif // ELESCOREBOARD_H
