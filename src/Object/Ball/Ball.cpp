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
    m_originalPos = p_Pos;
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
    // BALL MOVE
    m_Transform->m_Position += m_Direction;
    // RIGHT WALL AND LEFT WALL
    if (m_Transform->m_Position.m_X < 7 || m_Transform->m_Position.m_X > 74)
    {
        m_Velocity.m_X = -m_Velocity.m_X;
        m_Direction.m_X *= m_Velocity.m_X;
    }
    // TOP WALL AND BOTTOM WALL
    if (m_Transform->m_Position.m_Y < 3 || m_Transform->m_Position.m_Y > 22)
    {
        m_Velocity.m_Y = -m_Velocity.m_Y;
        m_Direction.m_Y *= m_Velocity.m_Y;
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

void Ball::Reset()
{
    srand(time(NULL));
    m_Transform->m_Position.m_X = m_originalPos.m_X;
    m_Transform->m_Position.m_Y = m_originalPos.m_Y;
    m_random = rand() % 6 + 2;
    switch (m_random)
    {
    case 2:
        m_Velocity = UPLEFT;
        break;
    case 3:
        m_Velocity = DOWNLEFT;
        break;
    case 4:
        m_Velocity = RIGHT;
        break;
    case 5:
        m_Velocity = UPRIGHT;
        break;
    case 6:
        m_Velocity = DOWNRIGHT;
        break;
    default:
        break;
    }
}

Ball::~Ball()
{
}
