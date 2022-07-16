#include "Player.h"
Player::Player()
{
}

Player::Player(char *p_Name)
:m_Name(p_Name)
{
    std::cout << "Player: " << p_Name << "" << std::endl;
}

void Player::render()
{
}

void Player::update()
{
}

void Player::clean()
{
}

Player::~Player()
{
}
