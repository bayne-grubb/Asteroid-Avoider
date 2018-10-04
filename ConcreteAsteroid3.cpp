#include "ConcreteAsteroid3.h"

extern uLCD_4DGL uLCD;

int e = 5;
int f = 110;

ConcreteAsteroid3::ConcreteAsteroid3()
{
    do {
        deltaX = (rand()%e - 2);
    } while(deltaX==0);
    do {
        deltaY = (rand()%e - 2);
    } while(deltaY==0);
    int borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%f);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%f);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%f);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%f);
    }
}

int asteroid_sprite_3[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,X,X,_,_,_,_,_,_,X,X,X,X,X,
    _,X,_,_,X,X,_,_,X,X,_,_,_,X,_,
    X,_,_,_,_,_,X,X,_,_,_,_,X,_,_,
    _,X,_,_,_,_,_,_,_,_,_,X,_,_,_,
    _,_,X,_,_,_,_,_,_,_,X,_,_,_,_,
    _,_,_,X,_,_,_,_,_,_,_,X,_,_,_,
    _,_,X,_,_,_,_,_,_,_,_,_,X,X,_,
    _,X,_,_,_,_,_,_,_,_,_,_,_,_,X,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_,
    _,_,X,_,X,X,X,_,_,_,_,X,_,_,_,
    _,_,_,X,_,_,_,X,X,X,X,_,_,_,_
};

int black_asteroid_sprite_3[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
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

void ConcreteAsteroid3::draw()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              asteroid_sprite_3);
}

void ConcreteAsteroid3::update()
{
    if(x_pos > 110 || y_pos > 110 || x_pos < 0 || y_pos < 0)
        resetAsteroid();
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              black_asteroid_sprite_3);
    x_pos += deltaX;
    y_pos += deltaY;
}

void ConcreteAsteroid3::isOffScreen()
{
    if(x_pos > 110 || y_pos > 110 || x_pos < 0 || y_pos < 0)
        resetAsteroid();
}

void ConcreteAsteroid3::resetAsteroid()
{
    //uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
    //          black_asteroid_sprite_3);
    do {
        deltaX = (rand()%e - 2);
    } while(deltaX==0);
    do {
        deltaY = (rand()%e - 2);
    } while(deltaY==0);
    int borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%f);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%f);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%f);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%f);
    }
}