/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#pragma warning( disable: 4275 4251 )

#ifdef SCENEOE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

#include "GcGiLightTraits.h"
#include "rxboiler.h"
#include "dbLight.h"

class GcDbImpSun;

class GCDB_PORT GcDbSun : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSun);
private:
  static Gsoft::UInt32 kCurrentVersionNumber;
public:
  GcDbSun();
  ~GcDbSun();

  GcGiDrawable* drawable() override;
  DrawableType  drawableType() const override { return GcGiDrawable::kDistantLight; }

  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler *pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler *pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler *pFiler) const override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler *pFiler) override;

  Gcad::ErrorStatus decomposeForSave(
    GcDb::GcDbDwgVersion ver,
    GcDbObject*& replaceObj,
    GcDbObjectId& replaceId,
    Gsoft::Boolean& exchangeXData) override;

  virtual bool isOn() const;
  virtual Gcad::ErrorStatus setOn(bool value);

  virtual double intensity() const;
  virtual Gcad::ErrorStatus setIntensity(double intensity);

  virtual const GcCmColor& sunColor() const;
  virtual Gcad::ErrorStatus setSunColor(const GcCmColor& color);

  virtual const GcGiColorRGB& sunColorPhotometric(const double multiplier);
  virtual const GcGiShadowParameters& shadowParameters() const;
  virtual void setShadowParameters(const GcGiShadowParameters& params);

  virtual Gcad::ErrorStatus setDateTime(const GcDbDate& datetime);
  virtual const GcDbDate& dateTime() const;

  virtual Gcad::ErrorStatus setDayLightSavingsOn(bool value);
  virtual bool isDayLightSavingsOn() const;

  virtual Gcad::ErrorStatus setAzimuth(double azimuth);
  virtual double azimuth() const;

  virtual Gcad::ErrorStatus setAltitude(double altitude);
  virtual double altitude() const;

  virtual const GcGeVector3d& sunDirection() const;
  virtual void setSunDirection(const GcGeVector3d& sundir);

  Gcad::ErrorStatus setSkyParameters(const GcGiSkyParameters& params);
  Gcad::ErrorStatus skyParameters(GcGiSkyParameters& params) const;

protected:
  Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  GcDbImpSun * mpGcDbImpSun;
};