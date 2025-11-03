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

#ifndef __ODGSMODELIMPL_H__
#define __ODGSMODELIMPL_H__

class OdGsNodeEx;
class OdGsBaseVectorizeView;

#include "../OdList.h"
#include "../UInt8Array.h"
#include "../UInt32Array.h"
#include "../DbStubPtrArray.h"
#include "../StaticRxObject.h"

#include "../Gi/GiDrawable.h"
#include "../Gi/GiCommonDraw.h"
#include "../Gi/GiExtAccum.h"
#include "../Gi/GiPathNode.h"

#include "../Gs/GsExport.h"
#include "../Gs/GsModel.h"
#include "../Gs/GsViewProps.h"
#include "../Gs/GsExtAccum.h"
#include "../Gs/GsMaterialCache.h"
#include "../Gs/GsVisualStyleProperties.h"
#include "../Gs/GsHighlightData.h"
#include "../Gs/GsMTContext.h"

struct OdGsGeomPortion;
struct OdGsGeomUniquePortion;
class OdGsLayerNode;
class OdGsBaseVectorizeDevice;

class OdGsXrefUnloadReactorImpl;
class OdInternalDatabaseServices;
class OdApLongTransactionManager;
class OdStreamBuf;

/** Description:
    This class is the base class for custom GsBaseModel objects which coordinate custom caching support 
    for Teigha vectorization applications.

    Remarks:
    Clients should derive their custom model classes from this class.

    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBaseModel : public OdGsModel
{
private:
  OdInternalDatabaseServices* m_pExDbService;
  OdApLongTransactionManager* m_pLTMgr;
  OdDbStub*       m_idLongTrans;
protected:
  OdGiOpenDrawableFn      m_openDrawableFn;
  OdGsNodeEx*             m_pNodes;
#ifndef ODGS_MT
  OdGsExtAccumPtr         m_pExtAccum;
#endif

  friend class OdGsNodeEx;

  /** Description:
    Adds the specified Node object to this BaseModel object.
    Arguments:
    pNode (I) Pointer to the Node to be added.  
  */
  void addNode(OdGsNodeEx* pNode);

public:
  virtual void invalidateEntRect(OdGiDrawable* pDrawable, OdGiDrawable* pParent, bool bForceIfNoExtents = false);

  bool m_bEliminateGsNodes;
  bool eliminateGsNodes() const { return m_bEliminateGsNodes; }

protected:
  OdUInt32 m_FadedStatus;
public:
  bool enableLayerLockFaded() const  { return GETBIT(m_FadedStatus, kLayerLockFaded); }
  bool enableXrefDwgFaded() const    { return GETBIT(m_FadedStatus, kXrefDwgFaded); }
  bool enableRefWorksetFaded() const { return GETBIT(m_FadedStatus, kRefWorksetFaded); }
  bool checkRefWorksetFaded() const  { return GETBIT(m_FadedStatus, kRefWorksetFadedCheck); }
  bool enableBvModeFaded() const  { return GETBIT(m_FadedStatus, kBvModeFaded); }

  void setEnableLayerLockFaded(bool bOn)  { SETBIT(m_FadedStatus, kLayerLockFaded, bOn); }
  void setEnableXrefDwgFaded(bool bOn)    { SETBIT(m_FadedStatus, kXrefDwgFaded, bOn); }
  void setEnableRefWorksetFaded(bool bOn) { SETBIT(m_FadedStatus, kRefWorksetFaded, bOn); }
  void setCheckRefWorksetFaded(bool bOn)  { SETBIT(m_FadedStatus, kRefWorksetFadedCheck, bOn); }
  void setEnableBvModeFaded(bool bOn)  { SETBIT(m_FadedStatus, kBvModeFaded, bOn); }

  bool refWorksetFaded() const { return (m_FadedStatus&kRefWorkset) == kRefWorkset; }
  void resetFadedStatus() { m_FadedStatus = 0; }

#ifdef ODA_DIAGNOSTICS
  int m_nNodes; //number of OdGsNodes allocated within the model (not necessary in 
                //m_pNodes list _directly_, can be owned by insert/block nodes).
