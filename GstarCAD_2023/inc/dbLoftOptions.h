/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef DBLOFTOPTIONS_H
#define DBLOFTOPTIONS_H

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbLoftOptions
{
public:
  GcDbLoftOptions();
  GcDbLoftOptions(const GcDbLoftOptions& src);
  ~GcDbLoftOptions();

  GcDbLoftOptions& operator = (const GcDbLoftOptions& src);
  bool             operator == (const GcDbLoftOptions&) const;

  enum NormalOption {
    kNoNormal,
    kFirstNormal,
    kLastNormal,
    kEndsNormal,
    kAllNormal,
    kUseDraftAngles
  };

  double  draftStart() const;
  void    setDraftStart(double ang);
  double  draftEnd() const;
  void    setDraftEnd(double ang);
  double  draftStartMag() const;
  void    setDraftStartMag(double val);
  double  draftEndMag() const;
  void    setDraftEndMag(double val);
  bool  arcLengthParam() const;
  void  setArcLengthParam(bool val);
  bool  noTwist() const;
  void  setNoTwist(bool val);
  bool  alignDirection() const;
  void  setAlignDirection(bool val);
  bool  simplify() const;
  void  setSimplify(bool val);
  bool  closed() const;
  void  setClosed(bool val);
  bool  periodic() const;
  void  setPeriodic(bool val);
  bool  ruled() const;
  void  setRuled(bool val);
  bool  virtualGuide() const;
  void  setVirtualGuide(bool val);

  GcDbLoftOptions::NormalOption  normal() const;
  void  setNormal(GcDbLoftOptions::NormalOption val);

  Gcad::ErrorStatus  setOptionsFromSysvars();
  Gcad::ErrorStatus  setSysvarsFromOptions();
  Gcad::ErrorStatus  checkOptions(bool displayErrorMessages = false);
  Gcad::ErrorStatus  checkLoftCurves(
    GcArray<GcDbEntity*>& crossSectionCurves,
    GcArray<GcDbEntity*>& guideCurves,
    GcDbEntity* pPathCurve,
    bool& allOpen, bool& allClosed, bool& allPlanar,
    bool displayErrorMessages = false);
  Gcad::ErrorStatus checkCrossSectionCurves(
    GcArray<GcDbEntity*>& crossSectionCurves,
    bool& allOpen, bool& allClosed, bool& allPlanar,
    bool displayErrorMessages = false);
  Gcad::ErrorStatus checkGuideCurves(GcArray<GcDbEntity*>& guideCurves, bool displayErrorMessages = false);
  Gcad::ErrorStatus checkPathCurve(GcDbEntity *pPathCurve, bool displayErrorMessages = false);

private:
  void *mpImpLoftOptions;
  friend class GcDbImpLoftOptions;
};

#pragma pack(pop)

#endif 