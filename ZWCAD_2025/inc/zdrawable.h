
#ifndef ZD_DRAWABLE_H
#define ZD_DRAWABLE_H

#include "zrxobject.h"
#include "zrxoverrule.h"
#include "zdbid.h"
#pragma pack (push, 8)

class ZcGsModel;
class ZcGiDrawableTraits;
class ZcGiWorldDraw;
class ZcGiViewportDraw;
class ZcGsNode;
class ZcDbSubentId;
class ZcDbExtents;
class ZcGiDrawStream;

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcGiDrawable : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcGiDrawable);

    enum SetAttributesFlags
    {
        kDrawableNone                           =  0,
        kDrawableIsAnEntity                     =  1,
        kDrawableUsesNesting                    =  2,
        kDrawableIsCompoundObject               =  4,
        kDrawableViewIndependentViewportDraw    =  8,
        kDrawableIsInvisible                    =  16,
        kDrawableHasAttributes                  =  32,
        kDrawableRegenTypeDependentGeometry     =  64,
        kDrawableIsDimension = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128),
        kDrawableRegenDraw                      = 256,
        kDrawableStandardDisplaySingleLOD       = 512,
        kDrawableShadedDisplaySingleLOD         = 1024,
        kDrawableViewDependentViewportDraw      =  2048,
        kDrawableBlockDependentViewportDraw     =  4096,
		kDrawableIsExternalReference            =  8192,
		kDrawableNotPlottable                   = 16384,
		kDrawableNotAllowLCS                    = 32768,
		kDrawableMergeControlOff                = 65536,
        kThreadedWorldDrawViewportDraw          = 131072,
        kDrawableManagesChildDrawables          = 262144
    };

    enum DrawableType
    {
        kGeometry              = 0,
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

	ZcGiDrawable();
	~ZcGiDrawable();


	ZSOFT_SEALED_VIRTUAL ZSoft::UInt32   setAttributes   (ZcGiDrawableTraits * traits) ZSOFT_SEALED;

	ZSOFT_SEALED_VIRTUAL ZSoft::Boolean  worldDraw       (ZcGiWorldDraw * wd) ZSOFT_SEALED;

	ZSOFT_SEALED_VIRTUAL void            viewportDraw    (ZcGiViewportDraw * vd) ZSOFT_SEALED;

	ZSOFT_SEALED_VIRTUAL ZSoft::UInt32   viewportDrawLogicalFlags (ZcGiViewportDraw * vd) ZSOFT_SEALED;

    virtual ZSoft::Boolean  isPersistent    (void) const                    = 0;
    virtual ZcDbObjectId    id              (void) const                    = 0;
    virtual DrawableType    drawableType() const { return kGeometry; }
    virtual void            setGsNode       (ZcGsNode * gsnode);
    virtual ZcGsNode*       gsNode          (void) const;

    virtual  ZSoft::Boolean RolloverHit(ZSoft::ULongPtr,
                                        ZSoft::ULongPtr,
                                        ZSoft::Boolean ) {
                        return ZSoft::kFalse; }

	virtual bool            bounds          (ZcDbExtents& /*bounds*/) const { return false; }

	virtual void            setDrawStream   (ZcGiDrawStream * pStream);
	virtual ZcGiDrawStream* drawStream      (void) const;

#pragma warning(pop)

protected:
    friend class ZcGiDrawableOverrule;

    virtual ZSoft::UInt32   subSetAttributes   (ZcGiDrawableTraits * traits)   = 0;

    virtual ZSoft::Boolean  subWorldDraw       (ZcGiWorldDraw * wd)            = 0;

    virtual void            subViewportDraw    (ZcGiViewportDraw * vd)         = 0;

    virtual ZSoft::UInt32   subViewportDrawLogicalFlags (ZcGiViewportDraw * ) { return 0; }

private:
    friend class ZcGiDrawableAccessory;

    class ZcGiDrawableAccessory* m_pAccessory;
};

class ZCDBCORE2D_PORT ZcGiDrawableOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiDrawableOverrule);

    ZcGiDrawableOverrule();

    virtual ZSoft::UInt32   setAttributes (ZcGiDrawable* pSubject, ZcGiDrawableTraits * traits);

    virtual ZSoft::Boolean  worldDraw     (ZcGiDrawable* pSubject, ZcGiWorldDraw * wd);

    virtual void            viewportDraw  (ZcGiDrawable* pSubject, ZcGiViewportDraw * vd);

    virtual ZSoft::UInt32   viewportDrawLogicalFlags (ZcGiDrawable* pSubject, ZcGiViewportDraw * vd);
};

class ZCDBCORE2D_PORT ZcGiDrawableReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiDrawableReactor);

    enum RegenFlags
    {
        k2DRegen,
        k3DRegen
    };

    virtual void beginRegen (ZcGiDrawable* , RegenFlags ) {}

    virtual void endRegen   (ZcGiDrawable* , RegenFlags ) {}

    virtual void modified   (ZcGiDrawable* ) {}

    virtual void erased     (ZcGiDrawable* ) {}

    virtual void handOverTo (ZcGiDrawable* , ZcGiDrawable* ) {}

    virtual void erased(ZcGiDrawable* , ZSoft::IntDbId ) {}

    virtual void modified(ZcGiDrawable* , ZSoft::IntDbId ) {}

    virtual void added(ZcGiDrawable* , ZSoft::IntDbId , ZSoft::LongPtr ) {}
};

#define zcgiDrawableEvent (&ZcGiDrawableEvent::instance())

class ZCDBCORE2D_PORT ZcGiDrawableEvent : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiDrawableEvent);

    static ZcGiDrawableEvent& instance();

    virtual void addReactor     (ZcGiDrawableReactor* pReactor);

    virtual void removeReactor  (ZcGiDrawableReactor* pReactor);

    virtual void sendBeginRegen (ZcGiDrawable* pDrawable, ZcGiDrawableReactor::RegenFlags flags);

    virtual void sendEndRegen   (ZcGiDrawable* pDrawable, ZcGiDrawableReactor::RegenFlags flags);

    virtual void sendModified   (ZcGiDrawable* pDrawable);

    virtual void sendErased     (ZcGiDrawable* pDrawable);

    virtual void sendHandOverTo (ZcGiDrawable* pDrawableFrom, ZcGiDrawable* pDrawableTo);

    virtual void sendErased     (ZcGiDrawable* pDrawable, ZSoft::IntDbId parentID);

    virtual void sendModified   (ZcGiDrawable* pDrawable, ZSoft::IntDbId parentID);

    virtual void sendAdded      (ZcGiDrawable* pDrawable, ZSoft::IntDbId parentID, ZSoft::LongPtr databasePtr);

private:
    ZcGiDrawableEvent   ();
    ZcGiDrawableEvent   (const ZcGiDrawableEvent&);
    void operator=      (const ZcGiDrawableEvent&);
   ~ZcGiDrawableEvent   ();

    class ZcGiImpDrawableEvent* m_pImp;
};

#pragma pack (pop)
#endif 
