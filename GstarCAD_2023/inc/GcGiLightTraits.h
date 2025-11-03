/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcgi.h"

#pragma pack (push, 8)

class GCBASE_PORT GcGiLightTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiLightTraits);

  virtual void setOn(bool on) = 0;
  virtual bool isOn() const = 0;
};

class GCBASE_PORT GcGiShadowParameters : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiShadowParameters);

  GcGiShadowParameters();
  ~GcGiShadowParameters();

  bool operator==(const GcGiShadowParameters& params) const;

  virtual void setShadowsOn(bool on);
  virtual bool shadowsOn() const;

  enum ShadowType {
    kShadowsRayTraced = 0,
    kShadowMaps,
    kAreaSampled
  };

  virtual void setShadowType(ShadowType typ);
  virtual ShadowType shadowType() const;

  virtual bool setShadowMapSize(Gsoft::UInt16 sz);
  virtual Gsoft::UInt16 shadowMapSize() const;

  virtual bool setShadowMapSoftness(Gsoft::UInt8 soft);
  virtual Gsoft::UInt8 shadowMapSoftness() const;

  virtual bool setShadowSamples(Gsoft::UInt16 samples);
  virtual Gsoft::UInt16 shadowSamples() const;

  virtual void setShapeVisibility(bool visible);
  virtual bool shapeVisibility() const;

  enum ExtendedLightShape {
    kLinear = 0,
    kRectangle,
    kDisk,
    kCylinder,
    kSphere
  };

  virtual bool setExtendedLightShape(ExtendedLightShape shape);
  virtual ExtendedLightShape extendedLightShape() const;

  virtual bool setExtendedLightLength(double length);
  virtual double extendedLightLength() const;

  virtual bool setExtendedLightWidth(double width);
  virtual double extendedLightWidth() const;

  virtual bool setExtendedLightRadius(double radius);
  virtual double extendedLightRadius() const;

protected:

  bool                mShadowsOn;
  ShadowType          mShadowType;
  Gsoft::UInt16       mShadowMapSize;
  Gsoft::UInt8        mShadowMapSoftness;
  Gsoft::UInt16       mShadowSamples;
  bool                mbShapeVisibility;
  ExtendedLightShape  mExtLightShape;
  double              mExtLightLength;
  double              mExtLightWidth;
  double              mExtLightRadius;
};

class GCBASE_PORT GcGiLightAttenuation : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiLightAttenuation);

  GcGiLightAttenuation();
  ~GcGiLightAttenuation();

  bool operator==(const GcGiLightAttenuation& atten) const;

  enum AttenuationType {
    kNone = 0,
    kInverseLinear,
    kInverseSquare
  };

  virtual void setAttenuationType(AttenuationType typ);
  virtual AttenuationType attenuationType() const;

  virtual void setUseLimits(bool on);
  virtual bool useLimits() const;
  virtual void setLimits(double startlim, double endlim);
  virtual double startLimit() const;
  virtual double endLimit() const;

private:
  AttenuationType mAttenType;
  bool            mUseAttenLimits;
  double          mAttenStartLimit;
  double          mAttenEndLimit;
};

