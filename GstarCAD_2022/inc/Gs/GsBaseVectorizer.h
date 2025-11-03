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

#ifndef ODGSBASEVECTORIZER_INC
#define ODGSBASEVECTORIZER_INC

#include <stdlib.h>
#include <utility>

#include "../UInt8Array.h"
#include "../IntArray.h"
#include "../DbStubPtrArray.h"
#include "../SlotManager.h"

#include "../Ge/GeExtents3d.h"

#include "../Gi/GiDrawable.h"
#include "../Gi/GiBaseVectorizer.h"
#include "../Gi/GiStack.h"
#include "../Gi/GiExtAccum.h"
#include "../Gi/GiConveyorEmbranchment.h"
#include "../Gi/GiIndirectEntityAccessor.h"
#include "../Gi/GiLinetypeRedir.h"

#include "../Gs/GsExport.h"
#include "../Gs/GsModel.h"
#include "../Gs/Gs.h"
#include "../Gs/GsDCPointArray.h"
#include "../Gs/GsDCRectArray.h"
#include "../Gs/GsViewProps.h"
#include "../Gs/GsExtAccum.h"
#include "../Gs/GsProperties.h"
#include "../Gs/GsCullingVolume.h"
#include "../Gs/SiVolume.h"
#include "../Gs/GsLtypeRedir.h"
#include "../Gs/GsHighlightData.h"
#include "../Gs/GsMTContext.h"

#include "../Si/SiSpatialIndex.h"
#include "../Si/BBox.h"

#include "../Ps/PlotStyles.h"

#include "../Gi/GiAbstractClipBoundary.h"

#include "../TD_PackPush.h"

class OdGsViewImpl;
class OdGsBaseVectorizeDevice;
class OdGsNodeEx;

class OdGsContainerNode;
class OdGsBlockReferenceNode;
class OdGsBlockReferenceNodeImpl;
class OdGsPdfReferenceNode;
class OdGiSectionGeometry;

/** Description:
    This class provides management of bitmapped GUI display windows.

    Library: TD_Gs 
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBaseModule : public OdGsModule
{
  OdRxObjectPtrArray  m_reactors;
protected:
  /** Description:
    Notifies connected reactors that the specified OdGsView object was created.

    Arguments:
    pView (I) Pointer to the OdGsView object.
    Remarks:
    This function is called after the operation.
  */
  void fire_viewWasCreated(OdGsView* pView);

  /** Description:
    Notifies connected reactors that the specified OdGsModule object is about to be unloaded.

    Arguments:
    pModule (I) Pointer to the GsModule object.
    Remarks:
    This function is called before the operation.
  */
  void fire_gsToBeUnloaded(OdGsModule* pModule);

  /** Description:
    Creates a new OdGsBaseVectorizeDevice object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdSmartPtr<OdGsBaseVectorizeDevice> createDeviceObject() = 0;

  /** Description:
    Creates a new OdGsViewImpl object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdSmartPtr<OdGsViewImpl> createViewObject() = 0;

  /** Description:
    Creates a new OdGsBaseVectorizeDevice object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdSmartPtr<OdGsBaseVectorizeDevice> createBitmapDeviceObject() = 0;

  /** Description:
    Creates a new OdGsBaseVectorizeView object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  virtual OdSmartPtr<OdGsViewImpl> createBitmapViewObject() = 0;

  OdGsBaseModule();
  
  /** Description:
    Notification function called whenever this BaseModule object is about to be released.
  */
  void onFinalRelease();
public:
  ODRX_DECLARE_MEMBERS(OdGsBaseModule);

  /** Description:
    Notifies connected reactors that the specified View object is about to be created.
    
    Arguments:
    pView (I) Pointer to the OdGsView object.
    Remarks:
    This function is called before the operation.
  */
  void fire_viewToBeDestroyed(OdGsView* pView);

  /** Description:
    Creates a new OdGsDevice object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  OdGsDevicePtr createDevice();
  
  /** Description:
    Creates a new OdGsBaseVectorizeDevice object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  OdGsDevicePtr createBitmapDevice();

  /** Description:
    Creates a new OdGsViewImpl object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  OdSmartPtr<OdGsViewImpl> createView();

  /** Description:
    Creates a new OdGsBaseVectorizeView object, and associates it with this BaseModule object.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  OdSmartPtr<OdGsViewImpl> createBitmapView();

  /** Description:
    Adds the specified *reactor* to this object's *reactor* list.
    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  void addReactor(OdGsReactor* pReactor);

  /** Description:
    Removes the specified *reactor* from this object's *reactor* list.
    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  void removeReactor(OdGsReactor* pReactor);

  /** Description:
    Notification function called at the start of the client application.
    Remarks:
    The user override of this function should register any custom objects defined in the 
    custom application, using the OdRxObject::rxInit function.  It should also register
    custom commands defined in the module.
  */
  void initApp();

  /** Description:
    Notification function called at the end of the client application.
    Remarks:
    The user override of this function should unregister any custom objects defined in the
    custom application, using the OdRxObject::rxUninit function.  It should also
    remove any custom commands that were registered in the initApp function.
  */
  void uninitApp();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsBaseModule object pointers.
*/
typedef OdSmartPtr<OdGsBaseModule> OdGsBaseModulePtr;

/** Description:
    This template class is a specialization of the OdArray class for ODCOLORREF objects.
*/
typedef OdArray<ODCOLORREF, OdMemoryAllocator<ODCOLORREF> > ODGSPALETTE;

class OdGiSelectProc;
class OdGiConveyorGeometry;
class OdGsBaseVectorizeView;
class OdGsBaseModel;
class OdGiPointLightTraitsData;
class OdGiSpotLightTraitsData;
class OdGiDistantLightTraitsData;
class OdGiWebLightTraitsData;
class OdGiSectionGeometryManager;

/** Description:
    This class implements bitmapped GUI display windows.

    Remarks:
    OdGsBaseVectorizeDevice objects own, *update*, and refresh one or more OdGsView objects.
    
    In addition, they responds to operating system notifications,
    such as window resize, forwarded by the graphics system client.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBaseVectorizeDevice : public OdGsDevice
{
  friend class OdGsViewImpl;
  friend class OdGsBaseVectorizeView;
  friend class OdGsBaseModule;

protected:
  OdSlotManager           m_slotManager;

  OdSmartPtr<OdGiContext> m_pUserContext;
  OdGsBaseModulePtr       m_pModule;
  OdArray<OdGsViewPtr>    m_views;
  ODGSPALETTE             m_logPalette;
  ODCOLORREF              m_Background;
  OdGsDCRect              m_outputRect;
  OdRxObjectPtr           m_sectionGeometryMap;
  OdRxObjectPtr           m_sectionManager;

  OdUInt32                m_flags;
  enum
  {
    kFirstFlag            = 1,

    kInvalid              = kFirstFlag << 0,
    kSortRenderTypes      = kFirstFlag << 1,
    kSpatialIndexDisabled = kFirstFlag << 2,
    kDynamicHighlight     = kFirstFlag << 3,
    kDynamicSubhighlight  = kFirstFlag << 4,
    kPhotometricLights    = kFirstFlag << 5,
    kSupportBlocks        = kFirstFlag << 6,
    kSupportOverlays      = kFirstFlag << 7,
    kUseSectionGeometryMap= kFirstFlag << 8,

    kLastFlag             = kSupportOverlays
  };
  OdGsDCRectArray         m_invalidRects;
  OdUInt32                m_invalidOverlays;

  /*
  virtual int invalidatedRectNum(int& max) const;
  virtual void invalidatedRectAt(int i, OdGsDCRect& rect) const;
  virtual void setInvalidatedRectAt(int i, const OdGsDCRect& rect);
  virtual void eraseInvalidatedRectAt(int i);
  virtual void clearInvalidatedRects();
  */

  bool invalid() const { return GETBIT(m_flags, kInvalid); }
  void setValid(bool bFlag);

  /** Description:
    Must be overridden to return true in child class to inform base implementation that
    child class supports partial update.
  */
  virtual bool supportPartialUpdate() const;

  void viewAdded(OdGsView* pView);

