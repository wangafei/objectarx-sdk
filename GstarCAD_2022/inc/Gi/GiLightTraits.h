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


#ifndef __OD_GI_LIGHT_TRAITS__
#define __OD_GI_LIGHT_TRAITS__

#include "../TD_PackPush.h"

#include "../CmColor.h"
#include "../OdString.h"
#include "../Ge/GeVector3d.h"

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiLightTraits : public OdGiDrawableTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiLightTraits);

  virtual void setOn(bool on) = 0;
  virtual bool isOn() const = 0;
};

typedef OdSmartPtr<OdGiLightTraits> OdGiLightTraitsPtr;

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
struct OdGiColorRGB
{
  double red, green, blue;

  OdGiColorRGB() : red(0.0), green(0.0), blue(0.0) { }
  OdGiColorRGB(double _red, double _green, double _blue) : red(_red), green(_green), blue(_blue) { }

  friend OdGiColorRGB operator +(const OdGiColorRGB &c1, const OdGiColorRGB &c2)
  {
    return OdGiColorRGB(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue);
  }
  friend OdGiColorRGB operator +(const OdGiColorRGB &c, double s)
  {
    return OdGiColorRGB(c.red + s, c.green + s, c.blue + s);
  }
  friend OdGiColorRGB operator +(double s, const OdGiColorRGB &c)
  {
    return OdGiColorRGB(s + c.red, s + c.green, s + c.blue);
  }

  friend OdGiColorRGB operator -(const OdGiColorRGB &c1, const OdGiColorRGB &c2)
  {
    return OdGiColorRGB(c1.red - c2.red, c1.green - c2.green, c1.blue - c2.blue);
  }
  friend OdGiColorRGB operator -(const OdGiColorRGB &c, double s)
  {
    return OdGiColorRGB(c.red - s, c.green - s, c.blue - s);
  }
  friend OdGiColorRGB operator -(double s, const OdGiColorRGB &c)
  {
    return OdGiColorRGB(s - c.red, s - c.green, s - c.blue);
  }

  friend OdGiColorRGB operator *(const OdGiColorRGB &c1, const OdGiColorRGB &c2)
  {
    return OdGiColorRGB(c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue);
  }
  friend OdGiColorRGB operator *(const OdGiColorRGB &c, double s)
  {
    return OdGiColorRGB(c.red * s, c.green * s, c.blue * s);
  }
  friend OdGiColorRGB operator *(double s, const OdGiColorRGB &c)
  {
    return OdGiColorRGB(s * c.red, s * c.green, s * c.blue);
  }

