#ifndef __BALL_H__
#define __BALL_H__

#include "../GameObject.h"
#include "../../Screen/Screen.h"

class Ball : public GameObject
{
private:
    Vector2D<float> m_Velocity;
    Vector2D<float> m_Direction;
    Vector2D<float> m_originalPos;
    int m_random;

public:
    // default constructor
    Ball();
    Ball(Vector2D<float> p_Pos);
    // render ball object
    virtual void render();
    // update ball object
    virtual void update(float p_DeltaTime);
    // clean ball object
    virtual void clean();

    void setPosition(Vector2D<float> p_Pos);
    Vector2D<float> getPosition();
    Vector2D<float> randDirection();
    void Reset();
    ~Ball();
};
#endif // __BALL_H__