#ifndef __ENGINE_H__
#define __ENGINE_H__

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

    bool IsRunning();
    // global functions
    inline static Engine *GetInstance();
    ~Engine();
};
#endif // __ENGINE_H__