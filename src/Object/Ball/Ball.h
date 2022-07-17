#ifndef __BALL_H__
#define __BALL_H__

#include "../GameObject.h"
#include "../../Screen/Screen.h"

class Ball : public GameObject
{
private:
    /* data */
    Vector2D<int> m_posBall;                    //position of ball
    Vector2D<int> m_originalPosBall;            //original position of ball
public:
    Ball();                         //default constructor
    Ball(Vector2D<int> posBall);
    // render ball object
    virtual void render(Screen *p_Screen);
    // update ball object
    virtual void update(float p_DeltaTime);
    // clean ball object
    virtual void clean();
    ~Ball();
};
#endif // __BALL_H__