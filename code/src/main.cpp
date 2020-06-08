#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        SmartPointer<int> p = new int(12);
        SmartPointer<int> q = new int(13);
        cout << "p = " << p.get() << endl;
        cout << "q = " << q.get() << endl;

        q = p;

        cout << "p = " << p.get() << endl;
        cout << "q = " << q.get() << endl;

        THROW_EXCEPTION(NoEnoughMemeryException, "NO Enough Memery to use!");
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}