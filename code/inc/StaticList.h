#ifndef __STATICLIST_H__
#define __STATICLIST_H__

#include "SeqList.h"

namespace LMSLib
{

template <typename T, int N>
class StaticList : public SeqList<T>
{
public:

StaticList()
{
    this->m_pArray = m_array;
}

int capacity()
{
    return N;
}

private:
    T m_array[N];

};

}


#endif // !__STATICLIST_H__