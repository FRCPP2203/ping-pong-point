#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__

#include "Vector2D.h"
class RigidBody
{
private:
    Vector2D<float> m_Position;

public:
    RigidBody();
    // Update methods
    void Update(float dt)
    {
        // m_Position = m_Velocity * dt;
    }
    ~RigidBody();
};
#endif // __RIGIDBODY_H__