#ifdef ODGS_MT
  mutable OdGsMTContextPtr m_pMTContext;
  OdArray<OdGsMTViewContextPtr> m_pMTViewContexts;

  virtual bool supportMultithreading() const;
  virtual OdUInt32 mtGetThreadSlotsCount() const;
  virtual OdGsMTContextPtr mtCreateMainContext();
  virtual OdGsMTContextPtr mtInitMainContext();
  virtual OdGsMTViewContextPtr mtCreateViewContext();
  virtual OdGsMTViewContextPtr mtInitViewContext(OdUInt32 nSlot, OdGsMTContext *pMainCtx);
  void mtInitContexts();
  void mtInitView(OdGsView *pView);
public:
  OdGsMTContext *mtContext() const
  {
    ODA_ASSERT(!m_pMTContext.isNull());
    return m_pMTContext.get();
  }
#endif
public:
  ODRX_DECLARE_MEMBERS(OdGsBaseVectorizeDevice);

  ~OdGsBaseVectorizeDevice();

  OdGiContext* userGiContext() const;
  void setUserGiContext(OdGiContext* pUserGiContext);

  OdRxDictionaryPtr properties();
  OdGsBaseVectorizeDevice();

  /** Description:
    Returns the *height* of this Device object in pixels.
  */
  int height() const;

  /** Description:
    Returns the *width* of this Device object in pixels.
  */
  int width() const;

  void invalidate();

  void invalidate(const OdGsDCRect &screenRect);

  void invalidateRegion(const OdGiPathNode& path);

  const OdGsDCRectArray& invalidRects() const;

  bool isValid() const;

  virtual void update(OdGsDCRect* pUpdatedRect);
  virtual void updateGeometry();
  virtual void updateScreen();

  void onSize(const OdGsDCRect& outputRect);

  const OdGsDCRect& outputRect() const;

  void onRealizeForegroundPalette();

  void onRealizeBackgroundPalette();

  void onDisplayChange(
    int bitsPerPixel, 
    int xPixels, 
    int yPixels);

  OdGsViewPtr createView(
    const OdGsClientViewInfo* pViewInfo = 0, 
    bool enableLayerVisibilityPerView = false);

  /*/DD2ARX - xi hui - 2008-06-24 - OdGsDevice::add
  void addView(
    OdGsView* pView);
  /*/
  virtual bool add(
    OdGsView* pView);
  //*/

  void insertView(int viewIndex, OdGsView* pView);

  /*/DD2ARX - xi hui - 2008-06-24 - OdGsDevice::erase
  bool eraseView(
    OdGsView* pView);
  /*/
  bool erase(
    OdGsView* pView);
  //*/

  int numViews() const;

  OdGsView* viewAt(int viewIndex);

  bool eraseView(int viewIndex);

  /*/DD2ARX - xi hui - 2008-06-24 - OdGsDevice::eraseAll
  void eraseAllViews();
  /*/
  void eraseAll();
  //*/

  bool setBackgroundColor(ODCOLORREF backgroundColor);

  ODCOLORREF getBackgroundColor();

  void setLogicalPalette(const ODCOLORREF* logicalPalette, int numColors);

  /** Description:
    Returns the specified *color* in the logical palette of this Device object.
    Arguments:
    colorIndex (I) Color *index*.
  */
  ODCOLORREF getColor(OdUInt16 colorIndex) const
  {
    return m_logPalette[colorIndex];
  }
  
  /** Description:
    Returns the logical palette of this Device object.
  */
  const ODCOLORREF* getPalette() const
  {
    return m_logPalette.asArrayPtr();
  }

  OdGsModelPtr createModel();
  bool isModelCompatible(OdGsModel* pModel) const;

  const OdGsView* rootView(const OdGsView *pView) const;

  // renderTypes support
  bool sortRenderTypes() const;
  void setSortRenderTypes(bool bFlag);
  virtual OdUInt32 renderTypeWeight(OdGsModel::RenderType renderType) const;
  virtual OdGsModel::RenderType transientRenderType() const;
  // overlays support
  bool supportOverlays() const;
  void setSupportOverlays(bool bFlag);
  virtual OdUInt32 renderTypeOverlay(OdGsModel::RenderType renderType) const;
  bool isOverlayInvalid(OdUInt32 nOverlay) const;
  void setOverlayInvalid(OdUInt32 nOverlay, bool bFlag);
  void resetOverlayFlags(bool bFlag = false);

  bool isSpatialIndexDisabled() const;
  void disableSpatialIndex(bool flag);

  bool supportDynamicHighlight() const;
  bool supportDynamicSubhighlight() const;

  bool supportPhotometricLights() const;

  bool supportBlocks() const;

  virtual bool enableCompatibleCacheViewport() const;
  virtual OdGsBaseVectorizeView* findCompatibleCacheViewport(const OdGsBaseVectorizeView& keyView) const;
  OdGiSectionGeometryManager *getSectionGeometryManager();
  OdRxObjectPtr getSectionGeometryMap();
  void clearSectionGeometryMap();

};

inline bool OdGsBaseVectorizeDevice::sortRenderTypes() const
{
  return GETBIT(m_flags, kSortRenderTypes);
}

inline void OdGsBaseVectorizeDevice::setSortRenderTypes(bool bFlag)
{
  SETBIT(m_flags, kSortRenderTypes, bFlag);
}

inline bool OdGsBaseVectorizeDevice::supportOverlays() const
{
  return GETBIT(m_flags, kSupportOverlays);
}

inline void OdGsBaseVectorizeDevice::setSupportOverlays(bool bFlag)
{
  SETBIT(m_flags, kSupportOverlays, bFlag);
}

inline bool OdGsBaseVectorizeDevice::isOverlayInvalid(OdUInt32 nOverlay) const
{
  return GETBIT(m_invalidOverlays, (1 << nOverlay));
}

inline void OdGsBaseVectorizeDevice::setOverlayInvalid(OdUInt32 nOverlay, bool bFlag)
{
  SETBIT(m_invalidOverlays, (1 << nOverlay), bFlag);
}

inline void OdGsBaseVectorizeDevice::resetOverlayFlags(bool bFlag)
{
  m_invalidOverlays = (bFlag) ? 0xFFFFFFFF : 0;
}

inline bool OdGsBaseVectorizeDevice::isSpatialIndexDisabled() const
{
  return GETBIT(m_flags, kSpatialIndexDisabled);
}

inline void OdGsBaseVectorizeDevice::disableSpatialIndex(bool flag)
{
  SETBIT(m_flags, kSpatialIndexDisabled, flag);
}

inline bool OdGsBaseVectorizeDevice::supportDynamicHighlight() const
{
  return GETBIT(m_flags, kDynamicHighlight);
}

inline bool OdGsBaseVectorizeDevice::supportDynamicSubhighlight() const
{
  return GETBIT(m_flags, kDynamicSubhighlight);
}

inline bool OdGsBaseVectorizeDevice::supportPhotometricLights() const
{
  return GETBIT(m_flags, kPhotometricLights);
}

inline bool OdGsBaseVectorizeDevice::supportBlocks() const
{
  return GETBIT(m_flags, kSupportBlocks);
}

class OdGsBaseModel;

/** Description:
    This class implements Viewport objects in GUI display windows.
    
    Library: TD_Gs
    
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsViewImpl : public OdGsView
{
  friend class OdGsBaseModule;
  friend class OdGsBaseVectorizeDevice;

protected:
  OdGsBaseModulePtr m_pModule;
  OdGsBaseVectorizeDevice*  m_pDevice;
  OdGsClientViewInfo        m_viewInfo;
  OdUInt32                  m_giViewportId;
  OdSharedPtr<OdGiClipBoundaryWithAbstractData> m_p3dClip;
  mutable OdUInt32 m_gsViewImplFlags;
  DefaultLightingType m_defaultLightingType;
  /** Description:
    Notification function called whenever this ViewImpl object is about to be released.
  */
  void onFinalRelease();

