#ifndef __INPUT_H__
#define __INPUT_H__

class Input
{
private:
    Input();
    // global variables
    static Input *s_Instance;

public:
    inline static Input *GetInstance();
    ~Input();
};
#endif // __INPUT_H__