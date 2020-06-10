#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        //StaticList<int, 10> list1;
        //DynamicList<int> list1(10);

        //StaticArray<int, 10> array;
        DynamicArray<int> array(10);

        for(int i=0; i<array.length(); i++)
        {
            array[i] = i;
        }

        DynamicArray<int> array1(array);

        array1.resize(4);   
        for(int i=0; i<array1.length(); i++)
        {
            //list1[2] = 12;  
            cout << array1[i] << " ";
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