#ifndef __GTREE_H__
#define __GTREE_H__

#include "Tree.h"
#include "GTreeNode.h"

namespace LMSLib
{
template <typename T>
class GTree : public Tree<T>
{
protected:
    GTreeNode<T>* find(GTreeNode<T>* node, const T& value) const
    {
        GTreeNode<T>* ret = NULL;

        if(NULL != node)
        {
            if(value == node->m_value)
            {
                return node;
            }
            else
            {
                for(node->m_child.mov(0); !node->m_child.end() && (ret == NULL); node->m_child.next())
                {
                    ret = find(node->m_child.current(), value);
                }
            }           
        }
        return ret;
    }

    GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* nodeValue) const
    {
        GTreeNode<T>* ret = NULL;

        if(NULL != node)
        {
            if(nodeValue == node)
            {
                return node;
            }
            else
            {
                for(node->m_child.mov(0); !node->m_child.end() && (ret == NULL); node->m_child.next())
                {
                    ret = find(node->m_child.current(), nodeValue);
                }
            }           
        }
        return ret;
    }


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
    GTreeNode<T>* find(const T& value) const
    {
        return find(root(), value);
    }
    GTreeNode<T>* find(TreeNode<T>* node) const
    {
        return find(root(), dynamic_cast<GTreeNode<T>*>(node));
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