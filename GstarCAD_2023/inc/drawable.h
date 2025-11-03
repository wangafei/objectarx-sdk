/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __DRAWABLE_H
#define __DRAWABLE_H

#include "rxobject.h"
#include "rxoverrule.h"
#include "dbid.h"
#pragma pack (push, 8)

class GcGsModel;
class GcGiDrawableTraits;
class GcGiWorldDraw;
class GcGiViewportDraw;
class GcDbSubentId;
class GcDbExtents;
class GcGiDrawStream;

class GCBASE_PORT GSOFT_NO_VTABLE GcGiDrawable : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiDrawable);

  enum SetAttributesFlags
  {
    kDrawableNone = 0,
    kDrawableIsAnEntity = 1,
    kDrawableUsesNesting = 2,
    kDrawableIsCompoundObject = 4,
    kDrawableViewIndependentViewportDraw = 8,
    kDrawableIsInvisible = 16,
    kDrawableHasAttributes = 32,
    kDrawableRegenTypeDependentGeometry = 64,
    kDrawableIsDimension = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128),
    kDrawableRegenDraw = 256,
    kDrawableStandardDisplaySingleLOD = 512,
    kDrawableShadedDisplaySingleLOD = 1024,
    kDrawableViewDependentViewportDraw = 2048,
    kDrawableBlockDependentViewportDraw = 4096,
    kDrawableIsExternalReference = 8192,
    kDrawableNotPlottable = 16384,
    kDrawableNotAllowLCS = 32768,
    kDrawableMergeControlOff = 65536
  };

  enum DrawableType
  {
    kGeometry = 0,
    kDistantLight,
    kPointLight,
    kSpotLight,
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

#pragma warning(push)
#pragma warning(disable: 4481)
#pragma warning(disable: 4100)  

  GcGiDrawable();
  ~GcGiDrawable();

  GSOFT_SEALED_VIRTUAL Gsoft::UInt32   setAttributes(GcGiDrawableTraits * traits) GSOFT_SEALED;
  GSOFT_SEALED_VIRTUAL Gsoft::Boolean  worldDraw(GcGiWorldDraw * wd) GSOFT_SEALED;
  GSOFT_SEALED_VIRTUAL void            viewportDraw(GcGiViewportDraw * vd) GSOFT_SEALED;
  GSOFT_SEALED_VIRTUAL Gsoft::UInt32   viewportDrawLogicalFlags(GcGiViewportDraw * vd) GSOFT_SEALED;

  virtual Gsoft::Boolean  isPersistent(void) const = 0;
  virtual GcDbObjectId    id(void) const = 0;
  virtual DrawableType    drawableType(void) const { return kGeometry; }
  virtual Gsoft::Boolean  RolloverHit(Gsoft::ULongPtr,
                                      Gsoft::ULongPtr,
                                      Gsoft::Boolean)
  {
    return Gsoft::kFalse;
  }
  virtual bool            bounds(GcDbExtents&) const { return false; }
  virtual void            setDrawStream(GcGiDrawStream * pStream);
  virtual GcGiDrawStream* drawStream(void) const;

#pragma warning(pop)

protected:
  friend class GcGiDrawableOverrule;
  virtual Gsoft::UInt32   subSetAttributes(GcGiDrawableTraits * traits) = 0;
  virtual Gsoft::Boolean  subWorldDraw(GcGiWorldDraw * wd) = 0;
  virtual void            subViewportDraw(GcGiViewportDraw * vd) = 0;
  virtual Gsoft::UInt32   subViewportDrawLogicalFlags(GcGiViewportDraw *) { return 0; }

private:
  friend class GcGiDrawableAccessory;
  class GcGiDrawableAccessory* m_pAccessory;
};

class GCBASE_PORT GcGiDrawableOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcGiDrawableOverrule);

  GcGiDrawableOverrule();
  virtual Gsoft::UInt32   setAttributes(GcGiDrawable* pSubject, GcGiDrawableTraits * traits);
  virtual Gsoft::Boolean  worldDraw(GcGiDrawable* pSubject, GcGiWorldDraw * wd);
  virtual void            viewportDraw(GcGiDrawable* pSubject, GcGiViewportDraw * vd);
  virtual Gsoft::UInt32   viewportDrawLogicalFlags(GcGiDrawable* pSubject, GcGiViewportDraw * vd);
};

class GCBASE_PORT GcGiDrawableReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiDrawableReactor);

  enum RegenFlags
  {
    k2DRegen,
    k3DRegen
  };

  virtual void beginRegen(GcGiDrawable*, RegenFlags) {}
  virtual void endRegen(GcGiDrawable*, RegenFlags) {}
  virtual void modified(GcGiDrawable*) {}
  virtual void erased(GcGiDrawable*) {}
  virtual void handOverTo(GcGiDrawable*, GcGiDrawable*) {}
  virtual void erased(GcGiDrawable*, Gsoft::IntDbId) {}
  virtual void modified(GcGiDrawable*, Gsoft::IntDbId) {}
  virtual void added(GcGiDrawable*, Gsoft::IntDbId, Gsoft::LongPtr) {}
};

#define gcgiDrawableEvent (&GcGiDrawableEvent::instance())

class GCBASE_PORT GcGiDrawableEvent : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiDrawableEvent);

  static GcGiDrawableEvent& instance();

  virtual void addReactor(GcGiDrawableReactor* pReactor);
  virtual void removeReactor(GcGiDrawableReactor* pReactor);
  virtual void sendBeginRegen(GcGiDrawable* pDrawable, GcGiDrawableReactor::RegenFlags flags);
  virtual void sendEndRegen(GcGiDrawable* pDrawable, GcGiDrawableReactor::RegenFlags flags);
  virtual void sendModified(GcGiDrawable* pDrawable);
  virtual void sendErased(GcGiDrawable* pDrawable);
  virtual void sendHandOverTo(GcGiDrawable* pDrawableFrom, GcGiDrawable* pDrawableTo);
  virtual void sendErased(GcGiDrawable* pDrawable, Gsoft::IntDbId parentID);
  virtual void sendModified(GcGiDrawable* pDrawable, Gsoft::IntDbId parentID);
  virtual void sendAdded(GcGiDrawable* pDrawable, Gsoft::IntDbId parentID, Gsoft::LongPtr databasePtr);

private:
  GcGiDrawableEvent();
  GcGiDrawableEvent(const GcGiDrawableEvent&);
  void operator=   (const GcGiDrawableEvent&);
  ~GcGiDrawableEvent();

  class GcGiImpDrawableEvent* m_pImp;
};

#pragma pack (pop)
#endif 