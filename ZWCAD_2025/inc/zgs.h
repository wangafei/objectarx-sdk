
#pragma once

#include "zacarray.h"
#include "zAdAChar.h"
#include "zgept3dar.h"
#include "zdbid.h"
#include "zAcString.h"
#include "zacgi.h"

class ZcGeMatrix3d;
class ZcGePoint3d;
class ZcGeVector3d;
class ZcGePoint2d;

class ZcGsModel;
class ZcGsDevice;
class ZcGsGraphicsKernel;	

class ZcGiVisualStyle;
class ZcGiContextualColors;
class ZcGiContextualAttributes;
struct ZcGsClientViewInfo;
class ZcGsRenderInterrupter;
class ZcGsRenderProgressMonitor;	
class ZcGiDrawable;

namespace Ztil
{
    class Image;
};

namespace GS 
{

    enum ErrorStatus {
        kSuccess,
        kOutOfRange,
        kInvalidInput
    };

    enum DeviceType {
        kScreenDevice =         0,
        kOffScreenDevice =      1,
        kSelectionDevice =      2
    };

    enum HighlightStyle {
        kHighlightDashed =               0,
        kHighlightThicken =              1,
        kHighlightDashedAndThicken =     2,
        kHighlightCustom =               3,
		kHighlightDim =                  4,
        kHighlightThickDim =             5,
        kHighlightGlow =                 6
    };
	enum SyncBehavior
	{
		eSync               = 0,
		eAsync              = 1,
	};

	enum ImageOrientation
	{
		kTopDown            = 0,
        kBottomUp           = 1             
	};

	enum ImageDataFormat
	{
		kRGBA               = 0,
		kBGRA               = 1
	};
};

#define SCALAR_MIN     (-2147483647 - 1) 
#define SCALAR_MAX       2147483647      
#pragma pack (push, 8)

class ZcGsDCPoint 
{
public:
    enum            MaxFlag { Maximum };
    enum            MinFlag { Minimum };

                    ZcGsDCPoint (void) { }
                    ZcGsDCPoint (long xin, long yin) : x (xin), y (yin) { }

                    ZcGsDCPoint (MaxFlag) { x = SCALAR_MAX; y = SCALAR_MAX; }
                    ZcGsDCPoint (MinFlag) { x = SCALAR_MIN; y = SCALAR_MIN; }

    void            operator=   (MaxFlag) { x = SCALAR_MAX; y = SCALAR_MAX; }
    void            operator=   (MinFlag) { x = SCALAR_MIN; y = SCALAR_MIN; }

	void            operator=   (ZcGsDCPoint const & r)              { x =  r.x;   y =  r.y; }
	bool            operator==  (ZcGsDCPoint const & r) const { return x == r.x && y == r.y; }
	bool            operator!=  (ZcGsDCPoint const & r) const { return x != r.x || y != r.y; }

    long            x;
    long            y;
};

class ZcGsDCRect 
{
public:
    enum            NullFlag { Null    };

	                ZcGsDCRect (void) { }
	                ZcGsDCRect (ZcGsDCPoint const & min, ZcGsDCPoint const & max)
                        : m_min (min)
                        , m_max (max) { }
	                ZcGsDCRect (long l, long r, long b, long t)
                        : m_min (l,b)
                        , m_max (r,t) { }
	                ZcGsDCRect (NullFlag) { set_null(); }

	ZcGsDCRect &    operator= (ZcGsDCRect const & other) {
                        m_min = other.m_min;
                        m_max = other.m_max;
                        return *this;
                    }
	void            operator|= (ZcGsDCRect const & rightside) {
                        if (m_min.x > rightside.m_min.x)            
                            m_min.x = rightside.m_min.x;            
                        if (m_max.x < rightside.m_max.x)            
                            m_max.x = rightside.m_max.x;

                        if (m_min.y > rightside.m_min.y)
                            m_min.y = rightside.m_min.y;
                        if (m_max.y < rightside.m_max.y)
                            m_max.y = rightside.m_max.y;
                    }
	void            operator&= (ZcGsDCRect const & rightside) {
                        if (m_min.x < rightside.m_min.x)
                            m_min.x = rightside.m_min.x;            
                        if (m_max.x > rightside.m_max.x)            
                            m_max.x = rightside.m_max.x;

                        if (m_min.y < rightside.m_min.y)
                            m_min.y = rightside.m_min.y;
                        if (m_max.y > rightside.m_max.y)
                            m_max.y = rightside.m_max.y;

                        if (m_min.x > m_max.x || m_min.y > m_max.y)
                            *this = Null;
                    }
	bool            operator== (ZcGsDCRect const & rightside) const {
                        return m_min == rightside.m_min &&
                               m_max == rightside.m_max;    
                    }
	bool            operator!= (ZcGsDCRect const & rightside) const {
                        return !(*this == rightside);
                    }

    void            set_null (void) {                   
		                m_min = ZcGsDCPoint::Maximum;   
		                m_max = ZcGsDCPoint::Minimum;   
                    }                                   

