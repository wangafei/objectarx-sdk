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

#ifndef __OD_GS_ENTITY_NODE__
#define __OD_GS_ENTITY_NODE__

#include "../Gs/GsNode.h"
#include "../Gs/GsBaseVectorizer.h"

#include "../Si/SiSpatialIndex.h"

/**
   {group:Structs}
*/
struct OdGsGeomUniquePortion
{
  OdGsLayerNode*  mpLayer;
  OdCmEntityColor mColor;
  OdGePoint3d mPoints[2];
};

struct OdGsGeomPortion
{
  OdGsLayerNode*    m_pLayer;
  OdRxObjectPtr     m_pGsMetafile;
  OdGsGeomPortion*  m_pNext;

  OdGsGeomPortion()
    : m_pLayer(0)
    , m_pGsMetafile(0)
    , m_pNext(0)
  {
  }

  void copyFrom(OdGsGeomPortion& c)
  {
    m_pLayer = c.m_pLayer;
    m_pGsMetafile = c.m_pGsMetafile;
    m_pNext = c.m_pNext;
  }
};

/** Description:
    This class implements OdGsNodeEx descendant objects that
    can serve as containers for other OdGsNodeEx objects.

    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsEntityNode : public OdGsNodeEx, public OdSiEntity
{
  friend class OdGsModuleObject;
  friend class OdGsBlockReferenceNode;

protected:
  OdGsEntityNode*         m_pNextEntity;

  OdGsEntityNode(const OdGsEntityNode& c);
public:
  OdGsEntityNode(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable, bool bSetGsNode = true);
  ~OdGsEntityNode();

  ODRX_DECLARE_MEMBERS(OdGsEntityNode);

  void setNextEntity(OdGsEntityNode* pNextEntity);
  OdGsEntityNode* nextEntity();
  const OdGsEntityNode* nextEntity() const;

  virtual OdGsEntityNode* makeClone() const = 0;

public:
  enum
  {
    kHasExtents         = OdGsNodeEx::kLastFlag << 1,
    kSpatiallyIndexed   = OdGsNodeEx::kLastFlag << 2,
    kMarkedToSkip       = OdGsNodeEx::kLastFlag << 3,
    kArrayAllocated     = OdGsNodeEx::kLastFlag << 4,
    kViewportDependent  = OdGsNodeEx::kLastFlag << 5,
    kOwned              = OdGsNodeEx::kLastFlag << 6,
    kDrawableRegenDraw  = OdGsNodeEx::kLastFlag << 7,
    kEntityUnerased     = OdGsNodeEx::kLastFlag << 8,
    kInvisible          = OdGsNodeEx::kLastFlag << 9,
    kLineweightBit1     = OdGsNodeEx::kLastFlag << 10, // reserve 5 bits for maximal lineweight
    kLineweightBit2     = OdGsNodeEx::kLastFlag << 11,
    kLineweightBit3     = OdGsNodeEx::kLastFlag << 12,
    kLineweightBit4     = OdGsNodeEx::kLastFlag << 13,
    kLineweightBit5     = OdGsNodeEx::kLastFlag << 14,
    kLineweightBitMask  = kLineweightBit1 | kLineweightBit2 | kLineweightBit3 | kLineweightBit4 | kLineweightBit5,
    kExtentsOutOfMS     = OdGsNodeEx::kLastFlag << 15,
    kNonSelectable      = OdGsNodeEx::kLastFlag << 16,
    kSkipSelection      = OdGsNodeEx::kLastFlag << 17,
    kErased             = OdGsNodeEx::kLastFlag << 18,
    kInWorkset          = OdGsNodeEx::kLastFlag << 19,
    kTopLevel           = OdGsNodeEx::kLastFlag << 20,

    kLastFlag           = kTopLevel
  };

  /** Description:
    Returns true if and only if this EntityNode object is spatially indexed.
  */
  bool spatiallyIndexed() const;
  /** Description:
    Controls the spatial indexing of this EntityNode object.
    Arguments:
    spatiallyIndexed (I) Controls spatially indexed.
  */
  void setSpatiallyIndexed(bool bIndexed);

  /** Description:
    Returns true if and only if this EntityNode object is the child of a ContainerNode object.
  */
  bool owned() const;
  /** Description:
    Controls the *owned* status of this EntityNode object.
    Arguments:
    owned (I) Controls *owned* status.
  */
  void setOwned(bool owned);

  /** Remarks:
    Returns true if and only if the underlying GiDrawable object(s) have *extents*.
  */
  bool hasExtents() const;

  /** Description:
    Returns true if and only if this EntityNode object is marked to be skipped.
  */
  bool markedToSkip() const;
  /** Description:
    Controls the MarkToSkip status of this EntityNode object.
    Arguments:
    markToSkip (I) Controls MarkToSkip.
  */
  void markToSkip(bool markToSkip);

  bool markedAsNonSelectable() const;
  void markAsNonSelectable(bool val);

  bool isMarkedSkipSelection() const;
  void markSkipSelection(bool val);

  bool isMarkedErased() const;
  void markErased(bool val);

  bool isInWorkset() const;
  void setInWorkset(bool val);

  bool entityUnerased() const;
  void setEntityUnerased(bool flag);

  bool isExtentsOutOfModelSpace() const;
  void setExtentsOutOfModelSpace(bool flag);

  bool isInvisible() const;

  bool isDrawableRegenDraw() const;

  void resetInvalidVpFlag();

  OdDb::LineWeight getMaxLineweightUsed() const;
  void addLineweight(OdUInt32 lwd);
  void setLineweight(OdUInt32 lwd);
  OdUInt32 getLineweight() const;

