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


#ifndef __OD_GI_ENVIRONMENT_TRAITS_DATA__
#define __OD_GI_ENVIRONMENT_TRAITS_DATA__

#include "TD_PackPush.h"

#include "Gi/GiEnvironment.h"
#include "Gi/GiLightTraits.h" // Define OdGiSkyParameters

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiBackgroundTraitsData
{

protected:
  OdGiDrawable::DrawableType m_type;

protected:
  OdGiBackgroundTraitsData()
  {
  }

public:

  OdGiDrawable::DrawableType type() const { return m_type; }

  static void deleteBackgroundTraitsData(OdGiBackgroundTraitsData* pBackgroundTraits);

  bool operator ==(const OdGiBackgroundTraitsData &data2) const
  {
    return m_type == data2.m_type;
  }
  bool operator !=(const OdGiBackgroundTraitsData &data2) const
  {
    return m_type != data2.m_type;
  }
};                          

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiSolidBackgroundTraitsData : public OdGiBackgroundTraitsData
{
  OdCmEntityColor      m_color;

public:
  OdGiSolidBackgroundTraitsData() { m_type = OdGiDrawable::kSolidBackground; }

  OdCmEntityColor color() const { return m_color; }
  void setColor(const OdCmEntityColor& color) { m_color = color; }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiGradientBackgroundTraitsData : public OdGiBackgroundTraitsData
{
  OdCmEntityColor      m_colorTop;
  OdCmEntityColor      m_colorMiddle;
  OdCmEntityColor      m_colorBottom;
  double               m_dHorizon;
  double               m_dHeight;
  double               m_dRotation;

public:
  OdGiGradientBackgroundTraitsData() : m_dHorizon(0.0), m_dHeight(0.0), m_dRotation(0.0) { m_type = OdGiDrawable::kGradientBackground; }

  OdCmEntityColor colorTop() const { return m_colorTop; }
  void setColorTop(const OdCmEntityColor& color) { m_colorTop = color; }
  OdCmEntityColor colorMiddle() const { return m_colorMiddle; }
  void setColorMiddle(const OdCmEntityColor& color) { m_colorMiddle = color; }
  OdCmEntityColor colorBottom() const { return m_colorBottom; }
  void setColorBottom(const OdCmEntityColor& color) { m_colorBottom = color; }
  
  double horizon() const { return m_dHorizon; }
  double height() const { return m_dHeight; }
  double rotation() const { return m_dRotation; }

  void setHorizon(double value) { m_dHorizon = value; }
  void setHeight(double value) { m_dHeight = value; }
  void setRotation(double value) { m_dRotation = value; }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiImageBackgroundTraitsData : public OdGiBackgroundTraitsData
{
  OdString             m_imageFileName;
  bool                 m_bFitToScreen;
  bool                 m_bMaintainAspect;
  bool                 m_bUseTiling;
  OdGeVector2d         m_vOffset;
  OdGeVector2d         m_vScale;

public:
  OdGiImageBackgroundTraitsData() : m_bFitToScreen(false), m_bMaintainAspect(false), m_bUseTiling(false) { m_type = OdGiDrawable::kImageBackground; }

  const OdString& imageFilename() const { return m_imageFileName; }
  void setImageFilename(const OdString& filename) { m_imageFileName = filename; }

  bool fitToScreen() const { return m_bFitToScreen; }
  bool maintainAspectRatio() const { return m_bMaintainAspect; }
  bool useTiling() const { return m_bUseTiling; }

  void setFitToScreen(bool flag) { m_bFitToScreen = flag; }
  void setMaintainAspectRatio(bool flag) { m_bMaintainAspect = flag; }
  void setUseTiling(bool flag) { m_bUseTiling = flag; }

  void setOffset(double x, double y);

  double xOffset() const { return m_vOffset.x; }
  double yOffset() const { return m_vOffset.y; }

  void setXOffset(double xOffset) { m_vOffset.x = xOffset; }
  void setYOffset(double yOffset) { m_vOffset.y = yOffset; }

  void setScale(double x, double y);

  double xScale() const { return m_vScale.x; }
  double yScale() const { return m_vScale.y; }

  void setXScale(double xScale) { m_vScale.x = xScale; }
  void setYScale(double yScale) { m_vScale.y = yScale; }
};

inline void OdGiImageBackgroundTraitsData::setOffset(double x, double y)
{ 
  m_vOffset.set(x, y);
}

inline void OdGiImageBackgroundTraitsData::setScale(double x, double y)
{ 
  m_vScale.set(x, y);
}

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiGroundPlaneBackgroundTraitsData : public OdGiBackgroundTraitsData
{
  OdCmEntityColor      m_colorSkyZenith;
  OdCmEntityColor      m_colorSkyHorizon;
  OdCmEntityColor      m_colorUndergroundHorizon;
  OdCmEntityColor      m_colorUndergroundAzimuth;
  OdCmEntityColor      m_colorGroundPlaneNear;
  OdCmEntityColor      m_colorGroundPlaneFar;

public:
  OdGiGroundPlaneBackgroundTraitsData() { m_type = OdGiDrawable::kGroundPlaneBackground; }

  OdCmEntityColor colorSkyZenith() const { return m_colorSkyZenith; }
  void setColorSkyZenith(const OdCmEntityColor& color) { m_colorSkyZenith = color; }
  OdCmEntityColor colorSkyHorizon() const { return m_colorSkyHorizon; }
  void setColorSkyHorizon(const OdCmEntityColor& color) { m_colorSkyHorizon = color; }
  OdCmEntityColor colorUndergroundHorizon() const { return m_colorUndergroundHorizon; }
  void setColorUndergroundHorizon(const OdCmEntityColor& color) { m_colorUndergroundHorizon = color; }
  OdCmEntityColor colorUndergroundAzimuth() const { return m_colorUndergroundAzimuth; }
  void setColorUndergroundAzimuth(const OdCmEntityColor& color) { m_colorUndergroundAzimuth = color; }
  OdCmEntityColor colorGroundPlaneNear() const { return m_colorGroundPlaneNear; }
  void setColorGroundPlaneNear(const OdCmEntityColor& color) { m_colorGroundPlaneNear = color; }
  OdCmEntityColor colorGroundPlaneFar() const { return m_colorGroundPlaneFar; }
  void setColorGroundPlaneFar(const OdCmEntityColor& color) { m_colorGroundPlaneFar = color; }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiSkyBackgroundTraitsData : public OdGiBackgroundTraitsData
{
  bool            m_status;
  double          m_intensityFactor;
  double          m_haze;
  double          m_horizonHeight;
  double          m_horizonBlur;
  OdCmEntityColor m_groundColor;
  OdCmEntityColor m_nightColor;
  bool            m_aerialPerspective;
  double          m_visibilityDistance;
  double          m_diskScale;
  double          m_glowIntensity;
  double          m_diskIntensity;
  OdUInt16        m_solarDiskSamples;
  OdGeVector3d    m_sunDirection;
  double          m_redBlueShift;
  double          m_saturation;
public:
  OdGiSkyBackgroundTraitsData() { m_type = OdGiDrawable::kSkyBackground; }

  void skyParameters(OdGiSkyParameters& params) const;
  void setSkyParameters(const OdGiSkyParameters& params);
};

inline void OdGiSkyBackgroundTraitsData::skyParameters(OdGiSkyParameters& params) const
{
  params.setIllumination(m_status);
  params.setIntensityFactor(m_intensityFactor);
  params.setHaze(m_haze);
  params.setHorizonHeight(m_horizonHeight);
  params.setHorizonBlur(m_horizonBlur);
  params.setGroundColor(m_groundColor);
  params.setNightColor(m_nightColor);
  params.setAerialPerspective(m_aerialPerspective);
  params.setVisibilityDistance(m_visibilityDistance);
  params.setDiskScale(m_diskScale);
  params.setGlowIntensity(m_glowIntensity);
  params.setDiskIntensity(m_diskIntensity);
  params.setSolarDiskSamples(m_solarDiskSamples);
  params.setSunDirection(m_sunDirection);
  params.setRedBlueShift(m_redBlueShift);
  params.setSaturation(m_saturation);
}

inline void OdGiSkyBackgroundTraitsData::setSkyParameters(const OdGiSkyParameters& params)
{
  m_status = params.illumination();
  m_intensityFactor = params.intensityFactor();
  m_haze = params.haze();
  m_horizonHeight = params.horizonHeight();
  m_horizonBlur = params.horizonBlur();
  m_groundColor = params.groundColor();
  m_nightColor = params.nightColor();
  m_aerialPerspective = params.aerialPerspective();
  m_visibilityDistance = params.visibilityDistance();
  m_diskScale = params.diskScale();
  m_glowIntensity = params.glowIntensity();
  m_diskIntensity = params.diskIntensity();
  m_solarDiskSamples = params.solarDiskSamples();
  m_sunDirection = params.sunDirection();
  m_redBlueShift = params.redBlueShift();
  m_saturation = params.saturation();
}

//

/** \details
    Corresponding C++ library: TD_Gi
    <group OdGi_Classes>
*/
class OdGiIBLBackgroundTraitsData : public OdGiBackgroundTraitsData
{
  bool      m_bEnable;
  OdString  m_iblFileName;
  double    m_rotation;
  bool      m_bDisplay;
  OdDbStub *m_secBkgndId;

public:
  OdGiIBLBackgroundTraitsData() { m_type = OdGiDrawable::kImageBasedLightingBackground; }

  bool isEnabled() const { return m_bEnable; }
  void enable(bool bSet) { m_bEnable = bSet; }

  const OdString &IBLFileName() const { return m_iblFileName; }
  void setIBLFileName(const OdString &iblFileName) { m_iblFileName = iblFileName; }

  double rotation() const { return m_rotation; }
  void setRotation(double angle) { m_rotation = angle; }

  bool displayImage() const { return m_bDisplay; }
  void setDisplayImage(bool bSet) { m_bDisplay = bSet; }

  OdDbStub *secondaryBackground() const { return m_secBkgndId; }
  void setSecondaryBackground(OdDbStub *secBkgndId) { m_secBkgndId = secBkgndId; }

  bool operator ==(const OdGiIBLBackgroundTraitsData &data2) const
  {
    return ((*static_cast<const OdGiBackgroundTraitsData*>(this) == static_cast<const OdGiBackgroundTraitsData&>(data2)) &&
           (m_bEnable == data2.m_bEnable) &&
           (m_iblFileName == data2.m_iblFileName) &&
           OdEqual(m_rotation, data2.m_rotation) &&
           (m_bDisplay == data2.m_bDisplay) &&
           (m_secBkgndId == data2.m_secBkgndId));
  }
  bool operator !=(const OdGiIBLBackgroundTraitsData &data2) const
  {
    return !(*this == data2);
  }
};

inline void OdGiBackgroundTraitsData::deleteBackgroundTraitsData(OdGiBackgroundTraitsData* pBackgroundTraits)
{
  switch(pBackgroundTraits->type())
  {
  case OdGiDrawable::kSolidBackground:
    delete static_cast<OdGiSolidBackgroundTraitsData*>(pBackgroundTraits);
    break;
  case OdGiDrawable::kGradientBackground:
    delete static_cast<OdGiGradientBackgroundTraitsData*>(pBackgroundTraits);
    break;
  case OdGiDrawable::kImageBackground:
    delete static_cast<OdGiImageBackgroundTraitsData*>(pBackgroundTraits);
    break;
  case OdGiDrawable::kGroundPlaneBackground:
    delete static_cast<OdGiGroundPlaneBackgroundTraitsData*>(pBackgroundTraits);
    break;
  case OdGiDrawable::kSkyBackground:
    delete static_cast<OdGiSkyBackgroundTraitsData*>(pBackgroundTraits);
    break;
  case OdGiDrawable::kImageBasedLightingBackground:
    delete static_cast<OdGiIBLBackgroundTraitsData*>(pBackgroundTraits);
    break;
  default:
    ODA_FAIL();
  }
}

//

/** Description:
    Library: Gi
    {group:OdGi_Classes}
*/
class OdGiRenderEnvironmentTraitsData
{
  bool                   m_bEnable;
  bool                   m_bIsBackground;
  OdCmEntityColor        m_FogColor;
  double                 m_dNearDist;
  double                 m_dFarDist;
  double                 m_dNearPerc;
  double                 m_dFarPerc;
  OdGiMaterialTexturePtr m_envMap;
public:
  OdGiRenderEnvironmentTraitsData()
    : m_bEnable(false)
    , m_bIsBackground(false)
    , m_FogColor(128, 128, 128)
    , m_dNearDist(0.0)
    , m_dFarDist(100.0)
    , m_dNearPerc(0.0)
    , m_dFarPerc(100.0)
  {
  }

  void setEnable(bool bEnable) { m_bEnable = bEnable; }
  bool enable() const { return m_bEnable; }
  void setIsBackground(bool bEnable) { m_bIsBackground = bEnable; }
  bool isBackground() const { return m_bIsBackground; }
  void setFogColor(const OdCmEntityColor &color) { m_FogColor = color; }
  const OdCmEntityColor &fogColor() const { return m_FogColor; }
  void setNearDistance(double nearDist) { m_dNearDist = nearDist; }
  double nearDistance() const { return m_dNearDist; }
  void setFarDistance(double farDist) { m_dFarDist = farDist; }
  double farDistance() const { return m_dFarDist; }
  void setNearPercentage(double nearPct) { m_dNearPerc = nearPct; }
  double nearPercentage() const { return m_dNearPerc; }
  void setFarPercentage(double farPct) { m_dFarPerc = farPct; }
  double farPercentage() const { return m_dFarPerc; }
  void setEnvironmentMap(const OdGiMaterialTexture *map)
  {
    m_envMap.release();
    if (map)
    {
      m_envMap = OdGiMaterialTexture::ODSYSCALL1(cast,map->ODSYSCALL0(clone));
    }
  }
  OdGiMaterialTexturePtr environmentMap() const { return m_envMap; }
};

/** Description:
    Library: Gi
    {group:OdGi_Classes}
*/
class OdGiRenderSettingsTraitsData
{
  bool   m_bMatEnable;
  bool   m_bTextureSampling;
  bool   m_bBackFaces;
  bool   m_bShadows;
  bool   m_bDiagnosticBack;
  double m_dScaleFactor;
public:
  OdGiRenderSettingsTraitsData()
    : m_bMatEnable(true)
    , m_bTextureSampling(true)
    , m_bBackFaces(true)
    , m_bShadows(true)
    , m_bDiagnosticBack(false)
    , m_dScaleFactor(1.0)
  {
  }
  virtual ~OdGiRenderSettingsTraitsData() { } // Exclude warnings in some compilers

  void setMaterialEnabled(bool enabled) { m_bMatEnable = enabled; }
  bool materialEnabled() const { return m_bMatEnable; }
  void setTextureSampling(bool enabled) { m_bTextureSampling = enabled; }
  bool textureSampling() const { return m_bTextureSampling; }
  void setBackFacesEnabled(bool enabled) { m_bBackFaces = enabled; }
  bool backFacesEnabled() const { return m_bBackFaces; }
  void setShadowsEnabled(bool enabled) { m_bShadows = enabled; }
  bool shadowsEnabled() const { return m_bShadows; }
  void setDiagnosticBackgroundEnabled(bool enabled) { m_bDiagnosticBack = enabled; }
  bool diagnosticBackgroundEnabled() const { return m_bDiagnosticBack; }
  void setModelScaleFactor(double scaleFactor) { m_dScaleFactor = scaleFactor; }
  double modelScaleFactor() const { return m_dScaleFactor; }
};

/** Description:
    Library: Gi
    {group:OdGi_Classes}
*/
class OdGiMentalRayRenderSettingsTraitsData : public OdGiRenderSettingsTraitsData
{
  int                        m_iSamplingMin;
  int                        m_iSamplingMax;
  OdGiMrFilter               m_SamplingFilter;
  double                     m_dSamplingWidth;
  double                     m_dSamplingHeight;
  float                      m_fContrastR;
  float                      m_fContrastG;
  float                      m_fContrastB;
  float                      m_fContrastA;
  OdGiMrShadowMode           m_ShadowMode;
  bool                       m_bShadowMapEnabled;
  bool                       m_bRayTraceEnabled;
  int                        m_iRTReflection;
  int                        m_iRTRefraction;
  int                        m_iRTSum;
  bool                       m_bGlobalIllum;
  int                        m_iGISampleCount;
  bool                       m_bSampleRadEnabled;
  double                     m_dSampleRad;
  int                        m_iPhotonsPerLight;
  int                        m_iPhotonsReflection;
  int                        m_iPhotonsRefraction;
  int                        m_iPhotonsSum;
  bool                       m_bFGEnabled;
  int                        m_iFGRayCount;
  bool                       m_bFGRadMin;
  bool                       m_bFGRadMax;
  bool                       m_bFGPixels;
  double                     m_dFGSRadMin;
  double                     m_dFGSRadMax;
  double                     m_dLightLumScale;
  OdGiMrDiagnosticMode       m_DiagMode;
  OdGiMrDiagnosticGridMode   m_DiagGridMode;
  float                      m_fDiagGridSize;
  OdGiMrDiagnosticPhotonMode m_DiagPhtMode;
  OdGiMrDiagnosticBSPMode    m_DiagBSPMode;
  bool                       m_bExportMIEnabled;
  OdString                   m_sMIFile;
  int                        m_iTileSize;
  OdGiMrTileOrder            m_TileOrder;
  int                        m_iMemLimit;
  float                      m_fEnergyMult;
  void*                      m_pProgressMonitor;
public:
  OdGiMentalRayRenderSettingsTraitsData()
    : OdGiRenderSettingsTraitsData()
    , m_iSamplingMin(-1)
    , m_iSamplingMax(0)
    , m_SamplingFilter(krBox)
    , m_dSamplingWidth(1.0)
    , m_dSamplingHeight(1.0)
    , m_fContrastR(0.1f)
    , m_fContrastG(0.1f)
    , m_fContrastB(0.1f)
    , m_fContrastA(0.1f)
    , m_ShadowMode(krSimple)
    , m_bShadowMapEnabled(true)
    , m_bRayTraceEnabled(true)
    , m_iRTReflection(2)
    , m_iRTRefraction(2)
    , m_iRTSum(4)
    , m_bGlobalIllum(false)
    , m_iGISampleCount(500)
    , m_bSampleRadEnabled(false)
    , m_dSampleRad(1.0)
    , m_iPhotonsPerLight(10000)
    , m_iPhotonsReflection(5)
    , m_iPhotonsRefraction(5)
    , m_iPhotonsSum(5)
    , m_bFGEnabled(false)
    , m_iFGRayCount(1000)
    , m_bFGRadMin(false)
    , m_bFGRadMax(false)
    , m_bFGPixels(false)
    , m_dFGSRadMin(1.0)
    , m_dFGSRadMax(1.0)
    , m_dLightLumScale(1.0)
    , m_DiagMode(krOff)
    , m_DiagGridMode(krObject)
    , m_fDiagGridSize(10.0f)
    , m_DiagPhtMode(krDensity)
    , m_DiagBSPMode(krDepth)
    , m_bExportMIEnabled(false)
    , m_sMIFile()
    , m_iTileSize(32)
    , m_TileOrder(krHilbert)
    , m_iMemLimit(1048)
    , m_fEnergyMult(1.0f)
    , m_pProgressMonitor(NULL)
  {
  }

  void setSampling(int min, int max)
  {
    m_iSamplingMin = min;
    m_iSamplingMax = max;
  }
  void sampling(int& min, int& max) const
  {
    min = m_iSamplingMin;
    max = m_iSamplingMax;
  }
  void setSamplingFilter(OdGiMrFilter filter, double width, double height)
  {
    m_SamplingFilter = filter;
    m_dSamplingWidth = width;
    m_dSamplingHeight = height;
  }
  void samplingFilter(OdGiMrFilter& filter, double& width, double& height) const
  {
    filter = m_SamplingFilter;
    width = m_dSamplingWidth;
    height = m_dSamplingHeight;
  }
  void setSamplingContrastColor(float r, float g, float b, float a)
  {
    m_fContrastR = r;
    m_fContrastG = g;
    m_fContrastB = b;
    m_fContrastA = a;
  }
  void samplingContrastColor(float& r, float& g, float& b, float& a) const
  {
    r = m_fContrastR;
    g = m_fContrastG;
    b = m_fContrastB;
    a = m_fContrastA;
  }
  void setShadowMode(OdGiMrShadowMode mode)
  {
    m_ShadowMode = mode;
  }
  OdGiMrShadowMode shadowMode() const
  {
    return m_ShadowMode;
  }
  void setShadowMapEnabled(bool enabled)
  {
    m_bShadowMapEnabled = enabled;
  }
  bool shadowMapEnabled() const
  {
    return m_bShadowMapEnabled;
  }
  void setRayTraceEnabled(bool enabled)
  {
    m_bRayTraceEnabled = enabled;
  }
  bool rayTraceEnabled() const
  {
    return m_bRayTraceEnabled;
  }
  void setRayTraceDepth(int reflection, int refraction, int sum)
  {
    m_iRTReflection = reflection;
    m_iRTRefraction = refraction;
    m_iRTSum = sum;
  }
  void rayTraceDepth(int& reflection, int& refraction, int& sum) const
  {
    reflection = m_iRTReflection;
    refraction = m_iRTRefraction;
    sum = m_iRTSum;
  }
  void setGlobalIlluminationEnabled(bool enabled)
  {
    m_bGlobalIllum = enabled;
  }
  bool globalIlluminationEnabled() const
  {
    return m_bGlobalIllum;
  }
  void setGISampleCount(int num)
  {
    m_iGISampleCount = num;
  }
  int giSampleCount() const
  {
    return m_iGISampleCount;
  }
  void setGISampleRadiusEnabled(bool enabled)
  {
    m_bSampleRadEnabled = enabled;
  }
  bool giSampleRadiusEnabled() const
  {
    return m_bSampleRadEnabled;
  }
  void setGISampleRadius(double radius)
  {
    m_dSampleRad = radius;
  }
  double giSampleRadius() const
  {
    return m_dSampleRad;
  }
  void setGIPhotonsPerLight(int num)
  {
    m_iPhotonsPerLight = num;
  }
  int giPhotonsPerLight() const
  {
    return m_iPhotonsPerLight;
  }
  void setPhotonTraceDepth(int reflection, int refraction, int sum)
  {
    m_iPhotonsReflection = reflection;
    m_iPhotonsRefraction = refraction;
    m_iPhotonsSum = sum;
  }
  void photonTraceDepth(int& reflection, int& refraction, int& sum) const
  {
    reflection = m_iPhotonsReflection;
    refraction = m_iPhotonsRefraction;
    sum = m_iPhotonsSum;
  }
  void setFinalGatheringEnabled(bool enabled)
  {
    m_bFGEnabled = enabled;
  }
  bool finalGatheringEnabled() const
  {
    return m_bFGEnabled;
  }
  void setFGRayCount(int num)
  {
    m_iFGRayCount = num;
  }
  int fgRayCount() const
  {
    return m_iFGRayCount;
  }
  void setFGRadiusState(bool bMin, bool bMax, bool bPixels)
  {
    m_bFGRadMin = bMin;
    m_bFGRadMax = bMax;
    m_bFGPixels = bPixels;
  }
  void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels)
  {
    bMin = m_bFGRadMin;
    bMax = m_bFGRadMax;
    bPixels = m_bFGPixels;
  }
  void setFGSampleRadius(double min, double max)
  {
    m_dFGSRadMin = min;
    m_dFGSRadMax = max;
  }
  void fgSampleRadius(double& min, double& max) const
  {
    min = m_dFGSRadMin;
    max = m_dFGSRadMax;
  }
  void setLightLuminanceScale(double luminance)
  {
    m_dLightLumScale = luminance;
  }
  double lightLuminanceScale() const
  {
    return m_dLightLumScale;
  }
  void setDiagnosticMode(OdGiMrDiagnosticMode mode)
  {
    m_DiagMode = mode;
  }
  OdGiMrDiagnosticMode diagnosticMode() const
  {
    return m_DiagMode;
  }
  void setDiagnosticGridMode(OdGiMrDiagnosticGridMode mode, float fSize)
  {
    m_DiagGridMode = mode;
    m_fDiagGridSize = fSize;
  }
  void diagnosticGridMode(OdGiMrDiagnosticGridMode& mode, float& fSize) const
  {
    mode = m_DiagGridMode;
    fSize = m_fDiagGridSize;
  }
  void setDiagnosticPhotonMode(OdGiMrDiagnosticPhotonMode mode)
  {
    m_DiagPhtMode = mode;
  }
  OdGiMrDiagnosticPhotonMode diagnosticPhotonMode() const
  {
    return m_DiagPhtMode;
  }
  void setDiagnosticBSPMode(OdGiMrDiagnosticBSPMode mode)
  {
    m_DiagBSPMode = mode;
  }
  OdGiMrDiagnosticBSPMode diagnosticBSPMode() const
  {
    return m_DiagBSPMode;
  }
  void setExportMIEnabled(bool enabled)
  {
    m_bExportMIEnabled = enabled;
  }
  bool exportMIEnabled() const
  {
    return m_bExportMIEnabled;
  }
  void setExportMIFileName(const OdString& miName)
  {
    m_sMIFile = miName;
  }
  const OdString &exportMIFileName() const
  {
    return m_sMIFile;
  }
  void setTileSize(int size)
  {
    m_iTileSize = size;
  }
  int tileSize() const
  {
    return m_iTileSize;
  }
  void setTileOrder(OdGiMrTileOrder order)
  {
    m_TileOrder = order;
  }
  OdGiMrTileOrder tileOrder() const
  {
    return m_TileOrder;
  }
  void setMemoryLimit(int limit)
  {
    m_iMemLimit = limit;
  }
  int memoryLimit() const
  {
    return m_iMemLimit;
  }
  void setEnergyMultiplier(float fScale)
  {
    m_fEnergyMult = fScale;
  }
  float energyMultiplier() const
  {
    return m_fEnergyMult;
  }
  void setProgressMonitor(void* pMonitor)
  {
    m_pProgressMonitor = pMonitor;
  }
  const void* progressMonitor() const
  {
    return m_pProgressMonitor;
  }
};

#include "TD_PackPop.h"

#endif // __OD_GI_ENVIRONMENT_TRAITS_DATA__
