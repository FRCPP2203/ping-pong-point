#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <iostream>
template <typename T>
class Vector2D
{
private:
    T m_X;
    T m_Y;
    inline Vector2D<T> &m_Add(const Vector2D<T> &p_Vec)
    {
        this->m_X += p_Vec.m_X;
        this->m_Y += p_Vec.m_Y;
        return *this;
    }
    inline Vector2D<T> &m_Subtract(const Vector2D<T> &p_Vec)
    {
        this->m_X -= p_Vec.m_X;
        this->m_Y -= p_Vec.m_Y;
        return *this;
    }
    inline Vector2D<T> &m_Multiply(const Vector2D<T> &p_Vec)
    {
        this->m_X *= p_Vec.m_X;
        this->m_Y *= p_Vec.m_Y;
        return *this;
    }
    inline Vector2D<T> &m_Divide(const Vector2D<T> &p_Vec)
    {
        this->m_X /= p_Vec.m_X;
        this->m_Y /= p_Vec.m_Y;
        return *this;
    }

public:
    Vector2D() : _X(0), m_Y(0) {}
    Vector2D(T p_X, T p_Y) : m_X(p_X), m_Y(p_y) {}

    friend Vector2D<T> &operator+(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Add(p_B);
    }
    friend Vector2D<T> &operator-(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Subtract(p_B);
    }
    friend Vector2D<T> &operator*(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Multiply(p_B);
    }
    friend Vector2D<T> &operator/(Vector2D<T> &p_A, const Vector2D<T> &p_B)
    {

        return p_A.m_Divide(p_B);
    }

    Vector2D<T> &operator+=(const Vector2D<T> &p_B)
    {
        return this->m_Add(p_B);
    }
    Vector2D<T> &operator-=(const Vector2D<T> &p_B)
    {
        return this->m_Subtract(p_B);
    }
    Vector2D<T> &operator*=(const Vector2D<T> &p_B)
    {
        return this->m_Multiply(p_B);
    }
    Vector2D<T> &operator/=(const Vector2D<T> &p_B)
    {
        return this->m_Divide(p_B);
    }

    friend std::ostream &operator<<(std::ostream output, const Vector2D &p_Vec)
    {
        output << "(X, Y) = (" << p_Vec.m_X << ", " << p_Vec.m_Y << ")\n";
        return output;
    }
};
#endif // __VECTOR2D_H__