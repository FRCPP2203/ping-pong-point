#include "Engine.h"

Engine::Engine()
{
}

void Engine::Init()
{
}

Engine *Engine::GetInstance()
{
    return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance;
}

Engine::~Engine()
{
}