  friend OdGiColorRGB operator /(const OdGiColorRGB &c1, const OdGiColorRGB &c2)
  {
    return OdGiColorRGB(c1.red / c2.red, c1.green / c2.green, c1.blue / c2.blue);
  }
  friend OdGiColorRGB operator /(const OdGiColorRGB &c, double s)
  {
    return OdGiColorRGB(c.red / s, c.green / s, c.blue / s);
  }
  friend OdGiColorRGB operator /(double s, const OdGiColorRGB &c)
  {
    return OdGiColorRGB(s / c.red, s / c.green, s / c.blue);
  }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiShadowParameters
{
public:
  OdGiShadowParameters();
  OdGiShadowParameters(const OdGiShadowParameters &parms);

  enum ShadowType 
  {
    kShadowsRayTraced = 0,
    kShadowMaps,
    kAreaSampled
  };

  void setShadowsOn(bool on);
  bool shadowsOn() const;

  void setShadowType(ShadowType typ);
  ShadowType shadowType() const;

  bool setShadowMapSize(OdUInt16 sz);
  OdUInt16 shadowMapSize() const;

  bool setShadowMapSoftness(OdUInt8 soft);
  OdUInt8 shadowMapSoftness() const;

  OdGiShadowParameters &operator =(const OdGiShadowParameters &parms);
private:
  bool       m_bShadowsOn;
  ShadowType m_shadowType;
  OdUInt16   m_shadowMapSize;
  OdUInt8    m_shadowMapSoftness;
};

inline OdGiShadowParameters::OdGiShadowParameters()
: m_bShadowsOn(true)
, m_shadowType(OdGiShadowParameters::kShadowsRayTraced)
, m_shadowMapSize(256)
, m_shadowMapSoftness(1)
{
}

inline OdGiShadowParameters::OdGiShadowParameters(const OdGiShadowParameters &parms)
: m_bShadowsOn(parms.m_bShadowsOn)
, m_shadowType(parms.m_shadowType)
, m_shadowMapSize(parms.m_shadowMapSize)
, m_shadowMapSoftness(parms.m_shadowMapSoftness)
{
}

inline void OdGiShadowParameters::setShadowsOn(bool on)
{
  m_bShadowsOn = on;
}

inline bool OdGiShadowParameters::shadowsOn() const
{
  return m_bShadowsOn;
}

inline void OdGiShadowParameters::setShadowType(ShadowType typ)
{
  m_shadowType = typ;
}

inline OdGiShadowParameters::ShadowType OdGiShadowParameters::shadowType() const
{
  return m_shadowType;
}

inline bool OdGiShadowParameters::setShadowMapSize(OdUInt16 sz)
{
  if((sz & (sz-1)) == 0 && sz >= 64 && sz <= 4096) // valid values are 64, 128, 256, 512, 1024, 2048, and 4096
  {
    m_shadowMapSize = sz;    
    return true;
  }
  else
  {
    return false;
  }
}

inline OdUInt16 OdGiShadowParameters::shadowMapSize() const
{
  return m_shadowMapSize;
}

inline bool OdGiShadowParameters::setShadowMapSoftness(OdUInt8 soft)
{
  m_shadowMapSoftness = soft;
  return true;
}

inline OdUInt8 OdGiShadowParameters::shadowMapSoftness() const
{
  return m_shadowMapSoftness;
}

inline OdGiShadowParameters &OdGiShadowParameters::operator =(const OdGiShadowParameters &parms)
{
  m_bShadowsOn = parms.m_bShadowsOn;
  m_shadowType = parms.m_shadowType;
  m_shadowMapSize = parms.m_shadowMapSize;
  m_shadowMapSoftness = parms.m_shadowMapSoftness;
  return *this;
}

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiLightAttenuation
{
public:
  OdGiLightAttenuation();
  
  enum AttenuationType 
  {
    kNone = 0,
    kInverseLinear,
    kInverseSquare
  };
  
  void setAttenuationType(AttenuationType typ);
  AttenuationType attenuationType() const;
  
  void setUseLimits(bool on);
  bool useLimits() const;
  
  void setLimits(double startlim, double endlim);
  double startLimit() const;
  double endLimit() const;
  
private:
  double          m_dAttenStartLimit;
  double          m_dAttenEndLimit;
  AttenuationType m_attenType;
  bool            m_bUseAttenLimits;
};

inline OdGiLightAttenuation::OdGiLightAttenuation()
: m_attenType(OdGiLightAttenuation::kNone)
, m_bUseAttenLimits(false)
, m_dAttenStartLimit(1.0)
, m_dAttenEndLimit(10.0)
{
}

inline void OdGiLightAttenuation::setAttenuationType(AttenuationType typ)
{
  m_attenType = typ;
}

inline OdGiLightAttenuation::AttenuationType OdGiLightAttenuation::attenuationType() const
{
  return m_attenType;
}
  
inline void OdGiLightAttenuation::setUseLimits(bool on)
{
  m_bUseAttenLimits = on;
}

inline bool OdGiLightAttenuation::useLimits() const
{
  return m_bUseAttenLimits;
}

inline void OdGiLightAttenuation::setLimits(double startlim, double endlim)
{
  m_dAttenStartLimit = startlim;
  m_dAttenEndLimit   = endlim;
}

inline double OdGiLightAttenuation::startLimit() const
{
  return m_dAttenStartLimit;
}

inline double OdGiLightAttenuation::endLimit() const
{
  return m_dAttenEndLimit;
}


/** Description:
    This class contains all sky properties for OdDbSun objects.

    Library:
    TD_Gi

    {group:OdGi_Classes} 
*/
class OdGiSkyParameters
{
public:
  OdGiSkyParameters();

  bool operator==(const OdGiSkyParameters& params) const;

  void setIllumination(bool enable);
  bool illumination() const;

  void setIntensityFactor(double intensity);
  double intensityFactor() const;

  void setHaze(double haze);
  double haze() const;

  void setHorizonHeight(double height);
  double horizonHeight() const;

  void setHorizonBlur(double blur);
  double horizonBlur() const;

  void setGroundColor(const OdCmEntityColor& color);
  OdCmEntityColor groundColor() const;

  void setNightColor(const OdCmEntityColor& color);
  OdCmEntityColor nightColor() const;

  void setAerialPerspective(bool apply);
  bool aerialPerspective() const;

