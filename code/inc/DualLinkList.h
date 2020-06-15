#ifndef __DUALLINKLIST_H__
#define __DUALLINKLIST_H__

#include "List.h"
#include "Exception.h"

namespace LMSLib
{
template <typename T>
class DualLinkList : public List<T>
{
protected:
    struct STNode : public Object
    {
        T value;
        STNode* pre;
        STNode* next;
    };

    mutable struct : public Object
    {
        char reserv[sizeof(T)];
        STNode* pre;
        STNode* next;
    }m_header;

    virtual STNode* create(const T& e)
    {
        STNode* ret = new STNode();
        ret->pre = NULL;
        ret->next = NULL;
        ret->value = e;
        return ret;
    }

    virtual void destroy(STNode* p)
    {   
        delete p;
    }

    STNode* position(int index) const
    {
        STNode* pos = reinterpret_cast<STNode*>(&m_header);
        for(int i=0; i<index; i++)
        {
            pos = pos->next; 
        }
        return pos;
    }

protected:
    int m_length;
    int m_step;
    bool m_bDirection;   //true-正向遍历   false-反向遍历
    STNode* m_curNode;

public:

    DualLinkList()
    {
        m_length = 0;
        m_header.pre = NULL;
        m_header.next = NULL;
        m_step = 1;
        m_curNode = reinterpret_cast<STNode*>(&m_header)->next;
    }

    bool insert(const T e) 
    {
        return insert(m_length, e);
    }

    bool insert(int index, const T e) 
    {
        bool ret = (index >= 0) && (index <= m_length);

        if(ret)
        {
            STNode* pos = position(index);

            STNode* newNode = create(e);
            if(NULL == newNode)
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memery to use!");
            }
            newNode->pre = pos;
            newNode->next = pos->next;
            if(pos->next == m_curNode)
            {
                m_curNode = newNode;
            }
            if(NULL != pos->next)
            {
                pos->next->pre = newNode;
            }
            pos->next = newNode;

            m_length++;
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
        bool ret = (index >= 0) && (index < m_length);
        if(ret)
        {
            STNode* pos = position(index);

            STNode* toDel = pos->next;
            if(toDel == m_curNode)
            {
                m_curNode = toDel->next;
            }
            
            if(NULL != toDel->next)
            {
                toDel->next->pre = pos;
            }
            
            pos->next = toDel->next;
            e = toDel->value;
            destroy(toDel);

            m_length--;
        }
        else
        {
            THROW_EXCEPTION(InvalidParaException, "Invalid Para Error");
        }
        return ret;
    }

    bool set(int index, const T e) 
    {
        bool ret = (index >= 0) && (index < m_length);

        if(ret)
        {
            STNode* pos = position(index);

            pos->next->value = e;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }

    bool get(int index, T& e) const 
    {
        bool ret = (index >= 0) && (index < m_length);

        if(ret)
        {
            STNode* pos = position(index);

            e = pos->next->value;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }

    int find(const T e) const 
    {
        int ret = -1;

        if(ret)
        {
            STNode* pos = reinterpret_cast<STNode*>(&m_header);

            for(int i=0; i<m_length; i++)
            {
                if(e == pos->next->value)
                {
                    ret = i;
                    break;
                }
                pos = pos->next;
            }
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }

    bool mov(int index, int step=1, bool direction = true)
    {
        bool ret = (index >= 0) && (index < m_length);

        if(ret)
        {
            m_curNode = position(index)->next;
            m_step = step;
            m_bDirection = direction;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        
        return ret;
    }

    void next()
    {
        for(int i=0; i<m_step; i++)
        {
            if(NULL == m_curNode)
            {
                break;
            }
            else
            {
                m_curNode = m_bDirection ? m_curNode->next : m_curNode->pre;
            }
        }
    }

    bool end()
    {
        return NULL == m_curNode;
    }

    T current()
    {
        if(m_curNode)
        {
            return m_curNode->value;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "current DualLinkList Node is NULL");
        }  
    }

    int length() const 
    {
        return m_length;
    }

    void clear() 
    {
        while (m_length > 0)
        {
            remove(0);
        }
    }

    virtual ~DualLinkList()
    {
        clear();
    }

};


}


#endif // !__DUALLINKLIST_H__