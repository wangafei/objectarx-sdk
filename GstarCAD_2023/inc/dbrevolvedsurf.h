/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DBREVOLVEDSURF_H
#define DBREVOLVEDSURF_H

#include "dbsurf.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbRevolvedSurface : public GcDbSurface
{
public:
  GcDbRevolvedSurface();
  ~GcDbRevolvedSurface();
  GCDB_DECLARE_MEMBERS(GcDbRevolvedSurface);

  virtual Gcad::ErrorStatus createRevolvedSurface(GcDbEntity* pRevEnt,
    const GcGePoint3d& axisPnt, const GcGeVector3d& axisDir,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions);

  GcDbEntity*   getRevolveEntity() const;
  GcDb3dProfile* revolveProfile() const;

  GcGePoint3d        getAxisPnt() const;
  Gcad::ErrorStatus  setAxisPnt(const GcGePoint3d& pnt);

  GcGeVector3d       getAxisVec() const;
  Gcad::ErrorStatus  setAxisVec(const GcGeVector3d& vec);

  double             getRevolveAngle() const;
  Gcad::ErrorStatus  setRevolveAngle(double ang);

  double             getStartAngle() const;
  void               getRevolveOptions(GcDbRevolveOptions& revolveOptions) const;
  Gcad::ErrorStatus  setRevolveOptions(const GcDbRevolveOptions& revolveOptions);
  Gcad::ErrorStatus  setRevolve(const GcGePoint3d& axisPnt, const GcGeVector3d& axisVec,
    double revAngle, const GcDbRevolveOptions& revolveOptions);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  virtual  bool isDependent() const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};
#pragma pack(pop)

#endif 