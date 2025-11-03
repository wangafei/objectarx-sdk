#pragma once
#include "RxObject.h"

class ODRX_ABSTRACT OdDbAlignment : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbAlignment);

  virtual OdResult getAlignment(
    OdDbEntity* pEnt,
    const OdDbObjectIdArray& nestedPickedEntities,
    const OdGePoint3d& pickPoint,
    const OdGeVector3d& normal,
    OdGePoint3d& closestPoint,
    OdGeVector3d& direction) = 0;
};

ODRX_NO_CONS_DEFINE_MEMBERS(OdDbAlignment, OdRxObject)