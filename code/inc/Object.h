#ifndef __OBJECT_H__
#define __OBJECT_H__

namespace LMSLib
{

class Object
{
public:
    void* operator new (unsigned int size) throw();
    void operator delete (void *p);
    void* operator new[](unsigned int size)throw();
    void operator delete[](void* p);

    bool operator == (const Object& obj);
    bool operator != (const Object& obj);

    virtual ~Object() = 0;

};


}

#endif // !__OBJECT_H__