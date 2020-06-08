#include "Exception.h"
#include <iostream>

using namespace std;
using namespace LMSLib;


int main(int argc, char* argv[])
{
    try
    {
        THROW_EXCEPTION(NoEnoughMemeryException, "NO Enough Memery to use!");
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}