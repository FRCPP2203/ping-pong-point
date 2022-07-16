#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "../GameObject.h"
class Player : public GameObject
{
private:
    const char *m_Name;

public:
    Player();
    Player(const char *p_Name);
    // render player object
    virtual void render();
    // update player object
    virtual void update();
    // clean  player object
    virtual void clean();
    ~Player();
};
#endif // __PLAYER_H__