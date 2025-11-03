/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

#ifndef _OD_DB_CURVE_PE_
#define _OD_DB_CURVE_PE_


#include "DbCurve.h"

/** Description:
    This class defines the interface for the Curve Protocol Extension classes.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbCurvePE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbCurvePE);

  /** Description:
    Creates a curve by projecting the specified Curve object onto the specified plane
    along a normal to the place.
    
    Arguments:
    pCurve (I) Pointer to the curve to project.
    projPlane (I) Projection plane.
    pProjCurve (O) Receives a SmartPointer to the projected curve.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getOrthoProjectedCurve(const OdDbCurve* pCurve, 
    const OdGePlane& projPlane, 
    OdDbCurve*& pProjCurve) const = 0;

 /** Description:
    Creates a curve by projecting the specified Curve object onto the specified plane
    along the specified direction.
    
    Arguments:
    pCurve (I) Pointer to the curve to project.
    projPlane (I) Projection plane.
    projDirection (I) Projection direction.
    pProjCurve (O) Receives a SmartPointer to the projected curve.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getProjectedCurve(const OdDbCurve* pCurve, 
    const OdGePlane& projPlane,
    const OdGeVector3d& projDirection, 
    OdDbCurve*& pProjCurve) const = 0;

  /** Description:
    Creates a set of curves representing the offsetting the specified Curve object by the specified distance.
    Arguments:
    pCurve (I) Pointer to the curve to offset.
    offsetDistance (I) Offset distance.
    offsetCurves (O) Receives an array of SmartPointers to the offset curves.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Pointers to all new curves are appended to the offsetCurves array.
  */
  virtual OdResult getOffsetCurves(const OdDbCurve* pCurve, 
    double offsetDistance,  
    OdDbVoidPtrArray& offsetCurves) const = 0;

  /** Description:
    Creates a set of curves representing the offsetting of the specified Curve object by the specified distance in a
    plane with the specified *normal*.
    Arguments:
    pCurve (I) Pointer to the curve to offset.
    offsetDistance (I) Offset distance.
    offsetCurves (O) Receives an array of SmartPointers to the offset curves.
    normal (I) Normal of the plane.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Pointers to all new curves are appended to the offsetCurves array.
  */
  virtual OdResult getOffsetCurvesGivenPlaneNormal(const OdDbCurve* pCurve, 
    const OdGeVector3d& normal, 
    double offsetDistance,
    OdDbVoidPtrArray& offsetCurves) const = 0;          

  /** Description:
    Creates a set of curves representing this splitting of the specified Curve object at the specified (parametric) *points*. 
    Arguments:
    pCurve (I) Pointer to the curve to offset.
    params (I) Array of curve parameters defining the segments.
    points (I) Array of *points* defining the segments.
    curveSegments (O) Receives an array of SmartPointers to the curves segments.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Pointers to all new curves are appended to the curveSegments array.
  */
  virtual OdResult getSplitCurves (const OdDbCurve* pCurve, 
    const OdGeDoubleArray& params, 
    OdDbVoidPtrArray& curveSegments) const = 0;

  virtual OdResult getSplitCurves (const OdDbCurve* pCurve, 
    const OdGePoint3dArray& points, 
    OdDbVoidPtrArray& curveSegments) const = 0;

  /**
    Description:
    Extends the specified Curve object to the specified WCS point.
    
    Arguments:
    pCurve (I) Pointer to the curve to extend.
    param (I) Parameter specifying point.
    toPoint (I) Point to which to extend.
    extendStart (I) True to extend start of curve, false to extend end of curve.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult extend(OdDbCurve* pCurve, 
    double param) = 0;

  virtual OdResult extend(
    OdDbCurve* pCurve, 
    bool extendStart,
    const OdGePoint3d& toPoint) = 0;


  /**
    Description:
    Returns an OdDbSpline approximation of the specified Curve object.
    
    Arguments:
    pCurve (I) Pointer to the curve.
    spline (O) Receives a SmartPointer to the OdDbSpline.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
 */
  virtual OdResult getSpline (const OdDbCurve* pCurve, 
    OdDbSpline*& spline) const = 0;


  /**
    Description:
    Returns the point on the specified Curve object closest to the given point.
    
    Arguments:
    pCurve (I) Pointer to the curve.
    givenPoint (I) Given point.
    pointOnCurve (O) Receives the closed point on this Curve object.
    extend (I) Extends this Curve object if and only if true.
    normal (I) Normal to the projection plane.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    If normal is specified, this Curve object is projected onto the plane
    defined by givenPoint and normal, finds the closest point on
    the projected curve to givenPoint, and projects said closest
    point back onto the plane of this Curve object. It is this point
    that is returned as pointOnCurve. 
  */
  virtual OdResult getClosestPointTo(const OdDbCurve* pCurve, 
    const OdGePoint3d& givenPoint,
    OdGePoint3d& pointOnCurve, 
    bool extend = false) const = 0;

  virtual OdResult getClosestPointTo(const OdDbCurve* pCurve, 
    const OdGePoint3d& givenPoint,
    const OdGeVector3d& normal,
    OdGePoint3d& pointOnCurve, 
    bool extend = false) const = 0;

  virtual OdResult reverseCurve(OdDbCurve *pCurve) = 0;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbCurvePE object pointers.
*/
typedef OdSmartPtr<OdDbCurvePE> OdDbCurvePEPtr;

#endif //_OD_DB_CURVE_PE_
