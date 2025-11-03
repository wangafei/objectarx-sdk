/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////




#ifndef ODDB_DBSPLINE_H
#define ODDB_DBSPLINE_H

#include "TD_PackPush.h"

#include "DbCurve.h"

class OdGeKnotVector;

static const unsigned int kPlineVerticesThrehold = 10000;

enum SplineType {kFitPoints = 0, kControlPoints = 1};

/** Description:
    This class represents Spline entities in an OdDbDatabase instance.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbSpline : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSpline);

  OdDbSpline();
  
  virtual ~OdDbSpline();
  
  OdDbSpline(const OdGePoint3dArray& points,
			 int                     order = 4, 
			 double                  fitTolerance = 0.0);
  OdDbSpline(const OdGePoint3dArray& points,
			 const OdGeVector3d&     startTangent,
			 const OdGeVector3d&     endTangent,
			 int                     order = 4, 
			 double                  fitTolerance = 0.0);
  OdDbSpline(int                     degree, 
			 OdBool					 rational, 
			 OdBool					 closed, 
			 OdBool					 periodic,
			 const OdGePoint3dArray& controlPoints, 
			 const OdGeDoubleArray&  knots, 
			 const OdGeDoubleArray&  weights,
			 double                  controlPtTol = 0.0, 
			 double                  knotTol = 0.0);
  OdDbSpline(const OdGePoint3d&  center,
			 const OdGeVector3d& unitNormal,
			 const OdGeVector3d& majorAxis,
			 double              radiusRatio,
			 double              startAngle = 0.0,
			 double              endAngle = 6.28318530717958647692);

  /** Description:
     Returns true if and only if this Spline entity is *rational* (DXF 70, bit 0x04).
  */
  OdBool isRational() const;
  
  /** Description:
    Returns the *degree* of this Spline entity (DXF 71).
    Remarks:
    degree is in the range [1..25].  
  */
  int degree() const;
  
  /** Description:
      Increased the degree of this spline to the specified value.
  */
  OdResult elevateDegree(int newDegree);
    
  /** Description:
    Returns the number of control *points* in this Spline entity (DXF 73).
  */
  int numControlPoints() const;
  
  /** Description:
    Returns the specified control *point* of this Spline entity (DXF 10).

    Arguments:
    controlPointIndex (I) Control *point* *index*.
    point (O) Receives the control *point*.
  */
  OdResult getControlPointAt(
    int controlPointIndex, 
    OdGePoint3d& point) const;
  
  /** Description:
      Sets the specified control *point* of this Spline entity (DXF 10).

      Arguments:
      controlPointIndex (I) Control *point* *index*.
      point (I) Control *point*.
  */
  OdResult setControlPointAt(
    int controlPointIndex, 
    const OdGePoint3d& point);
  
  /** Description:
    Returns the number of fit points in this Spline entity (DXF 74).
  */
  int numFitPoints() const;
  
  /** Description:
    Returns the specified fit *point* of this Spline entity (DXF 11).

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (O) Receives the fit *point*.
  */
  OdResult getFitPointAt(
    int fitPointIndex, 
    OdGePoint3d& point) const;
  
  /** Description:
    Sets the specfied fit *point* of this Spline entity (DXF 11).

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (I) Fit *point*.
  */
  OdResult setFitPointAt(
    int fitPointIndex, 
    const OdGePoint3d& point);
  
  /** Description:
    Inserts a fit *point* into this Spline entity after the specified *index*.
      
    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (O) Receives the fit *point*.
    
    Remarks:
    If fitPointIndex < 0, point is inserted at before the first fit *point*. 
    
    If fitPointIndex >= numFitPoints(), point is appended to the spline. 
  */
  OdResult insertFitPointAt(
    int fitPointIndex, 
    const OdGePoint3d& point);
  
  /** Description:
    Removes the specified fit *point* from this Spline entity.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
  */
  OdResult removeFitPointAt(
    int fitPointIndex);
  
  /** Description:
    Returns the curve fitting tolerance for this Spline entity (DXF 44).
    
    Remarks:
    This is the maximum drawing unit distance by which the Spline curve can deviate
    from a fit *points*. 
  */
  double fitTolerance() const;
  
  /** Description:
    Sets the curve fitting tolerance for this Spline entity (DXF 44).
    
    Remarks:
    This is the maximum drawing unit distance by which the Spline curve can deviate
    from a fit *points*. 
    
    Arguments:
    fitTolerance (I) Geometric tolerance.
  */
  OdResult setFitTol(
    double fitTolerance);
  
  /** Description:
    Returns the start point and end point WCS fit tangents for this Spline entity (DXF 12, 13).
    Arguments:
    startTangent (O) Receives the start point tangent.
    endTangent (O) Receives the end point tangent.
  */
  OdResult getFitTangents(
    OdGeVector3d& startTangent, 
    OdGeVector3d& endTangent) const;
  
  /** Description:
    Sets the start point and end point WCS fit tangents for this Spline entity (DXF 12, 13).
    Arguments:
    startTangent (O) Start point tangent.
    endTangent (O) End point tangent.
  */
  OdResult setFitTangents(
    const OdGeVector3d& startTangent, 
    const OdGeVector3d& endTangent);
  
  /** Description:
    Returns true if and only if this Spline entity is constructed using fit points.
  */
  OdBool hasFitData() const;
  
  /** Description:
    Returns the fit data for this Spline entity.

    Arguments:
    fitPoints (O) Receives the fit points.
    degree (O) Receives the *degree*.
    fitTolerance (O) Receives the fit tolerance.
    tangentsExist (O) Receives true if and only if start and end tangents are used.
    startTangent (O) Receives the start point tangent.
    endTangent (O) Receives the end point tangent.
  */
  OdResult getFitData(
    OdGePoint3dArray& fitPoints, 
    int& degree, 
    double& fitTolerance, 
    OdBool& tangentsExist, 
    OdGeVector3d& startTangent, 
    OdGeVector3d& endTangent ) const;
  
  /** Description:
    Sets the fit data for this Spline entity.
    Arguments:
    fitPoints (I) Fit points.
    degree (I) Degree.
    fitTolerance (I) Fit tolerance.
    startTangent (I) Start point tangent.
    endTangent (I) End point tangent.
  */
  OdResult setFitData(
    const OdGePoint3dArray& fitPoints, 
    int degree, 
    double fitTolerance, 
    const OdGeVector3d& startTangent, 
    const OdGeVector3d& endTangent );
  
  OdResult getFitData(OdGePoint3dArray&  fitPoints, 
    OdBool&    tangentsExist,
    OdGeVector3d&      startTangent,
    OdGeVector3d&      endTangent,
    OdGe::KnotParameterization&  knotParam,
    int&               degree, 
    double&            fitTolerance) const;

  OdResult setFitData(const OdGePoint3dArray&  fitPoints, 
    const OdGeVector3d&   startTangent, 
    const OdGeVector3d&   endTangent,
    OdGe::KnotParameterization  knotParam,
    int                   degree = 3, 
    double                fitTolerance = 0.0); 

  OdResult setFitData(const OdGePoint3dArray&  fitPoints, 
    bool                     isPeriodic,
    OdGe::KnotParameterization  knotParam,
    int                   degree = 3, 
    double                fitTolerance = 0.0); 

  /** Description:
    Purges the fit data for this Spline entity.
  */
  OdResult purgeFitData();
  
  /** Description:
      TBC.
      void updateFitData();
  */
  OdResult updateFitData();
  
  /** Description:
    Returns the NURBS data for this Spline entity.
    Arguments:
    degree (O) Receives the *degree*.
    rational (O) Receives true if and only if this Spline entity is *rational*.
    closed (O) Receives true if and only if this Spline entity is *closed*.
    periodic (O) Receives true if and only if this Spline entity is *periodic*.
    controlPoints (O) Receives an array of WCS control points.
    knots (O) Receives the knot vector.
    weights (O) Receives an array of *weights*.
    controlPtTol (O) Receives the control point tolerance.
    knotTol (O) Receives the knot tolerance.
  */
  OdResult getNurbsData(
    int& degree, 
    OdBool& rational, 
    OdBool& closed, 
    OdBool& periodic,
    OdGePoint3dArray& controlPoints, 
    OdGeDoubleArray& knots, 
    OdGeDoubleArray& weights, 
    double& controlPtTol,
    double& knotTol) const;

  OdResult getNurbsData(
    int& degree, 
    OdBool& rational, 
    OdBool& closed, 
    OdBool& periodic,
    OdGePoint3dArray& controlPoints, 
    OdGeKnotVector& knots, 
    OdGeDoubleArray& weights, 
    double& controlPtTol) const;
  
  /** Description:
    Sets the NURBS data for this Spline entity.
    Arguments:
    degree (I) Degree.
    rational (I) Controls if this Spline entity is *rational*.
    closed (I) Controls if this Spline entity *closed*.
    periodic (I) Controls if this Spline entity is *periodic*.
    controlPoints (I) Array of WCS control points.
    knots (I) Knot vector.
    weights (I) Array of *weights*.
    controlPtTol (I) Control point tolerance.
    knotTol (I) Knot tolerance.
    
    Remarks:
    o degree is in the range of [1..25]
    o If rational is true, controlPoints.length() must equal weights.length()
    o If periodic is false, then knots.length() must equal controlPoints.length() + degree + 1
    o If periodic is true, then knots.length() must equal controlPoints.length(), 
      the first and last controlPoints must be equal, and the first and last *weights* (if provided) must be equal.
    o If two control points are within controlPtTol, they are treated as the same control point.
    o If two *knots* are within knotTol, they are treated as the same knot.
  */
  OdResult setNurbsData(int degree, 
    OdBool rational, 
    OdBool closed, 
    OdBool periodic,
    const OdGePoint3dArray& controlPoints, 
    const OdGeDoubleArray& knots, 
    const OdGeDoubleArray& weights,
    double controlPtTol, 
    double knotTol );
  
  OdResult setNurbsData(
    int degree, 
    OdBool rational, 
    OdBool closed, 
    OdBool periodic,
    const OdGePoint3dArray& controlPoints, 
    const OdGeKnotVector& knots, 
    const OdGeDoubleArray& weights,
    double controlPtTol);
  
  /** Description:
    Returns the specified *weight* (DXF 41).
    Arguments:
    weightIndex (I) Weight *index*.
  */
  double weightAt(
    int weightIndex) const;
  
  /** Description:
    Sets the specified *weight* (DXF 41).
    Arguments:
    weightIndex (I) Weight *index*.
    weight (I) Weight.
  */
  OdResult setWeightAt(
    int weightIndex, 
    double weight);
  
  /** Description:
      Inserts a knot value into this spline.
  */
  OdResult insertKnot(double param);

  OdResult getOffsetCurvesGivenPlaneNormal(
    const OdGeVector3d& normal,
    double offsetDist,
    OdDbVoidPtrArray& offsetCurves) const;

  /** Description:
     Reverses this Spline entity.
     
     Remarks:
     The start point becomes the end point, and vice versa.
  */
  OdResult reverseCurve();
  
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  
  /*
     void getOffsetCurvesGivenPlaneNormal(const OdGeVector3d& normal,  //Replace OdRxObjectPtrArray
                                          double offsetDist, 
                                          OdRxObjectPtrArray& offsetCurves ) const;
  */
    
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdBool isPlanar() const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;


  /** Description:
      OdDbCurve methods
  */

  virtual OdResult getPointAtParam(
    double param, 
    OdGePoint3d& pointOnCurve) const;

  virtual OdResult getParamAtPoint(
    const OdGePoint3d& pointOnCurve, 
    double& param) const;

  virtual OdResult getStartParam(
    double& startParam) const;

  virtual OdResult getEndParam (
    double& endParam) const;

  virtual OdResult getStartPoint(
    OdGePoint3d& startPoint) const;

  virtual OdResult getEndPoint(
    OdGePoint3d& endPoint) const;

  virtual OdResult getDistAtParam( double param, double& dist ) const;

  virtual OdResult getParamAtDist( double dist, double& param ) const;

  virtual OdResult getFirstDeriv (
    double param,
    OdGeVector3d& firstDeriv) const;

  virtual OdResult getSecondDeriv (
    double param,
    OdGeVector3d& secondDeriv) const;

  virtual OdResult getArea(
    double& area) const;

  virtual OdBool isPeriodic() const;

  TD_USING(OdDbCurve::getFirstDeriv);
  TD_USING(OdDbCurve::getSecondDeriv);

  /**
    Description:
    Returns pointers to the curves that result from splitting this *curve* at the points corresponding 
    to params.

    Arguments:
    params (I) The parameter values corresponding to the split points.
    entitySet (O) Receives an array of pointers to the split curves.
    
    Remarks:
    o The first split curve will be from the start of this *curve* to params[0].
    o The second split curve will be from params[0] to params[1].
    o The last split curve will be from params[n-1] to the end of his *curve*.
  */      
  virtual OdResult getSplitCurves(
    const OdGeDoubleArray& params, 
    OdDbVoidPtrArray& entitySet) const;

  TD_USING(OdDbCurve::getSplitCurves);
  
  virtual OdResult decomposeForSave(
	OdDb::DwgVersion ver,
	OdDbObject*& replaceObj,
	OdDbObjectId& replaceId,
	OdBool& exchangeXData);

  /**
    Description:
    Returns the spline method (either by fit points or by control points).
  */  
  SplineType type() const;

  /**
    Description:
    Sets the spline method (either by fit points or by control points).

    Arguments:
    type (I) spline type to be set.

    Note:
    Returns the result of the operation: eOk if successful, or an appropriate error code if not.

    Remarks:
    Changing type from kControlPoints to kFitPoints recalculates fit points from control points.
  */ 

  OdResult setType(SplineType type);

  /**
    Description:
    Returns true if Control Vertices frame is visible.
  */      
  bool cvFrame() const;

  /**
    Description:
    Sets visibility of Control Vertices frame for this Spline entity.
    Arguments:
    bVisible (I) Control vertices frame visiblity.
  */      
  void setCvFrame(bool bVisible);

   /**
    Description:
    Inserts a control point at the specified knot.
    
    Arguments:
    knotParam (I) The knot parameter to add the control point at.
    ctrlPt (I) Coordinates of the control point to be added.
    weight(I) The weight to be assigned to the control point.
    
    Remarks:
    When called for a non-rational spline, weight is ignored.
	
	  Note:
    eOk if successful, or an appropriate error code if not.
  */
  OdResult insertControlPointAt(double knotParam, const OdGePoint3d& ctrlPt, double weight = 1.0);

  /**
    Description:
    Deletes a control point at the specified index.
    
    Arguments:
    index (I) The index of the control point to be deleted.
	
	  Note:
    eOk if successful, or an appropriate error code if not.
   */
  OdResult removeControlPointAt(int index);

/**
    Description:
    Returns true if the spline doesn't contain control points.
  */ 
  OdBool isNull() const;

  /**
    Description:
    Modifies the position and tangent of the point with a specified parameter.

    Arguments:
    param (I) Parameter value of the point.
    point (I) New position of the point.
    deriv (I) New value of the tangent vector at the point.
           
    Note:
    Returns true if and only if the point has successfully been adjusted.
  */
  OdBool modifyPositionAndTangent(double param, const OdGePoint3d& point, const OdGeVector3d* deriv);


  OdResult toPolyline(OdDbCurve*& pCurve, int precision = 10,
    int* maxSuggestedPrecision = NULL,
    unsigned int numOfVerticesThreshold = kPlineVerticesThrehold) const;

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const; 
  
  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSpline object pointers.
*/
typedef OdSmartPtr<OdDbSpline> OdDbSplinePtr;

#include "TD_PackPop.h"

#endif

