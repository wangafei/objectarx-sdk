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

// Material data entry for Gs material cache and textures processing.

#ifndef __ODGIMATERIALITEM_H__
#define __ODGIMATERIALITEM_H__


#include "GiExport.h"
#include "GiImage.h"
#include "GiMaterial.h"
#include "GiCommonDraw.h"

#include "../RxObject.h"

#include "../TD_PackPush.h"

class OdDbStub;

/** Description:
    Internal texture data for device support.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialTextureData : public OdRxObject
{
  public:
    // Simple variant type for external device information

    /** Description:
      Simple variant type for storing external device information.
    */
    struct DevDataVariant
    {
      enum DevDataVariantType
      {
        DevDataVariantType_Void = 0,
        DevDataVariantType_Ptr,
        DevDataVariantType_RxObject
      };

      DevDataVariant() : m_ddvType(DevDataVariantType_Void), m_pVoid(NULL)
      {
      }
      DevDataVariant(void *ptr) : m_ddvType(DevDataVariantType_Ptr), m_pVoid(ptr)
      {
        if (m_pVoid == NULL)
          m_ddvType = DevDataVariantType_Void;
      }
      DevDataVariant(OdRxObjectPtr ptr) : m_ddvType(DevDataVariantType_RxObject), m_pVoid(NULL)
      {
        m_pRxObject = ptr;
      }

      DevDataVariantType type() const
      {
        return m_ddvType;
      }
      void *getPtr() const
      {
        return m_pVoid;
      }
      OdRxObjectPtr getRxObject() const
      {
        return m_pRxObject;
      }

      DevDataVariant &operator =(void *ptr)
      {
        return setPtr(ptr);
      }
      DevDataVariant &operator =(OdRxObjectPtr ptr)
      {
        return setRxObject(ptr);
      }

      DevDataVariant &setPtr(void *ptr)
      {
        clear();
        if (ptr != NULL)
        {
          m_ddvType = DevDataVariantType_Ptr;
          m_pVoid = ptr;
        }
        return *this;
      }
      DevDataVariant &setRxObject(OdRxObjectPtr ptr)
      {
        clear();
        m_ddvType = DevDataVariantType_RxObject;
        m_pRxObject = ptr;
        return *this;
      }

      void clear()
      {
        m_ddvType = DevDataVariantType_Void;
        m_pVoid = NULL;
        if (m_pRxObject.isNull())
          m_pRxObject.release();
      }

    protected:
      DevDataVariantType m_ddvType;
      void *m_pVoid;
      OdRxObjectPtr m_pRxObject;
    };

  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialTextureData);
    friend class OdGiModuleObject;
    
    /** Description:
      Set texture pixels from RGBA array.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      image (I) Input BGRA image.
    */
    virtual void setTextureData(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, const OdGiImageBGRA32 &image) = 0;
    /** Description:
      Get texture pixels as array of RGBA colors.
      Arguments:
      data (O) Output BGRA colors array.
      width (O) Width of texture.
      height (O) Height of texture.
    */
    virtual void textureData(OdGiPixelBGRA32Array &data, OdUInt32 &width, OdUInt32 &height) const = 0;
    
    /** Description:
      Return true if texture data was previously initialized.
    */
    virtual bool haveData() const = 0;

    /** Description:
      Create default material texture data implementation that stores color array.
    */
    static OdSmartPtr<OdGiMaterialTextureData> createDefaultTextureDataImplementation();
    /** Description:
      Return description of default material texture data implementation.
    */
    static OdRxClass *defaultTextureDataImplementationDesc();

  private:
    /* {Secret} */
    static void rxInitDefaultTextureDataImplementation();
    /* {Secret} */
    static void rxUninitDefaultTextureDataImplementation();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialTextureData object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialTextureData> OdGiMaterialTextureDataPtr;

/** Description:
    Protocol extension for OdGiMaterialTextureEntry texture loading information.

    Library:
    TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialTextureLoadPE : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialTextureLoadPE);

    OdGiMaterialTextureLoadPE();

    /** Description:
      Called by texture loader before file loading.
      Can be used for file name correction before texture loading.
    */
    virtual void startTextureLoading(OdString &fileName, OdDbBaseDatabase* pDb) = 0;

    /** Description:
      Called by texture loader after file loading, only if texture loading success.
    */
    virtual void textureLoaded(const OdString &fileName, OdDbBaseDatabase* pDb) = 0;
    /** Description:
      Called by texture loader after file loading, only if texture loading failed.
    */
    virtual void textureLoadingFailed(const OdString &fileName, OdDbBaseDatabase* pDb) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialTextureLoadPE object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialTextureLoadPE> OdGiMaterialTextureLoadPEPtr;

