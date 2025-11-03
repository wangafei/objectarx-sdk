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




#ifndef OD_DBCURVE_H
#define OD_DBCURVE_H

#include "TD_PackPush.h"

#include "DbEntity.h"

class OdDbSpline;
typedef OdSmartPtr<OdDbSpline> OdDbSplinePtr;

class OdDbCurveImpl;
class OdDbCurve;

/** Description:
This template class is a specialization of the OdSmartPtr class for OdDbCurve object pointers.
*/
typedef OdSmartPtr<OdDbCurve> OdDbCurvePtr;
/** 
    Description:
    The class is the base class for all OdDb curves.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbCurve : public OdDbEntity
{
protected:
  OdDbCurve();
public:
  ODDB_DECLARE_MEMBERS(OdDbCurve);
  /**
  Gcad(Add):增加兼容接口
  */
  virtual ~OdDbCurve();

  /** 
    Description:
    Returns true if and only if this Curve object is closed.
  */
  virtual OdBool isClosed() const;

  /** 
    Description:
    Returns true if and only if this Curve object is periodic.
  */
  virtual OdBool isPeriodic() const;

  /** 
    Description:
    Returns the parameter corresponding to the start point of this Curve object.

    Arguments:
    startParam (O) Receives the start parameter.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getStartParam(
    double& startParam) const;

  /** 
    Description:
    Returns the parameter corresponding to the end point of this Curve object.

    Arguments:
    endParam (O) Receives the end parameter.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getEndParam(
    double& endParam) const;

  /** 
    Description:
    Returns the WCS start point of this Curve object.

    Arguments:
    startPoint (O) Receives the start point.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getStartPoint(
    OdGePoint3d& startPoint) const;

  /** 
    Description:
    Returns the WCS end point of this Curve object.

    Arguments:
    endPoint (O) Receives the end point.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getEndPoint(
    OdGePoint3d& endPoint) const;

  /**
    Description:
    Returns the WCS point on this Curve object corresponding to the specified parameter.
    
    Arguments:
    param (I) Parameter specifying point.
    pointOnCurve (O) Receives the point on this Curve object.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */    
  virtual OdResult getPointAtParam(
    double param, 
    OdGePoint3d& pointOnCurve) const;

  /**
    Description:
    Returns the parameter corresponding to the specified WCS point on this Curve object.

    Arguments:
    param (O) Receives the parameter corresponding to pointOnCurve.
    pointOnCurve (I) Point to be evaluated.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */    
  virtual OdResult getParamAtPoint(
    const OdGePoint3d& pointOnCurve, 
    double& param) const;

  /**
    Description:
    Returns the distance along this Curve object from its start point to the point specified by param.
    
    Arguments:
    param (I) Parameter specifying point.
    dist (O) Receives the distance. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getDistAtParam (
    double param, 
    double& dist) const;

  /**
    Description:
    Returns the parameter corresponding to the point a specified distance 
    along this Curve object from its start point.
    
    Arguments:
    param (O) Receives the parameter.
    dist (I) Distance along the curve. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getParamAtDist (
    double dist, 
    double& param) const;

  /**
    Description:
    Returns the distance along this Curve object from its start point to the specified WCS point.
    
    Arguments:
    pointOnCurve (I) Point on the curve.
    dist (O) Receives the distance. 
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getDistAtPoint (
    const OdGePoint3d& pointOnCurve, 
    double& dist)const;

  /**
    Description:
    Returns the WCS point a specified distance along this Curve object from its start point.
    
    Arguments:
    pointOnCurve (O) Receives the point.
    dist (I) Distance along the curve. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getPointAtDist (
    double dist, 
    OdGePoint3d& pointOnCurve) const;
  
  /**
    Description:
    Returns the first derivative of this Curve object at the specified WCS point.
    
    Arguments:
    param (I) Parameter specifying point.
    pointOnCurve (I) Point on the curve.
    firstDeriv (O) Receives the first derivative. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getFirstDeriv (
    double param,
    OdGeVector3d& firstDeriv) const;

  virtual OdResult getFirstDeriv (
    const OdGePoint3d& pointOnCurve,
    OdGeVector3d& firstDeriv) const;

  /**
    Description:
    Returns the second derivative of this Curve object at the specified point.
    
    Arguments:
    param (I) Parameter specifying point.
    pointOnCurve (I) Point on the curve.
    secondDeriv (O) Receives the first derivative. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getSecondDeriv (
    double param,
    OdGeVector3d& secondDeriv) const;

  virtual OdResult getSecondDeriv (
    const OdGePoint3d& pointOnCurve,
    OdGeVector3d& secondDeriv) const;

  /**
    Description:
    Returns the point on this Curve object closest to the given point.
    
    Arguments:
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
  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPoint,
    OdGePoint3d& pointOnCurve, 
    OdBool extend = kFalse) const;

  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPoint,
    const OdGeVector3d& normal,
    OdGePoint3d& pointOnCurve, 
    OdBool extend = kFalse) const;
  

  /**
    Description:
    Returns OdDbSpline approximation of this Curve object.    
    Arguments:
    spline (O) Receives a SmartPointer to the OdDbSpline.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
 */
  virtual OdResult getSpline (
    OdDbSpline*& spline) const;

  /**
    Description:
    Extends this Curve object to the specified WCS point.
    
    Arguments:
    param (I) Parameter specifying point.
    toPoint (I) Point to which to extend.
    extendStart (I) True to extend start of curve, false to extend end of curve.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult extend(
    double param);
  
  virtual OdResult extend(
    OdBool extendStart,
    const OdGePoint3d& toPoint);

  /**
    Description:
    Returns the *area* of this Curve object.

    Arguments:
    area (O) Receives the *area*.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getArea(
    double& area) const;
  
  /** Description:
    Creates a curve by projecting this Curve object onto the specified plane
    along its normal.
    
    Arguments:
    projPlane (I) Projection plane.
    pProjCurve (O) Receives a SmartPointer to the projected curve.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getOrthoProjectedCurve(const OdGePlane& projPlane,
    OdDbCurve*& pProjCurve) const;

  /** Description:
    Creates a curve by projecting this Curve object onto the specified plane
    along the specified direction.
    
    Arguments:
    projPlane (I) Projection plane.
    projDirection (I) Projection direction.
    pProjCurve (O) Receives a SmartPointer to the projected curve.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getProjectedCurve(const OdGePlane& projPlane,
    const OdGeVector3d& projDirection, OdDbCurve*& pProjCurve) const;

  /** Description:
    Creates a set of curves representing the offsetting of this Curve object by the specified distance.
    Arguments:
    offsetDistance (I) Offset distance.
    offsetCurves (O) Receives an array of SmartPointers to the offset curves.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Pointers to all new curves are appended to the offsetCurves array.
  */
  virtual OdResult getOffsetCurves(double offsetDistance,  
    OdDbVoidPtrArray& offsetCurves) const;

  /** Description:
    Creates a set of curves representing the offsetting of this Curve object by the specified distance in a
    plane with the specified *normal*.
    Arguments:
    offsetDistance (I) Offset distance.
    offsetCurves (O) Receives an array of SmartPointers to the offset curves.
    normal (I) Normal of the plane.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Pointers to all new curves are appended to the offsetCurves array.
  */
  virtual OdResult getOffsetCurvesGivenPlaneNormal(
    const OdGeVector3d& normal, double offsetDistance,
    OdDbVoidPtrArray& offsetCurves) const;          

  /** Description:
    Creates a set of curves representing this splitting of this Curve object at the specified (parametric) *points*. 
    Arguments:
    params (I) Array of curve parameters defining the segments.
    points (I) Array of *points* defining the segments.
    curveSegments (O) Receives an array of SmartPointers to the curves segments.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Pointers to all new curves are appended to the curveSegments array.
  */
  virtual OdResult getSplitCurves (const OdGeDoubleArray& params,
    OdDbVoidPtrArray& curveSegments) const;

  virtual OdResult getSplitCurves (const OdGePoint3dArray& points,
    OdDbVoidPtrArray& curveSegments) const;

  virtual OdResult reverseCurve();

  /** Description:
    Returns an OdGeCurve3d that is geometrically identical to this OdDbCurve.
    Arguments:
    pGeCurve (O) Receives a pointer to an OdGeCurve3d object that is geometrically identical to this OdDbCurve.
    The caller of this function is responsible for deleting this OdGeCurve3d object.
    tol (I) Optional tolerance.
    Returns:
    Returns eOk if successful.
  */
  virtual OdResult  getOdGeCurve ( OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol ) const;


  /** Description:
    Takes an OdGeCurve3d and returns an OdDbCurve that is geometrically identical to the OdGeCurve3d.
    Arguments:
    geCurve (I) Reference to an OdGeCurve3d.
    pDbCurve (O) Receives a pointer to an OdDbCurve object that is geometrically identical to geCurve.
    The caller of this function is responsible for deleting this OdDbCurve object or adding it to the database.
    normal (I) Optional normal vector. If this parameter is supplied then it must be a valid vector that 
    is perpendicular to the input geCurve, and this vector will become the normal vector of the output pDbCurve.
    If this parameter is not supplied, then this function will compute the normal vector itself.
    tol (I) Optional tolerance
    Returns:
    Returns eOk if successful.
  */
  static OdResult  createFromOdGeCurve ( const OdGeCurve3d& geCurve, OdDbCurve*& pDbCurve,
                                                               OdGeVector3d *normal = NULL,
                                                               const OdGeTol& tol = OdGeContext::gTol );

  /** Description:
    Takes an OdGeCurve3d and sets this OdDbCurve to be geometrically identical to the OdGeCurve3d.
    Arguments:
    geCurve (I) reference to an OdGeCurve3d.
    normal (I) Optional normal vector. If this parameter is supplied then it must be a valid vector that 
    is perpendicular to the input geCurve, and this vector will become the normal vector of the output pDbCurve.
    If this parameter is not supplied, then this function will compute the normal vector itself.
    tol (I) Optional tolerance.
    Returns:
    Returns eOk if successful.
  */
  virtual OdResult  setFromOdGeCurve ( const OdGeCurve3d& geCurve,
                                                            OdGeVector3d *normal = NULL,
                                                            const OdGeTol& tol = OdGeContext::gTol );
};

