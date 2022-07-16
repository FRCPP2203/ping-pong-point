#include "Engine.h"
#include "../Screen/Screen.h"
#include "../Timer/Timer.h"
#include "../Object/Player/Player.h"
#include "../Object/Ball/Ball.h"

Engine *Engine::s_Instance = nullptr;
Screen *Screen::s_Instance = nullptr;
bool Engine::s_IsRunning = false;
Player *l_Player = nullptr;
Player *r_Player = nullptr;
Ball *ball = nullptr;

Engine::Engine()
{
}

void Engine::Init(const char *p_Title, SHORT p_W, SHORT p_H)
{
    // Create Window
    Screen::GetInstance()->Init("Ping Pong Game");
    Screen::GetInstance()->DisableCtrButton(0, 1, 1);
    Screen::GetInstance()->SetWindowSize(60, 20);
    Screen::GetInstance()->DisableResizeWindow();
    Screen::GetInstance()->ShowScrollbar(0);
    Screen::GetInstance()->HideCurSor(1);
    /*
    Screen::GetInstance()->SetScreenBufferSize(100, 100);
    */

    // init Players(Bars) and Ball
    l_Player = new Player("Tin");
    r_Player = new Player("Dat");
    ball = new Ball();

    s_IsRunning = true;
}

void Engine::Loop()
{
    // delta time = (current time - last time) / 1000
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    // Is running
    while (IsRunning())
    {
        HandleEvents();
        Update();
        Render();
    }
}

void Engine::Render()
{
    l_Player->render();
    r_Player->render();
    ball->render();
}

void Engine::Update()
{
    l_Player->update();
    r_Player->update();
    ball->update();
}

void Engine::Clean()
{
    l_Player->clean();
    r_Player->clean();
    ball->clean();
}

void Engine::Quit()
{
    exit(0);
}

void Engine::HandleEvents()
{
}

bool Engine::IsRunning()
{
    return s_IsRunning;
}

Engine::~Engine()
{
}
