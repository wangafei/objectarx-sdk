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




#ifndef __ODGIWORLDGEOMETRY_H__
#define __ODGIWORLDGEOMETRY_H__

#include "../Gi/GiGeometry.h"

#include "../TD_PackPush.h"

/** Description:
    This class defines functions that allow entities to vectorize themselves.
    
    Remarks:
    Vectorization with the methods of this class are viewport independent. 
    For viewport specific vectorization, use subViewportDraw() instead of subWorldDraw().

    An OdGiWorldGeometry object is part of the OdGiWorldDraw argument passed to the subWorldDraw()
    method of an entity.

    Model coordinates are applied to all *geometry* in this class except for setExtents(). 
   
    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiWorldGeometry : public OdGiGeometry 
{ 
public:
  ODRX_DECLARE_MEMBERS(OdGiWorldGeometry);

  /** Description:
      Sets the extents of the current object.  

      Arguments:
      newExtents (I) Array[2] of WCS points.
      
      Remarks:
      Generation of model coordinate *geometry* automatically calculates the extents.
      You may override this calculation with this function.
  */
  virtual void setExtents(
    OdGePoint3d *newExtents) const = 0;

  /** Description:
      Starts segment of OdDbAttributes for block.

      Remarks:
      If this drawable is a block and has OdDbAttributes it must call
      this method exactly once before sending the attributes to 
      draw(). Once this is called the object may draw only attributes
      and no more primitives
      The attributes must be the last objects vectorized.
  */
  virtual void startAttributesSegment() {}
};

#include "../TD_PackPop.h"

#endif

