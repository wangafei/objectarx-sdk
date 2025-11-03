
#ifndef ZC_GEDXFIO_H
#define ZC_GEDXFIO_H

#include "zgefileio.h"
#include "zgelibver.h"
#pragma pack (push, 8)

class ZcDbDxfFiler;

class
ZcGeDxfIO
{
public:

    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeMatrix2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeScale2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeMatrix3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeScale3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeTol&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeInterval&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeKnotVector&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeDoubleArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeIntArray&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCurveBoundary&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePosition2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePointOnCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLine2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLineSeg2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeRay2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCircArc2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeEllipArc2d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeExternalCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCubicSplineCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeNurbCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCompositeCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeOffsetCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePolyline2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePosition3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePointOnCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePointOnSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLine3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeRay3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLineSeg3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeBoundedPlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCircArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeEllipArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCubicSplineCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeNurbCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCompositeCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeOffsetCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePolyline3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeAugPolyline3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeExternalCurve3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCone&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCylinder&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeTorus&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeExternalSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeOffsetSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeNurbSurface&);
    GE_DLLEXPIMPORT static
   Zcad::ErrorStatus outFields(ZcDbDxfFiler*,const ZcGeExternalBoundedSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeSphere&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeBoundBlock2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeBoundBlock3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCurveCurveInt2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCurveCurveInt3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeEllipCone&);

    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeMatrix2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeScale2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector2dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeMatrix3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeScale3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector3dArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeTol&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeInterval&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeKnotVector&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeDoubleArray&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeIntArray&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCurveBoundary&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePosition2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePointOnCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLine2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLineSeg2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeRay2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCircArc2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeEllipArc2d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCubicSplineCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeNurbCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCompositeCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeOffsetCurve2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePolyline2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePosition3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePointOnCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePointOnSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLine3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeRay3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLineSeg3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeBoundedPlane&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCircArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeEllipArc3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCubicSplineCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeNurbCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCompositeCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeOffsetCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePolyline3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeAugPolyline3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalCurve3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCone&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCylinder&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeTorus&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeOffsetSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeNurbSurface&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalBoundedSurface&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeSphere&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeBoundBlock2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeBoundBlock3d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCurveCurveInt2d&);
    GE_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCurveCurveInt3d&);
    GX_DLLEXPIMPORT static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeEllipCone&);

    GE_DLLDATAEXIMP static const ZcGeLibVersion  ZcGeDxfIOVersion;
};

#pragma pack (pop)
#endif
