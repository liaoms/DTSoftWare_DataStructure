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

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        StaticDualLinkList<int, 10> dlist;

        for(int i=0; i<dlist.cpacity() ; i++)
        {   
            dlist.insert(i);
        }

        dlist.remove(0);
        dlist.insert(3, 11);

        for(dlist.mov( dlist.length()-1, 1, false); !dlist.end(); dlist.next())
        {
            cout << dlist.current()  << " ";
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