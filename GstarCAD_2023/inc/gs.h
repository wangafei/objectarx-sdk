/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcarray.h"
#include "GdGChar.h"
#include "gept3dar.h"
#include "dbid.h"
#include "GcString.h"
#include "gcgi.h"

class GcGeMatrix3d;
class GcGePoint3d;
class GcGeVector3d;
class GcGePoint2d;

class GcGsModel;
class GcGsDevice;
class GcGsGraphicsKernel;
class GcGiVisualStyle;
class GcGiContextualColors;
class GcGiContextualAttributes;
struct GcGsClientViewInfo;
class GcGsRenderInterrupter;
class GcGsRenderProgressMonitor;

namespace Gtil
{
  class Image;
};

namespace GS
{
  enum ErrorStatus
  {
    kSuccess,
    kOutOfRange,
    kInvalidInput
  };

  enum DeviceType
  {
    kScreenDevice    = 0,
    kOffScreenDevice = 1,
    kSelectionDevice = 2
  };

  enum HighlightStyle
  {
    kHighlightDashed           = 0,
    kHighlightThicken          = 1,
    kHighlightDashedAndThicken = 2,
    kHighlightCustom           = 3,
    kHighlightDim              = 4,
    kHighlightThickDim         = 5,
    kHighlightGlow             = 6
  };

  enum SyncBehavior
  {
    eSync  = 0,
    eAsync = 1,
  };

  enum ImageOrientation
  {
    kTopDown  = 0,
    kBottomUp = 1
  };

  enum ImageDataFormat
  {
    kRGBA = 0,
    kBGRA = 1
  };
};

#define SCALAR_MIN     (-2147483647 - 1)
#define SCALAR_MAX       2147483647
#pragma pack (push, 8)

class GcGsDCPoint
{
public:
  enum            MaxFlag { Maximum };
  enum            MinFlag { Minimum };

  GcGsDCPoint(void) { }
  GcGsDCPoint(long xin, long yin) : x(xin), y(yin) { }

  GcGsDCPoint(MaxFlag) { x = SCALAR_MAX; y = SCALAR_MAX; }
  GcGsDCPoint(MinFlag) { x = SCALAR_MIN; y = SCALAR_MIN; }

  void            operator=   (MaxFlag) { x = SCALAR_MAX; y = SCALAR_MAX; }
  void            operator=   (MinFlag) { x = SCALAR_MIN; y = SCALAR_MIN; }

  void            operator=   (GcGsDCPoint const & r) { x = r.x;   y = r.y; }
  bool            operator==  (GcGsDCPoint const & r) const { return x == r.x && y == r.y; }
  bool            operator!=  (GcGsDCPoint const & r) const { return x != r.x || y != r.y; }

  long            x;
  long            y;
};

class GcGsDCRect
{
public:
  enum NullFlag
  {
    Null
  };

  GcGsDCRect(void) { }
  GcGsDCRect(GcGsDCPoint const & min, GcGsDCPoint const & max) : m_min(min), m_max(max) { }
  GcGsDCRect(long l, long r, long b, long t) : m_min(l, b), m_max(r, t) { }
  GcGsDCRect(NullFlag) { set_null(); }

