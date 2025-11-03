
#pragma once
#pragma pack (push, 8)

#ifndef ZCSYNERGY_PORT
#define ZCSYNERGY_PORT _declspec(dllexport)
#endif



class ZcDbImpViewRepBlockReference;

class ZCSYNERGY_PORT ZcDbViewRepBlockReference : public ZcDbBlockReference
{
    friend class ZcDbViewRepBlockReferenceInternals;

public:
    ZCRX_DECLARE_MEMBERS(ZcDbViewRepBlockReference);
    virtual ~ZcDbViewRepBlockReference();

    ZcDbObjectId                        ownerViewportId() const;

    virtual Zcad::ErrorStatus           copyFrom(const ZcRxObject* pSrc) override;

    virtual Zcad::ErrorStatus           dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus           dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus           dxfOutFields(ZcDbDxfFiler* pFiler) const override;
    virtual Zcad::ErrorStatus           dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus           audit(ZcDbAuditInfo* pAuditInfo) override;

    virtual void                        saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st) override;
    virtual Zcad::ErrorStatus           subGetGeomExtents(ZcDbExtents& extents) const override;
    virtual Zcad::ErrorStatus           subGetGsMarkersAtSubentPath(
                                            const ZcDbFullSubentPath& subPath, 
                                            ZcArray<ZSoft::GsMarker>& gsMarkers) const override;

    virtual ZcGePoint3d                 position() const override;

protected:
    
    virtual ZSoft::Boolean              subWorldDraw(ZcGiWorldDraw* mode) override;
    virtual void                        subViewportDraw(ZcGiViewportDraw* pVd) override;
    virtual Zcad::ErrorStatus           subTransformBy(const ZcGeMatrix3d& xform) override;

    virtual  Zcad::ErrorStatus          subPushHighlight  (const ZcDbFullSubentPath& subId,
                                                           ZcGiHighlightStyle        highlightStyle) override;
    virtual  Zcad::ErrorStatus          subPopHighlight   (const ZcDbFullSubentPath& subId) override;

public: 
    
    ZcDbViewRepBlockReference();
    ZcDbViewRepBlockReference(const ZcGePoint3d& position, ZcDbObjectId blockTableRecord);
    void                                setOwnerViewportId(const ZcDbObjectId& viewportId);

private:
    ZcDbImpViewRepBlockReference*       getImpObject();
    ZcDbImpViewRepBlockReference*       mpZcDbImpViewRepBlockReference;
};


#pragma pack (pop)
