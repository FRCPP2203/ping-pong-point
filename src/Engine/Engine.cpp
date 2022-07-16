#include "Engine.h"
#include "../Timer/Timer.h"
Engine *Engine::s_Instance = nullptr;
bool Engine::s_IsRunning = false;

Engine::Engine()
{
}

void Engine::Init()
{
    // create windows

    // init Map or Entities
}

void Engine::Loop()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    // Is running
    while (IsRunning())
    {
    }
}

void Engine::Render()
{
}

void Engine::Update()
{
}

void Engine::Clean()
{
}

void Engine::Quit()
{
}

bool Engine::IsRunning()
{
    return s_IsRunning;
}

Engine *Engine::GetInstance()
{
    return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance;
}

Engine::~Engine()
{
}
