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


#ifndef __OD_GS_CONTAINER_NODE__
#define __OD_GS_CONTAINER_NODE__

#include "../Gs/GsNode.h"
#include "../Si/SiSpatialIndex.h"

class OdGsEntityNode;
class OdGsLightNode;
class OdGsBlockNode;

/** Description:
    This class implements OdGsNodeEx descendent objects that
    can serve as containers for OdGsEntityNode objects.

    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsContainerNode : public OdGsNodeEx
{
  friend class OdGsReferenceImpl;
protected:
  OdGsEntityNode*         m_pFirstEntity;
  OdGsEntityNode*         m_pLastEntity;
  OdList<OdGsLightNode*>  m_lightPtrs; // some of the lights are entities (ones that lies in model space)
  OdSiSpatialIndexPtr     m_pSpIndex;
  OdGsEntityNode*         m_pClearSpatialQueryStateFirst;
  OdUInt32Array           m_vpAwareFlags;
  int                     m_nChild;
  OdUInt32                m_nChildErased;

  enum
  {
    kEntityListValid  = OdGsNodeEx::kLastFlag << 1,
    kChildrenUpToDate = OdGsNodeEx::kLastFlag << 2,
    kTopLevel         = OdGsNodeEx::kLastFlag << 3,
    kNodesEliminated  = OdGsNodeEx::kLastFlag << 4,
    kCheckWorkset     = OdGsNodeEx::kLastFlag << 5,
    kInvalidRealExtents = OdGsNodeEx::kLastFlag << 6,

    kLastFlag         = kInvalidRealExtents
  };

  enum
  {
	  kChildrenNotUpToDate = 0x80000000 //special flag to use in setChildrenUpToDate/childrenUpToDate
		  //per each viewport, flags are stored in m_vpAwareFlags
  };

public:
  /** Description:
    Controls the EntityListValid flag for this ContainterNode object.
    Arguments:
    entityListValid (I) Controls flag.
    
    Remarks:
    This flag is typically set by update() and cleared by invalidate().     
  */
  void setEntityListValid(bool entityListValid);
  
  /** Description:
    Returns true if and only if the ChildrenUpToDate flag is set for this ContainterNode object.
    Arguments:
    nVpID (I) Viewport ID.
    Remarks:
    This flag is typically set by update() and cleared by addChild() and invalidate().
  */
  bool childrenUpToDate(OdUInt32 nVpID) const;

  /** Description:
    Returns true if and only if a regen is required for the specified Viewport object for this ContainterNode object.
    Arguments:
    viewportId (I) Viewport ID. 
  */
  bool needRegen(OdUInt32 viewportId) const;

  void addChildNode(OdGsEntityNode* pEnt);
  void turnOnLights(OdGsBaseVectorizeView& view);

  /** Description:
    Vectorizes the entities in all of the child nodes of this ContainerNode object.
    Arguments:
    view (I) Vectorize view object
    Remarks:
    Returns pointer to the first entity node inside container.
  */
  virtual OdGsEntityNode* updateList(OdGsBaseVectorizeView& view);
  
  /** Description:
    Vectorizes the entities in all of the child nodes of this ContainerNode object.
    Arguments:
    vectorizeView (I) VectorizeView object
  */
  virtual void displayEntityList(OdGsBaseVectorizeView& vectorizeView);

  /** Description:
    Returns pointer to the first entity node inside container.
  */
  OdGsEntityNode* firstEntityNode();
  /** Description:
    Returns pointer to the first entity node inside container.
  */
  const OdGsEntityNode* firstEntityNode() const;
  /** Description:
    Returns pointer to the last entity node inside container.
  */
  OdGsEntityNode* lastEntityNode();
  /** Description:
    Returns pointer to the last entity node inside container.
  */
  const OdGsEntityNode* lastEntityNode() const;
  /** Description:
    Returns light nodes list.
  */
  OdList<OdGsLightNode*> &lightNodesList();
  /** Description:
    Returns light nodes list.
  */
  const OdList<OdGsLightNode*> &lightNodesList() const;

  /** Description:
    Returns the Aware flags for the specified Viewport for this ContainerNode object.
    
    Arguments:
    viewportId (I) Viewport ID. 
    
    Remarks:
    awareFlags() returns a combination of zero or more of the following:
    
    @table
    Name                            Value
    kVpID                           0x00000001
    kVpRegenType                    0x00000002
    kVpRenderMode                   0x00000004
    kVpWorldToEye                   0x00000008
    kVpPerspective                  0x00000010
    kVpResolution                   0x00000020
    kVpMaxDevForCircle              0x00000040
    kVpMaxDevForCurve               0x00000080
    kVpMaxDevForBoundary            0x00000100
    kVpMaxDevForIsoline             0x00000200
    kVpMaxDevForFacet               0x00000400
    kVpCamLocation                  0x00000800
    kVpCamTarget                    0x00001000
    kVpCamUpVector                  0x00002000
    kVpCamViewDir                   0x00004000
    kVpViewport                     0x00008000
    kVpFrontBack                    0x00010000
    kVpFrozenLayers                 0x00020000
    kVpAllProps                     0x0003FFFF
  */ 
  OdUInt32 awareFlags(OdUInt32 viewportId) const;

  /** Description:
    Sets the Aware flags for the specified Viewport for this ContainerNode object.
    
    Arguments:
    viewportId (I) Viewport ID. 
    flags (I) Aware flags.
    
    Remarks:
    awareFlags() returns a combination of zero or more of the following:
    
    @table
    Name                            Value
    kVpID                           0x00000001
    kVpRegenType                    0x00000002
    kVpRenderMode                   0x00000004
    kVpWorldToEye                   0x00000008
    kVpPerspective                  0x00000010
    kVpResolution                   0x00000020
    kVpMaxDevForCircle              0x00000040
    kVpMaxDevForCurve               0x00000080
    kVpMaxDevForBoundary            0x00000100
    kVpMaxDevForIsoline             0x00000200
    kVpMaxDevForFacet               0x00000400
    kVpCamLocation                  0x00000800
    kVpCamTarget                    0x00001000
    kVpCamUpVector                  0x00002000
    kVpCamViewDir                   0x00004000
    kVpViewport                     0x00008000
    kVpFrontBack                    0x00010000
    kVpFrozenLayers                 0x00020000
    kVpAllProps                     0x0003FFFF
  */ 
  void setAwareFlags(OdUInt32 viewportId, OdUInt32 flags);

