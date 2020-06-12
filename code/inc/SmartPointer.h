#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

#include "Pointer.h"
#include <iostream>

using namespace std;

namespace LMSLib
{
template <typename T>
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* pointer) : Pointer<T>(pointer)
    {   
    }

    SmartPointer(const SmartPointer<T>& obj)
    {
        this->m_pointer = obj.m_pointer;

        (const_cast<SmartPointer<T>&>(obj)).m_pointer = NULL;
    }

    SmartPointer<T>& operator = (const SmartPointer<T>& obj)
    {
        if(this != &obj)
        {
            delete this->m_pointer;
            this->m_pointer = obj.m_pointer;

            (const_cast<SmartPointer<T>&>(obj)).m_pointer = NULL;
        }

        return *this;
    }

    ~SmartPointer()
    {
        if(NULL == this->m_pointer)
        {
            delete this->m_pointer;
            this->m_pointer = NULL;
        }
    }
};

}

#endif // !__SMARTPOINTER_H__