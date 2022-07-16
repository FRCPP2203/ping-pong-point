#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <conio.h>
#include <windows.h>
class Engine
{
private:
    Engine();
    // global variables
    static Engine *s_Instance;
    static bool s_IsRunning;

public:
    // Create window and objects
    void Init();
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
    bool IsRunning();
    // global functions
    inline static Engine *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance;
    }
    ~Engine();
};
#endif // __ENGINE_H__