#include "Object.h"
#include <cstdlib>
#include <iostream>
using namespace std;

namespace ZXRLib
{
void *Object::operator new(unsigned int size)throw()
{
    cout << "Object::operator new "<< size << endl;
    return malloc(size);
}
void Object::operator delete(void *p)
{
    cout << "Object::operator delete "<<endl;
    free(p);
}
void* Object::operator new[] (unsigned int size)throw()
{
    return malloc(size);
}
void Object::operator delete[](void *p)
{
    free(p);
}
Object::~Object()
{

}
}
