#include "ScreenObject.h"

ScreenObject::ScreenObject(): x_pos(63) , y_pos(63) { }


void ScreenObject::setX_Pos(int s)
{
    x_pos = s;
}

void ScreenObject::setY_Pos(int s)
{
    y_pos = s;
}

int ScreenObject::getX_Pos()
{
    return x_pos;
}

int ScreenObject::getY_Pos()
{
    return y_pos;
}
