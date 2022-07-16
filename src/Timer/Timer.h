#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>
#include <ctime>
class Timer
{
private:
    Timer();

    // global variables
    float m_DeltaTime;
    float m_LastTime;
    static Timer *s_Instance;

public:
    void Tick();
    inline float GetDeltaTime();
    inline static Timer *GetInstance();
    ~Timer();
};
#endif // __TIMER_H__