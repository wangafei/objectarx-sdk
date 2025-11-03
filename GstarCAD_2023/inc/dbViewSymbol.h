/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "GcString.h"

#pragma pack (push, 8)

#ifndef GCSYNERGY_PORT
#define GCSYNERGY_PORT
#endif

class GcDbImpViewSymbol;
class GcRxSymbolSketch;
class GcDbAssocViewSymbolConstrGrpPE;

class GCSYNERGY_PORT GcDbViewSymbol : public GcDbEntity
{
  friend class GcDbViewSymbolSystemInternals;
public:
  GCRX_DECLARE_MEMBERS(GcDbViewSymbol);
  ~GcDbViewSymbol();

  GcDbObjectId                symbolStyleId() const;
  void                        setSymbolStyleId(const GcDbObjectId& styleId);
  double                      scale() const;
  void                        setScale(double val);

  Gcad::ErrorStatus           getIdentifier(GCHAR*& pszName) const;
  Gcad::ErrorStatus           getIdentifier(GcString& sName) const;
  Gcad::ErrorStatus           setIdentifier(const GcString& sName);

  GcDbObjectId                owningViewRep() const;
  void                        setOwningViewRep(const GcDbObjectId& owner);
  Gcad::ErrorStatus           createDefinition(GcRxSymbolSketch* pSketchObject);
  Gcad::ErrorStatus           exportSymbolGeometry(GcArray<GcGeCurve3d*>& geomArr, const GcDbObjectId& viewRepId);
  Gcad::ErrorStatus           setSymbolGeometry(const GcDbObjectIdArray& entIds);
  Gcad::ErrorStatus           setSymbolGeometry(const GcArray<GcDbObject*>& entities);
  Gcad::ErrorStatus						updateDefinition();


  Gsoft::Boolean      subWorldDraw(GcGiWorldDraw* pWd) override;
  Gcad::ErrorStatus   subErase(Gsoft::Boolean erasing) override;
  void                objectClosed(const GcDbObjectId dbObjId) override;
  Gcad::ErrorStatus   subClose() override;
  void                subSetDatabaseDefaults(GcDbDatabase* pDb) override;

  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus   audit(GcDbAuditInfo* pAuditInfo) override;

  Gcad::ErrorStatus   subGetGeomExtents(GcDbExtents& extents) const override;
  Gcad::ErrorStatus   subGetOsnapPoints(GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray&       geomIds) const override;
  Gcad::ErrorStatus   subTransformBy(const GcGeMatrix3d& xform) override;
  void                subGripStatus(const GcDb::GripStat status) override;
  Gcad::ErrorStatus   subGetGripPoints(GcDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const GcGeVector3d& curViewDir,
    const int bitflags) const override;
  Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d& offset,
    const int bitflags) override;
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
  void                subList() const override;
  void                saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;

protected:
  GcDbViewSymbol();

private:
  friend class GcDbAssocViewSymbolConstrGrpPE;
  GcDbImpViewSymbol*          mpImpSymbol;
};

#pragma pack (pop)