  GcGsDCRect &    operator= (GcGsDCRect const & other)
  {
    m_min = other.m_min;
    m_max = other.m_max;
    return *this;
  }
  void            operator|= (GcGsDCRect const & rightside)
  {
    if (m_min.x > rightside.m_min.x)
      m_min.x = rightside.m_min.x;
    if (m_max.x < rightside.m_max.x)
      m_max.x = rightside.m_max.x;

    if (m_min.y > rightside.m_min.y)
      m_min.y = rightside.m_min.y;
    if (m_max.y < rightside.m_max.y)
      m_max.y = rightside.m_max.y;
  }
  void            operator&= (GcGsDCRect const & rightside)
  {
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
  bool            operator== (GcGsDCRect const & rightside) const
  {
    return m_min == rightside.m_min && m_max == rightside.m_max;
  }
  bool            operator!= (GcGsDCRect const & rightside) const
  {
    return !(*this == rightside);
  }

  void            set_null(void)
  {
    m_min = GcGsDCPoint::Maximum;
    m_max = GcGsDCPoint::Minimum;
  }

  bool            is_null(void) const
  {
#ifdef ASSERT
    ASSERT((m_min.x <= m_max.x && m_min.y <= m_max.y) ||
      (m_min == GcGsDCPoint::Maximum && m_max == GcGsDCPoint::Minimum));
#endif
    return m_min.x > m_max.x;
  }

  bool            within(GcGsDCRect const & rightside) const
  {
#ifdef ASSERT
    ASSERT(!is_null());
#endif
    return m_min.x >= rightside.m_min.x &&
      m_min.y >= rightside.m_min.y &&
      m_max.x <= rightside.m_max.x &&
      m_max.y <= rightside.m_max.y;
  }

  GcGsDCPoint     m_min;
  GcGsDCPoint     m_max;
};

struct GcGsColor
{
  unsigned char m_red;
  unsigned char m_green;
  unsigned char m_blue;
  unsigned char m_filler;
};

typedef void *GcGsWindowingSystemID;
typedef void *GcGsWindowId;

class GcGsNode
{
public:
  virtual ~GcGsNode() { }
  virtual GcGiDrawable *drawable(void) const = 0;
};

class GcGsView
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

  virtual                    ~GcGsView(void) { }

  virtual GcGsGraphicsKernel &graphicsKernel(void) = 0;

  virtual void                setViewport(const GcGePoint2d & lowerLeft, const GcGePoint2d & upperRight) = 0;
  virtual void                setViewport(const GcGsDCRect  & screen_rect) = 0;
  virtual void                getViewport(GcGePoint2d & lowerLeft, GcGePoint2d & upperRight)  const = 0;
  virtual void                getViewport(GcGsDCRect  & screen_rect) const = 0;

  virtual void                setViewportClipRegion(int contours, int const * counts, GcGsDCPoint const * points) = 0;
  virtual void                removeViewportClipRegion(void) = 0;

  virtual void                setViewportBorderProperties(GcGsColor const & color, int weight) = 0;
  virtual void                getViewportBorderProperties(GcGsColor & color, int & weight) const = 0;

  virtual void                setViewportBorderVisibility(bool                bVisible) = 0;
  virtual bool                isViewportBorderVisible(void) const = 0;

  virtual void                setView(const GcGePoint3d &  position,
                                      const GcGePoint3d &  target,
                                      const GcGeVector3d&  upVector,
                                      double               fieldWidth,
                                      double               fieldHeight,
                                      Projection           projection = kParallel) = 0;

  virtual GcGePoint3d         position(void) const = 0;
  virtual GcGePoint3d         target(void) const = 0;
  virtual GcGeVector3d        upVector(void) const = 0;
  virtual bool                isPerspective(void) const = 0;
  virtual double              fieldWidth(void) const = 0;
  virtual double              fieldHeight(void) const = 0;

  virtual void                setEnableFrontClip(bool enable) = 0;
  virtual bool                isFrontClipped(void) const = 0;
  virtual void                setFrontClip(double distance) = 0;
  virtual double              frontClip(void) const = 0;

  virtual void                setEnableBackClip(bool enable) = 0;
  virtual bool                isBackClipped(void) const = 0;
  virtual void                setBackClip(double distance) = 0;
  virtual double              backClip(void) const = 0;

  virtual GcGeMatrix3d        viewingMatrix(void) const = 0;
  virtual GcGeMatrix3d        projectionMatrix(void) const = 0;
  virtual GcGeMatrix3d        screenMatrix(void) const = 0;
  virtual GcGeMatrix3d        worldToDeviceMatrix(void) const = 0;
  virtual GcGeMatrix3d        objectToDeviceMatrix(void) const = 0;

  virtual bool                add(GcGiDrawable * drawable, GcGsModel    * model) = 0;
  virtual bool                erase(GcGiDrawable * drawable) = 0;
  virtual void                eraseAll(void) = 0;

  virtual void                invalidate(void) = 0;
  virtual void                invalidate(const GcGsDCRect &rect) = 0;
  virtual bool                isValid(void) const = 0;

  virtual void                update(void) = 0;
  virtual void                beginInteractivity(double fFrameRateInHz) = 0;
  virtual void                endInteractivity(void) = 0;
  virtual bool                isInteractive(void) const = 0;
  virtual void                flush(void) = 0;

