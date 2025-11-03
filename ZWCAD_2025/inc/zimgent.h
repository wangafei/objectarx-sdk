
#ifndef __ZIMGENT_H
#define __ZIMGENT_H

#include "zdbents.h"
#include "zdbimage.h"
#include "zacgi.h"
#include "zgept3dar.h"
#include "zgebndpln.h"
#include "zgeplin2d.h"
#include "zdbproxy.h"
#include "zimgdef.h"
#pragma pack (push, 8)

const double kEpsilon = 1.0e-7;

const int kAllEntityProxyFlags =
    ZcDbProxyEntity::kEraseAllowed         |
    ZcDbProxyEntity::kTransformAllowed     |
    ZcDbProxyEntity::kColorChangeAllowed         |
    ZcDbProxyEntity::kLayerChangeAllowed         |
    ZcDbProxyEntity::kLinetypeChangeAllowed      |
    ZcDbProxyEntity::kMaterialChangeAllowed      |
    ZcDbProxyEntity::kLinetypeScaleChangeAllowed |
    ZcDbProxyEntity::kVisibilityChangeAllowed;

class RasterImageImp;

#pragma warning (push)
#pragma warning( disable : 4275 )

#ifdef ISMDLLACCESS
#undef ISMDLLACCESS
#endif
#ifdef ISMDLLACCESSDATA
#undef ISMDLLACCESSDATA
#endif
#ifdef ISM_OBJ

#define ISMDLLACCESS __declspec(dllexport)
#define ISMDLLACCESSDATA
#else
#define ISMDLLACCESS 
#define ISMDLLACCESSDATA __declspec(dllimport)
#endif

class ISMDLLACCESS ZcDbRasterImage : public ZcDbImage 
{
public:

    static ClassVersion         classVersion();

	ZCRX_DECLARE_MEMBERS(ZcDbRasterImage);

    		                    ZcDbRasterImage();
    virtual                     ~ZcDbRasterImage();

    RasterImageImp*             ptrImp() const;
    RasterImageImp*             setPtrImp(RasterImageImp* pImp);

    virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* filer) override;
    virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* filer) const override;

    virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* filer) override;
    virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* filer) const override;

    virtual Zcad::ErrorStatus   subSwapIdWith(
                                    ZcDbObjectId otherId,
                                    ZSoft::Boolean swapXdata = ZSoft::kFalse,
                                    ZSoft::Boolean swapExtDict = ZSoft::kFalse
                                ) override;

    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st) override;

    virtual bool                castShadows() const override;
    virtual void                setCastShadows(bool newVal) override;
    virtual bool                receiveShadows() const override;
    virtual void                setReceiveShadows(bool newVal) override;
    virtual ZcGiSentScanLines*  getScanLines(
                                    const ZcGiRequestScanLines& req
                                ) const override;
    virtual ZSoft::Boolean      freeScanLines(
                                    ZcGiSentScanLines* pSSL
                                ) const override;

    virtual Zcad::ErrorStatus   setImageDefId(ZcDbObjectId imageId);
    virtual ZcDbObjectId        imageDefId() const;

    virtual void                setReactorId(ZcDbObjectId reactorId);
    virtual ZcDbObjectId        reactorId() const;

    virtual ZSoft::Boolean      setOrientation(
                                    const ZcGePoint3d& origin,
                                    const ZcGeVector3d& uCorner,
                                    const ZcGeVector3d& vOnPlane);
    virtual void                getOrientation(
                                    ZcGePoint3d& origin,
                                    ZcGeVector3d& u,
                                    ZcGeVector3d& v) const;

    virtual ZcGeVector2d        scale() const;
    virtual ZcGeVector2d        imageSize(ZSoft::Boolean bGetCachedValue
                                        = ZSoft::kFalse) const;

    enum ClipBoundaryType
    {
        kInvalid,
        kRect,
        kPoly
    };
#ifndef _ZSOFT_MAC_
	virtual Zcad::ErrorStatus   setClipBoundaryToWholeImage(ZcGeVector2d& size);
	Zcad::ErrorStatus   setClipBoundaryToWholeImage()
	{
		ZcGeVector2d size(0,0);
		return setClipBoundaryToWholeImage(size);
	}
