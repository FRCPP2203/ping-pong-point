#include "Player.h"
#include "../../Input/Input.h"
#include <conio.h>
#include <iostream>
Player::Player()
{
}

Player::Player(const char *p_Name, Vector2D<float> p_Pos)
    : GameObject(p_Name, p_Pos)
{
}

void Player::render()
{
    char l = '|';
    int bar_height = 5;
    for (int i = 1; i <= bar_height; i++)
    {
        Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y + i);
        std::cout << l;
        std::cout << m_Transform->m_Position.m_X << " " << m_Transform->m_Position.m_Y + i;
    }
}

void Player::update(float p_DeltaTime)
{
    int bar_height = 5;
    for (int i = 1; i <= bar_height; i++)
    {
        Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y + i);
        std::cout << ' ';
        std::cout << "      ";
    }
    if (Input::GetInstance()->GetKeyDown('W'))
    {   
        if(m_Transform->m_Position.m_Y > 1)
            m_Transform->TranslateY(UPWARD);
    }
    if (Input::GetInstance()->GetKeyDown('S'))
    {
        if(m_Transform->m_Position.m_Y < 19)
            m_Transform->TranslateY(DOWNWARD);
    }
}

void Player::clean()
{
}

void Player::countScore(Ball &p_Ball)
{
    /*
    if (p_Ball.getPosition().m_X == m_Transform->m_Position.m_X && (p_Ball.getPosition().m_Y < m_Transform->m_Position.m_Y || p_Ball.getPosition().m_Y > m_Transform->m_Position.m_Y + 4))
    {   
        p_Ball.setPosition(Vector2D<float>(40, 13));
    }
    else if (p_Ball.getPosition().m_X == m_Transform->m_Position.m_X && (p_Ball.getPosition().m_Y > m_Transform->m_Position.m_Y || p_Ball.getPosition().m_Y < m_Transform->m_Position.m_Y + 4))
    {
        if (m_Score > 1)
        {
            m_Score = 0;
        }
        m_Score += 1;
    }
    */
    
}

Player::~Player()
{

}