  virtual void                setMaximumUpgrade(int step) = 0;
  virtual int                 maximumUpgrade(void) = 0;
  virtual void                setMinimumDegrade(int step) = 0;
  virtual int                 minimumDegrade(void) = 0;

  virtual void                hide(void) = 0;
  virtual void                show(void) = 0;
  virtual bool                isVisible(void) = 0;

  virtual void                freezeLayer(Gsoft::IntDbId layerID) = 0;
  virtual void                thawLayer(Gsoft::IntDbId layerID) = 0;
  virtual void                clearFrozenLayers(void) = 0;

  virtual void                invalidateCachedViewportGeometry(void) = 0;
  virtual void                invalidateCachedViewportGeometry(GcGiDrawable* pDrawable) = 0;

  virtual void                dolly(const GcGeVector3d & vector) = 0;
  virtual void                dolly(double x, double y, double z) = 0;
  virtual void                roll(double angle) = 0;
  virtual void                orbit(double x, double y) = 0;
  virtual void                zoom(double factor) = 0;
  virtual void                zoomExtents(const GcGePoint3d& minPoint, const GcGePoint3d& maxPoint) = 0;
  virtual void                zoomWindow(const GcGePoint2d& lowerLeft, const GcGePoint2d& upperRight) = 0;
  virtual void                pan(double x, double y) = 0;

  virtual bool                pointInView(const GcGePoint3d& pnt) = 0;
  virtual bool                extentsInView(const GcGePoint3d& minPoint, const GcGePoint3d& maxPoint) = 0;

  virtual GcGsView *          clone(bool bCloneViewParameters = true, bool bCloneGeometry = false) = 0;

  virtual bool                exceededBounds(void) = 0;

  virtual void                enableStereo(bool bEnable) = 0;
  virtual bool                isStereoEnabled(void) const = 0;
  virtual void                setStereoParameters(double   magnitude, double   parallax) = 0;
  virtual void                getStereoParameters(double & magnitude, double & parallax) const = 0;

  virtual void                getSnapShot(Gtil::Image       * pOutput,
                                          GcGsDCPoint const & offset) = 0;

  virtual bool                renderToImage(Gtil::Image* pOutput,
                                            GcGiDrawable* pSettings,
                                            GcGsRenderProgressMonitor* pProgressMonitor,
                                            const GcGsDCRect & rectScreen,
                                            bool bReuseScene = false) = 0;

  virtual GcGsDevice *        getDevice(void) const = 0;

  virtual void                setVisualStyle(const GcDbObjectId visualStyleId) = 0;
  virtual GcDbObjectId        visualStyle(void) const = 0;
  virtual void                setVisualStyle(const GcGiVisualStyle &visualStyle) = 0;
  virtual bool                visualStyle(GcGiVisualStyle &visualStyle) const = 0;

  virtual void                setBackground(const GcDbObjectId backgroundId) = 0;
  virtual GcDbObjectId        background(void) const = 0;

  virtual void                enableDefaultLighting(bool bEnable,
                                                    DefaultLightingType type = kTwoLights) = 0;

  virtual void                getNumPixelsInUnitSquare(const GcGePoint3d& givenWorldpt,
                                                       GcGePoint2d& pixelArea,
                                                       bool includePerspective = true) const = 0;

  virtual GcGsModel*          getModel(GcGiDrawable*) const = 0;
  virtual void                getModelList(GcArray<GcGsModel*>&) const = 0;

  virtual const               GcGsClientViewInfo& getClientViewInfo() const = 0;

  virtual void                update(GS::SyncBehavior sync) = 0;
  virtual bool                isPointInViewport(const Gsoft::Int32 x, const Gsoft::Int32 y) = 0;
  virtual GcGsView *          clone(bool bCloneViewParameters, ModelCloneOption cloneOption) = 0;
  virtual Gtil::Image *       createSnapshot(const GcGsDCPoint&     offset,
                                             const GcGsDCRect&      imageDim,
                                             GS::ImageDataFormat    format,
                                             GS::ImageOrientation   orientation,
                                             bool                   bOnlyCaptureRenderedImage = false) = 0;

  enum EnableIRResult
  {
    kSuccess,
    kOutOfMemory
  };

