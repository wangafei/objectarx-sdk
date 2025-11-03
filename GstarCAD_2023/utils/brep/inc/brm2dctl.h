/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRM2DCTL_H
#define GC_BRM2DCTL_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brmctl.h"

class GcBrMeshControl;

class GCBR_PORT GcBrMesh2dControl : public GcBrMeshControl
{
public:
  GCRX_DECLARE_MEMBERS(GcBrMesh2dControl);
  GcBrMesh2dControl();
  GcBrMesh2dControl(const GcBrMesh2dControl& src);
  ~GcBrMesh2dControl();

  GcBrMesh2dControl&  operator =      (const GcBrMesh2dControl& src);

  GcBr::ErrorStatus   setMaxAspectRatio(const double& maxAspectRatio = *(double*)NULL);
  GcBr::ErrorStatus   getMaxAspectRatio(double& maxAspectRatio) const;
  GcBr::ErrorStatus   setElementShape(const GcBr::Element2dShape& elementShape = *(GcBr::Element2dShape*)NULL);
  GcBr::ErrorStatus   getElementShape(GcBr::Element2dShape& elementShape) const;
};

#endif
