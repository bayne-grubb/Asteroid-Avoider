#include "SpaceShipEarth.h"
#include "uLCD_4DGL.h"
extern uLCD_4DGL uLCD;

#define ASTEROID_HEIGHT 12
#define ASTEROID_WIDTH 15
#define SPRITE_MAX 15
#define EARTH_WIDTH 10
#define EARTH_HEIGHT 10
#define EXPLOSION1_WIDTH 20
#define SCREEN_MAX 125
#define SCREEN_MIN 1
#define NUM_ASTEROIDS 4
#define Q 0x808000 //OLIVE
#define I 0x008000 //GREEN
#define S 0xC0C0C0 //SILVER
#define C 0x17202A //UFO GLASS
#define D 0x797D7F //DARK GREY
#define L 0x00FF00 //LIME
#define P 0xFF00FF //PINK
#define R 0xF1C40F //YELLOW
#define O 0xF39C12 //ORANGE
#define G 0xAAB7B8 //GREY
#define _ 0x000000 //BLACK
#define X 0xFFFFFF //WHITE
#define B 0x0000FF //BLUE
#define r 0xFF0000 //RED

int ship_sprite[EARTH_WIDTH *EARTH_HEIGHT] = {
    _,_,S,S,S,S,S,S,_,_,
    _,S,I,I,I,I,I,I,S,_,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,I,S,
    S,I,I,I,I,I,I,I,S,_,
    _,S,S,S,S,S,S,S,_,_,
};

int black_ship_sprite[EARTH_WIDTH *EARTH_HEIGHT] = {
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,
};

int explode_ship_sprite[EARTH_WIDTH *EARTH_HEIGHT] = {
    _,r,S,S,S,S,S,S,r,_,
    r,S,r,r,r,r,r,r,S,r,
    S,r,r,r,r,r,r,r,r,S,
    S,r,r,r,r,r,r,r,r,S,
    S,r,r,r,r,r,r,r,r,S,
    S,r,r,r,r,r,r,r,r,S,
    S,r,r,r,r,r,r,r,r,S,
    S,r,r,r,r,r,r,r,r,S,
    S,r,r,r,r,r,r,r,S,r,
    r,S,S,S,S,S,S,S,r,_,
};

void SpaceShipEarth::draw()
{
    uLCD.BLIT(ScreenObject::x_pos, ScreenObject::y_pos, EARTH_WIDTH, EARTH_HEIGHT,
              ship_sprite);
}

void SpaceShipEarth::explode()
{
    uLCD.BLIT(ScreenObject::x_pos, ScreenObject::y_pos, EARTH_WIDTH, EARTH_HEIGHT,
              explode_ship_sprite);
}

void SpaceShipEarth::update()
{
    uLCD.BLIT(ScreenObject::x_pos, ScreenObject::y_pos, EARTH_WIDTH, EARTH_HEIGHT,
              black_ship_sprite);
}

void SpaceShipEarth::moveRight(double moveDist)
{
    x_pos += moveDist;
}
void SpaceShipEarth::moveLeft(double moveDist)
{
    ScreenObject::x_pos -= moveDist;
}
void SpaceShipEarth::moveForward(double moveDist)
{
    ScreenObject::y_pos += moveDist;
}
void SpaceShipEarth::moveBackward(double moveDist)
{
    ScreenObject::y_pos -= moveDist;
}