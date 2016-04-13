#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

#include <QObject>
#include <QVector>
#include <QPainter>
#include <QPixmap>

class GameElement : public QObject
{
    Q_OBJECT
public:
    explicit GameElement(QObject *parent = 0);

    bool enabledLogic;
    bool enabledDraw;

    virtual void init()=0;
    virtual void draw(QPainter *)=0;
    virtual void logic()=0;

    QRectF& getBindRect();

protected:
    int frameCount;
    QVector<QPixmap> pixmapList;
    QRectF bindRect;

    void addFrame(QPixmap);
    void clearAllFrame();
signals:

public slots:

};

#endif // GAMEELEMENT_H