public:
  virtual void select(OdGsBaseVectorizeView& view) = 0;

  virtual bool layersChanged(OdGsBaseVectorizeView& view) const = 0;

  virtual OdUInt32 awareFlags(OdUInt32 viewportId) const = 0;

  TD_USING(OdGsNodeEx::extents);

  virtual bool isEmpty() = 0;
  virtual bool hasMetafile(OdGsBaseVectorizeView&, bool) { return true; }

  virtual OdGeExtents3d entityExtents() const = 0;

  // GCAD
  virtual void playAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode) = 0;
  virtual bool hasDataToPlayAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode) = 0;

  virtual bool realExt(OdGeExtents3d& ext) const = 0;

  virtual bool isValidMetafile(OdUInt32 viewportId, OdUInt32 nViewChangeMask, OdUInt32 &nAwareFlags) const = 0;

  // GCAD: 扩展标志
  virtual bool forceViewportDependence() const { return false; } // 将来改进，去掉该标志
  virtual bool referenceAsEntity() const { return false; } // 将来改进，去掉该标志

  virtual bool isPdfReference() const { return false; }
};

class GS_TOOLKIT_EXPORT OdGsEntityNodeEx : public OdGsEntityNode
{
  friend class OdGsModuleObject;
  friend class OdGsBlockReferenceNode;
  friend class OdGsMetafileMP;
protected:
  mutable OdGeExtents3d   m_extents;

  class Metafile : public OdRxObject
  {
  public:
    void* operator new(size_t size);
    void  operator delete(void* p);
      //ODGI_USE_HEAP()
    public:
      Metafile();
      ~Metafile();
      bool play(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode = kMfDisplay) const;
      bool hasDataToPlay(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode = kMfDisplay) const;
      bool layersChanged(OdUInt32 nVpId) const;
      bool containsVpFrozenLayers() const;
      bool isEmpty() const;
      bool cacheIn(OdGsBaseModel* pModel,OdStreamBuf*);
      bool cacheOut(OdGsBaseModel* pModel,OdStreamBuf*);

      OdUInt32            m_nAwareFlags;
      OdGeExtents3d       m_extents;
      OdGsGeomPortion     m_first;
  };

  /** Description:
    This template class is a specialization of the OdSmartPtr class for Metafile object pointers.
  */
  typedef OdSmartPtr<Metafile> MetafilePtr;

  /** Description:
      This template class is a specialization of the OdArray class for MetafilePtr objects.
  */
  typedef OdArray<MetafilePtr> MetafilePtrArray;

  struct MetafileStrg
  {
    OdUInt8 data[odmax(sizeof(MetafilePtrArray), sizeof(OdRxObject*))];
  };

  mutable MetafileStrg m_metafileStrg;

protected:
  void destroyMetafile();
  void clearMetafileArray();

