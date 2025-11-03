/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __IMGENT_H
#define __IMGENT_H

#include "dbents.h"
#include "dbimage.h"
#include "gcgi.h"
#include "gept3dar.h"
#include "gebndpln.h"
#include "geplin2d.h"
#include "dbproxy.h"
#pragma pack (push, 8)

const double kEpsilon = 1.0e-7;

const int kAllEntityProxyFlags =
  GcDbProxyEntity::kEraseAllowed               |
  GcDbProxyEntity::kTransformAllowed           |
  GcDbProxyEntity::kColorChangeAllowed         |
  GcDbProxyEntity::kLayerChangeAllowed         |
  GcDbProxyEntity::kLinetypeChangeAllowed      |
  GcDbProxyEntity::kMaterialChangeAllowed      |
  GcDbProxyEntity::kLinetypeScaleChangeAllowed |
  GcDbProxyEntity::kVisibilityChangeAllowed;

class RasterImageImp;

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

class GCDB_PORT GcDbRasterImage : public GcDbImage
{
public:
  static ClassVersion         classVersion();

  GCRX_DECLARE_MEMBERS(GcDbRasterImage);
  GcDbRasterImage();
  ~GcDbRasterImage();

  RasterImageImp*     ptrImp() const;
  RasterImageImp*     setPtrImp(RasterImageImp* pImp);

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* filer) const override;

  Gcad::ErrorStatus   subSwapIdWith(GcDbObjectId   otherId,
                                    Gsoft::Boolean swapXdata = Gsoft::kFalse,
                                    Gsoft::Boolean swapExtDict = Gsoft::kFalse) override;

  void                saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;

  bool                castShadows() const override;
  void                setCastShadows(bool newVal) override;
  bool                receiveShadows() const override;
  void                setReceiveShadows(bool newVal) override;

  GcGiSentScanLines*  getScanLines(const GcGiRequestScanLines& req) const override;
  Gsoft::Boolean      freeScanLines(GcGiSentScanLines* pSSL) const override;

  virtual Gcad::ErrorStatus   setImageDefId(GcDbObjectId imageId);
  virtual GcDbObjectId        imageDefId() const;

  virtual void                setReactorId(GcDbObjectId reactorId);
  virtual GcDbObjectId        reactorId() const;

  virtual Gsoft::Boolean      setOrientation(const GcGePoint3d&  origin,
                                             const GcGeVector3d& uCorner,
                                             const GcGeVector3d& vOnPlane);
  virtual void                getOrientation(GcGePoint3d&  origin,
                                             GcGeVector3d& u,
                                             GcGeVector3d& v) const;

  virtual GcGeVector2d        scale() const;
  virtual GcGeVector2d        imageSize(Gsoft::Boolean bGetCachedValue = Gsoft::kFalse) const;

  enum ClipBoundaryType
  {
    kInvalid,
    kRect,
    kPoly
  };
#ifndef _GSOFT_MAC_
  virtual Gcad::ErrorStatus   setClipBoundaryToWholeImage(GcGeVector2d& size);
  Gcad::ErrorStatus           setClipBoundaryToWholeImage()
  {
    GcGeVector2d size(0, 0);
    return setClipBoundaryToWholeImage(size);
  }
#else
  virtual Gcad::ErrorStatus   setClipBoundaryToWholeImage(GcGeVector2d& size);
  virtual Gcad::ErrorStatus   setClipBoundaryToWholeImage()
  {
    GcGeVector2d size(0, 0);
    return setClipBoundaryToWholeImage(size);
  }
#endif 
  virtual Gcad::ErrorStatus        setClipBoundary(ClipBoundaryType type, const GcGePoint2dArray&);
  virtual const GcGePoint2dArray&  clipBoundary() const;
  virtual ClipBoundaryType         clipBoundaryType() const;
  Gsoft::Boolean                   isClipped() const;

  virtual Gcad::ErrorStatus   getVertices(GcGePoint3dArray& verts) const;
  virtual Gcad::ErrorStatus   getPixelToModelTransform(GcGeMatrix3d&) const;

  enum ImageDisplayOpt
  {
    kShow          = 1,
    kShowUnAligned = 2,
    kClip          = 4,
    kTransparent   = 8
  };

  virtual void                setDisplayOpt(ImageDisplayOpt option, Gsoft::Boolean bValue);
  virtual Gsoft::Boolean      isSetDisplayOpt(ImageDisplayOpt option) const;

  virtual Gcad::ErrorStatus   setBrightness(Gsoft::Int8 value);
  virtual Gsoft::Int8         brightness() const;

  virtual Gcad::ErrorStatus   setContrast(Gsoft::Int8 value);
  virtual Gsoft::Int8         contrast() const;

  virtual Gcad::ErrorStatus   setFade(Gsoft::Int8 value);
  virtual Gsoft::Int8         fade() const;

  virtual Gsoft::Boolean      isClipInverted() const;
  virtual void                setClipInverted(Gsoft::Boolean newVal);

  double                      width() const;
  double                      height() const;

  double                      imageHeight() const;
  double                      imageWidth() const;
  Gcad::ErrorStatus           setHeight(double);
  Gcad::ErrorStatus           setWidth(double);
  GcGePoint3d                 position() const;

  double                      rotation() const;
  Gcad::ErrorStatus           setRotation(double rotation);

  bool                        isImageShown() const;
  void                        setShowImage(bool value);

  bool                        isImageTransparent() const;
  void                        setImageTransparency(bool value);

  bool                        isShownClipped() const;
  void                        setShowClipped(bool value);

