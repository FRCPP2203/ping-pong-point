#ifndef __ENGINE_H__
#define __ENGINE_H__

class Engine
{
private:
    // global
    static Engine *s_Instance;

public:
    Engine();
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
    // global
    static Engine *GetInstance();
    ~Engine();
};
#endif // __ENGINE_H__