  void setVisibilityDistance(double distance);
  double visibilityDistance() const;

  void setDiskScale(double scale);
  double diskScale() const;

  void setGlowIntensity(double intensity);
  double glowIntensity() const;

  void setDiskIntensity(double intensity);
  double diskIntensity() const;

  void setSolarDiskSamples(OdUInt16 samples);
  OdUInt16 solarDiskSamples() const;

  void setSunDirection(const OdGeVector3d& sundir);
  const OdGeVector3d& sunDirection() const;

  void setRedBlueShift(double redBlueShift);
  double redBlueShift() const;

  void setSaturation(double saturation);
  double saturation() const;
private:

  double          m_intensityFactor;
  double          m_haze;
  double          m_horizonHeight;
  double          m_horizonBlur;
  double          m_visibilityDistance;
  double          m_diskScale;
  double          m_glowIntensity;
  double          m_diskIntensity;
  double          m_redBlueShift;
  double          m_saturation;
  OdGeVector3d    m_sunDirection;
  OdCmEntityColor m_groundColor;
  OdCmEntityColor m_nightColor;
  OdUInt16        m_solarDiskSamples;
  bool            m_status;
  bool            m_aerialPerspective;
};


/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiStandardLightTraits : public OdGiLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiStandardLightTraits);

  virtual void setIntensity(double inten) = 0;
  virtual double intensity() const = 0;

  virtual void setLightColor(const OdCmEntityColor& color) = 0;
  virtual OdCmEntityColor lightColor() const = 0;

  virtual void setShadowParameters(const OdGiShadowParameters& params) = 0;
  virtual OdGiShadowParameters shadowParameters() const = 0;
};

typedef OdSmartPtr<OdGiStandardLightTraits> OdGiStandardLightTraitsPtr;

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiPointLightTraits : public OdGiStandardLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiPointLightTraits);

  virtual void setPosition(const OdGePoint3d& pos) = 0;
  virtual OdGePoint3d position() const = 0;

  virtual OdGiLightAttenuation lightAttenuation() const = 0;
  virtual void setAttenuation(const OdGiLightAttenuation& atten) = 0;
};

typedef OdSmartPtr<OdGiPointLightTraits> OdGiPointLightTraitsPtr;


/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiSpotLightTraits : public OdGiStandardLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiSpotLightTraits);

  virtual void setPosition(const OdGePoint3d& pos) = 0;
  virtual OdGePoint3d position() const = 0;

  virtual void setTargetLocation(const OdGePoint3d& loc) = 0;
  virtual OdGePoint3d targetLocation() const = 0;

  virtual bool setHotspotAndFalloff(double hotspot, double falloff) = 0;
  virtual double hotspot() const = 0;
  virtual double falloff() const = 0;

  virtual OdGiLightAttenuation lightAttenuation() const = 0;
  virtual void setAttenuation(const OdGiLightAttenuation& atten) = 0;
};

typedef OdSmartPtr<OdGiSpotLightTraits> OdGiSpotLightTraitsPtr;


/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiDistantLightTraits : public OdGiStandardLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiDistantLightTraits);
  
  virtual void setLightDirection(const OdGeVector3d& vec) = 0;
  virtual OdGeVector3d lightDirection() const = 0;
  
  virtual void setIsSunlight(bool isSunlight) = 0;
  virtual bool isSunlight() const = 0;
};

typedef OdSmartPtr<OdGiDistantLightTraits> OdGiDistantLightTraitsPtr;

//
// OdGiSkyParameters inline methods
//

inline OdGiSkyParameters::OdGiSkyParameters()
  : m_status(false)
  , m_intensityFactor(1.0)
  , m_haze(0.0)
  , m_horizonHeight(0.0)
  , m_horizonBlur(0.1)
  , m_aerialPerspective(false)
  , m_visibilityDistance(10000.0)
  , m_diskScale(4.0)
  , m_glowIntensity(1.0)
  , m_diskIntensity(1.0)
  , m_solarDiskSamples(8)
  , m_redBlueShift(0.0)
  , m_saturation(1.0)
{
  m_groundColor.setColor(0xc2808080);
  m_nightColor.setColor(0xc2010205);
  m_sunDirection.set(0.35, 1.0, -0.25);
}