protected:
  Gcad::ErrorStatus   subExplode(GcDbVoidPtrArray& entitySet) const override;
  Gsoft::Boolean      subWorldDraw(GcGiWorldDraw* mode) override;
  void                subViewportDraw(GcGiViewportDraw* mode) override;

  void                subList() const override;
  Gcad::ErrorStatus   subGetOsnapPoints(GcDb::OsnapMode     osnapMode,
                                        Gsoft::GsMarker     gsSelectionMark,
                                        const GcGePoint3d&  pickPoint,
                                        const GcGePoint3d&  lastPoint,
                                        const GcGeMatrix3d& viewXform,
                                        GcGePoint3dArray&   snapPoints,
                                        GcDbIntArray &      geomIds) const override;
  Gcad::ErrorStatus   subGetGripPoints(GcDbGripDataPtrArray& grips,
                                       const double          curViewUnitSize,
                                       const int             gripSize,
                                       const GcGeVector3d&   curViewDir,
                                       const int             bitflags) const override;
  Gcad::ErrorStatus   subGetGripPoints(GcGePoint3dArray&   gripPoints,
                                       GcDbIntArray&       osnapModes,
                                       GcDbIntArray &      geomIds) const override;
  void                subGripStatus(const GcDb::GripStat status) override;
  Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbVoidPtrArray& gripAppData,
                                          const GcGeVector3d&     offset,
                                          const int               bitflags) override;
  Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbIntArray& indices,
                                          const GcGeVector3d& offset) override;
  Gcad::ErrorStatus   subGetStretchPoints(GcGePoint3dArray& stretchPoints) const override;
  Gcad::ErrorStatus   subMoveStretchPointsAt(const GcDbIntArray& indices,
                                             const GcGeVector3d& offset) override;
  Gcad::ErrorStatus   subTransformBy(const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus   subGetTransformedCopy(const GcGeMatrix3d& xform,
                                            GcDbEntity*& ent) const override;
  Gcad::ErrorStatus   subGetSubentPathsAtGsMarker(GcDb::SubentType      type,
                                                  Gsoft::GsMarker       gsMark,
                                                  const GcGePoint3d&    pickPoint,
                                                  const GcGeMatrix3d&   viewXform,
                                                  int&                  numPaths,
                                                  GcDbFullSubentPath*&  subentPaths,
                                                  int                   numInserts = 0,
                                                  GcDbObjectId*         entAndInsertStack = 0) const override;
  Gcad::ErrorStatus   subGetGsMarkersAtSubentPath(const GcDbFullSubentPath& subPath,
                                                  GcArray<Gsoft::GsMarker>& gsMarkers) const override;
  GcDbEntity*         subSubentPtr(const GcDbFullSubentPath& id) const override;
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
  Gcad::ErrorStatus   subIntersectWith(const GcDbEntity*   ent,
                                       GcDb::Intersect     intType,
                                       GcGePoint3dArray&   points,
                                       Gsoft::GsMarker     thisGsMarker = 0,
                                       Gsoft::GsMarker     otherGsMarker = 0) const override;
  Gcad::ErrorStatus   subIntersectWith(const GcDbEntity*   ent,
                                       GcDb::Intersect     intType,
                                       const GcGePlane&    projPlane,
                                       GcGePoint3dArray&   points,
                                       Gsoft::GsMarker     thisGsMarker = 0,
                                       Gsoft::GsMarker     otherGsMarker = 0) const override;
  Gcad::ErrorStatus   subGetGeomExtents(GcDbExtents& extents) const override;

  friend class GcDbImpRasterImage;
  void                baseList() const;

private:
  void *operator new[](size_t) throw() { return (void*)0; }
  void operator delete[](void *) {};
  void *operator new[](size_t, const char *, int) throw() { return (void*)0; }

  RasterImageImp*         mpImp;
  static ClassVersion     mVersion;
};

inline RasterImageImp* GcDbRasterImage::ptrImp() const
{
  return mpImp;
}

inline RasterImageImp* GcDbRasterImage::setPtrImp(RasterImageImp* pImp)
{
  RasterImageImp* oldImp = mpImp;
  mpImp = pImp;
  return oldImp;
}

inline ClassVersion GcDbRasterImage::classVersion()
{
  return mVersion;
}

inline void pixelToModel(
  const GcGeMatrix3d&   pixToMod,
  const GcGePoint2d&    pixPt,
  GcGePoint3d&          modPt)
{
  modPt.set(pixPt.x, pixPt.y, 0);
  modPt.transformBy(pixToMod);
}

inline void modelToPixel(
  const GcGeMatrix3d&   modToPix,
  const GcGePoint3d&    modPt,
  GcGePoint2d&          pixPt)
{
  GcGePoint3d modelPt = modPt;
  modelPt.transformBy(modToPix);
  pixPt.set(modelPt.x, modelPt.y);
}

inline void modelToPixel(
  const GcGeVector3d& viewDir,
  const GcGeMatrix3d& modToPix,
  const GcGePlane&    plane,
  const GcGePoint3d&  modPt,
  GcGePoint2d&        pixPt)
{
  GcGePoint3d ptOnPlane = modPt.project(plane, viewDir);
  ptOnPlane.transformBy(modToPix);
  pixPt.set(ptOnPlane.x, ptOnPlane.y);
}

#pragma warning( default : 4275 )

#pragma pack (pop)
#endif
