/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbents.h"
#include "imgvars.h"
#include "imgent.h"
#include "GcDbGeoTypes.h"

#pragma pack (push, 8)
#pragma warning(push)
#pragma warning(disable : 4275) 

class GeoMapImp;
#if defined(__linux__)
#ifdef  GCGEOLOCATIONOBJ_API
#  define GCGEOLOCATIONOBJ_PORT  __attribute__ ((__visibility__("default")))
#else
#  define GCGEOLOCATIONOBJ_PORT
#endif
#else
#ifdef  GCGEOLOCATIONOBJ_API
#  define GCGEOLOCATIONOBJ_PORT  __declspec(dllexport)
#else
#  define GCGEOLOCATIONOBJ_PORT
#endif
#endif

class GCGEOLOCATIONOBJ_PORT GcDbGeoMap : public GcDbRasterImage
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGeoMap);

  GcDbGeoMap();
  GcDbGeoMap(GcGeoMapType mapType, GcGeoMapResolution resolution, unsigned int levelOfDetail);
  GcDbGeoMap(GcDbObjectId viewportId, bool isViewportSpecific);
  ~GcDbGeoMap();

public:

  GcGePoint3d			  bottomLeftPt() const;
  double						height() const;
  double						width() const;

  GcGePoint3d				imageBottomLeftPt() const;
  double						imageHeight() const;
  double						imageWidth() const;

  GcGeoMapResolution		resolution() const;
  Gcad::ErrorStatus			setResolution(GcGeoMapResolution resolution);

  unsigned int				LOD() const;

  GcGeoMapType				mapType() const;
  Gcad::ErrorStatus		setMapType(GcGeoMapType mapType);

  Gsoft::Boolean				isOutOfDate() const;

  Gsoft::Boolean				updateMapImage(Gsoft::Boolean bReset = Gsoft::kFalse);

  Gcad::ErrorStatus			dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus			dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus			dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus			dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus     subErase(Gsoft::Boolean erasing) override;

  Gcad::ErrorStatus	        applyPartialUndo(
    GcDbDwgFiler* undoFiler,
    GcRxClass*    classObj
  ) override;

  Gcad::ErrorStatus			subGetOsnapPoints(
    GcDb::OsnapMode osnapMode,
    Gsoft::GsMarker gsSelectionMark,
    const GcGePoint3d& pickPoint,
    const GcGePoint3d& lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray& snapPoints,
    GcDbIntArray& geomIds
  ) const override;
  Gcad::ErrorStatus			subGetGripPoints(
    GcDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const GcGeVector3d& curViewDir,
    const int bitflags
  ) const override;
  Gcad::ErrorStatus			subGetGripPoints(
    GcGePoint3dArray& gripPoints,
    GcDbIntArray& osnapModes,
    GcDbIntArray& geomIds
  ) const override;
  Gcad::ErrorStatus			subMoveGripPointsAt(
    const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d& offset,
    const int bitflags
  ) override;
  Gcad::ErrorStatus			subTransformBy(const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus           subIntersectWith(
    const GcDbEntity*   ent,
    GcDb::Intersect     intType,
    GcGePoint3dArray&   points,
    Gsoft::GsMarker     thisGsMarker = 0,
    Gsoft::GsMarker     otherGsMarker = 0
  ) const override;

  Gcad::ErrorStatus			subMoveGripPointsAt(
    const GcDbIntArray & indices,
    const GcGeVector3d& offset
  ) override;

  Gcad::ErrorStatus           subIntersectWith(
    const GcDbEntity*   ent,
    GcDb::Intersect     intType,
    const GcGePlane&    projPlane,
    GcGePoint3dArray&   points,
    Gsoft::GsMarker     thisGsMarker = 0,
    Gsoft::GsMarker     otherGsMarker = 0
  ) const override;

  GcGiSentScanLines*			getScanLines(const GcGiRequestScanLines& req) const override;
  Gsoft::Boolean				freeScanLines(GcGiSentScanLines* pSSL) const override;
  GcDbObjectId				imageDefId() const override;
  Gcad::ErrorStatus			getVertices(GcGePoint3dArray& verts) const override;
  GcGeVector2d				imageSize(Gsoft::Boolean bGetCachedValue = Gsoft::kFalse) const override;
  const GcGePoint2dArray&		clipBoundary() const override;
  Gcad::ErrorStatus			getImageVertices(GcGePoint3dArray& verts) const;

  Gcad::ErrorStatus		setBrightness(Gsoft::Int8 value) override;
  Gsoft::Int8					brightness() const override;

  Gcad::ErrorStatus   setContrast(Gsoft::Int8 value) override;
  Gsoft::Int8         contrast() const override;

  Gcad::ErrorStatus		setFade(Gsoft::Int8 value) override;
  Gsoft::Int8					fade() const override;

  void                getOrientation(
    GcGePoint3d& origin,
    GcGeVector3d& u,
    GcGeVector3d& v
  ) const override;

protected:
  Gsoft::UInt32				subSetAttributes(GcGiDrawableTraits* pTraits) override;
  Gsoft::Boolean			subWorldDraw(GcGiWorldDraw* pWorldDraw) override;
  void						    subViewportDraw(GcGiViewportDraw* pViewportDraw) override;
  void                subList() const override;
  Gcad::ErrorStatus		subGetGeomExtents(GcDbExtents& extents) const override;
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;

private:
  GeoMapImp*					m_pImp;
  friend class				GcDbGeoMapSystemInternals;

  void *operator new[](size_t nSize) { return (void*)0; }
  void operator delete[](void *p) {};
  void *operator new[](size_t nSize, const char *file, int line) { return (void*)0; }

#ifdef _GSOFT_MAC_
private:
  typedef GcDbRasterImage __super;
#endif

};

#pragma warning(pop)
#pragma pack (pop)