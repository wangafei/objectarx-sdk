/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEDXFIO_H
#define GC_GEDXFIO_H


#include "gefileio.h"
#include "gelibver.h"
#pragma pack (push, 8)

class GcDbDxfFiler;

class
  GcGeDxfIO
{
public:
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePoint2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeVector2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeMatrix2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeScale2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePoint2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeVector2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePoint3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeVector3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeMatrix3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeScale3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePoint3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeVector3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeTol&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeInterval&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeKnotVector&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeDoubleArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeIntArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCurveBoundary&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePosition2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePointOnCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeLine2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeLineSeg2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeRay2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCircArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeEllipArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeExternalCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCubicSplineCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeNurbCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCompositeCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeOffsetCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePolyline2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePosition3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePointOnCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePointOnSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeLine3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeRay3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeLineSeg3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePlane&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeBoundedPlane&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCircArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeEllipArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCubicSplineCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeNurbCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCompositeCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeOffsetCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGePolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeAugPolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeExternalCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCone&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCylinder&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeTorus&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeExternalSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeOffsetSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeNurbSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeExternalBoundedSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeSphere&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeBoundBlock2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeBoundBlock3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCurveCurveInt2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeCurveCurveInt3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDxfFiler*, const GcGeEllipCone&);

  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePoint2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeVector2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeMatrix2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeScale2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePoint2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeVector2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePoint3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeVector3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeMatrix3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeScale3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePoint3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeVector3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeTol&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeInterval&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeKnotVector&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeDoubleArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeIntArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCurveBoundary&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePosition2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePointOnCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeLine2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeLineSeg2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeRay2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCircArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeEllipArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeExternalCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCubicSplineCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeNurbCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCompositeCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeOffsetCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePolyline2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePosition3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePointOnCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePointOnSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeLine3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeRay3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeLineSeg3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePlane&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeBoundedPlane&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCircArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeEllipArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCubicSplineCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeNurbCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCompositeCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeOffsetCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGePolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeAugPolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeExternalCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCone&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCylinder&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeTorus&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeExternalSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeOffsetSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeNurbSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeExternalBoundedSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeSphere&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeBoundBlock2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeBoundBlock3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCurveCurveInt2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeCurveCurveInt3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDxfFiler*, GcGeEllipCone&);

  GCDB_PORT static const GcGeLibVersion  GcGeDxfIOVersion;
};

#pragma pack (pop)
#endif