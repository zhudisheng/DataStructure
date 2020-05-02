#ifndef _OBJECT_H_
#define _OBJECT_H_


namespace ZXRLib
{
class Object
{
public:
    void* operator new (unsigned int size) throw();
    void  operator delete(void *p);
    void* operator new[](unsigned int size)throw();
    void  operator delete[](void* p);
    bool  operator == (const Object& object);
    bool  operator != (const Object& object);
    virtual ~Object() = 0;
};
}

#endif // OBJECT_H
