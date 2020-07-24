#ifndef __TREENODE_H__
#define __TREENODE_H__

#include "Object.h"

namespace LMSLib
{

template <typename T>
class TreeNode : public Object
{
public:
    T m_value;
    TreeNode<T>* m_parent;

    TreeNode()
    {
        m_parent = NULL;
    }

    virtual ~TreeNode() = 0; 
};

template <typename T>
TreeNode<T>::~TreeNode()
{
    
}

}


#endif // !__TREENODE_H__