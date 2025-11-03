/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_ANNOTATIONSCALE_H
#define GCDB_ANNOTATIONSCALE_H

#pragma once
#pragma pack(push, 8)

#include "dbObjContext.h"

class GcDbImpAnnotationScale;

class GCDB_PORT GcDbAnnotationScale : public GcDbObjectContext, public GcHeapOperators
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAnnotationScale);

  GcDbAnnotationScale();
  ~GcDbAnnotationScale();

  Gcad::ErrorStatus getName(GcString& name) const override;
  Gcad::ErrorStatus setName(const GcString& name) override;
  Gsoft::LongPtr uniqueIdentifier() const override;
  GcString collectionName() const override;
  Gcad::ErrorStatus copyFrom(const GcRxObject *pOther) override;

  virtual Gcad::ErrorStatus getPaperUnits(double& dPaperUnits) const;
  virtual Gcad::ErrorStatus setPaperUnits(double dPaperUnits);
  virtual Gcad::ErrorStatus getDrawingUnits(double&  dDrawingUnits) const;
  virtual Gcad::ErrorStatus setDrawingUnits(const double dDrawingUnits);
  virtual Gcad::ErrorStatus getScale(double& dScale) const;
  virtual Gcad::ErrorStatus getIsTemporaryScale(bool& bTemporary) const;
  virtual bool matchScaleId(Gsoft::LongPtr id) const;
protected:
  GcDbImpAnnotationScale* mpImp;
  friend class GcDbSystemInternals;
  GcDbAnnotationScale(bool);
};

class GCDB_PORT GcDbAnnotationScaleReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAnnotationScaleReactor);

  virtual void annotationScaleChanged(const GcDbDatabase* pDb,
    const GcDbViewport* pVP,
    const GcDbAnnotationScale* pScale,
    const bool bInitializing);
};

GCDB_PORT bool gcdbAddAnnotationScaleReactor(GcDbAnnotationScaleReactor *pReactor);
GCDB_PORT bool gcdbRemoveAnnotationScaleReactor(GcDbAnnotationScaleReactor *pReactor);

#pragma pack(pop)

#endif