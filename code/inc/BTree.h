#ifndef __BTREE_H__
#define __BTREE_H__

#include "BTreeNode.h"
#include "Tree.h"

namespace LMSLib
{
    enum BTreePos
    {
        ANY,
        LEFT,
        RIGHT
    };
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

    bool insert(BTreeNode<T>* node, BTreeNode<T>* parent, BTreePos pos)
    {
        bool ret = true;
        if( (NULL != parent) && (NULL != node) )
        {
            if(ANY == pos)
            {
                if(NULL == parent->m_left)
                {
                    parent->m_left = node;
                }
                else if (NULL == parent->m_right)
                {
                    parent->m_right = node;
                }
                else
                {
                    ret = false;
                }
            }
            else if (LEFT == pos)
            {
                if(NULL == parent->m_left)
                {
                    parent->m_left = node;
                }
                else
                {
                    ret = false;
                }
            }
            else if (RIGHT == pos)
            {
                if(NULL == parent->m_right)
                {
                    parent->m_right = node;
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                ret = false;
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Parent Node is NULL...");
        }
        return ret;
    }


public:
    BTree()
    {

    }

    bool insert(const T& value, TreeNode<T>* parent)
    {
        return insert(value, parent, ANY);
    }

    bool insert(const T& value, TreeNode<T>* parent, BTreePos pos)
    {
        bool ret = true;

        BTreeNode<T>* newNode = BTreeNode<T>::NewNode();   
        if(NULL == newNode)
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to New BTreeNode...");
        }
        newNode->m_value = value;
        newNode->m_parent = parent;

        if( (NULL == parent) && (NULL == this->m_root) )
        {
            this->m_root = newNode;
        }
        else if(parent != NULL)
        {
            ret = insert(newNode, dynamic_cast<BTreeNode<T>*>(parent), pos);
        }
        else
        {
            delete newNode;
            newNode = NULL;
            THROW_EXCEPTION(InvalidParaException, "Input Parent is NULL...");
        }
        return ret;
    }

    bool insert(TreeNode<T>* node)
    {
        return insert(dynamic_cast<BTreeNode<T>*>(node), ANY);
    }

    bool insert(BTreeNode<T>* node, BTreePos pos)
    {
        bool ret = false;
        if(NULL != node)
        {
            BTreeNode<T>* parent = find(root(), dynamic_cast<BTreeNode<T>*>(node->m_parent));
            if(NULL != parent)
            {
                ret = insert(node, parent, pos);
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Input node is NULL...");
        }

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