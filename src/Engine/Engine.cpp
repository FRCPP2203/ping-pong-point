#include "Engine.h"
#include "../Timer/Timer.h"
#include "../Object/Player/Player.h"
#include "../Object/Ball/Ball.h"

Engine *Engine::s_Instance = nullptr;
bool Engine::s_IsRunning = false;
Player *l_Player = nullptr;
Player *r_Player = nullptr;
Ball *ball = nullptr;


Engine::Engine()
{
}

void Engine::Init()
{
    // create windows

    // init Players(Bars) and Ball
    l_Player = new Player("Tin");
    r_Player = new Player("Dat");
    ball = new Ball();
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
