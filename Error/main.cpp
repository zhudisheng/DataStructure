#include <iostream>
#include "Exception.h"

using namespace std;
using namespace ZXRLib;

int main(int argc, char *argv[])
{
    try
    {
        //throw Exception("test",__FILE__,__LINE__);
        THROW_EXCEPTION(ArithmetricException,"test");
    }
    catch(const Exception& e)
    {
        cout << "catch(const Exception& e)"<<endl;
        cout << e.message()<<endl;
        cout << e.location()<<endl;
    }
    catch(const ArithmetricException& e)
    {
        cout << "catch(const ArithmerticException& e)"<<endl;
        cout << e.message()<<endl;
        cout << e.location()<<endl;
    }
    return 0;
}
