#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <windows.h>
#include "../GameObject.h"
#include "../../Screen/Screen.h"
#include "../Ball/Ball.h"
class Player : public GameObject
{
private:
    const char *m_Name;
    int m_Score = 0;

public:
    Player();
    Player(const char *p_Name, Vector2D<float> p_Pos);
    // render player object
    virtual void render();
    // update player object
    virtual void update(float p_DeltaTime);
    // clean  player object
    virtual void clean();

    // count score
    void countScore(Ball &p_Ball);

    ~Player();
};
#endif // __PLAYER_H__