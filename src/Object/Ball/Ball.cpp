#include "Ball.h"

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

}
void Ball::clean()
{
}

Ball::~Ball()
{
}
