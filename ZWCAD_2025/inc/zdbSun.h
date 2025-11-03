
#pragma once

#include "zdbmain.h"
#pragma warning( disable: 4275 4251 )

#ifdef SCENEOE
#define DLLIMPEXP __declspec(dllexport)
#else

#define DLLIMPEXP
#endif

#include "zAcGiLightTraits.h"
#include "zrxboiler.h"
#include "zdbLight.h"

class ZcDbImpSun;

class LIGHTDLLIMPEXP ZcDbSun : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSun);
private:
    static ZSoft::UInt32 kCurrentVersionNumber;
public:
    ZcDbSun();
    ~ZcDbSun();
    virtual ZcGiDrawable* drawable() override;
    virtual DrawableType  drawableType() const override { return ZcGiDrawable::kDistantLight; }
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler *pFiler) const override;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler *pFiler) override;

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler *pFiler) const override;

    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler *pFiler) override;

    virtual Zcad::ErrorStatus decomposeForSave(
            ZcDb::ZcDbDwgVersion ver,
            ZcDbObject*& replaceObj,
            ZcDbObjectId& replaceId,
            ZSoft::Boolean& exchangeXData) override;
    virtual bool isOn() const;
    virtual Zcad::ErrorStatus setOn(bool value);
    virtual double intensity() const;
    virtual Zcad::ErrorStatus setIntensity(double intensity);
    virtual const ZcCmColor& sunColor() const;
    virtual Zcad::ErrorStatus setSunColor(const ZcCmColor& color);

    virtual const ZcGiColorRGB& sunColorPhotometric(const double multiplier);

    virtual const ZcGiShadowParameters& shadowParameters() const;
    virtual void setShadowParameters(const ZcGiShadowParameters& params);
    virtual Zcad::ErrorStatus setDateTime(const ZcDbDate& datetime);
    virtual const ZcDbDate& dateTime() const;
    virtual Zcad::ErrorStatus setDayLightSavingsOn(bool value);
    virtual bool isDayLightSavingsOn() const;
    virtual Zcad::ErrorStatus setAzimuth(double azimuth);
    virtual double azimuth() const;
    virtual Zcad::ErrorStatus setAltitude(double altitude);
    virtual double altitude() const;
    virtual const ZcGeVector3d& sunDirection() const;
    virtual void setSunDirection(const ZcGeVector3d& sundir);
    Zcad::ErrorStatus setSkyParameters(const ZcGiSkyParameters& params);
    Zcad::ErrorStatus skyParameters(ZcGiSkyParameters& params) const;
    
protected:
    
    virtual ZSoft::UInt32 subSetAttributes(ZcGiDrawableTraits* pTraits) override;

private:
    ZcDbImpSun * mpZcDbImpSun;
};
