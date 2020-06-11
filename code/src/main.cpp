#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"
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
        //StaticList<int, 10> list1;
        //DynamicList<int> list1(10);

        //StaticArray<int, 10> array;
        //DynamicArray<int> array(10);

        //LinkList<int> link;

        StaticLinkList<int, 10> link;
        for(int i=0; i<link.cpacity(); i++)
        {
            link.insert(i);
        }

        link.mov(3);
        cout << link.current() << endl;
        link.remove(link.find(link.current()));
        cout << link.current() << endl;

        link.remove(2);
        link.insert(12);

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