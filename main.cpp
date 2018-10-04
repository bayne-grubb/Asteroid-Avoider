#include "MMA8452.h"
#include "mbed.h"
#include "uLCD_4DGL.h"
#include "Speaker.h"
#include "ConcreteAsteroid1.h"
#include "ConcreteAsteroid2.h"
#include "ConcreteAsteroid3.h"
#include "ConcreteAsteroid4.h"
#include "SpaceShipEarth.h"
#include "PinDetect.h"
#include <cstdlib>
#include <ctime>

Serial pc(USBTX,USBRX);

PinDetect pb1(p17);

Speaker mySpeaker(p21);

bool lossCondition = false;

bool overlap(ScreenObject  &objectA, ScreenObject  &objectB)
{
    int EX = objectA.getX_Pos();
    int EY = objectA.getY_Pos();
    int AX = objectB.getX_Pos();
    int AY = objectB.getY_Pos();
    int LCX = EX - 15;
    int LCY = EX - 12;
    int RCX = EX + 10;
    int RCY = EX + 10;

    if( (AX > LCX) && (AX < RCX) && (AY>LCY) && (AY<RCY)) {
        lossCondition = true;
        return true;
    } else {
        return false;
    }


}



bool bombUsed = false;
bool ExplodeAllAsteroids = false;

void pb1_hit_callback (void)
{
    if(!bombUsed) {
        bombUsed = true;
        ExplodeAllAsteroids = true;
        mySpeaker.PlayNote(200.0,0.25,0.1);
    }
}

uLCD_4DGL uLCD(p28, p27, p29);


int main()
{

    uLCD.baudrate(3000000);
    wait(0.2);
    srand(time(0)); // do this srand call here ONLY... no where else in the code!
    MMA8452 acc(p9, p10, 40000);  //instantiate an acc object!

    //set parameters -- use these and don't change
    acc.setBitDepth(MMA8452::BIT_DEPTH_12);
    acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
    acc.setDataRate(MMA8452::RATE_100);


    SpaceShipEarth ship;

    ConcreteAsteroid1 Asteroid1;

    ConcreteAsteroid2 Asteroid2;

    ConcreteAsteroid3 Asteroid3;

    ConcreteAsteroid4 Asteroid4;

    pb1.mode(PullUp);
    wait(.01);
    pb1.attach_deasserted(&pb1_hit_callback);
    pb1.setSampleFrequency();

    set_time(0);
    time_t seconds;
    seconds = time(NULL);


    uLCD.rectangle(2 , 2 , 60 , 5 , 0x0000FF);
    while(seconds < 3) {
        seconds = time(NULL);

        Asteroid1.isOffScreen();
        Asteroid2.isOffScreen();
        Asteroid3.isOffScreen();
        Asteroid4.isOffScreen();

        Asteroid1.update();
        Asteroid2.update();
        Asteroid3.update();
        Asteroid4.update();

        ship.update(); //update ship position



        if(!acc.isXYZReady()) {
            wait(0.00001);
        } else {
            double x , y , z;
            acc.readXYZGravity(&x,&y,&z); //notice this is passed by reference use pointers

            if(x>0)
                ship.moveRight(x*3);
            else if(x<0)
                ship.moveLeft(abs(x*3));

            if(y>0)
                ship.moveForward(y*3);
            else if(y<0)
                ship.moveBackward(abs(y*3));


        }
        Asteroid1.isOffScreen();
        Asteroid2.isOffScreen();
        Asteroid3.isOffScreen();
        Asteroid4.isOffScreen();

        ship.draw();

        //mySpeaker.PlayNote(400.0,0.25,0.1);
        Asteroid1.draw();
        //mySpeaker.PlayNote(400.0,0.25,0.1);
        Asteroid2.draw();
        //mySpeaker.PlayNote(400.0,0.25,0.1);
        Asteroid3.draw();
        //mySpeaker.PlayNote(400.0,0.25,0.1);
        Asteroid4.draw();



        if(overlap(ship , Asteroid1) || overlap(ship , Asteroid2) || overlap(ship , Asteroid3) || overlap(ship , Asteroid4)) {
            ship.explode();
            wait(0.5);
            uLCD.cls();
            uLCD.printf("\n\n\n\n\n\t\t\t\t You LOST! \n");
            break;
        }




        if(ExplodeAllAsteroids) {
            Asteroid1.update();
            Asteroid2.update();
            Asteroid3.update();
            Asteroid4.update();
            Asteroid1.resetAsteroid();
            Asteroid2.resetAsteroid();
            Asteroid3.resetAsteroid();
            Asteroid4.resetAsteroid();
            wait(1);
            ExplodeAllAsteroids = false;
        }


        uLCD.rectangle(2 , 2 , 60 , 5 , 0x0000FF);
        uLCD.filled_rectangle(2 , 2 , 59 , 5 , BLACK);
        uLCD.filled_rectangle(2 , 2 , 60-2*seconds , 5 , 0x0000FF);
        //mySpeaker.PlayNote(400.0,0.25,0.1);
    }
    mySpeaker.PlayNote(400.0,0.25,0.1);
    if(!lossCondition) {
        uLCD.cls();
        uLCD.printf("\n\n\n\n\n\t\t\t\t Congratulations, \t\t You Have Won!\n");
    }
}
