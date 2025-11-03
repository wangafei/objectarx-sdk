/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcGiEnvironment.h"

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP 
#endif

class GcDbImpRenderSettings;
class GcDbImpRenderEnvironment;
class GcDbImpRapidRTRenderEnvironment;
class GcDbImpRenderGlobal;
class GcDbImpMentalRayRenderSettings;

class GCDB_PORT GcDbRenderSettings : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbRenderSettings);
  GcDbRenderSettings();
  GcDbRenderSettings(GcDbImpRenderSettings*);
  ~GcDbRenderSettings();

  GcGiDrawable* drawable() override;

  Gcad::ErrorStatus setName(const GcString& strName);
  GcString name() const;

  void setDescription(const GcString& strDes);
  GcString description() const;

  void setDisplayIndex(int idx);
  int displayIndex() const;

  void setMaterialsEnabled(bool bEnabled);
  bool materialsEnabled() const;

  void setTextureSampling(bool bSampling);
  bool textureSampling() const;

  void setBackFacesEnabled(bool bEnabled);
  bool backFacesEnabled() const;

  void setShadowsEnabled(bool bEnabled);
  bool shadowsEnabled() const;

  Gcad::ErrorStatus setPreviewImageFileName(const GcString& strFileName);
  GcString previewImageFileName() const;

  void setDiagnosticBackgroundEnabled(bool bEnabled);
  bool diagnosticBackgroundEnabled() const;

  Gcad::ErrorStatus setIsPredefined(bool bPredefined);
  bool isPredefined() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;
  virtual bool operator==(const GcDbRenderSettings& settings);

protected:
  Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;
  GcDbImpRenderSettings* mpImp;
};

class GCDB_PORT GcDbMentalRayRenderSettings : public GcDbRenderSettings
{
public:
  GCRX_DECLARE_MEMBERS(GcDbMentalRayRenderSettings);
  GcDbMentalRayRenderSettings();
  ~GcDbMentalRayRenderSettings();

  Gcad::ErrorStatus setSampling(int iMin, int iMax);
  void sampling(int& iMin, int& iMax) const;

  Gcad::ErrorStatus setSamplingFilter(GcGiMrFilter eFilter, double fWidth, double fHeight);
  void SamplingFilter(GcGiMrFilter& eFilter, double& fWidth, double& fHeight) const;

  Gcad::ErrorStatus setSamplingContrastColor(float r, float g, float b, float a);
  void samplingContrastColor(float& r, float& g, float& b, float& a) const;

  void setShadowMode(GcGiMrShadowMode eShadowMode);
  GcGiMrShadowMode shadowMode() const;

  void setShadowMapsEnabled(bool bEnabled);
  bool shadowMapsEnabled() const;

  void setRayTracingEnabled(bool bEnabled);
  bool rayTracingEnabled() const;

  Gcad::ErrorStatus setRayTraceDepth(int iReflection, int iRefraction, int iSum);
  void rayTraceDepth(int& iReflection, int& iRefraction, int& iSum) const;

  void setGlobalIlluminationEnabled(bool bEnabled);
  bool globalIlluminationEnabled() const;

  Gcad::ErrorStatus setGISampleCount(int iNum);
  int giSampleCount() const;

  void setGISampleRadiusEnabled(bool bEnabled);
  bool giSampleRadiusEnabled() const;

  Gcad::ErrorStatus setGISampleRadius(double fRadius);
  double giSampleRadius() const;

  Gcad::ErrorStatus setGIPhotonsPerLight(int iNum);
  int giPhotonsPerLight() const;

  Gcad::ErrorStatus setPhotonTraceDepth(int iReflection, int iRefraction, int iSum);
  void photonTraceDepth(int& iReflection, int& iRefraction, int& iSum) const;

  void setFinalGatheringEnabled(bool bEnabled);
  bool finalGatheringEnabled() const;

  Gcad::ErrorStatus setFinalGatheringMode(GcGiMrFinalGatheringMode mode);
  GcGiMrFinalGatheringMode finalGatheringMode() const;

  Gcad::ErrorStatus setFGRayCount(int iNum);
  int fgRayCount() const;

  void setFGRadiusState(bool bMin, bool bMax, bool bPixels);
  void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels) const;

  Gcad::ErrorStatus setFGSampleRadius(double fMin, double fMax);
  void fgSampleRadius(double& fMin, double& fMax) const;

  Gcad::ErrorStatus setLightLuminanceScale(double fLuminance);
  double lightLuminanceScale() const;

  Gcad::ErrorStatus setEnergyMultiplier(float fScale);
  float energyMultiplier() const;

  void setDiagnosticMode(GcGiMrDiagnosticMode eDiagnosticMode);
  GcGiMrDiagnosticMode diagnosticMode() const;

  Gcad::ErrorStatus setDiagnosticGridMode(GcGiMrDiagnosticGridMode eDiagnosticGridMode, float fSize);
  void diagnosticGridMode(GcGiMrDiagnosticGridMode& eDiagnosticGridMode, float& fSize) const;

  void setDiagnosticPhotonMode(GcGiMrDiagnosticPhotonMode eDiagnosticPhotonMode);
  GcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const;

  void setDiagnosticSamplesMode(bool bDiagnosticSamplesMode);
  bool diagnosticSamplesMode() const;

  void setDiagnosticBSPMode(GcGiMrDiagnosticBSPMode eDiagnosticBSPMode);
  GcGiMrDiagnosticBSPMode diagnosticBSPMode() const;

  void setExportMIEnabled(bool bEnabled);
  bool exportMIEnabled() const;

  Gcad::ErrorStatus setExportMIMode(GcGiMrExportMIMode eExportMIMode);
  GcGiMrExportMIMode exportMIMode() const;

  Gcad::ErrorStatus setExportMIFileName(const GcString& strFileName);
  GcString exportMIFileName() const;

  Gcad::ErrorStatus setTileSize(int iTileSize);
  int tileSize() const;

  void setTileOrder(GcGiMrTileOrder eTileOrder);
  GcGiMrTileOrder tileOrder() const;

  Gcad::ErrorStatus setMemoryLimit(int iMemoryLimit);
  int memoryLimit() const;

  enum ShadowSamplingMultiplier {
    kSamplingMultiplierZero = 0,
    kSamplingMultiplierOneEighth,
    kSamplingMultiplierOneFourth,
    kSamplingMultiplierOneHalf,
    kSamplingMultiplierOne,
    kSamplingMultiplierTwo
  };

  Gcad::ErrorStatus setShadowSamplingMultiplier(GcDbMentalRayRenderSettings::ShadowSamplingMultiplier multiplier);
  GcDbMentalRayRenderSettings::ShadowSamplingMultiplier shadowSamplingMultiplier() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  virtual bool operator==(const GcDbMentalRayRenderSettings& settings);
  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

