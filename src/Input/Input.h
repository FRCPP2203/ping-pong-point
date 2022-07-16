#ifndef __INPUT_H__
#define __INPUT_H__

class Input
{
private:
    Input();
    void KeyUp();
    void KeyDown();
    // const Uint8 *m_KeyStates;
    // global variables
    static Input *s_Instance;

public:
    inline static Input *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Input() : s_Instance;
    }
    void Listen();
    // bool GetKeyDown(SDL_Scancode key);
    ~Input();
};
#endif // __INPUT_H__