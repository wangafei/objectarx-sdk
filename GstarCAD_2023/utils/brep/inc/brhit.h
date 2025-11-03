/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRHIT_H
#define GC_BRHIT_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"

class GcGePoint3d;
class GcBrEntity;
class GcBrHitData;
class GcBrImpHit;

typedef GcBrHitData GcBrHitPath;

class GCBR_PORT GcBrHit : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcBrHit);
  GcBrHit();
  GcBrHit(const GcBrHit& src);
  ~GcBrHit();

  GcBrHit&            operator =      (const GcBrHit& src);

  Gsoft::Boolean      isEqualTo(const GcRxObject* other) const;
  Gsoft::Boolean      isNull() const;
  GcBr::ErrorStatus   setHitPath(GcBrHitPath& hitPath);

  GcBr::ErrorStatus   getPoint(GcGePoint3d*& point) const;
  GcBr::ErrorStatus   getEntityHit(GcBrEntity*& entityHit) const;
  GcBr::ErrorStatus   getEntityEntered(GcBrEntity*& entityEntered) const;
  GcBr::ErrorStatus   getEntityAssociated(GcBrEntity*& entity) const;
  GcBr::ErrorStatus   getPoint(GcGePoint3d& point) const;

  GcBr::ErrorStatus   setValidationLevel(const GcBr::ValidationLevel& validationLevel = *(GcBr::ValidationLevel*)NULL);
  GcBr::ErrorStatus   getValidationLevel(GcBr::ValidationLevel& validationLevel) const;
  Gsoft::Boolean      brepChanged() const;

  GcBr::ErrorStatus   set(GcBrHitData* hitData);
  GcBr::ErrorStatus   get(GcBrHitData*& hitData) const;

protected:
  GcBrImpHit*         mpImp;
};

#endif
