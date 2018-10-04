#ifndef ScreenObject_H_
#define ScreenObject_H_
class ScreenObject
{
protected:
    int x_pos;
    int y_pos;

public:
    ScreenObject();
    virtual void setX_Pos(int s);
    virtual void setY_Pos(int s);
    virtual int getX_Pos();
    virtual int getY_Pos();
    virtual void draw() = 0;
    virtual void update() = 0;


}; //end class ScreenObject

#endif