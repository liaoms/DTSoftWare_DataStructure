#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        //StaticList<int, 10> list1;
        //DynamicList<int> list1(10);

        //StaticArray<int, 10> array;
        //DynamicArray<int> array(10);

        LinkList<int> link;

        for(int i=0; i<10; i++)
        {
            link.insert(i);
        }

        for(link.mov(0); !link.end(); link.next())
        {
            cout << link.current() << " ";
        }
        cout << endl;

        link.mov(link.length()-1);
        cout << link.current() << endl;
        link.remove(link.length()-1);
        cout << link.current() << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}