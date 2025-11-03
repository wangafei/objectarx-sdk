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

#ifndef __OD_GS_NODE__
#define __OD_GS_NODE__

#include "../Gs/GsBaseModel.h"
#include "../ChunkAllocator.h"

class OdGsContainerNode;
class OdGsLayerNode;
class OdStreamBuf;
/** Description:
    This class is the base class for custom GsNode objects which implement custom caching support 
    for Teigha vectorization applications.

    Remarks:
    Cached rendering information may be stored in a custom GsNode descendant
    for each drawable in an OdDbDatabase object.
    
    This cached information can be fed into the Teigha vectorization
    framework during a redraw instead of making the usual calls to subWorldDraw() and 
    subViewportDraw(), thereby greatly improving the speed of redraws.

    Remarks:
    Clients should derive their custom node classes from this class.

    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT ODRX_ABSTRACT OdGsNodeEx : public OdGsNode
{
  friend class OdGsBaseModel;
  friend class OdGsBaseVectorizeView;
  friend class GcadGsModel;

protected:
  mutable OdGsNodeEx* m_pPrev;
  mutable OdGsNodeEx* m_pNext;

  GS_STATIC_EXPORT static AllocatorArray s_aAlloc;

  OdGsBaseModel*    m_pModel;
  void*             m_underlyingDrawable;
  OdGsHighlightBranchPtr m_pHLTBranch;

  enum
  {
    kPersistent = 0x00000001,
    kContainer  = 0x00000002,
    kHLT        = 0x00000004, // Highlight
    kHLT_All    = 0x00000008, // Highlight whole branch
    kHLT_SubEnt = 0x00000010, // Highlight subentities
    kEntityModified = 0x00000020,
    kBlock      = 0x00000040,
    kSyncDrawable=0x00000080,
    kUnloaded   = 0x00000100,
    kHidden     = 0x00000200,
    kLastFlag   = 0x00000200
  };

  mutable OdUInt32  m_flags;

  enum { kInvalidateVp = 0x80000000 };
  inline bool invalidVp() const { return GETBIT(m_flags, kInvalidateVp); }
  inline void setInvalidVp(bool val) { SETBIT(m_flags, kInvalidateVp, val); }

  /** Description:
    Removes the associations between the underlying Drawable object and this GsNode object.
  */
  void clearDrawable();
  void setToDrawable(const OdGiDrawable* pUnderlyingDrawable);

  
public:
  ODRX_DECLARE_MEMBERS(OdGsNodeEx);

  void* operator new(size_t);
  void operator delete(void *);

  /** Note:
      OdGsNodeEx objects perform no reference counting. This function does nothing but return.
  */
  void addRef();

  /** Note:
      OdGsNodeEx objects perform no reference counting. This function does nothing but return.
  */
  void release();

  /** Arguments:
    pModel (I) Pointer to the BaseModel object.
    pUnderlyingDrawable (I) Pointer to the underlying Drawable object.
  */
  OdGsNodeEx(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable, bool bSetGsNode = true);

protected:
  OdGsNodeEx(const OdGsNodeEx& c);
  virtual ~OdGsNodeEx();  // protected -> deconstructed by OdGsBaseModel ONLY

