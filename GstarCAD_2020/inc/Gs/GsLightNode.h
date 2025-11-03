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


#ifndef __OD_GS_LIGHT_NODE__
#define __OD_GS_LIGHT_NODE__

#include "../Gs/GsEntityNode.h"
#include "../Gi/GiLightTraitsData.h"

// Lights are entities that have some special meaning

/** 
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsLightNode : public OdGsEntityNodeEx
{

  // In case light isn't in model space
  
  OdGeMatrix3d m_model2World; 
  OdGiLightTraitsData* m_pLightTraits;

  void update();

public:
  ODRX_DECLARE_MEMBERS(OdGsLightNode);

  ~OdGsLightNode();
  OdGsLightNode(OdGsBaseModel* pModel, const OdGiDrawable* pUnderlyingDrawable, bool bSetGsNode = true);
protected:
  OdGsLightNode(const OdGsLightNode& c);
public:
  virtual OdGsEntityNode* makeClone() const;

  void setModelTransform(const OdGeMatrix3d& xform) { m_model2World = xform; }
  OdGeMatrix3d modelTransform() const { return m_model2World; }

  OdGiDrawable::DrawableType drawableType() { return underlyingDrawable()->drawableType(); }

  OdGiPointLightTraitsData* pointLightTraitsData() { return (OdGiPointLightTraitsData*)m_pLightTraits; }
  OdGiSpotLightTraitsData* spotLightTraitsData() { return (OdGiSpotLightTraitsData*)m_pLightTraits; }
  OdGiDistantLightTraitsData* distantLightTraitsData() { return (OdGiDistantLightTraitsData*)m_pLightTraits; }
  OdGiWebLightTraitsData* webLightTraitsData() { return (OdGiWebLightTraitsData*)m_pLightTraits; }
  OdGiLightTraitsData* lightTraitsData() { return m_pLightTraits; }

  // OdGsNodeEx virtual overrides
  
  virtual void invalidate(OdGsContainerNode* pParent, OdGsBaseVectorizeView* pView, OdUInt32 mask);
  virtual void update(OdGsBaseVectorizeView& view, OdGsContainerNode* pParent);

  /** Description:
    Returns true if and only if specified drawable is a light entity.
    Arguments:
    drawableType (I) Drawable type.
  */
  static bool drawableIsLight(OdGiDrawable::DrawableType drawableType);

  virtual bool isValidMetafile(OdUInt32, OdUInt32, OdUInt32 &) const { return false; }
  virtual bool cacheIn(OdStreamBuf*){return false;}
  virtual bool cacheOut(OdStreamBuf*){return false;}
};

typedef OdSmartPtr<OdGsLightNode> OdGsLightNodePtr;

inline bool OdGsLightNode::drawableIsLight(OdGiDrawable::DrawableType drawableType)
{
  return (drawableType >= OdGiDrawable::kDistantLight && drawableType <= OdGiDrawable::kSpotLight) || (drawableType == OdGiDrawable::kWebLight);
}

#endif // __OD_GS_LIGHT_NODE__
