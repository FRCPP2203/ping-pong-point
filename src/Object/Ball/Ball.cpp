#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(Vector2D<int> posBall)
{
    m_originalPosBall = posBall;
    m_posBall = posBall;
    
}

void Ball::render(Screen *p_Screen)
{
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
