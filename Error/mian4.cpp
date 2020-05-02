#include <iostream>
#include "linklist.h"

using namespace std;
using namespace ZXRLib;
int main()
{
    LinkList<int> list;
    for(int i=0;i<5;i++)
    {
       list.insert(0,i);
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
    */
    return 0;
}
