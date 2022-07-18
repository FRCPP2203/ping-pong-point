#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <windows.h>
#include "../GameObject.h"
#include "../../Screen/Screen.h"

class Player : public GameObject
{
private:
    const char *m_Name;

public:
    Player();
    Player(const char *p_Name, Vector2D<float> p_Pos);
    // render player object
    virtual void render();
    // update player object
    virtual void update(float p_DeltaTime);
    // clean  player object
    virtual void clean();
    ~Player();
};
#endif // __PLAYER_H__