/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEDWGIO_H
#define GC_GEDWGIO_H

#include "gefileio.h"
#include "gelibver.h"
#pragma pack (push, 8)

class GcDbDwgFiler;

class
  GcGeDwgIO
{
public:
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePoint2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeVector2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeMatrix2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeScale2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePoint2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeVector2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePoint3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeVector3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeMatrix3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeScale3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePoint3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeVector3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeTol&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeInterval&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeKnotVector&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeDoubleArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeIntArray&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCurveBoundary&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePosition2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePointOnCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeLine2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeLineSeg2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeRay2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCircArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeEllipArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeExternalCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCubicSplineCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeNurbCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCompositeCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeOffsetCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePolyline2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePosition3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePointOnCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePointOnSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeLine3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeRay3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeLineSeg3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePlane&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeBoundedPlane&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCircArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeEllipArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCubicSplineCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeNurbCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCompositeCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeOffsetCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGePolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeAugPolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeExternalCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCone&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCylinder&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeTorus&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeExternalSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeOffsetSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeNurbSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeExternalBoundedSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeSphere&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeBoundBlock2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeBoundBlock3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCurveCurveInt2d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeCurveCurveInt3d&);
  GCDB_PORT static
    Gcad::ErrorStatus outFields(GcDbDwgFiler*, const GcGeEllipCone&);

  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePoint2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeVector2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeMatrix2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeScale2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePoint2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeVector2dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePoint3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeVector3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeMatrix3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeScale3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePoint3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeVector3dArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeTol&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeInterval&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeKnotVector&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeDoubleArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeIntArray&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCurveBoundary&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePosition2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePointOnCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeLine2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeLineSeg2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeRay2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCircArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeEllipArc2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeExternalCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCubicSplineCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeNurbCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCompositeCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeOffsetCurve2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePolyline2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePosition3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePointOnCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePointOnSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeLine3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeRay3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeLineSeg3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePlane&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeBoundedPlane&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCircArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeEllipArc3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCubicSplineCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCompositeCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeOffsetCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeNurbCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGePolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeAugPolyline3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeExternalCurve3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCone&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCylinder&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeTorus&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeExternalSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeOffsetSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeNurbSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeExternalBoundedSurface&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeSphere&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeBoundBlock2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeBoundBlock3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCurveCurveInt2d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeCurveCurveInt3d&);
  GCDB_PORT static
    Gcad::ErrorStatus inFields(GcDbDwgFiler*, GcGeEllipCone&);

  GCDB_PORT static const GcGeLibVersion  GcGeDwgIOVersion;
};

#pragma pack (pop)
#endif