inline void OdGiSkyParameters::setIllumination(bool enable)
{
  m_status = enable;
}
inline bool OdGiSkyParameters::illumination() const
{
  return m_status;
}
inline void OdGiSkyParameters::setIntensityFactor(double intensity)
{
  m_intensityFactor = intensity;
}
inline double OdGiSkyParameters::intensityFactor() const
{
  return m_intensityFactor;
}
inline void OdGiSkyParameters::setHaze(double haze)
{
  m_haze = haze;
}
inline double OdGiSkyParameters::haze() const
{
  return m_haze;
}
inline void OdGiSkyParameters::setHorizonHeight(double height)
{
  m_horizonHeight = height;
}
inline double OdGiSkyParameters::horizonHeight() const
{
  return m_horizonHeight;
}
inline void OdGiSkyParameters::setHorizonBlur(double blur)
{
  m_horizonBlur = blur;
}
inline double OdGiSkyParameters::horizonBlur() const
{
  return m_horizonBlur;
}
inline void OdGiSkyParameters::setGroundColor(const OdCmEntityColor& color)
{
  m_groundColor = color;
}
inline OdCmEntityColor OdGiSkyParameters::groundColor() const
{
  return m_groundColor;
}
inline void OdGiSkyParameters::setNightColor(const OdCmEntityColor& color)
{
  m_nightColor = color;
}
inline OdCmEntityColor OdGiSkyParameters::nightColor() const
{
  return m_nightColor;
}
inline void OdGiSkyParameters::setAerialPerspective(bool apply)
{
  m_aerialPerspective = apply;
}
inline bool OdGiSkyParameters::aerialPerspective() const
{
  return m_aerialPerspective;
}
inline void OdGiSkyParameters::setVisibilityDistance(double distance)
{
  m_visibilityDistance = distance;
}
inline double OdGiSkyParameters::visibilityDistance() const
{
  return m_visibilityDistance;
}
inline void OdGiSkyParameters::setDiskScale(double scale)
{
  m_diskScale = scale;
}
inline double OdGiSkyParameters::diskScale() const
{
  return m_diskScale;
}
inline void OdGiSkyParameters::setGlowIntensity(double intensity)
{
  m_glowIntensity = intensity;
}
inline double OdGiSkyParameters::glowIntensity() const
{
  return m_glowIntensity;
}
inline void OdGiSkyParameters::setDiskIntensity(double intensity)
{
  m_diskIntensity = intensity;
}
inline double OdGiSkyParameters::diskIntensity() const
{
  return m_diskIntensity;
}
inline void OdGiSkyParameters::setSolarDiskSamples(OdUInt16 samples)
{
  m_solarDiskSamples = samples;
}
inline OdUInt16 OdGiSkyParameters::solarDiskSamples() const
{
  return m_solarDiskSamples;
}
inline void OdGiSkyParameters::setSunDirection(const OdGeVector3d& sundir)
{
  m_sunDirection = sundir;
}
inline const OdGeVector3d& OdGiSkyParameters::sunDirection() const
{
  return m_sunDirection;
}
inline void OdGiSkyParameters::setRedBlueShift(double redBlueShift)
{
  m_redBlueShift = redBlueShift;
}
inline double OdGiSkyParameters::redBlueShift() const
{
  return m_redBlueShift;
}
inline void OdGiSkyParameters::setSaturation(double saturation)
{
  m_saturation = saturation;
}
inline double OdGiSkyParameters::saturation() const
{
  return m_saturation;
}

