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
#ifndef __OD_GS_BLOCKREFERENCE_NODE__
#define __OD_GS_BLOCKREFERENCE_NODE__

#include "GsEntityNode.h"

/** Description:

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class OdSiSelBaseVisitor : public OdSiVisitor
{
public:
  virtual const OdSiShape* query() const = 0;
  virtual void resetQuery(const OdSiShape* pQuery) = 0;

  virtual void visit( OdSiEntity* pSiEnt, bool /*bCompletelyInside*/, const OdSiShape* pQuery ) = 0;
};


// forward declarations
class OdGsBlockReferenceNodeImpl;
class OdGsBlockNode;

/** Description:
    Service class for handling of viewport aware flags array

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsAwareFlagsArray
{
public:
  OdGsAwareFlagsArray(){}
  OdGsAwareFlagsArray(const OdGsAwareFlagsArray& c)
    : m_vpAwareFlags(c.m_vpAwareFlags)
  {
  }
  enum
  {
    kChildrenNotUpToDate = 0x80000000
  };
  void setChildrenUpToDate(bool childrenUpToDate, const OdUInt32 nVpID);
  bool childrenUpToDate(OdUInt32 nVpID) const;
  OdUInt32 get(OdUInt32 nVpID) const;
  void set(OdUInt32 nVpID, OdUInt32 flags);
  void clear() { m_vpAwareFlags.clear(); }

private:
  // viewport aware flags
  OdUInt32Array m_vpAwareFlags;
};

/** Description:
    This class is the base class for implementation of GS reference nodes.
    Derivatives of this class implement different model of storing referenced objects.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBlockReferenceNodeImpl
{
public:
  OdGsBlockReferenceNodeImpl();
  void* operator new(size_t);
  void  operator delete(void*);

  void addRef()
  {
    ++m_nRefCounter;
  }
  void release()
  {
    ODA_ASSERT((m_nRefCounter > 0));
    if (!(--m_nRefCounter))
      delete this;
  }
  long numRefs() const { return m_nRefCounter; }

  /** Description:
    This is fabric method, it creates and return instance of appropriate type of reference implementation.
    
    Arguments:
    pModel (I) Pointer to the Model object.
    pInsert (I) Pointer to the corresponding Db block reference
    Remarks:
  */
  static OdGsBlockReferenceNodeImpl* create(OdGsBaseModel* pModel, const OdGiDrawable*);

  // Main methods, used for implementing OdGsNodeEx interface
  virtual OdUInt32 updateSubitems(OdGsBaseVectorizeView& view,
    const OdDbStub*& blockId, OdGeExtents3d& extents, OdUInt32& lwd, OdGsBaseModel* pModel);
  
  virtual OdUInt32 updateSubitemsImpl(OdGsBaseVectorizeView& view,
    const OdGiDrawable* pBlock, OdGeExtents3d& extents, OdUInt32& lwd) = 0;
  virtual void display(OdGsBaseVectorizeView& view) = 0;

  // Following methods return true if operation succeded (invalidation
  // or destroying leave the object valid). Else false is returned, which means that
  // OdGsNodeEx should release the instance and recreate m_pImpl.
  virtual bool invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView,
                          OdUInt32 mask) = 0;
  virtual bool destroy() = 0;
  virtual bool destroySubitems() = 0;

  virtual bool select(OdGsBaseVectorizeView& view, OdSiSelBaseVisitor* pVisitor,
                      const OdSiShape* pShape, bool bHasExtents, OdGsView::SelectionMode mode) = 0;
  // Methods for traversing internal subitems
  virtual OdGsEntityNode* firstEntity() = 0;
  virtual OdGsBlockReferenceNodeImpl* clone() const = 0;
  virtual void playAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode) = 0;
  virtual bool isSharedReference() const { return false; }
  virtual bool isSharedDefinition() const { return false; }
  virtual bool layersChanged(OdGsBaseVectorizeView& view) const;

  virtual bool forceSubitemsUpdate(OdGsBaseVectorizeView& /*view*/) { return false; }

  virtual bool invalidateSTree(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask) { return false; }
  virtual void destroySTree() {}

  virtual bool realExt(OdGeExtents3d& /*ext*/) const{return false;}
  virtual bool cacheIn(OdStreamBuf*){return false;}
  virtual bool cacheOut(OdStreamBuf*){return false;}

  virtual bool hasEliminatedNodes() const{return false;}
