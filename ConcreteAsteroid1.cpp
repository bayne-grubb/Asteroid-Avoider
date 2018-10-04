#include "ConcreteAsteroid1.h"

int a = 5;
int b = 110;


ConcreteAsteroid1::ConcreteAsteroid1()
{
    do {
        deltaX = (rand()%a - 2);
    } while(deltaX == 0);
    do {
        deltaY = (rand()%a - 2);
    } while(deltaY == 0);

    int borderPosition;
    borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%b);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%b);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%b);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%b);
    }

}

extern uLCD_4DGL uLCD;

int asteroid_sprite_1[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,X,X,X,X,X,X,X,X,_,_,_,
    _,_,_,X,_,_,_,_,_,_,_,_,X,_,_,
    _,_,X,_,_,_,_,_,_,_,_,_,X,_,_,
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_,
    X,X,X,X,_,_,_,_,_,_,_,_,_,X,_,
    _,_,_,X,_,_,_,_,_,_,_,_,_,X,_,
    _,_,X,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,X,_,_,_,_,_,X,_,
    X,_,_,_,_,_,X,X,_,_,_,_,X,_,_,
    _,X,_,_,_,X,_,X,_,_,_,_,X,_,_,
    _,_,X,_,X,_,_,X,_,_,_,X,_,_,_,
    _,_,_,X,_,_,_,X,X,X,X,_,_,_,_
};

int black_asteroid_sprite_1[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_
};

void ConcreteAsteroid1::draw()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              asteroid_sprite_1);
}

void ConcreteAsteroid1::update()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              black_asteroid_sprite_1);
    x_pos += deltaX;
    y_pos += deltaY;
}

void ConcreteAsteroid1::isOffScreen()
{
    if(x_pos > 110 || y_pos > 110 || x_pos < 0 || y_pos < 0)
        resetAsteroid();
}

void ConcreteAsteroid1::resetAsteroid()
{
    //uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
      //        black_asteroid_sprite_1);
    do {
        deltaX = (rand()%a - 2);
    }while(deltaX==0);
    do {
        deltaY = (rand()%a - 2);
    }while(deltaY==0);
    int borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%b);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%b);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%b);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%b);
    }
}