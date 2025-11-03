/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcgi.h"
#include "GcGiLightTraits.h"
#pragma pack (push, 8)

#if defined(__linux__)
#ifdef GCGIENVIRONMENT_IMPL
#define GCGIENV_IMPEXP   __attribute__ ((__visibility__("default")))
#else
#define GCGIENV_IMPEXP
#endif
#else
#ifdef GCGIENVIRONMENT_IMPL
#define GCGIENV_IMPEXP __declspec(dllexport)
#else
#define GCGIENV_IMPEXP __declspec(dllimport)
#endif
#endif

class GCBASE_PORT GcGiSolidBackgroundTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiSolidBackgroundTraits);

  virtual void            setColorSolid(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorSolid(void) const = 0;
};

class GCBASE_PORT GcGiGradientBackgroundTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGradientBackgroundTraits);

  virtual void            setColorTop(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorTop(void) const = 0;
  virtual void            setColorMiddle(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorMiddle(void) const = 0;
  virtual void            setColorBottom(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorBottom(void) const = 0;
  virtual void            setHorizon(double horizon) = 0;
  virtual double          horizon(void) const = 0;
  virtual void            setHeight(double height) = 0;
  virtual double          height(void) const = 0;
  virtual void            setRotation(double rotation) = 0;
  virtual double          rotation(void) const = 0;
};

class GCBASE_PORT GcGiImageBackgroundTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiImageBackgroundTraits);

  virtual void            setImageFilename(const GCHAR* filename) = 0;
  virtual const GCHAR *   imageFilename(void) const = 0;
  virtual void            setFitToScreen(bool bFitToScreen) = 0;
  virtual bool            fitToScreen(void) const = 0;
  virtual void            setMaintainAspectRatio(bool bMaintainAspectRatio) = 0;
  virtual bool            maintainAspectRatio(void) const = 0;
  virtual void            setUseTiling(bool bUseTiling) = 0;
  virtual bool            useTiling(void) const = 0;
  virtual void            setXOffset(double xOffset) = 0;
  virtual double          xOffset(void) const = 0;
  virtual void            setYOffset(double yOffset) = 0;
  virtual double          yOffset(void) const = 0;
  virtual void            setXScale(double xScale) = 0;
  virtual double          xScale(void) const = 0;
  virtual void            setYScale(double yScale) = 0;
  virtual double          yScale(void) const = 0;
};

class GCBASE_PORT GcGiGroundPlaneBackgroundTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGroundPlaneBackgroundTraits);

  virtual void            setColorSkyZenith(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorSkyZenith(void) const = 0;
  virtual void            setColorSkyHorizon(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorSkyHorizon(void) const = 0;
  virtual void            setColorUndergroundHorizon(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorUndergroundHorizon(void) const = 0;
  virtual void            setColorUndergroundAzimuth(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorUndergroundAzimuth(void) const = 0;
  virtual void            setColorGroundPlaneNear(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorGroundPlaneNear(void) const = 0;
  virtual void            setColorGroundPlaneFar(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor colorGroundPlaneFar(void) const = 0;
};

class GCBASE_PORT GcGiSkyBackgroundTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiSkyBackgroundTraits);

  virtual void setSkyParameters(const GcGiSkyParameters& params) = 0;
  virtual void skyParameters(GcGiSkyParameters& params) const = 0;
};

class GCBASE_PORT GcGiIBLBackgroundTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiIBLBackgroundTraits);

  virtual void            setEnable(const bool bEnable) = 0;
  virtual bool            enable(void) const = 0;
  virtual void            setIBLImageName(const GcString& name) = 0;
  virtual GcString        IBLImageName(void) const = 0;
  virtual void            setRotation(const double rotation) = 0;
  virtual double          rotation(void) const = 0;
  virtual void            setDisplayImage(const bool bdisplay) = 0;
  virtual bool            displayImage(void) const = 0;
  virtual void            setSecondaryBackground(const GcDbObjectId bg) = 0;
  virtual GcDbObjectId    secondaryBackground(void) const = 0;
};

class GcGiMaterialTexture;

class GCBASE_PORT GcGiRenderEnvironmentTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiRenderEnvironmentTraits);

  virtual void            setEnable(const bool bEnable) = 0;
  virtual bool            enable(void) const = 0;
  virtual void            setIsBackground(const bool bEnable) = 0;
  virtual bool            isBackground(void) const = 0;
  virtual void            setFogColor(const GcCmEntityColor & color) = 0;
  virtual GcCmEntityColor fogColor(void) const = 0;
  virtual void            setNearDistance(const double nearDist) = 0;
  virtual double          nearDistance(void) const = 0;
  virtual void            setFarDistance(const double farDist) = 0;
  virtual double          farDistance(void) const = 0;
  virtual void            setNearPercentage(const double nearPct) = 0;
  virtual double          nearPercentage(void) const = 0;
  virtual void            setFarPercentage(const double farPct) = 0;
  virtual double          farPercentage(void) const = 0;
  virtual void            setEnvironmentMap(const GcGiMaterialTexture * map) = 0;
  virtual GcGiMaterialTexture * environmentMap(void) const = 0;
};

