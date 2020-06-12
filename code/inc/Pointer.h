#ifndef __POINTER_H__
#define __POINTER_H__

#include "Object.h"

namespace LMSLib
{

template <typename T>
class Pointer : public Object
{
protected:
    T *m_pointer;

public:

    Pointer(T* pointer)
    {
        m_pointer = pointer;
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

    T* operator -> () const
    {
        return m_pointer;
    }

    T& operator *() const
    {
        return *m_pointer;
    }

    T* get() const
    {
        return m_pointer;
    }

    T& value() const
    {
        return *m_pointer;
    }

    bool isNull() const
    {
        return NULL == m_pointer;
    }
};

}

#endif // !__POINTER_H__