#ifndef __GTREE_H__
#define __GTREE_H__

#include "Tree.h"
#include "GTreeNode.h"
#include "Exception.h"
#include "LinkQueue.h"

namespace LMSLib
{
template <typename T>
class GTree : public Tree<T>
{
private:
    GTree(const GTree<T>& obj);
    GTree<T>& operator= (const GTree<T>& obj);

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

    void free(GTreeNode<T>* node)
    {
        if(NULL == node)
        {
            return;
        }
        else
        {
            for(node->m_child.mov(0); !node->m_child.end(); node->m_child.next())
            {
                free(node->m_child.current());
            }

            if(node->flag())
            {
                delete node;
                node = NULL;
            }                       
        }
    }

    void remove(GTreeNode<T>* delNode, GTree<T>*& ret)
    {
        ret = new GTree<T>();

        if(NULL != ret)
        {
            if(delNode == root())
            {
                ret->m_root = this->m_root;
                this->m_root = NULL;
            }
            else
            {
                LinkList<GTreeNode<T>*>& child =  dynamic_cast<GTreeNode<T>*>(delNode->m_parent)->m_child;

                child.remove(child.find(delNode));

                delNode->m_parent = NULL;
                ret->m_root = delNode;
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to new Gtree...");
        }
    }

    int count(GTreeNode<T>* node) const
    {
        int ret = 0;
        if(NULL != node)
        {
            ret = 1;

            for(node->m_child.mov(0); !node->m_child.end(); node->m_child.next())
            {
                ret += count(node->m_child.current());
            }
        }
        
        return ret;
    }

    int degree(GTreeNode<T>* node) const
    {
        int ret = 0;
        if(NULL != node)
        {
            ret = node->m_child.length();

            for(node->m_child.mov(0); !node->m_child.end(); node->m_child.next())
            {
                int d = node->m_child.length();
                if(ret < d)
                {
                    ret = d;
                }
            }
        }
        return ret;
    }

    int height(GTreeNode<T>* node) const
    {
        int ret = 0;
        if(NULL != node)
        {
            for(node->m_child.mov(0); !node->m_child.end(); node->m_child.next())
            {
                int h = height(node->m_child.current());
                if(ret < h)
                {
                    ret = h;
                }
            }
            ret += 1;
        }

        return ret;
    }

    LinkQueue<GTreeNode<T>* > m_queue;

public:
    GTree()
    {
        m_queue.clear();
    }

    bool insert(const T& value, TreeNode<T>* parent)
    {
        bool ret = true;
        GTreeNode<T>* pNewNode = GTreeNode<T>::newNode();
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
            if( NULL == this->m_root )
            {
                this->m_root = node;
                node->m_parent = NULL;
            }
            else
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
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Input node can't be NULL...");
        }

        return ret;
    }

    SharedPointer<Tree<T> > remove(const T& value)
    {
        GTreeNode<T>* delNode = find(value);
        GTree<T>* ret = NULL;
        if(NULL != delNode)
        {
            remove(delNode, ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Input param error...");
        }
        return ret;
    }
 
    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {
        GTreeNode<T>* delNode = find(node);
        GTree<T>* ret = NULL;
        if(NULL != delNode)
        {
            remove(delNode, ret);
            m_queue.clear();
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Input param error...");
        }
        return ret;
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
        return count(root());
    }
 
    int degree() const
    {
        return degree(root());
    }
 
    int height() const 
    {
        return height(root());
    }
 
    void clear() 
    {
        free(dynamic_cast<GTreeNode<T>*>(this->m_root));
        this->m_root = NULL;

        m_queue.clear();
    }

    void begin()
    {
        if(NULL != this->m_root)
        {
            m_queue.clear();
            m_queue.add(root());
        }
    }

    void next()
    {
        if(m_queue.length() > 0)
        {
            GTreeNode<T>* front = m_queue.front();

            m_queue.remove();

            for(front->m_child.mov(0); !front->m_child.end(); front->m_child.next())
            {
                m_queue.add(front->m_child.current());
            }
        }
    }

    bool end()
    {
        return 0 == m_queue.length();
    }

    T current()
    {
        if(m_queue.length() > 0)
        {
            return m_queue.front()->m_value;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "queue is empty...");
        }
    }

    ~GTree()
    {
        clear();
    }
};

}

#endif // !__GTREE_H__