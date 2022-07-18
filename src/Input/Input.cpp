#include "Input.h"
#include "../Engine/Engine.h"
#include <conio.h>
#include <windows.h>
Input *Input::s_Instance = nullptr;

Input::Input()
{
}

void Input::KeyUp()
{
}

void Input::KeyDown()
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
            Engine::s_IsRunning = false;
            break;

        default:
            break;
        }
    }
}

bool Input::GetKeyDown(char key)
{
    return 1;
}

Input::~Input()
{
}
