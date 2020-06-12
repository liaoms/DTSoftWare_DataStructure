#ifndef __SHAREDPOINTER_H__
#define __SHAREDPOINTER_H__

#include "Pointer.h"

namespace LMSLib
{

template <typename T>
class SharedPointer : public Pointer<T>
{
private:
    int* m_pCount;

    void assign(const SharedPointer<T>& obj)
    {
        this->m_pointer = obj.m_pointer;
        m_pCount = obj.m_pCount;
        (*m_pCount) ++;
    }

public:
    SharedPointer(T* pointer)
    {
        m_pCount = reinterpret_cast<int*>(malloc(sizeof(int)));
        if(NULL != m_pCount)
        {
            *m_pCount = 1;
            this->m_pointer = pointer;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to Use!");
        }
    }

    SharedPointer(const SharedPointer<T>& obj)
    {
        assign(obj);
    }

    SharedPointer<T>& operator = (const SharedPointer<T>& obj)
    {
        clear();
        if(this != &obj)
        {
            assign(obj);
        }
        return *this;
    }

    bool operator == (const SharedPointer<T>& obj)
    {
        return this->m_pointer == obj.m_pointer;
    }

    bool operator != (const SharedPointer<T>& obj)
    {
        return this->m_pointer != obj.m_pointer;
    }

    void clear()
    {
        (*m_pCount) --;

        if(0 == (*m_pCount))
        {
            delete this->m_pointer;
            free(m_pCount);
            m_pCount = NULL;
            this->m_pointer = NULL;
        }
    }

    ~SharedPointer()
    {
        clear();
    }

};

}

#endif // !__SHAREDPOINTER_H__