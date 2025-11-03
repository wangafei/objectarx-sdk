

#ifndef _ZD_DBID_H
#define _ZD_DBID_H 1

#include "zadesk.h"
#include "zdbhandle.h"
#include "zAcDbCore2dDefs.h"
#include "ZRXExports.h"

#pragma pack(push, 8)

class ZcDbDatabase;
class ZcDbStub;
class ZcRxClass;

class  ZCDBCORE2D_PORT ZcDbObjectId
{
public:
    ZcDbObjectId();
    ZcDbObjectId(const ZcDbStub*);

    static const   ZcDbObjectId  kNull;

    bool           isNull() const;
    void           setNull();

    ZSoft::IntDbId     asOldId     () const;
    ZcDbObjectId&  setFromOldId(ZSoft::IntDbId oldId);
#if (defined(_WIN64) || defined(_ZC64)) && defined(_ZSOFT_WINDOWS_)	
  private:

    ZcDbObjectId&  setFromOldId(long);

  public:

    inline ZcDbObjectId&  setFromOldId(ZSoft::UIntPtr nUnsignedId)
    {
        const ZSoft::IntDbId nSignedId =
                        static_cast<ZSoft::IntDbId>(nUnsignedId);
        return this->setFromOldId(nSignedId);
    }
#endif

    bool           isValid() const;
	bool isWellBehaved() const;	

    ZcDbObjectId&  operator =  (const ZcDbObjectId&);
    ZcDbObjectId&  operator =  (const ZcDbStub*);

    bool           operator <  (const ZcDbObjectId&) const;
    bool           operator >  (const ZcDbObjectId&) const;
    bool           operator >= (const ZcDbObjectId&) const;
    bool           operator <= (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbObjectId&) const;

    bool           operator <  (const ZcDbStub*) const;
    bool           operator >  (const ZcDbStub*) const;
    bool           operator >= (const ZcDbStub*) const;
    bool           operator <= (const ZcDbStub*) const;
    bool           operator == (const ZcDbStub*) const;
    bool           operator != (const ZcDbStub*) const;

    operator       ZcDbStub*   () const;

    ZcDbDatabase* database() const;
    ZcDbDatabase* originalDatabase() const;
    bool          convertToRedirectedId();	
    bool          isErased() const;
    bool          isEffectivelyErased() const;
    bool          isResident() const;
    bool          objectLeftOnDisk() const;
    ZcDbHandle    handle() const;
    ZcDbHandle    nonForwardedHandle() const;

	ZcRxClass*    objectClass() const;		
protected:
    ZcDbStub*  mId;
};

class ZCDBCORE2D_PORT ZcDbHardOwnershipId : public ZcDbObjectId
{
public:
    ZcDbHardOwnershipId();
    ZcDbHardOwnershipId(const ZcDbObjectId&);
    ZcDbHardOwnershipId(const ZcDbStub*);

    ZcDbHardOwnershipId& operator =(const ZcDbHardOwnershipId&);
    ZcDbHardOwnershipId& operator =(const ZcDbObjectId&);
    ZcDbHardOwnershipId& operator =(const ZcDbStub*);

    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

class ZCDBCORE2D_PORT ZcDbSoftOwnershipId : public ZcDbObjectId
{
public:
    ZcDbSoftOwnershipId();
    ZcDbSoftOwnershipId(const ZcDbObjectId&);
    ZcDbSoftOwnershipId(const ZcDbStub*);

    ZcDbSoftOwnershipId& operator =(const ZcDbSoftOwnershipId&);
    ZcDbSoftOwnershipId& operator =(const ZcDbObjectId&);
    ZcDbSoftOwnershipId& operator =(const ZcDbStub*);
    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

class ZCDBCORE2D_PORT ZcDbHardPointerId : public ZcDbObjectId
{
public:
    ZcDbHardPointerId();
    ZcDbHardPointerId(const ZcDbObjectId&);
    ZcDbHardPointerId(const ZcDbStub*);

    ZcDbHardPointerId& operator =(const ZcDbHardPointerId&);
    ZcDbHardPointerId& operator =(const ZcDbObjectId&);
    ZcDbHardPointerId& operator =(const ZcDbStub*);
    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

class ZCDBCORE2D_PORT ZcDbSoftPointerId : public ZcDbObjectId
{
public:
    ZcDbSoftPointerId();
    ZcDbSoftPointerId(const ZcDbObjectId&);
    ZcDbSoftPointerId(const ZcDbStub*);