	bool            is_null (void) const {
#ifdef ASSERT
                        ASSERT ((m_min.x <= m_max.x && m_min.y <= m_max.y) ||
			                    (m_min == ZcGsDCPoint::Maximum && m_max == ZcGsDCPoint::Minimum));
#endif
                        return m_min.x > m_max.x;
                    }

	bool            within (ZcGsDCRect const & rightside) const {
#ifdef ASSERT
                        ASSERT (!is_null());                        
#endif
		                return m_min.x >= rightside.m_min.x &&      
			                   m_min.y >= rightside.m_min.y &&      
                               m_max.x <= rightside.m_max.x &&
                               m_max.y <= rightside.m_max.y;
                    }

	ZcGsDCPoint     m_min;
	ZcGsDCPoint     m_max;
};

struct ZcGsColor
{
	unsigned char   m_red;
    unsigned char   m_green;
    unsigned char   m_blue;
    unsigned char   m_filler;
};

typedef void *      ZcGsWindowingSystemID;       
typedef void *		ZcGsWindowId;               

class ZcGsNode
{
public:
	virtual ~ZcGsNode() { }
    virtual ZcGiDrawable *  drawable        (void) const = 0;
    virtual void            setDrawableNull (void)       = 0;  
};


class ZcGsView
{
public:

    enum Projection
    {
        kParallel,
        kPerspective
    };

    enum SelectionMode
    {
        kWindow,
        kCrossing,
        kFence,
        kWPoly,
        kCPoly,
    };

    enum DefaultLightingType
    {
        kOneLight,
        kTwoLights,
        kBackLight
    };

	enum ModelCloneOption
	{
		kCloneNoModels,
		kCloneMainPersistentModel,
		kCloneAllModels
	};
	virtual                    ~ZcGsView            (void) { }

    
    virtual ZcGsGraphicsKernel &graphicsKernel(void)                                            = 0;

	virtual void                setViewport         (const ZcGePoint2d & lowerLeft,
		                                             const ZcGePoint2d & upperRight)            = 0;
	virtual void                setViewport         (const ZcGsDCRect  & screen_rect)           = 0;
	virtual void                getViewport         (      ZcGePoint2d & lowerLeft,
		                                                   ZcGePoint2d & upperRight)  const     = 0;
	virtual void                getViewport         (      ZcGsDCRect  & screen_rect) const     = 0;

	virtual void                setViewportClipRegion       (int                 contours, 
                                                             int const *         counts, 
		                                                     ZcGsDCPoint const * points)        = 0;
    virtual void                removeViewportClipRegion    (void)                              = 0;

	virtual void                setViewportBorderProperties (ZcGsColor const &   color,
                                                             int                 weight)        = 0;
	virtual void                getViewportBorderProperties (ZcGsColor &         color,
                                                             int &               weight) const  = 0;

    virtual void                setViewportBorderVisibility (bool                bVisible)      = 0;
    virtual bool                isViewportBorderVisible     (void) const                        = 0;

	virtual void                setView             (const ZcGePoint3d &  position,
		                                             const ZcGePoint3d &  target,
		                                             const ZcGeVector3d&  upVector,
                                                     double               fieldWidth,
                                                     double               fieldHeight,
                                                     Projection           projection = kParallel) = 0;

	virtual ZcGePoint3d         position            (void) const            = 0;
	virtual ZcGePoint3d         target              (void) const            = 0;
	virtual ZcGeVector3d        upVector            (void) const            = 0;
    virtual bool                isPerspective       (void) const            = 0;
    virtual double              fieldWidth          (void) const            = 0;
    virtual double              fieldHeight         (void) const            = 0;

    virtual void                setEnableFrontClip  (bool enable)           = 0;
    virtual bool                isFrontClipped      (void) const            = 0;
    virtual void                setFrontClip        (double distance)       = 0;
    virtual double              frontClip           (void) const            = 0;

    virtual void                setEnableBackClip   (bool enable)           = 0;
    virtual bool                isBackClipped       (void) const            = 0;
    virtual void                setBackClip         (double distance)       = 0;
    virtual double              backClip            (void) const            = 0;
    
	virtual ZcGeMatrix3d        viewingMatrix       (void) const            = 0;
	virtual ZcGeMatrix3d        projectionMatrix    (void) const            = 0;
	virtual ZcGeMatrix3d        screenMatrix        (void) const            = 0;
	virtual ZcGeMatrix3d        worldToDeviceMatrix (void) const            = 0;
	virtual ZcGeMatrix3d        objectToDeviceMatrix(void) const            = 0;


	virtual bool                add                 (ZcGiDrawable * drawable, 
                                                     ZcGsModel    * model)    = 0;
	virtual bool                erase               (ZcGiDrawable * drawable) = 0;
    virtual void                eraseAll            (void)                    = 0;

    virtual void                invalidate          (void)                  = 0;
	virtual void                invalidate          (const ZcGsDCRect &rect)= 0;
    virtual bool                isValid             (void) const            = 0;

    virtual void                update              (void)                  = 0;
    virtual void                beginInteractivity  (double fFrameRateInHz) = 0;
    virtual void                endInteractivity    (void)                  = 0;
	virtual bool                isInteractive       (void) const            = 0;
    virtual void                flush               (void)                  = 0;

