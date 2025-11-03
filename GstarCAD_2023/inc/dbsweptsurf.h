/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DBSWEPTSURF_H
#define DBSWEPTSURF_H

#include "dbsurf.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbSweptSurface : public GcDbSurface
{
public:
  GcDbSweptSurface();
  ~GcDbSweptSurface();

  GCDB_DECLARE_MEMBERS(GcDbSweptSurface);

  virtual Gcad::ErrorStatus createSweptSurface(GcDbEntity* pSweepEnt,
    GcDbEntity* pPathEnt, GcDbSweepOptions& sweepOptions);

  GcDbEntity*   getSweepEntity() const;
  GcDbEntity*   getPathEntity() const;
  GcDb3dProfile* sweepProfile() const;
  GcDb3dProfile* pathProfile() const;

  void               getSweepOptions(GcDbSweepOptions& sweepOptions) const;
  Gcad::ErrorStatus  setSweepOptions(const GcDbSweepOptions& sweepOptions);
  Gcad::ErrorStatus  getPathLength(double& len) const;

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