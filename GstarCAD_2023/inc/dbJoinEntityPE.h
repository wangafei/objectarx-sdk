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

class GCDB_PORT GcDbJoinEntityPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbJoinEntityPE);

  virtual Gcad::ErrorStatus joinEntity(GcDbEntity* pPrimaryEntity,
    GcDbEntity* pSecondaryEntity,
    const GcGeTol& tol = GcGeContext::gTol) const = 0;
  virtual Gcad::ErrorStatus joinEntities(GcDbEntity* pPrimaryEntity,
    const GcArray<GcDbEntity*>& otherEntities,
    GcGeIntArray& joinedEntityIndices,
    const GcGeTol& tol = GcGeContext::gTol) const = 0;
};

#pragma pack (pop)