    virtual void                setMaximumUpgrade   (int step)              = 0;
    virtual int                 maximumUpgrade      (void)                  = 0;
    virtual void                setMinimumDegrade   (int step)              = 0;
    virtual int                 minimumDegrade      (void)                  = 0;

    virtual void                hide                (void)                  = 0;
    virtual void                show                (void)                  = 0;
    virtual bool                isVisible           (void)                  = 0;

    virtual void                freezeLayer         (ZSoft::IntDbId layerID)      = 0;
    virtual void                thawLayer           (ZSoft::IntDbId layerID)      = 0;
    virtual void                clearFrozenLayers   (void)                  = 0;

    virtual void                invalidateCachedViewportGeometry (void)     = 0;

    virtual void                invalidateCachedViewportGeometry(ZcGiDrawable* pDrawable) = 0;

	virtual void                dolly               (const ZcGeVector3d & vector)   = 0;
    virtual void                dolly               (double x, double y, double z)  = 0;
    virtual void                roll                (double angle)                  = 0;
    virtual void                orbit               (double x, double y)            = 0;
    virtual void                zoom                (double factor)                 = 0;
	virtual void                zoomExtents         (const ZcGePoint3d& minPoint, 
                                                     const ZcGePoint3d& maxPoint)   = 0;
	virtual void                zoomWindow          (const ZcGePoint2d& lowerLeft, 
                                                     const ZcGePoint2d& upperRight) = 0;
    virtual void                pan                 (double x, double y)            = 0;

	virtual bool                pointInView         (const ZcGePoint3d& pnt)        = 0;
	virtual bool                extentsInView       (const ZcGePoint3d& minPoint, 
                                                     const ZcGePoint3d& maxPoint)   = 0;

	virtual ZcGsView *          clone               (bool bCloneViewParameters = true,
                                                     bool bCloneGeometry       = false)  = 0;

    virtual bool                exceededBounds      (void)                          = 0;

    virtual void                enableStereo        (bool bEnable)                  = 0;
    virtual bool                isStereoEnabled     (void) const                    = 0;
    virtual void                setStereoParameters (double     magnitude,
                                                     double     parallax)           = 0;
    virtual void                getStereoParameters (double &   magnitude, 
                                                     double &   parallax) const     = 0;

	virtual void                getSnapShot         (Ztil::Image       * pOutput,
                                                     ZcGsDCPoint const & offset)    = 0;

	virtual bool                renderToImage       (Ztil::Image* pOutput,
                                                     ZcGiDrawable* pSettings,
                                                     ZcGsRenderProgressMonitor* pProgressMonitor,
                                                     const ZcGsDCRect & rectScreen,
                                                     bool bReuseScene = false)      = 0;


	virtual ZcGsDevice *        getDevice(void) const = 0;


	virtual void                setVisualStyle      (const ZcDbObjectId visualStyleId)      = 0;
	virtual ZcDbObjectId        visualStyle         (void) const                            = 0;
	virtual void                setVisualStyle      (const ZcGiVisualStyle &visualStyle)    = 0;
	virtual bool                visualStyle         (ZcGiVisualStyle &visualStyle) const    = 0;


	virtual void                setBackground       (const ZcDbObjectId backgroundId)       = 0;
	virtual ZcDbObjectId        background          (void) const                            = 0;


    virtual void                enableDefaultLighting (bool bEnable, 
                                                       DefaultLightingType type = kTwoLights) = 0;

	virtual void                getNumPixelsInUnitSquare(const ZcGePoint3d& givenWorldpt, 
		                                                       ZcGePoint2d& pixelArea,
                                                               bool includePerspective = true) const = 0;    
	virtual ZcGsModel*          getModel            (ZcGiDrawable*) const                   = 0;
	virtual void                getModelList        (ZcArray<ZcGsModel*>&) const            = 0;
	virtual const               ZcGsClientViewInfo& getClientViewInfo() const               = 0;

	virtual void                update              (GS::SyncBehavior sync) = 0;
	virtual bool                isPointInViewport   (const ZSoft::Int32 x, const ZSoft::Int32 y) = 0;
	virtual ZcGsView *          clone               (bool bCloneViewParameters, ModelCloneOption cloneOption)  = 0;

	
    virtual Ztil::Image *       createSnapshot      (const ZcGsDCPoint&     offset,
                                                     const ZcGsDCRect&      imageDim,
                                                     GS::ImageDataFormat    format,
                                                     GS::ImageOrientation   orientation,
                                                     bool                   bOnlyCaptureRenderedImage = false)    = 0;

    enum EnableIRResult
    {
        kSuccess,
        kOutOfMemory
    };

    virtual EnableIRResult      beginInteractiveRender  (ZcGsRenderProgressMonitor* pProgressMonitor) = 0;
    virtual void                endInteractiveRender    (void)                                        = 0;
    virtual bool                isRendering             (void) const                                  = 0;
	

	virtual void                beginFastInteractivity   (void)            = 0;
	virtual bool                endFastInteractivity     (void)            = 0;
	virtual bool                isFastInteractivity      (void)            = 0;
                                                                                    
};

