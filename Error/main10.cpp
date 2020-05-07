#include <iostream>
#include "dtstring.h"

using namespace std;
using namespace ZXRLib;

void test_1()
{
    cout << "test_1() begin..." << endl;

    String s;

    s = 'D';

    cout << s.str() << endl;
    cout << s.length() << endl;
    cout << (s == "D") << endl;
    cout << (s > "CCC") << endl;

    s += "zhuxinran";
    cout << s.str() << endl;
    cout << s.length() << endl;

    cout << "test_1() end ..." << endl;
}
void test_2()
{
    cout << "test_2() begin..." << endl;
    String a[] = {"E","D","C","B","A"};
    String min = a[0];
    for(int i = 0;i < 5;i++)
    {
        if(min > a[i])
        {
            min = a[i];
        }
    }

    cout << "min = " << min.str() << endl;
    cout << "test_2() end..." << endl;
}
int main()
{
    //test_1();
    //test_2();
    String s = "";
    s.insert(0,"zxr");
    cout << s.str() << endl;
    s.insert(3,"software");
    cout << s.str() << endl;
    /*
    String s = "  abc  ";
    if(s.trim().insert(0,"D.T.").endOf("abc")&&s.startWith("D.T."))
    {
        cout << "[" << s.str() << "]" << endl;
    }
    cout << s.trim().str() << endl;
    */
    return 0;

}
