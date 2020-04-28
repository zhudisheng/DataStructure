#include <iostream>
#include "Exception.h"
#include "Object.h"
#include "Smartpointer.h"
#include "List.h"
#include "StaticList.h"
#include "SeqList.h"
#include "DynamicList.h"


using namespace std;
using namespace ZXRLib;
int main()
{
    DynamicList<int> l(5);
    for(int i=0;i<l.capacity();i++)
    {
        l.insert(0,i);
    }
    for(int i=0;i<l.capacity();i++)
    {
        cout << l[i] << endl;
    }
    l[0] *= l[0];
    for(int i=0;i<l.capacity();i++)
    {
        cout << l[i] << endl;
    }
    try
    {
        l[5] = 5;
    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
        l.resize(10);
        l.insert(5,50);
    }
    for(int i=0;i<l.length();i++)
    {
        cout << l[i] << endl;
    }
    return 0;
    /*
    List<int> *l = NULL;
    SeqList<int> *sl = NULL;
    return 0;
    */
}


/*
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
    return 0;

}
*/
