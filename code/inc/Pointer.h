#ifndef __POINTER_H__
#define __POINTER_H__

#include "Object.h"
#include "Exception.h"

namespace LMSLib
{

template <typename T>
class Pointer : public Object
{
protected:
    T *m_pointer;

public:

    T* operator -> ()
    {
        return m_pointer;
    }

    T& operator *()
    {
        if(NULL != m_pointer)
        {
            return *m_pointer;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "pointer is NULL");
        }
    }

    T* get()
    {
        return m_pointer;
    }

    T& value()
    {
        if(NULL != m_pointer)
        {
            return *m_pointer;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "pointer is NULL");
        }
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
        if(NULL != m_pointer)
        {
            return *m_pointer;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "pointer is NULL");
        }
    }

    T* get() const
    {
        return m_pointer;
    }

    T& value() const
    {
        if(NULL != m_pointer)
        {
            return *m_pointer;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "pointer is NULL");
        }
    }

    bool isNull() const
    {
        return NULL == m_pointer;
    }
};

}

#endif // !__POINTER_H__