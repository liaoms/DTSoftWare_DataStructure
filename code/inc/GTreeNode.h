#ifndef __GTREENODE_H__
#define __GTREENODE_H__

#include "TreeNode.h"
#include "LinkList.h"

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

    ~GTreeNode()
    {

    }
};


}


#endif // !__GTREENODE_H__