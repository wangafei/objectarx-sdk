/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBIDMAP_H
#define GD_DBIDMAP_H 1

#include "gcdb.h"
#include "rxobject.h"
#include "dbid.h"

#pragma pack (push, 8)

class GcDbDatabase;

class GCDB_PORT GcDbIdPair
{
public:
  GcDbIdPair();
  GcDbIdPair(const GcDbIdPair&);
  GcDbIdPair(GcDbObjectId key, GcDbObjectId value,
    bool isCloned,
    bool isPrimary = false,
    bool isOwnerXlated = true);

  GcDbObjectId   key() const;
  GcDbObjectId   value() const;
  bool           isCloned() const;
  bool           isPrimary() const;
  bool           isOwnerXlated() const;

  void            setKey(GcDbObjectId);
  void            setValue(GcDbObjectId);
  void            setIsCloned(bool isCloned);
  void            setIsPrimary(bool isPrimary);
  void            setIsOwnerXlated(bool isOwnerXlated);

private:
  GcDbObjectId   mKey;
  GcDbObjectId   mValue;
  bool           mIsCloned : 1;
  bool           mIsPrimary : 1;
  bool           mIsOwnerXlated : 1;
};

class GcDbIdMappingIter;
class GcDbImpIdMapping;
class GcDbImpIdMappingIter;

class GCDB_PORT GcDbIdMapping : public  GcRxObject
{
public:
  GcDbIdMapping();
  ~GcDbIdMapping();
  GCRX_DECLARE_MEMBERS(GcDbIdMapping);

  virtual Gcad::ErrorStatus   assign(const GcDbIdPair&);
  virtual bool                compute(GcDbIdPair&) const;
  virtual bool                change(const GcDbIdPair&);
  virtual bool                del(GcDbObjectId key);
  Gcad::ErrorStatus           destDb(GcDbDatabase*& db) const;
  Gcad::ErrorStatus           setDestDb(GcDbDatabase* db);
  Gcad::ErrorStatus           origDb(GcDbDatabase*& db) const;
  GcDb::DeepCloneType         deepCloneContext() const;
  GcDb::DuplicateRecordCloning duplicateRecordCloning() const;
  Gcad::ErrorStatus           copyFrom(const GcRxObject* other) override;

private:
  friend class GcDbSystemInternals;
  friend class GcDbImpIdMappingIter;
  GcDbIdMapping(const GcDbIdMapping&) = delete;
  GcDbIdMapping& operator= (const GcDbIdMapping&) = delete;
  GcDbImpIdMapping* mpImp;
};

class GCDB_PORT GcDbIdMappingIter : public  GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbIdMappingIter);
  GcDbIdMappingIter(const GcDbIdMapping&);
  ~GcDbIdMappingIter();

  virtual Gcad::ErrorStatus   iterateOn(const GcDbIdMapping&);
  virtual void                start();
  virtual bool                getMap(GcDbIdPair&);
  virtual bool                next();
  virtual bool                done();

private:
  friend class                GcDbSystemInternals;
  GcDbImpIdMappingIter*       mpImp;
  GcDbIdMappingIter(const GcDbIdMappingIter&) = delete;
  GcDbIdMappingIter& operator= (const GcDbIdMappingIter&) = delete;
};

inline
GcDbObjectId GcDbIdPair::key() const
{
  return mKey;
}

inline
GcDbObjectId GcDbIdPair::value() const
{
  return mValue;
}

inline
bool GcDbIdPair::isCloned() const
{
  return mIsCloned;
}

inline
bool GcDbIdPair::isPrimary() const
{
  return mIsPrimary;
}

inline
bool GcDbIdPair::isOwnerXlated() const
{
  return mIsOwnerXlated;
}

inline
void GcDbIdPair::setKey(GcDbObjectId key)
{
  mKey = key;
}

inline
void GcDbIdPair::setValue(GcDbObjectId value)
{
  mValue = value;
}

inline
void GcDbIdPair::setIsCloned(bool isCloned)
{
  mIsCloned = isCloned;
}

inline
void GcDbIdPair::setIsPrimary(bool isPrimary)
{
  mIsPrimary = isPrimary;
}

inline
void GcDbIdPair::setIsOwnerXlated(bool isOwnerXlated)
{
  mIsOwnerXlated = isOwnerXlated;
}

#pragma pack (pop)

#endif