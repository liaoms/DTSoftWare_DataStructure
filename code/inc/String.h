#ifndef __STRING_H__
#define __STRING_H__

#include "Object.h"
#include "Exception.h"
#include <cstring>
#include <cstdio>

namespace LMSLib
{
class String : public Object
{
private:
    char* m_str;
    int m_length;

    void init(const char* str)
    {
        if(str)
        {
            m_str = reinterpret_cast<char*>(malloc(strlen(str) + 1));
            strcpy(m_str, str);
            m_str[strlen(m_str)] = '\0';
            m_length = strlen(m_str);
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "input str is NULL");
        }     
    }

    bool equal(const char* left, const char* right, int len) const
    {
        bool ret = (strlen(left) >= len) && (strlen(right) >= len);
        for(int i=0; (i<len) && ret; i++)
        {
            ret = ret && (left[i] == right[i]);
        }
        return ret;
    }

public:
    String()
    {
        init(" ");
    }

    String(char* str)
    {
        init(str);
    }

    String(const String& obj)
    {
        init(obj.m_str);
    }

    String& operator = (const String& obj)
    {
        return *this = obj.m_str;
    }

    String& operator = (const char* str)
    {
        
        if(m_str != str)
        {
            char* tmp = strdup(str ? str : "");

            if(tmp)
            {
                free(m_str);
                m_str = tmp;
                m_length = strlen(m_str);
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memory to use!");
            }
        }
        return *this;
    } 

    bool operator > (const String& obj) const
    {
        return ( strcmp(m_str, obj.m_str) > 0 );
    }

    bool operator > (const char* str) const
    {
        return ( strcmp(m_str, str) > 0 );
    }

    bool operator >= (const String& obj) const
    {
        return ( strcmp(m_str, obj.m_str) >= 0 );
    }

    bool operator >= (const char* str) const
    {
        return ( strcmp(m_str, str) >= 0 );
    }

    bool operator < (const String& obj) const
    {
        return ( strcmp(m_str, obj.m_str) < 0 );
    }

    bool operator < (const char* str) const
    {
        return ( strcmp(m_str, str) < 0 );
    }

    bool operator <= (const String& obj) const
    {
        return ( strcmp(m_str, obj.m_str) <= 0 );
    }

    bool operator <= (const char* str) const
    {
        return ( strcmp(m_str, str) <= 0 );
    }

    bool operator == (const String& obj) const
    {
        return ( strcmp(m_str, obj.m_str) == 0 );
    }

    bool operator == (const char* str) const
    {
        return ( strcmp(m_str, str) == 0 );
    }

    bool operator != (const String& obj) const
    {
        return !(*this == obj);
    }

    bool operator != (const char* str) const
    {
        return !(*this == str);
    }

    void operator += (const String& obj)
    {
        append(obj);
    }

    void operator += (const char* str)
    {
        append(str);
    }

    bool startWith(String& obj) const
    {
        return startWith(obj.m_str);
    }

    bool startWith(const char* str) const
    {
        bool ret = m_length >= strlen(str);
        if(ret)
        {
            ret = equal(m_str, str, strlen(str));
        }

        return ret;
    }

    bool endWith(String& obj) const
    {
        return endWith(obj.m_str);
    }

    bool endWith(const char* str) const
    {
        bool ret = m_length >= strlen(str);
        if(ret)
        {
            char* dest = m_str + ( m_length - strlen(str) );

            ret = equal(dest, str, strlen(str) );
        }
        return ret;
    }

    char operator [] (int index)
    {
        bool ret = index < m_length;
        if(ret)
        {
            return m_str[index];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
    }

    char operator [] (int index) const
    {
        return const_cast<String&>(*this)[index];
    }

    bool insert(const int index, const char* str)
    {
        bool ret = (index >= 0) && (index <= m_length);
        if(ret)
        {
            char* tmp = reinterpret_cast<char*>(malloc(m_length + strlen(str) + 1));

            if(tmp)
            {
                strncpy(tmp, m_str, index);  
                strcat(tmp, str);
                strcat(tmp, m_str + index);
                tmp[strlen(tmp)] = '\0';

                free(m_str);

                m_str = tmp;
                m_length = strlen(m_str);
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemeryException, "No Enough Memory to Use");
            }
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds!");
        }
        return ret;
    }

    bool insert(const int index, const String& obj)
    {
        return insert(index, obj.m_str);
    }

    bool append(const String& obj)
    {
        return append(obj.m_str);
    }

    bool append(const char* str)
    {
        return insert(m_length, str);
    }

    int length() const
    {
        return m_length;
    }

    char* str() const
    {
        return m_str;
    }
};

}

#endif // !__STRING_H__