class OdGiMaterialTextureEntry;

/** Description:
    Extends device by texture loading functionality.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialTextureLoaderExt : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialTextureLoaderExt);

    /** Description:
      Returns true if device supports loading of this kind of texture.
      Arguments:
      pTexture (I) Pointer to material texture.
    */
    virtual bool allowTextureLoading(OdGiMaterialTexturePtr pTexture) = 0;

    /** Description:
      Loads material texture.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation.
      giCtx (I) Gi context.
      pEntry (I) Texture entry.
      pTexture (I) Pointer to material texture.
    */
    virtual OdGiMaterialTextureDataPtr loadTexture(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, OdGiMaterialTextureEntry *pEntry, OdGiMaterialTexturePtr pTexture) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialTextureLoaderExt object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialTextureLoaderExt> OdGiMaterialTextureLoaderExtPtr;

/** Description:
    Manage scene textures.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialTextureManager : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialTextureManager);

    /** Description:
        Management type.
    */
    enum ManageType
    {
      kFileTexturesOnly = 0, // @def
      kFileAndProceduralTextures, // not efficient for search
      kDisable // only loading from LoaderExt will be active
    };

    /** Description:
      Sets type of textures management.
      Arguments:
      type (I) New management type.
    */
    virtual void setManageType(ManageType type) = 0;
    /** Description:
      Returns current management type.
    */
    virtual ManageType manageType() const = 0;

    /** Description:
      Sets texture loading extension.
      Arguments:
      pExt (I) New extentsion pointer.
    */
    virtual void setMaterialLoaderExt(OdGiMaterialTextureLoaderExt *pExt) = 0;
    /** Description:
      Returns current texture loading extension.
    */
    virtual OdGiMaterialTextureLoaderExtPtr materialLoaderExt() const = 0;

    /** Description:
      Search texture in cache.
      Arguments:
      matMap (I) Material map.
    */
    virtual OdGiMaterialTextureDataPtr searchTexture(const OdGiMaterialMap &matMap) = 0;
    /** Description:
      Search texture in cache.
      Arguments:
      pTexture (I) Material texture pointer.
    */
    virtual OdGiMaterialTextureDataPtr searchTexture(OdGiMaterialTexturePtr pTexture) = 0;
    /** Description:
      Search texture in cache.
      Arguments:
      fileName (I) Texture file name.
    */
    virtual OdGiMaterialTextureDataPtr searchTexture(const OdString &fileName) = 0;

    /** Description:
      Try to load texture if it is isn't available in cache.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation.
      giCtx (I) Gi context.
      pEntry (I) Texture entry.
      matMap (I) Material map.
    */
    virtual OdGiMaterialTextureDataPtr tryToLoad(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, OdGiMaterialTextureEntry *pEntry, const OdGiMaterialMap &matMap) = 0;
    /** Description:
      Try to load texture if it is isn't available in cache.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation.
      giCtx (I) Gi context.
      pEntry (I) Texture entry.
      pTexture (I) Material texture pointer.
    */
    virtual OdGiMaterialTextureDataPtr tryToLoad(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, OdGiMaterialTextureEntry *pEntry, OdGiMaterialTexturePtr pTexture) = 0;
    /** Description:
      Try to load texture if it is isn't available in cache.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation.
      giCtx (I) Gi context.
      pEntry (I) Texture entry.
      fileName (I) Texture file name.
    */
    virtual OdGiMaterialTextureDataPtr tryToLoad(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, OdGiMaterialTextureEntry *pEntry, const OdString &fileName) = 0;

    /** Description:
      Links texture to current cache.
      Arguments:
      matMap (I) Material map.
      pData (I) Texture data pointer
    */
    virtual void linkTexture(const OdGiMaterialMap &matMap, OdGiMaterialTextureDataPtr pData) = 0;
    /** Description:
      Links texture to current cache.
      Arguments:
      pTexture (I) Material texture pointer.
      pData (I) Texture data pointer
    */
    virtual void linkTexture(OdGiMaterialTexturePtr pTexture, OdGiMaterialTextureDataPtr pData) = 0;
    /** Description:
      Links texture to current cache.
      Arguments:
      fileName (I) Texture file name.
      pData (I) Texture data pointer
    */
    virtual void linkTexture(const OdString &fileName, OdGiMaterialTextureDataPtr pData) = 0;

    /** Description:
      Returns true if specified texture data is already available in cache.
      Arguments:
      pData (I) Texture data pointer
    */
    virtual bool isAvailable(OdGiMaterialTextureData *pData) const = 0;

    /** Description:
      Removes specified texture data from cache.
      Arguments:
      pData (I) Texture data pointer
    */
    virtual void unlinkTexture(OdGiMaterialTextureData *pData) = 0;

    /** Description:
      Clears cache.
    */
    virtual void clear() = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialTextureManager object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialTextureManager> OdGiMaterialTextureManagerPtr;

