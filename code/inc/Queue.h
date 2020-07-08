#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Object.h"

namespace LMSLib
{
template <typename T>
class Queue : public Object
{
public:
    virtual bool add(const T& e) = 0;
    virtual bool remove() = 0;
    virtual T front() = 0;
    virtual void clear() = 0;
    virtual int length() = 0;
};

}

#endif // !__QUEUE_H__