#else
    virtual Zcad::ErrorStatus   setClipBoundaryToWholeImage(ZcGeVector2d& size );
    virtual Zcad::ErrorStatus   setClipBoundaryToWholeImage()
    {
        ZcGeVector2d size(0,0);
        return setClipBoundaryToWholeImage(size);
    }
#endif
    virtual Zcad::ErrorStatus   setClipBoundary(
                                    ClipBoundaryType type,
                                    const ZcGePoint2dArray&
                                    );
    virtual const ZcGePoint2dArray&  clipBoundary() const;
    virtual ClipBoundaryType    clipBoundaryType() const;
    ZSoft::Boolean              isClipped() const;

    virtual Zcad::ErrorStatus   getVertices(
                                    ZcGePoint3dArray& verts
                                ) const;

    virtual Zcad::ErrorStatus   getPixelToModelTransform(ZcGeMatrix3d&) const;

    enum ImageDisplayOpt
    {
        kShow                   = 1,
        kShowUnAligned          = 2,
        kClip                   = 4,
        kTransparent            = 8
    };

    virtual void                setDisplayOpt(
                                    ImageDisplayOpt option,
                                    ZSoft::Boolean bValue
                                );
    virtual ZSoft::Boolean      isSetDisplayOpt(ImageDisplayOpt option) const;

    virtual Zcad::ErrorStatus   setBrightness( ZSoft::Int8 value );
    virtual ZSoft::Int8         brightness() const;

    virtual Zcad::ErrorStatus   setContrast( ZSoft::Int8 value );
    virtual ZSoft::Int8         contrast() const;

    virtual Zcad::ErrorStatus   setFade( ZSoft::Int8 value );
    virtual ZSoft::Int8         fade() const;

	virtual ZSoft::Boolean      isClipInverted() const;
	virtual void                setClipInverted(ZSoft::Boolean newVal);

	double                      width() const;
	double                      height() const;

	double                      imageHeight() const;
	double                      imageWidth() const;
	Zcad::ErrorStatus           setHeight(double);
	Zcad::ErrorStatus           setWidth(double);
	ZcGePoint3d                 position() const;

	double                      rotation() const;
	Zcad::ErrorStatus           setRotation(double rotation);


	bool                        isImageShown() const;
	void                        setShowImage(bool value);

	bool                        isImageTransparent() const;
	void                        setImageTransparency(bool value);

	bool                        isShownClipped() const;
	void                        setShowClipped(bool value);

