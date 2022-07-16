#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL.h>

class Timer
{
private:
    Timer();
    ~Timer();
    // global variables
    float mDeltaTime;
    float mTimeScale;
    unsigned int mStartTicks; //m_LastTime;
    unsigned int mElapsedTicks;

    static Timer* sInstance;

public:

    static Timer* Instance();
    static void Release();

    void Reset();
    float Timescale();
    void Update();

/*
    void Tick();
    inline float GetDeltaTime()
    {
        return m_DeltaTime;
    }
    inline static Timer *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Timer() : s_Instance;
    }
    ~Timer();
*/

};
#endif // __TIMER_H__