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


#ifndef OD_GETOL_H
#define OD_GETOL_H /* {Secret} */


#include "../Ge/GeExport.h"
#include "../Ge/GeDoubleArray.h"

#include "../TD_PackPush.h"

/**
    Description:
    
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeTol
{
public:
  OdGeTol(double t = 1.e-10) : m_pointTol(t), m_vectorTol(t),m_pointTol2(t*t), m_vectorTol2(t*t)  {}
  OdGeTol(double t1, double t2) : m_pointTol(t1) , m_vectorTol(t2) ,m_pointTol2(t1*t1) , m_vectorTol2(t2*t2){}

  double equalPoint() const { return m_pointTol; }
  double equalVector() const { return m_vectorTol;}
  double equalPoint2() const { return m_pointTol2; }
  double equalVector2() const { return m_vectorTol2;}

  void setEqualPoint(double val) { m_pointTol = val; m_pointTol2 = val*val;}
  void setEqualVector(double val) { m_vectorTol = val; m_vectorTol2 = val*val;}

private:
  double m_vectorTol;
  double m_pointTol;
  double m_vectorTol2;
  double m_pointTol2;
};

#include "../TD_PackPop.h"

#endif