  virtual EnableIRResult      beginInteractiveRender(GcGsRenderProgressMonitor* pProgressMonitor) = 0;
  virtual void                endInteractiveRender(void) = 0;
  virtual bool                isRendering(void) const = 0;

  virtual void                beginFastInteractivity(void) = 0;
  virtual bool                endFastInteractivity(void) = 0;
  virtual bool                isFastInteractivity(void) = 0;
};

class GcGsModel
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

  virtual                    ~GcGsModel(void) { }

  virtual GcGsGraphicsKernel &graphicsKernel(void) = 0;

  virtual bool                addSceneGraphRoot(GcGiDrawable * pRoot) = 0;
  virtual bool                eraseSceneGraphRoot(GcGiDrawable * pRoot) = 0;

  virtual void                onAdded(GcGiDrawable * pAdded, GcGiDrawable * pParent) = 0;
  virtual void                onAdded(GcGiDrawable * pAdded, Gsoft::IntDbId parentID) = 0;

  virtual void                onModified(GcGiDrawable * pModified, GcGiDrawable * pParent) = 0;
  virtual void                onModified(GcGiDrawable * pModified, Gsoft::IntDbId parentID) = 0;

  virtual void                onErased(GcGiDrawable * pErased, GcGiDrawable * pParent) = 0;
  virtual void                onErased(GcGiDrawable * pErased, Gsoft::IntDbId parentID) = 0;

  virtual void                onPaletteModified(void) = 0;

  virtual void                setTransform(const GcGeMatrix3d &) = 0;
  virtual GcGeMatrix3d        transform(void) const = 0;
  virtual void                setExtents(const GcGePoint3d &, const GcGePoint3d &) = 0;

  virtual void                invalidate(InvalidationHint hint) = 0;

  virtual void                setViewClippingOverride(bool bOverride) = 0;

  virtual void                setVisualStyle(const GcDbObjectId visualStyleId) = 0;
  virtual GcDbObjectId        visualStyle(void) const = 0;
  virtual void                setVisualStyle(const GcGiVisualStyle &visualStyle) = 0;
  virtual bool                visualStyle(GcGiVisualStyle &visualStyle) const = 0;

  virtual void                setBackground(const GcDbObjectId backgroundId) = 0;
  virtual GcDbObjectId        background(void) const = 0;

  virtual void                enableLinetypes(bool bEnable) = 0;
  virtual bool                linetypesEnabled(void) const = 0;

  virtual void                setEnableSectioning(bool enable) = 0;
  virtual bool                isSectioningEnabled(void) const = 0;
  virtual bool                setSectioning(const GcGePoint3dArray & pts,
                                            const GcGeVector3d &     upVector) = 0;
  virtual bool                setSectioning(const GcGePoint3dArray & pts,
                                            const GcGeVector3d &     upVector,
                                            double                   top,
                                            double                   bottom) = 0;
  virtual void                setSectioningVisualStyle(const GcDbObjectId visualStyleId) = 0;

  virtual RenderType          renderType(void) = 0;

  virtual double              shadowPlaneLocation(void) const = 0;
  virtual void                setShadowPlaneLocation(double planeLocationZ) = 0;

  virtual void                setSelectable(bool bEnable) = 0;
  virtual bool                selectable(void) const = 0;

  virtual void                setDrawOrder(GcGiDrawable*   pDrawable,
                                           GcGiDrawable*   pRelativeDrawable,
                                           GcGiDrawable*   pParent,
                                           OrderActionType action) = 0;

  virtual bool                bounds(const GcGiDrawable& drawable,
                                     GcGePoint3d& minPt,
                                     GcGePoint3d& maxPt) = 0;

  virtual void                onModified(GcGiDrawable * pModified,
                                         GcGiDrawable * pParent,
                                         InvalidationHint hint) = 0;
  virtual void                onModified(GcGiDrawable * pModified,
                                         Gsoft::IntDbId  parentID,
                                         InvalidationHint hint) = 0;

  virtual void                setUnitScale(double metersPerUnit) = 0;
  virtual double              unitScale(void) const = 0;

  virtual void                setLightingPhotometric(bool bPhotometric) = 0;
  virtual bool                isLightingPhotometric(void) const = 0;

  virtual void                setLightsInBlocksEnabled(bool bEnabled) = 0;
  virtual bool                lightsInBlocksEnabled(void) const = 0;
};

