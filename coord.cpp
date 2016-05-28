#include "coord.h"

coord::coord(int x1,int y1,MyButton* b1)
{
    x = x1;
    y = y1;
    b=b1;
}

coord::coord()
{

}

int coord::getx()
{
    return x;
}

int coord::gety()
{
    return y;
}

MyButton* coord::getButton()
{
    return b;

}

/*bool coord::lessThanX(const coord &c1, const coord &c2)
{
    return c1.x < c2.x;
}*/
