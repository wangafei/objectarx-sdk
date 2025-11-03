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

#ifndef OD_GEEXTC3D_H
#define OD_GEEXTC3D_H /* {Secret} */

class OdGeLine3d;
class OdGeLineSeg3d;
class OdGeRay3d;
class OdGeEllipArc3d;
class OdGeNurbCurve3d;

#include "../Ge/GeCurve3d.h"
#include "../Ge/GeCircArc3d.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GePoint3d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents, as OdGeCurve3d curves, 3D curves whose definitions are external to the OdGe library.
    
    Remarks:
    OdGeExternalCurve3d curve instances can be treated as any other OdCurve3d. 
    
    You can access the OdGeExternalCurve3d as a corresponding native OdGeCurve3d curve, if such a corresponding
    curve exists, or you may (more efficiently) access the external data in its native form.
    
    One example of using OdGeOdGeExternalCurve3d is to represent an ACIS curve. 
    
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeExternalCurve3d : public OdGeCurve3d
{
public:


  /**
    Arguments:
    pCurveDef (I) Pointer to the curve definition.
    curveKind (I) Information about system that created the *curve*.
    makeCopy (I) Makes a *copy* of the curve definition.
    source (I) Object to be cloned.

    Remarks:
    Without arguments, the constructor creates an empty instance.

    Possible values for curveKind:

    @untitled table
    kAcisEntity
    kExternalEntityUndefined
  */
  OdGeExternalCurve3d();
  OdGeExternalCurve3d(
    const OdGeExternalCurve3d& source);
  OdGeExternalCurve3d(
    void* pCurveDef, 
    OdGe::ExternalEntityKind curveKind,
	OdBool makeCopy = kTrue);

  /**
    Description:
    Return true if and only if the external curve can be represented as an OdGeLine3d. 
  */
  OdBool isLine () const;

  /**
    Description:
    Return true if and only if the external curve can be represented as an OdGeRay3d. 
  */
  OdBool isRay () const;

  /**
    Description:
    Return true if and only if the external curve can be represented as an OdGeLineSeg3d. 
  */
  OdBool isLineSeg () const;

  /**
    Description:
    Return true if and only if the external curve can be represented as an OdGeCircArc3d. 
  */
  OdBool isCircArc () const;

  /**
    Description:
    Return true if and only if the external curve can be represented as an OdGeEllipArc3d. 
  */
  OdBool isEllipArc () const;

  /**
    Description:
    Return true if and only if the external curve can be represented as an OdGeNurbCurve3d. 
  */
  OdBool isNurbCurve () const;
  
  /**
    Description:
    Returns true if and only if the curve is defined (not an empty instance).
  */
  OdBool isDefined () const;

  /**
    Description:
    Return true if and only if the external curve can be represented as a native OdGeCurve3d,
    and returns a pointer to an instance of that native *curve*.

    Arguments:
    nativeCurve (O) Receives the native *curve*.

    Remarks:
    The returned object is created with the new operator, and it is the responsibility of the caller to delete it.
  */
  OdBool isNativeCurve (
    OdGeCurve3d*& nativeCurve) const;

  /**
    Description:
    Returns a *copy* of the raw curve definition.

    Arguments:
    pCurveDef (O) Receives a pointer to a *copy* of the raw curve definition.

    Remarks:
    It is up to the caller to delete the memory allocated.
  */
   void getExternalCurve(
    void*& pCurveDef) const;

  /**
    Description:
    Rerurns information about the system that created the *curve*.

    Remarks:
    Possible values for curveKind:

    @untitled table
    kAcisEntity
    kExternalEntityUndefined
  */
   OdGe::ExternalEntityKind externalCurveKind() const;

  /* Description:
    Sets the parameters for this external curve according to the arguments, 
    and returns a reference to this external *curve*.

    Arguments:
    pCurveDef (I) Pointer to the curve definition.
    curveKind (I) Information about system that created the *curve*.
    makeCopy (I) If true, makes a *copy* of the curve definition.
  */
   OdGeExternalCurve3d& set(
    void* pCurveDef, 
    OdGe::ExternalEntityKind curveKind,
	OdBool makeCopy = kTrue);

  OdGeExternalCurve3d& operator =(
    const OdGeExternalCurve3d& extCurve);

  /**
    Description:
    Returns true if and only if the external curve owns the data.

    Remarks:
    If the external curve owns the data, it will be destroyed when
    the curve is destroyed.
  */
  OdBool isOwnerOfCurve () const;

  /**
    Description:
    Forces this external curve to own the data, and returns a reference to this *curve*.

    Remarks:
    If the external curve owns the data, it will be destroyed when
    the curve is destroyed.
  */
   OdGeExternalCurve3d& setToOwnCurve();

};

#include "../TD_PackPop.h"

#endif // OD_GEEXTC3D_H

