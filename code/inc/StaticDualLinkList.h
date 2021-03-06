#ifndef __STATICDUALLINKLIST_H__
#define __STATICDUALLINKLIST_H__

#include "DualLinkList.h"

namespace LMSLib
{

template <typename T, int N>
class StaticDualLinkList : public DualLinkList<T>
{
protected:
    typedef typename DualLinkList<T>::STNode STNode;

    struct SSTNode : public STNode
    {
        void * operator new (unsigned int size, void* loc)
        {
            return loc;
        }
    };
    
    char m_space[N * sizeof(SSTNode)];
    char m_use[N];

    STNode* create(const T& e)
    {
        SSTNode* ret = NULL;
        for(int i=0; i<N; i++)
        {
            if(0 == m_use[i])
            {
                ret = reinterpret_cast<SSTNode*>(m_space) + i;
                ret = new(ret) SSTNode();
                ret->value = e;
                m_use[i] = 1;
                break;
            }
        }
        return ret;
    }

    void destroy(STNode* p)
    {
        SSTNode* space = reinterpret_cast<SSTNode*>(m_space);
        SSTNode* sp = dynamic_cast<SSTNode*>(p);

        for(int i=0; i<N; i++)
        {
            if(sp == (space + i))
            {
                m_use[i] = 0;
                sp->~SSTNode();
                break;
            }
        }
    }

public:
    StaticDualLinkList()
    {
        for(int i=0; i<N; i++)
        {
            m_use[i] = 0;
        }
    }

    int cpacity()
    {
        return N;
    }

    ~StaticDualLinkList()
    {
        this->clear();
    }
};

}


#endif // !__STATICDUALLINKLIST_H__