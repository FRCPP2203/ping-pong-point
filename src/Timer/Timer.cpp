#include "Timer.h"

Timer *Timer::s_Instance = nullptr;
Timer::Timer()
{
}

void Timer::Tick()
{
}

inline float Timer::GetDeltaTime()
{
    return m_DeltaTime;
}

Timer *Timer::GetInstance()
{
    return s_Instance = (s_Instance == nullptr) ? new Timer() : s_Instance;
}

Timer::~Timer()
{
}