/** Description:
    Material texture entry that contains, generates, and loads texture data.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialTextureEntry : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialTextureEntry);

    /** Description:
      Return pointer to device-dependent texture data container.
    */
    virtual OdGiMaterialTextureDataPtr textureData() const = 0;
    /** Description:
      Return true if texture data is initialized.
    */
    virtual bool isTextureInitialized() const = 0;

    /** Description:
      Return width of procedurally generated textures.
    */
    virtual OdUInt32 proceduralTextureWidth() const = 0;
    /** Description:
      Set width of procedurally generated textures.
    */
    virtual void setProceduralTextureWidth(OdUInt32 width) = 0;
    /** Description:
      Return height of procedurally generated textures.
    */
    virtual OdUInt32 proceduralTextureHeight() const = 0;
    /** Description:
      Set height of procedurally generated textures.
    */
    virtual void setProceduralTextureHeight(OdUInt32 height) = 0;
    /** Description:
      Set width and height of procedurally generated textures.
    */
    virtual void setProceduralTextureResolution(OdUInt32 width, OdUInt32 height) = 0;
    
    /** Description:
      Return procedural textures quality coefficient.
    */
    virtual double proceduralTextureQuality() const = 0;
    /** Description:
      Set procedural textures quality coefficient.
    */
    virtual void setProceduralTextureQuality(double coef) = 0;

    /** Description:
      Load texture from material map.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation (must not be NULL)
      giCtx (I) Gi context.
      matMap (I) Input material map reference.
      pManager (I) Optional textures manager.
    */
    virtual bool setGiMaterialTexture(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, const OdGiMaterialMap &matMap, OdGiMaterialTextureManager *pManager = NULL) = 0;

    /** Description:
      Load texture from material texture pointer.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation (must not be NULL).
      giCtx (I) Gi context.
      pTexture (I) Pointer to material texture.
      pManager (I) Optional textures manager.
    */
    virtual bool setGiMaterialTexture(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, OdGiMaterialTexturePtr pTexture, OdGiMaterialTextureManager *pManager = NULL) = 0;
    // Load texture from raster file
    /** Description:
      Load texture from raster file.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation (must not be NULL).
      giCtx (I) Gi context.
      fileName (I) Name of file that contains raster image.
      pManager (I) Optional textures manager.
    */
    virtual bool setGiMaterialTexture(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, const OdString &fileName, OdGiMaterialTextureManager *pManager = NULL) = 0;
    /** Description:
      Generate texture from material opacity value.
      Arguments:
      pDeviceInfo (I) Optional external device information.
      pTexDataImpl (I) Description of texture data class implementation (must not be NULL).
      giCtx (I) Gi context.
      opacity (I) Material opacity value (0.0 - 1.0).
      pManager (I) Optional textures manager.
    */
    virtual bool setGiMaterialTexture(OdGiMaterialTextureData::DevDataVariant pDeviceInfo, OdRxClass *pTexDataImpl, const OdGiContext &giCtx, double opacity, OdGiMaterialTextureManager *pManager = NULL) = 0;

    /** Description:
      Sets texture data explicitly.
      Arguments:
      pTextureData (I) Pointer to texture data.
      pManager (I) Optional textures manager.
    */
    virtual void setTextureData(OdGiMaterialTextureData *pTextureData, OdGiMaterialTextureManager *pManager = NULL) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialTextureEntry object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialTextureEntry> OdGiMaterialTextureEntryPtr;

