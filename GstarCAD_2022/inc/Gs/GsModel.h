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




#ifndef __ODGSMODEL_H_INCLUDED_
#define __ODGSMODEL_H_INCLUDED_

#include "../Gs/Gs.h"

class OdGiPathNode;
class OdDbFullSubentPath;
typedef OdGiDrawable*    (* OdGsGetInterfaceFunc)            (LONG_PTR objectId, bool bNeedsValidation); 
typedef void             (* OdGsReleaseInterfaceFunc)        (OdGiDrawable*);

#include "../TD_PackPush.h"

/** Description:

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT ODRX_ABSTRACT OdGsNode : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGsNode);

  /** Description:
    Returns pointer to the Model object associated with this Cache object.
  */
  virtual OdGsModel* model() const = 0;

  /** Description:
    Reset pointer to the underlying GiDrawable object associated with this Cache object.
  */
  virtual void setDrawableNull() = 0;
  virtual OdGiDrawable* drawable(void) const 
  {
    throw OdError(OdResult::eNotImplemented);
    return NULL;
  }

  /** Description:
    Returns the *extents* of the underlying GiDrawable object(s) associated with this Cache object.
    
    Arguments:
    extents (O) Receives the *extents*.
    
    Remarks:
    Returns true if and only if the GiDrawable object(s) have extents.
  */
  virtual bool extents(OdGeExtents3d& extents) const = 0;
};

typedef OdGiDrawablePtr (*OdGiOpenDrawableFn)(OdDbStub* id);