    ZcDbSoftPointerId& operator =(const ZcDbSoftPointerId&);
    ZcDbSoftPointerId& operator =(const ZcDbObjectId&);
    ZcDbSoftPointerId& operator =(const ZcDbStub*);
    bool           operator != (const ZcDbObjectId&) const;
    bool           operator != (const ZcDbStub*) const;
    bool           operator == (const ZcDbObjectId&) const;
    bool           operator == (const ZcDbStub*) const;

    operator ZcDbStub* () const;
};

#pragma pack(pop)



__declspec(selectany) const ZcDbObjectId  ZcDbObjectId::kNull;

inline
ZcDbObjectId::ZcDbObjectId()
{ mId = nullptr; }

inline
ZcDbObjectId::ZcDbObjectId(const ZcDbStub* pStub)
{ mId = const_cast<ZcDbStub*>(pStub); }

inline bool
ZcDbObjectId::isNull() const
{ return mId == nullptr; }

inline void
ZcDbObjectId::setNull()
{ mId = nullptr; }

inline
ZSoft::IntDbId ZcDbObjectId::asOldId() const
{
    return reinterpret_cast<ZSoft::IntDbId>(this->mId);
}

inline
ZcDbObjectId& ZcDbObjectId::setFromOldId(ZSoft::IntDbId oldId)
{
    this->mId = reinterpret_cast<ZcDbStub*>(oldId);
    return *this;
}

inline 
ZcDbObjectId& ZcDbObjectId::operator = (const ZcDbObjectId& id)
{ mId = id.mId; return *this; }

inline 
ZcDbObjectId& ZcDbObjectId::operator = (const ZcDbStub* pStub)
{ mId = const_cast<ZcDbStub*>(pStub); return *this; }

inline
ZcDbObjectId::operator ZcDbStub* () const
{ return mId; }


bool c5ObjIdIsLessThan(const ZcDbStub * lhs, const ZcDbStub * rhs);
bool c5ObjIdIsGreaterThan(const ZcDbStub * lhs, const ZcDbStub * rhs);
bool c5ObjIdLessThanOrEqual(const ZcDbStub * lhs, const ZcDbStub * rhs);
bool c5ObjIdGreaterThanOrEqual(const ZcDbStub * lhs, const ZcDbStub * rhs);
bool c5ObjIdIsEqualTo(const ZcDbStub * lhs, const ZcDbStub * rhs);

inline bool ZcDbObjectId::operator < (const ZcDbObjectId& id) const
{ return c5ObjIdIsLessThan(*this, id); }

inline bool ZcDbObjectId::operator > (const ZcDbObjectId& id) const
{ return c5ObjIdIsGreaterThan(*this, id); }

inline bool ZcDbObjectId::operator <= (const ZcDbObjectId& id) const
{ return c5ObjIdLessThanOrEqual(*this, id); }

inline bool ZcDbObjectId::operator >= (const ZcDbObjectId& id) const
{ return c5ObjIdGreaterThanOrEqual(*this, id); }

inline bool ZcDbObjectId::operator == (const ZcDbObjectId& id) const
{ return c5ObjIdIsEqualTo(*this, id); }

inline bool ZcDbObjectId::operator != (const ZcDbObjectId& id) const
{ return !c5ObjIdIsEqualTo(*this, id); }

inline bool ZcDbObjectId::operator < (const ZcDbStub* pStub) const
{ return c5ObjIdIsLessThan(*this, pStub); }

inline bool ZcDbObjectId::operator > (const ZcDbStub* pStub) const
{ return c5ObjIdIsGreaterThan(*this, pStub); }

inline bool ZcDbObjectId::operator <= (const ZcDbStub* pStub) const
{ return c5ObjIdLessThanOrEqual(*this, pStub); }

inline bool ZcDbObjectId::operator >= (const ZcDbStub* pStub) const
{ return c5ObjIdGreaterThanOrEqual(*this, pStub); }

inline bool ZcDbObjectId::operator == (const ZcDbStub* pStub) const
{ return c5ObjIdIsEqualTo(*this, pStub); }

inline bool ZcDbObjectId::operator != (const ZcDbStub* pStub) const
{ return !c5ObjIdIsEqualTo(*this, pStub); }


inline
ZcDbHardOwnershipId::ZcDbHardOwnershipId() {}

inline
ZcDbHardOwnershipId::ZcDbHardOwnershipId(const ZcDbObjectId& id)
  : ZcDbObjectId(id) {}

inline
ZcDbHardOwnershipId::ZcDbHardOwnershipId(const ZcDbStub* pStub)
  : ZcDbObjectId(pStub) {}

inline
ZcDbHardOwnershipId& ZcDbHardOwnershipId::operator  = (
    const ZcDbHardOwnershipId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline
ZcDbHardOwnershipId& ZcDbHardOwnershipId::operator = (const ZcDbObjectId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline 
ZcDbHardOwnershipId& ZcDbHardOwnershipId::operator = (const ZcDbStub* pStub)
{ mId = const_cast<ZcDbStub*>(pStub); return *this; }

inline 
bool ZcDbHardOwnershipId::operator != (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator!=(id); }

inline 
bool ZcDbHardOwnershipId::operator != (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator!=(pStub); }

inline 
bool ZcDbHardOwnershipId::operator == (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator==(id); }

inline 
bool ZcDbHardOwnershipId::operator == (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator==(pStub); }

inline
ZcDbHardOwnershipId::operator ZcDbStub* () const
{ return mId; }

inline
ZcDbSoftOwnershipId::ZcDbSoftOwnershipId() {}

inline
ZcDbSoftOwnershipId::ZcDbSoftOwnershipId(const ZcDbObjectId& id)
  : ZcDbObjectId(id) {}

inline
ZcDbSoftOwnershipId::ZcDbSoftOwnershipId(const ZcDbStub* pStub)
  : ZcDbObjectId(pStub) {}

inline
ZcDbSoftOwnershipId& ZcDbSoftOwnershipId::operator = (
    const ZcDbSoftOwnershipId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline
ZcDbSoftOwnershipId& ZcDbSoftOwnershipId::operator = (const ZcDbObjectId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline 
ZcDbSoftOwnershipId& ZcDbSoftOwnershipId::operator = (const ZcDbStub* pStub)
{ mId = const_cast<ZcDbStub*>(pStub); return *this; }

inline 
bool ZcDbSoftOwnershipId::operator != (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator!=(id); }

inline 
bool ZcDbSoftOwnershipId::operator != (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator!=(pStub); }

inline 
bool ZcDbSoftOwnershipId::operator == (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator==(id); }

inline 
bool ZcDbSoftOwnershipId::operator == (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator==(pStub); }

inline
ZcDbSoftOwnershipId::operator ZcDbStub* () const
{ return mId; }

inline
ZcDbHardPointerId::ZcDbHardPointerId() {}

inline
ZcDbHardPointerId::ZcDbHardPointerId(const ZcDbObjectId& id)
  : ZcDbObjectId(id) {}

inline
ZcDbHardPointerId::ZcDbHardPointerId(const ZcDbStub* pStub)
  : ZcDbObjectId(pStub) {}

inline
ZcDbHardPointerId& ZcDbHardPointerId::operator = (
    const ZcDbHardPointerId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline
ZcDbHardPointerId& ZcDbHardPointerId::operator = (const ZcDbObjectId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline 
ZcDbHardPointerId& ZcDbHardPointerId::operator = (const ZcDbStub* pStub)
{ mId = const_cast<ZcDbStub*>(pStub); return *this; }

inline 
bool ZcDbHardPointerId::operator != (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator!=(id); }

inline 
bool ZcDbHardPointerId::operator != (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator!=(pStub); }

inline 
bool ZcDbHardPointerId::operator == (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator==(id); }

inline 
bool ZcDbHardPointerId::operator == (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator==(pStub); }

inline
ZcDbHardPointerId::operator ZcDbStub* () const
{ return mId; }

inline
ZcDbSoftPointerId::ZcDbSoftPointerId() {}

inline
ZcDbSoftPointerId::ZcDbSoftPointerId(const ZcDbObjectId& id)
  : ZcDbObjectId(id) {}

inline
ZcDbSoftPointerId::ZcDbSoftPointerId(const ZcDbStub* pStub)
  : ZcDbObjectId(pStub) {}

inline
ZcDbSoftPointerId& ZcDbSoftPointerId::operator = (const ZcDbSoftPointerId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline
ZcDbSoftPointerId& ZcDbSoftPointerId::operator = (const ZcDbObjectId& id)
{ ZcDbObjectId::operator=(id); return *this; }

inline 
ZcDbSoftPointerId& ZcDbSoftPointerId::operator = (const ZcDbStub* pStub)
{ mId = const_cast<ZcDbStub*>(pStub); return *this; }

inline 
bool ZcDbSoftPointerId::operator != (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator!=(id); }

inline 
bool ZcDbSoftPointerId::operator != (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator!=(pStub); }

inline 
bool ZcDbSoftPointerId::operator == (const ZcDbObjectId& id) const
{ return ZcDbObjectId::operator==(id); }

inline 
bool ZcDbSoftPointerId::operator == (const ZcDbStub* pStub) const
{ return ZcDbObjectId::operator==(pStub); }

inline
ZcDbSoftPointerId::operator ZcDbStub* () const
{ return mId; }

#define ZSOFT_ZCDBOBJECTID_DEFINED
#include "zacarrayhelper.h"

#endif
