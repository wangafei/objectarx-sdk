/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcdb.h"
#include "dbmain.h"

class GcDbViewport;

#pragma pack (push, 8)

class GCDB_PORT GcDbAnnotativeObjectPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAnnotativeObjectPE);

  virtual bool annotative(GcDbObject* pObject) const = 0;
  virtual Gcad::ErrorStatus setAnnotative(GcDbObject* pObject, const bool  bAnnotative) = 0;
  virtual Gcad::ErrorStatus setFromStyle(GcDbObject* pObject, bool&       bUpdated) = 0;

  virtual bool forceAnnoAllVisible(GcDbObject* pObj) const
  {
    GSOFT_UNREFED_PARAM(pObj);
    return false;
  }
  virtual Gcad::ErrorStatus setForceAnnoAllVisible(GcDbObject* pObj, bool bForce) const
  {
    GSOFT_UNREFED_PARAM(pObj);
    GSOFT_UNREFED_PARAM(bForce);
    return Gcad::eNotImplemented;
  }
  virtual Gcad::ErrorStatus resetScaleDependentProperties(GcDbObject* pObject)
  {
    GSOFT_UNREFED_PARAM(pObject);
    return Gcad::eNotImplemented;
  }
};

class GCDB_PORT GcDbPaperOrientationPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbPaperOrientationPE);

  virtual bool paperOrientation(GcDbObject* pObject) const = 0;
  virtual Gcad::ErrorStatus setPaperOrientation(GcDbObject* pObject, const bool  bPaperOrientation) = 0;

  virtual Gcad::ErrorStatus applyPaperOrientationTransform(GcDbObject* pObject, const GcDbViewport *pVport) const
  {
    GSOFT_UNREFED_PARAM(pObject);
    GSOFT_UNREFED_PARAM(pVport);
    return Gcad::eNotImplemented;
  }
};

#pragma pack (pop)