#include "ScreenObject.h"

class SpaceShipEarth: public ScreenObject
{
private:

public:
    virtual void draw();
    virtual void update();
    void explode();
    void moveRight(double moveDist);
    void moveLeft(double moveDist);
    void moveForward(double moveDist);
    void moveBackward(double moveDist);

}; //end class SpaceShipEarth