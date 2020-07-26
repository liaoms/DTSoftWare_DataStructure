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
#include "GTreeNode.h"
#include "GTree.h"
#include "BTree.h"

using namespace std;
using namespace LMSLib;

int main(int argc, char* argv[])
{
    try
    {
        BTree<int> bt;
        BTreeNode<int>* btn = NULL;

        bt.insert(1,NULL);

        btn = bt.find(1);
        if(!btn)
        {
            cout << "find(1) error" << endl;
            return 0;
        }
        bt.insert(2, btn);
        bt.insert(3, btn);

        btn = bt.find(2);
        if(!btn)
        {
            cout << "find(2) error" << endl;
            return 0;
        }
        bt.insert(4, btn);
        bt.insert(5, btn);

        btn = bt.find(4);
        if(!btn)
        {
            cout << "find(4) error" << endl;
            return 0;
        }
        bt.insert(8, btn);
        bt.insert(9, btn);

        btn = bt.find(5);
        if(!btn)
        {
            cout << "find(5) error" << endl;
            return 0;
        }
        bt.insert(10, btn);

        btn = bt.find(3);
        if(!btn)
        {
            cout << "find(3) error" << endl;
            return 0;
        }
        bt.insert(6, btn);
        bt.insert(7, btn);

        SharedPointer<BTree<int> > btclone = bt.clone();

        cout << "btclone.count() = " << btclone->count() << endl;
        cout << "btclone.height() = " << btclone->height() << endl;
        cout << "btclone.degree() = " << btclone->degree() << endl;

        SharedPointer<LinkQueue<int> > queue = btclone->traversal(FIRST);

        while(queue->length() > 0)
        {
            cout << queue->front() << " ";
            queue->remove();
        }
        cout << endl;

        SharedPointer<LinkQueue<int> > queue1 = btclone->traversal(MIDDLE);

        while(queue1->length() > 0)
        {
            cout << queue1->front() << " ";
            queue1->remove();
        }
        cout << endl;

        SharedPointer<LinkQueue<int> > queue2 = btclone->traversal(LAST);

        while(queue2->length() > 0)
        {
            cout << queue2->front() << " ";
            queue2->remove();
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