protected:
  void propagateLayerChanges(OdGsBaseVectorizeView& view);

public:
  ODRX_DECLARE_MEMBERS(OdGsContainerNode);

  /** Arguments:
    pModel (I) Pointer to the BaseModel object.
    pUnderlyingDrawable (I) Pointer to the underlying Drawable object.
    bTopLevel (I) true if container represents layout's block
  */
  OdGsContainerNode(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable, bool bTopLevel = true);
protected:
  OdGsContainerNode(const OdGsContainerNode& c);
public:

  ~OdGsContainerNode();

  /** Description:
    Returns true if and only if the EntityListValid flag is set for this ContainterNode object.
    Remarks:
    This flag is typically set by update() and cleared by invalidate().     
  */
  bool entityListValid() const;

  /** Description:
    Controls the ChildrenUpToDate flag for this ContainterNode object.
    Arguments:
    childrenUpToDate (I) Controls flag.
    nVpID (I) Viewport ID.
    Remarks:
    This flag is typically set by update() and cleared by addChild() and invalidate().
  */
  void setChildrenUpToDate(bool childrenUpToDate, OdUInt32* nVpID = NULL);

  /** Description:
    Adds a child node to this ContainerNode object.
    Arguments:
    pDrawable (I) Pointer to the Drawable object.
    unerased (I) Added child is unerased.
  */
  virtual void addChild(const OdGiDrawable* pDrawable, bool unerased = false);

  // adds information about the light if the light doesn't have gsNode yet
  virtual void addLight(const OdGiDrawable* pDrawable, const OdGeMatrix3d& model2World);

  /** Description:
    Removes the specified child node from this ContainerNode object.
    Arguments:
    pNode (I) Pointer to the child object. 
  */
  virtual void removeChild(OdGsNodeEx* pNode);

  void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent);

  void display(OdGsBaseVectorizeView& view);

  /** Description:
    Returns a reference to the spatial index for this ContainerNode object.
  */
  OdSiSpatialIndex& spatialIndex();
  /** Description:
    Returns a reference to the spatial index for this ContainerNode object.
  */
  const OdSiSpatialIndex& spatialIndex() const;

  /** Description:
    Note:
    This function is not implemented, and will generate a link error if you reference it.
  */
  void spatialQuery(const OdSiShape& query, OdSiVisitor& visitor);
  /** Description:
    Note:
    This function is not implemented, and will generate a link error if you reference it.
  */
  void spatialSequentalQuery(const OdSiShape& query, OdSiVisitor& visitor);

  /** Note:
    The default implementation of this function ignores the pParent argument.
  */
  void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);

  // GCAD
  void invalidateDrawOrder();

  /** Description:
    Returns summ of all aware flags for entire viewports list.
  */
  OdUInt32 currViewChanges() const;

  /** Description:
    Returns extents of this container node object.
    Arguments:
    extents (O) Reference to the OdGeExtents3d object which will receive current container node extents.
  */
  bool extents(OdGeExtents3d& extents) const;

  /** Description:
    Updates invalidVp flag for entire entities list.
  */
  void propagateInvalidVpFlag();

  bool isTopLevel() const;
  void setTopLevel(bool bVal);
  bool checkWorkset() const;
  void setCheckWorkset(bool bVal);
  void destroy();
  virtual OdGsContainerNode* makeClone() const;

  void destroySubitems();

  /** Description:
    Returns real extents of the node (for top level container only, for others it is NULL)
  */
  const OdGeExtents3d* realExtents(bool bNeedCalc = false) const;

  OdUInt32 maxLineWeightIndexUsed() const;

  /** Description:
    Sets real extents of the node (for top level container only, for others it is NULL)
  */
  void setRealExtents(const OdGeExtents3d& ext, OdUInt32 nMaxLw);

  void addRealExtents(const OdGeExtents3d& ext, OdUInt32 nLw);
  void invalidRealExtents();

  /** Description:
    Removes entities marked as erased.
  */
  void removeErased();

  /** Description:
    Returns number of child entities
  */
  int numberOfChildren() const { return m_nChild; }

  void destroySTree();

  virtual bool realExt(OdGeExtents3d& ext) const{ ext = m_realExtents; return true;}  
  virtual bool cacheIn(OdStreamBuf*);
  virtual bool cacheOut(OdStreamBuf*);

