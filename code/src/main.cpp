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
#include "DualLinkList.h"
#include "StaticDualLinkList.h"
#include "DualCircleList.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        DualCircleList<int> dlist;

        for(int i=0; i<10 ; i++)
        {   
            dlist.insert(i);
        }

        dlist.mov(3);
        cout << dlist.current() << endl;
        dlist.remove(3);
        cout << dlist.current() << endl;
        dlist.insert(9);
        //dlist.insert(3, 11);

        for(dlist.mov( dlist.length()-1, 1, false); !dlist.end(); dlist.next())
        {
            cout << dlist.current()  << endl;
            sleep(1);
        }

        cout << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}