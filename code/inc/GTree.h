#ifndef __GTREE_H__
#define __GTREE_H__

#include "Tree.h"
#include "GTreeNode.h"
#include "Exception.h"

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
        GTreeNode<T>* pNewNode = new GTreeNode<T>();
        if(NULL != pNewNode)
        {
            pNewNode->m_value = value;
            pNewNode->m_child.clear();

            if(NULL == parent)
            {    
                pNewNode->m_parent = NULL;
                this->m_root = pNewNode;
            }
            else
            {
                pNewNode->m_parent = parent;
                return insert(pNewNode);
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "NoEnough Memery to new GtreeNode");
        }

        return ret;
    }

    bool insert(TreeNode<T>* node) 
    {
        bool ret = false;

        if(NULL != node)
        {
            GTreeNode<T>* parentNode = find(node->m_parent);

            if(parentNode)
            {
                GTreeNode<T>* childNode = dynamic_cast<GTreeNode<T>*>(node);
                if(parentNode->m_child.find(childNode) < 0)
                {
                    parentNode->m_child.insert(childNode);
                }
                ret = true;
            }
            else
            {
                THROW_EXCEPTION(InvalidParaException, "Inout node did't have parent...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Input node can't be NULL...");
        }

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