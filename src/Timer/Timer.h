#ifndef __TIMER_H__
#define __TIMER_H__

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
    inline float GetDeltaTime()
    {
        return m_DeltaTime;
    }
    inline static Timer *GetInstance()
    {
        return s_Instance = (s_Instance == nullptr) ? new Timer() : s_Instance;
    }
    ~Timer();
};
#endif // __TIMER_H__