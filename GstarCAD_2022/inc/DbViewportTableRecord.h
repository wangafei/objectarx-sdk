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




#ifndef _ODDBVIEWPORTTABLERECORD_INCLUDED
#define _ODDBVIEWPORTTABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbAbstractViewTableRecord.h"

class OdGsDCRect;
class OdDbViewportTable;
class OdGeExtents;
class OdGeMatrix3d;

/** Description:
    This class represents tiled viewport records in the OdDbViewportTable in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbViewportTableRecord : public OdDbAbstractViewTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbViewportTableRecord);

  OdDbViewportTableRecord();
  virtual ~OdDbViewportTableRecord();

  typedef OdDbViewportTable TableType;

/** Description:
    Returns the lower left corner of this Viewport (DXF 10).
    
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
  */
  OdGePoint2d lowerLeftCorner() const;

  /** Description:
    Sets the lower-left corner of this Viewport (DXF 10).
    
    Arguments:
    point (I) Lower-left corner.
    
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
  */
  void setLowerLeftCorner(
    const OdGePoint2d& point);

  /** Description:
    Returns the upper right corner of this Viewport (DXF 11).
    
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
  */
  OdGePoint2d upperRightCorner() const;

  /** Description:
    Sets the upper right corner of this Viewport (DXF 11).

    Arguments:
    point (I) Upper-right corner.
    
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
  */
  void setUpperRightCorner(
    const OdGePoint2d& point);

  /** Description:
    Returns true if and only if this Viewport will display
    a plan view whenever the UCS for this Viewport changes.
    (DXF 71, bit 0x08).
  */
  bool ucsFollowMode() const;

  /** Description:
    Controls the display of 
    a plan view in this Viewport whenever the UCS for this Viewport changes.
    (DXF 71, bit 0x08).

    Arguments:
    ucsFollowMode (I) Controls UCSFollowMode.
  */
  void setUcsFollowMode(
    bool ucsFollowMode);

  /** Description:
    Returns the *circle* *zoom* percent for this Viewport (DXF 72).
    Remarks:
    circleSides() returns a number in the range [1..20000].
  */
  OdUInt16 circleSides() const;

  /** Description:
    Sets the *circle* *zoom* percent for this Viewport (DXF 72).
    Arguments:
    circleSides (I) *circle* *zoom* percent [1..20000].
  */
  void setCircleSides(
    OdUInt16 circleSides);

  /** Description:
    Returns true if and only if this Viewport will display a UCS icon (DXF 74, bit 0x01).
  */
  bool iconEnabled() const;

  /** Description:
    Controls the display of a UCS icon by this Viewport (DXF 74, bit 0x01).

    Arguments:
    iconEnabled (I) Controls the display.
  */
  void setIconEnabled(
    bool iconEnabled);

  /** Description:
    Returns true if and only if this Viewport will display a UCS icon at the UCS origin (DXF 74, bit 0x02).
  */
  bool iconAtOrigin() const;

  /** Description:
    Controls the display of a UCS icon at the UCS origin by this Viewport (DXF 74, bit 0x02).
    Arguments:
    atOrigin (I) Controls the display.   
  */
  void setIconAtOrigin(
    bool atOrigin);

  /** Description:
    Returns true if and only if this Viewport will display a grid (DXF 76).
  */
  bool gridEnabled() const;

  /** Description:
    Controls the display of a grid by this Viewport (DXF 76).
    Arguments:
    gridEnabled (I) Controls the display.
  */
  void setGridEnabled(
    bool gridEnabled);

  /** Description:
    Returns the grid increments for this Viewport (DXF 15, 25).
  */
  OdGePoint2d gridIncrements() const;

  /** Description:
    Sets the grid increments for this Viewport (DXF 15, 25).
    Arguments:
    gridIncrements (I) Grid increments.
  */
  void setGridIncrements(
    const OdGePoint2d& gridIncrements);

  /** Description:
    Returns true and only if snap is enabled for this Viewport (DXF 75).
  */
  bool snapEnabled() const;

  /** Description:
    Controls the snap for this Viewport (DXF 75).
    Arguments:
    snapEnabled (I) Controls the snap.
  */
  void setSnapEnabled(
    bool snapEnabled);

  /** Description:
    Returns true and only if isometric snap is enabled for this Viewport (DXF 75).
  */
  bool isometricSnapEnabled() const;

  /** Description:
    Controls the isometric snap for this Viewport (DXF 75).
    Arguments:
    isometricSnapEnabled (I) Controls the isometric snap.
  */
  void setIsometricSnapEnabled(bool isometricSnapEnabled);
  /** Description:
    Returns the snap IsoPair for this Viewport (DXF 78).
    
    Remarks:
    snapPair() returns one of the following:
    
    @table
    Description      Value
    Left isoplane    0
    Top isoplane     1
    Right isoplane   2
  */
  OdInt16 snapPair() const;
  
  
  /** Description:
    Returns the snap IsoPair for this Viewport (DXF 78).
    
    Remarks:
    snapPair must be one of the following:
    
    @table
    Description      Value
    Left isoplane    0
    Top isoplane     1
    Right isoplane   2
  */
  void setSnapPair(
    OdInt16 snapPair);


  /** Description:
    Returns the snap rotation angle for this Viewport (DXF 50).
    Note:
    All angles are expressed in radians.
  */
  double snapAngle() const;
  /** Description:
    Sets the snap rotation angle for this Viewport (DXF 50).
    Arguments:
    snapAngle (I) Snap angle.
    Note:
    All angles are expressed in radians.
  */
  void setSnapAngle(double snapAngle);
  /** Description:
    Returns the snap Base for this Viewport (DXF 13, 23).
    Note:
    All angles are expressed in radians.
  */
  OdGePoint2d snapBase() const;
  /** Description:
    Sets the snap Base for this Viewport (DXF 13, 23).
    Arguments:
    snapBase (I) Snap base.
    Note:
    All angles are expressed in radians.
  */
  void setSnapBase(
    const OdGePoint2d& snapBase);
  /** Description:
    Returns the snap increments for this Viewport (DXF 14, 24).
  */  
  OdGePoint2d snapIncrements() const;
  /** Description:
    Sets the snap increments for this Viewport (DXF 14, 24).
    Arguments:
    snapIncrements (I) Snap increments.
  */  
  void setSnapIncrements(const OdGePoint2d& snapIncrements);

  /** Description:
    Returns true if and only if the UCS saved with this Viewport will become
    active whenever this Viewport is made active (DXF 65).
  */
  bool isUcsSavedWithViewport() const;

  /** Description:
    Controls the UcsPerViewport for this Viewport (DXF 65).
    
    Arguments:
    ucsPerViewport (I) Controls UcsPerViewport.
    Remarks:
    If and only if UcsPerViewport is true, The UCS saved with this Viewport will become
    active whenever this Viewport is made active>
  */
  void setUcsPerViewport( bool ucsPerViewport);

  /** Description:
    Returns true if and only if the fast zooms are enabled for this Viewport (DXF 73).
  */
  bool fastZoomsEnabled() const;
  
  /** Description:
    Controls fast zooms for this Viewport (DXF 73).
    Arguments:
    fastZoomsEnabled (I) Fast zooms enabled.
  */
  void setFastZoomsEnabled(
    bool fastZoomsEnabled);

  // New R21 grid management API

  bool isGridBoundToLimits() const;
  void setGridBoundToLimits(bool enabled);
       
  bool isGridAdaptive() const;
  void setGridAdaptive(bool enabled);
       
  bool isGridSubdivisionRestricted() const;
  void setGridSubdivisionRestricted(bool enabled);
       
  bool isGridFollow() const;
  void setGridFollow(bool enabled);

  OdInt16 gridMajor() const;
  void setGridMajor(OdInt16 value);

  OdResult setBackground(const OdDbObjectId& backgroundId);
  OdDbObjectId previousBackground(OdGiDrawable::DrawableType type = OdGiDrawable::kGeometry) const;
  OdResult setPreviousBackground(OdDbObjectId backgroundId, OdGiDrawable::DrawableType type = OdGiDrawable::kGeometry);
  OdResult setPreviousBackground(OdDbObjectId backgroundId, OdGiDrawable::DrawableType type, bool bForcedSwitch);
  bool previousBackgroundForcedSwitch(void) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  /** Description:
    Returns the OdGsView associated with this Viewpoint.
  */
  OdGsView* gsView() const;
  /** Description:
    Sets the OdGsView associated with this Viewpoint.
    Arguments:
    pGsView (I) Pointer to the GsView.
  */
  void setGsView(OdGsView* pGsView);
  
  /** Description:
      Returns the OdGiDrawable for this Viewport.
  */
  OdGiDrawable* drawable();

  void setGsNode(OdGsNode* pNode);
  
  OdGsNode* gsNode() const;

  OdResult subGetClassID(CLSID* pClsid) const;

  virtual OdResult copyFrom (
    const OdRxObject* pSource);

  /** Description:
      Adjusts the parameters in this Viewport such that the view is zoomed 
      to the extents of the drawing.
  */
  void zoomExtents();

  OdResult subClose();

  OdInt16 number() const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbViewportTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbViewportTableRecord> OdDbViewportTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBVIEWPORTTABLERECORD_INCLUDED

