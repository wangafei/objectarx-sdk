/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GD_DBID_H
#define _GD_DBID_H 1

#include "gsoft.h"
#include "dbhandle.h"
#include "GcDbCore2dDefs.h"     

#pragma pack(push, 8)

class GcDbDatabase;
class GcDbStub;
class GcRxClass;

class GCDB_PORT GcDbObjectId
{
public:
  GcDbObjectId();
  GcDbObjectId(const GcDbStub*);

  static const   GcDbObjectId  kNull;
  bool           isNull() const;
  void           setNull();
  Gsoft::IntDbId asOldId() const;
  GcDbObjectId&  setFromOldId(Gsoft::IntDbId oldId);
#if (defined(_WIN64) || defined(_GC64)) && defined(_GSOFT_WINDOWS_)
private:
  GcDbObjectId&  setFromOldId(long);
public:
  inline GcDbObjectId&  setFromOldId(Gsoft::UIntPtr nUnsignedId)
  {
    const Gsoft::IntDbId nSignedId =
      static_cast<Gsoft::IntDbId>(nUnsignedId);
    return this->setFromOldId(nSignedId);
  }
#endif

  bool isValid() const;
  bool isWellBehaved() const;

  GcDbObjectId&  operator =  (const GcDbObjectId&);
  GcDbObjectId&  operator =  (const GcDbStub*);
  bool           operator <  (const GcDbObjectId&) const;
  bool           operator >  (const GcDbObjectId&) const;
  bool           operator >= (const GcDbObjectId&) const;
  bool           operator <= (const GcDbObjectId&) const;
  bool           operator == (const GcDbObjectId&) const;
  bool           operator != (const GcDbObjectId&) const;
  bool           operator <  (const GcDbStub*) const;
  bool           operator >  (const GcDbStub*) const;
  bool           operator >= (const GcDbStub*) const;
  bool           operator <= (const GcDbStub*) const;
  bool           operator == (const GcDbStub*) const;
  bool           operator != (const GcDbStub*) const;

  operator GcDbStub*   () const;
  GcDbDatabase* database() const;
  GcDbDatabase* originalDatabase() const;
  bool convertToRedirectedId();
  bool          isErased() const;
  bool          isEffectivelyErased() const;
  bool          isResident() const;
  bool          objectLeftOnDisk() const;
  GcDbHandle    handle() const;
  GcDbHandle    nonForwardedHandle() const;
  GcRxClass*    objectClass() const;

protected:
  GcDbStub*  mId;
};

class GcDbHardOwnershipId : public GcDbObjectId
{
public:
  GcDbHardOwnershipId();
  GcDbHardOwnershipId(const GcDbObjectId&);
  GcDbHardOwnershipId(const GcDbStub*);

  GcDbHardOwnershipId& operator =(const GcDbHardOwnershipId&);
  GcDbHardOwnershipId& operator =(const GcDbObjectId&);
  GcDbHardOwnershipId& operator =(const GcDbStub*);

  bool           operator != (const GcDbObjectId&) const;
  bool           operator != (const GcDbStub*) const;
  bool           operator == (const GcDbObjectId&) const;
  bool           operator == (const GcDbStub*) const;

  operator GcDbStub* () const;
};

class GcDbSoftOwnershipId : public GcDbObjectId
{
public:
  GcDbSoftOwnershipId();
  GcDbSoftOwnershipId(const GcDbObjectId&);
  GcDbSoftOwnershipId(const GcDbStub*);

  GcDbSoftOwnershipId& operator =(const GcDbSoftOwnershipId&);
  GcDbSoftOwnershipId& operator =(const GcDbObjectId&);
  GcDbSoftOwnershipId& operator =(const GcDbStub*);
  bool           operator != (const GcDbObjectId&) const;
  bool           operator != (const GcDbStub*) const;
  bool           operator == (const GcDbObjectId&) const;
  bool           operator == (const GcDbStub*) const;