class GcGsDevice
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

  virtual                    ~GcGsDevice(void) { }

  virtual GcGsGraphicsKernel &graphicsKernel(void) = 0;

  virtual void                invalidate(void) = 0;
  virtual void                invalidate(const GcGsDCRect &rect) = 0;
  virtual bool                isValid(void) const = 0;

  virtual void                update(GcGsDCRect *pUpdatedRect = nullptr) = 0;

  virtual void                onSize(int width, int height) = 0;
  virtual void                onRealizeForegroundPalette(void) = 0;
  virtual void                onRealizeBackgroundPalette(void) = 0;
  virtual void                onDisplayChange(int nBitsPerPixel, int nXRes, int nYRes) = 0;
  virtual bool                add(GcGsView * view) = 0;
  virtual bool                erase(GcGsView * view) = 0;
  virtual void                eraseAll(void) = 0;

  virtual bool                setBackgroundColor(GcGsColor color) = 0;
  virtual GcGsColor           getBackgroundColor(void) = 0;

  virtual void                setLogicalPalette(const GcGsColor * palette, int nCount) = 0;
  virtual void                setPhysicalPalette(const GcGsColor * palette, int nCount) = 0;

  virtual void                getSnapShot(Gtil::Image * pOutput, GcGsDCPoint const & offset) = 0;
  virtual void                setDeviceRenderer(RendererType type) = 0;
  virtual RendererType        getDeviceRenderer(void) = 0;

  virtual void                   setRenderInterrupter(GcGsRenderInterrupter* pInterrupter) = 0;
  virtual GcGsRenderInterrupter* getRenderInterrupter(void) const = 0;
  virtual void                   setDisplayUpdateSuppressed(bool bSuppressed) = 0;

  virtual void                invalidate(GcGsModel::RenderType pane) = 0;
  virtual void                invalidate(const GcGsDCRect &rect, GcGsModel::RenderType pane) = 0;
  virtual void                update(GcGsDCRect* pUpdatedRect, GS::SyncBehavior sync) = 0;
  virtual Gtil::Image *       createSnapshot(const GcGsDCPoint&     offset,
                                             const GcGsDCRect&      imageDim,
                                             GS::ImageDataFormat    format,
                                             GS::ImageOrientation   orientation) = 0;

  virtual int                 getMaxDeviceWidth(void) = 0;
  virtual int                 getMaxDeviceHeight(void) = 0;

  virtual void                setDesiredFrameRate(float frameRate) = 0;
  virtual void                pauseInteractiveRender(void) = 0;
  virtual void                resumeInteractiveRender(void) = 0;
  virtual void                postRenderProgressCheckingReqeust() = 0;

  enum EnableIRResult
  {
    kSuccess,
    kOutOfMemory
  };
  virtual EnableIRResult      beginInteractiveRender(GcGsRenderProgressMonitor* pProgressMonitor) = 0;
  virtual void                endInteractiveRender(void) = 0;
  virtual bool                isRendering(void) const = 0;
  virtual void                setFontKerningDisplay(bool bDisplay) = 0;
};

class GcGsConfigReactor
{
public:
  GcGsConfigReactor(void) { }
  virtual     ~GcGsConfigReactor(void) { }

  virtual void hardwareAccelerationWasModified(bool) { }
  virtual void configWasModified(void) { }
  virtual void deviceSwitchToBegin(void) { }
  virtual void deviceSwitchHasEnded(void) { }
};

class GcGsConfig
{
protected:
  GcGsConfig(void) = default;
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

  virtual                    ~GcGsConfig(void) = default;

  virtual bool                configure(void) = 0;
  virtual bool                showConfigDialog(const wchar_t *strInput = nullptr) const = 0;

  virtual void                driverName(GCHAR *pszPath, int nStrLen) const = 0;
  virtual int                 driverVersion(void) const = 0;
  virtual int                 driverRevision(void) const = 0;
  virtual void                driverPath(GCHAR *pszPath, int    nStrLen) const = 0;
  virtual void                setDriverPath(const GCHAR *pszPath) = 0;

  virtual void                currentDisplayDriver(GCHAR *pszPath,
                                                   int    nPathStrLen,
                                                   GCHAR *pszDriver,
                                                   int    nDriverStrLen,
                                                   bool  &bAccelerated) const = 0;