public:
  /** Description:
    Pointer to the BaseModel object associated with this Node object.
  */
  OdGsBaseModel* baseModel() const;

  OdGsModel* model() const;

  /** Description:
    Returns true if and only if this Node object serves as a container for other Node objects.
  */
  bool isContainer() const;

  bool isBlock() const;

  virtual bool isReference() const{return false;}

  bool isSyncDrawable() const { return GETBIT(m_flags, kSyncDrawable); }

  /** Description:
    Invalidates the cached data within this object.
    
    Arguments:
    pParent (I) Pointer to the ContainerNode object for this Node object.
    pView (I) Pointer to the VectorizeView object for which data are to be invalidated.
    mask (I) Mask.
    Remarks:
    The cached data will be regenerated the next time this Node object is accessed.
  */
  virtual void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask) = 0;

  /** Description:
    Returns the underlying Drawable object associated with this Node object.
  */
  OdGiDrawablePtr underlyingDrawable() const;

  /** Description:
    Returns ObjectID of the underlying Drawable object associated with this Node object.
  */
  OdDbStub* underlyingDrawableId() const;

  /** Description:
    Updates the cached data within this Node object for the specified VectorizeView and ContainerNode objects. 
    Arguments:
    pParent (I) Pointer to the ContainerNode object for this Node object.
    view (I) VectorizeView object for which data are to be updated.
  */
  virtual void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent) = 0;

  /** Description:
    Paints the specified *view* with the cached data associated with this Node object.
    Arguments:
    view (I) View to be painted.
  */
  virtual void display(OdGsBaseVectorizeView& view) = 0;

  /** Description:
    Invalidates parts of cache depended on layers modified since last regeneration.
    
    Remarks:
    For internal use only.
    Returns *this* if and only if the this node is one of modified layers.
  */
  virtual void propagateLayerChanges(OdGsBaseVectorizeView& view) = 0;

  virtual void highlight(bool bDoIt, bool bWholeBranch);

  bool isHighlighted() const;
  bool isHighlightedAll() const;

  virtual void destroy() = 0;

  void setUnloaded(bool isUnloaded);
  bool isUnloaded() const;

  void hide(bool bDoIt);
  bool isHidden() const;

  TD_USING(OdGsNode::extents);

  virtual bool extents(const OdGsView* pView, OdGeExtents3d& ext) const;

  virtual OdDb::LineWeight getMaxLineweightUsed() const;

  virtual void setDrawableNull();

  bool isHighlightedSubEnt() const;
  void highlightSubEnt(bool bDoIt);

  void setHighlightBranch(OdGsHighlightBranchPtr pBranch);
  const OdGsHighlightBranchPtr highlightBranch() const;
  void clearHighlightBranch();
  void removeHighlightBranch();

  virtual bool cacheIn(OdStreamBuf*){return false;}
  virtual bool cacheOut(OdStreamBuf*){return false;}
};


inline OdDbStub* OdGsNodeEx::underlyingDrawableId() const
{
  if(GETBIT(m_flags, kPersistent))
    return reinterpret_cast<OdDbStub*>(m_underlyingDrawable);
  return 0;
}

inline void OdGsNodeEx::highlight(bool bDoIt, bool bWholeBranch)
{
  SETBIT(m_flags, kHLT, bDoIt);
  SETBIT(m_flags, kHLT_All, bWholeBranch);
}

inline bool OdGsNodeEx::isHighlighted() const
{
  return GETBIT(m_flags, kHLT);
}

inline bool OdGsNodeEx::isHighlightedAll() const
{
  return GETBIT(m_flags, kHLT_All);
}

inline OdGsBaseModel* OdGsNodeEx::baseModel() const
{
  return const_cast<OdGsBaseModel*>(m_pModel);
}

inline bool OdGsNodeEx::isContainer() const
{
  return GETBIT(m_flags, kContainer);
}

inline bool OdGsNodeEx::isHighlightedSubEnt() const
{
  return GETBIT(m_flags, kHLT_SubEnt);
}

inline void OdGsNodeEx::highlightSubEnt(bool bDoIt)
{
  SETBIT(m_flags, kHLT_SubEnt, bDoIt);
}

inline void OdGsNodeEx::setHighlightBranch(OdGsHighlightBranchPtr pBranch)
{
  m_pHLTBranch = pBranch;
}

inline const OdGsHighlightBranchPtr OdGsNodeEx::highlightBranch() const
{
  return m_pHLTBranch;
}

inline void OdGsNodeEx::clearHighlightBranch()
{
  m_pHLTBranch = NULL;
}

inline  bool OdGsNodeEx::isBlock() const
{
  return GETBIT(m_flags, kBlock);
}

inline void OdGsNodeEx::setUnloaded(bool isUnloaded)
{
  SETBIT(m_flags, kUnloaded, isUnloaded);
}

inline bool OdGsNodeEx::isUnloaded() const
{
  return GETBIT(m_flags, kUnloaded);
}

inline void OdGsNodeEx::hide(bool bDoIt)
{
  SETBIT(m_flags, kHidden, bDoIt);
}

inline bool OdGsNodeEx::isHidden() const
{
  return GETBIT(m_flags, kHidden);
}

#endif // __OD_GS_NODE__
