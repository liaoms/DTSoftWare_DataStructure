#include "Exception.h"
#include <iostream>
#include "SmartPointer.h"
#include "StaticList.h"

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        StaticList<int, 10> list1;

        for(int i=0; i<list1.capacity(); i++)
        {
            list1.insert(i);
        }

        list1.remove(2);
        list1.insert(3,23);

        for(int i=0; i<list1.length(); i++)
        {
            int tmp;
            list1.get(i, tmp);

            cout << tmp << " ";
        }
        cout << endl;

        cout << "list1.find(23) = " << list1.find(23) << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}