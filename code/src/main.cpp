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

using namespace std;
using namespace LMSLib;

/*
* nTotalNum : 总人数
* nStartIdx : 起始位置
* nStep     : 间隔人数
* 返回值    :  最后剩的人
*/
int JosephCircle(unsigned int nTotalNum, unsigned int nStartIdx, unsigned int nStep)
{
    CircleList<int> cList;

    for(int i=0; i<nTotalNum; i++)
    {
        cList.insert(i+1);
    }

    cList.mov(nStartIdx-1);
    while(cList.length() > 1)
    {
        for(int i=1; i<nStep; i++)
        {
            cList.next();
        }
        {
            cout << "out : " << cList.current() << endl;
            cList.remove(cList.find(cList.current()));
        }
    }
    return cList.current();
}


int main(int argc, char* argv[])
{
    try
    {
        int ret = JosephCircle(10, 2, 8);

        cout << "last Idx = " << ret << endl;
    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}