public:
  ODRX_DECLARE_MEMBERS(OdGsViewImpl);

  OdGsViewImpl();
  ~OdGsViewImpl();
  /** Description:
    Initializes this Viewport object.
    
    Arguments:
    pDevice (I) Pointer to the OdGsBaseVectorizeDevice associated with this Viewport object.
    pViewInfo (I) Pointer to the Client View Information for this Viewport object.
    enableLayerVisibilityPerView (I) Layer visibility per viewport is supported, if and only if true.
      
  */
  virtual void init(OdGsBaseVectorizeDevice* pDevice, 
    const OdGsClientViewInfo* pViewInfo = 0, 
    bool enableLayerVisibilityPerView = false);

  virtual OdGsDevice* device() const;

  /** Description:
    Returns the OdGsBaseVectorizeDevice associated with this Viewport object.
  */
  OdGsBaseVectorizeDevice* baseDevice() { return m_pDevice; }
  const OdGsBaseVectorizeDevice* baseDevice() const { return m_pDevice; }

  /** Description:
    Returns the eye coordinate system *extents* of this Vectorizer object.
    
    Arguments:
    extents (O) Receives the *extents*.

    Remarks:
    Returns true if and only if the *extents* are defined.
  */
  virtual bool viewExtents(OdGeBoundBlock3d& extents) const = 0;

  virtual void clientViewInfo(OdGsClientViewInfo& viewInfo) const;

  TD_USING(OdGsView::setViewportClipRegion);
  virtual void setViewportClipRegion(int numContours, int const* numVertices, OdGePoint2d const* vertices);
  TD_USING(OdGsView::viewportClipRegion);
  virtual void viewportClipRegion(OdIntArray& counts, OdGePoint2dArray& vertices) const;

  bool isDependentViewportView() const;
  bool isDependentGeometryView() const;

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
  */
  virtual const OdGiClipBoundary *viewport3dClipping(const OdGiAbstractClipBoundary** ppClipInfo = NULL) const;
  /** Description:
    Returns the current 3d clipping for this Viewport object as single object.
  */
  OdGiClipBoundaryWithAbstractData *viewport3dClippingObject();
  /** Description:
    Returns true if and only if 3d clipping set for this Viewport object.
  */
  bool hasViewport3dClipping() const;

  enum ImplFlags
  {
    kFirstImplFlag = 1,
    kSectionableGeomEnabled = kFirstImplFlag << 0,
    kDefaultLightingEnabled = kFirstImplFlag << 1,
    kLastImplFlag = kDefaultLightingEnabled
  };

  virtual void enableDefaultLighting(bool bEnable, DefaultLightingType lightType = kTwoLights);
  bool defaultLightingEnabled() const;
  DefaultLightingType defaultLightingType() const;
};

inline bool OdGsViewImpl::isDependentViewportView() const
{
  return GETBIT(m_viewInfo.viewportFlags, OdGsClientViewInfo::kDependentViewport);
}

inline bool OdGsViewImpl::isDependentGeometryView() const
{
  return GETBIT(m_viewInfo.viewportFlags, OdGsClientViewInfo::kDependentGeometry);
}

inline bool OdGsViewImpl::defaultLightingEnabled() const
{
  return GETBIT(m_gsViewImplFlags, kDefaultLightingEnabled);
}

inline OdGsView::DefaultLightingType OdGsViewImpl::defaultLightingType() const
{
  return m_defaultLightingType;
}

namespace OdSi
{
  class BBox;
}

class OdGsMaterialNode;

enum EMetafilePlayMode
{
  kMfDisplay, //play for visualization. Default, valid for all metafile types.
  //Following modes are valid only if metafile can be played as OdGiConveyorGeometry
  //( if useMetafileAsGeometry() returns true).
  kMfSelect, //play as geometry for selection
  kMfExtents, //play as geometry for extents calculation
  kMfDisplayHLBack,
  kMfDisplayHLFront,
};

