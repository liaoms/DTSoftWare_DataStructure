#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include "List.h"
#include "Exception.h"

namespace LMSLib
{

template <typename T>
class SeqList : public List<T>
{
public:
    SeqList():m_pArray(NULL), m_length(0)
    {

    }
    bool insert(const T e)
    {
        return insert(m_length, e);
    }
    bool insert(int index, const T e)
    {
        bool ret = (index >=0 ) && (index <= m_length);
        ret = ret && (m_length < capacity());

        if(ret)
        {
            for(int i=m_length-1; i>=index; i--)
            {
                m_pArray[i+1] = m_pArray[i];
            }

            m_pArray[index] = e;
            m_length++;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }
    bool remove(int index)
    {
        T tmp;
        return remove(index, tmp);
    }
    bool remove(int index, T& e)
    {
        bool ret = (index >= 0) && (index <m_length);
        if(ret)
        {
            e = m_pArray[index];
            for(int i=index; i<=m_length; i++)
            {
                m_pArray[i] = m_pArray[i+1];
            }
            m_length--;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }
    bool set(int index, const T e)
    {
        bool ret = (index >= 0) && (index < m_length);

        if(ret)
        {
            m_pArray[index] = e;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }

        return ret;
    }
    bool get(int index, T& e) const
    {
        bool ret = (index >= 0) && (index < m_length);

        if(ret)
        {
            e = m_pArray[index];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }

        return ret;
    }
    int find(const T e) const
    {
        int index = -1;
        for(int i=0; i<m_length; i++)
        {
            if(e == m_pArray[i])
            {
                index = i;
                break;
            }
        }
        return index;
    }
    int length() const
    {
        return m_length;
    }
    void clear()
    {
        m_length = 0;
    }

    virtual int capacity() = 0;

protected:
    T* m_pArray;
    int m_length;
};

}

#endif // !__SEQLIST_H__