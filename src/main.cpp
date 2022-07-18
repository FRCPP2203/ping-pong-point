#include <iostream>
#include "Engine/Engine.h"

int main(int, char **)
{
    Engine::GetInstance()->Init("Ping Pong Game", _WINDOW_WIDTH, _WINDOW_HEIGHT);
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();
    return 0;
}