class GCBASE_PORT GcGiRenderSettingsTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiRenderSettingsTraits);

  virtual void setMaterialEnabled(bool enabled) = 0;
  virtual bool materialEnabled() const = 0;

  virtual void setTextureSampling(bool enabled) = 0;
  virtual bool textureSampling() const = 0;

  virtual void setBackFacesEnabled(bool enabled) = 0;
  virtual bool backFacesEnabled() const = 0;

  virtual void setShadowsEnabled(bool enabled) = 0;
  virtual bool shadowsEnabled() const = 0;

  virtual void setDiagnosticBackgroundEnabled(bool enabled) = 0;
  virtual bool diagnosticBackgroundEnabled() const = 0;

  virtual void            setModelScaleFactor(double scaleFactor) = 0;
  virtual double          modelScaleFactor(void) const = 0;
};

typedef enum {
  krBox = 0,
  krTriangle,
  krGauss,
  krMitchell,
  krLanczos
} GcGiMrFilter;

typedef enum {
  krSimple = 0,
  krSorted,
  krSegments
} GcGiMrShadowMode;

typedef enum {
  krOff = 0,
  krGrid,
  krPhoton,
  krSamples,
  krBSP
} GcGiMrDiagnosticMode;

typedef enum {
  krObject = 0,
  krWorld,
  krCamera
} GcGiMrDiagnosticGridMode;

typedef enum {
  krDensity = 0,
  krIrradiance
} GcGiMrDiagnosticPhotonMode;

typedef enum {
  krDepth = 0,
  krSize
} GcGiMrDiagnosticBSPMode;

typedef enum {
  krHilbert = 0,
  krSpiral,
  krLeftToRight,
  krRightToLeft,
  krTopToBottom,
  krBottomToTop
} GcGiMrTileOrder;

typedef enum {
  krAutomatic = 0,
  krLogarithmic
} GcGiMrExposureType;

typedef enum {
  krFinalGatherOff = 0,
  krFinalGatherOn,
  krFinalGatherAuto
} GcGiMrFinalGatheringMode;

typedef enum {
  krExportMIOff = 0,
  krExportMIWithRender,
  krExportMIOnly
} GcGiMrExportMIMode;