protected:
  mutable OdGeExtents3d m_realExtents; //Keeps real extents (for EXTMIN/MAX support)
  OdUInt32 m_maxLw;
};

inline bool OdGsContainerNode::entityListValid() const
{
  return GETBIT(m_flags, kEntityListValid);
}

inline void OdGsContainerNode::setEntityListValid(bool bValid)
{
  SETBIT(m_flags, kEntityListValid, bValid);
}

inline OdSiSpatialIndex& OdGsContainerNode::spatialIndex()
{
  return *m_pSpIndex.get();
}

inline const OdSiSpatialIndex& OdGsContainerNode::spatialIndex() const
{
  return *m_pSpIndex.get();
}

inline OdGsEntityNode* OdGsContainerNode::firstEntityNode()
{
  return m_pFirstEntity;
}

inline const OdGsEntityNode* OdGsContainerNode::firstEntityNode() const
{
  return m_pFirstEntity;
}

inline OdGsEntityNode* OdGsContainerNode::lastEntityNode()
{
  return m_pLastEntity;
}

inline const OdGsEntityNode* OdGsContainerNode::lastEntityNode() const
{
  return m_pLastEntity;
}

inline OdList<OdGsLightNode*> &OdGsContainerNode::lightNodesList()
{
  return m_lightPtrs;
}

inline const OdList<OdGsLightNode*> &OdGsContainerNode::lightNodesList() const
{
  return m_lightPtrs;
}

inline bool OdGsContainerNode::childrenUpToDate(OdUInt32 nVpID) const
{
  if(m_vpAwareFlags.size()>(int)nVpID)
    return !GETBIT(m_vpAwareFlags[nVpID], kChildrenNotUpToDate);
  return false;
}

inline void OdGsContainerNode::setChildrenUpToDate(bool bValid, OdUInt32* nVpID)
{
  if(nVpID)
  {
	  OdUInt32Array::size_type n = m_vpAwareFlags.size();
	  if(n <= (OdUInt32Array::size_type)*nVpID)
		  m_vpAwareFlags.insert(m_vpAwareFlags.end(), (*nVpID)+1-n, 0xFFFFFFFF);
	  SETBIT(m_vpAwareFlags[*nVpID], kChildrenNotUpToDate, !bValid);
  }
  else
  {
	  ODA_ASSERT(!bValid);
	  for(int i = 0; i < m_vpAwareFlags.size(); ++i)
		  SETBIT(m_vpAwareFlags[i], kChildrenNotUpToDate, true);
  }
}

inline OdUInt32 OdGsContainerNode::awareFlags(OdUInt32 nVpID) const
{
  if(m_vpAwareFlags.size()>(int)nVpID)
    return m_vpAwareFlags[nVpID] & ~kChildrenNotUpToDate;
  return 0xFFFFFFFF;
}

inline void OdGsContainerNode::setAwareFlags(OdUInt32 nVpID, OdUInt32 flags)
{
  flags &= ~kChildrenNotUpToDate;
  OdUInt32Array::size_type n = m_vpAwareFlags.size();
  if(n <= (OdUInt32Array::size_type)nVpID)
  {
    m_vpAwareFlags.insert(m_vpAwareFlags.end(), nVpID+1-n, 0xFFFFFFFF);
    m_vpAwareFlags[nVpID] = flags;
  }
  else
  {
    m_vpAwareFlags[nVpID] = ((m_vpAwareFlags[nVpID] & kChildrenNotUpToDate) | flags);
  }
}

inline bool OdGsContainerNode::needRegen(OdUInt32 nVpID) const
{
  if(!childrenUpToDate(nVpID))
    return true;

  OdUInt32 nAF = awareFlags(nVpID);
  return ( nAF == 0xFFFFFFFF || ( baseModel()->viewChanges(nVpID) & nAF) != 0 );
}

inline bool OdGsContainerNode::isTopLevel() const
{
  return GETBIT(m_flags, kTopLevel);
}

inline void OdGsContainerNode::setTopLevel(bool bVal)
{
  SETBIT(m_flags, kTopLevel, bVal);
}

inline bool OdGsContainerNode::checkWorkset() const
{
  return GETBIT(m_flags, kCheckWorkset);
}

inline void OdGsContainerNode::setCheckWorkset(bool bVal)
{
  ODA_ASSERT(isTopLevel());
  SETBIT(m_flags, kCheckWorkset, bVal);
}

#endif // __OD_GS_CONTAINER_NODE__
