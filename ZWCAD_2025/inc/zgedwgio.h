
#ifndef ZC_GEDWGIO_H
#define ZC_GEDWGIO_H

#include "zgefileio.h"
#include "zgelibver.h"
#pragma pack (push, 8)

class ZcDbDwgFiler;

class
ZcGeDwgIO
{
public:

    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeMatrix2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeScale2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeMatrix3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeScale3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeTol&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeInterval&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeKnotVector&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeDoubleArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeIntArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCurveBoundary&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePosition2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePointOnCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLine2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLineSeg2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeRay2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCircArc2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeEllipArc2d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeExternalCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCubicSplineCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeNurbCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCompositeCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeOffsetCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePolyline2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePosition3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePointOnCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePointOnSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLine3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeRay3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLineSeg3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeBoundedPlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCircArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeEllipArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCubicSplineCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeNurbCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCompositeCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeOffsetCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePolyline3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeAugPolyline3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeExternalCurve3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCone&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCylinder&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeTorus&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeExternalSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeOffsetSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeNurbSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*,const ZcGeExternalBoundedSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeSphere&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeBoundBlock2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeBoundBlock3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCurveCurveInt2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCurveCurveInt3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeEllipCone&);

    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeMatrix2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeScale2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeMatrix3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeScale3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeTol&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeInterval&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeKnotVector&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeDoubleArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeIntArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCurveBoundary&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePosition2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePointOnCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLine2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLineSeg2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeRay2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCircArc2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeEllipArc2d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCubicSplineCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeNurbCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCompositeCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeOffsetCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePolyline2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePosition3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePointOnCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePointOnSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLine3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeRay3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLineSeg3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeBoundedPlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCircArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeEllipArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCubicSplineCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCompositeCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeOffsetCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeNurbCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePolyline3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeAugPolyline3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalCurve3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCone&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCylinder&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeTorus&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeOffsetSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeNurbSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalBoundedSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeSphere&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeBoundBlock2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeBoundBlock3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCurveCurveInt2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCurveCurveInt3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeEllipCone&);

    GE_DLLDATAEXIMP static const ZcGeLibVersion  ZcGeDwgIOVersion;
};

#pragma pack (pop)
#endif
