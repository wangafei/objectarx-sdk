/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GEOMENT_DBSUBEID_H
#define GEOMENT_DBSUBEID_H

#include "gcdb.h"
#include "dbidar.h"

#pragma pack (push, 8)

class GcDbSubentId
{
public:
  GcDbSubentId();
  GcDbSubentId(GcDb::SubentType type, Gsoft::GsMarker index);
  GcDbSubentId(GcRxClass* pTypeClass, Gsoft::GsMarker index);
#ifdef __clang__
  ~GcDbSubentId() {};
#endif

  bool               operator ==(const GcDbSubentId& id) const;
  bool               operator !=(const GcDbSubentId& id) const;

  GcDb::SubentType   type() const;
  void               setType(GcDb::SubentType);
  GcRxClass*         typeClass() const;
  void               setTypeClass(GcRxClass* pClass);
  Gsoft::GsMarker    index() const;
  void               setIndex(Gsoft::GsMarker);

  static const GcDbSubentId kNull;

private:
  GcDb::SubentType mType;
  Gsoft::GsMarker  mIndex;
  GcRxClass*       mpTypeClass;
};

const Gsoft::GsMarker kNullSubentIndex = 0;

__declspec(selectany) extern const GcDbSubentId kNullSubentId(GcDb::kNullSubentType, kNullSubentIndex);

class GCDB_PORT GcDbFullSubentPath
{
public:
  GcDbFullSubentPath();
  GcDbFullSubentPath(GcDb::SubentType type, Gsoft::GsMarker index);
  GcDbFullSubentPath(GcDbObjectId entId, GcDb::SubentType type, Gsoft::GsMarker index);
  GcDbFullSubentPath(GcDbObjectId entId, GcDbSubentId subId);
  GcDbFullSubentPath(GcDbObjectIdArray objectIds, GcDbSubentId subId);
  GcDbFullSubentPath(const GcDbFullSubentPath&);
  ~GcDbFullSubentPath();

  GcDbFullSubentPath&     operator =  (const GcDbFullSubentPath&);

  bool           operator ==(const GcDbFullSubentPath& id) const;
  bool           operator !=(const GcDbFullSubentPath& id) const;

  void                setObjectIds(const GcDbObjectIdArray& objectIds);
  void                objectIds(GcDbObjectIdArray& objectIds) const;
  GcDbObjectIdArray&  objectIds();
  const GcDbObjectIdArray&  objectIds() const;
  void                setSubentId(const GcDbSubentId& subentId);
  const GcDbSubentId  subentId() const;
  GcDbSubentId&       subentId();
  void* userAppData() const;
  void setUserAppData(void* pData);

  GCDB_PORT_STATIC static const GcDbFullSubentPath kNull;

private:
  GcDbObjectIdArray mObjectIds;
  GcDbSubentId      mSubentId;
  void*             mpUserAppData{ nullptr };
};

inline GcDb::SubentType
GcDbSubentId::type() const
{
  return mType;
}

inline void
GcDbSubentId::setType(GcDb::SubentType type)
{
  mType = type;
  if (mType != GcDb::kClassSubentType)
    mpTypeClass = nullptr;
}

inline Gsoft::GsMarker
GcDbSubentId::index() const
{
  return mIndex;
}

inline void
GcDbSubentId::setIndex(Gsoft::GsMarker index)
{
  mIndex = index;
}

inline GcRxClass*
GcDbSubentId::typeClass() const
{
  return mpTypeClass;
}

inline void
GcDbSubentId::setTypeClass(GcRxClass* pTypeClass)
{
  mpTypeClass = pTypeClass;
  if (mpTypeClass != nullptr)
    mType = GcDb::kClassSubentType;
}

inline
GcDbSubentId::GcDbSubentId()
  : mType(GcDb::kNullSubentType), mIndex(kNullSubentIndex), mpTypeClass(nullptr)
{
}

inline
GcDbSubentId::GcDbSubentId(GcDb::SubentType t, Gsoft::GsMarker i)
  : mType(t), mIndex(i), mpTypeClass(nullptr)
{
}

inline
GcDbSubentId::GcDbSubentId(GcRxClass* pTypeClass, Gsoft::GsMarker i)
  : mType(GcDb::kClassSubentType), mIndex(i), mpTypeClass(pTypeClass)
{
}

inline bool
GcDbSubentId::operator ==(const GcDbSubentId& id) const
{
  return ((mIndex == id.mIndex)
    && (mType == id.mType)
    && (mpTypeClass == id.mpTypeClass));
}

inline bool
GcDbSubentId::operator !=(const GcDbSubentId& id) const
{
  return ((mIndex != id.mIndex)
    || (mType != id.mType)
    || (mpTypeClass != id.mpTypeClass));
}

inline
GcDbFullSubentPath::GcDbFullSubentPath() : mpUserAppData(NULL)
{
}

inline
GcDbFullSubentPath::GcDbFullSubentPath(GcDb::SubentType type,
  Gsoft::GsMarker index)
  : mSubentId(type, index), mpUserAppData(NULL)
{
}

inline void
GcDbFullSubentPath::objectIds(GcDbObjectIdArray& objectIds) const
{
  objectIds = mObjectIds;
}

inline GcDbObjectIdArray&
GcDbFullSubentPath::objectIds()
{
  return mObjectIds;
}

inline const GcDbObjectIdArray&
GcDbFullSubentPath::objectIds() const
{
  return mObjectIds;
}

inline const GcDbSubentId
GcDbFullSubentPath::subentId() const
{
  return mSubentId;
}

inline GcDbSubentId&
GcDbFullSubentPath::subentId()
{
  return mSubentId;
}

inline void*
GcDbFullSubentPath::userAppData() const
{
  return mpUserAppData;
}

inline void
GcDbFullSubentPath::setUserAppData(void* pData)
{
  mpUserAppData = pData;
}

inline void
GcDbFullSubentPath::setObjectIds(const GcDbObjectIdArray& objectIds)
{
  mObjectIds = objectIds;
}

inline void
GcDbFullSubentPath::setSubentId(const GcDbSubentId& subentId)
{
  mSubentId = subentId;
}

#pragma pack (pop)

#endif