protected:
  virtual ~OdGsBlockReferenceNodeImpl();

protected:
  OdRefCounter m_nRefCounter;
};

namespace GCSS
{
  class GcSiSelectVisitor;
}
/** Description:

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBlockReferenceNode
  : public OdGsEntityNodeEx  //@lmj
  , protected OdGsAwareFlagsArray
{
public:
  ODRX_DECLARE_MEMBERS(OdGsBlockReferenceNode);
  
  OdGsBlockReferenceNode(OdGsBaseModel* pModel, const OdGiDrawable* pInsert,
                         bool bSetGsNode);
protected:
  OdGsBlockReferenceNode(const OdGsBlockReferenceNode& c);
public:
  ~OdGsBlockReferenceNode();
  
  // additional flags for processing of inserts
  enum
  {
    kIsXref = OdGsEntityNode::kLastFlag << 1, // kValid
    kLastFlag = kIsXref
  };

  void setIsXref(bool b) { SETBIT(m_flags, kIsXref, b); }
  bool isXref() const    { return GETBIT(m_flags, kIsXref); }
  
  virtual OdGsEntityNode* makeClone() const;
  virtual bool layersChanged(OdGsBaseVectorizeView& view) const;
  // implementation of OdGsEntityNode interface:
  virtual void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent);
  virtual void propagateLayerChanges(OdGsBaseVectorizeView& view);
  
  virtual void display(OdGsBaseVectorizeView& view);
  
  virtual void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);
  virtual void destroy();
  virtual void destroySubitems();
  
  virtual bool select(OdGsBaseVectorizeView& view, OdSiSelBaseVisitor*, const OdSiShape* pQuery,
                      OdGsView::SelectionMode mode);
  
  /** Description:
      Returns the Aware flags for the specified Viewport for object.
      Arguments:
      viewportId (I) Viewport ID. 
  */ 
  virtual OdUInt32 awareFlags(OdUInt32 viewportId) const;
  
  /** Description:
      Returns true if the node has no graphical content.
  */
  virtual bool isEmpty();

  virtual OdGsEntityNode* firstEntity();
  virtual OdGsEntityNode* firstAttrib() { return m_pFirstAttrib; }
  virtual void updateImpl(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert);

  void restoreUpdate(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert);

  void clearBlockNode();
  OdGsBlockNode* blockNode() const { return m_pBlockNode; }
  OdGsEntityNode* firstEntityOwnCopy();

  bool isLayerLocked(OdGsBaseVectorizeView& view) const;

  virtual bool hasDataToPlayAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);
  
  virtual bool invalidateSTree(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);

  virtual bool isReference() const{return true;}
protected:
  OdGiClipBoundary* initClipBoundary(OdGsBaseVectorizeView& view);
  virtual void setChildrenUpToDate(bool childrenUpToDate, const OdUInt32 nVpID);
  virtual bool childrenUpToDate(OdUInt32 nVpID) const;
  void updateAttributes(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert,
                        OdGsBaseModel* pModel, OdGeExtents3d& extents, OdGsEntityNode*& pFirstAttrib,
                        const OdGsHighlightBranchPtr pHLTBranch);
  // Tool methods
  void setAwareFlags(OdUInt32 viewportId, OdUInt32 nAwareFlags);
  virtual void playAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);
  void doUpdateImpl(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert);
  void initBlockNode(const OdGiDrawable* pInsert);
  void initLayer(OdGsBaseVectorizeView& view);
  bool isLayerVisible(OdGsBaseVectorizeView& view);
  void setMetafile(OdGsBaseVectorizeView& view, OdGsBaseModel* pModel, OdGsGeomPortion& firstGeomPortion, bool needAwareFlags = false);

  virtual bool isValidMetafile(OdUInt32 viewportId, OdUInt32 nViewChangeMask, OdUInt32 &nAwareFlags) const { return false; }

  virtual bool realExt(OdGeExtents3d& ext) const;
  virtual bool cacheIn(OdStreamBuf*);
  virtual bool cacheOut(OdStreamBuf*);
  
