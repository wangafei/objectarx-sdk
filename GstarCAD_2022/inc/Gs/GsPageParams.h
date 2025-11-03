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




#ifndef _GSPAGEPARAMS_INCLUDED_
#define _GSPAGEPARAMS_INCLUDED_ /** { Secret } *// 

/** Description:
  This class stores printing page size and margins.

  Remarks:
  All values are in millimeters.

  Library:
  TD_Gs

  {group:OdGs_Classes} 
*/
class OdGsPageParams
{
  double m_dPaperWidth;  // All are in mm.
  double m_dPaperHeight;
  
  double m_dLeftMargin;
  double m_dRightMargin;
  double m_dTopMargin;
  double m_dBottomMargin;
public:
  OdGsPageParams()
    : m_dPaperWidth(210.)
    , m_dPaperHeight(297.)
    , m_dLeftMargin(0.)
    , m_dRightMargin(0.)
    , m_dTopMargin(0.)
    , m_dBottomMargin(0.)
  {
  }

  ~OdGsPageParams()
  {
  }

  OdGsPageParams(const OdGsPageParams& data)
  {
    *this = data;
  }

  OdGsPageParams& operator=(const OdGsPageParams& from)
  {
   m_dPaperWidth   = from.m_dPaperWidth;  // All are in mm.
   m_dPaperHeight  = from.m_dPaperHeight;
   m_dLeftMargin   = from.m_dLeftMargin;
   m_dRightMargin  = from.m_dRightMargin;
   m_dTopMargin    = from.m_dTopMargin;
   m_dBottomMargin = from.m_dBottomMargin;
   return *this;
  }

  double getPaperWidth() const   { return m_dPaperWidth;   }
  double getPaperHeight() const  { return m_dPaperHeight;  }
  double getLeftMargin() const   { return m_dLeftMargin;   }
  double getRightMargin() const  { return m_dRightMargin;  }
  double getTopMargin() const    { return m_dTopMargin;    }
  double getBottomMargin() const { return m_dBottomMargin; }

  void set(
    double dPaperWidth,
    double dPaperHeight,
    double dLeftMargin = 0.,
    double dRightMargin = 0.,
    double dTopMargin = 0.,
    double dBottomMargin = 0.
    )
  {
    const double dTol = OdGeContext::gZeroTol.equalPoint();
    if (dPaperWidth <= dTol || dPaperHeight <= dTol || dLeftMargin < 0. || dRightMargin < 0. || dTopMargin < 0. || dBottomMargin < 0.)
    {
      ODA_FAIL_ONCE();
      return;
    }

    if (dLeftMargin + dRightMargin >= dPaperWidth - dTol)
    {
      ODA_FAIL_ONCE();
      return;
    }

    if (dTopMargin + dBottomMargin >= dPaperHeight - dTol)
    {
      ODA_FAIL_ONCE();
      return;
    }

    m_dPaperWidth = dPaperWidth;
    m_dPaperHeight = dPaperHeight;
    m_dLeftMargin = dLeftMargin;
    m_dRightMargin = dRightMargin;
    m_dTopMargin = dTopMargin;
    m_dBottomMargin = dBottomMargin;
  }

  void scale(double dScale)
  {
    if (dScale > 1e-8)
    {
      m_dPaperWidth *= dScale;
      m_dPaperHeight *= dScale;
      m_dLeftMargin *= dScale;
      m_dRightMargin *= dScale;
      m_dTopMargin *= dScale;
      m_dBottomMargin *= dScale;
    }
  }
};

#endif //_GSPAGEPARAMS_INCLUDED_
