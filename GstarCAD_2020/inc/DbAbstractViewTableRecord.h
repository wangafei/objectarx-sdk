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




#ifndef _ODDBABSTRACTVIEWLTABLERECORD_INCLUDED
#define _ODDBABSTRACTVIEWLTABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"
#include "DbAbstractViewportData.h"
#include "ViewportDefs.h"
#include "Gi/GiViewportTraits.h"

class OdDbSun;
class OdDbAbstractViewTable;

/** Description:
    This class is the base class for OdDbViewTableRecord and OdDbViewportTableRecord.

    Library:
    TD_Db
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbAbstractViewTableRecord : public OdDbSymbolTableRecord
{
public:

  ODDB_DECLARE_MEMBERS(OdDbAbstractViewTableRecord);

protected:
  OdDbAbstractViewTableRecord();
 
public:
  virtual ~OdDbAbstractViewTableRecord();

  typedef OdDbAbstractViewTable TableType;

	enum RenderMode
	{
		k2DOptimized                 = 0,
		kWireframe                   = 1,
		kHiddenLine                  = 2,
		kFlatShaded                  = 3,
		kGouraudShaded               = 4,
		kFlatShadedWithWireframe     = 5,
		kGouraudShadedWithWireframe  = 6,
		kMaxRenderMode
	};
  /** Description:
    Returns the DSC center point of this View. 
    Remarks:
    o  DXF 10 for OdDbViewTableRecord.
    o  DXF 12 for OdDbViewportTableRecord.
  */
  OdGePoint2d centerPoint() const;

  /** Description:
    Sets the DCS center point of this View.
    Arguments:
    centerPoint (I) Center *point*.
    Remarks:
    o  DXF 10 for OdDbViewTableRecord.
    o  DXF 12 for OdDbViewportTableRecord.
  */
  void setCenterPoint(
    const OdGePoint2d& centerPoint);

  /** Description:
    Returns the DCS *height* of this View (DXF 40).
  */
  double height() const;

  /** Description:
    Sets the DCS *height* of this View (DXF 40).
    Arguments:
    height (I) Height.
  */
  void setHeight(double height);

  /** Description:
    Returns the DCS *width* of this View (DXF 41).
    
    Remarks:
    DXF 41 contains the *width* : *height* ratio for OdDbViewportTableRecord.
  */
  double width() const;

  /** Description:
    Sets the DCS *width* of this View (DXF 41).

    Arguments:
    width (I) Width. 

    Remarks:
    DXF 41 contains the *width* : *height* ratio for OdDbViewportTableRecord.
  */
  void setWidth(
    double width);

   /** Description:
    Returns the WCS view *target* of this View.
    
    Remarks:
    o  DXF 12 for OdDbViewTableRecord. 
    o  DXF 17 for OdDbViewportTableRecord.    
  */
  OdGePoint3d target() const;

  /** Description:
    Sets the WCS view *target* of this View.
    Arguments:
    target (I) Target.
    Remarks:
    o  DXF 12 for OdDbViewTableRecord.
    o  DXF 17 for OdDbViewportTableRecord.    
  */
  void setTarget(
    const OdGePoint3d& target);

  /** Description:
    Returns the WCS view direction of this View.
    viewDirection (I) View direction.

    Remarks:
    o  DXF 11 for OdDbViewTableRecord. 
    o  DXF 16 for OdDbViewportTableRecord.    
  */
  OdGeVector3d viewDirection() const;

  /** Description:
    Sets the WCS view direction of this View.
    Arguments:
    viewDirection (I) View direction.

    Remarks:
    o  DXF 12 for OdDbViewTableRecord. 
    o  DXF 17 for OdDbViewportTableRecord.    
  */
 void setViewDirection(
  const OdGeVector3d& viewDirection);

  /** Description:
    Returns the DCS twist angle of this View.

    Remarks:
    o  DXF 50 for OdDbViewTableRecord 
    o  DXF 51 for OdDbViewportTableRecord.    
    
    Note:
    All angles are expressed in radians.
  */
  double viewTwist() const;

  /** Description:
    Sets the DCS twist angle of this View.

    Remarks:
    o  DXF 50 for OdDbViewTableRecord 
    o  DXF 51 for OdDbViewportTableRecord.    
    
    Arguments:
    viewTwist (I) View twist angle.
    Note:
    All angles are expressed in radians.
  */
  void setViewTwist(
    double viewTwist);

  /** Description:
    Returns the perspective mode lens length (in mm) of this View (DXF 42).
  */
  double lensLength() const;

  /** Description:
    Sets the perspective mode lens length of this View (DXF 42).
    Arguments:
    lensLength (I) Lens length (mm).
  */
  void setLensLength(
    double lensLength);

  /** Description:
      Returns the front clip *distance* of this View (DXF 43).
  */
  double frontClipDistance() const;

  /** Description:
    Sets the front clip *distance* of this View (DXF 43).
    Arguments:
    frontClipDistance (I) Front clip *distance*.
  */
  void setFrontClipDistance(
    double frontClipDistance);

  /** Description:
    Returns the back clip *distance* of this View (DXF 44).
  */
  double backClipDistance() const;

  /** Description:
    Sets the back distance of this View (DXF 44).
    Arguments:
    backClipDistance (I) Back clip *distance*.
  */
  void setBackClipDistance(
    double backClipDistance);

  /** Description:
     Returns true if and only if perspective is on for this View (DXF 70, bit 0x01).
  */
  bool perspectiveEnabled() const;

  /** Description:
    Controls perspective mode for this view (DXF 71, bit 0x01).

    Arguments:
    perspectiveEnabled (I) Perspective Enabled.
  */
  void setPerspectiveEnabled(
    bool perspectiveEnabled);

  /** Description:
    Returns true if and only if front clipping is enabled for this View (DXF 71, bit 0x02).
  */
  bool frontClipEnabled() const;

  /** Description:
    Controls front clipping for this view (DXF 71, bit 0x02).

    Arguments:
    frontClipEnabled (I) Front clipping enabled.
  */
  void setFrontClipEnabled(
    bool frontClipEnabled);

  /** Description:
    Returns true if and only if back clipping is enabled for this View (DXF 71, bit 0x04).
  */
  bool backClipEnabled() const;

  /** Description:
    Controls back clipping for this view (DXF 71, bit 0x04).

    Arguments:
    backClipEnabled (I) Back clipping enabled.     
  */
  void setBackClipEnabled(
    bool backClipEnabled);

  /** Description:
    Returns true if and only if the front clipping plane plane passes through the camera (DXF 71, bit 0x10).
    Remarks:
    If true, the front clipping plane ignores the front clip *distance*.
  */
  bool frontClipAtEye() const;

  /** Description:
    Controls the front clipping plane passing through the camera (DXF 71, bit 0x10).

    Arguments:
    atEye (I) True to pass through camera, false to use front clip *distance*.
 */
  void setFrontClipAtEye(
    bool atEye);

  /** Description:
    Sets the render mode of this View (DXF 281).
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
  void setRenderMode(OdDbAbstractViewTableRecord::RenderMode renderMode);

  /** Description:
    Returns the render mode of this View (DXF 281).
    
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
    Returns the *origin*, X-axis, and Y-Axis of the UCS associated with this Viewport object.

    Arguments:
    origin (O) Receives the UCS *origin* (DXF 110).
    xAxis (O) Receives the UCS X-axis (DXF 111).
    yAxis (O) Receives the UCS Y-axis (DXF 112).

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult getUcs(OdGePoint3d& origin, 
    OdGeVector3d& xAxis, 
    OdGeVector3d& yAxis) const;

  /** Description:
    True if and only if the UCS associated with this View is
    orthographic with respect to UCSBASE (DXF 79).

    Arguments:
    orthoUcs (O) Receives the orthographic view type.
    pDb (I) Working *database*. 
    Remarks:
    Returns the type of orthographic view.
    
    orthoUcs must be one of the following:
    
    @table
    Name                 Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS 
    OdDb::kTopView        1       Top view with respect to the UCS 
    OdDb::kBottomView     2       Bottom view with respect to the UCS 
    OdDb::kFrontView      3       Front view with respect to the UCS 
    OdDb::kBackView       4       Back view with respect to the UCS 
    OdDb::kLeftView       5       Left view with respect to the UCS 
    OdDb::kRightView      6       Right view with respect to the UCS
    Note:
    If if this View object is *database* resident, the pDb parameter is ignored.
 
  */
  bool isUcsOrthographic(
    OdDb::OrthographicView& orthoUcs,
    const OdDbDatabase* pDb = 0) const;

  /** Description:
    Returns the Object ID of the UCS associated with this View (DXF 345).
  */
  OdDbObjectId ucsName() const;

  /** Description:
    Returns the *elevation* of the UCS plane of this View (DXF 146).
    
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the UCS plane of this View.
  */
  double elevation() const;

  /** Description:
    Sets the UCS associated with this Viewport object .

    Arguments:
    origin (I) The UCS *origin* (DXF 110).
    xAxis (I) The UCS X-axis (DXF 111).
    yAxis (I) The UCS Y-axis (DXF 112).
    orthoUcs (I) Orthographic view type (DXF 79).
    pDb (I) Working database. If object is a database resident this parameter is ignored.
    ucsId (I) Object ID of UCS (DXF 345 or 346).

    orthoUcs must be one of the following:
    
    @table
    Name                 Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS 
    OdDb::kTopView        1       Top view with respect to the UCS 
    OdDb::kBottomView     2       Bottom view with respect to the UCS 
    OdDb::kFrontView      3       Front view with respect to the UCS 
    OdDb::kBackView       4       Back view with respect to the UCS 
    OdDb::kLeftView       5       Left view with respect to the UCS 
    OdDb::kRightView      6       Right view with respect to the UCS 

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setUcs(
    const OdGePoint3d& origin, 
    const OdGeVector3d& xAxis, 
    const OdGeVector3d& yAxis);

  OdResult setUcs(
    OdDb::OrthographicView orthoUcs,
    const OdDbDatabase* pDb = 0);

  OdResult setUcs(
    const OdDbObjectId& ucsId);

  /** Description:
    Sets the UCS associated with this View to the WCS. 

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setUcsToWorld();

  /** Description:
    Sets the *elevation* of the UCS plane of this View (DXF 146).
    Arguments:
    elevation (I) Elevation.
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this View.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setElevation(
    double elevation);
  
  // New-2007 API

  const OdDbObjectId& background() const;//Gcad(Modify)
  OdDbObjectId&  background();//Gcad(Add);
  OdResult setBackground(const OdDbObjectId& background);//Gcad(Modify)

  OdDbObjectId visualStyle() const;
  OdResult setVisualStyle(const OdDbObjectId& visualStyle);//Gcad(Modify)

  bool isDefaultLightingOn() const;
  OdResult setDefaultLightingOn(bool isOn);//Gcad(Modify)

  OdGiViewportTraits::DefaultLightingType defaultLightingType() const;
  OdResult setDefaultLightingType(OdGiViewportTraits::DefaultLightingType lightingType);//Gcad(Modify)

  double brightness() const;
  OdResult setBrightness(double brightness);//Gcad(Modify)

  double contrast() const;
  OdResult setContrast(double contrast);//Gcad(Modify)

  OdCmColor ambientLightColor() const;
  OdResult setAmbientLightColor(const OdCmColor& color);//Gcad(Modify)

  OdDbObjectId sunId() const;
  OdDbObjectId setSun(OdDbSun* pSun);
  OdResult   setSun(OdDbObjectId& retId, OdDbSun* pSun);//Gcad(Modify)

  OdResult toneOperatorParameters(OdGiToneOperatorParameters &params) const;
  OdResult setToneOperatorParameters(const OdGiToneOperatorParameters &params);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult copyFrom (
    const OdRxObject* pSource);

	bool isViewOrthographic(OdDb::OrthographicView& view) const;

  OdResult setViewDirection(OdDb::OrthographicView view );

  virtual OdGiDrawable* drawable();

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbViewportTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbAbstractViewTableRecord> OdDbAbstractViewTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBABSTRACTVIEWLTABLERECORD_INCLUDED