  operator GcDbStub* () const;
};

class GcDbHardPointerId : public GcDbObjectId
{
public:
  GcDbHardPointerId();
  GcDbHardPointerId(const GcDbObjectId&);
  GcDbHardPointerId(const GcDbStub*);

  GcDbHardPointerId& operator =(const GcDbHardPointerId&);
  GcDbHardPointerId& operator =(const GcDbObjectId&);
  GcDbHardPointerId& operator =(const GcDbStub*);
  bool           operator != (const GcDbObjectId&) const;
  bool           operator != (const GcDbStub*) const;
  bool           operator == (const GcDbObjectId&) const;
  bool           operator == (const GcDbStub*) const;

  operator GcDbStub* () const;
};

class GcDbSoftPointerId : public GcDbObjectId
{
public:
  GcDbSoftPointerId();
  GcDbSoftPointerId(const GcDbObjectId&);
  GcDbSoftPointerId(const GcDbStub*);

  GcDbSoftPointerId& operator =(const GcDbSoftPointerId&);
  GcDbSoftPointerId& operator =(const GcDbObjectId&);
  GcDbSoftPointerId& operator =(const GcDbStub*);
  bool           operator != (const GcDbObjectId&) const;
  bool           operator != (const GcDbStub*) const;
  bool           operator == (const GcDbObjectId&) const;
  bool           operator == (const GcDbStub*) const;

  operator GcDbStub* () const;
};

#pragma pack(pop)

__declspec(selectany) const GcDbObjectId  GcDbObjectId::kNull;

inline
GcDbObjectId::GcDbObjectId()
{
  mId = nullptr;
}

inline
GcDbObjectId::GcDbObjectId(const GcDbStub* pStub)
{
  mId = const_cast<GcDbStub*>(pStub);
}

inline bool
GcDbObjectId::isNull() const
{
  return mId == nullptr;
}

inline void
GcDbObjectId::setNull()
{
  mId = nullptr;
}

inline
Gsoft::IntDbId GcDbObjectId::asOldId() const
{
  return reinterpret_cast<Gsoft::IntDbId>(this->mId);
}

inline
GcDbObjectId& GcDbObjectId::setFromOldId(Gsoft::IntDbId oldId)
{
  this->mId = reinterpret_cast<GcDbStub*>(oldId);
  return *this;
}

inline
GcDbObjectId& GcDbObjectId::operator = (const GcDbObjectId& id)
{
  mId = id.mId; return *this;
}

inline
GcDbObjectId& GcDbObjectId::operator = (const GcDbStub* pStub)
{
  mId = const_cast<GcDbStub*>(pStub); return *this;
}

inline
GcDbObjectId::operator GcDbStub* () const
{
  return mId;
}

inline
GcDbHardOwnershipId::GcDbHardOwnershipId() {}

inline
GcDbHardOwnershipId::GcDbHardOwnershipId(const GcDbObjectId& id)
  : GcDbObjectId(id) {}

inline
GcDbHardOwnershipId::GcDbHardOwnershipId(const GcDbStub* pStub)
  : GcDbObjectId(pStub) {}

