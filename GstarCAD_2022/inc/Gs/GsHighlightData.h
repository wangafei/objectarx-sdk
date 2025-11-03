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

#ifndef __ODGSHIGHLIGHTDATA_H__
#define __ODGSHIGHLIGHTDATA_H__

class OdGsNodeEx;

#include "../Int32Array.h"
#include "../GsMarkerArray.h"

#include "../Gi/GiDrawable.h"
#include "../Gi/GiPathNode.h"

#include "../Gs/GsExport.h"

#include "../Gs/GsMTContext.h"

#include "../TD_PackPush.h"

class OdGsBaseModel;

/** Description:
    This class provides a subentity highlighting data container.
    
    Remarks:
    For each OdGiPathNode this class contains a separate HighlightBranch, which correlates
    with a separate OdGsNodeEx. Each subentities highlight tree branch can contain any
    number of selection markers.

    Library: TD_Gs 

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsHighlightData
{
  public:
    /** Description:
        Base class for HighlightBranch which implements OdGiPathNode functionality.
    */
    struct HighlightNode : public OdGiPathNode
    {
      HighlightNode()
        : m_pParent(NULL)
        , m_pDrawableId(NULL)
        , m_pTransDrawable(NULL)
      {
      }

      OdGiPathNode *m_pParent;
      OdDbStub     *m_pDrawableId;
      OdGiDrawable *m_pTransDrawable;

      /** Description:
        Sets parent for HighlightNode.
        Arguments:
        pParent (I) Pointer to HighlightNode parent.
      */
      virtual void setParent(const OdGiPathNode *pParent = NULL)
      {
        m_pParent = const_cast<OdGiPathNode*>(pParent);
      }
      /** Description:
        Returns HighlightNode parent.
      */
      virtual const OdGiPathNode* parent() const
      {
        return m_pParent;
      }

      /** Description:
        Sets DBRO id for this HighlightNode.
        Arguments:
        pDrawableId (I) DBRO id.
      */
      virtual void setPersistentDrawableId(const OdDbStub *pDrawableId = NULL)
      {
        m_pDrawableId = const_cast<OdDbStub*>(pDrawableId);
      }
      /** Description:
        Returns DBRO id for this HighlightNode.
      */
      virtual OdDbStub* persistentDrawableId() const
      {
        return m_pDrawableId;
      }

      /** Description:
        Sets NDBRO drawable pointer.
        Arguments:
        pTransDrawable (I) NDBRO drawable pointer.
      */
      virtual void setTransientDrawable(const OdGiDrawable *pTransDrawable = NULL)
      {
        m_pTransDrawable = const_cast<OdGiDrawable*>(pTransDrawable);
      }
      /** Description:
        Returns NDBRO drawable pointer for this HighlightNode.
      */
      virtual const OdGiDrawable* transientDrawable() const
      {
        return m_pTransDrawable;
      }

      /** Description:
        Sets selection marker for this HighlightNode.
      */
      virtual void setSelectionMarker(OdGsMarker /*iMarker*/)
      {
      }
      /** Description:
        Returns selection marker for this HighlightNode.
      */
      virtual OdGsMarker selectionMarker() const
      {
        return -1;
      }

      /** Description:
        Copies HighlightNode information from other OdGiPathNode object.
        Arguments:
        node (I) Pointer to OdGiPathNode object which information must be copied.
      */
      HighlightNode &setFrom(const OdGiPathNode *node)
      {
        m_pDrawableId = node->persistentDrawableId();
        m_pTransDrawable = const_cast<OdGiDrawable*>(node->transientDrawable());
        return *this;
      }
    };
    /** Description:
        This class implements subentities highlighting tree branch.
    */
    struct GS_TOOLKIT_EXPORT HighlightBranch : public HighlightNode
    {
      ODRX_HEAP_OPERATORS();
      // Contained branches
      // Can't use OdList here. VS6 error.
      //OdList<HighlightBranch> m_Branch;
      /** Description:
          List for subentities highlighting tree branches.
      */
      class GS_TOOLKIT_EXPORT HighlightBranchList
      {
        HighlightBranch *m_pFirstBranch;
        HighlightBranch *m_pLastBranch;
        OdUInt32 m_uCount;
        public:
          ODRX_HEAP_OPERATORS();
          HighlightBranchList()
            : m_pFirstBranch(NULL)
            , m_pLastBranch(NULL)
            , m_uCount(0)
          {
          }
          ~HighlightBranchList()
          {
            clear();
          }

          /** Description:
            Appends and returns pointer to newly created subentities highlighting tree branch.
          */
          HighlightBranch *append();
          /** Description:
            Returns pointer to first subentities highlighting tree branch.
          */
          HighlightBranch *first();
          /** Description:
            Returns pointer to last subentities highlighting tree branch.
          */
          HighlightBranch *last();
          /** Description:
            Returns count of subentities highlighting tree branches, contained in this list.
          */
          OdUInt32 size();
          /** Description:
            Removes specified subentities highlighting tree branch from this list.
            Arguments:
            pBranch (I) Pointer to subentities highlighting tree branch which must be removed from this list.
          */
          void remove(HighlightBranch *pBranch);
          /** Description:
            Removes all contained subentities highlighting tree branches from this list.
          */
          void clear();
          /** Description:
            Returns true if and only if list contains one or more subentities highlighting tree branches.
          */
          bool empty();
      };
    protected:
      friend class OdGsHighlightData;
      friend class HighlightBranch::HighlightBranchList;
      HighlightBranch *m_pPrev;
      HighlightBranch *m_pNext;
      OdGsNodeEx *m_pCache;
    public:
      /** Description:
        List of subentities highlighting tree branches.
      */
      HighlightBranchList m_Branch;
      /** Description:
        Array of selection markers for this subentities highlighting tree branch.
      */
      OdGsMarkerArray m_Markers;

      HighlightBranch()
        : HighlightNode()
        , m_pPrev(NULL)
        , m_pNext(NULL)
        , m_pCache(NULL)
      {
        m_Markers.setGrowLength(1);
      }

      /** Description:
        Returns parent for this subentities highlighting tree branch.
      */
      const HighlightBranch *safeParent() const
      {
        return static_cast<HighlightBranch*>(m_pParent);
      }
      /** Description:
        Returns parent for this subentities highlighting tree branch.
      */
      HighlightBranch *safeParent()
      {
        return static_cast<HighlightBranch*>(m_pParent);
      }

      bool hasMarker(OdGsMarker gsMarker) const
      {
        if (gsMarker == -1) // frequent
          return false;
        OdGsMarkerArray::size_type tmp;
        return m_Markers.find(gsMarker, tmp);
      }
      bool hasMarkers() const
      {
        return !m_Markers.empty();
      }

      OdGsNodeEx *gsCache() const
      {
        return m_pCache;
      }
      void setGsCache(OdGsNodeEx *pNode)
      {
        m_pCache = pNode;
      }
    };
  public:
    //typedef OdList<HighlightBranch> HighlightBranchList;
    /** Description:
        List for subentities highlighting tree branches.
    */
    typedef HighlightBranch::HighlightBranchList HighlightBranchList;
  public:
    /** Description:
      Subentities highlighting tree branch flags.

      @table
      Name               Value    Description
      kChanged           1        Subentities highlighting tree changed at last function call.
    */
    enum HighlightFlags
    {
      kChanged = 1
    };
    class NodeModifyCallback
    {
      public:
        NodeModifyCallback() { }
        virtual ~NodeModifyCallback() { }
        virtual void nodeModified(OdGsNodeEx *pNode, HighlightBranch *pBranch, bool bHltModified, bool bSubHltModified) = 0;
    };
  protected:
    HighlightBranchList m_Branch;
    OdGsBaseModel *m_pBaseModel;
    OdUInt32 m_flags;
    NodeModifyCallback *m_pCallback;
  public:
    OdGsHighlightData()
      : m_pBaseModel(NULL)
      , m_flags(0)
      , m_pCallback(NULL)
    {
    }
    ~OdGsHighlightData()
    {
      clear();
    }

    /** Description:
      Sets base model pointer for this subentities highlighting tree.
      Arguments:
      pBaseModel (I) Pointer to base model.
    */
    void setBaseModel(OdGsBaseModel *pBaseModel)
    {
      m_pBaseModel = pBaseModel;
    }
    /** Description:
      Returns base model pointer for this subentities highlighting tree.
    */
    const OdGsBaseModel *baseModel() const
    {
      return m_pBaseModel;
    }

    /** Description:
      Adds new OdGiPathNode to this subentities highlighting tree.
      Remarks:
      If specified OdGiPathNode already added into this subentities highlighting tree,
      subentities highlighting tree remain unchanged.
    */
    void addPathNode(const OdGiPathNode *path);
    /** Description:
      Removes specified OdGiPathNode from this subentities highlighting tree.
      Remarks:
      If specified OdGiPathNode not presented into this subentities highlighting tree,
      subentities highlighting tree remain unchanged.
    */
    void removePathNode(const OdGiPathNode *path);

    /** Description:
      Removes specified drawable subentities highlighting tree branch from this subentities highlighting tree.
      Remarks:
      If specified drawable subentities highlighting tree branch not presented into this subentities highlighting tree,
      subentities highlighting tree remain unchanged.
    */
    void removeBranch(OdGiDrawable *pDrawable);

    /** Description:
      Removes specified cache subentities highlighting tree branch from this subentities highlighting tree.
      Remarks:
      If specified cache subentities highlighting tree branch not presented into this subentities highlighting tree,
      subentities highlighting tree remain unchanged.
    */
    void removeBranch(OdGsNodeEx *pNode);

    /** Description:
      Restore cache flags for entire highlighting branch.
    */
    void restoreCacheFlagsFromBranch(HighlightBranch *branch);

    /** Description:
      Removes all elements from this subentities highlighting tree.
      Remarks:
      Pointers to subentities highlighting tree branches will be not removed from correlated OdGsNode-s.
    */
    void clear();

    /** Description:
      Sets tree change diagnostic flag to specified value.
      Arguments:
      flag (I) New value for tree change diagnostic flag.
    */
    void setChangedFlag(bool flag)
    {
      SETBIT(m_flags, kChanged, flag);
    }
    /** Description:
      Returns tree change diagnostic flag state.
    */
    bool changedFlag() const
    {
      return GETBIT(m_flags, kChanged);
    }

    /** Description:
      Attaches highlighting modify notification callback.
    */
    void setNodeModifyCallback(NodeModifyCallback *pCallback)
    {
      m_pCallback = pCallback;
    }
    /** Description:
      Returns highlighting modify notification callback.
    */
    NodeModifyCallback *nodeModifyCallback() const
    {
      return m_pCallback;
    }
  protected:
    OdGsNodeEx *openDrawable(const OdGiPathNode *path);
    HighlightBranch *searchBranch(HighlightBranchList &branchList, const OdGiPathNode *path);
    OdGsNodeEx *openDrawable(HighlightBranch *pBranch);
    void addBranch(HighlightBranch *branch);
    void removeBranch(HighlightBranch *branch);
    HighlightBranch *removeEmptyBranch(HighlightBranchList &branchList, HighlightBranch *branch, bool bClearNode = true);
    HighlightBranch *recursiveAddPathNode(const OdGiPathNode *path, HighlightBranchList &branchList, bool last);
    HighlightBranch *recursiveRemovePathNode(const OdGiPathNode *path, HighlightBranchList &branchList, bool last);
    void recursiveClearBranch(HighlightBranch *branch);
    void resetNodeState(OdGsNodeEx *pNode, HighlightBranch *pBranch, bool bHlt, bool bSubHlt);
};

typedef OdGsHighlightData::HighlightBranch OdGsHighlightBranch;
typedef OdGsHighlightBranch *OdGsHighlightBranchPtr;

#include "../TD_PackPop.h"

#endif // __ODGSHIGHLIGHTDATA_H__
