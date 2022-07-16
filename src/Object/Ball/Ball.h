#ifndef __BALL_H__
#define __BALL_H__

#include "../GameObject.h"
class Ball : public GameObject
{
private:
    /* data */
public:
    Ball();
    // render ball object
    virtual void render();
    // update ball object
    virtual void update();
    // clean ball object
    virtual void clean();
    ~Ball();
};
#endif // __BALL_H__