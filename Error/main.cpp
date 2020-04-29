#include <iostream>
#include "dynamiclist.h"
#include "StaticArray.h"
#include "DynamicArray.h"
using namespace std;
using namespace ZXRLib;
int main()
{
    DynamicArray<int> s1(5);
    for(int i=0;i<s1.length();i++)
    {
        s1[i] = i*i;
    }
    for(int i=0;i<s1.length();i++)
    {
        cout << s1[i] << endl;
    }
    DynamicArray<int> s2(5);
    s2 = s1;
    s2.resize(3);
    cout << s2.length()<<endl;
    for(int i=0;i<s2.length();i++)
    {
        cout << s2[i] << endl;
    }
    //s2[6] = 100;
    return 0;
  /*  DynamicList<int> l(5 );
    for(int i = 0;i < l.capacity();i++)
    {
        l.insert(i);
    }
    for(int i = 0;i < l.length();i++)
    {
        cout << l[i] << endl;
    }
    //DynamicList<int> n = l;
    //DynamicList<int> n(5);
    //n = l;
    return 0;
    */
}
