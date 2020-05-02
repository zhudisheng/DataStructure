#include <iostream>
#include "linklist.h"
#include "StaticLinkList.h"
#include "Exception.h"
#include "SmartPointer.h"
#include "sharedpointer.h"

using namespace std;
using namespace ZXRLib;
class Test:public Object
{
public:
    int value;
    Test():value(0)
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()"<<endl;
    }
};
int main()
{
    const SharedPointer<Test> sp0 = new Test();
    SharedPointer<Test> sp1 = sp0;
    SharedPointer<Test> sp2 = NULL;
    sp2 = sp1;
    sp2->value = 100;
    cout << sp0->value << endl;
    cout << sp1->value << endl;
    cout << sp2->value << endl;
    cout << (sp0 == sp2) << endl;
    {
        SmartPointer<Test> sp = new Test();\
    }
    //SmartPointer<Test> spn;
    //spn = sp;
    /*
    LinkList<int>list;
    for(int i = 0;i < 5;i++)
    {
        list.insert(i);
    }
    for(list.move(0);!list.end();list.next())
    {
        cout << list.current()<<endl;
    }
    */
    return 0;
}
/*
int main()
{
    StaticLinkList<int,5> list;
    for(int i=0;i<5;i++)
    {
       list.insert(0,i);
    }
    try
    {
        list.insert(6);
    }catch(const Exception e)
    {
        cout << e.message() << endl;
    }

    for(list.move(0);!list.end();list.next())
    {
        cout << list.current()<<endl;
    }
    /*
    for(int i = 0;i<list.length();i++)
    {
        cout << list.get(i)<<endl;
    }
    return 0;
}
*/
