/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DBPLANESURF_H
#define DBPLANESURF_H

#include "dbsurf.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbPlaneSurface : public GcDbSurface
{
public:
  GcDbPlaneSurface();
  ~GcDbPlaneSurface();
  GCDB_DECLARE_MEMBERS(GcDbPlaneSurface);

  virtual Gcad::ErrorStatus createFromRegion(GcDbRegion *pRegion);

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