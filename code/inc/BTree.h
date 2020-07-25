#ifndef __BTREE_H__
#define __BTREE_H__

#include "BTreeNode.h"
#include "Tree.h"

namespace LMSLib
{
template <typename T>
class BTree : public Tree<T>
{
protected:
    BTreeNode<T>* find(BTreeNode<T>* node, const T& value) const
    {
        BTreeNode<T>* ret = NULL;
        if(NULL != node)
        {
            if(value == node->m_value)
            {
                ret = node;
            }
            else
            {
                if(NULL == ret)
                {
                    ret = find(node->m_left, value);
                }

                if(NULL == ret)
                {
                    ret = find(node->m_right, value);
                }
            } 
        }

        return ret;
    }

    BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* value) const
    {
        BTreeNode<T>* ret = NULL;

        if(NULL != node)
        {
            if(node == value)
            {
                ret = node;
            }
            else
            {
                if(NULL == ret)
                {
                    ret = find(node->m_left, value);
                }

                if(NULL == ret)
                {
                    ret = find(node->m_right, value);
                }
            }
        }
        return ret;
    }




public:
    BTree()
    {

    }

    bool insert(const T& value, TreeNode<T>* parent)
    {
        bool ret = true;

        return ret;
    }

    bool insert(TreeNode<T>* node)
    {
        bool ret = true;

        return ret;
    }

    SharedPointer<Tree<T> > remove(const T& value)
    {

    }

    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {

    }

    BTreeNode<T>* find(const T& value) const
    {
        return find(root(), value);
    }

    BTreeNode<T>* find(TreeNode<T>* node) const
    {
        return find( root(), dynamic_cast<BTreeNode<T>*>(node) );
    }

    BTreeNode<T>* root() const
    {
        return dynamic_cast<BTreeNode<T>*>(this->m_root);
    }

    int count() const 
    {

    }

    int degree() const 
    {

    }

    int height() const
    {

    }

    void clear() 
    {

    }
};

}

#endif // !__BTREE_H__