protected:
	virtual Zcad::ErrorStatus   subExplode(ZcDbVoidPtrArray& entitySet) const override;
	virtual ZSoft::Boolean      subWorldDraw(ZcGiWorldDraw* mode) override;
	virtual void                subViewportDraw(ZcGiViewportDraw* mode) override;

	virtual void                subList() const override;
	virtual Zcad::ErrorStatus   subGetOsnapPoints(
		ZcDb::OsnapMode     osnapMode,
		ZSoft::GsMarker     gsSelectionMark,
		const ZcGePoint3d&  pickPoint,
		const ZcGePoint3d&  lastPoint,
		const ZcGeMatrix3d& viewXform,
		ZcGePoint3dArray&   snapPoints,
		ZcDbIntArray &   geomIds
		) const override;
	virtual Zcad::ErrorStatus subGetGripPoints(
		ZcDbGripDataPtrArray& grips,
		const double curViewUnitSize,
		const int gripSize,
		const ZcGeVector3d& curViewDir,
		const int bitflags
		) const override;
	virtual Zcad::ErrorStatus   subGetGripPoints(
		ZcGePoint3dArray&   gripPoints,
		ZcDbIntArray&       osnapModes,
		ZcDbIntArray &   geomIds
		) const override;
	virtual void                subGripStatus (const ZcDb::GripStat status) override;
	virtual Zcad::ErrorStatus   subMoveGripPointsAt(
		const ZcDbVoidPtrArray& gripAppData,
		const ZcGeVector3d& offset, 
		const int bitflags) override;
	virtual Zcad::ErrorStatus   subMoveGripPointsAt(
		const ZcDbIntArray& indices,
		const ZcGeVector3d& offset) override;
	virtual Zcad::ErrorStatus   subGetStretchPoints(
		ZcGePoint3dArray&  stretchPoints
		) const override;
	virtual Zcad::ErrorStatus   subMoveStretchPointsAt(
		const ZcDbIntArray& indices,
		const ZcGeVector3d& offset
		) override;
	virtual Zcad::ErrorStatus   subTransformBy(const ZcGeMatrix3d& xform) override;
	virtual Zcad::ErrorStatus   subGetTransformedCopy(
		const ZcGeMatrix3d& xform,
		ZcDbEntity*& ent
		) const override;
	virtual Zcad::ErrorStatus   subGetSubentPathsAtGsMarker(
		ZcDb::SubentType      type,
		ZSoft::GsMarker       gsMark,
		const ZcGePoint3d&    pickPoint,
		const ZcGeMatrix3d&   viewXform,
		int&                  numPaths,
		ZcDbFullSubentPath*&  subentPaths,
		int                   numInserts = 0,
		ZcDbObjectId*         entAndInsertStack = 0
		) const override;
	virtual Zcad::ErrorStatus   subGetGsMarkersAtSubentPath(
		const ZcDbFullSubentPath& subPath, 
		ZcArray<ZSoft::GsMarker>& gsMarkers
		) const override;
	virtual ZcDbEntity*         subSubentPtr(const ZcDbFullSubentPath& id) const override;

	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;

	virtual Zcad::ErrorStatus   subIntersectWith(
		const ZcDbEntity*   ent,
		ZcDb::Intersect     intType,
		ZcGePoint3dArray&   points,
		ZSoft::GsMarker     thisGsMarker  = 0,
		ZSoft::GsMarker     otherGsMarker = 0
		) const override;

	virtual Zcad::ErrorStatus   subIntersectWith(
		const ZcDbEntity*   ent,
		ZcDb::Intersect     intType,
		const ZcGePlane&    projPlane,
		ZcGePoint3dArray&   points,
		ZSoft::GsMarker     thisGsMarker  = 0,
		ZSoft::GsMarker     otherGsMarker = 0
		) const override;
	virtual Zcad::ErrorStatus   subGetGeomExtents(ZcDbExtents& extents) const override;

	friend class ZcDbImpRasterImage;
	void                baseList() const;

private:

	void *operator new[](size_t) throw() { return (void*)0;}
	void operator delete[](void *) {};
	void *operator new[](size_t, const char *, int) throw() { return (void*)0;}
	

    RasterImageImp*			mpImp;
    static ClassVersion     mVersion;
};
#pragma warning (pop)

inline RasterImageImp*
ZcDbRasterImage::ptrImp() const
{
    return mpImp;
}

inline RasterImageImp*             
ZcDbRasterImage::setPtrImp(RasterImageImp* pImp)
{
	RasterImageImp* oldImp=mpImp;
	mpImp=pImp;
	return oldImp;
}

inline ClassVersion
ZcDbRasterImage::classVersion()
{   return mVersion; }

inline void 
pixelToModel(
  const ZcGeMatrix3d&		pixToMod,
  const ZcGePoint2d&		pixPt,
  ZcGePoint3d&				modPt)
{

	modPt.set(pixPt.x, pixPt.y, 0);
	modPt.transformBy(pixToMod);
}

inline void 
modelToPixel(
  const ZcGeMatrix3d&		modToPix,
  const ZcGePoint3d&		modPt,
  ZcGePoint2d&				pixPt)
{

	ZcGePoint3d modelPt = modPt;
	modelPt.transformBy(modToPix);
    pixPt.set(modelPt.x, modelPt.y);
}

inline void
modelToPixel(
  const ZcGeVector3d& viewDir,
  const ZcGeMatrix3d& modToPix,
  const ZcGePlane& plane,
  const ZcGePoint3d& modPt,
  ZcGePoint2d& pixPt)
{

    ZcGePoint3d ptOnPlane = modPt.project(plane, viewDir);
    ptOnPlane.transformBy(modToPix);
    pixPt.set(ptOnPlane.x, ptOnPlane.y);
}

#pragma warning( default : 4275 ) 

#pragma pack (pop)
#endif 
