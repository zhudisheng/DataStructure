#include <iostream>
#include "circlelist.h"

using namespace std;
using namespace ZXRLib;
void josephus(int n,int s,int m)
{
    CircleList<int> cl;
    for(int i = 1;i <= n;i++)
    {
        cl.insert(i);
    }
    /*
    for(int i = 0;i< n;i++)
    {
        cout << cl.get(i)<<endl;
    }
    */
    cout << cl.length() << endl;
    cl.move(s-1,m-1);
    while(cl.length() > 0)
    {
        cl.next();
        cout << cl.current() << endl;
        cl.remove(cl.find(cl.current()));
    }
}

int main()
{
    /*
    int n = 41;
    CircleList<int> cl;
    for(int i = 1;i <= n;i++)
    {
        cl.insert(i);
    }
    for(int i = 1;i<=n;i++)
    {
        cout << cl.get(i)<<endl;
    }
    */
    josephus(41,1,3);
    /*
    CircleList<int> cl;
    for(int i = 1;i < 5;i++)
    {
        cl.insert(i);
    }
    for(int i = 1;i<5;i++)
    {
        cout << cl.get(i) << endl;
    }
    */
    return 0;
}
