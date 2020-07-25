#ifndef __BTREENODE_H__
#define __BTREENODE_H__

#include "TreeNode.h"
#include "Exception.h"

namespace LMSLib
{
template <typename T>
class BTreeNode : public TreeNode<T>
{

public:
    BTreeNode<T>* m_left;
    BTreeNode<T>* m_right;
    BTreeNode()
    {
        m_left = NULL;
        m_right = NULL;
    }

    static BTreeNode* NewNode()
    {
        BTreeNode<T>* ret = new BTreeNode<T>();

        if(NULL != ret)
        {
            ret->m_flag = true;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No ENough Memery toNew BtreeNode...");
        }
    }
};

}

#endif // !__BTREENODE_H__