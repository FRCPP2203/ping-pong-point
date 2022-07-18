#include <iostream>
#include "Engine/Engine.h"

char start = 'X';
int main()
{
    do
    {
        Engine::GetInstance()->Menu();
        // Sleep(5000);
        std::cin >> start;
        system("cls");
        if (start == 'B')
        {
            Engine::GetInstance()->Init("Ping Pong Game", 80, 26);
            Engine::GetInstance()->Loop();
            // Engine::GetInstance()->Clean();
            Engine::GetInstance()->Quit();
        }
        if (start == 'Q')
        {
            Engine::GetInstance()->Quit();
        }
    } while (start != 'B' || start != 'Q');
    return 0;
}
