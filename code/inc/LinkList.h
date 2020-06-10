#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "List.h"
#include "Exception.h"

namespace LMSLib
{


template <typename T>
class LinkList : List<T>
{
protected:
    struct STNode : public Object
    {
        T value;
        STNode* next;

        STNode(T e) : value(e), next(NULL)
        {

        }
    };

    mutable struct : public Object
    {
        char reserv[sizeof(T)];
        STNode* next;
    }m_header;

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

            STNode* newNode = new STNode(e);
            newNode->next = pos->next;
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
            pos->next = toDel->next;
            e = toDel->value;
            delete toDel;
            toDel = NULL;

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

    ~LinkList()
    {
        clear();
    }
};

}


#endif // !__LINKLIST_H__