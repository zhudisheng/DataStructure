#include <iostream>
#include "Exception.h"
#include "Object.h"
#include "Smartpointer.h"

using namespace std;
using namespace ZXRLib;
class Test:public Object
{
public:
    int i;
    int j;
};
class Child:public Test
{
public:
    int k;
};

int main(int argc, char *argv[])
{


    SmartPointer<int> *sp = new SmartPointer<int>();
    delete sp;
    /*
    Object* obj1 = new Test();
    Object* obj2 = new Child();
    cout << "obj1 = " << obj1 << endl;
    cout << "obj2 = " << obj2 << endl;
    delete obj1;
    delete obj2;
    */
    /*
    try
    {
        //throw Exception("test",__FILE__,__LINE__);
        THROW_EXCEPTION(ArithmetricException,"test");
    }
    catch(const Exception& e)
    {
        cout << "catch(const Exception& e)"<<endl;
        cout << e.message()<<endl;
        cout << e.location()<<endl;
    }
    catch(const ArithmetricException& e)
    {
        cout << "catch(const ArithmerticException& e)"<<endl;
        cout << e.message()<<endl;
        cout << e.location()<<endl;
    }
    */
    return 0;

}
