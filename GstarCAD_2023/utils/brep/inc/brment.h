/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRMENT_H
#define GC_BRMENT_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"

class GcBrEntity;
class GcBrImpMeshEntity;

class GCBR_PORT GcBrMeshEntity : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcBrMeshEntity);
  virtual ~GcBrMeshEntity();

  Gsoft::Boolean      isEqualTo(const GcRxObject* other) const;
  Gsoft::Boolean      isNull() const;
  GcBr::ErrorStatus   getEntityAssociated(GcBrEntity*& entity) const;
  GcBr::ErrorStatus   setValidationLevel(const GcBr::ValidationLevel& = *(GcBr::ValidationLevel*)NULL);
  GcBr::ErrorStatus   getValidationLevel(GcBr::ValidationLevel& validationLevel) const;
  Gsoft::Boolean      brepChanged() const;

protected:
  GcBrMeshEntity();
  GcBrMeshEntity(const GcBrMeshEntity&);
  GcBrMeshEntity&     operator =      (const GcBrMeshEntity&);

  GcBrImpMeshEntity* mpImp;
};

#endif