#define DBCURVE_METHODS \
virtual OdBool isClosed() const; \
virtual OdBool isPeriodic() const; \
virtual OdBool isPlanar() const; \
virtual OdResult getPlane(OdGePlane&, OdDb::Planarity&) const; \
virtual OdResult getStartParam(double&) const; \
virtual OdResult getEndParam(double&) const; \
virtual OdResult getStartPoint(OdGePoint3d&) const; \
virtual OdResult getEndPoint(OdGePoint3d&) const; \
virtual OdResult getPointAtParam(double, OdGePoint3d&) const; \
virtual OdResult getParamAtPoint(const OdGePoint3d&, double&) const; \
virtual OdResult getDistAtParam(double, double&) const; \
virtual OdResult getParamAtDist(double, double&) const; \
virtual OdResult getDistAtPoint(const OdGePoint3d&, double&) const; \
virtual OdResult getPointAtDist(double, OdGePoint3d&) const; \
virtual OdResult getFirstDeriv(double, OdGeVector3d&) const; \
virtual OdResult getFirstDeriv(const OdGePoint3d&,OdGeVector3d&)const;\
virtual OdResult getSecondDeriv(double, OdGeVector3d&) const; \
virtual OdResult getSecondDeriv(const OdGePoint3d&, OdGeVector3d&) const; \
virtual OdResult getClosestPointTo(const OdGePoint3d&, OdGePoint3d&, OdBool = ::kFalse) const; \
virtual OdResult getClosestPointTo(const OdGePoint3d&, const OdGeVector3d&, OdGePoint3d&, OdBool = ::kFalse) const; \
virtual OdResult getOrthoProjectedCurve(const OdGePlane&, OdDbCurve*&) const; \
virtual OdResult getProjectedCurve(const OdGePlane&, const OdGeVector3d&, OdDbCurve*&) const; \
virtual OdResult getOffsetCurves(double, OdDbVoidPtrArray&) const; \
virtual OdResult getSpline(OdDbSpline*&) const; \
virtual OdResult getSplitCurves(const OdGeDoubleArray&, OdDbVoidPtrArray& curveSegments) const; \
virtual OdResult getSplitCurves(const OdGePoint3dArray&, OdDbVoidPtrArray&) const; \
virtual OdResult extend(double); \
virtual OdResult extend(OdBool, const OdGePoint3d&); \
virtual OdResult getArea(double&) const; \
virtual OdResult reverseCurve();

#include "TD_PackPop.h"

#endif

