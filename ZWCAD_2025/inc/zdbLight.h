
#pragma once

#include "zdbmain.h"
#include "zdbents.h"

#pragma warning( disable: 4275 4251 )

#ifdef SCENEOE
#define LIGHTDLLIMPEXP __declspec(dllexport)
#else
#define LIGHTDLLIMPEXP
#endif

#include "zAcGiLightTraits.h"

class ZcDbImpLight;

class LIGHTDLLIMPEXP ZcDbLight : public ZcDbEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLight);

private:
    static ZSoft::UInt32 kCurrentVersionNumber ;
public:
    ZcDbLight ();
    ~ZcDbLight();

    virtual Zcad::ErrorStatus subClose() override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler *pFiler) const override;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler *pFiler) override;

	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus decomposeForSave(
            ZcDb::ZcDbDwgVersion ver,
            ZcDbObject*& replaceObj,
            ZcDbObjectId& replaceId,
            ZSoft::Boolean& exchangeXData) override;

    virtual ZcGiDrawable::DrawableType    drawableType() const override;
    virtual bool castShadows() const override;
    virtual void setCastShadows(bool newVal) override;
    virtual bool receiveShadows() const override;
    virtual void setReceiveShadows(bool newVal) override;

	virtual Zcad::ErrorStatus copyFrom (const ZcRxObject* other) override;
	virtual const ZcString& name() const;

	virtual Zcad::ErrorStatus setName(const ZcString & name);

	virtual ZcGiDrawable::DrawableType lightType() const;

	virtual Zcad::ErrorStatus setLightType(ZcGiDrawable::DrawableType type);

    virtual  bool isOn() const;
    virtual Zcad::ErrorStatus setOn(bool value);
    virtual bool isPlottable() const;
    virtual Zcad::ErrorStatus setIsPlottable(bool plot);
    virtual const ZcCmColor& lightColor() const;
    virtual Zcad::ErrorStatus setLightColor(const ZcCmColor& color);
    virtual double intensity() const;
    virtual Zcad::ErrorStatus setIntensity(double intensity);
    virtual void setLightAttenuation(const ZcGiLightAttenuation& params);
    virtual const ZcGiLightAttenuation& lightAttenuation() const;
    virtual Zcad::ErrorStatus setPosition(const ZcGePoint3d& pos);
    virtual const ZcGePoint3d& position() const;
    virtual const ZcGePoint3d& targetLocation() const;
    virtual Zcad::ErrorStatus setTargetLocation(const ZcGePoint3d& newVal);
    virtual Zcad::ErrorStatus setHotspotAndFalloff(double hotspot, double falloff);
    virtual double hotspotAngle() const;
    virtual double falloffAngle() const;
    virtual const ZcGeVector3d& lightDirection() const;
    virtual Zcad::ErrorStatus setLightDirection(const ZcGeVector3d& lightvec);

    enum PhysicalIntensityMethod {
        kPeakIntensity = 0,
        kFlux,
        kIlluminance
    };

    ZcDbLight::PhysicalIntensityMethod physicalIntensityMethod() const;
    Zcad::ErrorStatus setPhysicalIntensityMethod(ZcDbLight::PhysicalIntensityMethod method);
    double physicalIntensity() const;
    Zcad::ErrorStatus setPhysicalIntensity(double physicalIntensity);
    double illuminanceDistance() const;
    Zcad::ErrorStatus setIlluminanceDistance(double distance);

    enum LampColorType {
        kKelvin = 0,
        kPreset
    };

    ZcDbLight::LampColorType lampColorType() const;
    Zcad::ErrorStatus setLampColorType(ZcDbLight::LampColorType colorType);
    double lampColorTemp() const;
    Zcad::ErrorStatus setLampColorTemp(double colorTemp);

    enum LampColorPreset {
        kD65White = 0,
        kFluorescent,
        kCoolWhite,
        kWhiteFluorescent,
        kDaylightFluorescent,
        kIncandescent,
        kXenon,
        kHalogen,
        kQuartz,
        kMetalHalide,
        kMercury,
        kPhosphorMercury,
        kHighPressureSodium,
        kLowPressureSodium,
        kCustom
    };

    ZcDbLight::LampColorPreset lampColorPreset() const;
    Zcad::ErrorStatus setLampColorPreset(ZcDbLight::LampColorPreset colorPreset);
    Zcad::ErrorStatus lampColorRGB(ZcGiColorRGB& rgbColor) const;
    Zcad::ErrorStatus setLampColorRGB(ZcGiColorRGB rgbColor);
    Zcad::ErrorStatus resultingColor(ZcCmColor& rgbColor) const;
    Zcad::ErrorStatus webFile(ZcString& webFile) const;
    Zcad::ErrorStatus setWebFile(const ZTCHAR* webFile);
    Zcad::ErrorStatus webRotation(ZcGeVector3d& rotation) const;
    Zcad::ErrorStatus setWebRotation(ZcGeVector3d rotation);
    bool hasTarget() const;
    Zcad::ErrorStatus setHasTarget(bool hasTarget);
    Zcad::ErrorStatus shadowParameters(ZcGiShadowParameters& params) const;
    Zcad::ErrorStatus setShadowParameters(const ZcGiShadowParameters& params);

	enum GlyphDisplayType {
		kGlyphDisplayAuto = 0,
		kGlyphDisplayOn,
		kGlyphDisplayOff
	};

	GlyphDisplayType glyphDisplay() const;		

	Zcad::ErrorStatus setGlyphDisplay(GlyphDisplayType type);	

