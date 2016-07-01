#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

#include <QObject>
#include <QVector>
#include <QPainter>

#include "gameinfo.h"

class GameElement : public QObject
{
    Q_OBJECT
private:
    QVector<QPolygon> polygonList;
    QVector<QPolygon> zoomPolygonList;
public:
    explicit GameElement(QObject *parent = 0);

    bool enabledUpdate;
    bool enabledDraw;

    virtual void initElement()=0;
    virtual void updateElement()=0;
    virtual void drawElement(QPainter *)=0;

protected:
    QPen pen;
    QBrush brush;
    QFont font;

    int polygonListLength;
    void addPolygon(const QPolygon &);
    void clearAllPolygon();
    QVector<QPolygon> &zoomPolygon(float);
    QPolygon& getPolygon(int);
signals:

public slots:

};

#endif // GAMEELEMENT_H
