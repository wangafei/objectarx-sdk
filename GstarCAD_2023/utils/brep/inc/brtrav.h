/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRTRAV_H
#define GC_BRTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"

class GcBrImpTraverser;
class GcBrTraverserData;

class GCBR_PORT GcBrTraverser : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcBrTraverser);
  virtual ~GcBrTraverser();

  Gsoft::Boolean    isEqualTo(const GcRxObject* other) const;
  Gsoft::Boolean    isNull() const;
  Gsoft::Boolean    done() const;
  GcBr::ErrorStatus next();
  GcBr::ErrorStatus restart();

  GcBr::ErrorStatus setValidationLevel(const GcBr::ValidationLevel& = *(GcBr::ValidationLevel*)NULL);
  GcBr::ErrorStatus getValidationLevel(GcBr::ValidationLevel& validationLevel) const;
  Gsoft::Boolean    brepChanged() const;

  GcBr::ErrorStatus set(GcBrTraverserData* traverserData);
  GcBr::ErrorStatus get(GcBrTraverserData*& traverserData) const;

protected:
  GcBrTraverser();
  GcBrTraverser(const GcBrTraverser& src);
  GcBrTraverser&      operator =      (const GcBrTraverser& src);
  GcBrImpTraverser*   mpImp;
};

#endif
