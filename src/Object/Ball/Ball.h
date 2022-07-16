#ifndef __BALL_H__
#define __BALL_H__

#include "../GameObject.h"
class Ball : public GameObject
{
private:
    /* data */
public:
    Ball();
    virtual void render();
    virtual void update();
    virtual void clean();
    ~Ball();
};
#endif // __BALL_H__