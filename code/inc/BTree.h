#ifndef __BTREE_H__
#define __BTREE_H__

#include "BTreeNode.h"
#include "Tree.h"
#include "LinkQueue.h"
#include "DynamicArray.h"

namespace LMSLib
{
    enum BTreePos
    {
        ANY,
        LEFT,
        RIGHT
    };

    enum BTTraversal 
    {
        FIRST,
        MIDDLE,
        LAST
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

    void remove(BTreeNode<T>* toDel, BTree<T>*& ret)
    {
        if(toDel == this->m_root)
        {
            ret->m_root = this->m_root;
            this->m_root = NULL;
        }
        else
        {
            BTreeNode<T>* parent = find(toDel->m_parent);

            if(parent)
            {
                if(toDel == parent->m_left)
                {
                    ret->m_root = toDel;
                    toDel->m_parent = NULL;
                    parent->m_left = NULL;
                }
                else if(toDel == parent->m_right)
                {
                    ret->m_root = toDel;
                    toDel->m_parent = NULL;
                    parent->m_right = NULL;
                }
            }
            else
            {
                THROW_EXCEPTION(InvalidParaException, "Input toDel is Error...");
            }
        }
    }

    void free(BTreeNode<T>* node)
    {
        if(NULL != node)
        {
            free(node->m_left);
            free(node->m_right);

            if(node->flag())
            {
                delete node;
                node = NULL;
            }
        }
    }

    int count(BTreeNode<T>* node) const
    {
        int ret = 0;
        if(NULL != node)
        {
            ret = count(node->m_left) + count(node->m_right) + 1;
        }
        return ret;
    }

    int degree(BTreeNode<T>* node) const 
    {
        int ret = 0;
        BTreeNode<T>* child[] = {node->m_left, node->m_right};
        if(NULL != node)
        {
            ret = (!!node->m_left) + (!!node->m_right);

            for(int i=0; (i < 2)&&(ret < 2); i++)
            {
                int d = degree(child[i]);

                if(ret < d)
                {
                    ret = d;
                }
            }
        }
        return ret;
    }

    int height(BTreeNode<T>* node) const
    {
        int ret = 0;
        if(NULL != node)
        {
            ret = height(node->m_left);
            int h = height(node->m_right);
            if(ret < h)
            {
                ret = h;
            }
            ret += 1;
        }
        return ret;
    }

    void traversal(BTreeNode<T>* node, LinkQueue<T>*& queue, BTTraversal mod)
    {
        if(NULL != node)
        {
            if(FIRST == mod)
            {
                queue->add(node->m_value);
                traversal(node->m_left, queue, mod);
                traversal(node->m_right, queue, mod);
            }
            else if (MIDDLE == mod)
            {
                traversal(node->m_left, queue, mod);
                queue->add(node->m_value);
                traversal(node->m_right, queue, mod);
            }
            else if(LAST == mod)
            {
                traversal(node->m_left, queue, mod);
                traversal(node->m_right, queue, mod);
                queue->add(node->m_value);
            }
            else
            {
                THROW_EXCEPTION(InvalidParaException, "Invalid Param Input...");
            }
        }
    }