class ZcGsModel
{
public:

	enum RenderType
	{  
		kMain,              
		kSprite,            
		kDirect,            
		kHighlight,         
		kHighlightSelection,
		kDirectTopmost,
		kContrast,
		kCount              
	};

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
		kInvalidateRasterImages,
		kInvalidateAttributes,
		kInvalidateUnderlayFrame,
		kInvalidateLtScale,
		kInvalidateTransform,
        kInvalidateTransparencies,
        kInvalidateDrawableByView
	};

	enum OrderActionType
	{
		kMoveBelow,
		kMoveAbove,
		kSwapOrder,
	};

	virtual                    ~ZcGsModel           (void) { }

    virtual ZcGsGraphicsKernel &graphicsKernel(void)                            = 0;

	virtual bool                addSceneGraphRoot   (ZcGiDrawable * pRoot)      = 0;
	virtual bool                eraseSceneGraphRoot (ZcGiDrawable * pRoot)      = 0;

	virtual void                onAdded             (ZcGiDrawable * pAdded,        
		                                             ZcGiDrawable * pParent)    = 0;

	virtual void                onAdded             (ZcGiDrawable * pAdded,
                                                     ZSoft::IntDbId       parentID)   = 0;
                                                    
	virtual void                onModified          (ZcGiDrawable * pModified,
		                                             ZcGiDrawable * pParent)    = 0;

	virtual void                onModified          (ZcGiDrawable * pModified, 
                                                     ZSoft::IntDbId       parentID)   = 0;
                                                    
	virtual void                onErased            (ZcGiDrawable * pErased,
		                                             ZcGiDrawable * pParent)    = 0;

	virtual void                onErased            (ZcGiDrawable * pErased, 
                                                     ZSoft::IntDbId       parentID)   = 0;

    virtual void                onPaletteModified   (void) = 0;


	virtual void                setTransform        (const ZcGeMatrix3d &)      = 0;
	virtual ZcGeMatrix3d        transform           (void) const                = 0;
	virtual void                setExtents          (const ZcGePoint3d &,
                                                     const ZcGePoint3d &)       = 0;

    virtual void                invalidate          (InvalidationHint hint)     = 0;

    virtual void                setViewClippingOverride (bool bOverride)        = 0;

	virtual void                setVisualStyle      (const ZcDbObjectId visualStyleId)      = 0;
	virtual ZcDbObjectId        visualStyle         (void) const                            = 0;
	virtual void                setVisualStyle      (const ZcGiVisualStyle &visualStyle)    = 0;
	virtual bool                visualStyle         (ZcGiVisualStyle &visualStyle) const    = 0;


	virtual void                setBackground       (const ZcDbObjectId backgroundId)       = 0;
	virtual ZcDbObjectId        background          (void) const                            = 0;


    virtual void                enableLinetypes     (bool bEnable)              = 0;
    virtual bool                linetypesEnabled    (void) const                = 0;

    virtual void                setEnableSectioning      (bool enable)          = 0;
    virtual bool                isSectioningEnabled      (void) const           = 0;
	virtual bool                setSectioning            (const ZcGePoint3dArray & pts, 
                                                          const ZcGeVector3d &     upVector) = 0;
	virtual bool                setSectioning            (const ZcGePoint3dArray & pts, 
                                                          const ZcGeVector3d &     upVector, 
                                                          double                   top, 
                                                          double                   bottom)   = 0;
	virtual void                setSectioningVisualStyle (const ZcDbObjectId visualStyleId)  = 0;


    virtual RenderType          renderType               (void)                     = 0;

	virtual double              shadowPlaneLocation      (void) const               = 0;
	virtual void                setShadowPlaneLocation   (double planeLocationZ)    = 0;

	virtual void                setSelectable            (bool bEnable)             = 0;
	virtual bool                selectable               (void) const               = 0;

	virtual void                setDrawOrder             (ZcGiDrawable* pDrawable,
                                                          ZcGiDrawable* pRelativeDrawable,
                                                          ZcGiDrawable* pParent,
                                                          OrderActionType action) = 0;

    virtual bool                bounds                   (const ZcGiDrawable& drawable,
                                                          ZcGePoint3d& minPt,
                                                          ZcGePoint3d& maxPt) = 0;

    virtual void                onModified               (ZcGiDrawable * pModified,
                                                          ZcGiDrawable * pParent,
                                                          InvalidationHint hint)    = 0;
	virtual void                onModified               (ZcGiDrawable * pModified,
                                                          ZSoft::IntDbId parentID,
                                                          InvalidationHint hint)   = 0;

	
    virtual void                setUnitScale(double metersPerUnit) = 0;

    virtual double              unitScale(void) const = 0;

    virtual void                setLightingPhotometric(bool bPhotometric) = 0;

    virtual bool                isLightingPhotometric(void) const = 0;

    virtual void                setLightsInBlocksEnabled(bool bEnabled) = 0;

    virtual bool                lightsInBlocksEnabled(void) const = 0;
	
};

class ZcGsDevice
{
public:

    enum RendererType
    {
        kDefault,
        kSoftware,
        kSoftwareNewViewsOnly,
        kFullRender,
		kSelectionRender,
		kFbxExportRender
    };

