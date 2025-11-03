/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "gcdb.h"
#include "dbmain.h"

#pragma once
#pragma pack (push, 8)

class GCCORE_PORT GcDbDynamicUCSPE : public GcRxObject
{
public:
  enum Flags {
    kDefault = 0x00,
  };

  GCRX_DECLARE_MEMBERS(GcDbDynamicUCSPE);

  virtual Gcad::ErrorStatus getCandidatePlanes(GcArray<GcGePlane>& results,
    double &distToEdge,
    double &objWidth,
    double &objHeight,
    GcDbEntity* pEnt,
    const GcDbSubentId& subentId,
    const GcGePlane& viewplane,
    GcDbDynamicUCSPE::Flags flags = kDefault
  ) const = 0;
};

class CPoint;
class GCCORE_PORT GcDbNonSubEntDynamicUCSPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbNonSubEntDynamicUCSPE);

  virtual Gcad::ErrorStatus getCandidatePlane(
    GcDbEntity* Ent,
    const CPoint& pt,
    GcGePlane &result,
    double &distToEdge,
    double &objWidth,
    double &objHeight,
    void*& context
  ) = 0;
  virtual Gcad::ErrorStatus highlightPlane(
    GcDbEntity* Ent,
    void* context
  ) = 0;
  virtual Gcad::ErrorStatus dehighlightPlane(
    GcDbEntity* Ent,
    void* context
  ) = 0;
};
#pragma pack (pop)