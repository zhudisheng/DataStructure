#include <iostream>
#include "staticarray.h"
#include "Object.h"
#include <ctime>
#include "Sort.h"

using namespace std;
using namespace ZXRLib;
struct Test:public Object
{
    int key1;
    int key2;

    Test(int k1,int k2)
    {
        key1 = k1;
        key2 = k2;
    }
    bool operator == (const Test& t)
    {
        return (key1 == t.key1)&&(key2 == t.key2);
    }

    bool operator != (const Test& t)
    {
        return !(*this == t);
    }
    bool operator < (const Test& t)
    {
        return (key1 < t.key1)||(key1 == t.key1)&&((key2 == t.key2));
    }
    bool operator >= (const Test& t)
    {
        return !(*this < t);
    }
    bool operator > (const Test& t)
    {
        return (key1 > t.key1)||((key1 == t.key1)&&(key2 > t.key2));
    }
    bool operator <= (const Test& t)
    {
        return !(*this > t);
    }
};
struct Test1:public Object
{
    int id;
    int data1[1000];
    double data2[500];
    bool operator < (const Test1& obj)
    {
        return id < obj.id;
    }
    bool operator >= (const Test1& obj)
    {
        return id >= obj.id;
    }
    bool operator > (const Test1& obj)
    {
        return id > obj.id;
    }
    bool operator <=(const Test1& obj)
    {
        return id <= obj.id;
    }
};
class TestProxy:public Object
{
protected:
    Test1* m_pTest;
public:
    /*
    TestProxy(Test1* pTest)
    {
        m_pTest = pTest;
    }
    */
    int id()
    {
        return m_pTest->id;
    }
    int* data1()
    {
        return m_pTest->data1;
    }
    double* data2()
    {
        return m_pTest->data2;
    }
    Test1& test()const
    {
        return *m_pTest;
    }
    bool operator < (const TestProxy& obj)
    {
        return test()< obj.test();
    }
    bool operator >= (const TestProxy& obj)
    {
        return test() >= obj.test();
    }
    bool operator > (const TestProxy& obj)
    {
        return test() > obj.test();
    }
    bool operator <=(const TestProxy& obj)
    {
        return test() <= obj.test();
    }
    Test1& operator= (Test1& test)
    {
        m_pTest = &test;
        return test;
    }
};
Test1 t[1000];
TestProxy pt[1000];
int main()
{
    clock_t begin = 0;
    clock_t end = 0;
    for(int i = 0;i < 1000;i++)
    {
        t[i].id = i;
        pt[i] = t[i];
    }
    begin = clock();
    Sort::Bubble(pt,1000,false);
    end = clock();

    cout << "Time:" << end-begin << endl;
    for(int i =0;i < 1000;i++)
    {
        cout << t[i].id << " " << pt[i].id() << endl;
    }
}
int main1()
{

    StaticArray<double,5> sa;
    for(int i=0;i < 5;i++)
    {
        sa[i] = i;
    }
    Sort::Insert(sa,false);
    /*
     *
    int array[] = {3,1,2,5,4};
    Sort::Quick(array,5,false);
    */
    //Sort::Bubble(array,5,false);
    //Sort::Insert(array,5,false);
    for(int i = 0;i < 5;i++)
    {
        cout << sa[i] << endl;
    }
   //Test t1(3,4);
    //Test t2(3,5);
    //cout << (t1>t2) << endl;
    return 0;
}
