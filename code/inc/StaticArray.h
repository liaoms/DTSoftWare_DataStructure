#ifndef __STATICARRAY_H__
#define __STATICARRAY_H__

#include "Array.h"
#include "Exception.h"

namespace LMSLib
{

template <typename T, int N>
class StaticArray : public Array<T>
{
public:
    StaticArray()
    {
        this->m_pArray = m_array;
        this->m_length = N;
    }

    bool set(int index, const T& e)
    {
        bool ret = (index >= 0) && (index < this->m_length);
        if(ret)
        {
            this->m_pArray[index] = e;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }

        return ret;
    }

    bool get(int index, T& e)
    {
        bool ret = (index >= 0) && (index < this->m_length);
        if(ret)
        {
            e = this->m_pArray[index];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }

    T& operator [](int index)
    {
        bool ret = (index >= 0) && (index < this->m_length);
        if(ret)
        {
            return this->m_pArray[index];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }       
    }

    T operator [](int index) const
    {
        return (const_cast<StaticArray<T, N>&>(*this))[index];
    }

    int length()
    {
        return this->m_length;
    }

private:
    T m_array[N];

};

}

#endif // !__STATICARRAY_H__