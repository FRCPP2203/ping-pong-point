#include "Engine.h"
#include "../Screen/Screen.h"
#include "../Timer/Timer.h"
#include "../Input/Input.h"
#include "../Object/Player/Player.h"
#include "../Object/Ball/Ball.h"
#include <fstream>
#include <time.h>
#include <windows.h>

std::ofstream record("res/delta_time.txt");
Engine *Engine::s_Instance = nullptr;
Screen *Screen::s_Instance = nullptr;
bool Engine::s_IsRunning = false;
Player *l_Player = nullptr;
Player *r_Player = nullptr;
Ball *ball = nullptr;
int i;

Engine::Engine()
{
}

void Engine::Init(const char *p_Title, SHORT p_W, SHORT p_H)
{
    // Create Window
    Screen::GetInstance()->Init(p_Title);
    Screen::GetInstance()->SetWindowSize(p_W, p_H);
    Screen::GetInstance()->SetScreenBufferSize(p_W, p_H);
    Screen::GetInstance()->DisableCtrButton(0, 1, 1);
    Screen::GetInstance()->DisableResizeWindow();
    Screen::GetInstance()->ShowScrollbar(0);
    Screen::GetInstance()->HideCurSor(1);
    // draw borders
    for (i = 2; i < _WINDOW_WIDTH; i++)
    {
        // draw top side
        Screen::GetInstance()->GoTo(i, 1);
        std::cout << "\xDB";
        // draw bottom side
        Screen::GetInstance()->GoTo(i, _WINDOW_HEIGHT - 1);
        std::cout << "\xDB";
    }
    for (i = 1; i < _WINDOW_HEIGHT; i++)
    {
        // draw left side
        Screen::GetInstance()->GoTo(2, i);
        std::cout << "\xDB";
        // draw right side
        Screen::GetInstance()->GoTo(_WINDOW_WIDTH - 1, i);
        std::cout << "\xDB";
    }
    // init Players(Bars) and Ball
    l_Player = new Player("Tin", Vector2D<float>(5, p_H));
    r_Player = new Player("Dat", Vector2D<float>(76, p_H));
    ball = new Ball(Vector2D<float>(p_W / 2, p_H / 2));
    s_IsRunning = true;
}

void Engine::Loop()
{

    const int frameDelay = 1000 / TARGET_FPS;

    uint32_t frameStart;
    int frameTime;
    // Is running
    while (IsRunning())
    {

        frameStart = clock();
        HandleEvents();
        Update();
        Render();
        Timer::GetInstance()->Tick();

        frameTime = clock() - frameStart;
        if (frameDelay > frameTime)
        {
            Sleep(frameDelay - frameTime); // delay a moment = frameDelay - frameTime;
        }
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
    float dt = Timer::GetInstance()->GetDeltaTime();
    record << dt << "\n";
    l_Player->update(dt);
    r_Player->update(dt);
    ball->update(dt);
}

void Engine::Clean()
{
    l_Player->clean();
    r_Player->clean();
    ball->clean();
}

void Engine::Quit()
{
    record.close();
    exit(0);
}

void Engine::HandleEvents()
{
    Input::GetInstance()->Listen();
}

bool Engine::IsRunning()
{
    return s_IsRunning;
}

Engine::~Engine()
{
}