  /** Description:
    Returns a reference to the *metafile* array of this EntityNode object as an array of MetafilePtr.
  */
  MetafilePtrArray& metafileArray() const;

  /** Description:
    Returns the array the objects in the *metafile* array of this EntityNode object.
  */
  OdGsEntityNodeEx::MetafilePtr metafile() const;
  /** Description:
    Returns the specified MetafilePtr from the *metafile* array of this EntityNode object.
    Arguments:
    metafileIndex (I) Metafile index.
  */
  OdGsEntityNodeEx::MetafilePtr metafileAt(int metafileIndex) const;
  
  /** Description:
    Sets the *metafile* array for this EntityNode object from the specified array of objects.
    metafiles (I) Array of *metafile* objects.
  */
  void setMetafile(OdGsEntityNodeEx::Metafile* metafiles);
  /** Description:
    Sets the specified entry in the *metafile* array of this EntityNode object.
    Arguments:
    metafileIndex (I) Metafile index.
    pMetafile (I) Pointer to the Metafile object
  */
  void setMetafileAt(int metafileIndex, OdGsEntityNodeEx::Metafile* pMetafile);
  /** Description:
    Convert a RegenType dependent cache to Viewport dependent cache.
    Arguments:
    view (I) VectorizeView object for which cache is to be converted.
  */
  virtual void convertToViewportDependent(const OdGsBaseVectorizeView& view);

  /** Description:
    Allocate array of metafiles; set flag kArrayAllocated.
  */
  void allocateMetafileArray();

  /**
    Arguments:
    view (I) VectorizeView object for which *metafile* is to be returned.
    checkVpChanges (I) Check for viewport changes if and only if true.
  */
  const OdGsEntityNodeEx::Metafile *metafile(OdGsBaseVectorizeView& view, bool bCheckVpChanges, bool bFindCompatible = true);
  /**
    Arguments:
    view (I) VectorizeView object for which *metafile* is to be returned.
  */
  void setMetafile(OdGsBaseVectorizeView& view, OdGsEntityNodeEx::Metafile* metafiles);
  virtual OdGsEntityNodeEx::Metafile* findCompatibleCache(const OdGsBaseVectorizeView& keyView);

public:
  ODRX_DECLARE_MEMBERS(OdGsEntityNodeEx);

  /** Arguments:
    pModel (I) Pointer to the BaseModel object.
    pUnderlyingDrawable (I) Pointer to the underlying Drawable object.
  */
  OdGsEntityNodeEx(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable, bool bSetGsNode = true);
protected:
  OdGsEntityNodeEx(const OdGsEntityNodeEx& c);
public:
  ~OdGsEntityNodeEx();

  virtual void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent);

  /** Description:
    Returns the Aware flags for the specified Viewport for this ContainerNode object.
    
    Arguments:
    viewportId (I) Viewport ID. 
    
    Remarks:
    awareFlags() returns a combination of zero or more of the following:
    
    @table
    Name                            Value
    kSuppressViewportDraw           0x01
    kDrawInvisibleEnts              0x02
    kDrawLayerOff                   0x04
    kDrawLayerFrozen                0x08
    kIgnoreFillPlane                0x10
    kFillPlaneSet                   0x20
  */ 
  virtual OdUInt32 awareFlags(OdUInt32 viewportId) const;

  virtual void display(OdGsBaseVectorizeView& view);

  virtual void select(OdGsBaseVectorizeView& view);

  virtual void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);

  void assumeMetafileSize(OdUInt32 viewportId) const; // GCAD EX
  bool isValidMetafile(OdGsBaseVectorizeView& view) const; // GCAD EX
  virtual bool isValidMetafile(OdUInt32 viewportId, OdUInt32 nViewChangeMask, OdUInt32 &nAwareFlags) const; // GCAD EX

  const OdGeExtents3d& getExtents() const { return m_extents; }

  virtual bool extents(OdGeExtents3d& extents) const;
  virtual bool extents(const OdGsView* pView, OdGeExtents3d& ext) const;

  virtual OdGeExtents3d entityExtents() const { return getExtents(); }

  /** Description:
    Returns true if the node has no graphical content.
  */
  virtual bool isEmpty();
  virtual bool hasMetafile(OdGsBaseVectorizeView& view, bool bCheckVpChanges);

  void destroy(){}
  virtual OdGsEntityNode* makeClone() const;

  virtual void propagateLayerChanges(OdGsBaseVectorizeView& view);
  virtual bool layersChanged(OdGsBaseVectorizeView& view) const;

  virtual void playAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);
  virtual bool hasDataToPlayAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);

  virtual bool realExt(OdGeExtents3d& ext) const;

  virtual void subUpdate() {}

  virtual bool cacheIn(OdStreamBuf*);
  virtual bool cacheOut(OdStreamBuf*);

  friend OdSmartPtr<OdGsEntityNodeEx::Metafile> odgsCreateMetafile();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsEntityNode object pointers. 
