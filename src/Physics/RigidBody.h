#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__
#define UNI_MASS 1.0f
#define GRAVITY 9.8f
#define FORWARD 1
#define BACKWARD -1
#define UPWARD -1
#define DOWNWARD 1
#include "Vector2D.h"

class RigidBody
{
private:
    float m_Mass;
    float m_Gravity;
    Vector2D<float> m_Force;
    Vector2D<float> m_Acceleration;
    Vector2D<float> m_Position;
    Vector2D<float> m_Velocity;
    Vector2D<float> m_Friction;

public:
    RigidBody()
    {
        m_Gravity = GRAVITY;
        m_Mass = UNI_MASS;
    }

    // Force
    inline void ApplyForce(Vector2D<float> p_force) { m_Force = p_force; }
    inline void ApplyForceX(float p_forceX) { m_Force.m_X = p_forceX; }
    inline void ApplyForceY(float p_forceY) { m_Force.m_Y = p_forceY; }
    inline void UnSetForce() { m_Force.Zeros(); }

    // Friction
    inline void ApplyFriction(Vector2D<float> p_friction) { m_Friction = p_friction; }
    inline void UnSetFriction() { m_Friction.Zeros(); }

    // Getters
    inline Vector2D<float> GetPosition() { return m_Position; }
    inline Vector2D<float> GetVelocity() { return m_Velocity; }
    inline Vector2D<float> GetAcceleration() { return m_Acceleration; }
    // Update methods
    void Update(float dt)
    {
        m_Acceleration.m_X = (m_Force.m_X + m_Friction.m_X) / m_Mass; /* a = Force/mass*/
        m_Acceleration.m_Y = m_Gravity + m_Force.m_Y / m_Mass;        /* weight = mass * gravity, drag = force,  a = (weight - drag)/m */
        m_Velocity = m_Acceleration * dt;
        m_Position = m_Velocity * dt;
    }
    ~RigidBody();
};
#endif // __RIGIDBODY_H__