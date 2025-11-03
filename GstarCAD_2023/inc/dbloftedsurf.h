/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef DBLOFTEDSURF_H
#define DBLOFTEDSURF_H

#include "dbsurf.h"
#include "db3dProfile.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbLoftedSurface : public GcDbSurface
{
public:
  GcDbLoftedSurface();
  ~GcDbLoftedSurface();
  GCDB_DECLARE_MEMBERS(GcDbLoftedSurface);

  virtual Gcad::ErrorStatus createLoftedSurface(
    GcArray<GcDbEntity*>& crossSectionCurves,
    GcArray<GcDbEntity*>& guideCurves,
    GcDbEntity* pPathCurve, GcDbLoftOptions& loftOptions);

  int           numCrossSections() const;
  GcDbEntity*   getCrossSection(int idx) const;
  int           numGuideCurves() const;
  GcDbEntity*   getGuideCurve(int idx) const;
  GcDbEntity*   getPathEntity() const;
  void          getLoftOptions(GcDbLoftOptions& loftOptions) const;
  GcDbLoftProfile*  crossSection(int idx) const;
  void              getCrossSections(GcArray<GcDbLoftProfile*>& crossSections) const;
  GcDbLoftProfile*  guide(int idx) const;
  void              getGuides(GcArray<GcDbLoftProfile*>& guides) const;
  GcDbLoftProfile*  path() const;
  int               startContinuity(bool isCrossSection = true) const;
  int               endContinuity(bool isCrossSection = true) const;
  double            startMagnitude(bool isCrossSection = true) const;
  double            endMagnitude(bool isCrossSection = true) const;
  Gcad::ErrorStatus setStartContinuity(int val, bool isCrossSection = true);
  Gcad::ErrorStatus setEndContinuity(int val, bool isCrossSection = true);
  Gcad::ErrorStatus setStartMagnitude(double val, bool isCrossSection = true);
  Gcad::ErrorStatus setEndMagnitude(double val, bool isCrossSection = true);
  Gcad::ErrorStatus setLoftOptions(const GcDbLoftOptions& loftOptions);

  enum LoftSurfaceType
  {
    kLoftSurf,
    kLoftBlendSurf,
    kLoftNetworkSurf
  };

  GcDbLoftedSurface::LoftSurfaceType  loftSurfaceType() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  virtual bool isDependent() const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};
#pragma pack(pop)

#endif 