#endif

  struct GS_TOOLKIT_EXPORT ViewProps
  {
  public:
    ViewProps();
    OdUInt32              m_vpId;
    OdGiRegenType         m_regenType;
    OdGsView::RenderMode  m_renderMode;
    OdGeMatrix3d          m_worldToEye;
    OdGePoint3d           m_cameraLocation;
    OdGePoint3d           m_cameraTarget;
    OdGeVector3d          m_cameraUpVector;
    OdGeVector3d          m_viewDir;
    OdGePoint2d           m_vpLowerLeft;
    OdGePoint2d           m_vpUpperRight;
    double                m_deviation[5];
    double                m_frontClip;
    double                m_backClip;
    OdDbStubPtrArray      m_frozenLayers;
    double                m_linetypeScaleMultiplier;
    OdUInt32              m_nViewChanges;
    OdUInt32              m_nViewDependencyMask;

    void set(const OdGsBaseVectorizeView& vpDraw);
    OdUInt32 difference(const ViewProps& props) const;
    bool isCompatibleWith(const ViewProps& props, OdUInt32 nFlags) const;
  };

  typedef std::pair<OdGsBaseVectorizeView*, OdUInt32> ViewRef;
  OdArray<ViewRef, OdMemoryAllocator<ViewRef> > m_views;
  
  friend class OdGsBaseVectorizeView;
  virtual void addViewRef(OdGsBaseVectorizeView* pView);
  virtual void removeViewRef(OdGsBaseVectorizeView* pView);
  OdGsBaseVectorizeView *refView() const;
  OdGsBaseVectorizeDevice *refDevice() const;

  /** Description:
    For internal needs. Do not use!
  */
  bool invalidVp(unsigned int viewportId) const
  {
    if(m_viewProps.size()>(OdSize)viewportId)
      return GETBIT(m_viewProps[viewportId].m_nViewChanges, 0x80000000);
    return true;
  }
  /** Description:
    For internal needs. Do not use!
  */
  void setInvalidVp(unsigned int viewportId, bool val)
  {
    if(m_viewProps.size()>(OdSize)viewportId)
      SETBIT(m_viewProps[viewportId].m_nViewChanges, 0x80000000, val);
  }
  virtual void clearChangedLayersList();
protected:

  OdArray<ViewProps>           m_viewProps;
  OdUInt32                     m_nLayers;
  OdGsLayerNode*               m_pFirstChangedLayer;

#ifndef ODGS_MT
  OdGsGeomPortion*             m_pGeomPortion;
  OdGsGeomUniquePortion*       m_pGeomUniquePortion;
  OdGsBaseVectorizeView*       m_pGsMetafileWriter;
#endif
  OdGsView::RenderMode         m_renderModeOverride;
  OdGeMatrix3d                 m_xForm;
  AdditionMode                 m_additionMode;
  OdDbStub*                    m_modelBackground;
  OdGsVisualStylePropertiesPtr m_modelVisualStyle;
  RenderType                   m_renderType;
  OdRxObjectPtr                m_pGsReserved;
  OdGsXrefUnloadReactorImpl   *m_pXrefReactor;

  // Material cache support
  OdGsMaterialCachePtr         m_pMaterialCache;

  // SubEntities highlighting
  OdGsHighlightData            m_highlightData;

protected:
  OdGsBaseModel();
  ~OdGsBaseModel();

  void deleteNodeEx(OdGsNodeEx* pNode);

public:
  enum {
    eEntityNode = 0,
    eEntityMetafile,
    eGeomPortion
  };
  virtual void* newObject(int nType);
  virtual void  deleteObject(int nType, void* pObject);
  virtual void  discardObject(int nType, void* pObject);

  /** Description:
    Returns the OdGsNodeEx object associated with the specified Drawable.
    
    Arguments:
    pDrawable (I) Pointer to the Drawable object.
    Remarks:
    If no Node object is associated with the Drawable object, one is created.
  */
  virtual OdGsNodeEx* gsNode(OdGiDrawable* pDrawable);

  /** Description:
    Removes the associations between the specified Node object and this BaseModel object.
    Arguments:
    pNode (I) Pointer to the Node object. 
  */
  virtual void detach(OdGsNodeEx* pNode);

  /** Description:
    Removes all Node objects from this BaseModel object.
  */
  virtual void detachAll();

  void addReactor(OdDbBaseDatabase* pDb);
  void detachAllFromDb(const OdDbBaseDatabase* pDb);

  /** Description:
    Opens the specified object.
    Arguments:
    objectID (I) Object ID of the Drawable object to be opened.
    
    Remarks:
    Returns a SmartPointer to the opened object.
  */
  OdGiDrawablePtr open(OdDbStub* objectId);

  void setOpenDrawableFn(OdGiOpenDrawableFn openDrawableFn);

  void onAdded(OdGiDrawable* pAdded, OdGiDrawable* pParent);
  void onAdded(OdGiDrawable* pAdded, LONG_PTR parentID);
  
  void onModified(OdGiDrawable* pModified, OdGiDrawable* pParent);
  void onModified(OdGiDrawable* pModified, LONG_PTR parentID);
  
  void onErased(OdGiDrawable* pErased, OdGiDrawable* pParent);
  void onErased(OdGiDrawable* pErased, LONG_PTR parentID);

  void invalidate(InvalidationHint hint);
  void invalidate(OdGsView* pView);
  /** Arguments:
    view (I) BaseVectorizeView object for which data are to be invalidated.
    mask (I) Mask.
  */
  void invalidate(OdGsBaseVectorizeView& view, OdUInt32 mask);

  /** Description:
    Returns the accumulated extents for this BaseModel object.
  */
