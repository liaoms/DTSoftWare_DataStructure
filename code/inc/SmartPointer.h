#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

#include "Object.h"
#include <iostream>

using namespace std;

namespace LMSLib
{
template <typename T>
class SmartPointer : public Object
{
public:
    SmartPointer(T* pointer) : m_pointer(pointer)
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

    T* operator -> ()
    {
        return m_pointer;
    }

    T& operator *()
    {
        return *m_pointer;
    }

    T* get()
    {
        return m_pointer;
    }

    T& value()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return NULL == m_pointer;
    }

    ~SmartPointer()
    {
        if(NULL == m_pointer)
        {
            delete m_pointer;
            m_pointer = NULL;
        }
    }

private:
    T* m_pointer;
};

}

#endif // !__SMARTPOINTER_H__