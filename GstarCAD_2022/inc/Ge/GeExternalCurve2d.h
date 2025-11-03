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

#ifndef OD_GE_EXTERNAL_CURVE_2D_H
#define OD_GE_EXTERNAL_CURVE_2D_H /* {Secret} */

#include "../Ge/GeCurve2d.h"
#include "../Ge/GeCircArc2d.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GePoint2d.h"
#include "../TD_PackPush.h"

class OdGeNurbCurve2d;

/**
    Description:
    This class represents, as OdGeCurve2d curves, 2D curves whose definitions are external to the OdGe library.
    
    Remarks:
    OdGeExternalCurve2d curve instances can be treated as any other OdCurve2d. 
    
    You can access the OdGeExternalCurve2d as a corresponding native OdGeCurve2d curve, if such a corresponding
    curve exists, or you may (more efficiently) access the external data in its native form.
    
    One example of using OdGeOdGeExternalCurve2d is to represent an ACIS curve. 
    
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeExternalCurve2d : public OdGeCurve2d
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
  OdGeExternalCurve2d();
  OdGeExternalCurve2d(
    const OdGeExternalCurve2d& source);
  OdGeExternalCurve2d(
    void* pCurveDef, 
    OdGe::ExternalEntityKind curveKind,
	OdBool makeCopy = kTrue);

  /**Description:
    Returns true, and an OdGeNurbCurve2d curve,
    if and only if the curve can be represented as an OdGeNurbCurve2d *curve*.

    Arguments:
    nurbCurve (O) Receives an OdGeNurbCurve2d internal representation of the external *curve*.

    Remarks:
    nurbCurve is created with the new method, and must be deleted by the caller.
  */
  OdBool isNurbCurve () const;
  OdBool isNurbCurve (
    OdGeNurbCurve2d& nurbCurve) const;

  /**
    Description:
    Returns true if and only if the curve is defined (not an empty instance).
  */
  OdBool isDefined () const;

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
    Returns information about the system that created the *curve*.

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
    makeCopy (I) If true, makes a *copy* of of the curve definition.
  */
  OdGeExternalCurve2d& set(
    void* pCurveDef, 
    OdGe::ExternalEntityKind curveKind,
	OdBool makeCopy = kTrue);

  /**
    Description:
    Returns true if and only if if the external curve owns the data.

    Remarks:
    If the external curve owns the data, it will be destroyed when
    the curve is destroyed.
  */
  OdBool isOwnerOfCurve () const;

  /**
    Description:
    Forces this external curve to own the data, and returns a pointer to this *curve*.

    Remarks:
    If the external curve owns the data, it will be destroyed when
    the curve is destroyed.
  */
  OdGeExternalCurve2d& setToOwnCurve();

  OdGeExternalCurve2d& operator =(
    const OdGeExternalCurve2d& extCurve);

};

#include "../TD_PackPop.h"

#endif // OD_GE_EXTERNAL_CURVE_2D_H
