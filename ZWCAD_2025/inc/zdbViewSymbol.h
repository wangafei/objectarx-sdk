
#pragma once

#include "zdbmain.h"
#include "zAcString.h"

#pragma pack (push, 8)

#ifndef ZCSYNERGY_PORT
#define ZCSYNERGY_PORT _declspec(dllexport)
#endif

class ZcDbImpViewSymbol;
class ZcRxSymbolSketch;
class ZcDbAssocViewSymbolConstrGrpPE;

class ZCSYNERGY_PORT ZcDbViewSymbol : public ZcDbEntity
{
    friend class ZcDbViewSymbolSystemInternals;
public:
    ZCRX_DECLARE_MEMBERS(ZcDbViewSymbol);

    virtual ~ZcDbViewSymbol();

    ZcDbObjectId                symbolStyleId() const;
    void                        setSymbolStyleId(const ZcDbObjectId& styleId);

    double                      scale() const;
    void                        setScale(double val);

    Zcad::ErrorStatus           getIdentifier(ZTCHAR*& pszName) const;
    Zcad::ErrorStatus           getIdentifier(ZcString& sName) const;
    Zcad::ErrorStatus           setIdentifier(const ZcString& sName);

    ZcDbObjectId                owningViewRep() const;
    void                        setOwningViewRep(const ZcDbObjectId& owner);
    Zcad::ErrorStatus           createDefinition(ZcRxSymbolSketch* pSketchObject);
    Zcad::ErrorStatus           exportSymbolGeometry(ZcArray<ZcGeCurve3d*>& geomArr, const ZcDbObjectId& viewRepId);
    Zcad::ErrorStatus           setSymbolGeometry(const ZcDbObjectIdArray& entIds);
    Zcad::ErrorStatus           setSymbolGeometry(const ZcArray<ZcDbObject*>& entities);
	Zcad::ErrorStatus			updateDefinition();

    virtual ZSoft::Boolean      subWorldDraw(ZcGiWorldDraw* pWd) override;

    virtual Zcad::ErrorStatus   subErase(ZSoft::Boolean erasing) override;
    void                        objectClosed(const ZcDbObjectId dbObjId);
    virtual Zcad::ErrorStatus   subClose () override;

    virtual void                subSetDatabaseDefaults(ZcDbDatabase* pDb) override;

    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const override;
    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus   audit(ZcDbAuditInfo* pAuditInfo) override;

    virtual Zcad::ErrorStatus   subGetGeomExtents(ZcDbExtents& extents) const override;

    virtual Zcad::ErrorStatus   subGetOsnapPoints(ZcDb::OsnapMode     osnapMode,
                                                  ZSoft::GsMarker     gsSelMark,
                                                  const ZcGePoint3d&  pickPoint,
                                                  const ZcGePoint3d&  lastPoint,
                                                  const ZcGeMatrix3d& viewXform,
                                                  ZcGePoint3dArray&   snapPoints,
                                                  ZcDbIntArray&       geomIds) const override;

    virtual Zcad::ErrorStatus   subTransformBy(const ZcGeMatrix3d& xform) override;

    virtual void                subGripStatus(const ZcDb::GripStat status) override;
    virtual Zcad::ErrorStatus   subGetGripPoints(ZcDbGripDataPtrArray& grips, 
                                                 const double curViewUnitSize, 
                                                 const int gripSize, 
                                                 const ZcGeVector3d& curViewDir, 
                                                 const int bitflags) const override;
    virtual Zcad::ErrorStatus   subMoveGripPointsAt(const ZcDbVoidPtrArray& gripAppData,
                                                 const ZcGeVector3d& offset, 
                                                 const int bitflags) override;

    virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;

    virtual void                subList() const override;

    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st) override;

protected:
    
    ZcDbViewSymbol();

private:

    friend class ZcDbAssocViewSymbolConstrGrpPE;
	ZcDbImpViewSymbol*          mpImpSymbol;
};

#pragma pack (pop)