    BTreeNode<T>* clone(BTreeNode<T>* node) const
    {
        BTreeNode<T>* ret = NULL;
        if(NULL != node)
        {
            ret = BTreeNode<T>::NewNode();
            if(ret != NULL)
            {
                ret->m_value = node->m_value;
                ret->m_left = clone(node->m_left);
                ret->m_right = clone(node->m_right);

                if(NULL != ret->m_left)
                {
                    ret->m_left->m_parent = ret;
                }
                if(NULL != ret->m_right)
                {
                    ret->m_right->m_parent = ret;
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to New BTreeNode...");
            }      
        }
        return ret;
    }

    bool equal(BTreeNode<T>* Node, BTreeNode<T>* objNode)
    {
        bool ret = true;
        if(Node == objNode)
        {
            ret = true;
        }
        else if( (Node != NULL) && (objNode != NULL) )
        {
            if(Node->m_value == objNode->m_value)
            {
                ret = ret && equal(Node->m_left, objNode->m_left);
                ret = ret && equal(Node->m_right, objNode->m_right);
            }
            else
            {
                ret = false;
            }
        }
        else if ( (Node != NULL) && (objNode == NULL) )
        {
            ret = false;
        }
        else if ( (Node == NULL) && (objNode != NULL) )
        {
            ret = false;
        }
        
        return ret;        
    }

    BTreeNode<T>* add(BTreeNode<T>* node1, BTreeNode<T>* node2)
    {
        BTreeNode<T>* ret = NULL;
        if( (node1 != NULL ) && (node2 != NULL) )
        {
            ret = BTreeNode<T>::NewNode();
            if(NULL != ret)
            {
                ret->m_value = node1->m_value + node2->m_value;

                BTreeNode<T>* lbtn = add(node1->m_left, node2->m_left);
                BTreeNode<T>* rbtn = add(node1->m_right, node2->m_right);

                if(NULL != lbtn)
                {
                    ret->m_left = lbtn;
                    lbtn->m_parent = ret;
                }
                if(NULL != rbtn)
                {
                    ret->m_right = rbtn;
                    rbtn->m_parent = ret;
                }
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to new BTreeNode...");
            }
        }
        else if ( (NULL == node1) && (NULL != node2) )
        {
            ret = clone(node2);
        }
        else if( (NULL != node1) && (NULL == node2) )
        {
            ret = clone(node1);
        }
        return ret;
    }

    LinkQueue<BTreeNode<T>*> m_queue;

public:
    BTree()
    {
        m_queue.clear();
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
        BTree<T>* ret = new BTree<T>();
        if(NULL == ret)
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to new Btree...");
        }

        BTreeNode<T>* node = find(value);

        if(NULL != node)
        {
            remove(node, ret);
        }
        m_queue.clear();

        return ret;
    }

    SharedPointer<Tree<T> > remove(TreeNode<T>* node)
    {
        BTree<T>* ret = new BTree<T>();
        if(NULL == ret)
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to new Btree...");
        }

        remove(dynamic_cast<BTreeNode<T>*>(node), ret);
        m_queue.clear();
        return ret;
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
        free(root());
        this->m_root = NULL;
        m_queue.clear();
    }

    void begin()
    {       
        if(NULL != root())
        {
            m_queue.clear();
            m_queue.add(root());
        }
    }

    void next()
    {
        if( m_queue.length() > 0 )
        {
            BTreeNode<T>* front = m_queue.front();

            if(NULL != front)
            {
                if(NULL != front->m_left)
                {
                    m_queue.add(front->m_left);
                }

                if(NULL != front->m_right)
                {
                    m_queue.add(front->m_right);
                }

                m_queue.remove();
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
    }

    SharedPointer<LinkQueue<T> > traversal(BTTraversal mod)
    {
        LinkQueue<T>* queue = new LinkQueue<T>();
        if(NULL == queue)
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to new DynamicArray...");
        }

        if(NULL != root())
        {
            traversal(root(), queue, mod);
        }
        return queue;
    }

    SharedPointer<BTree<T> > clone() const
    {
        BTree<T>* btree = new BTree<T>();
        if( NULL == btree )
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to new BTree...");
        }

        btree->m_root = clone(root());
        btree->m_root->m_parent = NULL;


        return btree;
    }

    bool operator == (BTree<T>& obj)
    {
        return (true == equal(root(), obj.root()));
    }

    bool operator != (BTree<T>& obj)
    {
        return (true != equal(root(), obj.root()));
    }

    SharedPointer<BTree<T> > add(BTree<T>& obj)
    {
        BTree<T>* ret = new BTree<T>();
        if(NULL != ret)
        {
            ret->m_root = add(root(), obj.root());
            ret->m_root->m_parent = NULL;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memrey to new BTree...");
        }
        return ret;
    }
};

}

#endif // !__BTREE_H__