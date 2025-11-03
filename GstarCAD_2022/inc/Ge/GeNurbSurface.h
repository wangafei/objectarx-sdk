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

#ifndef OD_GENURBSF_H
#define OD_GENURBSF_H /* {Secret} */


#include "../Ge/GeSurface.h"
#include "../Ge/GeKnotVector.h"
#include "../OdPlatformSettings.h"
#include "../TD_PackPush.h"

class OdGeNurbCurve3d;

static const int derivArraySize = 3;
/*
    Description:
    Defines VectorDerivArray type.
*/
typedef OdGeVector3d VectorDerivArray[derivArraySize][derivArraySize];
/*
    Description:
    Defines the WDerivArray type.
*/
typedef double WDerivArray [derivArraySize][derivArraySize];

/**
    Description:
    This class represents non-uniform, rational B-Spline (NURBS) surfaces.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeNurbSurface : public OdGeSurface
{
public:


  /** 
    Arguments:
    degreeInU (I) Degree in the U direction. 
    degreeInV (I) Degree in the V direction.
    propsInU (I) Properties in the U direction.
    propsInV (I) Properties in the V direction.
    numControlPointsInU (I) Number of control points in the U direction.
    numControlPointsInV (I) Number of control points in the V direction.
    controlPoints (I) Array of 3D control points.
    weights (I) Array of *weights*
    uKnots (I) Knot vector in the U direction.
    vKnots (I) Knot vector in the V direction.
    tol (I) Geometric tolerance.
    source (I) Object to be cloned.
   
    Remarks:
    propsInU and propsInV utilize OdGe::NurbSurfaceProperties values.
  */
  OdGeNurbSurface();
  OdGeNurbSurface(
    int degreeInU, 
    int degreeInV, 
    int propsInU, 
    int propsInV,
    int numControlPointsInU, 
    int numControlPointsInV,
    const OdGePoint3dArray& controlPoints,
    const OdGeDoubleArray& weights,
    const OdGeKnotVector& uKnots,
    const OdGeKnotVector& vKnots,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeNurbSurface(
    const OdGeNurbSurface& source);

  OdGeNurbSurface& operator =(
    const OdGeNurbSurface& nurb);

  
  /**
    Description:
    Returns true if and only if this surface is rational in the U direction.

    Arguments:
    tol (I) Geometric tolerance.
  */  
  OdBool isRationalInU () const;

  /**
    Description:
    Returns true if and only if this surface is periodic in the U direction, and returns the *period*.

    Arguments:
    period (I) Period.
  */  
  OdBool isPeriodicInU (double& period) const;

  /**
    Description:
    Returns true if and only if this surface is rational in the V direction.

    Arguments:
    tol (I) Geometric tolerance.
  */  
  OdBool isRationalInV () const;

  /**
    Description:
    Returns true if and only if this surface is periodic in the U direction, and returns the *period*.

    Arguments:
    period (I) Period.
  */  
  OdBool isPeriodicInV (double& period) const;
  
  /**
    Description:
    Returns a description of the singularity in the U direction:
    
    Remarks:
    singularityInU utilizes OdGe::NurbSurfaceProperties values.
  */
   int singularityInU() const;

  /**
    Description:
    Returns a description of the singularity in the V direction:
    
    Remarks:
    singularityInV utilizes OdGe::NurbSurfaceProperties values.
  */
   int singularityInV() const;

  /**
    Desctiption:
    Returns the degree in the U direction.
  */
   int degreeInU() const;

  /**
    Desctiption:
    Returns the number of control points in the U direction.
  */
   int numControlPointsInU() const;
  
  /**
    Desctiption:
    Returns the degree in the V direction.
  */
   int degreeInV() const;
  
  /**
    Desctiption:
    Returns the number of control points in the V direction.
  */
   int numControlPointsInV() const;

  /**
    Description:
    Returns the array of control points.
    
    controlPoints (O) Receives an array of 3D control points.
  */  
   void getControlPoints(
    OdGePoint3dArray& controlPoints) const;
    
  /**
    Description:
    Returns the array of *weights*.
    
    Arguments:
    weights (I) Array of *weights*
  */  
  OdBool getWeights (
    OdGeDoubleArray& weights) const;
  
  /**
    Description:
    Returns the number of knots in the U direction.
  */  
   int numKnotsInU() const;
  
  /**
    Description:
    Returns the knot vector in the U direction.
    
    Arguments:
    uKnots (I) Knot vector in the U direction.
  */
   void getUKnots(
    OdGeKnotVector& uKnots) const;
  
  /**
    Description:
    Returns the number of knots in the V direction.
  */  
   int numKnotsInV() const;
  
  /**
    Description:
    Returns the knot vector in the V direction.
    
    Arguments:
    vKnots (I) Knot vector in the V direction.
  */
   void getVKnots(
    OdGeKnotVector& vKnots) const;
    
  /**
    Description:
    Returns the data used to define this surface.
    
    Arguments:
    degreeInU (O) Receives the Degree in the U direction. 
    degreeInV (O) Receives the Degree in the V direction.
    propsInU (O) Receives the properties in the U direction.
    propsInV (O) Receives the properties in the V direction.
    numControlPointsInU (O) Receives the number of control points in the U direction.
    numControlPointsInV (O) Receives the number of control points in the V direction.
    controlPoints (O) Receives an array of 3D control points.
    weights (O) Receives an array of *weights*
    uKnots (O) Receives the knot vector in the U direction.
    vKnots (O) Receives the knot vector in the V direction.
   
    Remarks:
    propsInU and propsInV utilize OdGe::NurbSurfaceProperties values.
  */  
   void getDefinition(
    int& degreeInU, 
    int& degreeInV,
    int& propsInU, 
    int& propsInV,
    int& numControlPointsInU,
    int& numControlPointsInV,
    OdGePoint3dArray& controlPoints,
    OdGeDoubleArray& weights,
    OdGeKnotVector& uKnots,
    OdGeKnotVector& vKnots) const;

   OdGeNurbSurface& set(
     int degreeInU, 
     int degreeInV,
     int propsInU, 
     int propsInV,
     int numControlPointsInU,
     int numControlPointsInV,
     const OdGePoint3d controlPoints[],
     const double weights[],
     const OdGeKnotVector& uKnots,
     const OdGeKnotVector& vKnots,
     const OdGeTol& tol = OdGeContext::gTol);


  //////////////////////////////////////////////////////////////////////////
  // TD Special :

  // computes isolines
  
  /**
    Description:
    Returns the *isoline* for the specified value of V.
    Not implemented for third-party use only.

    Arguments:
    V (I) Value of V.
    isoline (O) Receives the isoline for the specified value of V. 
  */
  void computeVIsoLine(
    double V, 
    OdGeNurbCurve3d& isoline) const;

  /**
    Description:
    Returns the *isoline* for the specified value of U.
    Not implemented for third-party use only.

    Arguments:
    V (I) Value of U.
    isoline (O) Receives the isoline for the specified value of U. 
  */
   void computeUIsoLine(
    double U, 
    OdGeNurbCurve3d& isoline) const;

     /**
    Description:
    Returns the 2D pair of parameter values of a *point* on this surface.

    Arguments:
    point (I) Point to be evaluated.
    tol (I) Geometric tolerance.

    Remarks:
    The returned parameters specify a point within tol of *point*.
    If point is not on this surface, the results are unpredictable.
    If you are not sure the point is on this surface, use 
    isOn() instead of this function. This method is slower than paramOf, 
    but more accurate.
  */
   OdGePoint2d paramOfPrec(
    const OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;
   

  /**
    Description:
    Returns the *derivatives* at the point specified by param.
	Not implemented for third-party use only.

    Arguments:
    param (I) Parameter to be evaluated.
    numDeriv (I) Number of *derivatives* to be computed.
    derivatives (O) Receives an array of *derivatives* at the *point* corresponding to param.
  */
  OdBool getDerivativesAt (
    const OdGePoint2d& param, 
    OdUInt32 numDeriv,
    VectorDerivArray derivatives) const;

  // the index in "m_controlPoints" of control *point* (i,j):

  /** { Secret } */
   int loc(
    int i, 
    int j) const;

  /** { Secret } */
  /**
  Description:
  Sets the parameters for this spline according to the arguments, 
  and returns a reference to this spline.

  Arguments:
  degreeInU (I) Degree in the U direction. 
  degreeInV (I) Degree in the V direction.
  propsInU (I) Properties in the U direction.
  propsInV (I) Properties in the V direction.
  numControlPointsInU (I) Number of control points in the U direction.
  numControlPointsInV (I) Number of control points in the V direction.
  controlPoints (I) Array of 3D control points.
  weights (I) Array of *weights*
  uKnots (I) Knot vector in the U direction.
  vKnots (I) Knot vector in the V direction.
  tol (I) Geometric tolerance.
  source (I) Object to be cloned.
   
  Remarks:
  propsInU and propsInV utilize OdGe::NurbSurfaceProperties values.
  */
  OdGeNurbSurface& set(
  int degreeInU, 
  int degreeInV,
  int propsInU, 
  int propsInV,
  int numControlPointsInU,
  int numControlPointsInV,
  const OdGePoint3dArray& controlPoints,
  const OdGeDoubleArray& weights,
  const OdGeKnotVector& uKnots,
  const OdGeKnotVector& vKnots,
  const OdGeTol& tol = OdGeContext::gTol);
protected:
  void calculateNURBSProperties();
};

#include "../TD_PackPop.h"

#endif // OD_GENURBSF_H