	virtual                    ~ZcGsDevice          (void) { }
    virtual ZcGsGraphicsKernel &graphicsKernel(void)                        = 0;
	virtual void                invalidate          (void)                  = 0;
	virtual void                invalidate          (const ZcGsDCRect &rect)= 0;
	virtual bool                isValid             (void) const            = 0;

	virtual void                update              (ZcGsDCRect* pUpdatedRect = nullptr) = 0;

    virtual void                onSize              (int width, int height) = 0;
    virtual void                onRealizeForegroundPalette (void)           = 0;
    virtual void                onRealizeBackgroundPalette (void)           = 0;
    virtual void                onDisplayChange     (int nBitsPerPixel,     
                                                     int nXRes,             
                                                     int nYRes)             = 0;

	virtual bool                add                 (ZcGsView * view)       = 0;
	virtual bool                erase               (ZcGsView * view)       = 0;
    virtual void                eraseAll            (void)                  = 0;
                                                                            
	virtual bool                setBackgroundColor  (ZcGsColor color)       = 0;
	virtual ZcGsColor           getBackgroundColor  (void)                  = 0;
                                                    
	virtual void                setLogicalPalette   (const ZcGsColor * palette, 
                                                     int nCount)            = 0;
	virtual void                setPhysicalPalette  (const ZcGsColor * palette, 
                                                     int nCount)            = 0;

	virtual void                getSnapShot         (Ztil::Image * pOutput,
                                                     ZcGsDCPoint const & offset) = 0;

	virtual void                setDeviceRenderer   (RendererType type)     = 0;
	virtual RendererType        getDeviceRenderer   (void)                  = 0;

	virtual void                setRenderInterrupter(ZcGsRenderInterrupter* pInterrupter) = 0;
	virtual ZcGsRenderInterrupter* getRenderInterrupter(void) const = 0;
	virtual void                setDisplayUpdateSuppressed(bool bSuppressed) = 0;

	virtual void                invalidate          (ZcGsModel::RenderType pane) = 0;
	virtual void                invalidate          (const ZcGsDCRect &rect, ZcGsModel::RenderType pane) = 0;
	virtual void                update              (ZcGsDCRect* pUpdatedRect, GS::SyncBehavior sync) = 0;
    virtual Ztil::Image *       createSnapshot      (const ZcGsDCPoint&     offset,
                                                     const ZcGsDCRect&      imageDim,
                                                     GS::ImageDataFormat    format,
                                                     GS::ImageOrientation   orientation) = 0;
	virtual int                 getMaxDeviceWidth  (void)							= 0;
	virtual int                 getMaxDeviceHeight (void)							= 0;
	
	
    virtual void                setDesiredFrameRate      (float frameRate)          = 0;
    virtual void                pauseInteractiveRender   (void)                     = 0;
    virtual void                resumeInteractiveRender  (void)                     = 0;
    virtual void                postRenderProgressCheckingReqeust()                 = 0;

    enum EnableIRResult
    {
        kSuccess,
        kOutOfMemory
    };

    virtual EnableIRResult      beginInteractiveRender   (ZcGsRenderProgressMonitor* pProgressMonitor) = 0;
    virtual void                endInteractiveRender     (void)                                        = 0;
    virtual bool                isRendering              (void) const                                  = 0;

    virtual void                setFontKerningDisplay    (bool bDisplay)            = 0;
	
};

class ZcGsConfigReactor
{
public:
	ZcGsConfigReactor   (void) { }
	virtual     ~ZcGsConfigReactor   (void) { }

	virtual void hardwareAccelerationWasModified(bool) { }
	virtual void configWasModified              (void)          { }
	virtual void deviceSwitchToBegin            (void)          { }
	virtual void deviceSwitchHasEnded           (void)          { }
    virtual void updateAdapterStatus            (int)           { }
};

class ZcGsConfig
{
protected:
    ZcGsConfig(void) = default;    

public:

    enum Handedness
    {
        kLeft,
        kRight
    };    

	enum Quality
	{
		kLowQuality,
		kMediumQuality,
		kHighQuality
	};

	enum DegradationChannel
	{
		kViewportDraw,
		kLineAntialias,
		kLighting,
		kTransparencyQuality,
		kShadowsFull,
		kTransparency,
		kDiscardBackfaces,
		kShadowsGround,
		kEdgeStyles,
		kFacetEdges,
		kFastSilhouette,
		kTextures,
		kMaterials,
		kLightingQuality,
		kBackgrounds,
		kIntersectEdges,
		kFaceted,
		kWireframe,
		kDegradationChannels
	};

    enum FeatureModeType
    {
        kFM_Start = -3,
        kFM_Legacy = kFM_Start,
        kFM_ClassicDx9,
        kFM_ClassicDx11,

        kFM_Software,
        kFM_Basic,
        kFM_Medium,
        kFM_Advanced,

        kFM_Unknown = 0xffff,
    };

	virtual                    ~ZcGsConfig                      (void) = default;
	virtual bool                configure                       (void)                          = 0;
	virtual bool                showConfigDialog                (const wchar_t *strInput = nullptr) const = 0;

