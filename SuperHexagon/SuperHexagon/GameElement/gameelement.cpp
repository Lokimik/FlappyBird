#include "gameelement.h"

GameElement::GameElement(QObject *parent) :
    QObject(parent)
{
    this->clearAllPolygon();
    this->enabledUpdate = false;
    this->enabledDraw = false;
}

void GameElement::addPolygon(const QPolygon &polygon)
{
    if(polygon.isEmpty())
        return;
    this->polygonList.append(polygon);
    this->zoomPolygonList.append(polygon);
    this->polygonListLength = this->polygonList.length();
}

void GameElement::clearAllPolygon()
{
    this->polygonList.clear();
    this->zoomPolygonList.clear();
    this->polygonListLength = this->polygonList.length();
}

QPolygon &GameElement::getPolygon(int i)
{
    return this->polygonList[i];
}

QVector<QPolygon> &GameElement::zoomPolygon(float rate)
{
//    if(polygonList.isEmpty())
//        return;

    for(int i = 0; i<this->polygonList.length(); i++)
    {
        for(int j = 0; j< this->polygonList[i].length(); j++)
        {
            this->zoomPolygonList[i][j] = polygonList[i][j] * rate;
//            polygonList[0][j].operator *=(rate);
        }
    }
    return this->zoomPolygonList;
}