/** Description:
    The class represents collections of drawable objects in the Teigha framework.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT ODRX_ABSTRACT OdGsModel : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGsModel);
  virtual ~OdGsModel(void) { }

  /** Description:
    Specifies the function called by open() for this Model object.
    Arguments:
    openDrawableFn (I) Function to be called.
  */
  virtual void setOpenDrawableFn(OdGiOpenDrawableFn openDrawableFn) = 0;

  /** Description:
    Notification function called whenever a drawable object is added to this Model object.

    Arguments:
    pAdded (I) Pointer to the added Drawable object.
    pParent (I) Pointer to the parent of the added Drawable object.
  */
  virtual void onAdded(OdGiDrawable* pAdded, OdGiDrawable* pParent) = 0;

  /** 
      Arguments:
      parentID (I) Object ID of the parent of the added Drawable object.
  */
  virtual void onAdded(OdGiDrawable* pAdded, LONG_PTR parentID) = 0;
  
  /** Description:
    Notification function called whenever a drawable object is modified in this Model object.

    Arguments:
    pModified (I) Pointer to the modified Drawable object.
    pParent (I) Pointer to the parent of the modified Drawable object.
  */
  virtual void onModified(OdGiDrawable* pModified, OdGiDrawable* pParent) = 0;

  /** 
      Arguments:
      parentID (I) Object ID of the parent of the modified Drawable object.
  */
  virtual void onModified(OdGiDrawable* pModified, LONG_PTR parentID) = 0;
  
  /** Description:
    Notification function called whenever a drawable object is erased from this Model object.

    Arguments:
    pErased (I) Pointer to the erased Drawable object.
    pParent (I) Pointer to the parent of the erased Drawable object.
  */
  virtual void onErased(OdGiDrawable* pErased, OdGiDrawable* pParent) = 0;

  /** 
      Arguments:
      parentID (I) Object ID of the parent of the erased Drawable object.
  */
  virtual void onErased(OdGiDrawable* pErased, LONG_PTR parentID) = 0;

  // Invalidation Hint
  enum InvalidationHint
  {
    kInvalidateNone,
    kInvalidateIsolines,
    kInvalidateViewportCache,
    kInvalidateAll,
    kInvalidateAllStatic,
    kInvalidateFacets,
    kInvalidateFills,
    kInvalidateLinetypes,
    kInvalidateMaterials,
    kInvalidateLayers,
    kInvalidateXrefs,
  };

  /** Description:
    Invalidates the specified cached data contained in this Model object.
    Arguments:
    pView (I) Pointer to the VectorizeView object for which data are to be invalidated.
    hint (I) Invalidation *hint*.
    
    Remarks:
    hint must be one of the following:
    
    @table
    Name                        Value
    kInvalidateIsolines         0
    kInvalidateViewportCache    1
    kInvalidateAll              2
    
  */
  virtual void invalidate(InvalidationHint hint) = 0;

  virtual void invalidate(OdGsView* pView) = 0;

  virtual void setTransform(const OdGeMatrix3d&) = 0;

  virtual OdGeMatrix3d transform() const = 0;

  virtual void highlight(const OdGiPathNode& path, bool bDoIt = true, const OdGsView* pView = 0) = 0;
  virtual void highlight(OdGsNode* pGsNode, const OdGiPathNode& path, bool bDoIt, const OdGsView* pView = 0) = 0;
  virtual bool highlight(const OdDbFullSubentPath& pPath, bool bDoIt= true, const OdGsView* pView = 0) = 0;

  enum RenderType
  { 
    kMain = 0,           // Use main Z-buffer
    kSprite,             // Use alternate Z-buffer (for sprites)
    kDirect,             // Render on device directly
    kHighlight,          // Render on device directly (skipping frame buffer and Z-buffer)
    kHighlightSelection, // Render on device directly using highlighting style (skipping frame buffer and Z-buffer)
    kDirectTopmost,      // Render on top of all other render types without Z-buffer
    kContrast,           // Render with contrast style
    kUser1,
    kUser2,
    kUser3,
    kCount               // Count of RenderTypes
  };

  virtual void setRenderType(RenderType renderType) = 0;
  virtual RenderType renderType() const = 0;
  
  // Shadowing
  //
  virtual double shadowPlaneLocation(void) const
  {
    throw OdError(OdResult::eNotImplemented);
    return 0.0;
  }
  virtual void  setShadowPlaneLocation   (double planeLocationZ)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  // Selection
  //
  virtual void  setSelectable (bool bEnable)
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual bool  selectable(void) const
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }

  virtual bool addSceneGraphRoot(OdGiDrawable* pRoot)
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
  virtual bool eraseSceneGraphRoot(OdGiDrawable* pRoot)
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }

  virtual void onPaletteModified()
  {
    throw OdError(OdResult::eNotImplemented);
  }
  //virtual bool getTransformAt(const OdGsPath*, OdGeMatrix3d &) = 0;
  virtual void setExtents(const OdGePoint3d&, const OdGePoint3d&)
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual void setViewClippingOverride(bool bOverride)
  {
    throw OdError(OdResult::eNotImplemented);
  };
  //virtual void setMaterialsOverride(bool bOverride) = 0;
  virtual bool linetypesEnabled(void) const 
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
  virtual void enableLinetypes(bool bEnable)
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual void setRenderModeOverride(OdGsView::RenderMode mode = OdGsView::kNone) = 0;
  
  virtual void setEnableSectioning(bool enable) 
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual bool isSectioningEnabled(void) const
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
  
  virtual bool setSectioning(const OdGePoint3dArray & pts, 
    const OdGeVector3d &     upVector)
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
  virtual bool setSectioning(const OdGePoint3dArray & pts, 
	const OdGeVector3d &     upVector, 
	double                   top, 
	double                   bottom)
  {
    throw OdError(OdResult::eNotImplemented);
    return false;
  }
	
  virtual void  setSectioningVisualStyle(const OdDbStub* visualStyleId)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  enum AdditionMode
  {
    kAddDrawable = 0, // Add new drawable
    kUneraseDrawable  // Added drawables are unerased
  };

  virtual void setAdditionMode(AdditionMode mode) = 0;
  virtual AdditionMode additionMode() const = 0;

  virtual void setBackground(OdDbStub *backgroundId) = 0;
  virtual OdDbStub *background() const = 0;

  virtual void setVisualStyle(OdDbStub *visualStyleId) = 0;
  virtual OdDbStub *visualStyle() const = 0;
  virtual void setVisualStyle(const OdGiVisualStyle &visualStyle) = 0;
  virtual bool visualStyle(OdGiVisualStyle &visualStyle) const = 0;
  virtual void setCacheInvalid(bool){}
};

enum
{
  kLayerLockFaded       = 0x00000001,
  kXrefDwgFaded         = 0x00000002,
  kRefWorksetFaded      = 0x00000004,
  kRefWorksetFadedCheck = 0x00000008,
  kRefWorkset           = kRefWorksetFaded|kRefWorksetFadedCheck,
  kBvModeFaded          = 0x00000010
};

#include "../TD_PackPop.h"

#endif // __ODGSMODEL_H_INCLUDED_

