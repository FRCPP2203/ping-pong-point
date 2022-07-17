#include "Ball.h"
#define STOP         Vector2D<float>(0, 0)
#define LEFT         Vector2D<float>(-1, 0)
#define UPLEFT       Vector2D<float>(-1, -1)
#define DOWNLEFT     Vector2D<float>(-1, 1)
#define RIGHT        Vector2D<float>(1, 0)
#define UPRIGHT      Vector2D<float>(1, -1)
#define DOWNRIGHT    Vector2D<float>(1, 1)

Ball::Ball()
{
}

Ball::Ball(Vector2D<float> p_Pos)
:GameObject("ball",p_Pos)
{
}

void Ball::render(Screen *p_Screen)
{
    p_Screen->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y);
    std::cout << "O";
}

void Ball::update(float p_DeltaTime)
{
    m_Transform->m_Position += UPRIGHT;
    m_Transform->m_Position += STOP;
}
void Ball::clean()
{
}

Ball::~Ball()
{
}
