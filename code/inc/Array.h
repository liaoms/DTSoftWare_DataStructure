#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "Object.h"

namespace LMSLib
{

template <typename T>
class Array : public Object
{
public:
    virtual bool set(int index, const T& e) = 0;
    virtual bool get(int index, T& e) = 0;
    virtual T& operator [](int index) = 0;
    virtual T operator [](int index) const = 0;
    virtual int length() = 0;

protected:
    T* m_pArray;
    int m_length;
};

}


#endif // !__ARRAY_H__