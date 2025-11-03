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


#ifndef __OD_GI_LIGHT_TRAITS_DATA__
#define __OD_GI_LIGHT_TRAITS_DATA__

#include "../TD_PackPush.h"

#include "../Gi/GiLightTraits.h"

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiLightTraitsData
{
  double                     m_dIntensity;
  OdCmEntityColor            m_color;
  bool                       m_bOn;
protected:
  OdGiShadowParameters2      m_shadowParameters;
  
protected:

  OdGiDrawable::DrawableType m_type;
  OdGiLightTraitsData()
    : m_bOn(false)
    , m_dIntensity(0.0)
  {}

public:

  bool isOn() const { return m_bOn; }
  void setOn(bool value) { m_bOn = value; }

  double intensity() const { return m_dIntensity; }
  void setIntensity(double dIntensity) { m_dIntensity = dIntensity; }

  OdCmEntityColor color() const { return m_color; }
  void setColor(const OdCmEntityColor& color) { m_color = color; }

  OdGiShadowParameters shadowParameters() const { return m_shadowParameters; }
  void setShadowParameters(const OdGiShadowParameters& params) { m_shadowParameters = params; }

  OdGiDrawable::DrawableType type() const { return m_type; }

  static void deleteLightTraitsData(OdGiLightTraitsData* pLightTraits);
};                          

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiPointLightTraitsData : public OdGiLightTraitsData
{
  OdGePoint3d          m_position;
  OdGiLightAttenuation m_attenuation;
  // Photometric data
  double               m_dPhysIntensity;
  OdGiColorRGB         m_lampColor;
  bool                 m_bHasTarget;
  OdGePoint3d          m_target;

public:
  OdGiPointLightTraitsData()
    : m_dPhysIntensity(1500.0)
    , m_lampColor(1.0, 1.0, 1.0)
    , m_bHasTarget(false)
  {
    m_type = OdGiDrawable::kPointLight;
  }

  OdGePoint3d position() const { return m_position; }
  void setPosition(const OdGePoint3d& pos) { m_position = pos; }

  OdGiLightAttenuation attenuation() const { return m_attenuation; }
  void setAttenuation(const OdGiLightAttenuation& atten) { m_attenuation = atten; }

  double physicalIntensity() const { return m_dPhysIntensity; }
  void setPhysicalIntensity(double intensity) { m_dPhysIntensity = intensity; }

  OdGiColorRGB lampColor() const { return m_lampColor; }
  void setLampColor(const OdGiColorRGB& color) { m_lampColor = color; }

  TD_USING(OdGiLightTraitsData::shadowParameters);
  void shadowParameters(OdGiShadowParameters2 &sp) const { sp = m_shadowParameters; }
  TD_USING(OdGiLightTraitsData::setShadowParameters);
  void setShadowParameters(const OdGiShadowParameters2 &sp) { m_shadowParameters = sp; }

  bool hasTarget() const { return m_bHasTarget; }
  void setHasTarget(bool bTarget) { m_bHasTarget = bTarget; }

  OdGePoint3d targetLocation() const { return m_target; }
  void setTargetLocation(const OdGePoint3d &loc) { m_target = loc; }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiSpotLightTraitsData : public OdGiLightTraitsData
{
  OdGePoint3d          m_position, m_target;
  OdGiLightAttenuation m_attenuation;
  double               m_dHotspot, m_dFalloff;
  // Photometric data
  double               m_dPhysIntensity;
  OdGiColorRGB         m_lampColor;

public:
  OdGiSpotLightTraitsData()
    : m_dHotspot(0.0)
    , m_dFalloff(0.0)
    , m_dPhysIntensity(1500.0)
    , m_lampColor(1.0, 1.0, 1.0)
  {
    m_type = OdGiDrawable::kSpotLight;
  }

  OdGePoint3d position() const { return m_position; }
  void setPosition(const OdGePoint3d& pos) { m_position = pos; }

  OdGePoint3d target() const { return m_target; }
  void setTarget(const OdGePoint3d& trg) { m_target = trg; }

  OdGiLightAttenuation attenuation() const { return m_attenuation; }
  void setAttenuation(const OdGiLightAttenuation& atten) { m_attenuation = atten; }

  bool setHotspotAndFalloff(double hotSpot, double falloff);
  double hotspot() const { return m_dHotspot; }
  double falloff() const { return m_dFalloff; }

  double physicalIntensity() const { return m_dPhysIntensity; }
  void setPhysicalIntensity(double intensity) { m_dPhysIntensity = intensity; }

  OdGiColorRGB lampColor() const { return m_lampColor; }
  void setLampColor(const OdGiColorRGB& color) { m_lampColor = color; }

  TD_USING(OdGiLightTraitsData::shadowParameters);
  void shadowParameters(OdGiShadowParameters2 &sp) const { sp = m_shadowParameters; }
  TD_USING(OdGiLightTraitsData::setShadowParameters);
  void setShadowParameters(const OdGiShadowParameters2 &sp) { m_shadowParameters = sp; }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
inline bool OdGiSpotLightTraitsData::setHotspotAndFalloff(double hotspot, double falloff)
{ 
  if((hotspot > falloff) || 
     (hotspot < 0.0) || (falloff < 0.0) || 
     (OdaToDegree(hotspot) > 160.0) || (OdaToDegree(falloff) > 160.0))
    return false;
  m_dHotspot = hotspot;
  m_dFalloff = falloff; 
  return true;
}

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiDistantLightTraitsData : public OdGiLightTraitsData
{
  OdGeVector3d m_direction;
  // Photometric data
  double       m_dPhysIntensity;
  OdGiColorRGB m_lampColor;
  //OdGiSkyParameters m_skyParams; // Unused
  bool         m_bIsSunlight;
public:
  OdGiDistantLightTraitsData()
    : m_bIsSunlight(false)
    , m_dPhysIntensity(1500.0)
    , m_lampColor(1.0, 1.0, 1.0)
  {
    m_type = OdGiDrawable::kDistantLight;
  }

  OdGeVector3d direction() const { return m_direction; }
  void setDirection(const OdGeVector3d& dir) { m_direction = dir; }

  bool isSunlight() const { return m_bIsSunlight; }
  void setSunlight(bool val) { m_bIsSunlight = val; }

  double physicalIntensity() const { return m_dPhysIntensity; }
  void setPhysicalIntensity(double intensity) { m_dPhysIntensity = intensity; }

  OdGiColorRGB lampColor() const { return m_lampColor; }
  void setLampColor(const OdGiColorRGB& color) { m_lampColor = color; }

  TD_USING(OdGiLightTraitsData::shadowParameters);
  void shadowParameters(OdGiShadowParameters2 &sp) const { sp = m_shadowParameters; }
  TD_USING(OdGiLightTraitsData::setShadowParameters);
  void setShadowParameters(const OdGiShadowParameters2 &sp) { m_shadowParameters = sp; }

  void skyParameters(OdGiSkyParameters & /*params*/) const { /*params = m_skyParams;*/ }
  void setSkyParameters(const OdGiSkyParameters & /*params*/) { /*m_skyParams = params;*/ }
};

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiWebLightTraitsData : public OdGiPointLightTraitsData
{
  OdString                        m_webFile;
  OdGeVector3d                    m_webRotate;
  double                          m_dFlux;
  OdGiWebLightTraits::WebFileType m_webFileType;
  OdGiWebLightTraits::WebSymmetry m_webSymmetry;
  bool                            m_bHorzAng90to270;

public:
  OdGiWebLightTraitsData()
    : OdGiPointLightTraitsData()
    , m_dFlux(0.0)
    , m_webFileType(OdGiWebLightTraits::kTypeA)
    , m_webSymmetry(OdGiWebLightTraits::kNoSymmetry)
    , m_bHorzAng90to270(false)
  {
    m_type = OdGiDrawable::kWebLight;
  }

  OdString webFile() const { return m_webFile; }
  void setWebFile(const OdString &fileName) { m_webFile = fileName; }

  OdGeVector3d webRotation() const { return m_webRotate; }
  void setWebRotation(OdGeVector3d rot) { m_webRotate = rot; }

  double webFlux() const { return m_dFlux; }
  void setWebFlux(double flux) { m_dFlux = flux; }

  OdGiWebLightTraits::WebFileType webFileType() const { return m_webFileType; }
  void setWebFileType(OdGiWebLightTraits::WebFileType type) { m_webFileType = type; }

  OdGiWebLightTraits::WebSymmetry webSymmetry() const { return m_webSymmetry; }
  void setWebSymmetry(OdGiWebLightTraits::WebSymmetry sym) { m_webSymmetry = sym; }

  bool webHorzAng90to270() const { return m_bHorzAng90to270; }
  void setWebHorzAng90to270(bool bHA) { m_bHorzAng90to270 = bHA; }
};

inline void OdGiLightTraitsData::deleteLightTraitsData(OdGiLightTraitsData* pLightTraits)
{
  switch(pLightTraits->type())
  {
  case OdGiDrawable::kDistantLight:
    delete static_cast<OdGiDistantLightTraitsData*>(pLightTraits);
    break;
  case OdGiDrawable::kPointLight:
    delete static_cast<OdGiPointLightTraitsData*>(pLightTraits);
    break;
  case OdGiDrawable::kSpotLight:
    delete static_cast<OdGiSpotLightTraitsData*>(pLightTraits);
    break;
  case OdGiDrawable::kWebLight:
    delete static_cast<OdGiWebLightTraitsData*>(pLightTraits);
    break;
  default:
    {
      ODA_FAIL_ONCE();
    }
    break;
  }
}

#include "../TD_PackPop.h"

#endif // __OD_GI_LIGHT_TRAITS_DATA__
