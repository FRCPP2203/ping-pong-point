#ifndef __IOBJECT_H__
#define __IOBJECT_H__

#include "../Screen/Screen.h"
// Object Interface
class IObject
{
public:
    virtual void render(Screen *p_Screen) = 0;
    virtual void update(float p_DeltaTime) = 0;
    virtual void clean() = 0;
};
#endif // __IOBJECT_H__