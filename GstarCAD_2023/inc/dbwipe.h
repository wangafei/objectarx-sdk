/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __DBWIPE_H__
#define __DBWIPE_H__

#ifdef _DBWIPEOBJ_
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

#include "imgdef.h"
#include "imgent.h"

namespace Gtil
{
  class Image;
};

#define WIPEOUTOBJSERVICE	GCRX_T("WipeOut")

#pragma warning(push)
#pragma warning( disable : 4275 ) 
class GCDB_PORT GcDbWipeout : public GcDbRasterImage
{
public:
  GCRX_DECLARE_MEMBERS(GcDbWipeout);
  GcDbWipeout();

  GcRxObject*         clone() const override;
  GcGeVector2d        imageSize(Gsoft::Boolean bGetCachedValue = Gsoft::kFalse) const override;
  GcGiSentScanLines*  getScanLines(const GcGiRequestScanLines& req) const override;
  Gsoft::Boolean		  isClipped() const;
  void				      setDisplayOpt(ImageDisplayOpt option, Gsoft::Boolean bValue) override;
  Gsoft::Boolean		isSetDisplayOpt(ImageDisplayOpt option) const override;

  Gcad::ErrorStatus	setBrightness(Gsoft::Int8 value) override;
  Gsoft::Int8			brightness() const override;

  Gcad::ErrorStatus	setContrast(Gsoft::Int8 value) override;
  Gsoft::Int8			contrast() const override;

  Gcad::ErrorStatus	setFade(Gsoft::Int8 value) override;
  Gsoft::Int8			fade() const override;

  GcGeVector2d        scale() const override;

  Gcad::ErrorStatus           append(GcDbObjectId& id);
  static Gcad::ErrorStatus    createImageDefinition();
  static Gcad::ErrorStatus    fitPointsToImage(
    GcGePoint2dArray& pointArray,
    GcGePoint2d& minPoint,
    double& scale,
    Gsoft::Boolean bFlipY = Gsoft::kFalse);
  Gsoft::Boolean              frame() const;

protected:
  Gsoft::Boolean      subWorldDraw(GcGiWorldDraw* mode) override;
  void                subViewportDraw(GcGiViewportDraw* mode) override;
  void                subList() const override;
  Gcad::ErrorStatus   subMoveGripPointsAt(
    const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d& offset,
    const int bitflags) override;
  Gcad::ErrorStatus   subMoveGripPointsAt(
    const GcDbIntArray& indices,
    const GcGeVector3d&     offset) override;
  Gcad::ErrorStatus   subTransformBy(
    const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus   subGetTransformedCopy(
    const GcGeMatrix3d& xform,
    GcDbEntity*& ent
  ) const override;
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
  Gsoft::UInt32       subSetAttributes(GcGiDrawableTraits * traits) override;

private:
  Gsoft::Boolean              isHighlighted() const;
  void                        getPlane(GcGeBoundedPlane& boundedPlane) const;
  GcGeMatrix2d                fastMatrixInvert(const GcGeMatrix2d& m) const;
  void                        drawFrame(
    GcGiViewportDraw* mode,
    const GcGePoint3dArray& verts) const;
  Gcad::ErrorStatus           setDcToScreen(
    const GcGePoint2d& lowerLeft,
    const GcGePoint2d& upperRight,
    int width,
    int height,
    GcGeMatrix2d& dcToScreen) const;
  void                        setFrameExtents(
    GcGiWorldDraw* mode,
    const GcGePoint3dArray& verts) const;
  bool                        drawFilledPloygon(GcGiViewportDraw* mode,
    const GcGePoint3dArray& verts) const;
  bool                        IsSelfIntersecting(const GcGePoint3dArray& verts) const;
  Gsoft::Boolean              isFrameVisible(Gsoft::Boolean bPlotting = Gsoft::kFalse) const;

public:
  static long                 mImageData;
private:
  Gsoft::Boolean              mHighlight;

  void *operator new[](size_t nSize) throw() { return 0; }
  void operator delete[](void *p) {};
  void *operator new[](size_t nSize, const char *file, int line) throw() { return 0; }
};
#pragma warning(pop)
#endif 