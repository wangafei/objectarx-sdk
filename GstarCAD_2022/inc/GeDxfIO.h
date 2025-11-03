/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2016, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2002-2016 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef OD_GE_DXF_IO_H_
#define OD_GE_DXF_IO_H_

#include "Ge/GeLineSeg3d.h"
#include "Ge/GeEllipArc3d.h"
#include "Ge/GeCircArc3d.h"
#include "Ge/GeNurbCurve3d.h"
#include "Ge/GeCompositeCurve3d.h"
//#include "Ge/GeLibVersion.h"
#include "Ge/GeVector2dArray.h"

class OdDbDxfFiler;
class OdDbDwgFiler;
class OdGeScale2d;
class OdGeCurveBoundary;
class OdGePosition2d;
class OdGeRay2d;
class OdGeExternalCurve2d;
class OdGeCubicSplineCurve2d;
class OdGeCompositeCurve2d;
class OdGeOffsetCurve2d;
class OdGeSegmentChain2d;
class OdGePosition3d;
class OdGeRay3d;
class OdGeCubicSplineCurve3d;
class OdGeOffsetCurve3d;
class OdGeAugPolyline3d;
class OdGeExternalCurve3d;
class OdGeCone;
class OdGeEllipCone;
class OdGeCylinder;
class OdGeEllipCylinder;
class OdGeTorus;
class OdGeExternalSurface;
class OdGeOffsetSurface;
class OdGeExternalBoundedSurface;
class OdGeSphere;
class OdGeCurveCurveInt2d;
class OdGeCurveCurveInt3d;
class OdGePointOnCurve2d;
class OdGePolyline2d;
class OdGeNurbSurface;
class OdGeBoundBlock2d;

/** \details
    This class reads information from and writes information to a DXF file.

    Library: TD_Db
    
    <group OdDb_Classes>
*/
class TOOLKIT_EXPORT OdGeDxfIO
{
public:
  /** \details
    Writes information to a DXF file.

    \param pFiler [in]  Pointer to the OdDbDxfFiler object.
    \param object [in]  OdGe object to be written.
  */
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePoint2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeVector2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeMatrix2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeScale2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePoint2dArray& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeVector2dArray& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePoint3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeVector3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeMatrix3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeScale3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePoint3dArray& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeVector3dArray& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeTol& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeInterval& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeKnotVector& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeDoubleArray& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeIntArray& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCurveBoundary& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePosition2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePointOnCurve2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeLine2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeLineSeg2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeRay2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCircArc2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeEllipArc2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeExternalCurve2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCubicSplineCurve2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeNurbCurve2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCompositeCurve2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeOffsetCurve2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePolyline2d&) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeSegmentChain2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePosition3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePointOnCurve3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePointOnSurface& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeLine3d& object);
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeRay3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeLineSeg3d& object);
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePlane& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeBoundedPlane& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCircArc3d& object);
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeEllipArc3d& object);
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCubicSplineCurve3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeNurbCurve3d& object);
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCompositeCurve3d& object);
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeOffsetCurve3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGePolyline3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeAugPolyline3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeExternalCurve3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCone& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeEllipCone& object) { return eNotImplementedYet; }	// AE 03.09.2003 
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCylinder& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeEllipCylinder& object) { return eNotImplementedYet; }	// AE 09.09.2003 
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeTorus& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeExternalSurface& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeOffsetSurface& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeNurbSurface& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler,const OdGeExternalBoundedSurface& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeSphere& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeBoundBlock2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeBoundBlock3d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCurveCurveInt2d& object) { return eNotImplementedYet; }
  static OdResult outFields(OdDbDxfFiler* pFiler, const OdGeCurveCurveInt3d& object) { return eNotImplementedYet; }

  /** \details
    Reads information from a DXF file.

    \param pFiler [in]  Pointer to the OdDbDxfFiler object.
    \param object [in]  OdGe object to be read.
  */
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePoint2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeVector2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeMatrix2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeScale2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePoint2dArray& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeVector2dArray& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePoint3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeVector3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeMatrix3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeScale3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePoint3dArray& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeVector3dArray& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeTol& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeInterval& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeKnotVector& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeDoubleArray& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdIntArray& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCurveBoundary& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePosition2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePointOnCurve2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeLine2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeLineSeg2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeRay2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCircArc2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeEllipArc2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeExternalCurve2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCubicSplineCurve2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeNurbCurve2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCompositeCurve2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeOffsetCurve2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeSegmentChain2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePosition3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePointOnCurve3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePointOnSurface& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeLine3d& object);
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeRay3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeLineSeg3d& object);
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePlane& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeBoundedPlane& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCircArc3d& object);
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeEllipArc3d& object);
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCubicSplineCurve3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeNurbCurve3d& object);
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCompositeCurve3d& object);
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeOffsetCurve3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGePolyline3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeAugPolyline3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeExternalCurve3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCone& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeEllipCone& object) { return eNotImplementedYet; }	// AE 03.09.2003 
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCylinder& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeEllipCylinder& object) { return eNotImplementedYet; }	// AE 09.09.2003 
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeTorus& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeExternalSurface& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeOffsetSurface& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeNurbSurface& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeExternalBoundedSurface& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeSphere& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeBoundBlock2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeBoundBlock3d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCurveCurveInt2d& object) { return eNotImplementedYet; }
  static OdResult inFields(OdDbDxfFiler* pFiler, OdGeCurveCurveInt3d& object) { return eNotImplementedYet; }

  static const OdGeLibVersion  OdGeDxfIOVersion;
};

#endif // OD_GE_DXF_IO_H_

