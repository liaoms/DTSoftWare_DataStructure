#ifndef __TREE_H__
#define __TREE_H__

#include "Object.h"
#include "TreeNode.h"
#include "SharedPointer.h"

namespace LMSLib
{
template <typename T>
class Tree : public Object
{
private:
    Tree(const Tree<T>& obj);
    Tree<T>& operator= (const Tree<T>& obj);

protected:
    TreeNode<T>* m_root;
public:
    Tree()
    {
        m_root = NULL;
    }
    virtual bool insert(const T& value, TreeNode<T>* parent) = 0;
    virtual bool insert(TreeNode<T>* node) = 0;
    virtual SharedPointer<Tree<T> > remove(const T& value) = 0;
    virtual SharedPointer<Tree<T> > remove(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* find(const T& value) const = 0;
    virtual TreeNode<T>* find(TreeNode<T>* node) const = 0;
    virtual TreeNode<T>* root() const = 0;
    virtual int count() const = 0;
    virtual int degree() const = 0;
    virtual int height() const = 0;
    virtual void clear() = 0;
    virtual void begin() = 0;
    virtual void next() = 0;
    virtual bool end() = 0;
    virtual T current() = 0;

};

}

#endif // !__TREE_H__