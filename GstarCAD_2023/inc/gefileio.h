/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEFILEIO_H
#define GC_GEFILEIO_H     

#include "gcadstrc.h"
#include "gegbl.h"
#include "gedll.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gedblar.h"
#include "geintarr.h"
#pragma pack (push, 8)

class GcGeEntity2d;
class GcGeEntity3d;
class GcGePoint2d;
class GcGeVector2d;
class GcGeMatrix2d;
class GcGeScale2d;
class GcGePoint3d;
class GcGeVector3d;
class GcGeMatrix3d;
class GcGeScale3d;
class GcGeTol;
class GcGeInterval;
class GcGeKnotVector;
class GcGeCurveBoundary;
class GcGePosition2d;
class GcGePointOnCurve2d;
class GcGeLine2d;
class GcGeLineSeg2d;
class GcGeRay2d;
class GcGeCircArc2d;
class GcGeEllipArc2d;
class GcGeExternalCurve2d;
class GcGeCubicSplineCurve2d;
class GcGeCompositeCurve2d;
class GcGeOffsetCurve2d;
class GcGeNurbCurve2d;
class GcGePolyline2d;
class GcGePosition3d;
class GcGePointOnCurve3d;
class GcGePointOnSurface;
class GcGeLine3d;
class GcGeRay3d;
class GcGeLineSeg3d;
class GcGePlane;
class GcGeBoundedPlane;
class GcGeBoundBlock2d;
class GcGeBoundBlock3d;
class GcGeCircArc3d;
class GcGeEllipArc3d;
class GcGeCubicSplineCurve3d;
class GcGeCompositeCurve3d;
class GcGeOffsetCurve3d;
class GcGeNurbCurve3d;
class GcGePolyline3d;
class GcGeAugPolyline3d;
class GcGeExternalCurve3d;
class GcGeSurface;
class GcGeCone;
class GcGeCylinder;
class GcGeTorus;
class GcGeExternalSurface;
class GcGeOffsetSurface;
class GcGeNurbSurface;
class GcGeExternalBoundedSurface;
class GcGeSphere;
class GcGeCurveCurveInt2d;
class GcGeCurveCurveInt3d;
class GcGeEllipCone;

class GcGeFiler;
class GcGeLibVersion;

class
  GcGeFileIO
{
public:
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePoint2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeVector2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeMatrix2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeScale2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePoint2dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeVector2dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePoint3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeVector3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeMatrix3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeScale3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePoint3dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeVector3dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeTol&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeInterval&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeKnotVector&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeDoubleArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler* filer, const GcGeIntArray& ent,
      const GcGeLibVersion& version);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCurveBoundary&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePosition2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePointOnCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeLine2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeLineSeg2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeRay2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCircArc2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeEllipArc2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeExternalCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCubicSplineCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCompositeCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeOffsetCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeNurbCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePolyline2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePosition3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePointOnCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePointOnSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeLine3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeRay3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeLineSeg3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePlane&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeBoundedPlane&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCircArc3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeEllipArc3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCubicSplineCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCompositeCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeOffsetCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeNurbCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGePolyline3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeAugPolyline3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeExternalCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCone&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCylinder&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeTorus&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeExternalSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeOffsetSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeNurbSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeExternalBoundedSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeSphere&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeBoundBlock2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeBoundBlock3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCurveCurveInt2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeCurveCurveInt3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeLibVersion&);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus outFields(GcGeFiler*, const GcGeEllipCone&,
      const GcGeLibVersion& = GcGe::gLibVersion);

  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePoint2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeVector2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeMatrix2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeScale2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePoint2dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeVector2dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePoint3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeVector3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeMatrix3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeScale3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePoint3dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeVector3dArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeTol&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeInterval&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeKnotVector&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeDoubleArray&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler* filer, GcGeIntArray& ent,
      const GcGeLibVersion& version);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCurveBoundary&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePosition2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePointOnCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeLine2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeLineSeg2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeRay2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCircArc2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeEllipArc2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeExternalCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCubicSplineCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCompositeCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeOffsetCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeNurbCurve2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePolyline2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePosition3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePointOnCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePointOnSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeLine3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeRay3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeLineSeg3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePlane&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeBoundedPlane&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCircArc3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeEllipArc3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCubicSplineCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCompositeCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeOffsetCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeNurbCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGePolyline3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeAugPolyline3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeExternalCurve3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCone&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCylinder&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeTorus&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeExternalSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeOffsetSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeNurbSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeExternalBoundedSurface&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeSphere&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeBoundBlock2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeBoundBlock3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCurveCurveInt2d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeCurveCurveInt3d&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GX_DLLEXPIMPORT static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeEllipCone&,
      const GcGeLibVersion& = GcGe::gLibVersion);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus inFields(GcGeFiler*, GcGeLibVersion&);

private:
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeBoolean(GcGeFiler*, Gsoft::Boolean,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readBoolean(GcGeFiler*, Gsoft::Boolean*,
      const GcGeLibVersion&);
  static
    Gcad::ErrorStatus writeBool(GcGeFiler*, bool,
      const GcGeLibVersion&);
  static
    Gcad::ErrorStatus readBool(GcGeFiler*, bool*,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeLong(GcGeFiler*, Gsoft::Int32,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readLong(GcGeFiler*, Gsoft::Int32*,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeDouble(GcGeFiler*, double,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readDouble(GcGeFiler*, double*,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writePoint2d(GcGeFiler*, const GcGePoint2d&,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readPoint2d(GcGeFiler*, GcGePoint2d*,
      const GcGeLibVersion&);
  static
    Gcad::ErrorStatus writeVector2d(GcGeFiler*, const GcGeVector2d&,
      const GcGeLibVersion&);
  static
    Gcad::ErrorStatus readVector2d(GcGeFiler*, GcGeVector2d*,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writePoint3d(GcGeFiler*, const GcGePoint3d&,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readPoint3d(GcGeFiler*, GcGePoint3d*,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeVector3d(GcGeFiler*, const GcGeVector3d&,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readVector3d(GcGeFiler*, GcGeVector3d*,
      const GcGeLibVersion&);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeGcGeSurface(GcGeFiler*, const GcGeSurface&,
      const GcGeLibVersion& version);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readGcGeSurface(GcGeFiler*, GcGeSurface&,
      const GcGeLibVersion& version);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeGcGeEntity2d(GcGeFiler* filer,
      const GcGeEntity2d& ent, const GcGeLibVersion& version);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readGcGeEntity2d(GcGeFiler* filer, GcGeEntity2d*& ent,
      GcGe::EntityId id, const GcGeLibVersion& version);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus writeGcGeEntity3d(GcGeFiler* filer,
      const GcGeEntity3d& ent, const GcGeLibVersion& version);
  GE_DLLDATAEXIMP static
    Gcad::ErrorStatus readGcGeEntity3d(GcGeFiler* filer, GcGeEntity3d*& ent,
      GcGe::EntityId id, const GcGeLibVersion& version);

  static
    Gcad::ErrorStatus writeBytes(GcGeFiler* filer, const void* buf,
      Gsoft::UInt32 len, const GcGeLibVersion& version);
  static
    Gcad::ErrorStatus readBytes(GcGeFiler* filer, void* buf,
      Gsoft::UInt32 len, const GcGeLibVersion& version);

  friend class GcGeEllipArcParamOffset;

};

#pragma pack (pop)
#endif