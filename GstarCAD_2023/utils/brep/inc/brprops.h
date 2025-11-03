/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRPROPS_H
#define GC_BRPROPS_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/gepnt3d.h"
#include "../../../inc/gevec3d.h"

struct GcBrMassProps
{
  double       mVolume;
  double       mMass;
  GcGePoint3d  mCentroid;
  double       mRadiiGyration[3];
  double       mMomInertia[3];
  double       mProdInertia[3];
  double       mPrinMoments[3];
  GcGeVector3d mPrinAxes[3];
};

#endif
