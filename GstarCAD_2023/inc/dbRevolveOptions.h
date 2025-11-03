/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DBREVOLVEOPTIONS_H
#define DBREVOLVEOPTIONS_H

#include "dbmain.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbRevolveOptions
{
public:
  GcDbRevolveOptions();
  GcDbRevolveOptions(const GcDbRevolveOptions& src);
  ~GcDbRevolveOptions();

  GcDbRevolveOptions& operator = (const GcDbRevolveOptions& src);

  double  draftAngle() const;
  void  setDraftAngle(double ang);

  double  twistAngle() const;
  void  setTwistAngle(double ang);

  bool  closeToAxis() const;
  void  setCloseToAxis(bool val);

  Gcad::ErrorStatus  checkRevolveCurve(GcDbEntity* pRevEnt,
    const GcGePoint3d& axisPnt, const GcGeVector3d& axisDir,
    bool& closed, bool& endPointsOnAxis, bool& planar,
    bool displayErrorMessages = false);

private:
  void *mpImpRevolveOptions;
  friend class GcDbImpRevolveOptions;
};
#pragma pack(pop)

#endif 