/** Description:
    This class is a pattern implementation of the OdGsView interface. 
    
    Remarks:
    This class implements most of the OdGsView class.
    It creates simplified eye coordinate system (ECS) output graphics,
    which could be redirected by a client to a renderer to screen or file.
    
    See also:
    DWF/SVG exports
    
    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBaseVectorizeView : public OdGsViewImpl
                                              , public OdGiViewport
                                              , public OdGiBaseVectorizer
{
  friend OdGsBaseModel;
protected:
  mutable OdGeMatrix3d      m_objectToDeviceMatrix;
  mutable OdGeMatrix3d      m_worldToDeviceMatrix;

  mutable bool              m_bObjectToDeviceValid;
  mutable bool              m_bWorldToDeviceValid;

  ODCOLORREF                m_borderColor;
  int                       m_borderWeight;
  OdUInt32                  m_FadedEnable;

  OdGiOrthoClipperPtr       m_pXlineNRayClipper;

  OdGiConveyorEntryPoint    m_xlineNRayEntryPoint;
  OdGiConveyorConnector     m_ltpEntryPoint;

  OdGiXformPtr              m_pXToLtp;
  OdGiLinetypeRedirPtr      m_pLinetyper;

  OdGiConveyorEmbranchmentPtr m_pOutputBranch;
  OdGsExtAccumPtr           m_pOutputExtents;

  OdGsPropertiesPtr         m_pProperties;

  OdGiDrawablePtr           m_liveSection;
  OdRxObjectPtr             m_sectionGeometryMap;
  OdCmTransparency          m_sectForegroundFace;
  OdCmTransparency          m_sectForegroundEdge;

  struct DrawableHolder
  {
    DrawableHolder()
      : m_drawableId(0)
      , m_pGsRoot(0)
    {}
    OdDbStub*                 m_drawableId;
    OdGiDrawablePtr           m_pDrawable;
    OdSmartPtr<OdGsBaseModel> m_pGsModel;
    OdGsNodeEx*               m_pGsRoot;
    OdRxObjectPtr             m_pMetafile;
    OdGeExtents3d             m_lastExt;
  };
  typedef OdArray<DrawableHolder> DrawableHolderArray;

  enum Flags
  {
    kFillPlaneSet          = OdGiBaseVectorizer::kLastFlag <<  1,
    kDoFrontClip           = OdGiBaseVectorizer::kLastFlag <<  2,
    kDoBackClip            = OdGiBaseVectorizer::kLastFlag <<  3,
    kPerspectiveEnabled    = OdGiBaseVectorizer::kLastFlag <<  4,
    kBorderVisible         = OdGiBaseVectorizer::kLastFlag <<  5,
    kLinetypeContinuous    = OdGiBaseVectorizer::kLastFlag <<  6,
    kModelCache            = OdGiBaseVectorizer::kLastFlag <<  7,
    kInvalid               = OdGiBaseVectorizer::kLastFlag <<  8, // device surface entirely invalid
    kCheckValid            = OdGiBaseVectorizer::kLastFlag <<  9, // device surface entirely valid
    kHidden                = OdGiBaseVectorizer::kLastFlag <<  10, // view is hidden
    kTransparentClearColor = OdGiBaseVectorizer::kLastFlag <<  11, // todo -- move these two flags into separate field in 1.15
    kDevBgClearColor       = OdGiBaseVectorizer::kLastFlag <<  12,
    kHighlighted           = OdGiBaseVectorizer::kLastFlag <<  13,
    kDontAbortRegen        = OdGiBaseVectorizer::kLastFlag <<  14,
    kCheckLinePattern      = OdGiBaseVectorizer::kLastFlag <<  15,
    kDepViewInside         = OdGiBaseVectorizer::kLastFlag <<  16, // viewport completely visible
    kBreakSelection        = OdGiBaseVectorizer::kLastFlag <<  17,
    kSuppressOutput        = OdGiBaseVectorizer::kLastFlag <<  18,
    kAdjustDeviation       = OdGiBaseVectorizer::kLastFlag <<  19,
    kFaded                 = OdGiBaseVectorizer::kLastFlag <<  20,
    kSelectionGeometry     = OdGiBaseVectorizer::kLastFlag <<  21, // Processing geometry which is intended only for selection
    kSelectionDisabled     = OdGiBaseVectorizer::kLastFlag <<  22, // Processing geometry which shouldn't be used for selection
    kDisableSection        = OdGiBaseVectorizer::kLastFlag <<  23,

    kLastOptionFlag        = kDisableSection
  };

  // OdGiConveyorContext
  const OdGiViewport* giViewport() const;
  const OdGsView* gsView() const;

  virtual OdGsNodeEx* getRootNode(DrawableHolder& holder);
  virtual void updateViewProps();
  virtual bool isViewRegenerated() const;
  virtual double calcDeviation(const OdGiDeviationType type, const OdGePoint3d& pt) const;
  double possibleFPConversionError(const OdGeMatrix3d &xfm);
  double possibleFPConversionError();

  bool m_bLinetypeOpt;
  OdDbStub* m_LTypeByLayerId;
  OdDbStub* m_LTypeByBlockId;
  OdDbStub* m_LTypeContinuousId;
  OdDbDatabase* m_pDatabase;
  virtual void affect2dTraits(const OdGiSubEntityTraitsData* pFrom, OdGiSubEntityTraitsData& to) const;
  void affectLTyeTraits(const OdGiSubEntityTraitsData* pFrom, OdGiSubEntityTraitsData& to) const;

  mutable OdSi::BBox      m_spqbox;
  mutable OdSi::Volume    m_spqvol;

  friend class OdGsBaseVectorizeDevice;

  void screenRectNorm(OdGsDCRect& normalizedRect) const;
  virtual void propagateInvalidVpFlag();
  virtual void propagateLayersChanges();

  const OdPsPlotStyleData& plotStyle() const;
#ifdef ODGS_MT
  virtual void mtGhostViewInitialSetup(const OdGsBaseVectorizeView *pBearView);
  virtual void mtPrepareGhostViewForUpdate(const OdGsBaseVectorizeView *pBearView);
  mutable OdGsMTViewContext *m_pMTContext;
  OdArray<OdGsViewPtr> m_pMTGhosts;
public:
  OdGsMTViewContext *mtContext() const { return m_pMTContext; }
  OdGsBaseVectorizeView *mtGetGhost(OdUInt32 nGhost)
  {
    if (nGhost == 0)
      return this;
    return static_cast<OdGsBaseVectorizeView*>(m_pMTGhosts[nGhost - 1].get());
  }
#endif
protected:
  ODRX_USING_HEAP_OPERATORS(OdGiBaseVectorizer);

  DrawableHolderArray       m_drawables;
  int                       m_nCachedDrawables;

  /** Description:
    Returns the OdGiDrawable associated with the specified DrawableHolder object.
    Arguments:
    drawableHolder (I) Drawable holder.
     
  */
  OdGiDrawablePtr drawableAt(DrawableHolder& drawableHolder);

  /** Description:
    Returns the number of cached drawables for this VectorizeView object.
  */
  int cachedDrawables() const { return m_nCachedDrawables!=0; }

  OdDbStubPtrArray          m_frozenLayers;
  OdDbStubPtrArray          m_lastFrozenLayers;

  OdIntArray                m_nrcCounts;
  OdGePoint2dArray          m_nrcPoints;

  OdUInt8Array              m_lweights;
  double                    m_linetypeScaleMultiplier;
  double                    m_linetypeAlternateScaleMultiplier;
  double                    m_lineweightToDcScale;
  double                    m_deviation[5];

  OdGeVector3d              m_fillPlane;
  OdGePoint3d               m_position;
  OdGePoint3d               m_target;
  OdGeVector3d              m_upVector;
  OdGeVector3d              m_xVector;
  OdGeVector3d              m_eyeVector;
  double                    m_frontClipDist;
  double                    m_backClipDist;
  double                    m_lensLength;
  double                    m_eyeVecLength;

  double                    m_fieldWidth;
  double                    m_fieldHeight;
  OdGePoint2d               m_dcScreenMin;
  OdGePoint2d               m_dcScreenMax;
  OdGePoint2d               m_dcLowerLeft;
  OdGePoint2d               m_dcUpperRight;
  RenderMode                m_renderMode;

  OdGiContext::PStyleType   m_pstype;
  mutable int               m_nPenIndex;
  mutable OdDbStub*         m_psnId;
  mutable OdPsPlotStyleData m_plotStyle;
  mutable OdPsPlotStyleData m_effectivePlotStyle;
  mutable OdUInt32          m_nAwareFlags;

  EMetafilePlayMode         m_eMfPlayMode;
  OdGsBaseModel*            m_pGsModel;
  mutable const OdGiLayerTraitsData*
                            m_pCachedLayer;
  OdGiSelectProc*           m_pSelectProc;
  OdGsCullingVolumePtr      m_pCullingVolume;
  OdGsModel::RenderType     m_curRenderType;
  OdGiIndirectEntityAccessorPtr
                            m_pEntAccessor;
  bool                      m_bMetafileIsEmpty;
  OdGiConveyorGeometry*     m_pDetachedOutput;
  OdGsHighlightBranchPtr    m_pCurHltBranch;
  OdRxObjectPtr             m_pGsReserved;

  OdGeVector3d*             m_pAdjustOffsetStack;
  OdInt32                   m_nAOCounter;
  OdInt32                   m_nAOStep;
  const OdSiShape**         m_pSelShapeStack;
  OdInt32                   m_nSSCounter;
  OdInt32                   m_nSSStep;

  int                       m_lineweightToPixScale;

  OdDbStub* switchLayer(OdDbStub* layerId) const;
  const OdGiLayerTraitsData& effectiveLayerTraits() const;

  /** Description:
    Returns the minimum and maximum depth of this VectorizeView object.
    Arguments:
    pMinDeptSupported (O) Receives the minimum depth supported.
    pMaxDeptSupported (O) Receives the maximum depth supported.
    Remarks:
    Returns true if and only if this VectorizeView object supports depth.    
    
    Note:
    The default implementation of this function does nothing but return false.
  */
  virtual bool usesDept(double* pMinDeptSupported = 0, double* pMaxDeptSupported = 0) const;
  /**
    Description:
    Recomputes the *extents* for this VectorizeView object.
    
    Arguments:
    buildCache (I) Builds Metafile (cache) objects if and only if true.
  */
  virtual void updateExtents(bool buildCache);
  
  /** Description:
    Returns the minimum and maximum z-values for this VectorizeView object.
    Arguments:
    zNear (O) Receives the minimum z-value.
    zFar (O) Receives the maximum z-value.
    Remarks:
    Returns true if and only if this VectorizeView object has z-values associated with it.
  */
  virtual bool sceneDept(double& zNear, double& zFar) const;
  /** Description:
    Paints the *display* with each of the drawable objects associated with this VectorizeView object.
    
    Arguments:
    update (I) If and only if true, the cache is updated before displaying the drawable.
     
    Remarks:
    The display is painted for each drawable from one of the following methods in the following order.
    
    1.  Model cache. 
    2.  The metafile for the drawable.
    3.  The drawable itself.
  */
  virtual void display(bool update);

  /** Description:
    Returns the *output* *extents* of this VectorizeView object.
    Arguments:
    extents (O) Receives the *extents*.
    Remarks:
    Returns true if and only if this VectorizeView object has *extents*
  */
  bool getOutputExtents(OdGeBoundBlock3d& extents) const;

  /** Description:
    Data utilized only by derived classes.
  */
  OdGiRegenType m_regenerationType;

  /** Description:
    Notification function called whenever the World to Eye transformation matrix has been changed.
  */
  virtual void OnWorldToEyeChanged();
  
  /** Description:
    Updates the Xline and Ray clipper prior to rendering each Xline and Ray.
    
    Remarks:
    Called by ray() and xline().
  */
  virtual void UpdateXlineNRayClipper();

  /** Description:
    Returns true if and only if this VectorizeView object is configured to use a fill plane.
  */
  virtual bool useFillPlane() const;
  
  /** Description:
    Sets the fill type for this VectorizeView object.
    Arguments:
    fillType (I) Fill type.
    
    Remarks:
    fillType must be one of the following:
    
    @table
    Name               Value    Description
    kOdGiFillAlways    1        Always fill closed graphic primitives.
    kOdGiFillNever     2        Never fill closed graphic primitives.
  */
  void setFillType(const OdGiFillType fillType);
