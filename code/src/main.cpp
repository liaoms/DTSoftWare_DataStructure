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
#include "CircleList.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        CircleList<int> cList;

        for(int i=0; i<10; i++)
        {
            cList.insert(i);
        }

        cList.remove(0);
        cout << cList.current() << endl;
        cList.remove(cList.length()-1);
        cList.remove(4);
        cList.insert(0, 12);
        cList.insert(99);
        for(cList.mov(0); !cList.end(); cList.next())
        {
            cout << cList.current() << endl;
            sleep(1);
        }
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}