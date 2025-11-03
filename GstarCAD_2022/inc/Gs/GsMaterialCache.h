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


#ifndef __OD_GS_MATERIAL_CACHE__
#define __OD_GS_MATERIAL_CACHE__

// Cache for material nodes

#include "../RxObject.h"
#include "../Gs/GsMTContext.h"

class OdGsBaseVectorizeView;
class OdGsBaseModel;
class OdGsMaterialNode;

/** 
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsMaterialCache : public OdRxObject
{
  protected:
    OdUInt32                m_nMaterials;
#ifndef ODGS_MT
    OdGsMaterialNode*       m_pMaterials;
    OdGsMaterialNode*       m_pCurrentNode;
#else
    OdGsMaterialNode* volatile m_pMaterials;
#endif
    OdGsBaseModel*          m_pModel;
  public:
    OdGsMaterialCache();
    ~OdGsMaterialCache();

    ODRX_DECLARE_MEMBERS(OdGsMaterialCache);

    void setBaseModel(OdGsBaseModel* pModel);

    OdGsBaseModel* baseModel() { return m_pModel; }
    const OdGsBaseModel* baseModel() const { return m_pModel; }

    static OdSmartPtr<OdGsMaterialCache> createObject(OdGsBaseModel* pModel);

    // Search for already initialized node
    OdGsMaterialNode *searchNode(OdDbStub *mtl) const;
    // Get current node
#ifndef ODGS_MT
    OdGsMaterialNode *currentNode() const;
#else
    OdGsMaterialNode *currentNode(OdGsMTViewContext *pViewCtx) const;
#endif
    // Initialize new node, if not already initialized or changed and set's as current node
    void setMaterial(OdGsBaseVectorizeView& view, OdDbStub *mtl, bool bDontReinit = false);
    // Reset current node
#ifndef ODGS_MT
    void setCurrentNode(OdGsMaterialNode *curNode = NULL);
#else
    void setCurrentNode(OdGsMTViewContext *pViewCtx, OdGsMaterialNode *curNode = NULL);
#endif

    // Remove material node on Erase
    void removeNode(OdDbStub *mtl);

    // Cache accessors
    OdUInt32 getCacheSize() const;
    OdGsMaterialNode *getCacheNode(OdUInt32 n) const;

    // Aliases
    inline void addNode(OdGsBaseVectorizeView& view, OdDbStub *mtl)
    {
      setMaterial(view, mtl, true);
    }

    // Clear cache
    void clearCache();

    // Invalidate cache
    void invalidateCache();
};

typedef OdSmartPtr<OdGsMaterialCache> OdGsMaterialCachePtr;

#endif // __OD_GS_MATERIAL_CACHE__
