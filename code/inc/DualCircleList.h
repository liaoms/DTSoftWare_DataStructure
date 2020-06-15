#ifndef __DUALCIRCLELIST_H__
#define __DUALCIRCLELIST_H__

#include "DualLinkList.h"

namespace LMSLib
{

template <typename T>
class DualCircleList : public DualLinkList<T>
{
private:
    typedef typename DualLinkList<T>::STNode STNode;

    STNode* m_head;
    STNode* m_tail;

    void last_to_first()
    {
        m_tail->next = m_head;
        m_head->pre = m_tail;
    }

public:
    DualCircleList()
    {
        m_head = (this->m_header).next;
        m_tail = m_head;
    }

    bool insert(const T e) 
    {
        return insert(this->m_length, e);
    }

    bool insert(int index, const T e) 
    {
        bool ret = (index >= 0) && (index <= this->m_length);

        if(ret)
        {
            STNode* pos = this->position(index);

            STNode* newNode = create(e);
            if(NULL == newNode)
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to use!");
            }
            newNode->pre = pos;
            newNode->next = pos->next;
            if(pos == this->m_curNode)
            {
                this->m_curNode = newNode;
            }
            if(NULL != pos->next)
            {
                pos->next->pre = newNode;
            }
            pos->next = newNode;

            if(0 == index)
            {
                m_head = newNode;
            }

            if(index == this->m_length)
            {
                m_tail = newNode;
            }

            last_to_first();

            (this->m_length)++;
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Invalid Para Error!");
        }
        return ret;
    }

    bool remove(int index) 
    {
        T tmp;
        return remove(index, tmp);
    }

    bool remove(int index, T& e) 
    {
        bool ret = (index >= 0) && (index < this->m_length);
        if(ret)
        {
            STNode* pos = this->position(index);

            STNode* toDel = pos->next;
            if(toDel == this->m_curNode)
            {
                this->m_curNode = toDel->next;
            }
            
            if(NULL != toDel->next)
            {
                toDel->next->pre = pos;
            }
            
            pos->next = toDel->next;

            if(0 == index)
            {
                m_head = toDel->next;
                last_to_first();
            }
            else if(index == this->m_length-1)
            {
                m_tail = pos;
                last_to_first();
            }

            e = toDel->value;
            destroy(toDel);

            (this->m_length)--;
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Invalid Para Error");
        }
        return ret;
    }

};

}

#endif // !__DUALCIRCLELIST_H__