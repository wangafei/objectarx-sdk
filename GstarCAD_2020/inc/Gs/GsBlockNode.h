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
#ifndef __OD_GS_BLOCK_NODE__
#define __OD_GS_BLOCK_NODE__

#include "GsBlockReferenceNode.h"
#include "../Ge/GeScale3d.h"
#define STL_USING_SET
#define STL_USING_MAP
#include "OdaSTL.h"

/** Description:

    Library: Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBlockRefNodeDesc
{
public:
  OdGsBlockRefNodeDesc(const OdGiSubEntityTraitsData& tr, const OdGeMatrix3d& mat, bool bUsePlotStyles);
  OdGsBlockRefNodeDesc(const OdGsBlockRefNodeDesc& c);

  bool operator < (const OdGsBlockRefNodeDesc& d) const;

public:
  OdDbStub* m_layerId;
  OdDbStub* m_lineTypeId;
  OdUInt32 m_cmColor;
  OdDb::LineWeight m_lineWeight;
  double m_lineTypeScale;

  OdDb::PlotStyleNameType m_plotStyleNameType;
  OdDbStub* m_plotStyleNameId;

  OdDbStub* m_materialId;
  OdUInt32 m_cmTransparency;

  OdGeVector3d m_xDir;
  OdGeVector3d m_yDir;
  OdGeVector3d m_zDir;
  //OdGeScale3d  m_scale;
};

/** Description:

    Library: Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBlockNode : public OdGsNodeEx
{
public:
  enum
  {
    kInvalidateRefExtentsMask = (kVpLastPropBit << 1)
  };
  ODRX_DECLARE_MEMBERS(OdGsBlockNode);

  OdGsBlockNode(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable, bool bSetGsNode);
  ~OdGsBlockNode();

  void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* view, OdUInt32 mask);

  void addRef(OdGsBlockReferenceNode* pEntity);

  void release(OdGsBlockReferenceNode* pEntity);

  /** Description:
    Updates the cached data within this Node object for the specified VectorizeView and ContainerNode objects. 
    Arguments:
    pParent (I) Pointer to the ContainerNode object for this Node object.
    view (I) VectorizeView object for which data are to be updated.
  */
  void update(OdGsBaseVectorizeView&, OdGsContainerNode*)
  {
    ODA_ASSERT(false);
  }

  /** Description:
    Paints the specified *view* with the cached data associated with this Node object.
    Arguments:
    view (I) View to be painted.
  */
  void display(OdGsBaseVectorizeView&)
  {
    ODA_ASSERT(false);
  }

  /** Description:
    Returns the *extents* of the underlying GiDrawable object(s) associated with this Node object.
    
    Arguments:
    extents (O) Receives the *extents*.
    
    Remarks:
    Returns true if and only if the GiDrawable object(s) have extents.
  */
  bool extents(OdGeExtents3d&) const
  {
    ODA_ASSERT(false);
    return false;
  }

  /** Description:
    Invalidates parts of cache depended on layers modified since last regeneration.
    
    Remarks:
    For internal use only.
    Returns *this* if and only if the this node is one of modified layers.
  */
  void propagateLayerChanges(OdGsBaseVectorizeView& /*view*/);

  void destroy();

  OdGsBlockReferenceNodeImpl* findImp(const OdGsBlockRefNodeDesc& d);
  OdGsBlockReferenceNodeImpl* insertImp(const OdGsBlockRefNodeDesc& d, OdGsBlockReferenceNodeImpl* pImp);
  void invalidateShared();

protected:
  void clearInserts();

protected:
  class GS_TOOLKIT_EXPORT ImpMap
  {
  public:
    ImpMap() { }
    ~ImpMap() { clear(); }

    void clear();
    void destroy();

    OdGsBlockReferenceNodeImpl* findAt(const OdGsBlockRefNodeDesc& d);
    OdGsBlockReferenceNodeImpl* insertAt(const OdGsBlockRefNodeDesc& d, OdGsBlockReferenceNodeImpl* pImp);

    bool layersChanged(OdGsBaseVectorizeView& view, OdGsBaseModel* pModel);

  protected:
    typedef std::map<OdGsBlockRefNodeDesc, OdGsBlockReferenceNodeImpl*,
                      std::less<OdGsBlockRefNodeDesc> > _map;
    _map m_map;
  };

protected:
  typedef std::set<OdGsBlockReferenceNode*> Inserts;
  typedef Inserts::iterator InsertIterator;
  Inserts m_inserts;
  ImpMap m_sharedImp;
};

#endif // __OD_GS_BLOCK_NODE__
