#include <iostream>
#include "dynamiclist.h"

using namespace std;
using namespace ZXRLib;
int main()
{
    DynamicList<int> l(5);
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
}
