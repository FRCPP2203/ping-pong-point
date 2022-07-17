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
        case 'q':
        case 'z':
            Engine::s_IsRunning = false;
            break;
        
        default:
            break;
        }
    }
}

Input::~Input()
{
}
