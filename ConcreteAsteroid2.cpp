#include "ConcreteAsteroid2.h"

extern uLCD_4DGL uLCD;

int c = 5;
int d = 110;

ConcreteAsteroid2::ConcreteAsteroid2()
{
    do {
        deltaX = (rand()%c - 2);
    } while(deltaX==0);
    do {
        deltaY = (rand()%c - 2);
    } while(deltaY==0);
    int borderPosition; 
    borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%d);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%d);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%d);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%d);
    }
}

int asteroid_sprite_2[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,X,_,_,_,_,_,X,X,_,_,_,
    _,_,_,X,_,X,_,_,_,X,_,_,X,_,_,
    _,_,X,_,_,_,X,_,X,_,_,_,_,X,_,
    _,X,_,_,_,_,_,X,_,_,_,_,X,_,_,
    X,_,_,_,_,_,_,_,_,_,_,X,_,_,_,
    X,_,_,_,_,_,_,_,_,_,_,_,X,_,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,X,_,_,
    _,X,_,_,_,_,_,_,_,_,_,X,_,_,_,
    _,_,X,_,_,_,_,_,_,_,X,_,_,_,_,
    _,_,_,X,X,X,X,X,X,X,_,_,_,_,_
};

int black_asteroid_sprite_2[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
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

void ConcreteAsteroid2::draw()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              asteroid_sprite_2);
}

void ConcreteAsteroid2::update()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              black_asteroid_sprite_2);
    x_pos += deltaX;
    y_pos += deltaY;
}

void ConcreteAsteroid2::isOffScreen()
{
    if(x_pos > 110 || y_pos > 110 || x_pos < 0 || y_pos < 0)
        resetAsteroid();
}

void ConcreteAsteroid2::resetAsteroid()
{
    //uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
    //          black_asteroid_sprite_2);
    do {
        deltaX = (rand()%c - 2);
    } while(deltaX==0);
    do {
        deltaY = (rand()%c - 2);
    } while(deltaY==0);
    int borderPosition;
    borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%d);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%d);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%d);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%d);
    }
}