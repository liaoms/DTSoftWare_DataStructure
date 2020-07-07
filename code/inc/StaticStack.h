#ifndef __STATICSTACK_H__
#define __STATICSTACK_H__

#include "Stack.h"
#include "Exception.h"

namespace LMSLib
{

template <typename T, int N>
class StaticStack : public Stack<T>
{
private:
    T m_space[N];
    int m_top;
    int m_size;
public:
    StaticStack() : m_top(-1), m_size(N)
    {

    }

    bool push(const T& e)
    {
        bool ret = m_top < m_size - 1;

        if(ret)
        {
            m_space[m_top + 1] = e;
            m_top ++;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Stack is full");
        }

        return ret;
        
    }
    bool pop()
    {
        bool ret = (m_top >= 0);

        if(ret)
        {
            m_top --;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Stack is empty");
        }

        return ret;
    }
    T top()
    {
        bool ret = (m_top >= 0);
        T tmp;
        if(ret)
        {
            tmp = m_space[m_top];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Stack is empty");
        }

        return tmp;
    }
    bool clear()
    {
        bool ret = true;
        m_top = -1;
        return ret;

    }
    int size()
    {
        return m_size;
    }

};

}


#endif // !__STATICSTACK_H__