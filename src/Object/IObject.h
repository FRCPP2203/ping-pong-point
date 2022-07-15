#ifndef __IOBJECT_H__
#define __IOBJECT_H__

// Object Interface
class IObject
{
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};
#endif // __IOBJECT_H__