public:
  const OdSiShape* m_spQuery; // spatial query for displaying of top-level container

  OdUInt32 setAttributes(const OdGiDrawable* pDrawable);

  /** Description:
    Resets the Aware flags.

    See also:
    awareFlags
  */ 
  void resetAwareFlags() { m_nAwareFlags = 0; }

  /** Description:
    Returns the Aware flags for portion of geometry that had been vectorized
    since last call resetAwareFlags().
    
    Remarks:
    awareFlags() returns a combination of zero or more of the following:
    
    @table
    Name                    Value         Geometry_depends_on
    kVpID                   0x00000001    viewport Id (OdGiViewport::viewportId()).
    kVpRegenType            0x00000002    regeneration type (OdGiCommonDraw::regenType()).
    kVpRenderMode           0x00000004    render *mode* (OdGsView::mode()).
    kVpWorldToEye           0x00000008    description to come...
    kVpPerspective          0x00000010    description to come...
    kVpResolution           0x00000020    description to come...
    kVpMaxDevForCircle      0x00000040    description to come...
    kVpMaxDevForCurve       0x00000080    description to come...
    kVpMaxDevForBoundary    0x00000100    description to come...
    kVpMaxDevForIsoline     0x00000200    description to come...
    kVpMaxDevForFacet       0x00000400    description to come...
    kVpCamLocation          0x00000800    description to come...
    kVpCamTarget            0x00001000    description to come...
    kVpCamUpVector          0x00002000    description to come...
    kVpCamViewDir           0x00004000    description to come...
    kVpViewport             0x00008000    description to come...
    kVpFrontBack            0x00010000    description to come...
    kVpFrozenLayers         0x00020000    description to come...
    kVpLtypeScaleMult       0x00040000    description to come...

    See also:

    o  resetAwareFlags
  */ 
  OdUInt32 awareFlags() const { return m_nAwareFlags; }
  /** Description:
    Returns the frozen layers for this VectorizeView object.
    
    Arguments:
    frozenLayers (O) Receives an array of frozen *layer* Object IDs.
    
    Remarks:
    If called without the frozenLayers argument, returns true if and only if there
    are any frozen layers.    
  */
  bool frozenLayers() const { return !m_frozenLayers.empty(); }
  void frozenLayers(OdDbStubPtrArray& frozenLayers) const { frozenLayers = m_frozenLayers; }

  /** Description:
    Returns the effective plot style for this VectorizeView object.
  */
  const OdPsPlotStyleData& effectivePlotStyle() const;

  /** Description:
    Returns the *output* from this VectorizeView object.
  */
  OdGiConveyorOutput& output();

  /** Description:
    Returns the secondary *output* from this VectorizeView object.
  */
  OdGiConveyorOutput& secondaryOutput();

  /** Description:
    Returns true if and only if *output* suppressed.
  */
  bool isOutputSuppressed() const;

  /** Description:
    Returns true if and this if the effective linetype generation is continuous for VectorizeView object.
  */
  bool isEffectiveLinetypeContinuous() const;

  /** Description:
    Returns the specified OdGsView pointer 
    as a pointer to an OdGsBaseVectorizeView object.
    Arguments:
    pView (I) Pointer to an OdGsView object.
  */
  static OdGsBaseVectorizeView* safeCast(OdGsView* pView);

  OdGiContext* userGiContext() const;
  void setUserGiContext(OdGiContext* pUserGiContext);

  const OdGiIndirectEntityAccessor *getEntAccessor() const
  {
    return m_pEntAccessor.get();
  }
  bool isKindOfType(const OdGiDrawable *pDrw, OdGiIndirectEntityAccessor::ProcType type) const;
  OdGiIndirectEntityDataBasePtr getIndirectDataAccessor(const OdGiDrawable *pDrw, OdGiIndirectEntityAccessor::ProcType type) const;

  double lineweightToDcScale() const;
  void setLineweightToDcScale(double scale);
  void setLineweightEnum(int numLineweights, const OdUInt8* lineweights);
  
  /** Description:
    Returns the number of pixels corresponding to the specified *lineweight* for this VectorizeView object.
    Arguments:
    lineweight (I) Lineweight.
  */
  int lineweightToPixels(OdDb::LineWeight lineweight) const;
  double lineweightToPixels(double lineweight) const;

  void setViewport(const OdGePoint2d& lowerLeft, const OdGePoint2d& upperRight);
  void setViewport(const OdGsDCRect& screenRect);
  void setViewport(const OdGsDCRectDouble& screenRec);
  void getViewport(OdGePoint2d& lowerLeft, OdGePoint2d& upperRight) const;
  void getViewport(OdGsDCRect& screenRect) const;
  void getViewport(OdGsDCRectDouble& screenRec) const;

  void setMode(RenderMode mode);
  RenderMode mode() const;

  void setView(const OdGePoint3d & position,
    const OdGePoint3d& target,
    const OdGeVector3d& upVector,
    double fieldWidth,
    double fieldHeight,
    Projection projection = kParallel);

  OdGePoint3d position() const;
  OdGePoint3d target() const;
  OdGeVector3d upVector() const;

  const OdGeVector3d &xVector() const;
  const OdGeVector3d &eyeVector() const;

  double lensLength() const;
  
  /** Description:
    Returns the WCS (ECS) focal length of the lens for this VectorizeView object.
  */   
  double focalLength() const;

  void setLensLength(double lensLength);

  double fieldWidth() const;
  double fieldHeight() const;
  void setFieldWidth (double fw); 
  void setFieldHeight(double fh);
  void setViewCenter(const OdGePoint2d &ct);	

  void setEnableFrontClip(bool enable);
  bool isFrontClipped() const;
  void setFrontClip(double distance);
  double frontClip() const;

  void setEnableBackClip(bool enable);
  bool isBackClipped() const;
  void setBackClip(double distance);
  double backClip() const;

  OdGeMatrix3d viewingMatrix() const;
  OdGeMatrix3d projectionMatrix() const;
  OdGeMatrix3d screenMatrixWin() const;
  OdGeMatrix3d worldToDeviceMatrixWin() const;
  OdGeMatrix3d objectToDeviceMatrix() const;
  OdGeMatrix3d eyeToScreenMatrix() const;

  OdGeMatrix3d screenMatrix() const;
  OdGeMatrix3d worldToDeviceMatrix() const;

  void setViewportBorderProperties(ODCOLORREF color, int width);
  void getViewportBorderProperties(ODCOLORREF& color, int& width) const;
  void setViewportBorderVisibility(bool visible);
  bool isViewportBorderVisible() const;
  bool add(OdGiDrawable* sceneGraph, OdGsModel* model);
  bool erase(OdGiDrawable* sceneGraph);
  void eraseAll();

  void invalidate();
  void invalidate(const OdGsDCRect &rect);
  void invalidate(const OdGeExtents3d& worldExt, OdDb::LineWeight lwt = OdDb::kLnWt000 );
  void invalidateRegion(const OdGiPathNode& path);
  OdGsDCRectArray invalidRects() const;
  bool isValid() const;

  /** Arguments:
    mask (I) Mask.
  */
  void invalidateCachedViewportGeometry(OdUInt32 mask);
  void beginViewVectorization();
  
  /** Description:
    Caches the OdGiDrawable data for this VectorizeView object.
  */
  virtual void loadViewport();
  /** Description:
    Returns true if and only if this VectorizeView object is not off-screen.
  */
  bool isViewportOnScreen() const;

  bool isCompletelyVisible() const;

  virtual bool isViewportOnValidZone() const; // GCAD EX

  virtual bool forceMetafilesDependence() const;

  void update();
  /** Description:
    Draws the frame for this VectorizeView object.
  */
  virtual void drawViewportFrame();
  void endViewVectorization();

  void beginInteractivity(double frameRateInHz);
  void endInteractivity();
  void flush();

  void hide();
  void show();
  bool isVisible();

  void freezeLayer(LONG_PTR layerID);
  void thawLayer(LONG_PTR layerID);
  void clearFrozenLayers();

  void invalidateCachedViewportGeometry();

  //bool highlight(const OdGsPath*);
  //bool unhighlight(const OdGsPath*);

  void dolly(const OdGeVector3d& dollyVector);
  void dolly(double xDolly, double yDolly, double zDolly);
  void roll(double rollAngle);
  void orbit(double xOrbit, double yOrbit);
  void zoom(double zoomFactor);
  void zoomExtents(const OdGePoint3d& minPoint, const OdGePoint3d& maxPoint);
  void zoomWindow(const OdGePoint2d& lowerLeft,const OdGePoint2d& upperRight);
  void zoomScreenWindow(const OdGePoint2d& upLeft,const OdGePoint2d& bottomRight);
  void pan(double xPan, double yPan);

  virtual void pushView(); // GCAD EX
  virtual bool popView(bool bRollbackIfExceed = true); // GCAD EX
  virtual int  exceededMaxViewExtents() const; // GCAD EX

  OdGsViewPtr cloneView(bool cloneViewParameters = true, bool cloneGeometry = false);
  bool exceededBounds();

  void enableStereo(bool enabled);
  bool isStereoEnabled() const;
  void setStereoParameters(double magnitude, double parallax);
  void getStereoParameters(double& magnitude, double& parallax) const;

  bool hasViewportClipRegion() const { return m_nrcCounts.size() > 0; }
  void viewportClipRegion(OdIntArray& counts, OdGePoint2dArray& vertices) const;
  void viewportClipRegion(OdIntArray& counts, OdGsDCPointArray& dcPts) const;
  void setViewportClipRegion(int numContours, const int* numVertices, const OdGePoint2d* vertices);
  void setViewportClipRegion(int numContours, int const* numVertices, OdGsDCPoint const* vertices);

  bool pointInViewport(const OdGePoint2d& screenPoint) const;

  void viewParameters(OdGsView* pView) const;

  /** Description:
    This method can be called right after endMetafile() to check whether
    last recorded metafile was empty and optimize stored data.
  */
  bool isMetafileEmpty() const { return m_bMetafileIsEmpty; }

  /** Description:
	  This methods returns internal state indicating color fading mode.
  */
  bool isFaded() const { return GETBIT(m_flags, kFaded); }
  /** Description:
	  This methods sets internal state flag indicating color fading mode.
  */
  virtual void setFaded(bool bOn, OdUInt32 whichFade);

  /** Description:
    This methods sets internal state flag indicating playing mode and calls
    playMetafile(). The flag can be accessed via isPlayingMfAsGeometry(),
    see below.
  */
  void playMetafileMode(const OdRxObject* pMetafile, EMetafilePlayMode eMode);
  void playWorldLineMode(const OdGePoint3d* pPoints, int n, 
    const OdCmEntityColor& clr,
    OdDb::LineWeight lweight,
    EMetafilePlayMode eMode);

  /** Description:
    This method returns internal state indicating metafile playing mode.
  */
  EMetafilePlayMode metafilePlayMode() const { return m_eMfPlayMode; }

  /** Description:
    Returns current GsModel.
  */
  const OdGsBaseModel *currentBaseModel() const { return m_pGsModel; }

  /** Description:
    Returns current highlighting data.
  */
  OdGsHighlightBranchPtr currentHighlightBranch() const { return m_pCurHltBranch; }
  /** Description:
    Resets current highlighting data.
  */
  void setCurrentHighlightBranch(OdGsHighlightBranchPtr pCurHlt) { m_pCurHltBranch = pCurHlt; }
  void resetCurrentHighlightBranch() { m_pCurHltBranch = NULL; }

  void setModelSection(OdGiDrawable* pSection, bool bUseSectionGeometryMap);
  const OdGiDrawable* liveSection() const { return m_liveSection; }

