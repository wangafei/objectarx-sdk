/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcGiEnvironment.h"

class GCBASE_PORT GcGiViewportTraits : public GcGiDrawableTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiViewportTraits);

  virtual void setBackground(const GcDbObjectId backgroundId) = 0;
  virtual GcDbObjectId        background() const = 0;

  enum DefaultLightingType {
    kOneDistantLight = 0,
    kTwoDistantLights,
    kBackLighting,
  };
  virtual bool isDefaultLightingOn() const = 0;
  virtual void setDefaultLightingOn(bool on) = 0;
  virtual DefaultLightingType defaultLightingType() const = 0;
  virtual void setDefaultLightingType(DefaultLightingType typ) = 0;

  virtual void setAmbientLightColor(const GcCmColor& clr) = 0;
  virtual GcCmColor ambientLightColor() const = 0;

  virtual void setBrightness(double brightness) = 0;
  virtual double brightness() const = 0;

  virtual void setContrast(double contrast) = 0;
  virtual double contrast() const = 0;

  virtual void setRenderEnvironment(const GcDbObjectId renderEnvId) = 0;
  virtual GcDbObjectId renderEnvironment() const = 0;

  virtual void setRenderSettings(const GcDbObjectId renderSettingsId) = 0;
  virtual GcDbObjectId renderSettings() const = 0;

  virtual void setToneOperatorParameters(const GcGiToneOperatorParameters& params) = 0;
  virtual void toneOperatorParameters(GcGiToneOperatorParameters& params) const = 0;
};