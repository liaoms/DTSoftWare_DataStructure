#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "List.h"
#include "Exception.h"

namespace LMSLib
{


template <typename T>
class LinkList : public List<T>
{
protected:
    struct STNode : public Object
    {
        T value;
        STNode* next;
    };

    mutable struct : public Object
    {
        char reserv[sizeof(T)];
        STNode* next;
    }m_header;

    virtual STNode* create(const T& e)
    {
        STNode* ret = new STNode();
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

private:
    int m_length;
    int m_step;
    STNode* m_curNode;


public:

    LinkList()
    {
        m_length = 0;
        m_header.next = NULL;
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
            newNode->next = pos->next;
            if(pos == m_curNode)
            {
                m_curNode = newNode;
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

    bool mov(int index, int step=1)
    {
        bool ret = (index >= 0) && (index < m_length);

        if(ret)
        {
            m_curNode = position(index);
            m_step = step;
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
            if(NULL == m_curNode->next)
            {
                break;
            }
            else
            {
                m_curNode = m_curNode->next;
            }
        }
    }

    bool end()
    {
        return NULL == m_curNode->next;
    }

    T current()
    {
        if(m_curNode->next)
        {
            return m_curNode->next->value;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "current linkList Node is NULL");
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

    virtual ~LinkList()
    {
        clear();
    }
};

}


#endif // !__LINKLIST_H__