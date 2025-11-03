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

#ifndef OD_GELINE3D_H
#define OD_GELINE3D_H /* {Secret} */

class OdGeLine2d;
class OdGeLine3dImpl;
#include "../Ge/GeLinearEnt3d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents infinite lines in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLine3d : public OdGeLinearEnt3d
{
public:


  /**
    Arguments:
    line (I) Any 3D *line*.
    point (I) Any 3D *point*.
    point1 (I) Any 3D *point*.
    point2 (I) Any 3D *point*.
    source (I) Object to be cloned.
    vect (I) Any 3D vector.
    
    Remarks:
    point and vect construct an infinite *line* passing through point with 
    a *direction* of vect. vect cannot have a zero *length*.

    point1 and point2 construct an infinite *line* passing through both points. The 
    points cannnot be coincident.

    If called with no arguments, constructs in infinite *line* coincident with the X-axis.
  */
  OdGeLine3d();
  OdGeLine3d(
    const OdGeLine3d& source);
  OdGeLine3d(
    const OdGePoint3d& point, 
    const OdGeVector3d& vect);
  OdGeLine3d(
    const OdGePoint3d& point1, 
    const OdGePoint3d& point2);

  GE_STATIC_EXPORT static const OdGeLine3d kXAxis; // X-axis *line*.
  GE_STATIC_EXPORT static const OdGeLine3d kYAxis; // Y-axis *line*.
  GE_STATIC_EXPORT static const OdGeLine3d kZAxis; // Z-axis *line*.

  /**
    Description:
    Sets the parameters for this *line* according to the arguments, and returns a reference to this *line*.

    Arguments:
    point (I) Any 3D *point*.
    vect (I) Any 3D vector.
    point1 (I) Any 3D *point*.
    point2 (I) Any 3D *point*.

    Remarks:
    point and vect construct an infinite *line* passing through point with 
    a *direction* of vect. vect cannot have a zero *length*.

    point1 and point2 construct an infinite *line* passing through both points. The 
    points should no be coincident.
  */
   OdGeLine3d& set(
    const OdGePoint3d& point, 
    const OdGeVector3d& vect);
   OdGeLine3d& set(
    const OdGePoint3d& point1, 
    const OdGePoint3d& point2);

  OdGeLine3d& operator =(
    const OdGeLine3d& line);

  OdGeLine3d(OdGeLine3dImpl*);
};

#include "../TD_PackPop.h"

#endif // OD_GELINE3D_H
