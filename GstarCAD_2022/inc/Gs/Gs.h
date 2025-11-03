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

#ifndef __GS_H_INCLUDED_
#define __GS_H_INCLUDED_


#include "../RxObject.h"
#include "../RxIterator.h"
#include "../Gs/GsExport.h"

class OdGiDrawable;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiDrawable object pointers. 
*/
typedef OdSmartPtr<OdGiDrawable> OdGiDrawablePtr;

class OdGeMatrix3d;
class OdGePoint3d;
class OdGeVector3d;
class OdGePoint2d;
class OdDbHostAppServices;
class OdGiEdgeData;
class OdGiFaceData;
class OdGiVertexData;
class OdGiVertexData;
class OdDbDatabase;
class OdDbObjectId;
class OdDbStub;
class OdDbViewport;
class OdGeExtents3d;
class OdGiVisualStyle;
struct OdGiClipBoundary;
class OdGiAbstractClipBoundary;
class OdGsClassFactory;

#include "../OdPlatform.h"
#include "../RxModule.h"
#include "../IntArray.h"
#include "GsDCPointArray.h"
#include "../Ge/GePoint2dArray.h"

#include "../TD_PackPush.h"

class OdGsSelectionReactor;

class OdGsView;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGsView object pointers. 
*/
typedef OdSmartPtr<OdGsView> OdGsViewPtr;

class OdGsModel;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGsModel object pointers. 
*/
typedef OdSmartPtr<OdGsModel> OdGsModelPtr;

class OdGsDevice;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGsDevice object pointers. 
*/
typedef OdSmartPtr<OdGsDevice> OdGsDevicePtr;

class OdRxDictionary;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxDictionary object pointers. 
*/
typedef OdSmartPtr<OdRxDictionary> OdRxDictionaryPtr;

class OdGsReactor;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGsReactor object pointers. 
*/
typedef OdSmartPtr<OdGsReactor> OdGsReactorPtr;

#include "GsDefs.h"

class OdGiContext;
struct OdGsClientViewInfo;

#include "../Gi/GiExport.h"

/** Description:
    This class is the abstract base class for classes that implement Viewport objects in GUI *display* windows.

    Remarks:
    Each Viewport objects consists of a collection of objects to be viewed, and camera parameters that define the view.
    
    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT OdGsView : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGsView);
  
  enum RenderMode
  {
    kBoundingBox                  = -1,     // Bounding box. For internal use only.
    k2DOptimized                  = 0,      // Standard *display*. Optimized for 2D.
    kWireframe                    = 1,      // Standard *display*. Uses 3D pipeline.
    kHiddenLine                   = 2,      // Wireframe *display*. Hidden lines removed.
    kFlatShaded                   = 3,      // Faceted *display*. One *color* per face.
    kGouraudShaded                = 4,      // Smooth shaded *display*. Colors interpolated between *vertices*.
    kFlatShadedWithWireframe      = 5,      // Faceted *display* with wireframe overlay.
    kGouraudShadedWithWireframe   = 6,      // Smooth shaded *display* with wireframe overlay.
    kCount,
    kNone = kCount
  };

  enum Projection
  {
    kParallel     = 0,
    kPerspective  = 1
  };

  enum SelectionMode
  {
    kWindow       = 0,
    kCrossing     = 1,
    kFence        = 2,
    kWPoly        = 3,
    kCPoly        = 4,

    kPoint        = 16
  };

  enum DefaultLightingType
  {
    kOneLight = 0,
    kTwoLights,
    kBackLight
  };

  virtual ~OdGsView(void) { }
  /** Description:
    Returns the GsDevice object associated with this Viewport object.
  */
  virtual OdGsDevice* device() const = 0;

  /** Description:
    Returns the GiContext object associated with this Viewport object.
  */
  virtual OdGiContext* userGiContext() const = 0;

  /** Description:
    Sets the User Context object associated with this Viewport object.
    Arguments:
    pUserGiContext (I) Pointer to the User Context.
  */
  virtual void setUserGiContext(OdGiContext* pUserGiContext) = 0;

  /** Description:
    Returns the *scale* factor for displaying Lineweights in this Viewport object.
  */
  virtual double lineweightToDcScale() const = 0;
  /** Description:
    Sets the *scale* factor for displaying Lineweights in this Viewport object.
    Arguments:
    scale (I) Scale factor.
  */
  virtual void setLineweightToDcScale(double scale) = 0;

  /** Description:
    Sets the *lineweights* for this Viewport object.
    Arguments:
    numLineweights (I) Number of Lineweights.
    lineweights (I) Array of Lineweights.
  */
  virtual void setLineweightEnum(int numLineweights, const OdUInt8* lineweights) = 0;

  /** Description:
    Sets the size and *position* of this Viewport object.
    Arguments:
    lowerLeft (I) Lower-left corner in nomalized *device* coordinates [0.0 .. 1.0].
    upperRight (I) Upper-right corner in nomalized *device* coordinates [0.0 .. 1.0].
    screenRect (I) Screen rectangle in *device* coordinates (pixels).
    
    Remarks:
    (0,0) is the lower-left corner of the owning Device object. Coordinates increase upward and to the right.
    
    Note:
    The View object can be partly or completely off screen.    
  */
  virtual void setViewport(const OdGePoint2d& lowerLeft, const OdGePoint2d& upperRight) = 0;
  virtual void setViewport(const OdGsDCRect& screenRect) = 0;
  virtual void setViewport(const OdGsDCRectDouble& screenRect);

  /** Description:
    Returns the size and *position* of this Viewport object.
    Arguments:
    lowerLeft (O) Receives the lower-left corner in nomalized *device* coordinates [0.0 .. 1.0].
    upperRight (O) Receives the upper-right corner in nomalized *device* coordinates [0.0 .. 1.0].
    screenRect (O) Receives the screen rectangle in *device* coordinates (pixels).
    
    Remarks:
    (0,0) is the lower-left corner of the owning Device object.  Coordinates increase upward and to the right.
    
    Note:
    The View object may be partly or completely off screen.    
  */
  virtual void getViewport(OdGePoint2d& lowerLeft, OdGePoint2d& upperRight) const = 0;
  virtual void getViewport(OdGsDCRect& screenRect) const = 0;
  virtual void getViewport(OdGsDCRectDouble& screenRect) const;

  /** Description:
    Defines a polygonal clip region for this Viewport object.
    
    Arguments:
    numCoutours (I) Number of polygonal contours.
    numVertices (I) Array of the number of *vertices* in each polygonal contour.
    vertices (I) Array of *device* coordinate (pixel) *vertices* defining the polygonal contours.
  */
  virtual void setViewportClipRegion(int numContours, int const* numVertices, OdGsDCPoint const* vertices) = 0;
  virtual void setViewportClipRegion(int numContours, int const* numVertices, OdGePoint2d const* vertices) = 0;

  /** Description:
    Returns a polygonal clip region for this Viewport object.
    
    Arguments:
    counts (O) Array of the number of *vertices* in each polygonal contour.
    vertices (O) Array of *device* coordinate (pixel) *vertices* defining the polygonal contours.
  */
  virtual void viewportClipRegion(OdIntArray& counts, OdGsDCPointArray& vertices) const = 0;
  virtual void viewportClipRegion(OdIntArray& counts, OdGePoint2dArray& vertices) const = 0;

  /** Description:
    Removes the polygonal clip region for this Viewport object.
  */
  void removeViewportClipRegion();

  /** Description:
    Defines the 3d clipping for this Viewport object.

    Arguments:
    pBoundary (I) 3d clipping boundary.
    pClipInfo (I) Optional 3d clipping boundary extended data.
  */
  virtual void setViewport3dClipping(const OdGiClipBoundary* pBoundary, const OdGiAbstractClipBoundary* pClipInfo = NULL);

  /** Description:
    Returns the current 3d clipping for this Viewport object.

    Arguments:
    ppClipInfo (O) Optional 3d clipping boundary extended data.

    Note:
    Returns null if 3d clipping boundary doesn't set.
  */
  virtual const OdGiClipBoundary *viewport3dClipping(const OdGiAbstractClipBoundary** ppClipInfo = NULL) const;

  /** Description:
    Removes the 3d clipping from this Viewport object.
  */
  void removeViewport3dClipping();

  /** Description:
    Sets the *color* and *width* of the border for this Viewport object.
    Arguments:
    color (I) Border *color*.
    width (I) Border *width* in pixels.
  */
  virtual void setViewportBorderProperties(ODCOLORREF color, int width) = 0;

  /** Description:
    Returns the *color* and *width* of the border for this Viewport object.
    Arguments:
    color (O) Receives the border *color*.
    width (O) Receives the border *width* in pixels.
  */
  virtual void getViewportBorderProperties(ODCOLORREF& color, int& width) const = 0;

  void setViewportBorderProperties(const OdGsColor& color, int width);
  void getViewportBorderProperties(OdGsColor& color, int &width) const;
  
  /** Description:
    Controls the border visibility for this Viewport object.
    Arguments:
    visible (I) Controls visibility.
  */
  virtual void setViewportBorderVisibility(bool visible) = 0;

  /** Description:
    Returns true if and  only if the border is visible for this Viewport object.
  */
  virtual bool isViewportBorderVisible() const = 0;

  /** Description:
    Sets the camera parameters for this Viewport object.
    
    Arguments:
    position (I) Camera *position*.
    target (I) Camera *target*.
    upVector (I) Camera up vector.
    fieldWidth (I) *Projection* plane (field) width.
    fieldHeight (I) *Projection* plane (field) height.
    projectionType (I) *Projection* *type*.
    
    Remarks:
    All parameters are in WCS coordinates.

    projectionType must be one of the following:
    
    @table
    Name           Value
    kParallel      0
    kPerspective   1
    
    Note:    
    This method defines the transfomation from WCS coordinates to normalized *device* coordinates.
  */
  virtual void setView(
    const OdGePoint3d& position,
    const OdGePoint3d& target,
    const OdGeVector3d& upVector,
    double fieldWidth,
    double fieldHeight,
    Projection projectionType = kParallel) = 0;

  /** Description:
    Returns the WCS camera *position* for this Viewport object.
  */
  virtual OdGePoint3d position() const = 0;

  /** Description:
    Returns the WCS camera *target* for this Viewport object.
  */
  virtual OdGePoint3d target() const = 0;
  /** Description:
    Returns the WCS camera up vector for this Viewport object.
  */
  virtual OdGeVector3d upVector() const = 0;

  /** Description:
    Returns the perspective lens length for this Viewport object.
  */
  virtual double lensLength() const = 0;

  /** Description:
    Sets the perspective lens length for this Viewport object.
    Arguments:
    lensLength (I) Perspective lens length.
  */
  virtual void setLensLength(double lensLength) = 0;

  /** Description:
    Returns true if and only if the *projection* type for this Viewport object is kPerspective. 
  */
  virtual bool isPerspective() const = 0;

  /** Description:
    Returns the WCS projection plane (field) width for this Viewport object.
  */
  virtual double fieldWidth() const = 0;
  /** Description:
    Returns the WCS projection plane (field) height for this Viewport object.
  */
  virtual double fieldHeight() const = 0;
  
  virtual void setFieldWidth (double fw) = 0; 
  virtual void setFieldHeight(double fh) = 0;
  virtual void setViewCenter(const OdGePoint2d &ct) = 0;	

  /** Description:
    Controls the front clipping of this Viewport object.
    Arguments:
    enable (I) Enable front clipping.
  */
  virtual void setEnableFrontClip(bool enable) = 0;

  /** Description:
    Returns true if and only if front clipping is enabled for this Viewport object.
  */
  virtual bool isFrontClipped() const = 0;

  /** Description:
    Sets the front clip *distance* from the *target* of this Viewport object.
    Arguments:
    frontClip (I) Front clip *distance*.
  */
  virtual void setFrontClip(double frontClip) = 0;

  /** Description:
    Returns the front clip *distance* from the *target* of this Viewport object.
  */
  virtual double frontClip() const = 0;

  /** Description:
    Controls the back clipping of this Viewport object.
    Arguments:
    enable (I) Enable back clipping.
  */
  virtual void setEnableBackClip(bool enable) = 0;

  /** Description:
    Returns true if and only if back clipping is enabled for this Viewport object.
  */
  virtual bool isBackClipped() const = 0;

  /** Description:
    Sets the back clip *distance* from the *target* of this Viewport object.
    Arguments:
    backClip (I) Back clip *distance*.
  */
  virtual void setBackClip(double backClip) = 0;
  /** Description:
    Returns the back clip *distance* from the *target* of this Viewport object.
  */
  virtual double backClip() const = 0;

  /** Description:
      Returns the matrix that transforms world space to view space for this Viewport object.

      See Also:
      Coordinate Systems.
  */
  virtual OdGeMatrix3d viewingMatrix() const = 0;

  /** Description: 
      Returns the matrix that transforms view space to normalized *device* space for this Viewport object.

      See Also:
      Coordinate Systems.
  */
  virtual OdGeMatrix3d projectionMatrix() const = 0;

  /** Description: 
      Returns the matrix that transforms normalized *device* space to screen space for this Viewport object.

      See Also:
      Coordinate Systems.
  */
  virtual OdGeMatrix3d screenMatrixWin() const = 0;
  virtual OdGeMatrix3d screenMatrix() const;

  /** Description: 
      Returns a matrix that transforms coordinates from world space to screen space for this Viewport object. 
      
      Remarks:
      This is equivalent to the concatenation of the viewingMatrix, 
      projectionMatrix, and screenMatrixWin.

      See Also:
      Coordinate Systems.
  */
  virtual OdGeMatrix3d worldToDeviceMatrixWin() const = 0;
  virtual OdGeMatrix3d worldToDeviceMatrix() const;

  /** Description: 
      Returns the matrix that transforms coordinates from model space to screen space for this Viewport object.

      See Also:
      Coordinate Systems.
  */
  virtual OdGeMatrix3d objectToDeviceMatrix() const = 0;

  /** Description:
    Sets the render *mode* for this Viewport object.
    
    Arguments:
    mode (I) Render *mode*.
    
    Remarks:
    mode must be one of the following:
    
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
  virtual void setMode(RenderMode mode) = 0;

  /** Description:
    Sets the render *mode* for this Viewport object.
    
    Remarks:
    mode must be one of the following:
    
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
  virtual RenderMode mode() const = 0;

  /** Description:
    Adds the specified scene graph to this Viewport object.
    
    Arguments:
    pSceneGraph (I) Pointer to the root of the scene graph.
    pModel (I) Pointer to the Model object to which all scene graph notifications are to be directed.
    
    Remarks:
    This function is intended to be used as follows:
    
    1.  Construct a scene graph of OdGiDrawable objects. 
        Each object draws its children with OdGiGeometry::draw().
    
    2.  With this function, add the root of the scene graph and the 
        OdGsModel that handles notifications to this Viewport object.
  */
  virtual bool add(OdGiDrawable* pSceneGraph, OdGsModel* pModel) = 0;

  /** Description:
    Removes the specified scene graph from this Viewport object.
    
    Arguments:
    sceneGraph (I) Pointer to the root of the scene graph.
  */
  virtual bool erase(OdGiDrawable* sceneGraph) = 0;
  /** Description:
    Removes all scene graphs from this Viewport object.
    
    Arguments:
    sceneGraph (I) Root of scene graph.
  */
  virtual void eraseAll() = 0;

   /** Description:
    Marks for refresh the specified region of this Viewport object.
     
    Arguments:
    screenRect (I) Screen rectangle in *device* coordinates (pixels).
    
    Remarks:
    If screenRect is not specified, the entire area of this View is marked for refresh.
  */
  virtual void invalidate() = 0;
  virtual void invalidate(const OdGsDCRect &screenRect)= 0;

  /** Description:
    Returns true if and only if this Viewport object is showing the correct image.

    Remarks:
    This implies the follow:
    
    o  No part of GUI area is flagged for refresh.
    o  All rasterizations are complete
    o  The rendering pipeline *has* been flushed.
  */
  virtual bool isValid() const = 0;

  /** Description:
    Flushes any queued graphics to the *display* *device*.
    
    Remarks:
    If called while this Viewport object is in the interactive state, this function immediately returns.
  */
  virtual void update() = 0;

  /** Description:
    Puts this Viewport object into interactive state.
    
    Arguments:
    frameRateInHz (I) Frames/second.
    
    Remarks:
    A frame rate of 0.0 specifies the default frame rate.
  */
  virtual void beginInteractivity(double frameRateInHz) = 0;
  /** Description:
    Removes this Viewport object from the interactive state.
    Arguments:
    frameRateInHz (I) Frames/second.
  */
  virtual void endInteractivity() = 0;
  /** Description:
    Flushes the graphic pipeline and renders this Viewport object.
    
    Note:
    This function should be called only during interactivty. 
  */
  virtual void flush() = 0;

  virtual void  setMaximumUpgrade(int step)
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual int  maximumUpgrade(void)
  {
    throw OdError(OdResult::eNotImplemented);
    return -1;
  }
  virtual void  setMinimumDegrade(int step)
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual int   minimumDegrade(void)
  {
    throw OdError(OdResult::eNotImplemented);
    return -1;
  }


  /** Description:
    Hides this Viewport object.
  */
  virtual void hide() = 0;

  /** Description:
    Un-hides this Viewport object.
  */
  virtual void show() = 0;

  /** Description:
    Returns true if and only if this Viewport object is not hidden.
  */
  virtual bool isVisible() = 0;

  /** Description:
    Freezes the specified Layer object in this Viewport object.
    Arguments:
    layerID (I) Layer to freeze.
    Remarks:
    All layers are thawed by default.
  */
  virtual void freezeLayer(LONG_PTR layerID) = 0;
  
  /** Description:
    Thaws the specified Layer object in this Viewport object.
    Arguments:
    layerID (I) Layer to thaw.
    Remarks:
    All layers are thawed by default.
  */
  virtual void thawLayer(LONG_PTR layerID) = 0;

  /** Description:
    Thaws all Layer objects in this Viewport object.
    Remarks:
    All layers are thawed by default.
  */
  virtual void clearFrozenLayers() = 0;

  /** Description:
    Marks for regeneration all subViewportDraw() *geometry* for this Viewport object.
  */
  virtual void invalidateCachedViewportGeometry() = 0;

  virtual void select(const OdGsDCPoint* pts, int nPoints,
    OdGsSelectionReactor* pReactor,
    SelectionMode mode = kCrossing) = 0;

  virtual void select(const OdGePoint3d* wcspts, int nPoints,
    OdGsSelectionReactor* pReactor,
    SelectionMode mode = kCrossing) = 0;

  /** Description:
    Translates the camera *position* and *target* by the specified Camera Coordinate *dolly* amount.
     
    Arguments:
    dollyVector (I) Camera Coordinate dolly vector.
    xDolly (I) Camera Coordinate X dolly amount.
    yDolly (I) Camera Coordinate Y dolly amount.
    zDolly (I) Camera Coordinate Z dolly amount.
     
    Remarks:
    Camera Coordinates are relative to the view of a *target* from a camera. 
    
    o  The Y-axis is along up vector. 
    o  The Z-axis is along the vector from camera postiton to the *target*. 
    o  The X-axis is the cross product Y-axis ?Z-axis 
  */  
  virtual void dolly(const OdGeVector3d& dollyVector) = 0;
  virtual void dolly(double xDolly, double yDolly, double zDolly) = 0;

  /** Description:
    Rotates the camera by the specified amount about the eye vector.
     
    Arguments:
    rollAngle (I) Camera CCW roll angle.
     
    Remarks:
    Positive angles rotate the camera counterclockwise about the eye vector
    when viewed from the camera *position* to the *target*. This corresponds
    to a clockwise rotation of the up vector.
    
    Note:
    Camera Coordinates are relative to the view of a *target* from a camera. 
    
    o  The Y-axis is along up-vector. 
    o  The Z-axis (eye vector) is along the vector from camera postiton to the *target*. 
    o  The X-axis is the cross product Y-axis ?Z-axis.
    
    All angles are expressed in radians.
  */  
  virtual void roll(double rollAngle) = 0;

  /** Description:
    Orbits the camera about the *target* by the specified amounts.
     
    Arguments:
    xOrbit (I) X-axis Orbit.
    yOrbit (I) Y-axis Orbit.
     
    Remarks:
    he camera moves on the surface a sphere whose center the camera *target* and whose
    radius is the distance from the camera *position* to its *target* 
    
    o  The camera is first rotated about an axis parallel to the X-axis and passing through the *target*.  
    o  The camera is next rotated about an axis parallel to the Y-axis and passing through the *target*  
    
    Note:
    Camera Coordinates are relative to the view of a *target* from a camera. 
    
    o  The Y-axis is along up vector. 
    o  The Z-axis is along the vector from camera postiton to the *target*. 
    o  The X-axis is the cross product Y-axis ?Z-axis 

    All angles are expressed in radians.
  */  
  virtual void orbit(double xOrbit, double yOrbit) = 0;

  /** Description:
    Scales the focal length of the camera by the specified amount.
     
    Arguments:
    zoomFactor (I) Zoom factor.
     
  */  
  virtual void zoom(double zoomFactor) = 0;
  virtual void zoomExtents(const OdGePoint3d& minPoint, const OdGePoint3d& maxPoint) = 0;
  virtual void zoomWindow(const OdGePoint2d& lowerLeft,const OdGePoint2d& upperRight) = 0;
  virtual void zoomScreenWindow(const OdGePoint2d& upLeft,const OdGePoint2d& bottomRight) = 0;

  /** Description:
    Rotates the *target* abount the camera the specified amounts.
     
    Arguments:
    xPan (I) X-axis pan.
    yPan (I) Y-axis pan.
     
    Remarks:
    The *target* moves on the surface a sphere whose center the camera *position* and whose
    radius is the distance from the camera *position* to its *target* 
    
    o  The *target* is first rotated about an axis parallel to the X-axis and passing through the camera.  
    o  The *target* is next rotated about an axis parallel to the Y-axis and passing through the camera.  
    
    Note:
    Camera Coordinates are relative to the view of a *target* from a camera. 
    
    o  The Y-axis is along up vector. 
    o  The Z-axis is along the vector from camera postiton to the *target*. 
    o  The X-axis is the cross product Y-axis ?Z-axis 
    All angles are expressed in radians.
  */  
  virtual void pan(double xPan, double yPan) = 0;

  virtual bool pointInView(const OdGePoint3d& pnt)
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
  virtual bool extentsInView(const OdGePoint3d& minPoint, const OdGePoint3d& maxPoint)
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
  /** Description:
    Clones this Viewport object.

    Arguments:
    cloneViewParameters (I) If and only if true, view parameters will be cloned.
    cloneGeometry (I) If and only if true, *geometry* will be cloned.
    
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdGsViewPtr cloneView(bool cloneViewParameters = true, bool cloneGeometry = false) = 0;

  /** Description:
    Sets the view parameters of the specified OdGsView object to that of this Viewport object.
    Arguments:
    pView (O) Receives the view parameters.
  */
  virtual void viewParameters(OdGsView* pView) const = 0;

  /** Description:
    Returns true if an only if any view parameters have exceeded their boundaries since the last
    call to this function.
    
    Remarks:
    The following calls are monitored:
    
    o  dolly()
    o  orbit()
    o  pan() 
    o  roll()
    o  setBackClip()
    o  setFrontClip()
    o  setView()
    o  zoom()
  */
  virtual bool exceededBounds() = 0;

  /** Description:
    Controls stereo viewing for this Viewport object.
    
    Arguments:
    enable (I) Controls stereo viewing.
  */
  virtual void enableStereo(bool enabled) = 0;

  /** Description:
    Returns true if and only if stereo viewing is enabled for this Viewport object.
  */
  virtual bool isStereoEnabled() const = 0;

  /** Description:
    Sets the stereo parameters for this Viewport Object.
    Arguments:
    magnitude (I) View separation [0.0 .. 2.0].
    parallax (I) Adjusts the plane of zero *parallax* [0.0 .. 2.0].
    
    Remarks:
    magnitude controls view eye separation, and hence the stereo effect.
    
    o  A *magnitude* of 1.0 is the default value.
    o  A *magnitude* of 0.0 produces no stereo effect.
    o  A *magnitude* of 2.0 produces a double stereo effect.
    
    parallax adjusts the zero *parallax* plane.
    
    o  A *parallax* of 1.0 is the default value. An object centered at the *target* will be half-in and half-out of the screen.
    o  A *parallax* of 0.0 moves the object into the screen.
    o  A *parallax* of 2.0 move the object out of the screen.
    
  */ 
  virtual void setStereoParameters(double magnitude, double parallax) = 0;

  /** Description:
    Returns the stereo parameters for this Viewport Object.
    Arguments:
    magnitude (O) Receives the view separation [0.0 .. 2.0].
    parallax (O) Receives the plane of zero *parallax* adjustment [0.0 .. 2.0].
    
    Remarks:
    magnitude controls view eye separation, and hence the stereo effect.
    
    o  A *magnitude* of 1.0 is the default value.
    o  A *magnitude* of 0.0 produces no stereo effect.
    o  A *magnitude* of 2.0 produces a double stereo effect.
    
    parallax adjusts the zero *parallax* plane.
    
    o  A *parallax* of 1.0 is the default value. An object centered at the *target* will be half-in and half-out of the screen.
    o  A *parallax* of 0.0 moves the object into the screen.
    o  A *parallax* of 2.0 move the object out of the screen.
    
  */ 
  virtual void getStereoParameters(double& magnitude, double& parallax) const = 0;

  virtual OdGsDevice * getDevice(void) const
  {
    throw OdError(OdResult::eNotImplemented);
    return NULL;
  }

  /** Description:
    Returns an iterator to traverse the lights attached to this Viewport object.
    Arguments:
    pLightsIterator (I) Pointer to the lights iterator.
  */
  virtual void initLights(OdRxIterator* pLightsIterator) = 0;

  /** Description:
    Sets a multiplier that is used to scale all linetypes in this Viewport object.
    
    Arguments:
    linetypeScaleMultiplier (I) Linetype scale multiplier.
  */
  virtual void setLinetypeScaleMultiplier(double linetypeScaleMultiplier) = 0;

  /** Description:
    Sets a multiplier that coul be used as an alternate scale factor for linetypes in this Viewport object.
    
    Arguments:
    linetypeAlternateScaleMultiplier (I) Alternate linetype scale multiplier.
  */
  virtual void setAlternateLinetypeScaleMultiplier(double linetypeAlternateScaleMultiplier) = 0;

  virtual double linetypeScaleMultiplier() const { return 1.; }

  /** Description:
    Returns the ClientViewInfo for this Viewport object.
    
    Arguments:
    clientViewInfo (O) Receives the ClientViewInfo.
  */
  virtual void clientViewInfo(OdGsClientViewInfo& clientViewInfo) const;

  enum ClearColor
  {
    kTransparent,
    kDeviceBackground,
    kPaletteBackground
  };

  /** Description:
    Sets the clear color for this view

    Arguments:
    color (I) The clear color.
  */
  virtual void setClearColor(ClearColor color) = 0;

  virtual bool pointInViewport(const OdGePoint2d& screenPoint) const = 0;

  virtual void getNumPixelsInUnitSquare(const OdGePoint3d& point,
                                        OdGePoint2d& pixelDensity, bool bUsePerspective = true) const = 0;

  virtual void setBackground(OdDbStub *backgroundId) = 0;
  virtual OdDbStub *background() const = 0;

  virtual void setVisualStyle(OdDbStub *visualStyleId) = 0;
  virtual OdDbStub *visualStyle() const = 0;
  virtual void setVisualStyle(const OdGiVisualStyle &visualStyle) = 0;
  virtual bool visualStyle(OdGiVisualStyle &visualStyle) const = 0;
  /** \details
    Enables default lighting for this view.

    \param bEnable [in]  New default lighting state.
    \param lightType [in]  New default lighting type.
  */
  virtual void enableDefaultLighting(bool bEnable, DefaultLightingType lightType = kTwoLights) = 0;
};

