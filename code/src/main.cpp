#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        //StaticList<int, 10> list1;
        //DynamicList<int> list1(10);

        StaticArray<int, 10> array;

        for(int i=0; i<array.length(); i++)
        {
            array[i] = i;
        }

        for(int i=0; i<array.length(); i++)
        {
            //list1[2] = 12;  
            cout << array[i] << " ";
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