    virtual bool                isInConfiguring(void) = 0;

    virtual void                saveToRegistry(void) = 0;

    virtual void                restore(void) = 0;

	virtual void                driverName                      (ZTCHAR * pszPath, 
                                                                 int nStrLen) const             = 0;
    virtual int                 driverVersion                   (void) const                    = 0;
    virtual int                 driverRevision                  (void) const                    = 0;
	virtual void                driverPath                      (ZTCHAR *        pszPath, 
                                                                 int            nStrLen) const  = 0;
	virtual void                setDriverPath                   (const ZTCHAR *  pszPath)        = 0;

	virtual void                currentDisplayDriver            (ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR *        pszDriver,
                                                                 int            nDriverStrLen,
                                                                 bool &         bHardwareAccelerated) const = 0;

	virtual void                hardwareAcceleratedDriver       (ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR *        pszDriver,
                                                                 int            nDriverStrLen) const = 0; 
	virtual void                setHardwareAcceleratedDriver    (const ZTCHAR *  pszPath,
		                                                         const ZTCHAR *  pszDriver)      = 0;

	virtual void                defaultHardwareAcceleratedDriver(ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR *        pszDriver,
                                                                 int            nDriverStrLen) const = 0;
	virtual void                hardwareAcceleratedDrivers      (ZTCHAR *        pszPath,
                                                                 int            nPathStrLen,
                                                                 ZTCHAR **       pszDrivers,
                                                                 int            nDrivers,
																 int			nDriverStrLen)  = 0;
    virtual int                 numHardwareAcceleratedDrivers   (void)                          = 0;

    virtual void                setDynamicTessellation          (bool bDynamicTessellation)     = 0;
    virtual bool                dynamicTessellation             (void)const                     = 0;

    virtual GS::ErrorStatus     setMaxLODs                      (int nLevels)                   = 0;
    virtual int                 maxLODs                         (void)const                     = 0;

    virtual GS::ErrorStatus     setSurfaceTessellationTol       (int surfaceTessellationTol)    = 0;
    virtual int                 surfaceTessellationTol          (void)const                     = 0;

    virtual GS::ErrorStatus     setCurveTessellationTol         (int curveTessellationTol)      = 0;
    virtual int                 curveTessellationTol            (void)const                     = 0;

    virtual GS::ErrorStatus     setFrameRate                    (int nFramesPerSecond)          = 0;
    virtual int                 frameRate                       (void)const                     = 0;

    virtual void                setAdaptiveDegradation          (bool bAdaptiveDegradation)     = 0;
    virtual bool                adaptiveDegradation             (void)const                     = 0;

    virtual int                 degradationChainPosition        (DegradationChannel channel)const = 0;
    virtual DegradationChannel  degradationChannelAt            (int position)const             = 0;
    virtual void                shiftDegradationChainPosition   (DegradationChannel channel,
                                                                 bool bShiftDown)               = 0;
    virtual void                setCanDegradeChannel            (DegradationChannel channel,
                                                                 bool bDegrade)                 = 0;
    virtual bool                canDegradeChannel               (DegradationChannel channel)const= 0;
    virtual void                setRedrawOnWindowExpose         (bool bRedrawWindowExpose)      = 0;
    virtual bool                redrawOnWindowExpose            (void)const                     = 0;

    virtual void                setHandedness                   (Handedness)                    = 0;
    virtual Handedness          handedness                      (void)const                     = 0;

    virtual void                setDiscardBackFaces             (bool bDiscardBackFaces)        = 0;
    virtual bool                discardBackFaces                (void)const                     = 0;

    virtual void                setTransparency                 (Quality quality)               = 0;
    virtual Quality             transparency                    (void)const                     = 0;

	virtual void                addReactor                      (ZcGsConfigReactor *)           = 0;
	virtual void                removeReactor                   (ZcGsConfigReactor *)           = 0;

	
    struct EffectStatus
    {
        const ZcUniqueString* pUniqueString;            
        ZcString              effectName;               
        int                   bEnabled;
        int                   bRecommended;
        int                   bAvailable;
        int                   nFeatureLevel;            
    };

    struct CertificationData
    {
        ZcString              sCardName;                
        ZcString              sDriverVersion;           
        ZcString              sProductDriverURL;        
        ZcString              sTuningDate;              
        ZcString              sDeviceFailed;            
        int                   nHardwareFeatureLevel;    
        int                   nSoftwareFeatureLevel;    
        int                   nCertificationStatus;     
        int                   nHardwareID;              
    };

    enum EffectListType {
        kEL_Current,
        kEL_RegistryHardware,
        kEL_RegistrySoftware,
        kEL_File,
        kEL_HardwareBasic,
        kEL_HardwareMedium,
        kEL_HardwareAdvanced
    };

    virtual ZcArray<EffectStatus> *
                                getEffectList                    (EffectListType type) = 0;

    virtual FeatureModeType     getFeatureMode(void) const = 0;
    virtual int                 getFeatureModeAvailable(void) const = 0;
    virtual void                setFeatureMode(const FeatureModeType) = 0;

