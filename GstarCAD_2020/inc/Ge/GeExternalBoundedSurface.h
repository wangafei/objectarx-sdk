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

#ifndef OD_GEXBNDSF_H
#define OD_GEXBNDSF_H /* {Secret} */

class OdGeExternalSurface;
class OdGeCurveBoundary;
#include "../Ge/GeGbl.h"
#include "../Ge/GeSurface.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents bounded surfaces, whose definitions are external to the OdGe library.
    
    Remarks:
    Each instance of ns OdGeExternalBoundedSurface is comprosed of an instance
    of an OdExternalSurface and a collection of instances of AcGeCurveBoundary.
    
    OdGeExternalBoundedSurface instances can be treated as any other OdGeSurface. 
    
    You can access the OdGeExternalBoundedSurface as a corresponding native OdGeSurface, if such a corresponding
    surface exists, or you may (more efficiently) access the external data in its native form.
    
    One example of using OdGeExternalBoundedSurface is to access an ACIS surface. 
   
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeExternalBoundedSurface : public OdGeSurface
{
public:


  /**
    Arguments:
    pSurfaceDef (I) Pointer to the surface definition.
    surfaceKind (I) Information about system that created the surface.
    makeCopy (I) Makes a *copy* of curveDef.
    source (I) Object to be cloned.
    
    Remarks:
    Without arguments, the constructor creates an empty instance.

    Possible values for surfaceKind:
    
    @untitled table
    kAcisEntity
    kExternalEntityUndefined
  */
  OdGeExternalBoundedSurface();
  OdGeExternalBoundedSurface(
    void* pSurfaceDef, 
    OdGe::ExternalEntityKind surfaceKind, 
    OdBool makeCopy = kTrue);
  OdGeExternalBoundedSurface(
    const OdGeExternalBoundedSurface& source);

  // Surface data.
  //

  /**
    Description:
    Rerurns information about the system that created the surface.

    Remarks:
    Possible values for externalSurfaceKind:

    @untitled table
    kAcisEntity
    kExternalEntityUndefined
  */
   OdGe::ExternalEntityKind externalSurfaceKind() const;
  
  /**
    Description:
    Returns true if and only if the surface is defined (not an empty instance).
  */
   OdBool isDefined() const;

  /**
    Description:
    Returns a *copy* of the raw surface definition.

    Arguments:
    curveDef (O) Receives a pointer to a *copy* of the raw surface definition.

    Remarks:
    It is up to the caller to delete the memory allocated.
  */
   void getExternalSurface(
    void*& pSurfaceDef) const;

  // Odcess to unbounded surface.
  //

  /**
    Description:
    Returns the unbounded surface.
    
    Arguments:
    pSurfaceDef (O) Receives a pointer to the unbounded surface definition.
    unboundedSurfaceDef (O) Receives the unbounded surface definition.
    
    Remarks:
    If called with a pointer to OdGeSurface, the OdExternalSurface
    will be converted to a native OdGeSurface, if possible.
  */   
   void getBaseSurface(
    OdGeSurface*& pSurfaceDef) const;
   void getBaseSurface(
    OdGeExternalSurface& unboundedSurfaceDef) const;

  // Type queries on the unbounded base surface.

  /**
    Description:
    Return true if and only if the unbounded base surface can be represented as an OdGePlanarEnt. 
  */
   OdBool isPlane() const;

  /**
    Description:
    Return true if and only if the unbounded base surface can be represented as an OdGeSphere. 
  */
   OdBool isSphere() const;

  /**
    Description:
    Return true if and only if the unbounded base surface can be represented as an OdGeCylinder. 
  */
   OdBool isCylinder() const;

  /**
    Description:
    Return true if and only if the unbounded base surface can be represented as an OdGeCone. 
  */
   OdBool isCone() const;
  
  /**
    Description:
    Return true if and only if the unbounded base surface can be represented as an OdGeTorus. 
  */
   OdBool isTorus() const;
  
  /**
    Description:
    Return true if and only if the unbounded base surface can be represented as an OdGeNurbSurface. 
  */
   OdBool isNurbs() const;

  /**
    Description:
    Return true if and only if the unbounded base surface cannot be represented as an native OdGeSurface. 
  */
   OdBool isExternalSurface() const;

  // Odcess to the boundary data.
  //
  
  /**
    Description:
    Returns the number of *contours* on this surface.  
  */
   int numContours() const;

  /**
    Description:
    Returns an array of the *contours* on this surface.

    Arguments
    numContours (O) Receives the number of *contours* on this surface.
    contours (O) Receives the array of *contours*. 
  */
   void getContours(
    int& numContours, 
    OdGeCurveBoundary*& contours) const;

  // Set methods
  //
  
  /* Description:
    Sets the parameters for this external bound surface according to the arguments, 
    and returns a reference to this external surface.

    Arguments:
    pSurfaceDef (I) Pointer to the surface definition.
    surfaceKind (I) Information about system that created the surface.
    makeCopy (I) If true, makes a *copy* of the surface definition.
  */
   OdGeExternalBoundedSurface& set(
    void* pSurfaceDef,
    OdGe::ExternalEntityKind surfaceKind, 
    OdBool makeCopy = kTrue);

  // Surface ownership.
  //
  
  /**
    Description:
    Returns true if and only if the external surface owns the data.

    Remarks:
    If the external surface owns the data, it will be destroyed when
    the curve is destroyed.
  */
   OdBool isOwnerOfSurface() const;

  /**
    Description:
    Forces this external surface to own the data, and returns a reference to this external surface.

    Remarks:
    If the external surface owns the data, it will be destroyed when
    the external surface is destroyed.
  */
   OdGeExternalBoundedSurface& setToOwnSurface();

  // Assignment operator.
  //
  OdGeExternalBoundedSurface& operator =(
    const OdGeExternalBoundedSurface& extBoundSurf);

};

#include "../TD_PackPop.h"

#endif // OD_GEXBNDSF_H
