/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "rxobject.h"
#include "rxboiler.h"
#include "gcbasedefs.h" 

#pragma pack(push, 8)

class GcRxCopyOnWriteObject : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxCopyOnWriteObject, GCBASE_PORT);
  GCBASE_PORT GcRxCopyOnWriteObject(GcRxObject* pData);
  GCBASE_PORT GcRxCopyOnWriteObject(const GcRxCopyOnWriteObject& other);
  GCBASE_PORT ~GcRxCopyOnWriteObject();
  GCBASE_PORT const GcRxCopyOnWriteObject& operator=(const GcRxCopyOnWriteObject& other);
protected:
  GCBASE_PORT GcRxObject* write();
  GCBASE_PORT const GcRxObject* read() const;
  GCBASE_PORT void unshare();
private:
  void* m_pData;
};

#define GCRX_DECLARE_MEMBERS_READWRITE_EXPIMP(CLASS_NAME, DATA_NAME, EXPIMP)   \
    GCRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, EXPIMP);            \
    DATA_NAME* write()                                          \
    {                                                           \
        return (DATA_NAME*)GcRxCopyOnWriteObject::write();      \
    }                                                           \
    const DATA_NAME* read() const                               \
    {                                                           \
        return (const DATA_NAME*)GcRxCopyOnWriteObject::read(); \
    }

#define GCRX_EMPTY

#define GCRX_DECLARE_MEMBERS_READWRITE(CLASS_NAME, DATA_NAME) \
    GCRX_DECLARE_MEMBERS_READWRITE_EXPIMP(CLASS_NAME, DATA_NAME, GCRX_EMPTY )

#pragma pack(pop)