#ifndef ODGS_MT
  OdGsExtAccum& extentsAccum();
#else
  OdGsExtAccum& extentsAccum(OdGsMTViewContext *pViewCtx);
#endif
  /** Description:
    Returns the view properties that have changed for the specified Viewport
    
    Arguments:
    viewportId (I) Viewport ID. 
  */
  OdUInt32 viewChanges(OdUInt32 viewportId) const;
  /** Description:
    Returns the size of the ViewProperties array for this BaseModel object.
  */
  OdUInt32 numViewProps() const;
  
  /** Description:
    Returns a reference to the the ViewProp structure for the specified Viewport.
    
    Arguments:
    viewportId (I) Viewport ID. 
  */
  const ViewProps& viewProps(OdUInt32 viewportId) const;
  
  /** Description:
    Updates the ViewProps structure for the specified Viewport.
    Arguments:
    viewport (I) Viewport.
  */
  virtual void updateViewProps(const OdGsBaseVectorizeView& viewport);

  virtual bool isViewPropsValid(OdUInt32 viewportId) const;

  virtual OdGsLayerNode* gsLayerNode(OdDbStub* layerId, const OdGsBaseVectorizeView* pView);

  virtual void propagateLayerChanges(OdGsBaseVectorizeDevice& device);

  virtual void beginMetafileRecording(OdGsBaseVectorizeView* pGsMetafileWriter, OdGsGeomPortion* pGeomPortion);
  virtual void beginMetafileRecording(OdGsBaseVectorizeView* pGsMetafileWriter, OdGsGeomUniquePortion* pGeomPortion);

#ifndef ODGS_MT
  virtual void endMetafileRecording();
#else
  virtual void endMetafileRecording(OdGsBaseVectorizeView* pView);
#endif

  virtual void beginPlayMetafileRecording(OdGsBaseVectorizeView* pView, const OdRxObject* pMetafile);
  virtual void endPlayMetafileRecording(OdGsBaseVectorizeView* pView, const OdRxObject* pMetafile);

  virtual void onTraitsModified(OdDbStub* layerId, OdDbStub* materialId, OdGsBaseVectorizeView* pView);

  void setTransform(const OdGeMatrix3d& xForm);

  OdGeMatrix3d transform() const;

  OdGsView::RenderMode renderModeOverride() const;

  void setRenderModeOverride(OdGsView::RenderMode mode = OdGsView::kNone);

  void highlight(const OdGiPathNode& path, bool bDoIt= true, const OdGsView* pView = 0);
  void highlight(OdGsNode* pGsNode, const OdGiPathNode& path, bool bDoIt, const OdGsView* pView = 0);
  bool highlight(const OdDbFullSubentPath& pPath, bool bDoIt= true, const OdGsView* pView = 0);

  // Material cache support
  OdGsMaterialCachePtr materialCache() const;

  OdGsHighlightData &highlightData();
  const OdGsHighlightData &highlightData() const;

  void setAdditionMode(AdditionMode mode);
  AdditionMode additionMode() const;

  void setRenderType(RenderType renderType);
  RenderType renderType() const;

  void setBackground(OdDbStub *backgroundId);
  OdDbStub *background() const;

  void setVisualStyle(OdDbStub *visualStyleId);
  OdDbStub *visualStyle() const;
  void setVisualStyle(const OdGiVisualStyle &visualStyle);
  bool visualStyle(OdGiVisualStyle &visualStyle) const;

  virtual bool cacheMetafileIn(const OdRxObject* , OdStreamBuf*){return false;}
  virtual bool cacheMetafileOut(const OdRxObject* , OdStreamBuf*){return false;}
protected:
  // SubEntities highlighting
  virtual bool removeSubEntHighlightBranch(OdGsNodeEx* pNode);

  /** Description:
    Update layer into metafile geometry portion, even if metafile for geometry portion is not created.
  */
  virtual void affectLayerChange(OdDbStub* layerId, const OdGsBaseVectorizeView* pView);

  void removeLayer(OdGsNodeEx* pNode);
};

inline OdGsView::RenderMode OdGsBaseModel::renderModeOverride() const
{
  return m_renderModeOverride;
}

inline OdGiDrawablePtr OdGsBaseModel::open(OdDbStub* objectId) 
{
  if(m_openDrawableFn)
    return m_openDrawableFn(objectId);
  //ODA_ASSERT_ONCE(objectId==0);
  return OdGiDrawablePtr();
}

