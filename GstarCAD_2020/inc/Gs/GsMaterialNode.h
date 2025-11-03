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


#ifndef __OD_GS_MATERIAL_NODE__
#define __OD_GS_MATERIAL_NODE__

#include "Gs/GsNode.h"
#include "Gi/GiMaterial.h"
#include "Gi/GiMaterialTraitsData.h"

// Materials cached in GsModel, but in separate cache, instead all geometry.

// GsModel caches hierarchy:
// OdGsBaseModel
//   OdGsContainerNode <-- OdGsNodeEx - geometry cache
//     OdGsEntityNode <-- OdGsNodeEx
//       OdGsLightNode - has separate array, but stored into geometry cache too
//   OdGsLayerNode <-- OdGsNodeEx - layers cache
// OdGsBaseMode::OdGsMaterialCache
//   OdGsMaterialNode <-- OdGsNodeEx - materials cache

/** 
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsMaterialNode : public OdGsNodeEx
{
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

  /** Description:
      No operation.
  */
  void propagateLayerChanges(OdGsBaseVectorizeView& view);

  OdGiMaterialTraitsData m_materialTraits;
  bool m_dataInitialized;
  bool m_dataModified;
  bool m_cachedDataModified;

  mutable OdGsMaterialNode* m_pMatPrev;
  mutable OdGsMaterialNode* m_pMatNext;

  OdRxObjectPtr m_pCachedData;
public:
  ODRX_DECLARE_MEMBERS(OdGsMaterialNode);

  /** Arguments:
    pModel (I) Pointer to the BaseModel object.
    pUnderlyingDrawable (I) Pointer to the underlying Drawable object.
  */
  OdGsMaterialNode(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable);
  ~OdGsMaterialNode();

  void destroy() {}

  OdGiMaterialTraitsData& materialTraits();
  const OdGiMaterialTraitsData& materialTraits() const;

  // Called from OdGsNodeEx if material data changed at update.
  // May be used by inherited nodes to update device-dependant information.
  virtual void onModified(OdGsBaseVectorizeView& view);

  /** Description:
      No operation.
  */
  void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);

  /** Description:
  */
  void update(OdGsBaseVectorizeView& view);

  OdGsMaterialNode *nextNode() const;
  OdGsMaterialNode *prevNode() const;
  OdGsMaterialNode *setNextNode(OdGsMaterialNode *newNode);
  OdGsMaterialNode *setPrevNode(OdGsMaterialNode *newNode);

  bool isDataModified() const;

  bool isCachedDataModified() const;
  void setCachedDataUpdated();

  OdRxObjectPtr cachedData() const;
  void setCachedData(OdRxObjectPtr newCachedData);
};

// Cache for material nodes
#include "GsMaterialCache.h"

#endif // __OD_GS_MATERIAL_NODE__
