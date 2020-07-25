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

        cout << "bt.count() = " << bt.count() << endl;
        cout << "bt.height() = " << bt.height() << endl;
        cout << "bt.degree() = " << bt.degree() << endl;

        int array[] = {8,9,10,6,7};

        SharedPointer<Tree<int> > ret = bt.remove(2);

        for(int i=0; i<sizeof(array)/sizeof(int); i++)
        {
            TreeNode<int>* node = bt.find(array[i]);

            if(node)
            {
                while(node)
                {
                    cout << node->m_value << " ";
                    node = node->m_parent;
                }
                cout << endl;
            }
        }

    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}