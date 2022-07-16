#include "Timer.h"

Timer *Timer::s_Instance = nullptr;

Timer::Timer()
{
}

void Timer::Tick()
{
    m_DeltaTime = (clock() - m_LastTime) * (TARGET_FPS / 1000.0f);

    if (m_DeltaTime > TARGET_DELTATIME)
    {
        m_DeltaTime = TARGET_DELTATIME;
    }

    m_LastTime = clock();
}
