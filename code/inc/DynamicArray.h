#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include "Array.h"
#include "Exception.h"

namespace LMSLib
{

template <typename T>
class DynamicArray : public Array<T>
{
public:
    DynamicArray(int length)
    {
        this->m_pArray = new T[length];
        if(this->m_pArray)
        {
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to use!");
        }
    }

    DynamicArray(const DynamicArray<T>& obj)
    {
        this->m_pArray = new T[obj.m_length];
        if(this->m_pArray)
        {
            this->m_length = obj.m_length;

            for(int i=0; i<obj.m_length; i++)
            {
                this->m_pArray[i] = obj[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to Use!");
        }       
    }

    DynamicArray<T>& operator = (const DynamicArray<T>& obj)
    {
        if(this != &obj)
        {
            for(int i=0; i<obj.m_length; i++)
            {
                this->m_pArray[i] = obj[i];
            }
        }
        return *this;
    }

    bool resize(int length)
    {
        bool ret = true;
        if(this->m_length != length)
        {
            T* newBuf = new T[length];
            if(newBuf)
            {
                int len = (this->m_length > length) ? length : this->m_length;

                for(int i=0; i<len; i++)
                {
                    newBuf[i] = this->m_pArray[i];
                }

                T* tmp = this->m_pArray;

                this->m_pArray = newBuf;
                this->m_length = length;

                delete[] tmp;
                tmp = NULL;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to Use!");
            }
        }
        return ret;
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
        bool ret = (index >= 0) && (index <this->m_length);
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
        bool ret = (index >= 0) && (index <this->m_length);
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
        return (const_cast<DynamicArray<T>&>(*this))[index];
    }

    int length() 
    {
        return this->m_length;
    }

    ~DynamicArray()
    {
        if(this->m_pArray)
        {
            delete [] this->m_pArray;
            this->m_pArray = NULL;
        }
    }
};

}


#endif // !__DYNAMICARRAY_H__