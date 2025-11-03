/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack (push, 8)

#ifndef GCSYNERGY_PORT
#define GCSYNERGY_PORT
#endif

class GcDbImpViewRepBlockReference;

class GCSYNERGY_PORT GcDbViewRepBlockReference : public GcDbBlockReference
{
  friend class GcDbViewRepBlockReferenceInternals;

public:
  GCRX_DECLARE_MEMBERS(GcDbViewRepBlockReference);
  ~GcDbViewRepBlockReference();

  GcDbObjectId                ownerViewportId() const;
  Gcad::ErrorStatus           copyFrom(const GcRxObject* pSrc) override;

  Gcad::ErrorStatus           dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus           dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus           dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus           dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus           audit(GcDbAuditInfo* pAuditInfo) override;

  void                        saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;
  Gcad::ErrorStatus           subGetGeomExtents(GcDbExtents& extents) const override;
  Gcad::ErrorStatus           subGetGsMarkersAtSubentPath(
    const GcDbFullSubentPath& subPath,
    GcArray<Gsoft::GsMarker>& gsMarkers) const override;
  GcGePoint3d                 position() const override;

protected:
  Gsoft::Boolean              subWorldDraw(GcGiWorldDraw* mode) override;
  void                        subViewportDraw(GcGiViewportDraw* pVd) override;
  Gcad::ErrorStatus           subTransformBy(const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus           subPushHighlight(const GcDbFullSubentPath& subId,
    GcGiHighlightStyle highlightStyle) override;
  Gcad::ErrorStatus           subPopHighlight(const GcDbFullSubentPath& subId) override;

public:
  GcDbViewRepBlockReference();
  GcDbViewRepBlockReference(const GcGePoint3d& position, GcDbObjectId blockTableRecord);
  void                        setOwnerViewportId(const GcDbObjectId& viewportId);

private:
  GcDbImpViewRepBlockReference*       getImpObject();
  GcDbImpViewRepBlockReference*       mpGcDbImpViewRepBlockReference;
};

#pragma pack (pop)