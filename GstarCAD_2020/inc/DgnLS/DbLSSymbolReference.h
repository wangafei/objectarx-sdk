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

#ifndef ODDGNLS_DBLSSYMBOLREFERENCE_H
#define ODDGNLS_DBLSSYMBOLREFERENCE_H

#include "OdaCommon.h"
#include "DbFiler.h"

#include "TD_PackPush.h"

/** Description:
    Dgn Line Style Symbol Reference.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
struct OdDbLSSymbolReference
{
  enum VertexMask
  {
    kLSAtStroke    = 0,  // No vertex mask.
    kLSAtOrigin    = 4,  // Symbol at element origin.
    kLSAtEnd       = 8,  // Symbol at element end.
    kLSAtVertex    = 16  // Symbol on each element vertex.
  };
  enum Justify
  {
    kLSNoJustify     = 0, // No symbol justification (symbol on stroke)
    kLSJustifyLeft   = 1, // Symbol at left stroke side.
    kLSJustifyRight  = 2, // Symbol at right stroke side.
    kLSJustifyCenter = 3  // Symbol at center of stroke.
  };
  enum RotationType
  {
    kLSRelative    = 0, // Rotation relative to curve direction.
    kLSAbsolute    = 1, // Rotation in absolute coordinates of drawing.
    kLSAdjusted    = 2  // Rotation is adjusted left to right; mirror symbols if line is reversed.
  };

protected:
  bool m_bPartialStrokes; // Partial: Origin: true (projected: false), Projected: true (projected: true), None: false (projected: false)
  bool m_bClipPartial;
  bool m_bAllowStretch;
  bool m_bPartialProjected; // Look for m_bPartialStrokes
  bool m_bSymbolColor; // false - use line color, true - use element color
  bool m_bSymbolWeight; // false - use line lineweight, true - use element lineweight
  Justify m_Justify; // 0 for vertex symbols
  RotationType m_RotationType;
  OdInt16 m_nVertexMask; // 0 for stroke symbols
  double m_fXOffset;
  double m_fYOffset;
  double m_fAngle; // in radians
  OdInt32 m_nStroke; // -1 for vertex symbols
  OdDbHardPointerId m_SymbolComponent;

public:
  OdDbLSSymbolReference()
    : m_bPartialStrokes(true)
    , m_bClipPartial(false)
    , m_bAllowStretch(false)
    , m_bPartialProjected(false)
    , m_bSymbolColor(false)
    , m_bSymbolWeight(false)
    , m_Justify(kLSNoJustify)
    , m_RotationType(kLSRelative)
    , m_nVertexMask((OdInt16)kLSAtStroke)
    , m_fXOffset(0.0)
    , m_fYOffset(0.0)
    , m_fAngle(0.0)
    , m_nStroke(-1)
  {
  }
  
  /**
    Description:
    Returns true if partial strokes mode is enabled.

    Remarks:
    If this mode is disabled: display whole symbol or none.
  */
  bool partialStrokes() const { return m_bPartialStrokes; }
  /**
    Description:
    Sets partial stroke mode.

    Arguments:
    bSet (I) New value to set.
  */
  void setPartialStrokes(bool bSet) { m_bPartialStrokes = bSet; }

  /**
    Description:
    Returns true if symbol clipping on partial strokes enabled.
  */
  bool clipPartial() const { return m_bClipPartial; }
  /**
    Description:
    Enables symbol clipping on partial strokes mode.

    Arguments:
    bSet (I) New value to set.
  */
  void setClipPartial(bool bSet) { m_bClipPartial = bSet; }

  /**
    Description:
    Returns true if symbol can be scaled.
  */
  bool allowStretch() const { return m_bAllowStretch; }
  /**
    Description:
    Enables symbol scalability.

    Arguments:
    bSet (I) New value to set.
  */
  void setAllowStretch(bool bSet) { m_bAllowStretch = bSet; }

  /**
    Description:
    Returns true if project partial origin if it is beyond the end of line mode is enabled.
  */
  bool partialProjected() const { return m_bPartialProjected; }
  /**
    Description:
    Sets project partial origin if it is beyond the end of line mode.

    Arguments:
    bSet (I) New mode to set.
  */
  void setPartialProjected(bool bSet) { m_bPartialProjected = bSet; }

  /**
    Description:
    Returns true if symbol color usage enabled.

    Remarks:
    Elsewhere line color will be used.
  */
  bool useSymbolColor() const { return m_bSymbolColor; }
  /**
    Description:
    Sets symbol color usage mode.

    Arguments:
    bSet (I) New mode to set.
  */
  void setUseSymbolColor(bool bSet) { m_bSymbolColor = bSet; }

  /**
    Description:
    Returns true if symbol lineweight usage enabled.

    Remarks:
    Elsewhere line lineweight will be used.
  */
  bool useSymbolLineweight() const { return m_bSymbolWeight; }
  /**
    Description:
    Sets symbol lineweight usage mode.

    Arguments:
    bSet (I) New mode to set.
  */
  void setUseSymbolLineweight(bool bSet) { m_bSymbolWeight = bSet; }

  /**
    Description:
    Returns symbol justification on stroke.
  */
  Justify justify() const { return m_Justify; }
  /**
    Description:
    Sets symbol justification on stroke.

    Arguments:
    nSet (I) New justification value to set.
  */
  void setJustify(Justify nSet) { m_Justify = nSet; }

  /**
    Description:
    Returns symbol rotation mode.
  */
  RotationType rotationType() const { return m_RotationType; }
  /**
    Description:
    Sets symbol rotation mode.

    Arguments:
    nSet (I) New rotation mode to set.
  */
  void setRotationType(RotationType nSet) { m_RotationType = nSet; }

  /**
    Description:
    Returns vertex type for this symbol.
  */
  OdUInt32 vertexMask() const { return (OdUInt32)m_nVertexMask; }
  /**
    Description:
    Sets vertex type for this symbol.

    Arguments:
    nVertexMask (I) Vertex type to set.
    Remarks:
    Must be set to 0 if symbol is associated with stroke.
  */
  void setVertexMask(OdUInt32 nVertexMask) { m_nVertexMask = (OdInt16)nVertexMask; }

  /**
    Description:
    Returns symbol offset in X direction.
  */
  double xOffset() const { return m_fXOffset; }
  /**
    Description:
    Sets symbol offset in X direction.

    Arguments:
    fOffset (I) New offset to set.
  */
  void setXOffset(double fOffset) { m_fXOffset = fOffset; }

  /**
    Description:
    Returns symbol offset in Y direction.
  */
  double yOffset() const { return m_fYOffset; }
  /**
    Description:
    Sets symbol offset in Y direction.

    Arguments:
    fOffset (I) New offset to set.
  */
  void setYOffset(double fOffset) { m_fYOffset = fOffset; }

  /**
    Description:
    Returns symbol rotation angle.
  */
  double angle() const { return m_fAngle; }
  /**
    Description:
    Sets symbol rotation angle.

    Arguments:
    fAngle (I) Rotation angle in radians.
  */
  void setAngle(double fAngle) { m_fAngle = fAngle; }

  /**
    Description:
    Returns stroke index with which this symbol is associated.
  */
  OdInt32 strokeNumber() const { return m_nStroke; }
  /**
    Description:
    Associate symbol with stroke.

    Arguments:
    nStroke (I) Stroke index.
    Remarks:
    Must be set to -1 if symbol is configured for vertex symbol usage.
  */
  void setStrokeNumber(OdInt32 nStroke) { m_nStroke = nStroke; }

  /**
    Description:
    Returns symbol component identifier with which this symbol reference is associated.
  */
  OdDbObjectId symbolComponent() const { return m_SymbolComponent; }
  /**
    Description:
    Sets symbol component identifier with which this symbol reference will be associated.

    Arguments:
    id (I) Symbol component identifier.
  */
  void setSymbolComponent(const OdDbObjectId &id) { m_SymbolComponent = id; }

private:
  friend class OdDbLSPointComponentImpl;

  OdResult dwgInFields(OdDbDwgFiler *pFiler);
  void dwgOutFields(OdDbDwgFiler *pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler *pFiler);
  void dxfOutFields(OdDbDxfFiler *pFiler) const;

#ifdef ODA_DIAGNOSTICS
  void trace(OdUInt32 nSymbol) const;
#endif
};

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSSYMBOLREFERENCE_H
