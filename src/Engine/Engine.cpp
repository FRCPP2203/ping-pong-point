#include "Engine.h"
#include "../Screen/Screen.h"
#include "../Timer/Timer.h"
#include "../Input/Input.h"
#include "../Object/Player/Player.h"
#include "../Object/Ball/Ball.h"
#include <fstream>
/*
enum eDir{
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6
};
*/
#define STOP         Vector2D<float>(0, 0)
#define LEFT         Vector2D<float>(-1, 0)
#define UPLEFT       Vector2D<float>(-1, -1)
#define DOWNLEFT     Vector2D<float>(-1, 1)
#define RIGHT        Vector2D<float>(1, 0)
#define UPRIGHT      Vector2D<float>(1, -1)
#define DOWNRIGHT    Vector2D<float>(1, 1)

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
    Screen::GetInstance()->SetWindowSize(79, 30);
    Screen::GetInstance()->SetScreenBufferSize(79, 30);
    Screen::GetInstance()->DisableCtrButton(0, 1, 1);
    Screen::GetInstance()->DisableResizeWindow();
    Screen::GetInstance()->ShowScrollbar(0);
    Screen::GetInstance()->HideCurSor(1);

    // draw borders
    for (i = 2; i < p_W; i++)
    {
        // draw top side
        Screen::GetInstance()->GoTo(i, 1);
        std::cout << "\xDB";
        // draw bottom side
        Screen::GetInstance()->GoTo(i, p_H - 1);
        std::cout << "\xDB";
    }
    for (i = 1; i < p_H; i++)
    {
        // draw left side
        Screen::GetInstance()->GoTo(2, i);
        std::cout << "\xDB";
        // draw right side
        Screen::GetInstance()->GoTo(p_W - 1, i);
        std::cout << "\xDB";
    }

    Screen::GetInstance()->GoTo(4, 28);
    std::cout << "SCORE : 0";
    Screen::GetInstance()->GoTo(50, 28);
    std::cout << "Press Esc key to quit game";

    // init Players(Bars) and Ball
    l_Player = new Player("Tin", Vector2D<float>(5, p_H));
    r_Player = new Player("Dat", Vector2D<float>(76, p_H));
    ball = new Ball(Vector2D<float>(p_W / 2, p_H / 2));
    ball->ChangeDirection(DOWNRIGHT);
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
        CleanSystem();
        HandleEvents();
        Update();
        Render();
        Logic();
    }
}

void Engine::CleanSystem(){
    for(int i = 6; i < 78; i++){
        for(int j = 2; j < 25; j++){
            Screen::GetInstance()->GoTo(i, j);
            std::cout << " ";
        }
    }
}

void Engine::Render()
{
    l_Player->render(Screen::GetInstance());
    r_Player->render(Screen::GetInstance());
    ball->render(Screen::GetInstance());
}

void Engine::Logic()
{
    
    //Top wall
    if(ball->getPosition().m_Y == 2){
        ball->getDirection() -= UPRIGHT;
        ball->ChangeDirection( ball->getDirection().m_X == 0 && ball->getDirection().m_Y == 0 ? DOWNRIGHT : DOWNLEFT);
    }
    //Bottom wall
    if(ball->getPosition().m_Y == 24){
        ball->getDirection() -= DOWNRIGHT;
        ball->ChangeDirection( ball->getDirection().m_X == 0 && ball->getDirection().m_Y == 0 ? UPRIGHT : UPLEFT);
    }
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
