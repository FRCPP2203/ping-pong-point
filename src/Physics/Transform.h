#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Vector2D.h"
class Transform
{
private:
    Vector2D<float> m_Position;

public:
    Transform() {}
    ~Transform() {}
};
#endif // __TRANSFORM_H__