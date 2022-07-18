#ifndef __TIMER_H__
#define __TIMER_H__

#include "time.h"
const int TARGET_FPS = 15;
const float TARGET_DELTATIME = 1.5f;
class Timer
{
private:
    float m_DeltaTime;
    float m_LastTime;
    static Timer *s_Instance;

public:
    Timer();
    void Tick();
    inline float GetDeltaTime()
    {
        return m_DeltaTime;
    }
    inline static Timer *GetInstance()
    {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer();
    };
};
#endif // __TIMER_H__