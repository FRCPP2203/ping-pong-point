#include "Input.h"
#include "../Engine/Engine.h"
#include <conio.h>
#include <windows.h>
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
            Engine::s_IsRunning = true;
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
