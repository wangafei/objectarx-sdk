/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "rxprotevnt.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbAppEntityGrips : public GcRxProtocolReactor
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAppEntityGrips);

  virtual Gcad::ErrorStatus getGripPoints(
    GcDbGripDataPtrArray& grips,
    const double          curViewUnitSize,
    const int             gripSize,
    const GcGeVector3d&   curViewDir,
    const int             bitflags,
    GcDbEntity*           pEntity) = 0;
  virtual Gcad::ErrorStatus moveGripPointsAt(
    const GcDbVoidPtrArray&        gripAppData,
    const GcGeVector3d&            offset,
    const int                      bitflags,
    GcDbEntity*                    pEntity) = 0;
  virtual void gripStatus(const GcDb::GripStat status, GcDbEntity* pEntity) = 0;
};

class GCDB_PORT GcDbBlockInsertionPoints : public GcRxProtocolReactor
{
public:
  GCRX_DECLARE_MEMBERS(GcDbBlockInsertionPoints);

  virtual Gcad::ErrorStatus getInsertionPoints(
    const GcDbBlockTableRecord* pBlock,
    const GcDbBlockReference*   pBlkRef,
    GcGePoint3dArray&           insPts,
    GcGeVector3dArray&          alignmentDirections) = 0;
};
#pragma pack(pop)