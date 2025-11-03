
#ifndef AECMODELER_INC_ENTITY_H
#define AECMODELER_INC_ENTITY_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwEntity
{
public:

    ZwEntity() : mFlags(0) {}
    virtual ~ZwEntity()    {}

    ZwFlag flags     ()           const { return mFlags;               }
    void setFlags  (ZwFlag flags)       { mFlags = flags;              }
    bool isFlagOn  (ZwFlag flag)  const { return (mFlags & flag) != 0; }
    bool isFlagOff (ZwFlag flag)  const { return (mFlags & flag) == 0; }
    void setFlagOn (ZwFlag flag)        { mFlags |=  flag;             }
    void setFlagOff(ZwFlag flag)        { mFlags &= ~flag;             }
    void flipFlag  (ZwFlag flag)        { mFlags ^=  flag;             }

#undef new
#undef delete


    void* operator new   (size_t); 
    void  operator delete(void*); 

#ifdef _DEBUG

    void* operator new   (size_t, const char* lpszFileName, int nLine);
    void operator  delete(void*,  const char* lpszFileName, int nLine);
#endif

private:
    ZwFlag mFlags;

};


AECMODELER_NAMESPACE_END
#endif
