/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRMCTL_H
#define GC_BRMCTL_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"

class GcBrImpMeshControl;

class GCBR_PORT GcBrMeshControl : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcBrMeshControl);
  virtual ~GcBrMeshControl();

  Gsoft::Boolean      isEqualTo(const GcRxObject* other) const;
  GcBr::ErrorStatus   setMaxSubdivisions(const Gsoft::UInt32& maxSubs = *(Gsoft::UInt32*)NULL);
  GcBr::ErrorStatus   getMaxSubdivisions(Gsoft::UInt32& maxSubs) const;
  GcBr::ErrorStatus   setMaxNodeSpacing(const double& maxNodeSpace = *(double*)NULL);
  GcBr::ErrorStatus   getMaxNodeSpacing(double& maxNodeSpace) const;
  GcBr::ErrorStatus   setAngTol(const double& angTol = *(double*)NULL);
  GcBr::ErrorStatus   getAngTol(double& angTol) const;
  GcBr::ErrorStatus   setDistTol(const double& distTol = *(double*)NULL);
  GcBr::ErrorStatus   getDistTol(double& distTol) const;

protected:
  GcBrMeshControl();
  GcBrMeshControl(const GcBrMeshControl& src);
  GcBrMeshControl& operator =      (const GcBrMeshControl& src);
  GcBrImpMeshControl* mpImp;
};

#endif