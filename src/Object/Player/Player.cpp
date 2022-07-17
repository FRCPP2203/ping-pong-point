#include "Player.h"
Player::Player()
{
}

Player::Player(const char *p_Name, bool p_Left)
    : m_Name(p_Name), m_Left(p_Left)
{
}

void Player::render(Screen *p_Screen)
{
    char l = m_Left ? ']' : '[';
    int bar_height = 5;
    int draw_at = m_Left ?5 : 76;

    for(int i = 1; i <= bar_height; i++)
    {
        p_Screen->GoTo(draw_at, 5 + i);
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
