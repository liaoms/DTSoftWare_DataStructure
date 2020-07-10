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
#include "StaticStack.h"
#include "LinkStack.h"
#include "StaticQueue.h"
#include "LinkQueue.h"
#include "StackToQueue.h"
#include "QueueToStack.h"
#include "String.h"
#include "Sort.h"

using namespace std;
using namespace LMSLib;

int main(int argc, char* argv[])
{
    try
    {
        int array[] = {12,32,23,1,34,4,3,87,567,43,45,67,89};
        int len = sizeof(array)/sizeof(int);

        Sort<int>::bubble(array, len);

        for(int i=0; i<len; i++)
        {
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