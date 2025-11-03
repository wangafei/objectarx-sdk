/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "gcgimaterial.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbMaterial : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbMaterial);

  GcDbMaterial();
  ~GcDbMaterial();

  virtual Gcad::ErrorStatus   setName(const GCHAR * pName);
  virtual const GCHAR *       name(void) const;

  virtual Gcad::ErrorStatus   setDescription(const GCHAR * pDescription);
  virtual const GCHAR *       description(void) const;

  virtual void setAmbient(const GcGiMaterialColor & color);
  virtual void ambient(GcGiMaterialColor & color) const;

  virtual void setDiffuse(const GcGiMaterialColor & color, const GcGiMaterialMap & map);
  virtual void diffuse(GcGiMaterialColor & color, GcGiMaterialMap & map) const;

  virtual void setSpecular(const GcGiMaterialColor & color,
    const GcGiMaterialMap & map,
    double dGloss);
  virtual void specular(GcGiMaterialColor & color,
    GcGiMaterialMap & map,
    double & dGloss) const;

  virtual void setReflection(const GcGiMaterialMap & map);
  virtual void reflection(GcGiMaterialMap & map) const;

  virtual void setOpacity(double dPercentage, const GcGiMaterialMap & map);
  virtual void opacity(double & dPercentage, GcGiMaterialMap & map) const;

  virtual void setBump(const GcGiMaterialMap & map);
  virtual void bump(GcGiMaterialMap & map) const;

  virtual void setRefraction(double dIndex, const GcGiMaterialMap & map);
  virtual void refraction(double & dIndex, GcGiMaterialMap & map) const;

  virtual double translucence() const;
  virtual Gcad::ErrorStatus setTranslucence(double value);

  virtual double selfIllumination() const;
  virtual Gcad::ErrorStatus setSelfIllumination(double value);

  virtual double reflectivity() const;
  virtual Gcad::ErrorStatus setReflectivity(double value);

  virtual GcGiMaterialTraits::IlluminationModel illuminationModel() const;
  virtual Gcad::ErrorStatus setIlluminationModel(GcGiMaterialTraits::IlluminationModel model);

  virtual GcGiMaterialTraits::ChannelFlags channelFlags() const;
  virtual Gcad::ErrorStatus setChannelFlags(GcGiMaterialTraits::ChannelFlags value);

  virtual GcGiMaterialTraits::Mode mode() const;
  virtual Gcad::ErrorStatus setMode(GcGiMaterialTraits::Mode value);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  GcGiDrawable*     drawable(void) override;

  double              colorBleedScale() const;
  Gcad::ErrorStatus   setColorBleedScale(double value);
  double              indirectBumpScale() const;
  Gcad::ErrorStatus   setIndirectBumpScale(double value);
  double              reflectanceScale() const;
  Gcad::ErrorStatus   setReflectanceScale(double value);
  double              transmittanceScale() const;
  Gcad::ErrorStatus   setTransmittanceScale(double value);
  Gsoft::Boolean      twoSided() const;
  Gcad::ErrorStatus   setTwoSided(Gsoft::Boolean value);
  GcGiMaterialTraits::LuminanceMode luminanceMode() const;
  Gcad::ErrorStatus   setLuminanceMode(GcGiMaterialTraits::LuminanceMode value);
  double              luminance() const;
  Gcad::ErrorStatus   setLuminance(double value);
  double              shininess() const;
  Gcad::ErrorStatus   setShininess(double value);
  Gcad::ErrorStatus   normalMap(GcGiMaterialMap & map,
    GcGiMaterialTraits::NormalMapMethod & method,
    double & strength) const;
  Gcad::ErrorStatus   setNormalMap(const GcGiMaterialMap & map,
    GcGiMaterialTraits::NormalMapMethod method,
    double strength);
  Gsoft::Boolean      isAnonymous() const;
  Gcad::ErrorStatus   setAnonymous(Gsoft::Boolean isAnonymous);
  GcGiMaterialTraits::GlobalIlluminationMode globalIllumination() const;
  void                setGlobalIllumination(GcGiMaterialTraits::GlobalIlluminationMode mode);
  GcGiMaterialTraits::FinalGatherMode        finalGather() const;
  void                setFinalGather(GcGiMaterialTraits::FinalGatherMode mode);
  bool                isRenamable() const;

  void* getGsftMaterialData();
  Gcad::ErrorStatus setGsftMaterialData(const void* pMatObj, bool bCacheIt = false);
  void clearGsftMaterialCache();

  enum MaterialFlags {
    kNone = 0,
    kIsLegacy = 0x1,
    kIsModifiedIsValid = 0x2,
    kIsModified = 0x4,
    kIsModifiedAndValid = 0x6
  };

  Gcad::ErrorStatus getGsftMaterialFlags(MaterialFlags& flags) const;
  Gcad::ErrorStatus setGsftMaterialFlags(MaterialFlags flags);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)