/** Description:
    This stucture contains the Window ID and Viewport Object ID.
    
    Library: TD_Gs

    {group:Structs}
*/
struct OdGsClientViewInfo 
{
  enum ViewportFlags
  {
    kDependentViewport = 1,
    kDependentGeometry = 2,
    kHelperView        = 4
  };

  long      viewportId;        // Returned by OdGiViewport::viewportId()
  long      acadWindowId;      // Returned by OdGiViewport::acadWindowId()
  OdDbStub* viewportObjectId;  // Returned by OdGiViewportDraw::viewportObjectId()
  OdUInt32  viewportFlags;     // Optional view flags

  OdGsClientViewInfo()
    : viewportId(-1)
    , acadWindowId(0)
    , viewportObjectId(NULL)
    , viewportFlags(0)
  {
  }
};

class OdGiContext;

/** Description:
    This class is the abstract base class for classes that encapsulate GUI *display* windows.

    Remarks:
    OdGsDevice objects own, *update*, and refresh one or more OdGsView objects.
    
    In addition, they responds to operating system notifications,
    such as window resize, forwarded by the graphics system client.

    Library: TD_Gs
        
    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT OdGsDevice : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGsDevice);

  virtual ~OdGsDevice(void) { }

  /** Description:
    Returns a SmartPointer to the dictionary containing the
    *properties* for this Device object.
  */
  virtual OdRxDictionaryPtr properties() = 0;

  /** Description:
    Returns the User Context object associated with this Device object.
  */
  virtual OdGiContext* userGiContext() const = 0;

  /** Description:
    Sets the User Context object associated with this Device object.
    Arguments:
    pUserGiContext (I) Pointer to the User Context.
  */
  virtual void setUserGiContext(OdGiContext* pUserGiContext) = 0;

  /** Description:
    Marks for refresh the specified region of the GUI window of this Device object.
     
    Arguments:
    screenRect (I) Rectangular area.
    
    Remarks:
    If screenRect is not specified, the entire GUI window is marked for refresh.
  */
  virtual void invalidate() = 0;

  virtual void invalidate(const OdGsDCRect &screenRect) = 0;

  /** Description:
    Returns true if and only if the GUI window for this Device object is showing the correct image.

    Remarks:
    This implies the follow:
    
    o  No part of GUI area is flagged for refresh.
    o  All rasterizations are complete
    o  The rendering pipeline *has* been flushed.
  */
  virtual bool isValid() const = 0;

  /** Description:
    Updates the GUI window for this Device object.
    
    Arguments:
    pUpdatedRect (O) Pointer to the a rectangle to receive the region updated by this function.

    Note:    
    This function call is propagated to all OdGsView objects owned by this Device object,
    thus displaying the correct image on the GUI window of this Device object.
  */
  virtual void update(OdGsDCRect* pUpdatedRect = 0) = 0;

  /** Description:
    Notification function called whenever the size of the GUI window for this Device object *has* changed.
    
    Arguments:
    outputRect (I) New size of the *output* rectangle in *device* coordinates (pixels).

    Note:
    This function should *not* be called if this Device object *has* a *width* and/or *height* of 0, .
  */
  virtual void onSize(const OdGsDCRect& outputRect) = 0;
  virtual void onSize(const OdGsDCRectDouble& outputRect);
  virtual void onSize(int x,int y);
  /** Description:
    
    Remarks:
    Causes this Device object to realize its foreground pallette.
 */  
  virtual void onRealizeForegroundPalette() = 0;

  /** Description:
    Notification function typically called whenever the GUI window for this Device object loses focus.
    
    Remarks:
    Causes this Device object to realize its background pallette.
 */  
  virtual void onRealizeBackgroundPalette() = 0;

  /** Description:
    Notification function called whenever the OS screen resolution and/or *color* depth have changed.
    
    Arguments:
    bitsPerPixel (I) Color depth.
    xPixels (I) X pixels.
    yPixels (I) Y pixels.
  
    Remarks:
    This function is called after the operation.  
  */
  virtual void onDisplayChange(int bitsPerPixel, int xPixels, int yPixels) = 0;

  /** Description:
    Creates a new OdGsView object, and associates it with this Device object.
    
    Arguments:
    pViewInfo (I) Pointer to the Client View Information for this Device object.
    enableLayerVisibilityPerView (I) Layer visibility per viewport is supported, if and only if true.
    
    Remarks:
    Returns a SmartPointer to the newly created object.

    pViewInfo contains information returned by OdGiViewport::acadWindowId() and OdGiViewportDraw::viewportObjectId()
  */
  virtual OdGsViewPtr createView(
    const OdGsClientViewInfo* pViewInfo = 0, 
    bool enableLayerVisibilityPerView = false) = 0;

  /** Description:
    Associates the specified Viewport object with this Device object.
    
    Arguments:
    pView (I) Pointer to the OdGsView object.
  */
  /*/DD2ARX - xi hui - 2008-06-24 - OdGsDevice::add
  virtual void addView(
    OdGsView* pView) = 0;
  /*/
  virtual bool add(
    OdGsView* pView) = 0;
  //*/
  
  /** Description:
    Creates a new OdGsModel object, and associates it with this Device object.
    
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdGsModelPtr createModel() = 0;

  /** Description:
    Checks compatibility between specified OdGsModel and this Device object.

    Arguments:
    pModel (I) Model object pointer to check compatibility.

    Remarks:
    Use this method to check compatibility of exist Model object and newly created device
    to be sure the exist Model object could be used with this Device object.

    By default this always returns false. It is must be implemented in inherited classes
    to enable Model object reuse support. If Device object use overriden Model object
    it should return false if input Model object doesn't overriden.

    Typical way to check compatibility is using of RTTI.

    If your metafiles cache doesn't support per-device sharing override and return false.
  */
  virtual bool isModelCompatible(OdGsModel* pModel) const;

  /** Description:
    Inserts the specified Viewport object to the specified position in this Device object.

    Arguments:
    viewIndex (I) View index.
    pView (I) Pointer to the OdGsView object.
  */
  virtual void insertView(int viewIndex, OdGsView* pView) = 0;

  /** Description:
    Erases the specified View object.
    Arguments:
    pView (I) Pointer to the OdGsView object.
    viewIndex (I) View index.
    Remarks:
    Returns true if and only if successful.
  */
  /*/DD2ARX - xi hui - 2008-06-24 - OdGsDevice::erase
  virtual bool eraseView(
    OdGsView* pView) = 0;
  /*/
  virtual bool erase(
    OdGsView* pView) = 0;
  //*/
  
  virtual bool eraseView(int viewIndex) = 0;

  /** Description:
    Erases all views associated with this Device object.
  */
  /*/DD2ARX - xi hui - 2008-06-24 - OdGsDevice::eraseAll
  virtual void eraseAllViews() = 0;
  /*/
  virtual void eraseAll() = 0;
  //*/
  
  /** Description:
    Returns the number of views associated with this Device object.
  */
  virtual int numViews() const = 0;

  /** Description:
    Returns the specified OdGsView object associated with this Device object.
    Arguments:
    viewIndex (I) View index.
  */
  virtual OdGsView* viewAt(int viewIndex) = 0;

  /** Description:
    Sets the Background Color of the GUI window of this Device object.
    Arguments:
    backgroundColor (I) Background *color*.
  */
  virtual bool setBackgroundColor(ODCOLORREF backgroundColor) = 0;

  /** Description:
    Returns the Background Color of the GUI window of this Device object.
  */
  virtual ODCOLORREF getBackgroundColor() = 0;

  /** Description:
    Sets the logical pallete to be used by this Device object.
    
    Arguments:
    logicalPalette (I) Logical palette.
    numColors (I) Number of colors in palette.
    
    Remarks:
    The logical pallete is used with calls to OdGiSubEntityTraits::setColor().
  */
  virtual void setLogicalPalette(const ODCOLORREF* logicalPalette, int numColors) = 0;

  virtual void setPhysicalPalette(const OdGsColor* palette, int nCount);

  void setLogicalPalette(const OdGsColor* palette, int nCount);
  bool setBackgroundColor(OdGsColor color);
  //OdGsColor getBackgroundColor();  // OdGsColor::operator=
};

