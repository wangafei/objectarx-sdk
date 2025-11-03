/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbmain.h"
#include "dbents.h"
#pragma warning( disable: 4275 4251 )
#ifdef SCENEOE
#define LIGHTDLLIMPEXP __declspec(dllexport)
#else
#define LIGHTDLLIMPEXP
#endif

#include "GcGiLightTraits.h"

class GcDbImpLight;

class GCDB_PORT GcDbLight : public GcDbEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcDbLight);

private:
  static Gsoft::UInt32 kCurrentVersionNumber;
public:
  GcDbLight();
  ~GcDbLight();

  Gcad::ErrorStatus subClose() override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler *pFiler) const override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler *pFiler) override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus decomposeForSave(
    GcDb::GcDbDwgVersion ver,
    GcDbObject*& replaceObj,
    GcDbObjectId& replaceId,
    Gsoft::Boolean& exchangeXData) override;

  GcGiDrawable::DrawableType    drawableType() const override;
  bool castShadows() const override;
  void setCastShadows(bool newVal) override;
  bool receiveShadows() const override;
  void setReceiveShadows(bool newVal) override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;
  virtual const GcString& name() const;
  virtual Gcad::ErrorStatus setName(const GcString & name);
  virtual GcGiDrawable::DrawableType lightType() const;
  virtual Gcad::ErrorStatus setLightType(GcGiDrawable::DrawableType type);

  virtual  bool isOn() const;
  virtual Gcad::ErrorStatus setOn(bool value);
  virtual bool isPlottable() const;
  virtual Gcad::ErrorStatus setIsPlottable(bool plot);
  virtual const GcCmColor& lightColor() const;
  virtual Gcad::ErrorStatus setLightColor(const GcCmColor& color);
  virtual double intensity() const;
  virtual Gcad::ErrorStatus setIntensity(double intensity);
  virtual void setLightAttenuation(const GcGiLightAttenuation& params);
  virtual const GcGiLightAttenuation& lightAttenuation() const;
  virtual Gcad::ErrorStatus setPosition(const GcGePoint3d& pos);
  virtual const GcGePoint3d& position() const;
  virtual const GcGePoint3d& targetLocation() const;
  virtual Gcad::ErrorStatus setTargetLocation(const GcGePoint3d& newVal);
  virtual Gcad::ErrorStatus setHotspotAndFalloff(double hotspot, double falloff);
  virtual double hotspotAngle() const;
  virtual double falloffAngle() const;
  virtual const GcGeVector3d& lightDirection() const;
  virtual Gcad::ErrorStatus setLightDirection(const GcGeVector3d& lightvec);

  enum PhysicalIntensityMethod {
    kPeakIntensity = 0,
    kFlux,
    kIlluminance
  };

  GcDbLight::PhysicalIntensityMethod physicalIntensityMethod() const;
  Gcad::ErrorStatus setPhysicalIntensityMethod(GcDbLight::PhysicalIntensityMethod method);
  double physicalIntensity() const;
  Gcad::ErrorStatus setPhysicalIntensity(double physicalIntensity);
  double illuminanceDistance() const;
  Gcad::ErrorStatus setIlluminanceDistance(double distance);

  enum LampColorType {
    kKelvin = 0,
    kPreset
  };

  GcDbLight::LampColorType lampColorType() const;
  Gcad::ErrorStatus setLampColorType(GcDbLight::LampColorType colorType);
  double lampColorTemp() const;
  Gcad::ErrorStatus setLampColorTemp(double colorTemp);

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

  GcDbLight::LampColorPreset lampColorPreset() const;
  Gcad::ErrorStatus setLampColorPreset(GcDbLight::LampColorPreset colorPreset);
  Gcad::ErrorStatus lampColorRGB(GcGiColorRGB& rgbColor) const;
  Gcad::ErrorStatus setLampColorRGB(GcGiColorRGB rgbColor);
  Gcad::ErrorStatus resultingColor(GcCmColor& rgbColor) const;
  Gcad::ErrorStatus webFile(GcString& webFile) const;
  Gcad::ErrorStatus setWebFile(const GCHAR* webFile);
  Gcad::ErrorStatus webRotation(GcGeVector3d& rotation) const;
  Gcad::ErrorStatus setWebRotation(GcGeVector3d rotation);
  bool hasTarget() const;
  Gcad::ErrorStatus setHasTarget(bool hasTarget);
  Gcad::ErrorStatus shadowParameters(GcGiShadowParameters& params) const;
  Gcad::ErrorStatus setShadowParameters(const GcGiShadowParameters& params);

  enum GlyphDisplayType {
    kGlyphDisplayAuto = 0,
    kGlyphDisplayOn,
    kGlyphDisplayOff
  };

  GlyphDisplayType glyphDisplay() const;
  Gcad::ErrorStatus setGlyphDisplay(GlyphDisplayType type);

protected:
  void subViewportDraw(GcGiViewportDraw *mode) override;
  Gsoft::Boolean subWorldDraw(GcGiWorldDraw *mode) override;
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;
  Gcad::ErrorStatus   subGetOsnapPoints(
    GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds) const override;

  Gcad::ErrorStatus   subGetOsnapPoints(
    GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds,
    const GcGeMatrix3d& insertionMat) const override;
  Gcad::ErrorStatus subTransformBy(const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus subGetTransformedCopy(const GcGeMatrix3d & xform, GcDbEntity *& pEnt) const override;
  void subList() const override;
  Gcad::ErrorStatus subGetGripPoints(GcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, const GcGeVector3d &curViewDir, const int bitflags) const override;
  Gcad::ErrorStatus subMoveGripPointsAt(const GcDbVoidPtrArray &gripAppData, const GcGeVector3d &offset, const int bitflags) override;
  Gcad::ErrorStatus subDeepClone(GcDbObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
  Gcad::ErrorStatus subWblockClone(GcRxObject* pOwnerObject, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary) const override;
  Gcad::ErrorStatus subHighlight(const GcDbFullSubentPath& subId,
    const Gsoft::Boolean highlightAll) const override;
  Gcad::ErrorStatus subUnhighlight(const GcDbFullSubentPath& subId,
    const Gsoft::Boolean highlightAll) const override;
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
  Gcad::ErrorStatus subGetGeomExtents(GcDbExtents& extents) const override;
private:
  friend class GcDbImpLight;
  Gsoft::UInt32     baseSetAttributes(GcGiDrawableTraits* pTraits);
  Gcad::ErrorStatus baseDeepClone(GcDbObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary) const;
  Gcad::ErrorStatus baseWblockClone(GcRxObject* pOwnerObject, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary) const;
  Gcad::ErrorStatus baseHighlight(const GcDbFullSubentPath& subId,
    const Gsoft::Boolean highlightAll) const;
  Gcad::ErrorStatus baseUnhighlight(const GcDbFullSubentPath& subId,
    const Gsoft::Boolean highlightAll) const;

  GcDbImpLight * mpGcDbImpLight;
  bool mSelected;
};