/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GEOMENT_DBBODY_H
#define GEOMENT_DBBODY_H

#include "dbmain.h"
#include "dbsubeid.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbBody : public  GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDbBody);
  GcDbBody();
  ~GcDbBody();

  virtual Gsoft::Boolean    isNull() const;
  void dragStatus(const GcDb::DragStat) override;

  virtual void*             ASMBodyCopy(bool bDeepCopy = false) const;
  virtual void const *      getLockedASMBody();
  virtual void              unlockASMBody();
  virtual void*             getLockedWritableASMBody();
  virtual void              commitWritableASMBody();
  virtual Gcad::ErrorStatus setASMBody(const void* modelerBody);

  virtual GcDbSubentId    internalSubentId(void*) const;
  virtual void*           internalSubentPtr(const GcDbSubentId& id) const;

  static  Gcad::ErrorStatus acisOut(const GCHAR* fileName, const GcDbVoidPtrArray&);
  static  Gcad::ErrorStatus acisIn(const GCHAR* fileName, GcDbVoidPtrArray&);

  virtual Gsoft::UInt32 numChanges() const;
  virtual bool usesGraphicsCache();
  void invalidateCachedBodySubentIds();
};

#pragma pack (pop)

#endif