protected:
  // Pointer to layer node
  OdGsLayerNode* m_pLayer;
  // Pointer to implementation object
  OdGsBlockReferenceNodeImpl* m_pImpl;
  // Pointer to the node, corresponding to the block table record  
  OdGsBlockNode* m_pBlockNode;
  // Number of highlighted children nodes
  //OdUInt32 m_nChildHighlighted;
  // list of attributes
  OdGsEntityNode* m_pFirstAttrib;

  friend class GCSS::GcSiSelectVisitor;
};

/** Description:

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsMInsertBlockNode: public OdGsBlockReferenceNode
{
public:
  ODRX_DECLARE_MEMBERS(OdGsMInsertBlockNode);
  
  OdGsMInsertBlockNode(OdGsBaseModel* pModel, const OdGiDrawable* pInsert, bool bSetGsNode);
protected:
  OdGsMInsertBlockNode(const OdGsMInsertBlockNode& c);
public:
  ~OdGsMInsertBlockNode();

  virtual void updateImpl(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert);

  virtual void display(OdGsBaseVectorizeView& view);

  virtual void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);
  virtual void destroy();
  virtual void destroySubitems();

  virtual bool select(OdGsBaseVectorizeView& view, OdSiSelBaseVisitor*, const OdSiShape* pQuery,
                      OdGsView::SelectionMode mode);

  virtual OdGsEntityNode* firstEntity();
  virtual OdGsEntityNode* firstAttrib();
  virtual OdGsEntityNode* makeClone() const;
  virtual void playAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);

protected:
  void updateWithClipping(OdGsBaseVectorizeView& view, OdGiDrawable* pInsert, 
                          std::auto_ptr<OdGiClipBoundary>& pClipBoundary);
  void updateWithoutClipping(OdGsBaseVectorizeView& view, OdGiDrawable* pInsert);

  void destroyCollection();

  bool selectSubitems(OdGsBaseVectorizeView& view, const OdGeMatrix3d& blockTransf,
                      OdSiSelBaseVisitor* pVisitor, const OdSiShape* pQuery, OdGsView::SelectionMode mode,
                      int nCols, int nRows, double sx, double sy);
  bool selectAttributes(OdGsBaseVectorizeView& view, const OdGeMatrix3d& blockTransf,
                        int nCols, int nRows, double sx, double sy);

  void getMInsertParameters(OdGiDrawable* pInsert, const OdGeMatrix3d& blockTransf,
                            int& nCols, int& nRows, double& sx, double& sy, OdGsBaseVectorizeView& view);
  void adjustCollectionSize(unsigned int nItems, OdGiDrawable* pInsert);
  void updateExtents(OdGiDrawable* pInsert, const OdGeMatrix3d& blockTransf, OdGsBaseVectorizeView& view);

protected:
  class GS_TOOLKIT_EXPORT CollectionItem
  {
  public:
    CollectionItem() : m_nodeImp(0), m_pFirstAttrib(0) { }
    CollectionItem(const CollectionItem& c):
    m_nodeImp(c.m_nodeImp), m_pFirstAttrib(c.m_pFirstAttrib){}
    void copyFrom(const CollectionItem& c);

    OdGsBlockReferenceNodeImpl* imp() { return m_nodeImp; }
    const OdGsBlockReferenceNodeImpl* imp() const { return m_nodeImp; }
    OdGsEntityNode* firstAttrib() { return m_pFirstAttrib; }
    const OdGsEntityNode* firstAttrib() const { return m_pFirstAttrib; }

  public:
    OdGsBlockReferenceNodeImpl* m_nodeImp;
    OdGsEntityNode* m_pFirstAttrib;
  };
  class Collection: public OdArray<CollectionItem>
  {
  public:
    Collection(): OdArray<CollectionItem>(){}
    Collection(const Collection& c);
    ~Collection();
    void adjustSize(unsigned int nItems, OdGiDrawable* pInsert, OdGsBaseModel* pModel);
  };
  // Collection of implementation objects, representing clipped MINSERT.
  // (If MINSERT is not clipped, it's represented by only implementation 
  // object OdGsBlockReferenceNode::m_pImpl)
  Collection* m_pCollectionImpl;
  OdGeMatrix3d m_xModelToWorld;

  friend class GCSS::GcSiSelectVisitor;
};

/** Description:

    Library: TD_Gs

    {group:OdGs_Classes} 
*/