inline bool OdGiSkyParameters::operator==(const OdGiSkyParameters& params) const
{
  if (m_status             != params.m_status)             return false;
  if (m_intensityFactor    != params.m_intensityFactor)    return false;
  if (m_haze               != params.m_haze)               return false;
  if (m_horizonHeight      != params.m_horizonHeight)      return false;
  if (m_horizonBlur        != params.m_horizonBlur)        return false;
  if (m_groundColor        != params.m_groundColor)        return false;
  if (m_nightColor         != params.m_nightColor)         return false;
  if (m_aerialPerspective  != params.m_aerialPerspective)  return false;
  if (m_visibilityDistance != params.m_visibilityDistance) return false;
  if (m_diskScale          != params.m_diskScale)          return false;
  if (m_glowIntensity      != params.m_glowIntensity)      return false;
  if (m_diskIntensity      != params.m_diskIntensity)      return false;
  if (m_solarDiskSamples   != params.m_solarDiskSamples)   return false;
  if (m_sunDirection       != params.m_sunDirection)       return false;
  if (m_redBlueShift       != params.m_redBlueShift)       return false;
  if (m_saturation         != params.m_saturation)         return false;
  return true;
}

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiShadowParameters2 : public OdGiShadowParameters
{
  public:
    OdGiShadowParameters2();
    OdGiShadowParameters2(const OdGiShadowParameters &parms);
    OdGiShadowParameters2(const OdGiShadowParameters2 &parms2);

    enum ExtendedLightShape {
      kLinear = 0,
      kRectangle,
      kDisk,
      kCylinder,
      kSphere
    };

    bool setShadowSamples(OdUInt16 nSamples);
    OdUInt16 shadowSamples() const;
    
    void setShapeVisibility(bool bVisibility);
    bool shapeVisibility() const;

    bool setExtendedLightShape(ExtendedLightShape lightShape);
    ExtendedLightShape extendedLightShape() const;

    bool setExtendedLightLength(double dLength);
    double extendedLightLength() const;

    bool setExtendedLightWidth(double dWidth);
    double extendedLightWidth() const;

    bool setExtendedLightRadius(double dRadius);
    double extendedLightRadius() const;

    OdGiShadowParameters2 &operator =(const OdGiShadowParameters &parms);
    OdGiShadowParameters2 &operator =(const OdGiShadowParameters2 &parms2);
  private:
    OdUInt16           m_shadowSamples;
    bool               m_bShapeVisible;
    ExtendedLightShape m_lightShape;
    double             m_lightLength;
    double             m_lightWidth;
    double             m_lightRadius;
};

inline OdGiShadowParameters2::OdGiShadowParameters2()
  : OdGiShadowParameters()
  , m_shadowSamples(16)
  , m_bShapeVisible(false)
  , m_lightShape(kSphere)
  , m_lightLength(0.0)
  , m_lightWidth(0.0)
  , m_lightRadius(0.0)
{
}

inline OdGiShadowParameters2::OdGiShadowParameters2(const OdGiShadowParameters &parms)
  : OdGiShadowParameters(parms)
  , m_shadowSamples(16)
  , m_bShapeVisible(false)
  , m_lightShape(kSphere)
  , m_lightLength(0.0)
  , m_lightWidth(0.0)
  , m_lightRadius(0.0)
{
}

inline OdGiShadowParameters2::OdGiShadowParameters2(const OdGiShadowParameters2 &parms2)
  : OdGiShadowParameters(parms2)
  , m_shadowSamples(parms2.m_shadowSamples)
  , m_bShapeVisible(parms2.m_bShapeVisible)
  , m_lightShape(parms2.m_lightShape)
  , m_lightLength(parms2.m_lightLength)
  , m_lightWidth(parms2.m_lightWidth)
  , m_lightRadius(parms2.m_lightRadius)
{
}

inline OdGiShadowParameters2 &OdGiShadowParameters2::operator =(const OdGiShadowParameters &parms)
{
  *((OdGiShadowParameters*)this) = parms;
  return *this;
}

inline OdGiShadowParameters2 &OdGiShadowParameters2::operator =(const OdGiShadowParameters2 &parms2)
{
  *((OdGiShadowParameters*)this) = *((const OdGiShadowParameters*)&parms2);
  m_shadowSamples = parms2.m_shadowSamples;
  m_bShapeVisible = parms2.m_bShapeVisible;
  m_lightShape = parms2.m_lightShape;
  m_lightLength = parms2.m_lightLength;
  m_lightWidth = parms2.m_lightWidth;
  m_lightRadius = parms2.m_lightRadius;
  return *this;
}

inline bool OdGiShadowParameters2::setShadowSamples(OdUInt16 nSamples)
{
  m_shadowSamples = nSamples;
  return true;
}

inline OdUInt16 OdGiShadowParameters2::shadowSamples() const
{
  return m_shadowSamples;
}

inline void OdGiShadowParameters2::setShapeVisibility(bool bVisibility)
{
  m_bShapeVisible = bVisibility;
}

inline bool OdGiShadowParameters2::shapeVisibility() const
{
  return m_bShapeVisible;
}

inline bool OdGiShadowParameters2::setExtendedLightShape(OdGiShadowParameters2::ExtendedLightShape lightShape)
{
  m_lightShape = lightShape;
  return true;
}

inline OdGiShadowParameters2::ExtendedLightShape OdGiShadowParameters2::extendedLightShape() const
{
  return m_lightShape;
}

inline bool OdGiShadowParameters2::setExtendedLightLength(double dLength)
{
  m_lightLength = dLength;
  return true;
}

inline double OdGiShadowParameters2::extendedLightLength() const
{
  return m_lightLength;
}

