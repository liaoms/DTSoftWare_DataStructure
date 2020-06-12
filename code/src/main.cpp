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
        const SharedPointer<int> p = new int(12);
        SharedPointer<int> p1(p);

        SharedPointer<int> p2 = new int(22);

        cout << (p2 == p) << endl;

        p2 = p;

        cout << (p2 == p) << " " << (p1 == p) << endl;

        cout << *p << endl;
        cout << p.value() << endl;
        cout << p.get() << endl;
        cout << p.isNull() << endl << endl;
        
        cout << *p1 << endl;
        cout << p1.value() << endl;
        cout << p1.get() << endl;
        cout << p1.isNull() << endl << endl;

        cout << *p2 << endl;
        cout << p2.value() << endl;
        cout << p2.get() << endl;
        cout << p2.isNull() << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}