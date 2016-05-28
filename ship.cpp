#include "ship.h"

bool Ship::buttonBelongsTo(int xb, int yb)
{
    for(int i=0;i<coordVector.size();i++)
    {
        if((coordVector[i].getx() == xb)&&(coordVector[i].gety() == yb))
        {
            return 1;
        }
    }
    return 0;
}

Ship::Ship(int s)
{

    size = s;
    wasPlaced = 0;
}

void Ship::addcoord(coord a)
{
    coordVector.append(a);
}



void Ship::place()
{
    wasPlaced++;
}

QVector<coord>& Ship::getcoords()
{
    return coordVector;
}


bool Ship::isPlaced()
{
    if(wasPlaced > 1) return 1;
    else return 0;
}

QVector<coord> Ship::sortVX()
{
    QVector<coord> tempo  = coordVector;
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(tempo[j].getx() < tempo[j+1].getx())
            {
               coord temp = tempo[j];
               tempo[j] = tempo[j+1];
               tempo[j+1] = temp;
            }
        }
    }
    return tempo;
}

QVector<coord> Ship::sortVY()
{
    QVector<coord> tempo = coordVector;
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(tempo[j].gety() < tempo[j+1].gety())
            {
               coord temp = tempo[j];
               tempo[j] = tempo[j+1];
               tempo[j+1] = temp;
            }
        }
    }
    return tempo;
}



