#ifndef COORD_H
#define COORD_H
#include "mybutton.h"

class coord
{
    int x;
    int y;
    MyButton *b;

public:
    coord(int x1,int y1,MyButton* b1);
    coord();
    int getx();
    int gety();
    MyButton* getButton();
   // static bool lessThanX(const coord &c1, const coord &c2);

};

#endif // COORD_H