protected:
  Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpMentalRayRenderSettings;
  Gsoft::UInt32 baseSetAttributes(GcGiDrawableTraits* pTraits);
  GcDbImpMentalRayRenderSettings* mpImpMentalRay;
};

class GCDB_PORT GcDbRapidRTRenderSettings : public GcDbRenderSettings
{
public:
  GCRX_DECLARE_MEMBERS(GcDbRapidRTRenderSettings);

  enum RenderTarget
  {
    krLevel = 0,
    krTime = 1,
    krInfinite = 2
  };

  GcDbRapidRTRenderSettings();
  ~GcDbRapidRTRenderSettings();

  Gcad::ErrorStatus setRenderTarget(RenderTarget target);
  RenderTarget renderTarget() const;

  Gcad::ErrorStatus setRenderLevel(int level);
  int renderLevel() const;

  Gcad::ErrorStatus setRenderTime(int time);
  int renderTime() const;

  Gcad::ErrorStatus setLightingModel(GcGiLightingMode model);
  GcGiLightingMode lightingModel() const;

  Gcad::ErrorStatus setFilterType(GcGiFilterType type);
  GcGiFilterType filterType() const;

  Gcad::ErrorStatus setFilterWidth(float width);
  float filterWidth() const;

  Gcad::ErrorStatus setFilterHeight(float height);
  float filterHeight() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  virtual bool operator==(const GcDbRapidRTRenderSettings& settings);
  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;
  Gcad::ErrorStatus decomposeForSave(GcDb::GcDbDwgVersion ver, GcDbObject*& replaceObj,
    GcDbObjectId& replaceId, Gsoft::Boolean& exchangeXData) override;

protected:
  Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;
};

class GCDB_PORT GcDbRenderEnvironment : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbRenderEnvironment);
  GcDbRenderEnvironment();
  ~GcDbRenderEnvironment();

  GcGiDrawable* drawable() override;

  void setFogEnabled(bool bEnable);
  bool fogEnabled() const;

  void setFogBackgroundEnabled(bool bEnable);
  bool fogBackgroundEnabled() const;

  void setFogColor(const GcCmEntityColor& color);
  GcCmEntityColor fogColor() const;

  Gcad::ErrorStatus setFogDensity(double dNear, double dFar);
  void fogDensity(double& dNear, double& dFar) const;

  Gcad::ErrorStatus setDistances(double dNear, double dFar);
  void distances(double& dNear, double& dFar) const;

  void setEnvironmentImageEnabled(bool bEnabled);
  bool environmentImageEnabled() const;

  Gcad::ErrorStatus setEnvironmentImageFileName(const GcString& strFileName);
  GcString environmentImageFileName() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  virtual bool operator==(const GcDbRenderEnvironment& environment);

protected:
  Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;
  GcDbImpRenderEnvironment* mpImp;
};

class GCDB_PORT GcDbRenderGlobal : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbRenderGlobal);

  enum Procedure
  {
    krView = 0,
    krCrop,
    krSelected
  };

  enum Destination
  {
    krWindow = 0,
    krViewport
  };

  GcDbRenderGlobal();
  ~GcDbRenderGlobal();

  void setProcedureAndDestination(Procedure eProcedure, Destination eDestination);
  void procedureAndDestination(Procedure& eProcedure, Destination& eDestination) const;

  Gcad::ErrorStatus setProcedure(Procedure eProcedure);
  Procedure procedure();

  Gcad::ErrorStatus setDestination(Destination eDestination);
  Destination destination();

  void setSaveEnabled(bool bEnabled);
  bool saveEnabled() const;

  Gcad::ErrorStatus setSaveFileName(const GcString& strFileName);
  GcString saveFileName() const;

  Gcad::ErrorStatus setDimensions(int w, int h);
  void dimensions(int& w, int& h) const;

  void setPredefinedPresetsFirst(bool bPredefinedPresetsFirst);
  bool predefinedPresetsFirst() const;

  void setHighInfoLevel(bool bHighInfoLevel);
  bool highInfoLevel() const;

  Gcad::ErrorStatus setExposureType(GcGiMrExposureType type);
  GcGiMrExposureType exposureType() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

private:
  GcDbImpRenderGlobal* mpImp;

public:
  bool operator==(const GcDbRenderGlobal& global);
  GcString dimensionName() const;
};