inline bool OdGiShadowParameters2::setExtendedLightWidth(double dWidth)
{
  m_lightWidth = dWidth;
  return true;
}

inline double OdGiShadowParameters2::extendedLightWidth() const
{
  return m_lightWidth;
}

inline bool OdGiShadowParameters2::setExtendedLightRadius(double dRadius)
{
  m_lightRadius = dRadius;
  return true;
}

inline double OdGiShadowParameters2::extendedLightRadius() const
{
  return m_lightRadius;
}

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiPointLightTraits2 : public OdGiPointLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiPointLightTraits2);

  virtual void setPhysicalIntensity(double fIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const OdGiColorRGB& color) = 0;
  virtual OdGiColorRGB lampColor() const = 0;

  virtual void setShadowParameters(const OdGiShadowParameters2 &sp) = 0;
  virtual void shadowParameters(OdGiShadowParameters2 &sp) const = 0;

  virtual void setHasTarget(bool bTarget) = 0;
  virtual bool hasTarget() const = 0;

  virtual void setTargetLocation(const OdGePoint3d &loc) = 0;
  virtual OdGePoint3d targetLocation() const = 0;
};

typedef OdSmartPtr<OdGiPointLightTraits2> OdGiPointLightTraits2Ptr;

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiSpotLightTraits2 : public OdGiSpotLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiSpotLightTraits2);

  virtual void setPhysicalIntensity(double fIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const OdGiColorRGB& color) = 0;
  virtual OdGiColorRGB lampColor() const = 0;

  virtual void setShadowParameters(const OdGiShadowParameters2 &sp) = 0;
  virtual void shadowParameters(OdGiShadowParameters2 &sp) const = 0;
};

typedef OdSmartPtr<OdGiSpotLightTraits2> OdGiSpotLightTraits2Ptr;

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiDistantLightTraits2 : public OdGiDistantLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiDistantLightTraits2);

  virtual void setPhysicalIntensity(double fIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const OdGiColorRGB& color) = 0;
  virtual OdGiColorRGB lampColor() const = 0;

  virtual void setShadowParameters(const OdGiShadowParameters2 &sp) = 0;
  virtual void shadowParameters(OdGiShadowParameters2 &sp) const = 0;

  virtual void setSkyParameters(const OdGiSkyParameters &params) = 0;
  virtual void skyParameters(OdGiSkyParameters &params) const = 0;
};

typedef OdSmartPtr<OdGiDistantLightTraits2> OdGiDistantLightTraits2Ptr;

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiWebLightTraits : public OdGiPointLightTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiWebLightTraits);

  enum WebFileType
  {
    kTypeA = 3,
    kTypeB = 2,
    kTypeC = 1
  };

  enum WebSymmetry
  {
    kNoSymmetry = 0,
    kSingleSymmetry,
    kDoubleSymmetry,
    kAxialSymmetry
  };

  virtual void setPhysicalIntensity(double fIntensity) = 0;
  virtual double physicalIntensity() const = 0;

  virtual void setLampColor(const OdGiColorRGB& color) = 0;
  virtual OdGiColorRGB lampColor() const = 0;

  virtual void setShadowParameters(const OdGiShadowParameters2 &sp) = 0;
  virtual void shadowParameters(OdGiShadowParameters2 &sp) const = 0;

  virtual void setHasTarget(bool bTarget) = 0;
  virtual bool hasTarget() const = 0;

  virtual void setTargetLocation(const OdGePoint3d &loc) = 0;
  virtual OdGePoint3d targetLocation() const = 0;

  virtual void setWebFile(const OdString &fileName) = 0;
  virtual OdString webFile() const = 0;

  virtual void setWebRotation(OdGeVector3d fRot) = 0;
  virtual OdGeVector3d webRotation() const = 0;

  virtual void setWebFlux(double fFlux) = 0;
  virtual double webFlux() const = 0;

  virtual void setWebFileType(WebFileType type) = 0;
  virtual WebFileType webFileType() const = 0;

  virtual void setWebSymmetry(WebSymmetry sym) = 0;
  virtual WebSymmetry webSymmetry() const = 0;

  virtual void setWebHorzAng90to270(bool bFlag) = 0;
  virtual bool webHorzAng90to270() const = 0;
};

typedef OdSmartPtr<OdGiWebLightTraits> OdGiWebLightTraitsPtr;

#include "../TD_PackPop.h"

#endif // __OD_GI_LIGHT_TRAITS__
