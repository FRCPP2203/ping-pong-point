#include <iostream>
#include "Engine/Engine.h"
int main(int, char **)
{
    Engine::GetInstance()->Init();
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();
}
