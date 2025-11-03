#pragma once

#include "Gs.h"

class OdGsNode;

namespace Atil
{
  class Image;
};

// ****************************************************************************
// OdGsConfig
// ****************************************************************************

class OdGsConfig
{
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
    kViewportDraw,        // Viewport draw objects On to Off
    kLineAntialias,       // Line antialias On to Off
    kLighting,            // User lighting to Default lighting
    kTransparencyQuality, // Transparency quality High to Medium then Medium to Low
    kShadowsFull,         // Full Shadows to Ground Shadows
    kTransparency,        // Transparency On to Off
    kDiscardBackfaces,    // Discard Backfaces Off to On
    kShadowsGround,       // Ground Shadows to Shadows Off
    kEdgeStyles,          // Any Edge Style On to All Edge Styles Off
    kFacetEdges,          // Facet Edges to Isolines
    kFastSilhouette,      // Fast silhouettes On to Off
    kTextures,            // Textures On to Off
    kMaterials,           // Materials On to Off
    kLightingQuality,     // Lighting Quality Per-Vertex to Per-Face
    kBackgrounds,         // Backgrounds On to Off
    kIntersectEdges,      // Face Intersect Edges On to Off
    kFaceted,             // Faceted to Wireframe
    kWireframe,           // Wireframe to Bounding box
    kDegradationChannels
  };

  enum HardwareFeature {
    kHwAcceleration,
    kHwGeometryAccel,
    kHwAntiAliasing,
    kHwGooch,
    kHwShadows,
    kHwTextureCompression,
    kHwPhong,
    kHw2DHwAcceleration,
    kHwDisable2DPreClip,
    kHwFeatures
  };

  virtual ~OdGsConfig(void) {}

  // dialog, read & write registry
  virtual bool configure(const OdChar * pszConfigInfo, bool bShowDialog) = 0;

  virtual bool saveSettings(void) = 0;

  // hardware & software drivers
  virtual void driverName(OdChar * pszPath, int nStrLen) const = 0;
  virtual int driverVersion(void) const = 0;
  virtual int driverRevision(void) const = 0;
  virtual void driverPath(OdChar * pszPath,int nStrLen) const = 0;
  virtual void setDriverPath(const OdChar * pszPath) = 0;

  virtual void currentDisplayDriver(
    OdChar * pszPath,
    int            nPathStrLen,
    OdChar *        pszDriver,
    int            nDriverStrLen,
    bool &         bHardwareAccelerated) = 0;

  virtual void hardwareAcceleratedDriver(
    OdChar *        pszPath,
    int             nPathStrLen,
    OdChar *        pszDriver,
    int             nDriverStrLen) = 0;

  virtual void setHardwareAcceleratedDriver(
    const OdChar *  pszPath,
    const OdChar *  pszDriver) = 0;

  virtual void defaultHardwareAcceleratedDriver(
    OdChar *        pszPath,
    int             nPathStrLen,
    OdChar *        pszDriver,
    int             nDriverStrLen) = 0;

  virtual void hardwareAcceleratedDrivers(
    OdChar *        pszPath,
    int             nPathStrLen,
    OdChar **       pszDrivers,
    int             nDrivers) = 0;

  virtual int numHardwareAcceleratedDrivers(void) = 0;

  // level of detail & dynamic tessellation
  virtual void setDynamicTessellation(bool bDynamicTessellation) = 0;

  virtual bool dynamicTessellation(void) = 0;

  virtual OdResult setMaxLODs(int nLevels) = 0;
  virtual int maxLODs(void) = 0;

  virtual OdResult setSurfaceTessellationTol(int surfaceTessellationTol) = 0;
  virtual int surfaceTessellationTol(void) = 0;

  virtual OdResult setCurveTessellationTol(int curveTessellationTol) = 0;
  virtual int curveTessellationTol(void) = 0;

  // adaptive degradation
  virtual int frameRate(void) = 0;
  virtual OdResult setFrameRate(int nFramesPerSecond) = 0;

  virtual void setAdaptiveDegradation(bool bAdaptiveDegradation) = 0;
  virtual bool adaptiveDegradation(void) = 0;

  virtual int degradationChainPosition(DegradationChannel channel) = 0;

  virtual DegradationChannel degradationChannelAt(int position) = 0;

  virtual void shiftDegradationChainPosition(DegradationChannel channel, bool bShiftDown) = 0;
  virtual bool canDegradeChannel(DegradationChannel channel) = 0;

  virtual void setCanDegradeChannel(DegradationChannel channel,bool bDegrade) = 0;

  // performance
  virtual void setUseDisplayLists(bool bUseDisplayLists) = 0;

  virtual bool useDisplayLists(void) = 0;

  virtual void setRedrawOnWindowExpose(bool bRedrawWindowExpose) = 0;

  virtual bool redrawOnWindowExpose(void) = 0;

  // display options
  virtual Handedness handedness(void) const = 0;

  virtual void setHandedness(Handedness) = 0;

  virtual bool discardBackFaces(void) = 0;
  virtual void setDiscardBackFaces(bool bDiscardBackFaces) = 0;

  virtual Quality transparency(void) = 0;

  virtual void setTransparency(Quality quality) = 0;

  // hardware features
  virtual bool isFeatureEnabled(HardwareFeature feature) = 0;

  virtual void setFeatureEnabled(HardwareFeature feature, bool bEnable = true) = 0;
  virtual bool isFeatureAvailable(HardwareFeature feature) = 0;

  virtual bool isFeatureRecommended(HardwareFeature feature) = 0;
};

class OdGsConfig2 : public OdGsConfig
{
public:
  virtual bool generateVertexNormals(void) const = 0;
  virtual void setGenerateVertexNormals(bool bEnable) = 0;
};

struct OdGsDrawableLink
{
  LONG_PTR id;
  OdGiDrawable *pDrawable;
  OdGsNode *pNode;
};

typedef OdArray<OdGsDrawableLink> OdGsDrawablePath;

typedef OdGsClassFactory *    (*OdGsCreateClassFactoryFunc)(void);
typedef void(*OdGsDeleteClassFactoryFunc)(OdGsClassFactory *);




