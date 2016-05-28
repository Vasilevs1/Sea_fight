#include "mybutton.h"

int MyButton::getx()
{
    return x;
}

int MyButton::gety()
{
    return y;
}

MyButton::MyButton(int x1,int y1) : QPushButton()
{
    x=x1;
    y=y1;
}

