#ifndef __BTREE_H__
#define __BTREE_H__

#include "BTreeNode.h"
#include "Tree.h"

namespace LMSLib
{
template <typename T>
class BTree : public Tree<T>
{
private:

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
        return NULL;
    }

    BTreeNode<T>* find(TreeNode<T>* node) const
    {
        return NULL;
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