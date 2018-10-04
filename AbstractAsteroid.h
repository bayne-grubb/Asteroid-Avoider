#ifndef AbstractAsteroid_H_
#define AbstractAsteroid_H_

#include "ScreenObject.h"
#include "uLCD_4DGL.h"
class AbstractAsteroid: public ScreenObject
{
protected:
    int deltaX;
    int deltaY;
public:

    //void move();

}; //end class AbstractAsteroid

#endif