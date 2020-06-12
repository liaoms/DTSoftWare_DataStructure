#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"
#include "SharedPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "StaticLinkList.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        const SmartPointer<int> p = new int(12);
        SmartPointer<int> p1(p);

        cout << *p << endl;
        cout << p.value() << endl;
        cout << p.get() << endl;
        cout << p.isNull() << endl << endl;
        
        cout << *p1 << endl;
        cout << p1.value() << endl;
        cout << p1.get() << endl;
        cout << p1.isNull() << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}