  virtual void                hardwareAcceleratedDriver(GCHAR *pszPath,
                                                        int    nPathStrLen,
                                                        GCHAR *pszDriver,
                                                        int    nDriverStrLen) const = 0;
  virtual void                setHardwareAcceleratedDriver(const GCHAR *pszPath,
                                                           const GCHAR *pszDriver) = 0;

  virtual void                defaultHardwareAcceleratedDriver(GCHAR *pszPath,
                                                               int    nPathStrLen,
                                                               GCHAR *pszDriver,
                                                               int    nDriverStrLen) const = 0;
  virtual void                hardwareAcceleratedDrivers(GCHAR  *pszPath,
                                                         int     nPathStrLen,
                                                         GCHAR **pszDrivers,
                                                         int     nDrivers,
                                                         int     nDriverStrLen) = 0;
  virtual int                 numHardwareAcceleratedDrivers(void) = 0;

  virtual void                setDynamicTessellation(bool bDynamicTessellation) = 0;
  virtual bool                dynamicTessellation(void) const = 0;

  virtual GS::ErrorStatus     setMaxLODs(int nLevels) = 0;
  virtual int                 maxLODs(void) const = 0;

  virtual GS::ErrorStatus     setSurfaceTessellationTol(int surfaceTessellationTol) = 0;
  virtual int                 surfaceTessellationTol(void) const = 0;

  virtual GS::ErrorStatus     setCurveTessellationTol(int curveTessellationTol) = 0;
  virtual int                 curveTessellationTol(void) const = 0;

  virtual GS::ErrorStatus     setFrameRate(int nFramesPerSecond) = 0;
  virtual int                 frameRate(void) const = 0;

  virtual void                setAdaptiveDegradation(bool bAdaptiveDegradation) = 0;
  virtual bool                adaptiveDegradation(void) const = 0;

  virtual int                 degradationChainPosition(DegradationChannel) const = 0;
  virtual DegradationChannel  degradationChannelAt(int position) const = 0;
  virtual void                shiftDegradationChainPosition(DegradationChannel, bool bShiftDown) = 0;
  virtual void                setCanDegradeChannel(DegradationChannel, bool bDegrade) = 0;
  virtual bool                canDegradeChannel(DegradationChannel) const = 0;

  virtual void                setRedrawOnWindowExpose(bool bRedrawWindowExpose) = 0;
  virtual bool                redrawOnWindowExpose(void) const = 0;

  virtual void                setHandedness(Handedness) = 0;
  virtual Handedness          handedness(void) const = 0;

  virtual void                setDiscardBackFaces(bool bDiscardBackFaces) = 0;
  virtual bool                discardBackFaces(void) const = 0;

  virtual void                setTransparency(Quality quality) = 0;
  virtual Quality             transparency(void) const = 0;

  virtual void                addReactor(GcGsConfigReactor *) = 0;
  virtual void                removeReactor(GcGsConfigReactor *) = 0;

  struct EffectStatus
  {
    const GcUniqueString* pUniqueString;
    GcString              effectName;
    int                   bEnabled;
    int                   bRecommended;
    int                   bAvailable;
    int                   nFeatureLevel;
  };

  struct CertificationData
  {
    GcString              sCardName;
    GcString              sDriverVersion;
    GcString              sProductDriverURL;
    GcString              sTuningDate;
    GcString              sDeviceFailed;
    int                   nHardwareFeatureLevel;
    int                   nSoftwareFeatureLevel;
    int                   nCertificationStatus;
    int                   nHardwareID;
  };

  enum EffectListType
  {
    kEL_Current,
    kEL_RegistryHardware,
    kEL_RegistrySoftware,
    kEL_File,
    kEL_HardwareBasic,
    kEL_HardwareMedium,
    kEL_HardwareAdvanced
  };

  virtual GcArray<EffectStatus> * getEffectList(EffectListType type) = 0;

