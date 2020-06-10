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

        link.insert(2, 22);
        link.insert(0, 11);
        link.insert(link.length(), 99);
        link.set(4, 44);
        link.remove(2);

        for(int i=0; i<link.length(); i++)
        {
            int tmp;
            link.get(i, tmp);
            cout << tmp << " ";
        }
        cout << endl;

        cout << link.find(99) << endl;
        cout << link.find(123) << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}