inline OdUInt32 OdGsBaseModel::numViewProps() const
{
  return m_viewProps.size();
}

#ifndef ODGS_MT
inline OdGsExtAccum& OdGsBaseModel::extentsAccum()
{
  return *m_pExtAccum.get();
}
#else
inline OdGsExtAccum& OdGsBaseModel::extentsAccum(OdGsMTViewContext *pViewCtx)
{
  return *(pViewCtx->m_pExtAccum.get());
}
#endif

inline bool sameSortedArrays(const OdDbStubPtrArray& ar1, const OdDbStubPtrArray& ar2)
{
  if(ar1.size() != ar2.size())
    return false;
  OdDbStub * const *pAr1 = ar1.asArrayPtr(), * const *pAr2 = ar2.asArrayPtr();
  for(int i = 0; i < ar1.size(); ++i)
  {
    if(pAr1[i] != pAr2[i])
      return false;
  }
  return true;
}

inline bool OdGsBaseModel::ViewProps::isCompatibleWith(const OdGsBaseModel::ViewProps& props, OdUInt32 nMask) const
{
  if(GETBIT(nMask, kVpID))
  {
    if(m_vpId!=props.m_vpId)
      return false;
  }
  if(GETBIT(nMask, kVpRegenType))
  {
    if(m_regenType!=props.m_regenType)
      return false;
  }
  if(GETBIT(nMask, kVpRenderMode))
  {
    if(m_renderMode!=props.m_renderMode)
      return false;
  }
  if(GETBIT(nMask, kVpFrozenLayers) || !sameSortedArrays(m_frozenLayers, props.m_frozenLayers))
  {
    return false;
  }
  if(GETBIT(nMask, kVpFrontBack))
  {
    if(m_frontClip!=props.m_frontClip || m_backClip!=props.m_backClip)
      return false;
  }
  if(GETBIT(nMask, kVpCamLocation))
  {
    if(m_cameraLocation!=props.m_cameraLocation)
      return false;
  }
  if(GETBIT(nMask, kVpCamTarget))
  {
    if(m_cameraTarget!=props.m_cameraTarget)
      return false;
  }
  if(GETBIT(nMask, kVpMaxDevForCircle))
  {
    if(m_deviation[kOdGiMaxDevForCircle]!=props.m_deviation[kOdGiMaxDevForCircle])
      return false;
  }
  if(GETBIT(nMask, kVpCamUpVector))
  {
    if(m_cameraUpVector!=props.m_cameraUpVector)
      return false;
  }
  if(GETBIT(nMask, kVpCamViewDir))
  {
    if(m_viewDir!=props.m_viewDir)
      return false;
  }
  if(GETBIT(nMask, kVpViewport))
  {
    if(m_vpLowerLeft!=props.m_vpLowerLeft || m_vpUpperRight!=props.m_vpUpperRight)
      return false;
  }
  if(GETBIT(nMask, kVpWorldToEye))
  {
    if(m_worldToEye!=props.m_worldToEye)
      return false;
  }
  if(GETBIT(nMask, kVpLtypeScaleMult))
  {
    if(m_linetypeScaleMultiplier!=props.m_linetypeScaleMultiplier)
      return false;
  }
  return true;
}

inline const OdGsBaseModel::ViewProps& OdGsBaseModel::viewProps(OdUInt32 viewportId) const
{
  if(m_viewProps.size() <= (int)viewportId)
    const_cast<OdGsBaseModel*>(this)->m_viewProps.resize(viewportId + 1);
  return m_viewProps[viewportId];
}

inline OdUInt32 OdGsBaseModel::viewChanges(OdUInt32 viewportId) const
{
  return viewProps(viewportId).m_nViewChanges;
}

inline OdGsBaseVectorizeView *OdGsBaseModel::refView() const
{
  if (m_views.empty())
    return NULL;
  return m_views.first().first;
}

// Material cache support
inline OdGsMaterialCachePtr OdGsBaseModel::materialCache() const
{
  return m_pMaterialCache;
}

inline OdGsHighlightData &OdGsBaseModel::highlightData()
{
  return m_highlightData;
}

inline const OdGsHighlightData &OdGsBaseModel::highlightData() const
{
  return m_highlightData;
}

inline void OdGsBaseModel::setAdditionMode(OdGsModel::AdditionMode mode)
{
  m_additionMode = mode;
}

inline OdGsModel::AdditionMode OdGsBaseModel::additionMode() const
{
  return m_additionMode;
}

inline void OdGsBaseModel::setRenderType(OdGsModel::RenderType renderType)
{
  m_renderType = renderType;
}

inline OdGsModel::RenderType OdGsBaseModel::renderType() const
{
  return m_renderType;
}

#endif // __ODGSMODELIMPL_H__
