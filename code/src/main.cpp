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

using namespace std;
using namespace LMSLib;

int main(int argc, char* argv[])
{
    try
    {
        LinkQueue<int, 10> q;
        for(int i=0; i<q.capacity(); i++)
        {
            q.add(i);
        }

        q.remove();
        q.add(100);
        q.remove();
        q.add(110);
        q.remove();
        q.add(120);
        q.remove();
        q.add(140);

        while(q.length() > 0)
        {
            cout << q.front() << endl;
            q.remove();
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