#include <iostream>
#include "Engine/Engine.h"
int main(int, char **)
{
    Engine::GetInstance()->Init("DEMO", 60, 10);
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();
    return 0;
}
