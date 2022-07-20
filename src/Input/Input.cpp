#include "Input.h"
#include "../Engine/Engine.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "../Screen/Screen.h"
Input *Input::s_Instance = nullptr;

Input::Input()
{
}

void Input::Listen()
{
    if (_kbhit())
    {
        char keyBoard = _getch();
        switch (keyBoard)
        {
        case 27:
        case 'q':
        case 'Q':
            Engine::s_IsRunning = false;
            break;
        case 'b':
        case 'B':
            Engine::s_State = 2;
            break;
        case 'p':
        case 'P':
            if (Engine::s_State > 0)
                Engine::s_IsPausing = true;
            break;
        case 'r':
        case 'R':
            Engine::s_State = 2;
            Engine::s_IsPausing = false;
            break;
        default:
            break;
        }
    }
}

bool Input::GetKeyDown(int key)
{
    if (GetKeyState(key) & 0x8000)
    {
        return 1;
    }
    return 0;
}

Input::~Input()
{
}
