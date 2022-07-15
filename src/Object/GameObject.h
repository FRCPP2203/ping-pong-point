#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "IObject.h"
class GameObject
{
private:
    /* data */
public:
    GameObject(/* args */) {}
    ~GameObject() {}
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};
#endif // __GAMEOBJECT_H__