class GCBASE_PORT GcGiMentalRayRenderSettingsTraits : public GcGiRenderSettingsTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiMentalRayRenderSettingsTraits);

  virtual void setSampling(int min, int max) = 0;
  virtual void sampling(int& min, int& max) const = 0;

  virtual void setSamplingFilter(GcGiMrFilter filter, double width, double height) = 0;
  virtual void SamplingFilter(GcGiMrFilter& filter, double& width, double& height) const = 0;

  virtual void setSamplingContrastColor(float r, float g, float b, float a) = 0;
  virtual void samplingContrastColor(float& r, float& g, float& b, float& a) const = 0;

  virtual void setShadowMode(GcGiMrShadowMode mode) = 0;
  virtual GcGiMrShadowMode shadowMode() const = 0;

  virtual void setShadowMapEnabled(bool enabled) = 0;
  virtual bool shadowMapEnabled() const = 0;

  virtual void setRayTraceEnabled(bool enabled) = 0;
  virtual bool rayTraceEnabled() const = 0;

  virtual void setRayTraceDepth(int reflection, int refraction, int sum) = 0;
  virtual void rayTraceDepth(int& reflection, int& refraction, int& sum) const = 0;

  virtual void setGlobalIlluminationEnabled(bool enabled) = 0;
  virtual bool globalIlluminationEnabled() const = 0;

  virtual void setGISampleCount(int num) = 0;
  virtual int giSampleCount() const = 0;

  virtual void setGISampleRadiusEnabled(bool enabled) = 0;
  virtual bool giSampleRadiusEnabled() const = 0;

  virtual void setGISampleRadius(double radius) = 0;
  virtual double giSampleRadius() const = 0;

  virtual void setGIPhotonsPerLight(int num) = 0;
  virtual int giPhotonsPerLight() const = 0;

  virtual void setPhotonTraceDepth(int reflection, int refraction, int sum) = 0;
  virtual void photonTraceDepth(int& reflection, int& refraction, int& sum) const = 0;

  virtual void setFinalGatheringEnabled(bool enabled) = 0;
  virtual bool finalGatheringEnabled() const = 0;

  virtual void setFGRayCount(int num) = 0;
  virtual int fgRayCount() const = 0;

  virtual void setFGRadiusState(bool bMin, bool bMax, bool bPixels) = 0;
  virtual void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels) = 0;

  virtual void setFGSampleRadius(double min, double max) = 0;
  virtual void fgSampleRadius(double& min, double& max) const = 0;

  virtual void setLightLuminanceScale(double luminance) = 0;
  virtual double lightLuminanceScale() const = 0;

  virtual void setDiagnosticMode(GcGiMrDiagnosticMode mode) = 0;
  virtual GcGiMrDiagnosticMode diagnosticMode() const = 0;

  virtual void setDiagnosticGridMode(GcGiMrDiagnosticGridMode mode, float fSize) = 0;
  virtual void diagnosticGridMode(GcGiMrDiagnosticGridMode& mode, float& fSize) const = 0;

  virtual void setDiagnosticPhotonMode(GcGiMrDiagnosticPhotonMode mode) = 0;
  virtual GcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const = 0;

  virtual void setDiagnosticBSPMode(GcGiMrDiagnosticBSPMode mode) = 0;
  virtual GcGiMrDiagnosticBSPMode diagnosticBSPMode() const = 0;

  virtual void setExportMIEnabled(bool enabled) = 0;
  virtual bool exportMIEnabled() const = 0;

  virtual void setExportMIFileName(const GCHAR* miName) = 0;
  virtual const GCHAR* exportMIFileName() const = 0;

  virtual void setTileSize(int size) = 0;
  virtual int tileSize() const = 0;

  virtual void setTileOrder(GcGiMrTileOrder order) = 0;
  virtual GcGiMrTileOrder tileOrder() const = 0;

  virtual void setMemoryLimit(int limit) = 0;
  virtual int memoryLimit() const = 0;

  virtual void setEnergyMultiplier(float fScale) = 0;
  virtual float energyMultiplier() const = 0;

  virtual void setProgressMonitor(void* pMonitor) = 0;
  virtual const void* progressMonitor(void) const = 0;

  virtual void setExposureType(GcGiMrExposureType type) = 0;
  virtual GcGiMrExposureType exposureType() const = 0;

  virtual void setFinalGatheringMode(GcGiMrFinalGatheringMode mode) = 0;
  virtual GcGiMrFinalGatheringMode finalGatheringMode() const = 0;

  virtual void setShadowSamplingMultiplier(double multiplier) = 0;
  virtual double shadowSamplingMultiplier() const = 0;

  virtual void setExportMIMode(GcGiMrExportMIMode mode) = 0;
  virtual GcGiMrExportMIMode exportMIMode() const = 0;
};