protected:
    virtual void subViewportDraw (ZcGiViewportDraw *mode) override ;
    virtual ZSoft::Boolean subWorldDraw (ZcGiWorldDraw *mode) override;
    virtual ZSoft::UInt32  subSetAttributes(ZcGiDrawableTraits* pTraits) override;

    virtual Zcad::ErrorStatus   subGetOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray &   geomIds) const override;

    virtual Zcad::ErrorStatus   subGetOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray &   geomIds,
                                 const ZcGeMatrix3d& insertionMat) const override;

	virtual Zcad::ErrorStatus subTransformBy(const ZcGeMatrix3d& xform) override;
	virtual Zcad::ErrorStatus subGetTransformedCopy(const ZcGeMatrix3d & xform,ZcDbEntity *& pEnt) const override;

	virtual void subList() const override;	

    virtual Zcad::ErrorStatus subGetGripPoints (ZcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, const ZcGeVector3d &curViewDir, const int bitflags) const ;
  
	virtual Zcad::ErrorStatus subMoveGripPointsAt (const ZcDbVoidPtrArray &gripAppData, const ZcGeVector3d &offset, const int bitflags) ;

    virtual Zcad::ErrorStatus subDeepClone(ZcDbObject* pOwner,ZcDbObject*& pClonedObject,
                                        ZcDbIdMapping& idMap,ZSoft::Boolean isPrimary = true) const override;

    virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwnerObject, ZcDbObject*& pClonedObject,
                                        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary ) const override;

	virtual Zcad::ErrorStatus subHighlight(const ZcDbFullSubentPath& subId, 
		const ZSoft::Boolean highlightAll) const override;	

	virtual Zcad::ErrorStatus subUnhighlight(const ZcDbFullSubentPath& subId, 
		const ZSoft::Boolean highlightAll) const override;	

	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
	virtual Zcad::ErrorStatus subGetGeomExtents(ZcDbExtents& extents) const override;

private:
    friend class ZcDbImpLight;
	
	ZSoft::UInt32 baseSetAttributes(ZcGiDrawableTraits* pTraits);
	Zcad::ErrorStatus baseDeepClone(ZcDbObject* pOwner,ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,ZSoft::Boolean isPrimary) const;
	Zcad::ErrorStatus baseWblockClone(ZcRxObject* pOwnerObject, ZcDbObject*& pClonedObject, 
		ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary) const;
	Zcad::ErrorStatus baseHighlight(const ZcDbFullSubentPath& subId, 
		const ZSoft::Boolean highlightAll) const;
	Zcad::ErrorStatus baseUnhighlight(const ZcDbFullSubentPath& subId, 
		const ZSoft::Boolean highlightAll) const;
	

    ZcDbImpLight * mpZcDbImpLight;
    bool mSelected;
};