protected:
  /** Description:
    Returns the *width* to *height* ratio for this VectorizeView object.
  */
  double windowAspect() const;
  /** Description:
    Returns the perspective transformation matrix for this VectorizeView object.
  */
  OdGeMatrix3d perspectiveMatrix() const;

  void affectTraits(const OdGiSubEntityTraitsData* pSource, OdGiSubEntityTraitsData& destination) const;

  void selectionMarkerOnChange(bool bChange = false);

  void checkRenderType(const OdGsModel *pModel);
  virtual void renderTypeOnChange(OdGsModel::RenderType renderType);
  
  static OdRxClass* g_pDesc;
public:
  OdGsBaseVectorizeView();
  ~OdGsBaseVectorizeView();

  static void rxInit();
  static void rxUninit();
  static OdRxClass* desc();
  OdRxClass* isA() const;
  OdRxObject* queryX(const OdRxClass* pProtocolClass) const;

  void setEnableLinetypeOpt(bool b) { m_bLinetypeOpt = b; }
  bool enableLinetypeOpt() const { return m_bLinetypeOpt; }

  // OdGsView methods - overrides

  OdGiRegenType regenType() const;
  double deviation(const OdGiDeviationType deviationType, const OdGePoint3d& pointOnCurve) const;
  OdBool regenAbort() const;

  OdUInt32      sequenceNumber() const;
  bool          isValidId(const OdUInt32 viewportId) const;
  OdDbStub*     viewportObjectId() const;

  void setFillPlane(const OdGeVector3d* pNormal = 0);

  OdGiViewport& viewport() const;

  // OdGiViewport
  OdGeMatrix3d getModelToEyeTransform() const;
  OdGeMatrix3d getEyeToModelTransform() const;
  OdGeMatrix3d getWorldToEyeTransform() const;
  OdGeMatrix3d getEyeToWorldTransform() const;
  //DD2ARX - xi hui - 08-07-09 - OdGiViewport::ModifyInterface
  void getEyeToModelTransform(OdGeMatrix3d& unnamed) const;
  void getEyeToWorldTransform(OdGeMatrix3d& unnamed) const;
  void getModelToEyeTransform(OdGeMatrix3d& unnamed) const;
  void getWorldToEyeTransform(OdGeMatrix3d& unnamed) const;

  bool isPerspective() const;
  bool doPerspective(OdGePoint3d& point) const;
  bool doInversePerspective(OdGePoint3d& point) const;
  
  void getNumPixelsInUnitSquare(const OdGePoint3d& givenWorldpt, OdGePoint2d& pixelArea) const;
  void getNumPixelsInUnitSquare(const OdGePoint3d& givenWorldpt, OdGePoint2d& pixelArea, bool includePerspective /*= true*/) const;
  
  OdGePoint3d getCameraLocation() const;
  OdGePoint3d getCameraTarget() const;
  OdGeVector3d getCameraUpVector() const;
  //DD2ARX - xi hui - 08-07-09 - OdGiViewport::ModifyInterface
  void getCameraLocation(OdGePoint3d& location) const;
  void getCameraTarget(OdGePoint3d& target) const;
  void getCameraUpVector(OdGeVector3d& upVector) const;
  
  OdUInt32 viewportId() const;
  OdInt16  acadWindowId() const;
  void getViewportDcCorners(OdGePoint2d& lowerLeft, OdGePoint2d& upperRight) const;
  
  bool getFrontAndBackClipValues(bool& clipFront, bool& clipBack, double& front, double& back) const;
  
  double linetypeGenerationCriteria() const;
  double linetypeScaleMultiplier() const;
  double linetypeAlternateScaleMultiplier() const;
  void setLinetypeScaleMultiplier(double linetypeScaleMultiplier);
  void setAlternateLinetypeScaleMultiplier(double linetypeAlternateScaleMultiplier);
  bool layerVisible(OdDbStub* layerId) const;

  OdGeVector3d viewDir() const;

  void initLights(OdRxIterator* pLightsIterator);

  /** Description:
    Evokes the specified OdGsSelectionReactor object for the specified *polygon* in this VectorizeView object.
    Arguments:
    points (I) Array of *points*.
    numPoints (I) Number of *points*.
    pReactor (I) Pointer to the reactor. 
  */
  virtual void select(const OdGsDCPoint* points, int numPoints, OdGsSelectionReactor* pReactor,
    SelectionMode mode = kCrossing);
  virtual void select(const OdGePoint3d* wcspts, int nPoints, OdGsSelectionReactor* pReactor,
	  SelectionMode mode = kCrossing);

  /** Description:
    Evokes the specified OdGsSelectionReactor object for the specified *polygon* in EYE coordinates in this VectorizeView object.
    Arguments:
    points (I) Array of *points*.
    numPoints (I) Number of *points*.
    pReactor (I) Pointer to the reactor. 
  */
  virtual void select(const OdGePoint2d* aPtDc, int numPoints, OdGsSelectionReactor* pReactor,
    SelectionMode mode = kCrossing);

  OdBool xline(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint) const;
  OdBool ray(const OdGePoint3d& basePoint, const OdGePoint3d& throughPoint) const;

  /** Description:
    Introduces a DCS rectangle into this vectorization *context*.
    Arguments:
    lowerLeft (I) Lower-left corner.
    upperRight (I) Upper-right corner.
  */
  void screenRect(OdGsDCPoint &lowerLeft, OdGsDCPoint &upperRight) const;
  void screenRect(OdGePoint2d &lowerLeft, OdGePoint2d &upperRight) const;

  void setExtents(OdGePoint3d *newExtents) const;

  bool doDraw(OdUInt32 drawableFlags, const OdGiDrawable* pDrawable);

  void drawBlockReference(const OdGiDrawable* pInsert, OdGsBlockReferenceNode* pNode);
  void drawPdfReference(const OdGiDrawable* pInsert, OdGsPdfReferenceNode* pNode);
  OdUInt32 drawBlock(const OdGiDrawable* pDrawable, OdGsBlockReferenceNodeImpl* pContainer,
                     OdGeExtents3d& extents, OdUInt32& lwd);

  OdBool pushModelTransform(const OdGeVector3d& normal);
  OdBool pushModelTransform(const OdGeMatrix3d & xfm);
  OdBool popModelTransform();

  enum MetafileTransformFlags
  {
    kSharedRefTransform = (1 << 0),
    kSharedRefUpdate    = (1 << 1),
    kSharedRefSelect    = (1 << 2),
    kSharedRefAdjust    = (1 << 3)
  };
  virtual void pushMetafileTransform(const OdGeMatrix3d&, OdUInt32 = 0) { }
  virtual void popMetafileTransform(OdUInt32 = 0) { }
  virtual bool useSharedBlockReferences() const { return true; }
  virtual bool enableUseSharedBlockReferences(bool bEnable) { return true; }
  virtual bool gsNodeBlockReferenceAsEntity() const { return false; }

  enum DrawableFlags
  {
    kSharedDisabled           = 0x01,
    kEffectivelyPaperOriented = 0x02,
    kImageHLT                 = 0x04,
    kIsRtzoom                 = 0x08,
    kRtDispOpt                = 0x10,
    kUnUsed1                  = 0x20,
    kUnUsed2                  = 0x40
  };

  virtual OdUInt32 testDrawableFlags(const OdGiDrawable* pDrawable, void* pReserve = NULL) const{return 0;}

  virtual void onTraitsModified();

  /** Description: 
    Controls *analytic* linetype support for circles and circular arcs in this VectorizeView object. 

    Arguments:
    analytic (I) Analytic linetype support.

    See Also:
    Analytic Linetyping
  */
  virtual void setAnalyticLinetypingCircles(bool analytic);

  /** Description:
    Returns true if and only if *analytic* linetype support for circles and circular arcs is
    enabled in this VectorizeView object.

    See Also:
    Analytic Linetyping
  */
  virtual bool isAnalyticLinetypingCircles() const;
  
  /** Description:
    Controls *analytic* linetype support for ellipses, elliptical curves, 
    and NURBS curves in this VectorizeView object. 

    Arguments:
    analytic (I) Analytic linetype support.
    See Also:
    Analytic Linetyping
  */
  virtual void setAnalyticLinetypingComplexCurves(bool analytic);

  /** Description:
    Returns true if and only if *analytic* linetype support for ellipses, elliptical curves, 
    and NURBS curves is enabled in this VectorizeView object.

    See Also:
    Analytic Linetyping
  */
  virtual bool isAnalyticLinetypingComplexCurves() const;

  /** Description:
    Builds a spatial query for the specified *polygon* in this VectorizeView object.
    Arguments:
    sceneExtents (I) Whole scene extents.
    points (I) Array of *points*.
    numPoints (I) Number of *points*.
  */
  virtual const OdSiShape& buildSpatialQuery(const OdGeExtents3d& sceneExtents, int numPoints = 0, const OdGsDCPoint* points = 0) const;
  /** Description:
    Builds a spatial query for the specified *polygon* in EYE coordinates in this VectorizeView object.
    Arguments:
    sceneExtents (I) Whole scene extents.
    points (I) Array of *points*.
    numPoints (I) Number of *points*.
  */
  virtual const OdSiShape& buildSpatialQuery(const OdGeExtents3d& sceneExtents, int numPoints, const OdGePoint2d* points) const;

  /** Description:
    Creates a new GsMetafile (cache) object.
    Remarks:
    Returns a SmartPointer to the newly created object.
    
    GsMetafiles are used to record vectorizations, and rapidly 'redraw' them to a *display* *device*. 

    See also:
    
    o  beginMetafile
    o  endMetafile
    o  playMetafile    
  */
  virtual OdRxObjectPtr newGsMetafile();
  /** Description:
    Begins vectorization to the specified GsMetafile (cache) object.
    Arguments:
    pMetafile (I) Pointer to the GsMetafile.
    Remarks:
    GsMetafiles are used to record vectorizations, and rapidly 'redraw' them to a *display* *device*. 
    
    See also:
    
    o  endMetafile
    o  newGsMetafile
    o  playMetafile    
  */
  virtual void beginMetafile(OdRxObject* pMetafile);
  /** Description:
    Ends vectorization to the specified GsMetafile (cache) object.
    Arguments:
    pMetafile (I) Pointer to the GsMetafile.
    Remarks:
    GsMetafiles are used to record vectorizations, and rapidly 'redraw' them to a *display* *device*. 
    
    See also:
    
    o  beginMetafile    
    o  newGsMetafile
    o  playMetafile    
  */
  virtual void endMetafile(OdRxObject* pMetafile);
  /** Description:
    Plays (redraws) the specified Metafile (cache) object.
    Arguments:
    pMetafile (I) Pointer to the GsMetafile.
    Remarks:
    GsMetafiles are used to record vectorizations, and rapidly 'redraw' them to a *display* *device*. 
    See also:
    
    o  beginMetafile
    o  endMetafile
    o  newGsMetafile    
  */
  virtual void playMetafile(const OdRxObject* pMetafile);
  virtual void playWorldLine(const OdGePoint3d* pPoints, int n,
    const OdCmEntityColor& clr,
    OdDb::LineWeight lweight);

  /** Description:
    Returns the eye coordinate system *extents* of this Vectorizer object.
    
    Arguments:
    extents (O) Receives the *extents*.

    Remarks:
    Returns true if and only if the *extents* are defined.
  */
  bool viewExtents(OdGeBoundBlock3d& extents) const;

  // Primitives culling routines

  /** Description:
    Initialize culling volume, associated with current view.

    Remarks:
    Default implementation initializes culling volume for overall view, and transforms overall view culling volume
    for all viewports inside overall view space (only if viewports has orthogonal projection). 
    This method can be overrided into user device for adjust described behaviour.
    If this method overrided as empty function (not create culling volume inside) - all culling functionality
    will be disabled.

    See also:
    o  isCullingVolumeInitialized
    o  cullingVolumeIntersectWithOpt
    o  cullingVolumeIntersectWith
  */
  virtual void initCullingVolume();
  /** Description:
    Sets culling volume associated with current view.
    Arguments:
    newVol (I) Smart pointer to new culling volume object.
    See also:
    o  cullingVolume
    o  initCullingVolume
  */
  void setCullingVolume(OdGsCullingVolumePtr newVol);
  /** Description:
    Returns culling volume associated with current view.
    See also:
    o  initCullingVolume
    o  setCullingVolume
  */
  OdGsCullingVolumePtr cullingVolume() const;
  /** Description:
    Returns true if and only if culling volume associated with current view.
    Remarks:
    Culling volume consider associated with current view if pointer to culling volume is not null.
    See also:
    o  initCullingVolume
    o  setCullingVolume
    o  cullingVolume
  */
  virtual bool isCullingVolumeInitialized() const;
  /** Description:
    Optimized intersection test between culling volume associated with current view and culling primitive.
    Remarks:
    Returns true if culling volume is not initialized.
    Arguments:
    prim (I) Input primitive for culling detection.
    See also:
    o  isCullingVolumeInitialized
    o  cullingVolumeIntersectWith
  */
  virtual bool cullingVolumeIntersectWithOpt(const OdGsCullingPrimitive &prim) const;
  /** Description:
    Complete intersection test between culling volume associated with current view and culling primitive.

    Remarks:
    Returns kIntersectIn intersection status if culling volume is not initialized.
    Return value intersection statuses:
    @table
    Name               Value    Description
    kIntersectNot      0        No intersection detected.
    kIntersectOk       1        Intersects with culling volume boundary.
    kIntersectIn       2        Culling volume primitive is completely inside culling volume boundary.

    Arguments:
    prim (I) Input primitive for culling detection.

    See also:
    o  isCullingVolumeInitialized
    o  cullingVolumeIntersectWithOpt
  */  
  virtual OdGsCullingVolume::IntersectionStatus cullingVolumeIntersectWith(const OdGsCullingPrimitive &prim) const;
  /** Description:
    Applies transformation for culling volume associated with current view.
    Arguments:
    xfm (I) Transformation matrix.
    See also:
    o  initCullingVolume
  */
  virtual void cullingVolumeTransformBy(const OdGeMatrix3d &xfm);

  virtual void setClearColor(ClearColor color);

  ClearColor clearColor() const;

  virtual bool isHighlighted() const;
  virtual void highlight(bool bHighlight);

  virtual void addPointLight(const OdGiPointLightTraitsData&) {}
  virtual void addSpotLight(const OdGiSpotLightTraitsData&) {}
  virtual void addDistantLight(const OdGiDistantLightTraitsData&) {}
  virtual void addWebLight(const OdGiWebLightTraitsData&); // default implementation call's addPointLight

  virtual bool useMetafileAsGeometry() const { return false; }
  virtual OdGiConveyorOutput& outputForMetafileGeometry();
  virtual void setTransformForMetafileGeometry(const OdGeMatrix3d&) {}
  virtual OdGeMatrix3d getTransformForMetafileGeometry() const { return OdGeMatrix3d::kIdentity; }
  void checkSelection();

  void clearLinetypeCache();

  void pushAdjustOffset(const OdGeVector3d& ao);
  void popAdjustOffset() { --m_nAOStep; }
  bool isAdjustOffset() const { return m_nAOStep >= 0; }
  const OdGeVector3d& curAdjustOffset() const { return m_pAdjustOffsetStack[m_nAOStep]; }

  void pushSelShape(const OdSiShape* pShape);
  void popSelShape() { --m_nSSStep; }
  bool isSelShape() const { return m_nSSStep >= 0; }
  const OdSiShape* curSelShape() const { return m_pSelShapeStack[m_nSSStep]; }
  const OdSiShape* rootSelShape() const { return m_pSelShapeStack[0]; }

