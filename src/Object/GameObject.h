#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "IObject.h"
#include "../Physics/Transform.h"
#include "../Physics/Vector2D.h"
#include "../Screen/Screen.h"

class GameObject : public IObject
{
protected:
    const char *m_ObjID;
    Transform *m_Transform;

public:
    GameObject() {}
    GameObject(const char *p_ObjID, Vector2D<float> p_Pos)
        : m_ObjID(p_ObjID)
    {
        m_Transform = new Transform(p_Pos.m_X, p_Pos.m_Y);
    }
    virtual void render() = 0;
    virtual void update(float p_DeltaTime) = 0;
    virtual void clean() = 0;
};
#endif // __GAMEOBJECT_H__