  virtual bool                isFeatureEnabled(const GcUniqueString*) const = 0;
  virtual void                setFeatureEnabled(const GcUniqueString*, bool bEnable = true) = 0;
  virtual int                 getFeatureVal(const GcUniqueString*) const = 0;
  virtual void                setFeatureVal(const GcUniqueString*, int iVal = 0) = 0;
  virtual bool                isFeatureAvailable(const GcUniqueString*) const = 0;
  virtual bool                isFeatureRecommended(const GcUniqueString*) const = 0;
  virtual int                 getFeatureAvailableVal(const GcUniqueString*) const = 0;
  virtual int                 getFeatureRecommendedVal(const GcUniqueString*) const = 0;

  virtual void                setHardwareAcceleration(bool bEnable) = 0;
  virtual bool                isHardwareAccelerationEnabled(void) = 0;
  virtual bool                isHardwareAccelerationAvailable(void) = 0;
  virtual bool                isHardwareAccelerationRecommended(void) = 0;
  virtual bool                isNoHardwareOverrideEnabled(void) = 0;

  virtual CertificationData   getCertificationData(void) = 0;
  virtual GcString            getVirtualDeviceName(void) = 0;

  virtual void                setGenerateVertexNormals(bool bEnable) = 0;
  virtual bool                generateVertexNormals(void) const = 0;

  enum SpyglassType
  {
    kNone = 0,
    kSoftware,
    kHardware
  };

  virtual SpyglassType        spyglassType(void) const = 0;
  virtual bool                isAADisabledInInteractive(void) const = 0;
  virtual bool                isLODEnabledInRetainModeWhileInteractive(void) const = 0;
};

typedef GcGiDrawable*    (*GcGsGetInterfaceFunc)    (Gsoft::IntDbId objectId, bool bNeedsValidation);
typedef void(*GcGsReleaseInterfaceFunc)(GcGiDrawable*);

class GcGsReactor
{
public:
  GcGsReactor(void) { }
  virtual                    ~GcGsReactor(void) { }

  enum ViewUpdateFlags { kCameraChanged = 1 };

  virtual void                viewWasCreated(GcGsView *) { }
  virtual void                viewToBeDestroyed(GcGsView *) { }
  virtual void                viewToBeUpdated(GcGsView *, int) { }
  virtual void                viewWasUpdated(GcGsView *, int) { }
  virtual void                gsToBeUnloaded(GcGsGraphicsKernel *) { }

  virtual void                viewInteractivityToBeChanged(const GcGsView *, bool) { }
  virtual void                viewInteractivityWasChanged(const GcGsView *, bool) { }
};

class GcGsModelReactor
{
public:
  GcGsModelReactor(void) { }
  virtual                    ~GcGsModelReactor(void) { }

  virtual bool                onSceneGraphRootAdded(GcGsModel    *, GcGiDrawable *) { return true; }
  virtual bool                onSceneGraphRootErased(GcGsModel    *, GcGiDrawable *) { return true; }

  virtual bool                onAdded(GcGsModel    *, GcGiDrawable *, GcGiDrawable *) { return true; }
  virtual bool                onAdded(GcGsModel    *, GcGiDrawable *, Gsoft::IntDbId) { return true; }

  virtual bool                onErased(GcGsModel    *, GcGiDrawable *, GcGiDrawable *) { return true; }
  virtual bool                onErased(GcGsModel    *, GcGiDrawable *, Gsoft::IntDbId) { return true; }

  virtual bool                onModified(GcGsModel    *, GcGiDrawable *, GcGiDrawable *) { return true; }
  virtual bool                onModified(GcGsModel    *, GcGiDrawable *, Gsoft::IntDbId) { return true; }
};

struct GcGsDrawableLink
{
  Gsoft::IntDbId id;
  GcGiDrawable  *pDrawable;
  GcGsNode      *pNode;
};

typedef GcArray<GcGsDrawableLink> GcGsDrawablePath;

struct GcGsClientViewInfo
{
  GcGsClientViewInfo()
    : viewportId(0)
    , acadWindowId(0)
    , viewportObjectId(0)
    , contextColors(nullptr)
    , contextualAttributes(nullptr) { }

  Gsoft::LongPtr            viewportId;
  Gsoft::LongPtr            acadWindowId;
  Gsoft::IntDbId            viewportObjectId;
  GcGiContextualColors     *contextColors;
  GcGiContextualAttributes *contextualAttributes;

  GcDbObjectId viewportObjectAsObjectId() const;
};

