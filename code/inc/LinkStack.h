#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include "LinkList.h"
#include "Stack.h"
namespace LMSLib
{
template <typename T, int N>
class LinkStack : public Stack<T>
{
private:
    int m_size;
    LinkList<T> m_list;

public:
    LinkStack() : m_size(N)
    {
        m_list.clear();
    }

    bool push(const T& e)
    {
        bool ret = m_list.length() < m_size;

        if(ret)
        {
            m_list.insert(0, e);
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "DynamicStack is full");
        }
        return ret;
    }
    bool pop()
    {
        bool ret = m_list.length() > 0;

        if(ret)
        {
            m_list.remove(0);
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "DynamicStack is Empty");
        }
        return ret;
    }
    T top()
    {
        if(m_list.length() > 0)
        {
            T tmp;
            m_list.get(0,tmp);
            return tmp;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "DynamicStack is Empty");
        }
        
    }
    bool clear()
    {
        m_list.clear();
    }
    int size()
    {
        return m_size;
    }
};

}


#endif // !__LINKSTACK_H__