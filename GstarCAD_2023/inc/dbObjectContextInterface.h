/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack (push, 8)

#include "gcdb.h"
#include "dbmain.h"

class GcDbObjectContext;

const GCDB_PORT GcString& gcdbAnnotationScaleCollectionName();

class GCDB_PORT GcDbObjectContextInterface : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectContextInterface);

  virtual bool supportsCollection(
    const GcDbObject* pObject,
    const GcString&   collectionName) const = 0;
  virtual bool hasContext(const GcDbObject* pObject,
    const GcDbObjectContext& context) const = 0;

  virtual Gcad::ErrorStatus addContext(
    GcDbObject*              pObject,
    const GcDbObjectContext& context) const = 0;
  virtual Gcad::ErrorStatus removeContext(
    GcDbObject*              pObject,
    const GcDbObjectContext& context) const = 0;
};

#pragma pack (pop)