class OdGsPdfBlockNode;

class GS_TOOLKIT_EXPORT OdGsPdfReferenceNode : public OdGsEntityNodeEx
{
public:
  ODRX_DECLARE_MEMBERS(OdGsPdfReferenceNode);
  
  OdGsPdfReferenceNode(OdGsBaseModel* pModel, const OdGiDrawable* pInsert,
                         bool bSetGsNode);
protected:
  OdGsPdfReferenceNode(const OdGsPdfReferenceNode& c);
public:
  ~OdGsPdfReferenceNode();
  
  virtual OdGsEntityNode* makeClone() const;
  // implementation of OdGsEntityNode interface:
  virtual void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent);
  
  virtual void display(OdGsBaseVectorizeView& view);
  
  virtual void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);
  virtual void destroy();
  virtual void destroySubitems();
  
  virtual bool select(OdGsBaseVectorizeView& view, OdSiSelBaseVisitor*, const OdSiShape* pQuery,
                      OdGsView::SelectionMode mode);
   
  /** Description:
      Returns true if the node has no graphical content.
  */
  virtual bool isEmpty();

  virtual OdGsEntityNode* firstEntity();
  virtual void updateImpl(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert);
  
  void clearBlockNode();
  OdGsEntityNode* firstEntityOwnCopy();

  virtual bool hasDataToPlayAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);
  
  void detach();
  
  OdDbBaseDatabase* blockDatabase(){return m_pBlockDatabase;}

protected:
  OdGiClipBoundary* initClipBoundary(OdGsBaseVectorizeView& view);
  // Tool methods
  virtual void playAsGeometry(OdGsBaseVectorizeView& view, EMetafilePlayMode eMode);
  void doUpdateImpl(OdGsBaseVectorizeView& view, const OdGiDrawable* pInsert);
  void initBlockNode(const OdGiDrawable* pInsert);
  void initLayer(OdGsBaseVectorizeView& view);
  bool isLayerVisible(OdGsBaseVectorizeView& view);
  void setMetafile(OdGsBaseVectorizeView& view, OdGsBaseModel* pModel, OdGsGeomPortion& firstGeomPortion);

  virtual bool isValidMetafile(OdUInt32 viewportId, OdUInt32 nViewChangeMask, OdUInt32 &nAwareFlags) const { return false; }

  virtual bool realExt(OdGeExtents3d& ext) const;

  virtual void subUpdate(){m_bUpdateSubEnt = true;};

  virtual bool isPdfReference() const {return true;}
  virtual bool cacheIn(OdStreamBuf*){return false;}
  virtual bool cacheOut(OdStreamBuf*){return false;}

protected:
  // Pointer to layer node
  OdGsLayerNode* m_pLayer;
  // Pointer to implementation object
  OdGsBlockReferenceNodeImpl* m_pImpl;
  bool m_bUpdateSubEnt;
  OdDbStub* m_pBlockId;
  OdDbBaseDatabase* m_pBlockDatabase;
  OdGsPdfBlockNode*m_pPdfBlock;
  friend class GCSS::GcSiSelectVisitor;
};


class GS_TOOLKIT_EXPORT OdGsPdfBlockNode : public OdGsNodeEx
{
public:
  ODRX_DECLARE_MEMBERS(OdGsPdfBlockNode);

  OdGsPdfBlockNode(OdGsBaseModel* pModel, OdGsPdfReferenceNode* pPdfNode);
  ~OdGsPdfBlockNode();

  void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* view, OdUInt32 mask)
  {

  }

  void update(OdGsBaseVectorizeView&, OdGsContainerNode*)
  {
    ODA_ASSERT(false);
  }

  void display(OdGsBaseVectorizeView&)
  {
    ODA_ASSERT(false);
  }

  bool extents(OdGeExtents3d&) const
  {
    ODA_ASSERT(false);
    return false;
  }

  void propagateLayerChanges(OdGsBaseVectorizeView& /*view*/)
  {

  }

  void destroy();

  void detach();

  OdDbBaseDatabase *database();

protected:

  OdGsPdfReferenceNode *m_pPdfRef;
};


#endif // __OD_GS_REFERENCE_NODE__
