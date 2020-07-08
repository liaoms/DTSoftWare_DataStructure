#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include "Queue.h"
#include "LinkList.h"

namespace LMSLib
{
template <typename T, int N>
class LinkQueue : public Queue<T>
{
private:
    LinkList<T> m_list;

public:
    bool add(const T& e)
    {
        bool ret = m_list.length() < N;
        if(ret)
        {
            m_list.insert(m_list.length(), e);
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "LinkQueue is full");
        }
        return ret;
    }

    bool remove()
    {
        bool ret = m_list.length() > 0;
        if(ret)
        {
            m_list.remove(0);
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "LinkQueue is empty");
        }
        return ret;
    }
    T front()
    {
        if(m_list.length() > 0)
        {
            T tmp;
            m_list.get(0, tmp);
            return tmp;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "LinkQueue is empty");
        }
    }
    void clear()
    {
        m_list.clear();
    }
    int length()
    {
        return m_list.length();
    }

    int capacity()
    {
        return N;
    }
};
}

#endif // !__LINKQUEUE_H__