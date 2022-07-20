#include "Player.h"
#include "../../Input/Input.h"
#include "../../Engine/Engine.h"
#include <conio.h>
#include <iostream>
Player::Player()
{
}

Player::Player(const char *p_Name, Vector2D<float> p_Pos)
    : GameObject(p_Name, p_Pos)
{
}

void Player::resetScore()
{
    m_Score = 0;
}

void Player::render()
{
    char l = '|';
    int bar_height = 5;
    for (int i = 1; i <= bar_height; i++)
    {
        Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y + i);
        // std::cout << m_Transform->m_Position.m_X << ":" << m_Transform->m_Position.m_Y;
        std::cout << l;
    }
    Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X - 4, 28);
    std::cout << "Score " << m_ObjID << ": " << m_Score;
}

void Player::update(float p_DeltaTime)
{
    int bar_height = 5;
    // Clean Player
    for (int i = 1; i <= bar_height; i++)
    {
        Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X, m_Transform->m_Position.m_Y + i);
        std::cout << ' ';
        // std::cout << "         ";
    }
    // Clear Score
    // Screen::GetInstance()->GoTo(m_Transform->m_Position.m_X + 7, 28);
    // std::cout << "   ";
    if (Input::GetInstance()->GetKeyDown('W'))
    {
        if (m_Transform->m_Position.m_Y > 1)
            m_Transform->TranslateY(UPWARD);
    }
    if (Input::GetInstance()->GetKeyDown('S'))
    {
        if (m_Transform->m_Position.m_Y < 20)
            m_Transform->TranslateY(DOWNWARD);
    }
}

void Player::clean()
{
}

void Player::countScore(Ball &p_Ball)
{
    Vector2D<float> tmp = p_Ball.getPosition();
    // RIGHT WALL AND LEFT WALL
    if (p_Ball.getPosition().m_X == m_Transform->m_Position.m_X && (p_Ball.getPosition().m_Y < m_Transform->m_Position.m_Y || p_Ball.getPosition().m_Y > m_Transform->m_Position.m_Y + 5))
    {
        p_Ball.setPosition(Vector2D<float>(40, 13));
    }
    // RIGHT PLAYER AND LEFT PLAYER
    else if (p_Ball.getPosition().m_X == m_Transform->m_Position.m_X && (p_Ball.getPosition().m_Y > m_Transform->m_Position.m_Y || p_Ball.getPosition().m_Y < m_Transform->m_Position.m_Y + 5))
    {
        p_Ball.setPosition(tmp);
        if (m_Score > 3)
        {
            Screen::GetInstance()->GoTo(35, 28);
            std::cout << "PLAYER WIN: " << m_ObjID;
            Engine::s_IsPausing = true;
        }
        else
            m_Score += 1;
    }
}

Player::~Player()
{
}
