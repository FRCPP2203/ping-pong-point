#include "Ball.h"
#include <time.h>

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
    m_Direction = randDirection();
}

void Ball::render()
{
    Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y);
    std::cout << "O";
    // std::cout << m_Transform->m_Position.m_X << " " << m_Transform->m_Position.m_Y;
}

void Ball::update(float p_DeltaTime)
{
    Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y);
    std::cout << " ";
    // BALL MOVE
    m_Transform->m_Position += m_Velocity;
    // RIGHT WALL AND LEFT WALL
    if (m_Transform->m_Position.m_X < 6 || m_Transform->m_Position.m_X > 74)
    {
        m_Velocity.m_X = -m_Velocity.m_X;
        m_Transform->m_Position.m_X += m_Velocity.m_X;
    }
    // TOP WALL AND BOTTOM WALL
    if (m_Transform->m_Position.m_Y < 3 || m_Transform->m_Position.m_Y > 22)
    {
        m_Velocity.m_Y = -m_Velocity.m_Y;
        m_Transform->m_Position.m_Y += m_Velocity.m_Y;
    }
}
void Ball::clean()
{
}

void Ball::setPosition(Vector2D<float> p_Pos)
{
    m_Transform->m_Position = p_Pos;
}

Vector2D<float> Ball::getPosition()
{
    return m_Transform->m_Position;
}

Vector2D<float> Ball::randDirection()
{
    srand(time(0));

    int random = rand() % 4 + 1;
    switch (random)
    {
    case 1:
        return DOWNLEFT;
    case 2:
        return UPLEFT;
    case 3:
        return UPRIGHT;
    case 4:
        return DOWNRIGHT;
    default:
        return DOWNRIGHT;
    }
}

Ball::~Ball()
{
}
