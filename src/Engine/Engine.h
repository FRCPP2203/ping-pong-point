#ifndef __ENGINE_H__
#define __ENGINE_H__
#define _WINDOW_WIDTH 80
#define _WINDOW_HEIGHT 45
#include <conio.h>
#include <windows.h>
class Engine
{
private:
    Engine();
    // global variables
    static Engine *s_Instance;

public:
    // Create window and objects
    void Init(const char *p_Title, SHORT p_W, SHORT p_H);
    // Creat Menu
    void Menu();
    // clean menu
    void CleanMenu();
    // Game loop
    void Loop();
    // Game render Entities and Map
    void Render();
    // Game Update by Delta Time
    void Update();
    // Game clean
    void Clean();
    // Game Quit
    void Quit();

    // handle events
    void HandleEvents();
    //
    bool IsPausing();
    bool IsRunning();
    // global functions and variables
    inline static Engine *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance;
    }

    static int s_State;
    static bool s_IsPausing;
    static bool s_IsRunning;
    ~Engine();
};
#endif // __ENGINE_H__