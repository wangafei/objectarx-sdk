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


#ifndef _DbRevolveOptions_h_Included_
#define _DbRevolveOptions_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"

class OdDbRevolveOptionsImpl;

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRevolveOptions
{
public:
  OdDbRevolveOptions();
  OdDbRevolveOptions(const OdDbRevolveOptions& src);
  ~OdDbRevolveOptions();
  OdDbRevolveOptions& operator =(const OdDbRevolveOptions& src);

  double draftAngle() const;
  void setDraftAngle(double ang);

  double twistAngle() const;
  void setTwistAngle(double ang);

  bool closeToAxis() const;
  void setCloseToAxis(bool val);

  OdResult checkRevolveCurve(
    OdDbEntity* pRevEnt,
    const OdGePoint3d& axisPnt,
    const OdGeVector3d& axisDir,
    bool& closed,
    bool& endPointsOnAxis,
    bool& planar,
    bool displayErrorMessages = false);

private:
  friend class OdDbRevolveOptionsImpl;
  OdDbRevolveOptionsImpl* m_pImpl;
};

#include "TD_PackPop.h"
#endif //_DbRevolveOptions_h_Included_
