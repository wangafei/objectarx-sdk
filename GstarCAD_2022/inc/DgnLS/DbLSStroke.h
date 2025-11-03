/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2014, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2014 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef ODDGNLS_DBLSSTROKE_H
#define ODDGNLS_DBLSSTROKE_H

#include "OdaCommon.h"
#include "DbFiler.h"

#include "TD_PackPush.h"

/** Description:
    Dgn Line Style Stroke.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
struct OdDbLSStroke
{
  enum WidthMode
  {
    kLSNoWidth    = 0, // Stroke haven't width.
    kLSWidthLeft  = 1, // Stroke have width only for left side.
    kLSWidthRight = 2, // Stroke have width only for right side.
    kLSWidthFull  = 3  // Stroke have width only for left and right sides.
  };
  enum CapMode
  {
    kLSCapsClosed   = 0, // Closed stroke caps.
    kLSCapsOpen     = 1, // Open stroke caps.
    kLSCapsExtended = 2, // Extended stroke caps.
    kLSCapsHexagon  = 3, // Hexagonal stroke caps.
    kLSCapsOctagon  = 4, // Octagonal stroke caps.
    kLSCapsDecagon  = 5, // Decagonal stroke caps.
    kLSCapsArc      = 30 // Round stroke caps.
  };

protected:
  bool m_bIsDash; // true - dash; false - gap
  bool m_bBypassCorner;
  bool m_bCanBeScaled; // Variable length
  /* InvertAt boolean flags:
     - Invert at: None: true, true.
     - Invert at: Origin: false, true.
     - Invert at: End: true, false.
     - Invert at: Both: false, false.
     - for non-RSC LineStyles (( Border ), ( Center ) and etc.) them always false.
     - them always false for internal components.
  */
  bool m_bDontInvertAtOrigin;
  bool m_bDontInvertAtEnd;
  double m_fLength;
  double m_fStartWidth;
  double m_fEndWidth;
  WidthMode m_WidthMode;
  CapMode m_CapMode;

public:
  OdDbLSStroke()
    : m_bIsDash(false)
    , m_bBypassCorner(false)
    , m_bCanBeScaled(false)
    , m_bDontInvertAtOrigin(false)
    , m_bDontInvertAtEnd(false)
    , m_fLength(1.0)
    , m_fStartWidth(0.0)
    , m_fEndWidth(0.0)
    , m_WidthMode(kLSNoWidth)
    , m_CapMode(kLSCapsClosed)
  {
  }
  
  /**
    Description:
    Returns true if this stroke is dash.
  */
  bool isDash() const { return m_bIsDash; }
  /**
    Description:
    Returns true if this stroke is gap.
  */
  bool isGap() const { return !m_bIsDash; }
  /**
    Description:
    Sets this stroke as dash.
  */
  void setDash() { m_bIsDash = true; }
  /**
    Description:
    Sets this stroke as gap.
  */
  void setGap() { m_bIsDash = false; }
  /**
    Description:
    Sets *isDash* flag for this stroke.

    Arguments:
    bSet (I) New flag to set.
  */
  void setIsDash(bool bSet) { m_bIsDash = bSet; }

  /**
    Description:
    Returns corners bypass flag.
  */
  bool bypassCorner() const { return m_bBypassCorner; }
  /**
    Description:
    Sets corners bypass flag.

    Arguments:
    bSet (I) New value to set.
  */
  void setBypassCorner(bool bSet) { m_bBypassCorner = bSet; }

  /**
    Description:
    Returns true if variable stroke length is enabled.
  */
  bool canBeScaled() const { return m_bCanBeScaled; }
  /**
    Description:
    Sets variable length flag.

    Arguments:
    bSet (I) New value to set.
  */
  void setCanBeScaled(bool bSet) { m_bCanBeScaled = bSet; }

  /**
    Description:
    Returns true if invert stroke at origin mode is enabled.
  */
  bool invertAtOrigin() const { return !m_bDontInvertAtOrigin; }
  /**
    Description:
    Sets invert stroke at origin mode flag.

    Arguments:
    bSet (I) New value to set.
  */
  void setInvertAtOrigin(bool bSet) { m_bDontInvertAtOrigin = !bSet; }

  /**
    Description:
    Returns true if invert stroke at end mode is enabled.
  */
  bool invertAtEnd() const { return !m_bDontInvertAtEnd; }
  /**
    Description:
    Sets invert stroke at end mode flag.

    Arguments:
    bSet (I) New value to set.
  */
  void setInvertAtEnd(bool bSet) { m_bDontInvertAtEnd = !bSet; }

  /**
    Description:
    Returns stroke length.
  */
  double length() const { return m_fLength; }
  /**
    Description:
    Sets stroke length.

    Arguments:
    fLen (I) New stroke length.
  */
  void setLength(double fLen) { m_fLength = fLen; }

  /**
    Description:
    Returns stroke start width.
  */
  double startWidth() const { return m_fStartWidth; }
  /**
    Description:
    Sets stroke start width.

    Arguments:
    fWidth (I) New stroke start width.
  */
  void setStartWidth(double fWidth) { m_fStartWidth = fWidth; }

  /**
    Description:
    Returns stroke end width.
  */
  double endWidth() const { return m_fEndWidth; }
  /**
    Description:
    Sets stroke end width.

    Arguments:
    fWidth (I) New stroke end width.
  */
  void setEndWidth(double fWidth) { m_fEndWidth = fWidth; }

  /**
    Description:
    Returns stroke width mode.
  */
  WidthMode widthMode() const { return m_WidthMode; }
  /**
    Description:
    Sets stroke width mode.

    Arguments:
    mode (I) New stroke width mode.
  */
  void setWidthMode(WidthMode mode) { m_WidthMode = mode; }

  /**
    Description:
    Returns stroke caps type.
  */
  CapMode capMode() const { return m_CapMode; }
  /**
    Description:
    Sets stroke caps type.

    Arguments:
    mode (I) New stroke caps type.
  */
  void setCapMode(CapMode mode) { m_CapMode = mode; }

private:
  friend class OdDbLSStrokePatternComponentImpl;

  OdResult dwgInFields(OdDbDwgFiler *pFiler);
  void dwgOutFields(OdDbDwgFiler *pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler *pFiler);
  void dxfOutFields(OdDbDxfFiler *pFiler) const;

#ifdef ODA_DIAGNOSTICS
  void trace(OdUInt32 nStroke) const;
#endif
};

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSSTROKE_H
