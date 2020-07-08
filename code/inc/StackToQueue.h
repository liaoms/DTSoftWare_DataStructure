#ifndef __STACKTOQUEUE_H__
#define __STACKTOQUEUE_H__

#include "Queue.h"
#include "LinkStack.h"

namespace LMSLib
{
template <typename T>
class StackToQueue : public Queue<T>
{
private:
    LinkStack<T> m_stackIn;
    LinkStack<T> m_stacklOut;

public:
    bool add(const T& e)
    {
        return m_stackIn.push(e);
    }

    bool remove()
    {
        bool ret = length() > 0;
        if(ret)
        {
            if(0 == m_stacklOut.size())
            {
                while(m_stackIn.size() > 0)
                {
                    m_stacklOut.push(m_stackIn.top());
                    m_stackIn.pop();
                }
            }

            if(m_stacklOut.size() > 0)
            {
                m_stacklOut.pop();               
            }
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "StackToQueue is Empty");
        }
        return ret;
    }
    T front()
    {
        bool ret = length() > 0;
        if(ret)
        {
            if(0 == m_stacklOut.size())
            {
                while(m_stackIn.size() > 0)
                {
                    m_stacklOut.push(m_stackIn.top());
                    m_stackIn.pop();
                }
            }

            if(m_stacklOut.size() > 0)
            {
                return m_stacklOut.top();               
            }
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "StackToQueue is Empty");
        }      
    }

    void clear()
    {
        m_stackIn.clear();
        m_stacklOut.clear();
    }
    int length()
    {
        return m_stacklOut.size() + m_stackIn.size();
    }
};

}

#endif // !__STACKTOQUEUE_H__