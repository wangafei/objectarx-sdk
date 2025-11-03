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

#ifndef OD_GEPOS3D_H
#define OD_GEPOS3D_H /* {Secret} */

#include "../Ge/GePointEnt3d.h"
#include "../Ge/GePoint3d.h"
#include "../TD_PackPush.h"

/**
    Description:
    This class represents points (positions) in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePosition3d : public OdGePointEnt3d
{
public:


 /**
    Arguments:
    point (I) Any 3D *point*.
    x (I) The X-coordinate of the *point*.
    y (I) The Y-coordinate of the *point*.
    z (I) The Z-coordinate of the *point*.
    source (I) Object to be cloned.
 */
  OdGePosition3d();
  OdGePosition3d(
    const OdGePoint3d& point);
  OdGePosition3d(
    double x, 
    double y, 
    double z);
  OdGePosition3d(
    const OdGePosition3d& source);

  /**
    Description:
    Sets the coordinates of, and returns a reference
    to, this *point*.

    Arguments:
    point (I) Any 3D *point*.
    x (I) The X-coordinate of the position.
    y (I) The Y-coordinate of the position.
    z (I) The Z-coordinate of the *point*.
  */
   OdGePosition3d& set(
    const OdGePoint3d& point);
   OdGePosition3d& set(
    double x, 
    double y, 
    double z);

  OdGePosition3d& operator =(
    const OdGePosition3d& pos);

  //////////////////////////////////////////////////////////////////////////

};

#include "../TD_PackPop.h"

#endif // OD_GEPOS3D_H

