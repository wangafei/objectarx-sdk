#pragma once

#include "zdbents.h"
#include "zimgvars.h"
#include "zimgent.h"
#include "zAcDbGeoTypes.h"

#pragma pack (push, 8)
#pragma warning(push)
#pragma warning(disable : 4275)

class GeoMapImp;

#ifdef  ZCGEOLOCATIONOBJ_API
#  define ZCGEOLOCATIONOBJ_PORT  __declspec(dllexport)
#else
#  define ZCGEOLOCATIONOBJ_PORT
#endif

class ZCGEOLOCATIONOBJ_PORT ZcDbGeoMap : public ZcDbRasterImage
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGeoMap);

	
	
	ZcDbGeoMap();
    ZcDbGeoMap(ZcGeoMapType mapType, ZcGeoMapResolution resolution, unsigned int levelOfDetail);
    ZcDbGeoMap(ZcDbObjectId viewportId, bool isViewportSpecific);

	
	
    virtual ~ZcDbGeoMap();

public:
	

	
	
    ZcGePoint3d					bottomLeftPt() const;
	
	
	double						height() const;
	
	
    double						width() const;

	
	
	ZcGePoint3d					imageBottomLeftPt() const;
	
	
	double						imageHeight() const;
	
	
	double						imageWidth() const;

	
	
	
	

	
    ZcGeoMapResolution			resolution() const;

	
	
	
	

	

	
    Zcad::ErrorStatus			setResolution(ZcGeoMapResolution resolution);

	
	
	
	

	
	unsigned int				LOD() const;

	
	
	

	
	ZcGeoMapType				mapType() const;

	
	
	
	

	

	
    Zcad::ErrorStatus			setMapType(ZcGeoMapType mapType);

	
	
	
	

	
	
	ZSoft::Boolean				isOutOfDate() const;

	
	
	
	
	

	

	
	ZSoft::Boolean				updateMapImage(ZSoft::Boolean bReset = ZSoft::kFalse);

    Zcad::ErrorStatus			dwgInFields(ZcDbDwgFiler* pFiler) override;
    Zcad::ErrorStatus			dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    Zcad::ErrorStatus			dxfInFields(ZcDbDxfFiler* pFiler) override;
    Zcad::ErrorStatus			dxfOutFields(ZcDbDxfFiler* pFiler) const override;
    Zcad::ErrorStatus           subErase(ZSoft::Boolean erasing) override;

	virtual Zcad::ErrorStatus	applyPartialUndo(
									ZcDbDwgFiler* undoFiler,
                                    ZcRxClass*    classObj
									) override;

    Zcad::ErrorStatus			subGetOsnapPoints(
									ZcDb::OsnapMode osnapMode,
									ZSoft::GsMarker gsSelectionMark,
									const ZcGePoint3d& pickPoint,
									const ZcGePoint3d& lastPoint,
									const ZcGeMatrix3d& viewXform,
									ZcGePoint3dArray& snapPoints,
									ZcDbIntArray& geomIds
									) const override;
    Zcad::ErrorStatus			subGetGripPoints(
									ZcDbGripDataPtrArray& grips,
									const double curViewUnitSize,
									const int gripSize,
									const ZcGeVector3d& curViewDir,
									const int bitflags
									) const override;
    Zcad::ErrorStatus			subGetGripPoints(
									ZcGePoint3dArray& gripPoints,
									ZcDbIntArray& osnapModes,
									ZcDbIntArray& geomIds
									) const override;
	Zcad::ErrorStatus			subMoveGripPointsAt(
									const ZcDbVoidPtrArray& gripAppData,
									const ZcGeVector3d& offset,
									const int bitflags
									) override;
    Zcad::ErrorStatus			subTransformBy(const ZcGeMatrix3d& xform) override;
    Zcad::ErrorStatus           subIntersectWith(
                                    const ZcDbEntity*   ent,
                                    ZcDb::Intersect     intType,
                                    ZcGePoint3dArray&   points,
                                    ZSoft::GsMarker     thisGsMarker  = 0,
                                    ZSoft::GsMarker     otherGsMarker = 0
                                    ) const override;

	Zcad::ErrorStatus			subMoveGripPointsAt(
									const ZcDbIntArray & indices,
									const ZcGeVector3d& offset
									) override;

    Zcad::ErrorStatus           subIntersectWith(
                                    const ZcDbEntity*   ent,
                                    ZcDb::Intersect     intType,
                                    const ZcGePlane&    projPlane,
                                    ZcGePoint3dArray&   points,
                                    ZSoft::GsMarker     thisGsMarker  = 0,
                                    ZSoft::GsMarker     otherGsMarker = 0
                                    ) const override;

    ZcGiSentScanLines*			getScanLines(const ZcGiRequestScanLines& req) const override;
    ZSoft::Boolean				freeScanLines(ZcGiSentScanLines* pSSL) const override;

    ZcDbObjectId				imageDefId() const override;

	
	
	
	

	
    Zcad::ErrorStatus			getVertices(ZcGePoint3dArray& verts) const override;
	
    ZcGeVector2d				imageSize(ZSoft::Boolean bGetCachedValue = ZSoft::kFalse) const override;
    const ZcGePoint2dArray&		clipBoundary() const override;

	
	
	
	

	
    Zcad::ErrorStatus			getImageVertices(ZcGePoint3dArray& verts) const;

    Zcad::ErrorStatus			setBrightness( ZSoft::Int8 value ) override;
	
	
    ZSoft::Int8					brightness() const override;

    Zcad::ErrorStatus			setContrast( ZSoft::Int8 value ) override;
	
	
    ZSoft::Int8					contrast() const override;

    Zcad::ErrorStatus			setFade( ZSoft::Int8 value ) override;
	
	
    ZSoft::Int8					fade() const override;

    void                        getOrientation(
									ZcGePoint3d& origin,
									ZcGeVector3d& u,
									ZcGeVector3d& v
									) const override;

protected:

    ZSoft::UInt32				subSetAttributes(ZcGiDrawableTraits* pTraits) override;
    ZSoft::Boolean				subWorldDraw(ZcGiWorldDraw* pWorldDraw) override;
    void						subViewportDraw(ZcGiViewportDraw* pViewportDraw) override;
    virtual void				subList() const override;

    Zcad::ErrorStatus			subGetGeomExtents(ZcDbExtents& extents) const override;
    virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;

private:
    GeoMapImp*					m_pImp;

    friend class				ZcDbGeoMapSystemInternals;

    void *operator new[](size_t nSize) { return (void*)0;}
    void operator delete[](void *p) {};
    void *operator new[](size_t nSize, const char *file, int line) { return (void*)0;}

#ifdef _ZSOFT_MAC_
private:
    typedef ZcDbRasterImage __super;
#endif

};

#pragma warning(pop)
#pragma pack (pop)
