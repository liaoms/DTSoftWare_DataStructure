#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

namespace LMSLib
{

#define THROW_EXCEPTION(e, msg) (throw e(msg, __FILE__, __LINE__))

//异常基类
class Exception : public Object
{
private:
    void init(const char* msg, const char* file, const int line);

public:
    Exception(const char* msg);
    Exception(const char* file, const int line);
    Exception(const char* msg, const char* file, const int line);

    Exception(const Exception& obj);
    Exception& operator = (const Exception& obj);

    virtual char* message();
    virtual char* location();

    virtual ~Exception() = 0;

private:
    char* m_pMessage;
    char* m_pLocation;
};

//计算异常
class ArithmeticException : public Exception
{
public:
    ArithmeticException(const char* msg):Exception(msg){}

    ArithmeticException(const char* file, const int line):Exception(file, line){}

    ArithmeticException(const char* msg, const char* file, const int line):Exception(msg, file, line){}

    ArithmeticException& operator = (const ArithmeticException& obj)
    {
        Exception::operator=(obj);
        return *this;
    }
};

//内存不够
class NoEnoughMemeryException : public Exception
{
public:
    NoEnoughMemeryException(const char* msg):Exception(msg){}

    NoEnoughMemeryException(const char* file, const int line):Exception(file, line){}

    NoEnoughMemeryException(const char* msg, const char* file, const int line):Exception(msg, file, line){}

    NoEnoughMemeryException& operator = (const NoEnoughMemeryException& obj)
    {
        Exception::operator=(obj);
        return *this;
    }
};

//空指针
class NullPointerException : public Exception
{
public:
    NullPointerException(const char* msg):Exception(msg){}

    NullPointerException(const char* file, const int line):Exception(file, line){}

    NullPointerException(const char* msg, const char* file, const int line):Exception(msg, file, line){}

    NullPointerException& operator = (const NullPointerException& obj)
    {
        Exception::operator=(obj);
        return *this;
    }
};

//参数错误
class InvalidParaException : public Exception
{
public:
    InvalidParaException(const char* msg):Exception(msg){}

    InvalidParaException(const char* file, const int line):Exception(file, line){}

    InvalidParaException(const char* msg, const char* file, const int line):Exception(msg, file, line){}

    InvalidParaException& operator = (const InvalidParaException& obj)
    {
        Exception::operator=(obj);
        return *this;
    }
};

//下标越界
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException(const char* msg):Exception(msg){}

    IndexOutOfBoundsException(const char* file, const int line):Exception(file, line){}

    IndexOutOfBoundsException(const char* msg, const char* file, const int line):Exception(msg, file, line){}

    IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException& obj)
    {
        Exception::operator=(obj);
        return *this;
    }
};

}

#endif // __EXCEPTION_H__!