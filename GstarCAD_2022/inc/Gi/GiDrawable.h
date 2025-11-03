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




#ifndef __ODDRAWABLE_H__
#define __ODDRAWABLE_H__  /** {Secret} **/

#include "../RxObject.h"
#include "../RxOverrule.h"

class OdGiDrawableTraits;
class OdGiWorldDraw;
class OdGiViewportDraw;
class OdGsNode;
class OdDbStub;
class OdGeExtents3d;
class OdDbExtents;
class OdDbObjectId;
#include "../TD_PackPush.h"

/** Description:
    This class is the base class for all graphical objects, both transient and persistent.
    
    Remarks:
    This interface must be implemented by all graphical objects.  Such objects
    are capable of vectorizing themselves within the Teigha framework.

    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiDrawable : public OdRxObject
{
protected:
  OdGiDrawable();
public:

  ODRX_DECLARE_MEMBERS(OdGiDrawable);

  enum SetAttributesFlags
  {
    kDrawableNone                         = 0, // Default flags; the drawable object uses only OdGi primitives, 
                                               // with no nested calls to draw().
    kDrawableIsAnEntity                   = 1, // Classes derived from OdDbEntity must set this flag,
                                               // which is set by the default implementation of 
                                               // OdDbEntity::subSetAttributes().
    kDrawableUsesNesting                  = 2, // The drawable uses nested calls to draw(), but makes no
                                               // calls to other OdGi primatives. 
    kDrawableIsCompoundObject             = 4, // The drawable is to be treated as a block. Valid only when combined 
                                               // with kDrawableIsAnEntity. If set, you must override 
                                               // OdDbEntity::getCompoundObjectTransform().
    kDrawableViewIndependentViewportDraw  = 8,  // Currently not supported.
    kDrawableIsInvisible                  = 16, // Object is invisible, and should not be rendered.
    kDrawableHasAttributes                = 32, // Currently not supported.
    kDrawableRegenTypeDependantGeometry   = 64, // Currently not supported.
    kDrawableIsDimension                  = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128), // Dimension objects must set these flags
                                                // which are set by the default implementation of 
                                                // OdDbDimension.
    kDrawableRegenDraw                    = 256,// The drawable must be always regenerated.
    kDrawableDBRO                         = 512,
    kDrawableShadedDisplaySingleLOD       = 1024,// Drawable has single level of detail for regen type 

    kDrawableViewDependentViewportDraw    = 2048,  // Drawable requires viewportDraw be called on every view change.

    kDrawableBlockDependentViewportDraw   = 4096,  // Drawable requires unique viewportDraw elaboration for each block path.
    kDrawableIsExternalReference          = 8192, // Drawable is an external reference 
    kLastFlag                             = kDrawableIsExternalReference // Marker
  };

  enum DrawableType
  {
      kGeometry              = 0, 
      kDistantLight          = 1, // this number is important!
      kPointLight            = 2, // this number is important!
      kSpotLight             = 3, // this number is important!
      kAmbientLight,
      kSolidBackground,
      kGradientBackground,
      kImageBackground,
      kGroundPlaneBackground,
      kViewport,
      kWebLight,
      kSkyBackground,
      kImageBasedLightingBackground
  };
  
  virtual DrawableType drawableType() const { return kGeometry; }

  /** Description:
    Sets the vectorization attributes of this object, and returns its attribute flags.  

    Arguments:
    pTraits (I) Pointer to OdGiDrawableTraits object from and to which the attributes are to be set.

    Remarks:
    This function is called by the vectorization framework, prior to calling worldDraw() or
    viewportDraw(), to set the attributes for an object.

    See Also:
    SetAttributesFlags 
  */
  ODRX_SEALED_VIRTUAL OdUInt32 setAttributes(OdGiDrawableTraits* pTraits) ODRX_SEALED;

  /** Description:
    Creates a viewport-independent geometric representation of this object.
    
    Remarks:
    Returns true if and only if the geometric representation can be generated in a
    viewport-independent manner. 

    Note:
    A return value of false indicates that viewportDraw() must be called of this object.

    The 3D GS will call this function at least once, but may cache subsequent *display* updates.

    Use OdGsModel::onModified() to assure that the 3D GS will call worldDraw() for next *display* update.
    
    The default implementation does nothing but return true. This function can be
    overridden in custom classes.

    Arguments:
    pWd (I) Pointer to the OdGiWorldDraw interface.
  */
  ODRX_SEALED_VIRTUAL OdBool worldDraw(OdGiWorldDraw* pWd) ODRX_SEALED;

  /** Description:
    Creates a viewport-dependent geometric representation of this object.

    Remarks:
    Causes an OdGiDrawable to describe its geometry to the specified OdGiViewportDraw object. 

    This function is called once per viewport.

    Remarks:
    By overriding this function, it is possible for have totally different images in each viewport; a schematic
    in one viewport, a layout in another.
    
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.

    Arguments:
    pVd (I) Pointer to the OdGiViewportDraw interface.
  */
  ODRX_SEALED_VIRTUAL void viewportDraw(OdGiViewportDraw* pVd) ODRX_SEALED;

  /** Description:
    Returns true and only if this object is persistent (stored in a *database*).
  */
  virtual OdBool isPersistent() const = 0;

  /** Description:
    Returns the *database* ID of this object.

    Remarks:
    Returns a null pointer if this object is not persistent.
  */
  virtual OdDbObjectId id() const = 0;

  /** Description:
    Assigns the specified OdGsNode to this object.
    
    Arguments:
    pGsNode (I) Pointer to the OdGsNode to be assigned.
  */
  virtual void setGsNode(OdGsNode* pGsNode) = 0;

  /** Description:
    Returns the OdGsNode associated with this object.
  */
  virtual OdGsNode* gsNode() const = 0;

  /** Description:
    Return true if you want rollover to track your object, false to ignore it.

    Arguments:
    nSubentId (I) The *database* ID of the object.
    nMouseFlags (I) Identical to the WM_MOUSEMOVE wParam windows message.
    bReset (I) Set to true you want rollover to track your object, false to ignore it.
  */
  virtual OdBool  RolloverHit(
    OdULongPtr nSubentId,
    OdULongPtr nMouseFlags,
    OdBool bReset)
  {
    return ::kFalse;
  }

  /** Description:
    Returns the setAttributes flags for the current viewportDraw. 
    
    Arguments:
    pVd (I) Pointer to OdGiViewportDraw interface.
    
    Note:
    The default implementation of this function always returns 0.
  */
  ODRX_SEALED_VIRTUAL OdUInt32 viewportDrawLogicalFlags(OdGiViewportDraw* pVd) ODRX_SEALED;

 /** Description:
    Returns a WCS bounding box that represents the *extents* of this entity.

    Arguments:
    extents (O) Receives the WCS *extents*.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    The default implementation of this function always returns eInvalidExtents. 
  */
  virtual OdResult getGeomExtents(OdDbExtents& extents) const; // Gcad(Modify)

  //internal use only.
  enum InternalFlags
  {
    kGsNodeFlags = 0
  };
  virtual int getUnknown(int type) const;
  virtual void setUnknown(int type, int data);

  virtual bool            bounds(OdDbExtents& /*bounds*/) const;
  protected:
    virtual OdUInt32 subSetAttributes (OdGiDrawableTraits * traits) {return kDrawableNone;};
    virtual OdBool subWorldDraw (OdGiWorldDraw * wd) {return ::kFalse;};
    virtual void subViewportDraw (OdGiViewportDraw * vd) {};

    virtual OdUInt32 subViewportDrawLogicalFlags (OdGiViewportDraw * vd);
    friend class OdGiDrawableOverrule;
};

typedef OdSmartPtr<OdGiDrawable> OdGiDrawablePtr;

/** Description:

    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiDrawableOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdGiDrawableOverrule);
  OdGiDrawableOverrule();
  virtual OdUInt32 setAttributes (OdGiDrawable* pSubject, OdGiDrawableTraits * traits);
  virtual OdBool worldDraw (OdGiDrawable* pSubject, OdGiWorldDraw * wd);
  virtual void viewportDraw (OdGiDrawable* pSubject, OdGiViewportDraw * vd);
  virtual OdUInt32 viewportDrawLogicalFlags (OdGiDrawable* pSubject, OdGiViewportDraw * vd);
};

#include "../TD_PackPop.h"

#endif // __ODDRAWABLE_H__