*/
typedef OdSmartPtr<OdGsEntityNode> OdGsEntityNodePtr;
typedef OdSmartPtr<OdGsEntityNodeEx> OdGsEntityNodeExPtr;


inline void OdGsEntityNode::setNextEntity(OdGsEntityNode* pNextEntity)
{
  m_pNextEntity = pNextEntity;
}

inline OdGsEntityNode* OdGsEntityNode::nextEntity()
{
  return m_pNextEntity;
}

inline const OdGsEntityNode* OdGsEntityNode::nextEntity() const
{
  return m_pNextEntity;
}

inline bool OdGsEntityNode::hasExtents() const
{
  return GETBIT(m_flags, kHasExtents);
}

inline bool OdGsEntityNode::markedToSkip() const
{
  return GETBIT(m_flags, kMarkedToSkip);
}

inline void OdGsEntityNode::markToSkip(bool bSkip)
{
  SETBIT(m_flags, kMarkedToSkip, bSkip);
}

inline bool OdGsEntityNode::spatiallyIndexed() const
{
  return GETBIT(m_flags, kSpatiallyIndexed);
}

inline void OdGsEntityNode::setSpatiallyIndexed(bool bIndexed)
{
  SETBIT(m_flags, kSpatiallyIndexed, bIndexed);
}

inline bool OdGsEntityNode::owned() const
{
  return GETBIT(m_flags, kOwned);
}

inline void OdGsEntityNode::setOwned(bool bOwned)
{
  SETBIT(m_flags, kOwned, bOwned);
}

inline bool OdGsEntityNode::entityUnerased() const
{
  return GETBIT(m_flags, kEntityUnerased);
}

inline void OdGsEntityNode::setEntityUnerased(bool flag)
{
  SETBIT(m_flags, kEntityUnerased, flag);
}

inline bool OdGsEntityNode::isInvisible() const
{
  return GETBIT(m_flags, kInvisible);
}

inline bool OdGsEntityNode::isDrawableRegenDraw() const
{
  return GETBIT(m_flags, kDrawableRegenDraw);
}

inline bool OdGsEntityNode::isExtentsOutOfModelSpace() const
{
  return GETBIT(m_flags, kExtentsOutOfMS);
}

inline void OdGsEntityNode::setExtentsOutOfModelSpace(bool flag)
{
  SETBIT(m_flags, kExtentsOutOfMS, flag);
}

inline void OdGsEntityNode::resetInvalidVpFlag()
{
  if (invalidVp())
  {
    setInvalidVp(false);
  }
}

inline bool OdGsEntityNode::markedAsNonSelectable() const
{
  return GETBIT(m_flags, kNonSelectable);
}

inline void OdGsEntityNode::markAsNonSelectable(bool val)
{
  SETBIT(m_flags, kNonSelectable, val);
}

inline bool OdGsEntityNode::isMarkedSkipSelection() const
{
  return GETBIT(m_flags, kSkipSelection);
}

inline void OdGsEntityNode::markSkipSelection(bool val)
{
  SETBIT(m_flags, kSkipSelection, val);
}

inline bool OdGsEntityNode::isMarkedErased() const
{
  return GETBIT(m_flags, kErased);
}

inline void OdGsEntityNode::markErased(bool val)
{
  SETBIT(m_flags, kErased, val);
}

inline bool OdGsEntityNode::isInWorkset() const
{
  return GETBIT(m_flags, kInWorkset);
}

inline void OdGsEntityNode::setInWorkset(bool val)
{
  SETBIT(m_flags, kInWorkset, val);
}

#endif // __OD_GS_ENTITY_NODE__
