#include "Ball.h"

#define STOP Vector2D<float>(0, 0)
#define LEFT Vector2D<float>(-1, 0)
#define UPLEFT Vector2D<float>(-1, -1)
#define DOWNLEFT Vector2D<float>(-1, 1)
#define RIGHT Vector2D<float>(1, 0)
#define UPRIGHT Vector2D<float>(1, -1)
#define DOWNRIGHT Vector2D<float>(1, 1)

Ball::Ball()
{
}

Ball::Ball(Vector2D<float> p_Pos)
    : GameObject("ball", p_Pos)
{
    m_Velocity = Vector2D<float>(1.0f, 1.0f);
    m_Direction = UPLEFT;
}

void Ball::render()
{
    Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y);
    std::cout << "O";
}

void Ball::update(float p_DeltaTime)
{
    Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y);
    std::cout << " ";
    m_Transform->m_Position += m_Direction;
    if (m_Transform->m_Position.m_X < 5 || m_Transform->m_Position.m_X > 76)
    {
        m_Velocity.m_X = -m_Velocity.m_X;
        m_Direction.m_X *= m_Velocity.m_X;
    }
    if (m_Transform->m_Position.m_Y < 3 || m_Transform->m_Position.m_Y > 22)
    {
        m_Velocity.m_Y = -m_Velocity.m_Y;
        m_Direction.m_Y *= m_Velocity.m_Y;
    }
}
void Ball::clean()
{
}

Ball::~Ball()
{
}
