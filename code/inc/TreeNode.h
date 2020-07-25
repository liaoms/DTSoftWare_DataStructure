#ifndef __TREENODE_H__
#define __TREENODE_H__

#include "Object.h"

namespace LMSLib
{

template <typename T>
class TreeNode : public Object
{
private:
    TreeNode(const TreeNode<T>& obj);
    TreeNode<T>& operator = (const TreeNode<T>& obj);

protected:
    bool m_flag;

public:
    T m_value;
    TreeNode<T>* m_parent;

    TreeNode()
    {
        m_parent = NULL;
        m_flag = false;
    }

    void * operator new (unsigned int size) throw()
    {
        return Object::operator new (size);
    }

    bool flag()
    {
        return m_flag;
    }

    virtual ~TreeNode() = 0; 
};

template <typename T>
TreeNode<T>::~TreeNode()
{
    
}

}


#endif // !__TREENODE_H__