/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBLTRANS_H
#define GD_DBLTRANS_H 1

#include "dbmain.h"
#include "GdGChar.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbLongTransWorkSetIterator : public GcRxObject
{
public:
  ~GcDbLongTransWorkSetIterator() {};
  GCRX_DECLARE_MEMBERS(GcDbLongTransWorkSetIterator);

  virtual void           start(bool incRemovedObjs = false, bool incSecondaryObjs = false) = 0;
  virtual bool           done() = 0;
  virtual void           step() = 0;
  virtual GcDbObjectId   objectId() const = 0;
  virtual bool           curObjectIsErased() const = 0;
  virtual bool           curObjectIsRemoved() const = 0;
  virtual bool           curObjectIsPrimary() const = 0;
};

class GCDB_PORT GcDbLongTransaction : public GcDbObject
{
public:
  GcDbLongTransaction();
  ~GcDbLongTransaction();
  GCDB_DECLARE_MEMBERS(GcDbLongTransaction);

  enum {
    kSameDb = 0,
    kXrefDb = 1,
    kUnrelatedDb = 2
  };

  int                  type() const;
  GcDbObjectId         originBlock() const;
  GcDbObjectId         destinationBlock() const;
  Gcad::ErrorStatus    getLongTransactionName(GCHAR*&) const;
  Gcad::ErrorStatus    addToWorkSet(GcDbObjectId id);
  Gcad::ErrorStatus    removeFromWorkSet(GcDbObjectId id);
  Gcad::ErrorStatus    syncWorkSet();
  Gcad::ErrorStatus    newWorkSetIterator(
    GcDbLongTransWorkSetIterator*& pNewIter,
    bool incRemovedObjs = false,
    bool incSecondaryObjs = false)
    const;
  GcDbObjectId         originObject(GcDbObjectId id) const;
  bool                 workSetHas(GcDbObjectId id, bool bIncErased = false) const;
  GcDbIdMapping*       activeIdMap();
  void                 regenWorkSetWithDrawOrder();
  bool                 disallowDrawOrder();
};

#pragma pack (pop)

#endif