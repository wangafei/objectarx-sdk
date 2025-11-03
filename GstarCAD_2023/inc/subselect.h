/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcedinpt.h"

typedef GcDbFullSubentPathArray GcSubentPathArray;

class GcGiViewport;

class GcEdSubSelectFilter
{
public:
  virtual ~GcEdSubSelectFilter() { }

  enum SubSelectStatus
  {
    kSubSelectionNone = 0,
    kSubSelectionAugment,
    kSubSelectionExclusive,
    kSubSelectAll
  };

  virtual Gcad::ErrorStatus subSelectClassList(GcArray<GcRxClass*>& clsIds)
  {
    return Gcad::eOk;
  }

  virtual bool selectEntity(
    const GcGePoint3d&  wvpt,
    const GcGeVector3d& wvwdir,
    const GcGeVector3d& wvwxdir,
    double              wxaper,
    double              wyaper,
    Gsoft::Int32        flags,
    const GcGiViewport* pCurVp,
    GcDbEntity*         pEnt) const
  {
    return false;
  }
  virtual SubSelectStatus subSelectEntity(
    const GcGePoint3d&        wpt1,
    const GcGePoint3d&        wpt2,
    const GcGeVector3d&       wvwdir,
    const GcGeVector3d&       wvwxdir,
    double                    wxaper,
    double                    wyaper,
    GcDb::SelectType          seltype,
    bool                      bAugment,
    bool                      bIsInPickfirstSet,
    bool                      bEvery,
    const GcGiViewport*       pCurVP,
    GcDbEntity*               pEnt,
    GcDbFullSubentPathArray&  paths)
  {
    return kSubSelectionNone;
  }
  virtual SubSelectStatus subSelectEntity(
    const resbuf*             pResbuf,
    bool                      bAugment,
    bool                      bIsInPickfirstSet,
    bool                      bEvery,
    const GcGiViewport*       pCurVP,
    GcDbEntity*               pEnt,
    GcDbFullSubentPathArray&  paths)
  {
    return kSubSelectionNone;
  }

  virtual bool reSubSelectEntity(GcDbEntity* pEnt, GcDbFullSubentPathArray& paths)
  {
    return false;
  }
  virtual bool cancelSubSelect(GcDbEntity* pEnt)
  {
    return false;
  }
  virtual bool cancelAllSubSelect()
  {
    return false;
  }
  virtual bool onKey(Gsoft::UInt32 wMsg, unsigned int nChar, unsigned int rptCnt, unsigned int flags)
  {
    return false;
  }
  virtual bool isSubSelected(GcDbEntity* pEnt) const
  {
    return false;
  }
};
