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
        GTree<char> tree;
        GTreeNode<char>* node = NULL;

        GTreeNode<char> root;
        root.m_value = 'A';
        root.m_parent = NULL;

        tree.insert(&root);

        node = tree.find('A');
        if(NULL == node)
        {
            cout << "can't find 'A'" << endl;
        }
        tree.insert('B', node);
        tree.insert('C', node);
        tree.insert('D', node);

        node = tree.find('B');
        if(NULL == node)
        {
            cout << "can't find 'B'" << endl;
        }
        tree.insert('E', node);
        tree.insert('F', node);

        node = tree.find('C');
        if(NULL == node)
        {
            cout << "can't find 'C'" << endl;
        }
        tree.insert('G', node);

        node = tree.find('D');
        if(NULL == node)
        {
            cout << "can't find 'D'" << endl;
        }
        tree.insert('H', node);
        tree.insert('I', node);
        tree.insert('J', node);

        node = tree.find('E');
        if(NULL == node)
        {
            cout << "can't find 'E'" << endl;
        }
        tree.insert('K', node);
        tree.insert('L', node);

        node = tree.find('H');
        if(NULL == node)
        {
            cout << "can't find 'H'" << endl;
        }
        tree.insert('M', node);

        cout << "tree.count() = " << tree.count() << endl;
        cout << "tree.degree() = " << tree.degree() << endl;
        cout << "tree.height() = " << tree.height() << endl;

        char array[] = {'K', 'L', 'F', 'G', 'M', 'I', 'J'};

        for(tree.begin(); !tree.end(); tree.next())
        {
            cout << tree.current() << " ";
        }
        cout << endl;

        BTree<int> bt;
        BTreeNode<int> btn;

        cout << bt.find(1) << endl;
        cout << bt.find(&btn) << endl;

    }
    catch(Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    return 0;
}