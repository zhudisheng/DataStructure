#include <iostream>
#include "dualcirclelist.h"
using namespace std;
using namespace ZXRLib;
int main()
{
    DualCircleList<int> dl;
    for(int i = 0;i < 5;i++)
    {
        dl.insert(0,i);
        dl.insert(0,5);
    }
    /*
    for(dl.move(0);!dl.end();dl.next())
    {
        cout << dl.current()<<endl;
    }
    for(int i = 0;i<dl.length();i++)
    {
        cout << dl.get(i) << endl;
    }
    */
    cout << "begin"<<endl;
    dl.move(dl.length()-1);
    while(dl.find(5)!=-1)
    {
        if(dl.current() == 5)
        {
            cout << dl.current() << endl;
            dl.remove(dl.find(dl.current()));
        }
        else
        {
            dl.pre();
        }
    }
    for(int i=0;i<dl.length();i++)
    {
        cout << dl.get(i) << endl;
    }
    int i = 0;
    for(dl.move(dl.length()-1);(i<dl.length()&&!dl.end());dl.pre(),i++)
    {
        cout << dl.current()<<endl;
    }
    cout << "end"<<endl;
    return 0;
}
