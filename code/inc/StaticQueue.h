#ifndef __STATICQUEUE_H__
#define __STATICQUEUE_H__

#include "Queue.h"
#include "Exception.h"

namespace LMSLib
{

template <typename T, int N>
class StaticQueue : public Queue<T>
{
private:
    T m_space[N];
    int m_length;
    int m_head;
    int m_tail;

public:
    StaticQueue() : m_length(0), m_head(0), m_tail(0)
    {

    }

    bool add(const T& e)
    {
        bool ret = m_length < capacity();

        if(ret)
        {
            m_space[m_tail] = e;
            m_tail = (m_tail + 1) % N;
            m_length ++;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "StaticQueue is full");
        }
        return ret;
    }
    bool remove() 
    {
        bool ret = m_length > 0;

        if(ret)
        {
            m_head = (m_head + 1) % N;
            m_length --;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "StaticQueue is Empty");
        }
        return ret;
    }
    T front() 
    {
        return m_space[m_head];
    }
    void clear() 
    {
        m_length = 0;
        m_head = 0;
        m_tail = 0;
    }
    int length() 
    {
        return m_length;
    }

    int capacity()
    {
        return N;
    }
};

}

#endif // !__STATICQUEUE_H__