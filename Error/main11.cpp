#include <iostream>
#include <cstring>
#include "dtstring.h"

using namespace std;
using namespace ZXRLib;

unsigned int sum(unsigned int n)
{
   if(n > 1)
   {
       return n + sum(n-1);
   }
   else
   {
       return 1;
   }
}
unsigned int fac(unsigned int n)
{
    if(n > 2)
    {
        return fac(n-1) + fac(n - 2);
    }
    if((n == 2)||(n == 1))
    {
        return 1;
    }
}

unsigned int _strlen_(const char* s)
{
    /*
   if(*s != '\0')
   {
       return 1+ _strlen_(s+1);
   }
   else
   {
       return 0;
   }
   */
    return s ? (*s ?(1+_strlen_(s+1)):0):0;
}
int main()
{
    String s = "ababax";
    //cout << s.replace("abab","cdcd").str() << endl;
    String s1 = s.sub(3,2);
    cout << s.str() << endl;
    cout << s1.str() << endl;
    cout << sum(100) << endl;
    for(int i = 1;i < 10;i++)
    {
        cout << fac(i) << endl;
    }
    cout << _strlen_("abc") << endl;
    /*
    String s = "ababax";
    String s1 = s - "aba";
    cout << s.str() << endl;
    cout << s1.str() << endl;

    s -= "ba";
    cout << s.str() << endl;
    s -= s;
    cout << "[" << s.str() <<  "]" << endl;
    //cout << s.remove("baba").length() << endl;
    //cout << s.remove("baba").str() << endl;
    int *pmt = make_pmt("ABCDABD");
    for(int i = 0;i < strlen("ABCDABD");i++)
    {
        cout << i << ":" << pmt[i] << endl;
    }
    */
    return 0;
}