class OdGsModule;

/** Description:
    This class is the base class for custom classes that receive notification
    of OdGs events.
    
    Note:
    The default implementations of all methods in this class do nothing but return.

    Library:
    TD_Gs
  
    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT OdGsReactor : public OdRxObject
{
public:
  OdGsReactor(void) { }
  virtual  ~OdGsReactor(void) { }
  /** Description
    Notification function called whenever a OdGsView object *has* been created.
    Arguments:
    pView (I) Pointer to the OdGsView object.

    Remarks:
    This function is called after the operation.
  */
  virtual void viewWasCreated(OdGsView* pView);

  /** Description
    Notification function called whenever an OdGsView object is about to be destroyed.
    Arguments:
    pView (I) Pointer to the OdGsView object.

    Remarks:
    This function is called before the operation.
  */
  virtual void viewToBeDestroyed(OdGsView* pView);

  /** Description
    Notification function called whenever an OdGsModule object is about to be unloaded.
    Arguments:
    pModule (I) Pointer to the OdGsModule object.

    Remarks:
    This function is called after the operation.
  */
  virtual void gsToBeUnloaded(OdGsModule* pModule);

  virtual void  gsToBeUnloaded(OdGsClassFactory * pClassFactory)
  { 
    throw OdError(OdResult::eNotImplemented);
  }
  virtual void  configWasModified(void)
  {
    throw OdError(OdResult::eNotImplemented);
  }
};

/** Description:
    This class provides management of OdGsDevice classes.
    Library: TD_Gs 
    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT OdGsModule : public OdRxModule
{
public:
  ODRX_DECLARE_MEMBERS(OdGsModule);

  /** Description:
    Creates a new OdGsDevice object, and associates it with this Module object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdGsDevicePtr createDevice() = 0;

  /** Description:
    Creates a new OdGsBaseVectorizeDevice object, and associates it with this Module object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdGsDevicePtr createBitmapDevice();

  /** Description:
    Adds the specified *reactor* to this object's *reactor* list.
    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  virtual void addReactor(OdGsReactor* pReactor) = 0;

  /** Description:
    Removes the specified *reactor* from this object's *reactor* list.
    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  virtual void removeReactor(OdGsReactor* pReactor) = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGsModule object pointers. 
*/
typedef OdSmartPtr<OdGsModule> OdGsModulePtr;

#include "../TD_PackPop.h"

#endif // __GS_H_INCLUDED_
