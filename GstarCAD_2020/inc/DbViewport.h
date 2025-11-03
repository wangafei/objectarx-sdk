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




#ifndef _OD_DB_VIEWPORT_
#define _OD_DB_VIEWPORT_

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DbSymbolTable.h"
#include "ViewportDefs.h"

#include "Gi/GiViewportTraits.h"

#include "DbAbstractViewTableRecord.h"
#include "XRefMan.h"

class OdGeExtents3d;
class OdGeMatrix3d;
class OdGsView;
class OdDbSun;

/** Description:
    This class represents PaperSpace Viewport entities in an OdDbDatabase instance.
  
    Library:
    TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbViewport : public OdDbEntity
{
protected:
  /* void dxfOutXData(OdDbDxfFiler* pFiler) const;
  */
public:
  ODDB_DECLARE_MEMBERS(OdDbViewport);

  OdDbViewport();
  ~OdDbViewport();
  
  /** Description:
    Returns the *height* of this Viewport object (DXF 41).

    Note: 
    If this Viewport object is an overall viewport,
    the values returned by width() and height() must be divided by a
    factor of 1.058, and the parameters of setWidth and setHeight() 
    must be multiplied by a like factor.                        
  */
  double height() const;

  /** Description:
    Sets the *height* of this Viewport object (DXF 41).
    Arguments:
    height (I) Height.

    Note: 
    If this Viewport object is an overall viewport,
    the values returned by width() and height() must be divided by a
    factor of 1.058, and the parameters of setWidth and setHeight() 
    must be multiplied by a like factor.                        
  */
  OdResult setHeight(
    double height);

  /** Description:
    Returns the *width* of this Viewport object (DXF 40).

    Note: 
    If this Viewport object is an overall viewport,
    the values returned by width() and height() must be divided by a
    factor of 1.058, and the parameters of setWidth and setHeight() 
    must be multiplied by a like factor.                        
  */
  double width() const;

  /** Description:
    Sets the *width* of this Viewport object (DXF 40).
    Arguments:
    width (I) Width.

    Note: 
    If this Viewport object is an overall viewport,
    the values returned by width() and height() must be divided by a
    factor of 1.058, and the parameters of setWidth and setHeight() 
    must be multiplied by a like factor.                        
  */
  OdResult setWidth(
    double width);

  /** Description:
    Returns the WCS center point of this Viewport object (DXF 10).
  */
  OdGePoint3d centerPoint() const;

  /** Description:
    Sets the WCS center point of this Viewport object (DXF 10).
    Arguments:
    centerPoint (I) Center point.
  */
  OdResult setCenterPoint(
    const OdGePoint3d& centerPoint);

  /** Description:
    Returns the ID *number* of this Viewport object.
    Remarks:
    Returns -1 if this Viewport object is inactive.
  */
  OdInt16 number() const;

  /** Description:
    Returns true if and only if this Viewport object is on (DXF 90, bit 0x20000).
  */
  bool isOn() const;

  /** Description:
    Turns on this Viewport object (DXF 90, bit 0x20000, DXF 68 non-zero).
  */
  OdResult setOn();

  /** Description:
    Turns off this Viewport object (DXF 90, bit 0x20000, DXF 68 zero).
  */
  OdResult setOff();

  /** Description:
    Returns the WCS view target of this Viewport object (DXF 17).
  */
  OdGePoint3d viewTarget() const;

  /** Description:
    Sets the WCS view target of this Viewport object (DXF 17).
    Arguments:
    viewTarget (I) View target.
  */
  OdResult setViewTarget(
    const OdGePoint3d& viewTarget);

  /** Description:
    Returns the WCS view direction of this Viewport object (DXF 16).
  */
  OdGeVector3d viewDirection() const;

  /** Description:
    Sets the WCS view direction of this Viewport object (DXF 16).
    Arguments:
    viewDirection (I) View direction.
  */
  OdResult setViewDirection(
    const OdGeVector3d& viewDirection);

  /** Description:
    Returns the DCS view *height* of this Viewport object (DXF 45).
  */
  double viewHeight() const;

  /** Description:
    Sets the DCS view *height* of this Viewport object (DXF 45).
    Arguments:
    viewHeight (I) View *height*.
  */
  OdResult setViewHeight(
    double viewHeight);

  /** Description:
    Returns the DCS view center of this Viewport object (DXF 12).
  */
  OdGePoint2d viewCenter() const;

  /** Description:
    Sets the DCS view center of this Viewport object (DXF 12).
    Arguments:
    viewCenter (I) View center.
  */
  OdResult setViewCenter(
    const OdGePoint2d& viewCenter);

  /** Description:
    Returns the DCS twist angle of this Viewport object (DXF 51).
    
    Note:
    All angles are expressed in radians.
  */
  double twistAngle() const;

  /** Description:
    Sets the DCS twist angle of this Viewport object (DXF 51).
    Arguments:
    twistAngle (I) Twist angle.
    Note:
    All angles are expressed in radians.
  */
  OdResult setTwistAngle(
    double twistAngle);

  /** Description:
    Returns the perspective mode lens length (in mm) of this Viewport object (DXF 42).
  */
  double lensLength() const;

  /** Description:
    Sets the perspective mode lens length of this Viewport object (DXF 42).
    Arguments:
    lensLength (I) Lens length (mm).
  */
  OdResult setLensLength(
    double lensLength);

  /** Description:
    Returns true if and only if front clipping is on for this Viewport object (DXF 90, bit 0x02).
  */
  bool isFrontClipOn() const;

  /** Description:
    Turns on front clipping for this Viewport object (DXF 90, bit 0x02).
  */
  OdResult setFrontClipOn();

  /** Description:
    Turns off front clipping for this Viewport object (DXF 90, bit 0x02).
  */
  OdResult setFrontClipOff();

  /** Description:
    Returns true if and only if back clipping is on for this Viewport object (DXF 90, bit 0x04).
  */
  bool isBackClipOn() const;

  /** Description:
    Turns on back clipping for this Viewport object (DXF 90, bit 0x04).
  */
  OdResult setBackClipOn();

  /** Description:
    Turns off back clipping for this Viewport object (DXF 90, bit 0x04).
  */
  OdResult setBackClipOff();

  /** Description:
    Returns true if and only if the front clipping plane passes through the camera (DXF 90, bit 0x10).
    Remarks:
    If true, the front clipping plane ignores the front clip *distance*.
  */
  bool isFrontClipAtEyeOn() const;

  /** Description:
    Sets the front clipping plane to pass through the camera (DXF 90, bit 0x10).
    Remarks:
    The front clipping plane ignores the front clip *distance*.
  */
  OdResult setFrontClipAtEyeOn();

  /** Description:
    Sets the front clipping plane to utilize the front clip *distance* (DXF 90, bit 0x10).
  */
  OdResult setFrontClipAtEyeOff();

  /** Description:
      Returns the front clip *distance* of this Viewport object (DXF 43).
  */
  double frontClipDistance() const;

  /** Description:
    Sets the front clip *distance* of this Viewport object (DXF 43).
    Arguments:
    frontClipDistance (I) Front clip *distance*.
  */
  OdResult setFrontClipDistance(
    double frontClipDistance);

  /** Description:
    Returns the back clip *distance* of this Viewport object (DXF 44).
  */
  double backClipDistance() const;

  /** Description:
    Sets the back distance of this Viewport object (DXF 44).
    Arguments:
    backClipDistance (I) Back clip *distance*.
  */
  OdResult setBackClipDistance(
    double backClipDistance);

  /** Description:
     Returns true if and only if perspective is on for this Viewport object (DXF 90, bit 0x01).
  */
  bool isPerspectiveOn() const;

  /** Description:
    Sets perspective on for this Viewport object (DXF 90, bit 0x01).
  */
  OdResult setPerspectiveOn();

  /** Description:
    Sets perspective off for this Viewport object (DXF 90, bit 0x01).
  */
  OdResult setPerspectiveOff();

  /** Description:
    Returns true if and only if UCS follow mode is on for this Viewport object (DXF 90, bit 0x08).
  */
  bool isUcsFollowModeOn() const;

  /** Description:
    Sets UCS follow mode on for this Viewport object (DXF 90, bit 0x08).
  */
  OdResult setUcsFollowModeOn();

  /** Description:
    Sets UCS follow mode off for this Viewport object (DXF 90, bit 0x08).
  */
  OdResult setUcsFollowModeOff();

  /** Description:
    Returns true if and only if the UCS icon is visible for this Viewport object (DXF 90, bit 0x20).
  */
  bool isUcsIconVisible() const;

  /** Description:
    Sets UCS icon visible on for this Viewport object (DXF 90, bit 0x20).
  */
  OdResult setUcsIconVisible();

  /** Description:
    Sets UCS icon visible false for this Viewport object (DXF 90, bit 0x20).
  */
  OdResult setUcsIconInvisible();

  /** Description:
    Returns true if and only if the UCS icon is at the UCS origin for this Viewport object (DXF 90, bit 0x40).
  */
  bool isUcsIconAtOrigin() const;

  /** Description:
    Sets the UCS icon to the UCS origin for this Viewport object (DXF 90, bit 0x40).
  */
  OdResult setUcsIconAtOrigin();

  /** Description:
    Sets the UCS icon to the corner of this Viewport object (DXF 90, bit 0x40).
  */
  OdResult setUcsIconAtCorner();

  /** Description:
    Returns true if and only if fast zooms are on for this Viewport object (DXF 90, bit 0x80).
  */
  bool isFastZoomOn() const;

  /** Description:
    Sets fast zooms on for this Viewport object (DXF 90, bit 0x80).
  */
  OdResult setFastZoomOn();

  /** Description:
    Sets fast zooms off for this Viewport object (DXF 90, bit 0x80).
  */
  OdResult setFastZoomOff();

  /** Description:
    Returns the *circle* *zoom* percent of this Viewport object (DXF 72).
    Remarks:
    circleSides() has a range of [1..20000]
  */
  OdUInt16 circleSides() const;

  /** Description:
    Sets the *circle* *zoom* percent of this Viewport object (DXF 72).
    Arguments:
    circleSides (I) *circle* *zoom* percent [1,20000].
  */
  OdResult setCircleSides(
    OdUInt16 circleSides);

  /** Description:
    Returns true if and only if the snap mode is on for this Viewport object (DXF 90, bit 0x100).
  */
  bool isSnapOn() const;

  /** Description:
    Sets the snap mode on for this Viewport object (DXF 90, bit 0x100).
  */
  OdResult setSnapOn();

  /** Description:
    Sets the snap mode off for this Viewport object (DXF 90, bit 0x100).
  */
  OdResult setSnapOff();

  /** Description:
    Returns true if and only if isometric snap style is on for this Viewport object (DXF 90, bit 0x400).
  */
  bool isSnapIsometric() const;

  /** Description:
    Sets the isometric snap style on for this Viewport object (DXF 90, bit 0x400).
  */
  OdResult setSnapIsometric();

  /** Description:
    Sets the isometric snap style off for this Viewport object (DXF 90, bit 0x400).
  */
  OdResult setSnapStandard();

  /** Description:
    Returns the UCS snap angle of this Viewport object (DXF 50).
  */
  double snapAngle() const;

  /** Description:
    Sets the UCS snap angle of this Viewport object (DXF 50).
    Arguments:
    snapAngle (I) Snap angle.
    Note:
    All angles are expressed in radians.
  */
  OdResult setSnapAngle(
    double snapAngle);

  /** Description:
    Returns the UCS snap base point of this Viewport object (DXF 13).
  */
  OdGePoint2d snapBasePoint() const;

  /** Description:
    Sets the UCS snap base point of this Viewport object (DXF 13).
    Arguments:
    snapBasePoint (I) Snap base point.
  */
  OdResult setSnapBasePoint(
    const OdGePoint2d& snapBasePoint); 
  
  /** Description:
    Returns the snap increment of this Viewport object (DXF 14).
  */
  OdGeVector2d snapIncrement() const;

  /** Description:
    Sets the snap increment of this Viewport object (DXF 14).
    Arguments:
    snapIncrement (I) Snap increment.
  */
  OdResult setSnapIncrement(
    const OdGeVector2d& snapIncrement);
  
  /** Description:
    Returns the snap IsoPair of this Viewport object (DXF 14).
    Remarks:
    snapIsoPair() returns one of the following:
    
    @table
    Value    Description
    0        Left isoplane
    1        Top isoplane
    2        Right isoplane
  */
  OdUInt16 snapIsoPair() const;

  /** Description:
    Sets the snap IsoPair of this Viewport object (DXF 14).
    Arguments:
    snapIsoPair (I) Snap IsoPair.
    Remarks:
    snapIsoPair must be one of the following:
    
    @table
    Value    Description
    0        Left isoplane
    1        Top isoplane
    2        Right isoplane
  */
  OdResult setSnapIsoPair(
    OdUInt16 snapIsoPair);
  
  /** Description:
    Returns true if and only if the grid is on for this Viewport object (DXF 90, bit 0x200).
  */
  bool isGridOn() const;

  /** Description:
    Sets the grid on for this Viewport object (DXF 90, bit 0x200).
  */
  OdResult setGridOn();

  /** Description:
    Sets the grid off for this Viewport object (DXF 90, bit 0x200).
  */
  OdResult setGridOff();
  
  /** Description:
    Returns the grid increment of this Viewport object (DXF 15).
  */
  OdGeVector2d gridIncrement() const;

  /** Description:
    Sets the grid increment of this Viewport object (DXF 15).
    Arguments:
    gridIncrement (I) Grid increment.
  */
  OdResult setGridIncrement(
    const OdGeVector2d& gridIncrement);
  
  /** Description:
    Returns true if and only if this Viewport object will have hidden lines removed during plotting. (DXF 90, bit 0x800).
  */
  bool hiddenLinesRemoved() const;

  /** Description:
    Sets this Viewport object to have hidden shown lines during plotting. (DXF 90, bit 0x800).  
  */
  OdResult showHiddenLines();

  /** Description:
    Sets this Viewport object to have hidden lines removed during plotting. (DXF 90, bit 0x800).  
  */
  OdResult removeHiddenLines();
  
  /** Description:
    Freezes the specified layers in this Viewport object (DXF 341)
    
    Arguments:
    layerIds (I) Object IDs of the layers to be frozen.

    Remarks:
    Other viewports are unaffected by this function.
  */
  OdResult freezeLayersInViewport(
    const OdDbObjectIdArray& layerIds);

  /** Description:
    Thaws the specified layers in this Viewport object (DXF 341)
    
    Arguments:
    layerIds (I) Object IDs of the layers to be thawed.

    Remarks:
    Other viewports are unaffected by this function.
  */
  OdResult thawLayersInViewport(
    const OdDbObjectIdArray& layerIds);

  /** Description:
      Thaws all layers in this Viewport object.
  */
  OdResult thawAllLayersInViewport();

  /** Description:
    Returns true and only if the specified *layer* is frozen in this Viewport object.
    Arguments:
    layerId (I) Layer ID of the *layer* to be queried.
  */
  bool isLayerFrozenInViewport(
    const OdDbObjectId& layerId) const;

  /** Description:
    Returns all layers that are frozen in this Viewport object.
    Arguments:
    layerIds (O) Receives the Object IDs of the frozen layers.
  */
  OdResult getFrozenLayerList(
    OdDbObjectIdArray& layerIds) const;
  
  /** Description:
     Updates the display to reflect changes in this Viewport object.
     
     Remarks:
     Closing this Viewport object automatically calls this function. 
     
     Throws:
     eNotImplemented
  */
  OdResult updateDisplay() const;
  
  
  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);
  
  /** Description:
    Returns true if and only if scale factor of this Viewport object is locked (DXF 90, bit 0x4000).
  */
  bool isLocked() const;

  /** Description:
    Locks the scale factor of this Viewport object (DXF 90, bit 0x4000).
  */
  OdResult setLocked();

  /** Description:
    Unlocks the scale factor of this Viewport object (DXF 90, bit 0x4000).
  */
  OdResult setUnlocked();
  
  /** Description:
    Returns true if and only if this Viewport object is transparent (DXF 90, bit 0x4000).
  */
  bool isTransparent() const;

  /** Description:
    Sets this Viewport object transparent (DXF 90, bit 0x4000).
  */
  OdResult setTransparent();

  /** Description:
    Sets this Viewport object opaque (DXF 90, bit 0x4000).
  */
  OdResult setOpaque();
  
  enum StandardScaleType
  {
    kScaleToFit,  // Scaled to Fit
    kCustomScale, // Scale is not a standard scale
    k1_1,         // 1:1
    k1_2,         // 1:2
    k1_4,         // 1:4
    k1_5,         // 1:5
    k1_8,         // 1:8
    k1_10,        // 1:10
    k1_16,        // 1:16
    k1_20,        // 1:20
    k1_30,        // 1:30
    k1_40,        // 1:40
    k1_50,        // 1:50
    k1_100,       // 1:100
    k2_1,         // 2:1
    k4_1,         // 4:1
    k8_1,         // 8:1
    k10_1,        // 10:1
    k100_1,       // 100:1
    k1_128in_1ft, // 1/128"= 1'
    k1_64in_1ft,  // 1/64"= 1'
    k1_32in_1ft,  // 1/32"= 1'
    k1_16in_1ft,  // 1/16"= 1'
    k3_32in_1ft,  // 3/32"= 1'
    k1_8in_1ft,   // 1/8" = 1'
    k3_16in_1ft,  // 3/16"= 1'
    k1_4in_1ft,   // 1/4" = 1'
    k3_8in_1ft,   // 3/8" = 1'
    k1_2in_1ft,   // 1/2" = 1'
    k3_4in_1ft,   // 3/4" = 1'
    k1in_1ft,     // 1" = 1'
    k1and1_2in_1ft,// 1 1/2"= 1'
    k3in_1ft,     // 3" = 1'
    k6in_1ft,     // 6" = 1'
    k1ft_1ft      // 1' = 1'
  };
  
  enum ShadePlotType
  {
      kAsDisplayed = 0,     // As displayed
      kWireframe   = 1,     // Wireframe
      kHidden      = 2,     // Hidden
      kRendered    = 3,     // Rendered
      kVisualStyle = 4,
      kRenderPreset= 5
  };

  /** Description:
    Returns the custom scale of this Viewport object.
  */
  double customScale() const;

  /** Description:
    Sets the custom scale of this Viewport object.
    Arguments:
    customScale (I) Custom scale.
  */
  OdResult setCustomScale(
    double customScale);
  
  /** Description:
    Returns the standard scale type of this Viewport object/
  */
  StandardScaleType standardScale() const;

  /** Description:
    Sets the standard scale type of this Viewport object.
    Arguments:
    standardScale (I) Standard scale type.
  */
  OdResult setStandardScale(
    const StandardScaleType standardScale);
  
  /** Description:
    Returns the name of the plot style sheet applied to objects in this Viewport object (DXF 1).
  */
  OdString plotStyleSheet() const;

  OdResult plotStyleSheet(OdChar *&) const;
  OdResult plotStyleSheet(const OdChar *&) const;

  /** Description:
    Returns the plot style sheet name associated with this Viewport object.
  */
  OdResult effectivePlotStyleSheet(const OdChar *&pName) const;

  /** Description:
   Sets the plot style sheet name associated with this Viewport object.
  */
  OdResult setPlotStyleSheet(
    const OdChar * plotStyleSheetName);
  
  /** Description:
    Returns true if and only if non-rectangular clipping is enabled for this Viewport object (DXF 90, bit 0x10000).
  */
  bool isNonRectClipOn() const;

  /** Description:
    Sets non-rectangular clipping on for this Viewport object (DXF 90, bit 0x10000).
  */
  OdResult setNonRectClipOn();

  /** Description:
    Sets non-rectangular clipping off for this Viewport object (DXF 90, bit 0x10000).
  */
  OdResult setNonRectClipOff();
  
  /** Description:
    Returns the Object ID of the clipping entity for this Viewport object (DXF 340).
  */
  OdDbObjectId nonRectClipEntityId() const;

  /** Description:
    Sets the Object ID of the clipping entity for this Viewport object (DXF 340).
    
    Arguments:
    clipEntityId (I) Object ID of the clipping entity.
    
    Remarks:
    The following entity types are acceptable clipping entities:

    @untitled table
    OdDb2dPolyline
    OdDb3dPolyline
    OdDbCircle
    OdDbEllipse
    OdDbFace
    OdDbPolyline
    OdDbRegion
    OdDbSpline
    
    Note:
    A clipping entity must be in the same PaperSpace as this Viewport.
  */
  OdResult setNonRectClipEntityId(
    OdDbObjectId clipEntityId);
  
  /*
     virtual void modified(const OdDbObject *); 
  */
  virtual void copied(const OdDbObject* pDbObj,const OdDbObject* pNewObj);
  virtual void subObjModified(const OdDbObject* pDbObj, const OdDbObject* pSubObj);
  
  /** Description:
    Returns the *origin*, X-axis, and Y-Axis of the UCS associated with this Viewport object.

    Arguments:
    origin (O) Receives the UCS *origin* (DXF 110).
    xAxis (O) Receives the UCS X-axis (DXF 111).
    yAxis (O) Receives the UCS Y-axis (DXF 112).
  */
  OdResult getUcs(OdGePoint3d& origin, 
    OdGeVector3d& xAxis, 
    OdGeVector3d& yAxis) const;

  /** Description:
    True if and only if the UCS associated with this Viewport object
    is orthographic with respect to UCSBASE (DXF 79).

    Arguments:
    viewType (O) Receives the orthographic view type.
    pDb (I) Working database. If object is a database resident this parameter is ignored.

    Remarks:
    Returns the type of orthographic view.
    
    viewType must be one of the following:
    
    @table
    Name                  Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS 
    OdDb::kTopView        1       Top view with respect to the UCS 
    OdDb::kBottomView     2       Bottom view with respect to the UCS 
    OdDb::kFrontView      3       Front view with respect to the UCS 
    OdDb::kBackView       4       Back view with respect to the UCS 
    OdDb::kLeftView       5       Left view with respect to the UCS 
    OdDb::kRightView      6       Right view with respect to the UCS 
  */
  bool isUcsOrthographic(
    OdDb::OrthographicView& viewType,
    const OdDbDatabase* pDb = 0) const;

  /** Description:
    Returns the Object ID of the UCS associated with this Viewport object (DXF 345 or 346).
  */
  OdDbObjectId ucsName() const;

  /** Description:
    Returns the *elevation* of the UCS plane of this entity (DXF 146).
    
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the UCS plane of this entity.
  */
  double elevation() const;
  
  /** Description:
    Sets the UCS associated with this Viewport object 

    Arguments:
    origin (I) The WCS *origin* of the UCS (DXF 110).
    xAxis (I) The WCS X-axis of the UCS (DXF 111).
    yAxis (I) The WCS Y-axis of the UCS(DXF 112).
    viewType (I) Orthographic view type (DXF 79).
    pDb (I) Working database. If object is a database resident this parameter is ignored.
    ucsId (I) Object ID of the UCS (DXF 345 or 346).

    viewType must be one of the following:
    
    @table
    Name            Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS 
    OdDb::kTopView        1       Top view with respect to the UCS 
    OdDb::kBottomView     2       Bottom view with respect to the UCS 
    OdDb::kFrontView      3       Front view with respect to the UCS 
    OdDb::kBackView       4       Back view with respect to the UCS 
    OdDb::kLeftView       5       Left view with respect to the UCS 
    OdDb::kRightView      6       Right view with respect to the UCS 
  */
  OdResult setUcs(
    const OdGePoint3d& origin, 
    const OdGeVector3d& xAxis, 
    const OdGeVector3d& yAxis);

  OdResult setUcs(
    OdDb::OrthographicView viewType, const OdDbDatabase* pDb = 0);

  OdResult setUcs(
    const OdDbObjectId& ucsId);

  /** Description:
    Sets the UCS associated with this Viewport object to the WCS. 
  */
  OdResult setUcsToWorld();

  /** Description:
    Sets the *elevation* of the UCS plane of this Viewport object (DXF 146).
    Arguments:
    elevation (I) Elevation.
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this Viewport object.
  */
  OdResult setElevation(
    double elevation);

  bool isViewOrthographic(OdDb::OrthographicView& view) const;

  OdResult setViewDirection(OdDb::OrthographicView view);

  
  /** Description:
    Returns true if and only if the UCS that is associated with this Viewport object will become active
    with the activation of this Viewport object.
  */
  bool isUcsSavedWithViewport() const;

  /** Description:
    Controls the activation of the UCS that is associated with this Viewport object 
    with the activation of this Viewport object.
    
    Arguments:
    ucsPerViewport (I) Controls activation of the UCS.
  */
  void setUcsPerViewport(
    bool ucsPerViewport);
  
  /** Description:
    Set the render mode of this Viewport object (DXF 281).
    Arguments:
    renderMode (I) Render mode.
    Remarks:
    renderMode must be one of the following:
    
    @table
    Name                            Value      Description
    kBoundingBox                    -1         Bounding box. For internal use only.
    k2DOptimized                    0          Standard *display*. Optimized for 2D.
    kWireframe                      1          Standard *display*. Uses 3D pipeline.
    kHiddenLine                     2          Wireframe *display*. Hidden lines removed.
    kFlatShaded                     3          Faceted *display*. One *color* per face.
    kGouraudShaded                  4          Smooth shaded *display*. Colors interpolated between *vertices*.
    kFlatShadedWithWireframe        5          Faceted *display* with wireframe overlay.
    kGouraudShadedWithWireframe     6          Smooth shaded *display* with wireframe overlay.
  */
  OdResult setRenderMode(
    OdDbAbstractViewTableRecord::RenderMode renderMode);

  /** Description:
    Returns the render mode of this Viewport object (DXF 281).

    Remarks:
    renderMode() returns one of the following:
    
    @table
    Name                            Value      Description
    kBoundingBox                    -1         Bounding box. For internal use only.
    k2DOptimized                    0          Standard *display*. Optimized for 2D.
    kWireframe                      1          Standard *display*. Uses 3D pipeline.
    kHiddenLine                     2          Wireframe *display*. Hidden lines removed.
    kFlatShaded                     3          Faceted *display*. One *color* per face.
    kGouraudShaded                  4          Smooth shaded *display*. Colors interpolated between *vertices*.
    kFlatShadedWithWireframe        5          Faceted *display* with wireframe overlay.
    kGouraudShadedWithWireframe     6          Smooth shaded *display* with wireframe overlay.
  */
  OdDbAbstractViewTableRecord::RenderMode renderMode() const;

  /** Description:
    Returns the shade plot type of the current viewport. 

    Remarks:
    shadePlot determines how this Viewport object will plot.
  */
  ShadePlotType shadePlot() const;

  /** Description:
    Set the shade plot type of this Viewport object (DXF 281).
    Arguments:
    shadePlot (I) Shade plot type.
    Remarks:
    shadePlot determines how this Viewport object will plot.
  */
  OdResult setShadePlot(
    const ShadePlotType shadePlot);

  // New in R21 functions

  OdDbObjectId shadePlotId() const;
  OdResult     setShadePlot(const ShadePlotType type, const OdDbObjectId& shadePlotId);

  bool         plotWireframe() const;
  bool         plotAsRaster() const;

  OdDbObjectId background() const;
  OdResult     setBackground(const OdDbObjectId& backgroundId);
  
  OdDbObjectId previousBackground(OdGiDrawable::DrawableType type
                                          = kGeometry) const;
  OdResult  setPreviousBackground(OdDbObjectId backgroundId,
                                             OdGiDrawable::DrawableType type
                                             = kGeometry);
  OdResult   setPreviousBackground(OdDbObjectId backgroundId,
                                            OdGiDrawable::DrawableType type,
                                            bool bForcedSwitch);
  bool previousBackgroundForcedSwitch (void) const;
  // Visual Styles

  OdDbObjectId visualStyle() const;
  OdResult     setVisualStyle(const OdDbObjectId& visualStyle);

  // Viewport Lighting

  bool                isDefaultLightingOn() const;
  OdResult            setDefaultLightingOn(bool on);
  OdGiViewportTraits::DefaultLightingType defaultLightingType() const;
  OdResult            setDefaultLightingType(OdGiViewportTraits::DefaultLightingType typ);

  // Brightness controls the relative intensity of lights.

  double              brightness() const;
  OdResult            setBrightness(double);

  // Contrast controls intensity of ambient light, relative to other lights.

  double              contrast() const;
  OdResult            setContrast(double);

  OdCmColor           ambientLightColor() const;
  OdResult            setAmbientLightColor(const OdCmColor& clr);

  // A single sun (distant light) can be associated with each viewport.

  OdDbObjectId        sunId() const;
  OdDbObjectId        setSun(OdDbSun* pSun);
  OdResult            setSun(OdDbObjectId& retId, OdDbObject* pSun);
  OdResult            setSun(OdDbObjectId& retId, OdDbObject* pSun, bool eraseOldSun);

  OdResult toneOperatorParameters(OdGiToneOperatorParameters &params) const;
  OdResult setToneOperatorParameters(const OdGiToneOperatorParameters &params);


  OdResult setAnnotationScale(const OdDbAnnotationScale* pScaleObj);
  OdDbAnnotationScalePtr annotationScale() const;
  
  bool isGridBoundToLimits() const;
  OdResult setGridBoundToLimits(bool bNewVal);

  bool isGridAdaptive() const;
  OdResult setGridAdaptive(bool bNewVal);

  bool isGridSubdivisionRestricted() const;
  OdResult setGridSubdivisionRestricted(bool bNewVal);

  bool isGridFollow() const;
  OdResult setGridFollow(bool bNewVal);

  OdUInt16 gridMajor() const;
  OdResult setGridMajor(OdUInt16);
  
  OdGsView* gsView() const;
  void setGsView(OdGsView*);


  virtual void subSetDatabaseDefaults(OdDbDatabase* pDb);

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

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  OdResult subClose();

  OdResult subErase(
    OdBool erasing);

  /** Description:
    Adjusts the parameters of this Viewport object such that the view is zoomed 
    to the extents of the drawing.
  */
  void zoomExtents();

  virtual OdResult subGetGeomExtents(
    OdDbExtents& extents) const;

  virtual OdResult subTransformBy(
  const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  void modified(const OdDbObject* pObj);

  void erased(const OdDbObject* pObj, OdBool pErasing);

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, const OdGePlane& projPlane, 
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, 
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0 ) const;

  // view association

  OdResult setModelView      (const OdDbXrefObjectId &xrefObjId);
  OdResult getModelView      (OdDbXrefObjectId &xrefObjId) const;
  OdResult removeModelView   (void);

  OdResult setSheetView      (OdDbObjectId objId);
  OdResult getSheetView      (OdDbObjectId &objId)const;
  OdResult removeSheetView   (void);

  OdResult setLabelBlock     (OdDbObjectId objId);
  OdResult getLabelBlock     (OdDbObjectId &objId)const;
  OdResult removeLabelBlock  (void);

  OdResult syncModelView     (void);
  
#ifdef _WINDOWS_
    OdResult getThumbnail (BITMAPINFO*& thumbnail) const;
    OdResult setThumbnail(const BITMAPINFO * thumbnail);
#endif
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbViewport object pointers.
*/
typedef OdSmartPtr<OdDbViewport> OdDbViewportPtr;

#include "TD_PackPop.h"

#endif
