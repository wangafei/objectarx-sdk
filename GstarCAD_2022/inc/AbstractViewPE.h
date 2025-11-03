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




#ifndef OD_ABSTRACTVIEWPE_H
#define OD_ABSTRACTVIEWPE_H


#include "Ge/GePoint3d.h"
#include "Ge/GeVector3d.h"
#include "ViewportDefs.h"
#include "IdArrays.h"
#include "Gi/GiViewportTraits.h"

class OdGeBoundBlock3d;
class OdDbDatabase;

#include "TD_PackPush.h"

/** Description:
    This class defines the interface for Protocol Extension classes for OdGsView, OdDbViewTableRecord, OdDbViewport and OdDbViewportTableRecord objects.
    
    Note:
    Only the following objects are supported:
    
    o  OdGsView
    o  OdDbViewTableRecord
    o  OdDbViewport
    o  OdDbViewportTableRecord
    o  Derivatives of one of the above.

    Library: TD_Db
    
    {group:Other_Classes} 
*/
class TOOLKIT_EXPORT OdAbstractViewPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdAbstractViewPE);

  // Viewport methods:

  /** Description:
    Returns the lower-left corner of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
    See Also:
    Coordinate Systems
  */
  virtual OdGePoint2d lowerLeftCorner(const OdRxObject* pViewport) const = 0;
  /** Description:
    Returns the upper-right corner of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
    See Also:
    Coordinate Systems
  */
  virtual OdGePoint2d upperRightCorner(const OdRxObject* pViewport) const = 0;
  /** Description:
    Sets the corners of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    lowerLeft (I) Lower-left corner.
    upperRight (I) Upper-right corner.
    Remarks:
    o  point == (0.0, 0.0) corresponds to the lower-left corner of the graphics area.
    o  point == (1.0, 1.0) corresponds to the upper-right corner of the graphics area.
    See Also:
    Coordinate Systems
  */
  virtual void setViewport(OdRxObject* pViewport, const OdGePoint2d& lowerLeft, const OdGePoint2d& upperRight) const = 0;

  // View methods:

   /** Description:
    Returns the WCS view *target* of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGePoint3d target(const OdRxObject* pViewport) const = 0;
  
  /** Description:
    Returns the WCS view *direction* of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGeVector3d direction(const OdRxObject* pViewport) const = 0;

  /** Description:
    Returns the WCS Up vector of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGeVector3d upVector (const OdRxObject* pViewport) const = 0;
  /** Description:
    Returns the DCS field width of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    See Also:
    Coordinate Systems
  */
  virtual double fieldWidth(const OdRxObject* pViewport) const = 0;
  virtual void setfieldWidth(const OdRxObject* pViewport,double fw) = 0;
  /** Description:
    Returns the DCS field height of the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    See Also:
    Coordinate Systems
  */
  virtual double fieldHeight(const OdRxObject* pViewport) const = 0;
  virtual void setfieldHeight(const OdRxObject* pViewport,double fh)  = 0;
  virtual void setViewCenter(const OdRxObject* pViewport,const OdGePoint2d &ct) = 0;
  /** Description:
    Returns true if and only if the *projection* type for the specified Viewport object is perspective. 
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isPerspective(const OdRxObject* pViewport) const = 0;
  
  /** Description:
    Returns the view offset vector for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdGeVector2d viewOffset(const OdRxObject* pViewport) const = 0;

  /** Description:
    Sets the parameters for the specified Viewport object according to the arguments.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    target (I) WCS view *target*.
    direction (I) WCS view *direction*.
    upVector (I) WCS Up vector.
    fieldWidth (I) DCS field width.
    fieldHeight (I) DCS field height.
    isPerspective (I) Controls perspective.
    viewOffset (I) View offset vector.

    See Also:
    Coordinate Systems
  */
  virtual void setView(
      OdRxObject* pViewport,
      const OdGePoint3d& target,
      const OdGeVector3d& direction,
      const OdGeVector3d& upVector,
      double fieldWidth,
      double fieldHeight,
      bool isPerspective,
      const OdGeVector2d& viewOffset = OdGeVector2d::kIdentity) const = 0;

  /** Description:
    Sets the perspective lens length for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    lensLength (I) Perspective lens length.
  */
  virtual void setLensLength(OdRxObject* pViewport, double lensLength) const = 0;
  /** Description:
    Returns the perspective lens length for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual double lensLength(const OdRxObject* pViewport) const = 0;

  /** Description:
    Returns true if and only if front clipping is on for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isFrontClipOn(const OdRxObject* pViewport) const = 0;

  /** Description:
    Controls front clipping for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    frontClip (I) Controls front clip.
  */
  virtual void setFrontClipOn(OdRxObject* pViewport, bool frontClip) const = 0;

  /** Description:
    Returns true if and only if back clipping is on for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isBackClipOn(const OdRxObject* pViewport) const = 0;
  
  /** Description:
    Controls back clipping for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    backClip (I) Controls back clip.
  */
  virtual void setBackClipOn(OdRxObject* pViewport, bool backClip) const = 0;

  /** Description:
    Returns true if and only if the front clipping plane passes through the camera for the specified Viewport object.
    Remarks:
    If true, the front clipping plane ignores the front clip *distance*.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool isFrontClipAtEyeOn(const OdRxObject* pViewport) const = 0;
  
  /** Description:
    Controls the front clipping plane's passing through the camera for the specified Viewport object.
    Remarks:
    If and only if frontClipAtEye is true, the front clipping plane ignores the front clip *distance*.

    Arguments:
    pViewport (I) Pointer to the Viewport object.
    frontClipAtEye (I) Controls FrontClipAtEye.
  */
  virtual void setFrontClipAtEyeOn(OdRxObject* pViewport, bool frontClipAtEye) const = 0;

  /** Description:
    Returns the front clip *distance* for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual double frontClipDistance(const OdRxObject* pViewport) const = 0;
  
  /** Description:
    Sets the front clip *distance* for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    frontClipDistance (I) Front clip *distance*.
  */
  virtual void setFrontClipDistance(OdRxObject* pViewport, double frontClipDistance) const = 0;

  /** Description:
    Returns the back clip *distance* for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual double backClipDistance(const OdRxObject* pViewport) const = 0;
  /** Description:
    Sets the front clip *distance* for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    backClipDistance (I) Back clip *distance*.
  */
  virtual void setBackClipDistance(OdRxObject* pViewport, double backClipDistance) const = 0;

  /** Description:
    Sets the render mode for the specified Viewport object.
    Arguments:
    renderMode (I) Render mode.
    pViewport (I) Pointer to the Viewport object.
    
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
  virtual void setRenderMode(OdRxObject* pViewport, OdDb::RenderMode renderMode) const = 0;

  /** Description:
    Returns the render mode for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.

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
  virtual OdDb::RenderMode renderMode(const OdRxObject* pViewport) const = 0;

  /** Description:
    Sets visual style for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual void setVisualStyle(OdRxObject* pViewport, const OdDbObjectId& visualStyleId) const = 0;
  /** Description:
    Returns visual style for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdDbObjectId visualStyle(const OdRxObject* pViewport) const = 0;

  /** \details
    Sets background for the specified Viewport object.
    \param pViewport [in]  Pointer to the Viewport object.
    \param backgroundId [in]  Background Object ID.
  */
  virtual void setBackground(OdRxObject* pViewport, OdDbStub* backgroundId) const = 0;
  /** \details
    Returns background for the specified Viewport object.
    \param pViewport [in]  Pointer to the Viewport object.
  */
  virtual OdDbStub* background(const OdRxObject* pViewport) const = 0;

  /** \details
    Returns default lighting state.
    \param pViewport [in]  Pointer to the Viewport object.
  */
  virtual bool isDefaultLightingOn(const OdRxObject* pViewport) const;
  /** \details
    Sets default lighting state.
    \param pViewport [in]  Pointer to the Viewport object.
    \param isOn [in]  New default lighting state.
  */
  virtual void setDefaultLightingOn(OdRxObject* pViewport, bool isOn) const;

  /** \details
    Returns default lighting type.
    \param pViewport [in]  Pointer to the Viewport object.
  */
  virtual OdGiViewportTraits::DefaultLightingType defaultLightingType(const OdRxObject* pViewport) const;
  /** \details
    Sets default lighting type.
    \param pViewport [in]  Pointer to the Viewport object.
    \param lightingType [in]  New default lighting type.
  */
  virtual void setDefaultLightingType(OdRxObject* pViewport, OdGiViewportTraits::DefaultLightingType lightingType) const;

  /** \details
    Returns the frozen layers for the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    frozenLayers (O) Receives an array of frozen *layer* Object IDs.
  */
  virtual void frozenLayers(const OdRxObject* pViewport, OdDbObjectIdArray& frozenLayers) const;

  /** Description:
    Sets the frozen layers for the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    frozenLayers (I) Array of frozen *layer* Object IDs.
  */
  virtual void setFrozenLayers(OdRxObject* pViewport, const OdDbObjectIdArray& frozenLayers) const;

  /** Arguments:
    pSourceView (I) Pointer to the source Viewport object.
    pDestinationView (I) Pointer to the destination Viewport object
  */
  virtual void setView(OdRxObject* pDestinationView, const OdRxObject* pSourceView) const;

  // UCS methods:

  /** Description:
    Returns true if and only if there is a UCS associated with the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual bool hasUcs(const OdRxObject* pViewport) const = 0;

  /** Description:
    Returns orthographic view *type* of the UCS associated with the specified Viewport object.

    Arguments:
    pViewport (I) Pointer to the Viewport object.
    pDb (I) Working database. If object is a database resident this parameter is ignored.

    Remarks:
    orthoUcs() returns one of the following:
    
    @table
    Name                 Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS 
    OdDb::kTopView        1       Top view with respect to the UCS 
    OdDb::kBottomView     2       Bottom view with respect to the UCS 
    OdDb::kFrontView      3       Front view with respect to the UCS 
    OdDb::kBackView       4       Back view with respect to the UCS 
    OdDb::kLeftView       5       Left view with respect to the UCS 
    OdDb::kRightView      6       Right view with respect to the UCS 
  */
  virtual OdDb::OrthographicView orthoUcs(const OdRxObject* pViewport, const OdDbDatabase* pDb = 0) const = 0;

  /** Description:
    Sets the UCS associated with the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    orthoUcs(I) Orthographic view *type*.
    pDb (I) Working database. If object is a database resident this parameter is ignored.

    Remarks:
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
  */
  virtual bool setUcs(OdRxObject* pViewport, OdDb::OrthographicView orthoUcs, const OdDbDatabase* pDb = 0) const = 0;
  
  /** Description:
    Returns the Object ID of the UCS name associated with the specified Viewport object. 
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual OdDbObjectId ucsName(const OdRxObject* pViewport) const = 0;

  /** Arguments:
    ucsId (I) Object ID of UCS.
  */
  virtual bool setUcs(OdRxObject* pViewport, const OdDbObjectId& ucsId) const = 0;

  /** Description:
    Returns the UCS associated with the specified Viewport object. 
    Arguments:
    origin (O) Receives the UCS *origin*.
    xAxis (O) Receives the UCS X-axis.
    yAxis (O) Receives the UCS Y-axis.
  */
  virtual void getUcs(const OdRxObject* pViewport, OdGePoint3d& origin, OdGeVector3d& xAxis, OdGeVector3d& yAxis) const = 0;

  /** Arguments:
    origin (I) The UCS *origin*.
    xAxis (I) The UCS X-axis.
    yAxis (I) The UCS Y-axis.
  */
  virtual void setUcs(OdRxObject* pViewport, const OdGePoint3d& origin, const OdGeVector3d& xAxis, const OdGeVector3d& yAxis) const = 0;

  /** Description:
    Returns the *elevation* for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
  */
  virtual double elevation(const OdRxObject* pViewport) const = 0;

  /** Description:
    Sets the *elevation* for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    elevation (I) Elevation.
  */
  virtual void setElevation(OdRxObject* pViewport, double elevation) const = 0;
  /** Arguments:
    pSourceView (I) Pointer to the source Viewport object.
    pDestinationView (I) Pointer to the destination Viewport object
  */
  virtual void setUcs(OdRxObject* pDestinationView, const OdRxObject* pSourceView) const;

  // Util methods:

  /** Description:
    Returns the eye coordinate system *extents* of the specified Viewport object.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    extents (O) Receives the *extents*.

    Remarks:
    Returns true if and only if the *extents* are defined.

    Note:
    The components of extents are clipped to the range [-10e100..10e100].
    See Also:
    Coordinate Systems
  */
  virtual bool viewExtents(
    const OdRxObject* pViewport, 
    OdGeBoundBlock3d& extents) const = 0;

  /** Description:
    Modifies the specified Viewport object to fit the specified eye coordinate system *extents*.
    
    Arguments:
    pViewport (I) Pointer to the Viewport object.
    pExtents (I) Pointer to the *extents*.
    extCoef (I) Optional extents multiplier.

    Remarks:
    Returns true if and only if the *extents* are defined.

    Remarks:
    If pExtents is null, this function calls viewExtents() to determine the *extents*.
  */
  virtual bool zoomExtents(
    OdRxObject* pViewport, 
    const OdGeBoundBlock3d* pExtents = 0,
    double extCoef = 1.02) const;

  /** Description:
    Returns the transformation matrix from WCS to EyeSpace for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.

    See Also:
    Coordinate Systems
  */
  virtual OdGeMatrix3d worldToEye(const OdRxObject* pViewport) const;
  /** Description:
    Returns the transformation matrix from EyeSpace to WCS for the specified Viewport object.
    Arguments:
    pViewport (I) Pointer to the Viewport object.

    See Also:
    Coordinate Systems
  */
  virtual OdGeMatrix3d eyeToWorld(const OdRxObject* pViewport) const;
  /** \details
    Returns compatible visual style or background object for specified viewport.
    \param pViewport [in]  Pointer to the Viewport object.
    \param pCopyObject [in]  Input object ID.
    \returns Returns comptaible objectID or null in case if there is no any compatible objects found.
  */
  virtual OdDbStub* compatibleCopyObject(const OdRxObject* pViewport, OdDbStub* pCopyObject) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdAbstractViewPE object pointers.
*/
typedef OdSmartPtr<OdAbstractViewPE> OdAbstractViewPEPtr;

#include "TD_PackPop.h"

#endif // OD_ABSTRACTVIEWPE_H

