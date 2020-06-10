#ifndef __DYNAMICLIST_H__
#define __DYNAMICLIST_H__

#include "SeqList.h"

namespace LMSLib
{

template <typename T>
class DynamicList : public SeqList<T>
{
public:

DynamicList(int capacity):m_Capacity(0)
{
    this->m_pArray = new T[capacity];
    if(NULL != this->m_pArray)
    {
        m_Capacity = capacity;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to use! new DynamicList Space error");
    }  
}

bool resize(unsigned int capacity)
{
    bool ret = true;
    
    if(capacity == 0)
    {
        THROW_EXCEPTION(InvalidParaException, " Invalid Para Error! DynaimcList resize param need > 0");
    }

    if( m_Capacity != capacity )
    {

        T* newBuf = new T[capacity];
        if(NULL != newBuf)
        {
            int len = (this->m_length > capacity) ? capacity : this->m_length;

            for(int i=0; i<len; i++)
            {
                newBuf[i] = this->m_pArray[i];
            }

            T* toDel = this->m_pArray;

            this->m_pArray = newBuf;
            this->m_length = len;
            m_Capacity = capacity;

            delete[] toDel;
            toDel = NULL;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "NoEnough Memery to use!");
            ret = false;
        }     
    }

    return ret;
}

int capacity()
{
    return m_Capacity;
}

~DynamicList()
{
    if(this->m_pArray)
    {
        delete[] this->m_pArray;
        this->m_pArray = NULL;
    }
}

private:
    int m_Capacity;

};

}

#endif // !__DYNAMICLIST_H__