#ifndef DRAWBRIDGE_API
#define DRAWBRIDGE_API
#endif
class GcGsKernelDescriptor : public GcGiKernelDescriptor
{
public:
  void addSupport(const GcUniqueString *capability)
  {
    if (capability)
      append(capability);
  }

  bool requires(const GcUniqueString *capability) const
  {
    return capability ? contains(capability) : false;
  }

#ifndef DRAWBRIDGE_DATA_API
#define DRAWBRIDGE_DATA_API __declspec(dllimport)
#endif

  static DRAWBRIDGE_DATA_API const GcUniqueString *k2DDrawing;
  static DRAWBRIDGE_DATA_API const GcUniqueString *k3DDrawing;
  static DRAWBRIDGE_DATA_API const GcUniqueString *k3DSelection;
  static DRAWBRIDGE_DATA_API const GcUniqueString *k3DRapidRTRendering;
};

#ifdef __clang__
#define DRAWBRIDGE_MAC_API DRAWBRIDGE_API
#else
#define DRAWBRIDGE_MAC_API
#endif

class DRAWBRIDGE_MAC_API GcGsGraphicsKernel : public GcGiGraphicsKernel
{
public:
  GcGsGraphicsKernel(void) : m_refCount(0) { }
  ~GcGsGraphicsKernel(void) { }

  DRAWBRIDGE_API void addRef(void);
  DRAWBRIDGE_API bool delRef(void);

  virtual bool        isCompatibleWith(const GcGsKernelDescriptor &descriptor) const = 0;

  virtual GcGsModel  *createModel(GcGsModel::RenderType type,
                                  Gsoft::IntDbId databaseId,
                                  GcGsGetInterfaceFunc getFunc,
                                  GcGsReleaseInterfaceFunc releaseFunc) = 0;
  virtual void        deleteModel(GcGsModel *pModel) = 0;
  virtual GcGsView   *createView(const GcGsClientViewInfo * pClientViewInfo = nullptr,
                                 bool bEnableLayerVisibilityPerView = false) = 0;
  virtual void        deleteView(GcGsView *pView) = 0;

  virtual GcGsDevice *createDevice(GcGsWindowingSystemID id, GS::DeviceType deviceType = GS::kScreenDevice) = 0;

  virtual GcGsDevice *createOffScreenDevice(void) = 0;

  virtual void        deleteDevice(GcGsDevice *pDevice) = 0;

  virtual GcGsConfig *getConfig(void) const = 0;

  virtual void        addReactor(GcGsReactor *pReactor) = 0;
  virtual void        removeReactor(GcGsReactor *pReactor) = 0;

  virtual void        addModelReactor(GcGsModel *pModel, GcGsModelReactor *pReactor) = 0;
  virtual void        removeModelReactor(GcGsModel *pModel, GcGsModelReactor *pReactor) = 0;

  virtual void        associate(Gsoft::LongPtr databasePtr, GcGsModel *pModel, GcGsModel::RenderType renderType) = 0;

  virtual GcGsModel*  find(Gsoft::LongPtr databasePtr, GcGsModel::RenderType renderType) = 0;

protected:
  int m_refCount;
};

class GcGsRenderInterrupter
{
public:
  virtual bool interrupt(GcGsView* pView, GcGsModel::RenderType nType) = 0;
};

struct GcGsRenderStatistics
{
public:
  float  fRenderTime;
  size_t iMemory;
  size_t iMaterialCount;
  size_t iLightCount;
  size_t iTriangleCount;
};

class GcGsRenderProgressMonitor
{
public:
  virtual ~GcGsRenderProgressMonitor() { }

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
                          int   iRenderTimeSpent,
                          int   iCurrentRenderLevel,
                          float fCurrentLevelProgress,
                          int   iTileIndex = 0) = 0;

  virtual void OnTile(int x, int y, int w, int h, const unsigned char* pPixels) = 0;

  virtual void OnStatusChanged(RenderingStatus status) = 0;
  virtual void SetStatistics(const GcGsRenderStatistics* pStats) = 0;
  virtual bool ShouldReuseDatabase() { return false; }

  virtual bool IsValid() { return true; }
  virtual bool IsAsync() { return false; }
  virtual bool IsOutputImageFlipped() { return false; }
};
#pragma pack(pop)
