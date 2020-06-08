#include "Exception.h"

namespace LMSLib
{

void Exception::init(const char* msg, const char* file, const int line)
{
    if(NULL != msg)
    {
        m_pMessage = static_cast<char*>( malloc(strlen(msg) + 1) );
        if(NULL != m_pMessage)
        {
            strcpy(m_pMessage, msg);
        }
    }

    if(NULL != file)
    {
        char sl[16] = {0};
        sprintf(sl, "%d", line);

        m_pLocation = static_cast<char*>( malloc(strlen(file) + strlen(sl) + 2) );
        if(NULL != m_pLocation)
        {
            strcpy(m_pLocation, file);
            strcat(m_pLocation, ":");
            strcat(m_pLocation, sl);
        }
    }    
}

Exception::Exception(const char* msg):m_pMessage(NULL), m_pLocation(NULL)
{
    init(msg, NULL, 0);
}

Exception::Exception(const char* file, const int line)
{
    init(NULL, file, line);
}

Exception::Exception(const char* msg, const char* file, const int line)
{
    init(msg, file, line);
}

Exception::Exception(const Exception& obj)
{
    this->m_pMessage = static_cast<char*>( malloc( strlen(obj.m_pMessage) + 1 ) );
    if(NULL != this->m_pMessage)
    {
        strcpy(this->m_pMessage, obj.m_pMessage);
    }

    this->m_pLocation = static_cast<char*>( malloc(strlen(obj.m_pLocation) + 1 ) );
    if(NULL != this->m_pLocation)
    {
        strcpy(this->m_pLocation, obj.m_pLocation);
    }
}

Exception& Exception::operator = (const Exception& obj)
{
    if(this != &obj)
    {
        this->m_pMessage = static_cast<char*>( malloc(strlen(obj.m_pMessage) + 1 ) );
        if(NULL != this->m_pMessage)
        {
            strcpy(this->m_pMessage, obj.m_pMessage);
        }

        this->m_pLocation = static_cast<char*>( malloc(strlen(obj.m_pLocation) + 1 ) );
        if(NULL != this->m_pLocation)
        {
            strcpy(this->m_pLocation, obj.m_pLocation);
        }
    }
}

char* Exception::message()
{
    return m_pMessage;
}

char* Exception::location()
{
    return m_pLocation;
}

Exception::~Exception()
{
    if(m_pLocation)
    {
        free(m_pLocation);
        m_pLocation = NULL;
    }

    if(m_pMessage)
    {
        free(m_pMessage);
        m_pMessage = NULL;
    }
}

}

