#pragma once

#include "Ge/GePlane.h"
#include "DbBaseSubentId.h"
#include "RxObject.h"

class OdDbEntity;

class OdDbDynamicUCSPE : public OdRxObject
{
public:
  enum Flags
  {
    kDefault = 0x00,
  };

  ODRX_DECLARE_MEMBERS(OdDbDynamicUCSPE);

  virtual OdResult getCandidatePlanes(OdArray<OdGePlane>& results,
    double& distToEdge,
    double& objWidth,
    double& objHeight,
    OdDbEntity* pEnt,
    const OdDbSubentId& subentId,
    const OdGePlane& viewplane,
    OdDbDynamicUCSPE::Flags flags = kDefault
  ) const = 0;
};

ODRX_NO_CONS_DEFINE_MEMBERS(OdDbDynamicUCSPE, OdRxObject);