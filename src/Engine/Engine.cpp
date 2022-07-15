#include "Engine.h"

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
    // Is running
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

Engine *Engine::GetInstance()
{
    return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance;
}

Engine::~Engine()
{
}
