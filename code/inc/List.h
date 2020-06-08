#ifndef __LIST_H__
#define __LIST_H__

#include "Object.h"

namespace LMSLib
{
template <typename T>
class List : public Object
{
private:
    //禁止拷贝赋值与拷贝构造
    List(const List<T>& obj);
    List<T>& operator = (const List<T>& obj);
public:
    virtual bool insert(const T e) = 0;
    virtual bool insert(int index, const T e) = 0;
    virtual bool remove(int index) = 0;
    virtual bool remove(int index, T& e) = 0;
    virtual bool set(int index, const T e) = 0;
    virtual bool get(int index, T& e) = 0;
    virtual T& get(int index) = 0;
    virtual int length() = 0;
    virtual void clear() = 0;
};


}

#endif // !__LIST_H__