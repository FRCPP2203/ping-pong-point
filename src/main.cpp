#include <iostream>
#include <stdlib.h>
#include "Engine/Engine.h"
int main()
{
    Engine::GetInstance()->Init("Ping Pong Game", 80, 26);
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();
    return 0;
}
