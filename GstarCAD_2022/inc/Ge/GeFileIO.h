///////////////////////////////////////////////////////////////////////////////
// Copyright ?2006, Open Design Alliance Inc. ("Open Design") 
// 
// This software is owned by Open Design, and may only be incorporated into 
// application programs owned by members of Open Design subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with 
// Open Design. The structure and organization of this Software are the valuable 
// trade secrets of Open Design and its suppliers. The Software is also protected 
// by copyright law and international treaty provisions. Application 
// programs incorporating this software must include the following statement 
// with their copyright notices:
//
//      DWGdirect ?2006 by Open Design Alliance Inc. All rights reserved. 
//
// By use of this software, you acknowledge and accept the terms of this 
// agreement.
///////////////////////////////////////////////////////////////////////////////



#ifndef OD_GE_FILE_IO_H
#define OD_GE_FILE_IO_H /* {Secret} */


class OdGeEntity2d;
class OdGeEntity3d;
class OdGePoint2d;
class OdGeVector2d;
class OdGeMatrix2d;
class OdGeScale2d;
class OdGePoint3d;
class OdGeVector3d;
class OdGeMatrix3d;
class OdGeScale3d;
class OdGeTol;
class OdGeInterval;
class OdGeKnotVector;
class OdGeCurveBoundary;
class OdGePosition2d;
class OdGePointOnCurve2d;
class OdGeLine2d;
class OdGeLineSeg2d;
class OdGeRay2d;
class OdGeCircArc2d;
class OdGeEllipArc2d;
class OdGeExternalCurve2d;
class OdGeCubicSplineCurve2d;
class OdGeCompositeCurve2d;
class OdGeOffsetCurve2d;
class OdGeNurbCurve2d;
class OdGePolyline2d;
class OdGePosition3d;
class OdGePointOnCurve3d;
class OdGePointOnSurface;
class OdGeLine3d;
class OdGeRay3d;
class OdGeLineSeg3d;
class OdGePlane;
class OdGeBoundedPlane;
class OdGeBoundBlock2d;
class OdGeBoundBlock3d;
class OdGeCircArc3d;
class OdGeEllipArc3d;
class OdGeCubicSplineCurve3d;
class OdGeCompositeCurve3d;
class OdGeOffsetCurve3d;
class OdGeNurbCurve3d;
class OdGePolyline3d;
class OdGeAugPolyline3d;
class OdGeExternalCurve3d;
class OdGeSurface;
class OdGeCone;
class OdGeCylinder;
class OdGeTorus;
class OdGeExternalSurface;
class OdGeOffsetSurface;
class OdGeNurbSurface;
class OdGeExternalBoundedSurface;
class OdGeSphere;
class OdGeCurveCurveInt2d;
class OdGeCurveCurveInt3d;
class OdGeEllipCone; 
class OdGeEllipCylinder; 

class OdGeFiler;
class OdGeLibVersion;

#include "../Ge/GeGbl.h"
#include "../Ge/GeLibVersion.h"
#include "../Ge/Ge.h"
#include "../Ge/GeIntArray.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GePoint3dArray.h"
#include "../Ge/GeVector2dArray.h"
#include "../Ge/GeVector3dArray.h"

