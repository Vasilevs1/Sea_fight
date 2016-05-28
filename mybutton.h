#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>

class MyButton : public QPushButton
{
    int x;
    int y;
public:
    int getx();
    int gety();
    MyButton(int x1, int y1);
};

#endif // MYBUTTON_H