public:
  // Viewport properties (backgrounds, render settings, visual styles) management
  virtual bool updateViewportProperties(OdUInt32 incFlags = OdGsProperties::kAll);
  virtual bool displayViewportProperties(OdGsPropertiesDirectRenderOutput *pdro = NULL, OdUInt32 incFlags = OdGsProperties::kAll);
  OdGsPropertiesPtr getViewportPropertiesRoot() const;
  OdGsPropertiesPtr getViewportPropertiesForType(OdGsProperties::PropertiesType type) const;

  // Inherited from GsView 
  virtual void setBackground(OdDbStub *backgroundId);
  virtual OdDbStub *background() const;
  virtual void setVisualStyle(OdDbStub *visualStyleId);
  virtual OdDbStub *visualStyle() const;
  virtual void setVisualStyle(const OdGiVisualStyle &visualStyle);
  virtual bool visualStyle(OdGiVisualStyle &style) const;
  
  // Materials support
  virtual void processMaterialNode(OdDbStub *materialId, OdGsMaterialNode *node);

  virtual bool getMaxExtents(OdGeExtents3d& extents); // GCAD EX
  virtual int  testEntityExtents(const OdGeExtents3d& extents); // GCAD EX
  virtual int  testOnlyUpdateGeometry() const; // GCAD EX
  virtual int  testReupdateGeometry() const; // GCAD EX

  virtual void setLineweightToPixScale(int lwScale);// GCAD Ex

  virtual int getRenderMode() const { return mode(); }
