#ifndef __QUEUETOSTACK_H__
#define __QUEUETOSTACK_H__

#include "Stack.h"
#include "LinkQueue.h"

namespace LMSLib
{
template <typename T>
class QueueToStack : public Stack<T>
{
private:
    LinkQueue<T> m_queue1;
    LinkQueue<T> m_queue2;

    LinkQueue<T>* m_pQueueIn;
    LinkQueue<T>* m_pQueueOut;

    void swap()
    {
        LinkQueue<T>* tmp = m_pQueueIn;
        m_pQueueIn = m_pQueueOut;
        m_pQueueOut = tmp;
    }

public:
    QueueToStack()
    {
        m_pQueueIn = &m_queue1;
        m_pQueueOut = &m_queue2;
    }

    bool push(const T& e)
    {
        return m_pQueueIn->add(e);
    }
    bool pop()
    {
        bool ret = size() > 0;
        if(ret)
        {
            int n = m_pQueueIn->length()-1;
            for(int i=0; i<n; i++)
            {
                m_pQueueOut->add(m_pQueueIn->front());
                m_pQueueIn->remove();
            }
            m_pQueueIn->remove();

            swap();
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "QueueToStack is Empty");
        }
        return ret;
    }
    T top()
    {
        bool ret = size() > 0;
        if(ret)
        {
            int n = m_pQueueIn->length()-1;
            for(int i=0; i<n; i++)
            {
                m_pQueueOut->add(m_pQueueIn->front());
                m_pQueueIn->remove();
            }
            return m_pQueueIn->front();
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "QueueToStack is Empty");
        }
    }
    bool clear()
    {
        m_queue1.clear();
        m_queue2.clear();
    }
    int size()
    {
        return m_pQueueOut->length() + m_pQueueIn->length();
    }

};


}

#endif // !__QUEUETOSTACK_H__