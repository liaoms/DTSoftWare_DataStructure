#ifndef __STACK_H__
#define __STACK_H__

#include "Object.h"

namespace LMSLib
{
template <typename T>
class Stack : public Object
{
public:
    virtual bool push(const T& e) = 0;
    virtual bool pop() = 0;
    virtual T top() = 0;
    virtual bool clear() = 0;
    virtual int size() = 0;
};


} 

#endif // !__STACK_H__