typedef enum
{
  krEQuitByRenderLevel = 0,
  krEQuitByRenderTime
}GcGiQuitCondition;

typedef enum
{
  krESimplistic = 0,
  krEBasic,
  krEAdvanced
}GcGiLightingMode;

typedef enum
{
  krEBox = 0,
  krETriangle,
  krEGaussian,
  krELanczos,
  krEMitchell
}GcGiFilterType;

class GCBASE_PORT GcGiRapidRTRenderSettingsTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiRapidRTRenderSettingsTraits);

  virtual void setQuitCondition(GcGiQuitCondition quitCondition) = 0;
  virtual GcGiQuitCondition quitCondition() const = 0;

  virtual void setDesiredRenderTime(int renderTime) = 0;
  virtual int desiredRenderTime() const = 0;

  virtual void setDesiredRenderLevel(int renderLevel) = 0;
  virtual int desiredRenderLevel() const = 0;

  virtual void setLightingMode(GcGiLightingMode mode) = 0;
  virtual GcGiLightingMode lightingMode() const = 0;

  virtual void setFilterType(GcGiFilterType filterInfo) = 0;
  virtual GcGiFilterType filterType() const = 0;

  virtual void setFilterWidth(float width) = 0;
  virtual float filterWidth() const = 0;

  virtual void setFilterHeight(float height) = 0;
  virtual float filterHeight() const = 0;
};

class GCBASE_PORT GcGiToneOperatorParameters : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiToneOperatorParameters);

  GcGiToneOperatorParameters();
  ~GcGiToneOperatorParameters();

  GcGiToneOperatorParameters& operator=(const GcGiToneOperatorParameters& params);
  bool operator==(const GcGiToneOperatorParameters& params) const;

  virtual void setIsActive(bool active);
  virtual bool isActive() const;

  virtual void setChromaticAdaptation(bool enable);
  virtual bool chromaticAdaptation() const;

  virtual void setColorDifferentiation(bool enable);
  virtual bool colorDifferentiation() const;

  virtual void setWhiteColor(const GcCmColor& color);
  virtual GcCmColor whiteColor() const;

  virtual void setProcessBackground(bool processBG);
  virtual bool processBackground() const;

  virtual bool setBrightness(double brightness);
  virtual double brightness() const;

  virtual bool setContrast(double contrast);
  virtual double contrast() const;

  virtual bool setMidTones(double midTones);
  virtual double midTones() const;

  enum ExteriorDaylightMode {
    kDaylightOff = 0,
    kDaylightOn,
    kDaylightAuto
  };

  virtual bool setExteriorDaylight(ExteriorDaylightMode mode);
  virtual ExteriorDaylightMode exteriorDaylight() const;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

private:
  bool                    mbIsActive;
  bool                    mbChromaticAdaptation;
  bool                    mbColorDifferentiation;
  GcCmColor               mWhiteColor;
  bool                    mbProcessBackground;
  double                  mBrightness;
  double                  mContrast;
  double                  mMidTones;
  ExteriorDaylightMode    mExteriorDaylight;
};

class GCBASE_PORT GcGiPhotographicExposureParameters : public GcGiToneOperatorParameters
{
public:
  GCRX_DECLARE_MEMBERS(GcGiPhotographicExposureParameters);

  GcGiPhotographicExposureParameters();
  ~GcGiPhotographicExposureParameters();

  GcGiPhotographicExposureParameters& operator=(const GcGiPhotographicExposureParameters& params);
  bool operator==(const GcGiPhotographicExposureParameters& params) const;

  bool setExposure(double exposure);
  double exposure(void) const;

  bool setWhitePoint(double whitePoint);
  double whitePoint(void) const;

  bool setBrightness(double) override;
  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

public:
  static double convertExposureToBrightness(double exp);
  static double convertBrightnessToExposure(double brt);

private:
  double                    mExposure;
  double                    mWhitePoint;
};

#pragma pack (pop)