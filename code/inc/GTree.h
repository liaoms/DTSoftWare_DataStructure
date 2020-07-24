#ifndef __GTREE_H__
#define __GTREE_H__

#include "Tree.h"
#include "GTreeNode.h"

namespace LMSLib
{
template <typename T>
class GTree : public Tree<T>
{
public:
    bool insert(const T& value, TreeNode<T>* parent)
    {
        bool ret = true;
        return ret;
    }
    bool insert(TreeNode<T>* node, TreeNode<T>* parent) 
    {
        bool ret = true;
        return ret;
    }
    SharedPointer<Tree<T> > remove(const T& value)
    {
        return NULL;
    }
    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {
        return NULL;
    }
    GTreeNode<T>* find(const T& valuee) const
    {

    }
    GTreeNode<T>* find(TreeNode<T>* node) const
    {

    }
    GTreeNode<T>* root() const
    {
        return dynamic_cast<GTreeNode<T>*>(this->m_root);
    }

    int count() const
    {
        int ret = 0;
        return ret;
    }
    int degree() const
    {
        int ret = 0;
        return ret;
    }
    int height() const 
    {
        int ret = 0;
        return ret;
    }
    void clear() 
    {

    }
};

}

#endif // !__GTREE_H__