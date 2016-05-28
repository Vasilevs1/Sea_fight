#ifndef SHIP_H
#define SHIP_H
#include <QVector>
#include "coord.h"
class Ship
{

     int size;
     int wasPlaced;
     QVector <coord> coordVector;
public:
    bool buttonBelongsTo(int xb,int yb);
    Ship(int s);
    void addcoord(coord a);
    void place();
    QVector<coord>& getcoords();
    bool isPlaced();
    QVector<coord> sortVX();
    QVector<coord> sortVY();

};

#endif // SHIP_H
