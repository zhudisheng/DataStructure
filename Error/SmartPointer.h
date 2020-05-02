#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_
#include "Pointer.h"

namespace ZXRLib
{
template <typename T>
class SmartPointer : public Pointer<T>
{
protected:
    T* m_pointer;
public:
    SmartPointer(T* p = nullptr):Pointer<T>(p)
    {
            m_pointer = p;
    }
    SmartPointer(const SmartPointer<T>& obj)
    {
        this->m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }
    SmartPointer<T>& operator=(const SmartPointer<T>& obj)
    {
        if(this != &obj)
        {
            T *p = this->m_pointer;
            this->m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
            delete p;
        }
        return *this;
    }
    ~SmartPointer()
    {
        delete this->m_pointer;
    }

};

}


#endif // SMARTPOINTER_H
