#include "Player.h"
Player::Player()
{
}

Player::Player(const char *p_Name, Vector2D<float> p_Pos)
    : GameObject(p_Name, p_Pos)
{
}

void Player::render(Screen *p_Screen)
{
    char l = '-';
    int bar_height = 5;
    for (int i = 1; i <= bar_height; i++)
    {
        p_Screen->GoTo(m_Transform->m_Position.m_X, (m_Transform->m_Position.m_Y - 5) / 2 + i);
        std::cout << l;
    }
}

void Player::update(float p_DeltaTime)
{
}

void Player::clean()
{
}

Player::~Player()
{
}