private:
  bool drawSectionable(const OdGiDrawable& drawable, bool& bRes);
  bool drawSectionGeometry(OdGiSectionGeometry& geom, bool bVpModelTfAwareBefore);
};

inline const
OdGsDCRect& OdGsBaseVectorizeDevice::outputRect() const
{
  return m_outputRect;
}

inline const OdGsDCRectArray&
OdGsBaseVectorizeDevice::invalidRects() const
{
  return m_invalidRects;
}

inline OdGsBaseVectorizeView* OdGsBaseVectorizeView::safeCast(OdGsView* pView)
{
  return static_cast<OdGsBaseVectorizeView*>(OdSmartPtr<OdGsViewImpl>(pView).get());
}

/** Description:
    This function must be called before using any GS implementation classes.
    Remarks:
    OdGsBaseModule::initApp() calls this function, so there is no need to call it explicitly
    when using GS classes within an OdRx Module derived from OdGsBaseModule.

    Library: TD_Gs
*/
GS_TOOLKIT_EXPORT void odgsInitialize();

/** Description:
    This function must be called after using any GS implementation classes.
    Remarks:
    OdGsBaseModule::uninitApp() calls this function, so there is no need to call it explicitly
    when using OdGs classes within an OdRx Module derived from OdGsBaseModule.

    Library: TD_Gs
*/
GS_TOOLKIT_EXPORT void odgsUninitialize();


#include "../TD_PackPop.h"

#endif // ODGSBASEVECTORIZER_INC
