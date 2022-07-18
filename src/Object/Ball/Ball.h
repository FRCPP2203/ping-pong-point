#ifndef __BALL_H__
#define __BALL_H__

#include "../GameObject.h"
#include "../../Screen/Screen.h"

class Ball : public GameObject
{
private:
    Vector2D<float> m_Direction;
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
    virtual void ChangeDirection(Vector2D<float> direction);
    Vector2D<float> getDirection();
    Vector2D<float> getPosition();
    ~Ball();
};
#endif // __BALL_H__