inline
GcDbHardOwnershipId& GcDbHardOwnershipId::operator  = (
  const GcDbHardOwnershipId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbHardOwnershipId& GcDbHardOwnershipId::operator = (const GcDbObjectId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbHardOwnershipId& GcDbHardOwnershipId::operator = (const GcDbStub* pStub)
{
  mId = const_cast<GcDbStub*>(pStub); return *this;
}

inline
bool GcDbHardOwnershipId::operator != (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator!=(id);
}

inline
bool GcDbHardOwnershipId::operator != (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator!=(pStub);
}

inline
bool GcDbHardOwnershipId::operator == (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator==(id);
}

inline
bool GcDbHardOwnershipId::operator == (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator==(pStub);
}

inline
GcDbHardOwnershipId::operator GcDbStub* () const
{
  return mId;
}

inline
GcDbSoftOwnershipId::GcDbSoftOwnershipId() {}

inline
GcDbSoftOwnershipId::GcDbSoftOwnershipId(const GcDbObjectId& id)
  : GcDbObjectId(id) {}

inline
GcDbSoftOwnershipId::GcDbSoftOwnershipId(const GcDbStub* pStub)
  : GcDbObjectId(pStub) {}

inline
GcDbSoftOwnershipId& GcDbSoftOwnershipId::operator = (
  const GcDbSoftOwnershipId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbSoftOwnershipId& GcDbSoftOwnershipId::operator = (const GcDbObjectId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbSoftOwnershipId& GcDbSoftOwnershipId::operator = (const GcDbStub* pStub)
{
  mId = const_cast<GcDbStub*>(pStub); return *this;
}

inline
bool GcDbSoftOwnershipId::operator != (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator!=(id);
}

inline
bool GcDbSoftOwnershipId::operator != (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator!=(pStub);
}

inline
bool GcDbSoftOwnershipId::operator == (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator==(id);
}

inline
bool GcDbSoftOwnershipId::operator == (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator==(pStub);
}

inline
GcDbSoftOwnershipId::operator GcDbStub* () const
{
  return mId;
}

inline
GcDbHardPointerId::GcDbHardPointerId() {}

inline
GcDbHardPointerId::GcDbHardPointerId(const GcDbObjectId& id)
  : GcDbObjectId(id) {}

inline
GcDbHardPointerId::GcDbHardPointerId(const GcDbStub* pStub)
  : GcDbObjectId(pStub) {}

inline
GcDbHardPointerId& GcDbHardPointerId::operator = (
  const GcDbHardPointerId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbHardPointerId& GcDbHardPointerId::operator = (const GcDbObjectId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbHardPointerId& GcDbHardPointerId::operator = (const GcDbStub* pStub)
{
  mId = const_cast<GcDbStub*>(pStub); return *this;
}

inline
bool GcDbHardPointerId::operator != (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator!=(id);
}

inline
bool GcDbHardPointerId::operator != (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator!=(pStub);
}

inline
bool GcDbHardPointerId::operator == (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator==(id);
}

inline
bool GcDbHardPointerId::operator == (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator==(pStub);
}

inline
GcDbHardPointerId::operator GcDbStub* () const
{
  return mId;
}

inline
GcDbSoftPointerId::GcDbSoftPointerId() {}

inline
GcDbSoftPointerId::GcDbSoftPointerId(const GcDbObjectId& id)
  : GcDbObjectId(id) {}

inline
GcDbSoftPointerId::GcDbSoftPointerId(const GcDbStub* pStub)
  : GcDbObjectId(pStub) {}

inline
GcDbSoftPointerId& GcDbSoftPointerId::operator = (const GcDbSoftPointerId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbSoftPointerId& GcDbSoftPointerId::operator = (const GcDbObjectId& id)
{
  GcDbObjectId::operator=(id); return *this;
}

inline
GcDbSoftPointerId& GcDbSoftPointerId::operator = (const GcDbStub* pStub)
{
  mId = const_cast<GcDbStub*>(pStub); return *this;
}

inline
bool GcDbSoftPointerId::operator != (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator!=(id);
}

inline
bool GcDbSoftPointerId::operator != (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator!=(pStub);
}

inline
bool GcDbSoftPointerId::operator == (const GcDbObjectId& id) const
{
  return GcDbObjectId::operator==(id);
}

inline
bool GcDbSoftPointerId::operator == (const GcDbStub* pStub) const
{
  return GcDbObjectId::operator==(pStub);
}

inline
GcDbSoftPointerId::operator GcDbStub* () const
{
  return mId;
}

#define GSFT_GCDBOBJECTID_DEFINED
#include "gcarrayhelper.h"

#endif