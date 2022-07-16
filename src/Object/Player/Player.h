#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../GameObject.h"
class Player : public GameObject
{
private:
    /* data */
public:
    Player();
    // render player object
    virtual void render();
    // update player object
    virtual void update();
    // clean  player object
    virtual void clean();
    ~Player();
};
#endif // __PLAYER_H__