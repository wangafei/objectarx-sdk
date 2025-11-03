/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DBEXTRUDEDSURF_H
#define DBEXTRUDEDSURF_H

#include "dbsurf.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbExtrudedSurface : public GcDbSurface
{
public:
  GcDbExtrudedSurface();
  ~GcDbExtrudedSurface();
  GCDB_DECLARE_MEMBERS(GcDbExtrudedSurface);

  virtual Gcad::ErrorStatus createExtrudedSurface(GcDbEntity* pSweepEnt,
    const GcGeVector3d& directionVec, GcDbSweepOptions& sweepOptions);
  GcDbEntity*    getSweepEntity() const;
  GcDb3dProfile* sweepProfile() const;

  GcGeVector3d       getSweepVec() const;
  Gcad::ErrorStatus  setSweepVec(const GcGeVector3d& sweepVec);
  double             getHeight() const;
  Gcad::ErrorStatus  setHeight(double height);
  void               getSweepOptions(GcDbSweepOptions& sweepOptions) const;
  Gcad::ErrorStatus  setSweepOptions(const GcDbSweepOptions& sweepOptions);
  Gcad::ErrorStatus  setExtrude(const GcGeVector3d& sweepVec,
    const GcDbSweepOptions& sweepOptions);

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