    virtual bool                isFeatureEnabled                 (const ZcUniqueString*) const  = 0;
    virtual void                setFeatureEnabled                (const ZcUniqueString*,
                                                                  bool bEnable = true)          = 0;
    virtual int                 getFeatureVal                    (const ZcUniqueString*) const  = 0;
    virtual void                setFeatureVal                    (const ZcUniqueString*,
                                                                  int iVal = 0)                 = 0;
    virtual bool                isFeatureAvailable               (const ZcUniqueString*) const  = 0;
    virtual bool                isFeatureRecommended             (const ZcUniqueString*) const  = 0;
    virtual int                 getFeatureAvailableVal           (const ZcUniqueString*) const  = 0;
    virtual int                 getFeatureRecommendedVal         (const ZcUniqueString*) const  = 0;
	

	virtual void                setHardwareAcceleration          (bool bEnable)                 = 0;
	virtual bool                isHardwareAccelerationEnabled    (void)  const                  = 0;
	virtual bool                isHardwareAccelerationAvailable  (void)  const                  = 0;
	virtual bool                isHardwareAccelerationRecommended(void)  const                  = 0;
	virtual bool                isNoHardwareOverrideEnabled      (void)  const                  = 0;
    virtual CertificationData   getCertificationData             (void)                         = 0;
	virtual ZcString            getVirtualDeviceName             (void)                         = 0;
	virtual void                setGenerateVertexNormals         (bool bEnable)                 = 0;
	virtual bool                generateVertexNormals            (void) const                   = 0;
	
    virtual void                setMetalMode                     (int metalMode)                = 0;
    virtual int                 getMetalMode                     (void) const                   = 0;

    enum SpyglassType
    {
        kNone = 0,               
        kSoftware,
        kHardware
    };

    virtual SpyglassType        spyglassType                     (void) const                   = 0;
    virtual bool                canEnableMetal                   (void) const                   = 0;

    virtual bool                isAADisabledInInteractive        (void) const                   = 0;

    virtual bool                isLODEnabledInRetainModeWhileInteractive        (void) const                   = 0;
	
};

typedef ZcGiDrawable*    (* ZcGsGetInterfaceFunc)            (ZSoft::IntDbId objectId,
                                                              bool bNeedsValidation); 
typedef void             (* ZcGsReleaseInterfaceFunc)        (ZcGiDrawable*);

class ZcGsReactor
{
public:
	                            ZcGsReactor                 (void)  { }
	virtual                    ~ZcGsReactor                 (void)  { }

    enum ViewUpdateFlags { kCameraChanged = 1 };

	virtual void                viewWasCreated              (ZcGsView * pView)  { }
	virtual void                viewToBeDestroyed           (ZcGsView * pView)  { }
	virtual void                viewToBeUpdated             (ZcGsView * pView, int viewUpdateflags) { }
	virtual void                viewWasUpdated              (ZcGsView * pView, int viewUpdateflags) { }
	virtual void                gsToBeUnloaded              (ZcGsGraphicsKernel * pClassFactory) { }
	virtual void                viewInteractivityToBeChanged(const ZcGsView *, bool /*interactive*/) { }
	virtual void                viewInteractivityWasChanged (const ZcGsView *, bool /*interactive*/) { }
};

class ZcGsModelReactor 
{
public:
	ZcGsModelReactor        (void)  { }
	virtual                    ~ZcGsModelReactor        (void)  { }
	virtual bool                onSceneGraphRootAdded   (ZcGsModel* , ZcGiDrawable * )  { return true; }
	virtual bool                onSceneGraphRootErased  (ZcGsModel* , ZcGiDrawable * ) { return true; }
	virtual bool                onAdded                 (ZcGsModel* , ZcGiDrawable * ,ZcGiDrawable * )  { return true; }
	virtual bool                onAdded                 (ZcGsModel* , ZcGiDrawable * , ZSoft::IntDbId ) { return true; }
	virtual bool                onErased                (ZcGsModel* ,	ZcGiDrawable * , ZcGiDrawable * )  { return true; }
	virtual bool                onErased                (ZcGsModel* ,	ZcGiDrawable * , ZSoft::IntDbId ) { return true; }
	virtual bool                onModified              (ZcGsModel* , ZcGiDrawable * , ZcGiDrawable * )  { return true; }
	virtual bool                onModified              (ZcGsModel* , ZcGiDrawable * , ZSoft::IntDbId ) { return true; }
};

struct ZcGsDrawableLink
{
    ZSoft::IntDbId id;
    ZcGiDrawable *pDrawable;
    ZcGsNode *pNode;
};

typedef ZcArray<ZcGsDrawableLink> ZcGsDrawablePath;
struct ZcGsClientViewInfo
{
	ZcGsClientViewInfo()
        : viewportId(0)
		, zcadWindowId(0)
        , viewportObjectId(0)
        , contextColors(nullptr)
		, contextualAttributes(nullptr)
		{ }

	ZSoft::LongPtr viewportId;
	ZSoft::LongPtr zcadWindowId;
	ZSoft::IntDbId viewportObjectId;
	ZcGiContextualColors* contextColors;
	ZcGiContextualAttributes* contextualAttributes;

