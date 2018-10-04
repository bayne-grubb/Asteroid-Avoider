#include "ConcreteAsteroid4.h"

extern uLCD_4DGL uLCD;

int n = 5;
int i = 110;

ConcreteAsteroid4::ConcreteAsteroid4()
{
    do {
        deltaX = (rand()%n - 2);
    } while(deltaX==0);
    do {
        deltaY = (rand()%n - 2);
    } while(deltaY==0);
    int borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%i);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%i);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%i);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%i);
    }
}

int asteroid_sprite_4[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,X,X,X,X,X,X,X,X,_,_,_,
    _,_,_,_,X,_,_,_,_,_,_,_,X,X,_,
    _,_,_,_,_,X,_,_,_,_,_,_,_,X,X,
    X,X,X,X,X,X,X,_,_,_,_,X,X,_,_,
    X,_,_,_,_,_,_,_,_,X,X,_,_,_,_,
    X,_,_,_,_,_,_,_,X,_,_,_,_,_,_,
    X,_,_,_,_,_,_,_,X,X,X,X,_,_,_,
    X,_,_,_,_,_,_,_,_,_,_,_,X,X,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,X,X,_,_,_,_,X,_,_,
    _,_,X,_,X,X,_,_,X,_,_,X,_,_,_,
    _,_,_,X,_,_,_,_,_,X,X,_,_,_,_
};

int black_asteroid_sprite_4[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
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

void ConcreteAsteroid4::draw()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              asteroid_sprite_4);
}

void ConcreteAsteroid4::update()
{
    uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
              black_asteroid_sprite_4);
    x_pos += deltaX;
    y_pos += deltaY;

}

void ConcreteAsteroid4::isOffScreen()
{
    if(x_pos > 110 || y_pos > 110 || x_pos < 0 || y_pos < 0)
        resetAsteroid();
}

void ConcreteAsteroid4::resetAsteroid()
{
    //uLCD.BLIT(x_pos, y_pos, ASTEROID_WIDTH, ASTEROID_HEIGHT,
    //          black_asteroid_sprite_4);
    do {
        deltaX = (rand()%n - 2);
    } while(deltaX==0);
    do {
        deltaY = (rand()%n - 2);
    } while(deltaY==0);
    int borderPosition = rand() % 4;
    if(borderPosition == 0) {
        x_pos = 0;
        y_pos = (rand()%i);
    } else if(borderPosition == 1) {
        y_pos = 0;
        x_pos = (rand()%i);
    } else if(borderPosition == 2) {
        x_pos = 110;
        y_pos = (rand()%i);
    } else if(borderPosition == 3) {
        y_pos = 110;
        x_pos = (rand()%i);
    }
}