class GCBASE_PORT GcGiSkyParameters : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiSkyParameters);

  GcGiSkyParameters();
  ~GcGiSkyParameters();

  bool operator==(const GcGiSkyParameters& params) const;

  void setIllumination(bool enable) { return setIlluminationImp(enable); }
  bool illumination() const { return illuminationImp(); }

  bool setIntensityFactor(double intensity) { return setIntensityFactorImp(intensity); }
  double intensityFactor() const { return intensityFactorImp(); }

  bool setHaze(double haze) { return setHazeImp(haze); }
  double haze() const { return hazeImp(); }

  bool setHorizonHeight(double height) { return setHorizonHeightImp(height); }
  double horizonHeight() const { return horizonHeightImp(); }

  bool setHorizonBlur(double blur) { return setHorizonBlurImp(blur); }
  double horizonBlur() const { return horizonBlurImp(); }

  void setGroundColor(const GcCmColor& color) { return setGroundColorImp(color); }
  GcCmColor groundColor() const { return groundColorImp(); }

  void setNightColor(const GcCmColor& color) { setNightColorImp(color); }
  GcCmColor nightColor() const { return nightColorImp(); }

  void setAerialPerspective(bool apply) { setAerialPerspectiveImp(apply); }
  bool aerialPerspective() const { return aerialPerspectiveImp(); }

  bool setVisibilityDistance(double distance) { return setVisibilityDistanceImp(distance); }
  double visibilityDistance() const { return visibilityDistanceImp(); }

  bool setDiskScale(double scale) { return setDiskScaleImp(scale); }
  double diskScale() const { return diskScaleImp(); }

  bool setGlowIntensity(double intensity) { return setGlowIntensityImp(intensity); }
  double glowIntensity() const { return glowIntensityImp(); }

  bool setDiskIntensity(double intensity) { return setDiskIntensityImp(intensity); }
  double diskIntensity() const { return diskIntensityImp(); }

  bool setSolarDiskSamples(Gsoft::UInt16 samples) { return setSolarDiskSamplesImp(samples); }
  Gsoft::UInt16 solarDiskSamples() const { return solarDiskSamplesImp(); }

  bool setSunDirection(const GcGeVector3d& sundir) { return setSunDirectionImp(sundir); }
  const GcGeVector3d& sunDirection() const { return sunDirectionImp(); }

  bool setRedBlueShift(double redBlueShift) { return setRedBlueShiftImp(redBlueShift); }
  double redBlueShift(void) const { return redBlueShiftImp(); }

  bool setSaturation(double saturation) { return setSaturationImp(saturation); }
  double saturation(void) const { return saturationImp(); }

protected:
  virtual void setIlluminationImp(bool enable);
  virtual bool illuminationImp(void) const;

  virtual bool setIntensityFactorImp(double intensity);
  virtual double intensityFactorImp() const;

  virtual bool setHazeImp(double haze);
  virtual double hazeImp(void) const;

  virtual bool setHorizonHeightImp(double height);
  virtual double horizonHeightImp(void) const;

  virtual bool setHorizonBlurImp(double blur);
  virtual double horizonBlurImp() const;

  virtual void setGroundColorImp(const GcCmColor& color);
  virtual GcCmColor groundColorImp() const;

  virtual void setNightColorImp(const GcCmColor& color);
  virtual GcCmColor nightColorImp() const;

  virtual void setAerialPerspectiveImp(bool apply);
  virtual bool aerialPerspectiveImp() const;

  virtual bool setVisibilityDistanceImp(double distance);
  virtual double visibilityDistanceImp() const;

  virtual bool setDiskScaleImp(double scale);
  virtual double diskScaleImp() const;

  virtual bool setGlowIntensityImp(double intensity);
  virtual double glowIntensityImp() const;

  virtual bool setDiskIntensityImp(double intensity);
  virtual double diskIntensityImp() const;

  virtual bool setSolarDiskSamplesImp(Gsoft::UInt16 samples);
  virtual Gsoft::UInt16 solarDiskSamplesImp(void) const;

  virtual bool  setSunDirectionImp(const GcGeVector3d& sundir);
  virtual const GcGeVector3d& sunDirectionImp(void) const;

  virtual bool setRedBlueShiftImp(double redBlueShift);
  virtual double  redBlueShiftImp(void) const;

  virtual bool setSaturationImp(double saturation);
  virtual double  saturationImp(void) const;

private:
  bool            mStatus;
  double          mIntensityFactor;
  double          mHaze;
  double          mHorizonHeight;
  double          mHorizonBlur;
  GcCmColor       mGroundColor;
  GcCmColor       mNightColor;
  bool            mAerialPerspective;
  double          mVisibilityDistance;
  double          mDiskScale;
  double          mGlowIntensity;
  double          mDiskIntensity;
  Gsoft::UInt16   mSolarDiskSamples;
  GcGeVector3d    mSunDirection;
  double          mRedBlueShift;
  double          mSaturation;
};