    ZcDbObjectId viewportObjectAsObjectId() const;
};


#ifndef DRAWBRIDGE_API
#define DRAWBRIDGE_API
#endif 
class ZcGsKernelDescriptor : public ZcGiKernelDescriptor
{
public:
    
	void addSupport(const ZcUniqueString *capability)
    {
        if (capability)
            append(capability); 
    }

	bool hasRequirement(const ZcUniqueString *capability) const
    { 
        return capability ? contains(capability) : false; 
    }

#ifndef DRAWBRIDGE_DATA_API
#define DRAWBRIDGE_DATA_API __declspec(dllimport)
#endif

    static DRAWBRIDGE_DATA_API const ZcUniqueString *k2DDrawing;
    static DRAWBRIDGE_DATA_API const ZcUniqueString *k3DDrawing;
    static DRAWBRIDGE_DATA_API const ZcUniqueString* k3DDrawing2;
    static DRAWBRIDGE_DATA_API const ZcUniqueString *k3DSelection;
    static DRAWBRIDGE_DATA_API const ZcUniqueString *k3DRapidRTRendering;
};

#if defined(__clang__) && !defined(_MSC_VER)
#define DRAWBRIDGE_MAC_API DRAWBRIDGE_API
#else
#define DRAWBRIDGE_MAC_API
#endif

class DRAWBRIDGE_MAC_API ZcGsGraphicsKernel : public ZcGiGraphicsKernel
{
public:
    ZcGsGraphicsKernel   (void) : m_refCount(0) { }

	virtual                    ~ZcGsGraphicsKernel(void) { }
    DRAWBRIDGE_API void addRef               (void);

    DRAWBRIDGE_API bool delRef               (void);

    virtual bool        isCompatibleWith     (const ZcGsKernelDescriptor &descriptor) const = 0;

	virtual ZcGsModel *         createModel     (ZcGsModel::RenderType type, ZSoft::IntDbId databaseId,
                                                 ZcGsGetInterfaceFunc getFunc, ZcGsReleaseInterfaceFunc releaseFunc)  = 0;
	virtual void                deleteModel     (ZcGsModel * pModel)         = 0;

	virtual ZcGsView *          createView      (const ZcGsClientViewInfo * pInfo   = nullptr,
                                                 bool bEnableLayerVisibilityPerView = false) = 0;
	virtual void                deleteView      (ZcGsView * pView)           = 0;

	virtual ZcGsDevice *        createDevice    (ZcGsWindowingSystemID id,
                                                 GS::DeviceType deviceType = GS::kScreenDevice)  = 0;
	virtual ZcGsDevice *        createOffScreenDevice(void)                 = 0;
	virtual void                deleteDevice    (ZcGsDevice * pDevice)       = 0;

	virtual ZcGsConfig *        getConfig       (void) const = 0;

	virtual void                addReactor      (ZcGsReactor * pReactor)    = 0;
	virtual void                removeReactor   (ZcGsReactor * pReactor)    = 0;

	virtual void                addModelReactor (ZcGsModel* pModel,	ZcGsModelReactor* pReactor)   = 0;
	virtual void                removeModelReactor(ZcGsModel* pModel, ZcGsModelReactor* pReactor)   = 0;

	
    virtual void        associate            (ZSoft::LongPtr databasePtr, ZcGsModel *pModel, ZcGsModel::RenderType renderType) = 0;

    virtual ZcGsModel*  find                 (ZSoft::LongPtr databasePtr, ZcGsModel::RenderType renderType) = 0;

protected:
    int m_refCount;
	
};

class ZcGsRenderInterrupter
{
public:
	virtual bool interrupt(ZcGsView* pView, ZcGsModel::RenderType nType) = 0;
};

struct ZcGsRenderStatistics
{
public:
    float fRenderTime;

    size_t iMemory;

    size_t iMaterialCount;

    size_t iLightCount;

    size_t iTriangleCount;
};

class ZcGsRenderProgressMonitor
{
public:
    virtual ~ZcGsRenderProgressMonitor() { }

    enum Phase
    {
        kTranslation,
        kPhotonEmission,
        kFinalGather,
        kRender,
        kDraft,
        kInitialize,
    };

    enum RenderingStatus
    {
        kRendering,
        kPaused,
		kFinished,
		kAborted,
		kWillNotRender,
		kSoftOutOfMemory,
		kHardOutOfMemory,
        kError,
    };

    virtual bool OnProgress(Phase ePhase,
                            float fOverallProgress,
                            int iRenderTimeSpent,
                            int iCurrentRenderLevel,
                            float fCurrentLevelProgress,
                            int iTileIndex = 0) = 0;

    virtual void OnTile(int x, int y, int w, int h, const unsigned char* pPixels) = 0;

    virtual void OnStatusChanged(RenderingStatus status) = 0;

    virtual void SetStatistics(const ZcGsRenderStatistics* pStats) = 0;

    virtual bool ShouldReuseDatabase() { return false; }

    virtual bool IsValid() { return true; }

    virtual bool IsAsync() { return false; }

    virtual bool IsOutputImageFlipped() { return false; }
};


#pragma pack (pop)
