#ifndef __GTREENODE_H__
#define __GTREENODE_H__

#include "TreeNode.h"
#include "LinkList.h"
#include "Exception.h"

namespace LMSLib
{
template <typename T>
class GTreeNode : public TreeNode<T>
{
public:

    LinkList<GTreeNode<T>*> m_child;

    GTreeNode()
    {
        m_child.clear();
    }

    static GTreeNode<T>* newNode()
    {
        GTreeNode<T>* node = NULL;
        node = new GTreeNode<T>();

        if(NULL != node)
        {
            node->m_flag = true;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery tonew GTreeNode...");
        }

        return node;
    }

    ~GTreeNode()
    {

    }
};


}


#endif // !__GTREENODE_H__