/**
    Description:
    This class reads information from and writes information to a file.

    Library: Ge

    {group:OdGe_Classes} 
*/
class OdGeFileIO
{
public:
  /**
    Description:
    Writes information to a file.

    Arguments:
    pFiler (I) Pointer to the OdGeFiler *object*.
    object (I) OdGe *object* to be written.
    libVersion (I) OdGe library version.
  */
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePoint2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeVector2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeMatrix2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeScale2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePoint2dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeVector2dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePoint3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeVector3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeMatrix3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeScale3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePoint3dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeVector3dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeTol& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeInterval& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeKnotVector& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeDoubleArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler, 
    const OdGeIntArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCurveBoundary& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePosition2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);  
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePointOnCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeLine2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeLineSeg2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeRay2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCircArc2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeEllipArc2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeExternalCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCubicSplineCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCompositeCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeOffsetCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeNurbCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePolyline2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePosition3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePointOnCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePointOnSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeLine3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeRay3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeLineSeg3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePlane& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeBoundedPlane& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCircArc3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeEllipArc3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCubicSplineCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCompositeCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeOffsetCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeNurbCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGePolyline3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeAugPolyline3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeExternalCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCone& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeEllipCone& object,    
    const OdGeLibVersion& = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCylinder& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeEllipCylinder& object, 
    const OdGeLibVersion& = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeTorus& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeExternalSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeOffsetSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeNurbSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeExternalBoundedSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeSphere& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeBoundBlock2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeBoundBlock3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCurveCurveInt2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeCurveCurveInt3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void outFields (
    OdGeFiler* pFiler,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);

  /**
    Description:
    Reads information from a file.

    Arguments:
    pFiler (I) Pointer to the OdGeFiler *object*.
    object (O) Receives the OdGe *object* to be read.
    libVersion (I) OdGe library version.
  */
  static void inFields (
    OdGeFiler* pFiler,
    OdGePoint2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeVector2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeMatrix2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeScale2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePoint2dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeVector2dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePoint3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeVector3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeMatrix3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeScale3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePoint3dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeVector3dArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeTol& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeInterval& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeKnotVector& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeDoubleArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler, 
    OdGeIntArray& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCurveBoundary& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePosition2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePointOnCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeLine2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeLineSeg2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeRay2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCircArc2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeEllipArc2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeExternalCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCubicSplineCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCompositeCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeOffsetCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeNurbCurve2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePolyline2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePosition3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePointOnCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePointOnSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeLine3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeRay3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeLineSeg3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePlane& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeBoundedPlane& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCircArc3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeEllipArc3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCubicSplineCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCompositeCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeOffsetCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeNurbCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGePolyline3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeAugPolyline3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeExternalCurve3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCone& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeEllipCone& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion); 
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCylinder& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeEllipCylinder& object,  
    const OdGeLibVersion& = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeTorus& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeExternalSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeOffsetSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeNurbSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeExternalBoundedSurface& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeSphere& object,
    const OdGeLibVersion& libVersionsion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeBoundBlock2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeBoundBlock3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCurveCurveInt2d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    OdGeCurveCurveInt3d& object,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);
  static void inFields (
    OdGeFiler* pFiler,
    const OdGeLibVersion& libVersion = OdGe::gLibVersion);

private:
  static
  void writeBoolean(OdGeFiler*, OdBool,
    const OdGeLibVersion&);
  static
  void readBoolean(OdGeFiler*, OdBool*,
    const OdGeLibVersion&);
  void writeBool(OdGeFiler*, bool,
    const OdGeLibVersion&);
  static
    void readBool(OdGeFiler*, bool*,
    const OdGeLibVersion&);
  static
    void writeLong(OdGeFiler*, long,
    const OdGeLibVersion&);
  static
    void readLong(OdGeFiler*, long*,
    const OdGeLibVersion&);
  static
    void writeDouble(OdGeFiler*, double,
    const OdGeLibVersion&);
  static
    void readDouble(OdGeFiler*, double*,
    const OdGeLibVersion&);
  static
    void writePoint2d(OdGeFiler*, const OdGePoint2d&,
    const OdGeLibVersion&);
  static
    void readPoint2d(OdGeFiler*, OdGePoint2d*,
    const OdGeLibVersion&);
  static
    void writeVector2d(OdGeFiler*, const OdGeVector2d&,
    const OdGeLibVersion&);
  static
    void readVector2d(OdGeFiler*, OdGeVector2d*,
    const OdGeLibVersion&);
  static
    void writePoint3d(OdGeFiler*, const OdGePoint3d&,
    const OdGeLibVersion&);
  static    void readPoint3d(OdGeFiler*, OdGePoint3d*,
    const OdGeLibVersion&);
  static
    void writeVector3d(OdGeFiler*, const OdGeVector3d&,
    const OdGeLibVersion&);
  static
    void readVector3d(OdGeFiler*, OdGeVector3d*,
    const OdGeLibVersion&);
  static
    void writeAcGeSurface(OdGeFiler*, const OdGeSurface&,
    const OdGeLibVersion& version);
  static
    void readAcGeSurface(OdGeFiler*, OdGeSurface&,
    const OdGeLibVersion& version);
  static
    void writeAcGeEntity2d(OdGeFiler* pFiler,
    const OdGeEntity2d& ent, const OdGeLibVersion& version);
  static
    void readAcGeEntity2d(OdGeFiler* pFiler, OdGeEntity2d*& ent,
    OdGe::EntityId id, const OdGeLibVersion& version);
  static
    void writeAcGeEntity3d(OdGeFiler* pFiler,
    const OdGeEntity3d& ent, const OdGeLibVersion& version);
  static
    void readAcGeEntity3d(OdGeFiler* pFiler, OdGeEntity3d*& ent,
    OdGe::EntityId id, const OdGeLibVersion& version);

  friend class OdGeFileIOX;

};

#endif // OD_GE_FILE_IO_H


