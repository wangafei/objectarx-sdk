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

#ifndef OD_GEOFFSF_H
#define OD_GEOFFSF_H /* {Secret} */

#include "../Ge/GeGbl.h"
#include "../Ge/GeSurface.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GePoint3dArray.h"
#include "../Ge/GeDoubleArray.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents surfaces that are exact offsets of other surfaces.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeOffsetSurface : public OdGeSurface
{
public:


  /**
    Arguments:
    source (I) Object to be cloned.
    baseSurface (I) Any *surface*.
    offsetDistance (I) Offset *distance*.
    makeCopy (I) Makes a *copy* of baseSurface.

    Remarks:
    Without arguments, the constructor sets the base surface pointer to NULL, and the offset distance to 0.0.
  */
  OdGeOffsetSurface();
  OdGeOffsetSurface(
    OdGeSurface* baseSurface,
    double offsetDistance,
    OdBool makeCopy = kTrue);
  OdGeOffsetSurface(
    const OdGeOffsetSurface& source);

  /**
    Description:
    Return true if and only if the offset *surface* can be represented as an OdGePlanarEnt. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isPlane () const;
  
  /**
    Description:
    Return true if and only if the offset *surface* can be represented as an OdGeBoundedPlane. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isBoundedPlane () const;
  
  /**
    Description:
    Return true if and only if the offset *surface* can be represented as an OdGeSphere. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isSphere () const;
  
  /**
    Description:
    Return true if and only if the offset *surface* can be represented as an OdGeCylinder. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isCylinder () const;
  
  /**
    Description:
    Return true if and only if the offset *surface* can be represented as an OdGeCone. 

    Note:
    By default this function throws exception "not Implemented".
  */
   OdBool isCone() const;
  
  /**
    Description:
    Return true if and only if the offset *surface* can be represented as an OdGeTorus. 

    Note:
    By default this function throws exception "not Implemented".
  */
   OdBool isTorus() const;
  
  /**
    Description:
    Creates a *copy* of this *surface* as an OdGeSurface, and returns a pointer to the new *surface*.
    
    Arguments:
    simpleSurface (O) Receives the OdGeSurface. 
  */
   OdBool getSurface(
    OdGeSurface*& simpleSurface) const;

  /**
    Description:
    Returns the base *surface*.
    
    Arguments:
    baseSurface (O) Receives base *surface*.
  */
   void getConstructionSurface(
    OdGeSurface*& baseSurface) const;

  /**
    Description:
    Returns the offset *distance* of this *surface*. 
  */
   double offsetDist() const;

  /**
    Description:
    Sets the parameters for this *surface* according to the arguments.

    Arguments:
    baseSurface (I) Any *surface*.
    offsetDistance (I) Offset *distance*.
    makeCopy (I) Makes a *copy* of baseSurface.
    
    Remarks:
    Returns a reference to this *surface*.
  */
   OdGeOffsetSurface& set(
    OdGeSurface* baseSurface, 
    double offsetDistance,
    OdBool makeCopy = kTrue);

  OdGeOffsetSurface& operator =(
    const OdGeOffsetSurface& surface);

};

#include "../TD_PackPop.h"

#endif // OD_GEOFFSF_H

