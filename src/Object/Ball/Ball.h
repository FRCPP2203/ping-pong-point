#ifndef __BALL_H__
#define __BALL_H__

#include "../GameObject.h"
#include "../../Screen/Screen.h"

class Ball : public GameObject
{
private:

    
public:
    //default constructor
    Ball();
    Ball(Vector2D<float> p_Pos);
    // render ball object
    virtual void render(Screen *p_Screen);
    // update ball object
    virtual void update(float p_DeltaTime);
    // clean ball object
    virtual void clean();
    ~Ball();
};
#endif // __BALL_H__