/** Description:
    Container item for material data storage.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialItem : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialItem);

    /** Description:
      Return diffuse texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr diffuseTexture() const = 0;
    /** Description:
      Return diffuse texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr diffuseTexture() = 0;
    /** Description:
      Create and return diffuse texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createDiffuseTexture() = 0;
    /** Description:
      Destroy diffuse texture.
    */
    virtual void removeDiffuseTexture() = 0;
    /** Description:
      Return true if diffuse texture is created.
    */
    virtual bool haveDiffuseTexture() const = 0;

    // Container data

    /** Description:
      Return pointer to cached data object.
    */
    virtual OdRxObjectPtr cachedData() const = 0;
    /** Description:
      Set pointer to cached data object.
    */
    virtual void setCachedData(OdRxObjectPtr data) = 0;

    /** Description:
      Return material ID.
    */    
    virtual const OdDbStub *materialId() const = 0;
    /** Description:
      Set material ID.
    */
    virtual void setMaterialId(const OdDbStub *matId = NULL) = 0;
    /** Description:
      Test whether stored material ID is equal to *matId*.
    */
    virtual bool isMaterialIdValid(const OdDbStub *matId) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialItem object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialItem> OdGiMaterialItemPtr;

/** Description:
    Container item for material data store (for render devices).

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialRenderItem : public OdGiMaterialItem
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMaterialRenderItem);

    /** Description:
      Return specular texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr specularTexture() const = 0;
    /** Description:
      Return specular texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr specularTexture() = 0;
    /** Description:
      Create and return specular texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createSpecularTexture() = 0;
    /** Description:
      Destroy specular texture.
    */
    virtual void removeSpecularTexture() = 0;
    /** Description:
      Return true if specular texture created.
    */
    virtual bool haveSpecularTexture() const = 0;

    /** Description:
      Return reflection texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr reflectionTexture() const = 0;
    /** Description:
      Return reflection texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr reflectionTexture() = 0;
    /** Description:
      Create and return reflection texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createReflectionTexture() = 0;
    /** Description:
      Destroy reflection texture.
    */
    virtual void removeReflectionTexture() = 0;
    /** Description:
      Return true if reflection texture created.
    */
    virtual bool haveReflectionTexture() const = 0;

    /** Description:
      Return opacity texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr opacityTexture() const = 0;
    /** Description:
      Return opacity texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr opacityTexture() = 0;
    /** Description:
      Create and return opacity texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createOpacityTexture() = 0;
    /** Description:
      Destroy opacity texture.
    */
    virtual void removeOpacityTexture() = 0;
    /** Description:
      Return true if opacity texture created.
    */
    virtual bool haveOpacityTexture() const = 0;

    /** Description:
      Return bump texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr bumpTexture() const = 0;
    /** Description:
      Return bump texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr bumpTexture() = 0;
    /** Description:
      Create and return bump texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createBumpTexture() = 0;
    /** Description:
      Destroy bump texture.
    */
    virtual void removeBumpTexture() = 0;
    /** Description:
      Return true if bump texture created.
    */
    virtual bool haveBumpTexture() const = 0;

    /** Description:
      Return refraction texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr refractionTexture() const = 0;
    /** Description:
      Return refraction texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr refractionTexture() = 0;
    /** Description:
      Create and return refraction texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createRefractionTexture() = 0;
    /** Description:
      Destroy refraction texture.
    */
    virtual void removeRefractionTexture() = 0;
    /** Description:
      Return true if refraction texture created.
    */
    virtual bool haveRefractionTexture() const = 0;

    /** Description:
      Return normal map texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr normalMapTexture() const = 0;
    /** Description:
      Return normal map texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr normalMapTexture() = 0;
    /** Description:
      Create and return normal map texture pointer.
    */
    virtual OdGiMaterialTextureEntryPtr createNormalMapTexture() = 0;
    /** Description:
      Destroy normal map texture.
    */
    virtual void removeNormalMapTexture() = 0;
    /** Description:
      Return true if normal map texture created.
    */
    virtual bool haveNormalMapTexture() const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialRenderItem object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMaterialRenderItem> OdGiMaterialRenderItemPtr;

#include "../TD_PackPop.h"

#endif // __ODGIMATERIALITEM_H__
