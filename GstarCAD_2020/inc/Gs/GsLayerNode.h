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


#ifndef __OD_GS_LAYER_NODE__
#define __OD_GS_LAYER_NODE__

#include "../Gs/GsNode.h"
#include "../Gi/GiLayerTraitsData.h"

typedef OdArray<OdGiLayerTraitsData, OdMemoryAllocator<OdGiLayerTraitsData> > OdGiLayerTraitsDataArray;

/** 
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsLayerNode : public OdGsNodeEx
{
  enum
  {
    kDirty     = OdGsNodeEx::kLastFlag << 1,
    kVpDep     = OdGsNodeEx::kLastFlag << 2,
    kVpFrozen  = OdGsNodeEx::kLastFlag << 3,

    kLastFlag = kVpFrozen
  };

  /** Description:
      No operation.
  */
  void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent);

  /** Description:
      No operation.
  */
  void display(OdGsBaseVectorizeView& view);

  /** Description:
      No operation.
  */
  bool extents(OdGeExtents3d& ) const;

  void propagateLayerChanges(OdGsBaseVectorizeView& view);

  OdGiLayerTraitsData m_layerTraits;
  mutable OdGiLayerTraitsDataArray m_vpLayerTraits;

  friend class OdGsBaseModel;
  friend class GcadGsModel;
  OdGsLayerNode* m_pNextChanged;
public:
  ODRX_DECLARE_MEMBERS(OdGsLayerNode);

  /** Arguments:
    pModel (I) Pointer to the BaseModel object.
    pUnderlyingDrawable (I) Pointer to the underlying Drawable object.
  */
  OdGsLayerNode(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable);
  ~OdGsLayerNode();

  void destroy() {}

  OdGiLayerTraitsData& layerTraits(OdUInt32 nVpId);

  const OdGiLayerTraitsData& layerTraits(OdUInt32 nVpId) const;

  void reserveLayerTraits(OdUInt32 nVpId);

  bool isDirty() const;
  void setDirty(bool bDirty);
  bool isUpToDate(OdUInt32 nVpId) const;
  bool isValidCache(OdUInt32 nVpId) const;
  void setCacheUpToDate(OdUInt32 nVpId);
  bool isVpFrozen() const;

  void onModified();

  /** Description:
      No operation.
  */
  void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);

  /** Description:
  */
  void update(OdGsBaseVectorizeView& view);
};

inline bool
OdGsLayerNode::isDirty() const
{
  return GETBIT(m_flags, kDirty);
}

inline void
OdGsLayerNode::setDirty(bool bDirty)
{
  SETBIT(m_flags, kDirty, bDirty);
}

#endif // __OD_GS_LAYER_NODE__
