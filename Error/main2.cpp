#include <iostream>
#include "LinkList.h"

using namespace std;
using namespace ZXRLib;

class Test:public Object
{
    int i;
public:
    Test(int v = 0)
    {
        i=v;
    }
    bool operator == (const Test&obj)
    {
        return this->i == obj.i;
    }
};
int main()
{

    //LinkList<Test> list1;
    //Test t;
    //list1.insert(t);
    //cout << "D.T.Software..." << endl;
    Test t1(1);
    Test t2(2);
    Test t3(3);
    LinkList<Test> list1;
    list1.insert(t1);
    list1.insert(t2);
    list1.insert(t3);
    cout << list1.find(t2)<<endl;
    LinkList<int> list;
    for(int i = 0;i < 5;i++)
    {
        list.insert(0,i);
        //list.set(0,i*i);
    }
    cout << list.find(-3) << endl;
    /*
    for(int i = 0;i<list.length();i++)
    {
        cout << list.get(i) << endl;
    }
    list.remove(2);
    for(int i = 0;i<list.length();i++)
    {
        cout << list.get(i) << endl;
    }
    */
    return 0;
}
