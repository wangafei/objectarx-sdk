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

#ifndef OD_GESURF_H
#define OD_GESURF_H /* {Secret} */


#include "../Ge/GeEntity3d.h"
#include "../Ge/GeVector3dArray.h"
#include "../Ge/GePoint2d.h"

class OdGePoint2d;
class OdGeCurve3d;
class OdGePointOnCurve3d;
class OdGePointOnSurface;
class OdGePointOnSurfaceData;
class OdGeInterval;

#include "../TD_PackPush.h"

/**
    Description:
    This class is the base class for all OdGe parametric surfaces.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeSurface : public OdGeEntity3d
{
public:


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
    isOn() instead of this function.
  */
   OdGePoint2d paramOf(
    const OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

  TD_USING(OdGeEntity3d::isOn);
  /**
    Arguments:
    ParamPoint (O) Receives the 2D pair of parameter values at the *point*. 
  */
  OdBool isOn ( 
    const OdGePoint3d& point, 
    OdGePoint2d& paramPoint,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *point* on this surface closest to the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
    tol (I) Geometric tolerance.
  */
   OdGePoint3d closestPointTo(
    const OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *point* on this surface closest to the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
    pntOnSurface (O) Receives the closest *point* on surface to specified *point*. 
    tol (I) Geometric tolerance.
  */
   void getClosestPointTo(
    const OdGePoint3d& point, 
    OdGePointOnSurface& pntOnSurface,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the distance to the *point* on this curve closest to the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
    tol (I) Geometric tolerance.
  */
   double distanceTo(
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if the *normal* of this surface has been reversed an odd
    number of times.
  */
   OdBool isNormalReversed() const;

  /**
    Description:
    Reverses the *normal* of this surface and reurns a reference to this surface.
  */
   OdGeSurface& reverseNormal();

  /**
    Description:
    Returns the minimum rectangle in parameter space that contains the parameter
    domain of this surface.

    Arguments:
    intrvlU (O) Receives the u interval.
    intrvlV (O) Receives the v interval.
  */
   void getEnvelope(
    OdGeInterval& intrvlU, 
    OdGeInterval& intrvlV) const;

  /**
    Description:
    Returns true if and only if this surface is closed in the U direction.

    Arguments:
    tol (I) Geometric tolerance.
  */  
  OdBool isClosedInU(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if this surface is closed in the V direction.

    Arguments:
    tol (I) Geometric tolerance.
  */  
  OdBool isClosedInV (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the point corresponding to the parameter pair, as well as the
    *derivatives* and the *normal* at that *point*.

    Arguments:
    param (I) The parameter pair to be evaluated.
    numDeriv (I) The number of *derivatives* to be computed.
    derivatives (O) Receives an array of *derivatives* at the point corresponding to param.
    normal (O) Receives the *normal* at the point corresponding to param.
    
    Remarks:
    Derivatives are ordered as follows: du, dv, dudu, dvdv, dudv
  */
   OdGePoint3d evalPoint(
    const OdGePoint2d& param) const;
   OdGePoint3d evalPoint(
    const OdGePoint2d& param, 
    int numDeriv,
    OdGeVector3dArray& derivatives) const;
   OdGePoint3d evalPoint(
    const OdGePoint2d& param,
    int numDeriv,
    OdGeVector3dArray& derivatives, 
    OdGeVector3d& normal) const;
	OdGeVector3d getNormal(const OdGePoint2d& param)const;
  OdGeSurface& operator=(
    const OdGeSurface& surf);

  //////////////////////////////////////////////////////////////////////////
  // TD Special :

  /**
  Description:
  Returns projP and true,
  if and only if there is a *point* on this surface, projP, where
  a *normal* to this surface passes through the point p.

  Arguments:
  p (I) Any 3D *point*.
  projP (O) Receives the *point* on this surface. 
  */
   OdBool project(
    const OdGePoint3d& p, 
    OdGePoint3d& projP) const;

   /** \details
    Returns true if and only if this surface has reparameterization,
    and returns the swap flag value and u- and v-coefficients.

    \param swapUV [out]  Receives the current uv parameter swap flag value. If returns true, uv parameters were swapped; returns false in the other case.
    \param uCoeffA [out]  Receives the current value of the uCoeffA coefficient.
    \param vCoeffA [out]  Receives the current value of the vCoeffA coefficient.
    \param uCoeffB [out]  Receives the current value of the uCoeffB coefficient.
    \param vCoeffB [out]  Receives the current value of the vCoeffB coefficient.
  */
   bool getReparameterization(
     bool& swapUV,
     double& uCoeffA,
     double& vCoeffA,
     double& uCoeffB,
     double& vCoeffB) const;

   /** \details
    Sets a new swap flag value, and u- and v-coefficients to new values.

    \param swapUV [in]  A new value of the swap flag to be set. Default value is false.
    \param uCoeffA [in]  A new uCoeffA value. Default value is 1.0.
    \param vCoeffA [in]  A new vCoeffA value. Default value is 1.0.
    \param uCoeffB [in]  A new uCoeffB value. Default value is 0.0.
    \param vCoeffB [in]  A new vCoeffB value. Default value is 0.0.
  */
  void setReparameterization(
    bool swapUV = false,
    double uCoeffA = 1.,
    double vCoeffA = 1.,
    double uCoeffB = 0.,
    double vCoeffB = 0.);

  /** \details
    Set the rectangle in parameter space that defines the parameter
    domain of this surface.
    \returns
    Returns true if and only the new parameter domain was successfully set
    for this surface.

    \param realIntrvlU [in] A reference to a new real u interval to be set.
    \param realIntrvlV [in] A reference to a new real v interval to be set.
  */
  bool setEnvelope(
    const OdGeInterval& realIntrvlU,
    const OdGeInterval& realIntrvlV);
protected:
  OdGeSurface();
  OdGeSurface(
    const OdGeSurface& surf);

};

#include "../TD_PackPop.h"

#endif // OD_GESURF_H

