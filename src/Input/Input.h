#ifndef __INPUT_H__
#define __INPUT_H__
#include <windows.h>
class Input
{
private:
    Input();
    // global variables
    static Input *s_Instance;

public:
    inline static Input *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Input() : s_Instance;
    }
    void Listen();
    bool GetKeyDown(int key);
    ~Input();
};
#endif // __INPUT_H__