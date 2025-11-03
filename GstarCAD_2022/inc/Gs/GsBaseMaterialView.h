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

#ifndef __OD_GS_BASE_MATERIAL_VIEW__
#define __OD_GS_BASE_MATERIAL_VIEW__

#include "Gs/GsBaseVectorizer.h"
#include "Gs/GsExtAccum.h"
#include "Gi/GiMapperItem.h"
#include "Gi/GiMaterialItem.h"

#include "TD_PackPush.h"

/** Description:
    This class provides material support for OdGsBaseVectorizeView.

    Remarks:
    OdGsBaseMaterialView works only with diffuse material/mapping channel and not applicable for
    complete rendering devices.
    
    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBaseMaterialView
  : public OdGsBaseVectorizeView
{
  public:
    enum MaterialViewFlags
    {
      kProcessMappers               = 1,        // Process material mappers
      kProcessMaterials             = (1 << 1), // Process materials

      kProcessMappersAndMaterials   = 3,        // Process both material mappers and materials

      kMappersForRender             = (1 << 2), // OdGiMapperRenderItem instead of OdGiMapperItem
      kMaterialsForRender           = (1 << 3), // OdGiMaterialRenderItem instead of OdGiMaterialItem

      kMappersAndMaterialsForRender = 12,       // kMappersForRender | kMaterialsForRender

      kProcessForRender             = 15,       // kProcessMappersAndMaterials | kMappersAndMaterialsForRender

      // #5127 fix. Delay cache implementation.
      kEnableDelayCache             = (1 << 4)  // Enable cache, which drop extents data after drawable extents computation
    };

    // Cache structures
    enum DelayCacheEntryType
    {
      kInternal = 0,
      kUser
    };
    struct DelayCacheEntry
    {
      DelayCacheEntry() : m_pNext(NULL) { }
      virtual ~DelayCacheEntry() { }

      DelayCacheEntry *m_pNext;

      // Don't return kInternal here if you want get callback
      virtual DelayCacheEntryType internalType() const { return kUser; }

      DelayCacheEntry *nextEntry() { return m_pNext; }
      void setNextEntry(DelayCacheEntry *pNext) { m_pNext = pNext; }

      virtual void play(OdGsBaseMaterialView &mView) const
      {
        mView.playDelayCacheEntry(this);
      }
    };
    friend class OdDefDelayCacheEntryMap;
  private:
    bool                m_bMaterialCommited;    // Material already emitted by GsModel
    bool                m_bMapperNeedExtents;   // Mapper awaiting current drawable extents
    struct ExtentsContainer
    {
      const OdGiDrawable *m_pCurrentDrawable;
      OdGeExtents3d       m_Extents;
      bool                m_bExtentsValid;
      bool                m_bAwaiting;
    } m_CurrentDrawableExtents;
    struct DelayCache
    {
      const OdGiMapper *m_pCurMapper,   *m_pCopyMapper;
      const OdDbStub   *m_pCurMaterial, *m_pCopyMaterial;
      DelayCacheEntry   m_Cache;
      DelayCacheEntry  *m_pTail;

      DelayCache() : m_pCurMapper(NULL)
                   , m_pCurMaterial(NULL)
                   , m_pTail(&m_Cache)
      {
      }

      void clear();
    } m_DelayCache;
  protected:
    OdUInt32            m_uMaterialViewFlags;   // Set of material view flags
    OdGiMaterialItemPtr m_pCurrentMaterialItem; // Current material
    OdGiMapperItemPtr   m_pCurrentMapperItem;   // Current mapper
    OdGiMaterialTraitsData m_nullMaterialTraitsData;
    OdGiMaterialItemPtr m_pNullMaterialItem;
  public:
    explicit OdGsBaseMaterialView(OdUInt32 uMaterialViewFlags = kProcessMappersAndMaterials);
    ~OdGsBaseMaterialView();

    // OdGsBaseVectorizerView overrides

    virtual void onTraitsModified();

    virtual void beginMetafile(OdRxObject* pMetafile);
    virtual void endMetafile(OdRxObject* pMetafile);
    virtual void beginViewVectorization();
    virtual void endViewVectorization();

    virtual void processMaterialNode(OdDbStub *materialId, OdGsMaterialNode *node);

    virtual bool doDraw(OdUInt32 drawableFlags, const OdGiDrawable *pDrawable);

    // OdGsBaseMaterialView methods

    /** Description:
      Returns current material item.
    */
    OdGiMaterialItemPtr currentMaterial() const;
    /** Description:
      Sets current material item.
      Arguments:
      pMaterial (I) New material item.
    */
    void resetCurrentMaterial(OdGiMaterialItemPtr pMaterial);
    /** Description:
      Returns true if and only if materials support enabled.
    */
    bool isMaterialEnabled() const;
    /** Description:
      Returns true if and only if current material available.
    */
    bool isMaterialAvailable() const;
    /** Description:
      Removes current material item.
    */
    void resetCurrentMaterial();
    /** Description:
      Returns current material mapper item.
      Arguments:
      bForCoords (I) Set to true if mapper item pointer will be used for texture coordinates calculations.
    */
    OdGiMapperItemPtr currentMapper(bool bForCoords = true) const;
    /** Description:
      Sets current material mapper item.
      Arguments:
      pMapper (I) New material mapper item.
    */
    void resetCurrentMapper(OdGiMapperItemPtr pMapper);
    /** Description:
      Returns true if and only if mappers support enabled.
    */
    bool isMapperEnabled() const;
    /** Description:
      Returns true if and only if current mapper item available.
    */
    bool isMapperAvailable() const;

    /** Description:
      Returns true if and only if delay cache is enabled and drawable extents is not available.
    */
    bool isMappingDelayed() const;

    // Output callbacks

    /** Description:
      Can be overrided by device for setup additional transform matrix to material mapper.
      Arguments:
      dm (O) Transform matrix.
      Remarks:
      Return true if transform matrix initialized.
    */
    virtual bool getDeviceMapperMatrix(OdGeMatrix3d &dm) const;
    /** Description:
      Test does current material need to be processed.
      Arguments:
      materialId (I) Material id.
      Remarks:
      Return true material need to be skipped.
      As default returns true for 2d optimized, wireframe and hidden render modes and if materialId null.
    */
    virtual bool skipMaterialProcess(OdDbStub *materialId) const;
    /** Description:
      Can be overrided by device for process null materials.
    */
    virtual void nullMaterialStub();
    /** Description:
      Called by OdGsBaseMaterialView for initialize/reinitialize material cache.
      Arguments:
      prevCache (I) Previous cache, if available.
      materialId (I) Material id.
      materialData (I) Current material traits.
      Remarks:
      As default returns null pointer.
    */
    virtual OdGiMaterialItemPtr fillMaterialCache(OdGiMaterialItemPtr prevCache, OdDbStub *materialId, const OdGiMaterialTraitsData &materialData);
    /** Description:
      Called by OdGsBaseMaterialView for render material cache.
      Arguments:
      pCache (I) Material cache.
      materialId (I) Material id.
      Remarks:
      As default does nothing.
    */
    virtual void renderMaterialCache(OdGiMaterialItemPtr pCache, OdDbStub *materialId);

    /** Description:
      Called by delay cache entry as default handler.
      Arguments:
      pEntry (I) Pointer to caller entry.
    */
    virtual void playDelayCacheEntry(const DelayCacheEntry *pEntry);
    /** Description:
      Sets user entry to delay cache.
      Arguments:
      pEntry (I) Pointer to newly created cache entry.
    */
    void appendDelayCacheEntry(DelayCacheEntry *pEntry);
    /** Description:
      Called by delay cache writer if mapping entry was changed.
      Remarks:
      Can be used for link cache markers with texture coordinates which must be recalculated after extents
      will be calculated.
    */
    virtual void mapperChangedForDelayCache();
    /** Description:
      Called by delay cache writer after execution of all cache entries.
      Remarks:
      Can be overrided for clear device's internal caches. If you want clear caches before execution,
      you could override computeDelayedExtents method instead of delayCacheProcessed.
    */
    virtual void delayCacheProcessed(const OdGiDrawable *pDrawable);
  protected:
    /** Description:
      Called internally if extents needed for current drawable (delay cache disabled).
      Arguments:
      pDrawable (I) Pointer to current drawable.
      extents (O) Computed extents.
      Remarks:
      Returns true if and only if computed extents valid.
      Can be overrided by device if it needs more fast implementation.
    */
    virtual bool computeDrawableExtents(const OdGiDrawable *pDrawable, OdGeExtents3d &extents);
    /** Description:
      Called internally if extents needed for current drawable (if delay cache enabled).
      Arguments:
      pDrawable (I) Pointer to current drawable.
      extents (O) Computed extents.
      Remarks:
      Returns true if and only if computed extents valid.
      Can be overrided by device if it needs more fast implementation.
    */
    virtual bool computeDelayedExtents(const OdGiDrawable *pDrawable, OdGeExtents3d &extents);
  private:
    void computeDrawableExtents();
    bool tryGsModelExtents(OdGeExtents3d &extents) const;
  protected:
    OdGiMapperItemPtr _itlCreateMapperItem() const;
    OdGiMaterialItemPtr _itlCreateMaterialItem() const;
};

#include "TD_PackPop.h"

#endif // __OD_GS_BASE_MATERIAL_VIEW__