class GCBASE_PORT GcGiStandardLightTraits : public GcGiLightTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiStandardLightTraits);

  virtual void setIntensity(double inten) = 0;
  virtual double intensity() const = 0;

  virtual void setLightColor(const GcCmColor& color) = 0;
  virtual GcCmColor lightColor() const = 0;

  virtual void setShadowParameters(const GcGiShadowParameters& params) = 0;
  virtual void shadowParameters(GcGiShadowParameters& params) const = 0;
};

class GCBASE_PORT GcGiPointLightTraits : public GcGiStandardLightTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiPointLightTraits);

  virtual void setPosition(const GcGePoint3d& pos) = 0;
  virtual GcGePoint3d position() const = 0;

  virtual void lightAttenuation(GcGiLightAttenuation& atten) const = 0;
  virtual void setAttenuation(const GcGiLightAttenuation& atten) = 0;

  virtual void setPhysicalIntensity(double physicalIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const GcGiColorRGB& rgbColor) = 0;
  virtual void lampColor(GcGiColorRGB& rgbColor) const = 0;

  virtual void setHasTarget(bool bHasTarget) = 0;
  virtual bool hasTarget(void) const = 0;

  virtual void setTargetLocation(const GcGePoint3d& loc) = 0;
  virtual GcGePoint3d targetLocation() const = 0;
};

class GCBASE_PORT GcGiSpotLightTraits : public GcGiStandardLightTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiSpotLightTraits);

  virtual void setPosition(const GcGePoint3d& pos) = 0;
  virtual GcGePoint3d position() const = 0;

  virtual void setTargetLocation(const GcGePoint3d& loc) = 0;
  virtual GcGePoint3d targetLocation() const = 0;

  virtual bool setHotspotAndFalloff(double hotspot, double falloff) = 0;
  virtual double hotspot() const = 0;
  virtual double falloff() const = 0;

  virtual void lightAttenuation(GcGiLightAttenuation& atten) const = 0;
  virtual void setAttenuation(const GcGiLightAttenuation& atten) = 0;

  virtual void setPhysicalIntensity(double physicalIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const GcGiColorRGB& rgbColor) = 0;
  virtual void lampColor(GcGiColorRGB& rgbColor) const = 0;
};

class GCBASE_PORT GcGiDistantLightTraits : public GcGiStandardLightTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiDistantLightTraits);

  virtual void setLightDirection(const GcGeVector3d& vec) = 0;
  virtual GcGeVector3d lightDirection() const = 0;

  virtual void setIsSunlight(bool isSunlight) = 0;
  virtual bool isSunlight() const = 0;

  virtual void setPhysicalIntensity(double physicalIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const GcGiColorRGB& rgbColor) = 0;
  virtual void lampColor(GcGiColorRGB& rgbColor) const = 0;

  virtual void setSkyParameters(const GcGiSkyParameters& params) = 0;
  virtual void skyParameters(GcGiSkyParameters& params) const = 0;
};

class GCBASE_PORT GcGiWebLightTraits : public GcGiPointLightTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiWebLightTraits);

  enum WebFileType
  {
    kTypeC = 1,
    kTypeB = 2,
    kTypeA = 3
  };

  enum WebSymmetry
  {
    kNoSymmetry = 0,
    kSingleSymmetry = 1,
    kDoubleSymmetry = 2,
    kAxialSymmetry = 3,
  };

  virtual void setWebFile(const GCHAR* webFile) = 0;
  virtual void webFile(GcString& webFile) const = 0;

  virtual void setWebRotation(GcGeVector3d rotation) = 0;
  virtual void webRotation(GcGeVector3d& rotation) const = 0;

  virtual void setWebFlux(double flux) const = 0;
  virtual double webFlux() const = 0;

  virtual void setWebFileType(WebFileType type) = 0;
  virtual WebFileType webFileType(void) const = 0;

  virtual void setWebSymmetry(WebSymmetry symmetry) = 0;
  virtual WebSymmetry webSymmetry(void) const = 0;

  virtual void setWebHorzAng90to270(bool bIs90to270) = 0;
  virtual bool webHorzAng90to270(void) const = 0;
};

#pragma pack (pop)