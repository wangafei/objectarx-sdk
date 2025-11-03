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

#ifndef OD_GEEXTSF_H
#define OD_GEEXTSF_H /* {Secret} */

#include "../Ge/GeGbl.h"
#include "../Ge/GeSurface.h"

#include "../TD_PackPush.h"

class OdGePlane;
class OdGeCylinder;
class OdGeCone;
class OdGeSphere;
class OdGeTorus;
class OdGeNurbSurface;
class OdGeEllipCone;            // AE 03.09.2003 
class OdGeEllipCylinder;    // AE 09.09.2003    

/**
    Description:
    This class represents unbounded surfaces, whose definitions are external to the OdGe library, as OdGeSurface.
    
    Remarks:
    OdGeExternalSurface instances can be treated as any other OdGeSurface. 
    
    You can access the OdGeExternalSurface as a corresponding native OdGeSurface, if such a corresponding
    surface exists, or you may (more efficiently) access the external data in its native form.
    
    One example of using OdGeExternalSurface is to access an ACIS surface. 
    
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeExternalSurface : public OdGeSurface
{
public:


  /**
    Arguments:
    pSurfaceDef (I) Pointer to the surface definition.
    surfaceKind (I) Information about system that created the surface.
    makeCopy (I) Makes a *copy* of the surface definition.
    source (I) Object to be cloned.
    
    Remarks:
    Without arguments, the constructor creates an empty instance.

    Possible values for surfaceKind:
    
    @untitled table
    kAcisEntity
    kExternalEntityUndefined
  */
  OdGeExternalSurface();
  OdGeExternalSurface(
    void* pSurfaceDef, 
    OdGe::ExternalEntityKind surfaceKind,
	OdBool makeCopy = kTrue);
  OdGeExternalSurface(
    const OdGeExternalSurface& source);

  /**
    Description:
    Returns a *copy* of the raw surface definition.

    Arguments:
    pSurfaceDef (O) Receives a pointer to a *copy* of the raw surface definition.

    Remarks:
    It is up to the caller to delete the memory allocated.
  */
   void getExternalSurface(
    void*& pSurfaceDef) const;

  // Type of the external surface.
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
    Return true if and only if the surface can be represented as an OdGePlanarEnt. 
  */
   OdBool isPlane() const;

  /**
    Description:
    Return true if and only if the external surface can be represented as an OdGeSphere. 
  */
   OdBool isSphere() const;

  /**
    Description:
    Return true if and only if the external surface can be represented as an OdGeCylinder. 
  */
   OdBool isCylinder() const;

  /**
    Description:
    Return true if and only if the external surface can be represented as an OdGeCone. 
  */
   OdBool isCone() const;

  /**
    Description:
    Return true if and only if the external surface can be represented as an OdGeTorus. 
  */
   OdBool isTorus() const;
  
  /**
    Description:
    Return true if and only if the external surface can be represented as an OdGeNurbSurface. 
  */
   OdBool isNurbSurface() const;

  /**
    Description:
    Returns true if and only if the surface is defined (not an empty instance).
  */
   OdBool isDefined() const;

  /**
    Description:
    Return true if and only if the external surface can be represented as a native OdGeSurface,
    and returns a pointer to an instance of that native surface.

    Arguments:
    nativeSurface (O) Receives the native surface.

    Remarks:
    The returned object is created with the new operator, and it is the responsibility of the caller to delete it.
  */
   OdBool isNativeSurface(
    OdGeSurface*& nativeSurface) const;

  // Assignment operator.
  //

  OdGeExternalSurface& operator =(
    const OdGeExternalSurface& extSurf);

  // Reset surface
  //

  /* Description:
    Sets the parameters for this external surface according to the arguments, 
    and returns a reference to this external surface.

    Arguments:
    pSurfaceDef (I) Pointer to the surface definition.
    surfaceKind (I) Information about system that created the surface.
    makeCopy (I) If true, makes a *copy* of the surface definition.
  */
   OdGeExternalSurface& set(
    void* pSurfaceDef,
    OdGe::ExternalEntityKind surfaceKind,
	OdBool makeCopy = kTrue);

  /**
    Description:
    Returns true if and only if the external surface owns the data.

    Remarks:
    If the external surface owns the data, it will be destroyed when
    the surface is destroyed.
  */
  OdBool isOwnerOfSurface () const;
  
  /**
    Description:
    Forces this external surface to own the data, and returns a reference to this external surface.

    Remarks:
    If the external surface owns the data, it will be destroyed when
    the external surface is destroyed.
  */
   OdGeExternalSurface& setToOwnSurface();

  //////////////////////////////////////////////////////////////////////////
};

#include "../TD_PackPop.h"

#endif // OD_GEEXTSF_H

