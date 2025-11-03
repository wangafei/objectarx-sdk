/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GdGChar.h"
#include "gcgi.h"
#pragma pack (push, 8)

#if defined(__linux__)
#ifdef GCGIMATERIAL_IMPL
#define GCGIMAT_IMPEXP __attribute__ ((__visibility__("default")))
#else
#define GCGIMAT_IMPEXP 
#endif
#else
#ifdef GCGIMATERIAL_IMPL
#define GCGIMAT_IMPEXP __declspec(dllexport)
#else
#define GCGIMAT_IMPEXP __declspec(dllimport)
#endif
#endif

class GcGiMaterialColor;
class GcGiMaterialMap;

class GCGIMAT_IMPEXP GcGiMaterialTraits : public GcGiNonEntityTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiMaterialTraits);

  enum IlluminationModel {
    kBlinnShader = 0,
    kMetalShader,
  };

  enum ChannelFlags
  {
    kNone = 0x00000,
    kUseDiffuse = 0x00001,
    kUseSpecular = 0x00002,
    kUseReflection = 0x00004,
    kUseOpacity = 0x00008,
    kUseBump = 0x00010,
    kUseRefraction = 0x00020,
    kUseNormalMap = 0x00040,
    kUseAll = (kUseDiffuse | kUseSpecular | kUseReflection
               | kUseOpacity | kUseBump | kUseRefraction
               | kUseNormalMap),
  };

  enum Mode {
    kRealistic = 0,
    kAdvanced,
  };

  enum LuminanceMode
  {
    kSelfIllumination = 0,
    kLuminance,
  };

  enum NormalMapMethod
  {
    kTangentSpace
  };

  enum GlobalIlluminationMode
  {
    kGlobalIlluminationNone,
    kGlobalIlluminationCast,
    kGlobalIlluminationReceive,
    kGlobalIlluminationCastAndReceive
  };

  enum FinalGatherMode
  {
    kFinalGatherNone,
    kFinalGatherCast,
    kFinalGatherReceive,
    kFinalGatherCastAndReceive
  };

  virtual void setAmbient(const GcGiMaterialColor & color) = 0;
  virtual void setDiffuse(const GcGiMaterialColor & color,
    const GcGiMaterialMap & map) = 0;
  virtual void setSpecular(const GcGiMaterialColor & color,
    const GcGiMaterialMap & map,
    double dGloss) = 0;
  virtual void setReflection(const GcGiMaterialMap & map) = 0;
  virtual void setOpacity(double dPercentage,
    const GcGiMaterialMap & map) = 0;
  virtual void setBump(const GcGiMaterialMap & map) = 0;
  virtual void setRefraction(double dIndex,
    const GcGiMaterialMap & map) = 0;
  virtual void setTranslucence(double value) = 0;
  virtual void setSelfIllumination(double value) = 0;
  virtual void setReflectivity(double value) = 0;
  virtual void setIlluminationModel(IlluminationModel model) = 0;
  virtual void setChannelFlags(ChannelFlags flags) = 0;
  virtual void setMode(Mode value) = 0;
  virtual void ambient(GcGiMaterialColor & color) const = 0;
  virtual void diffuse(GcGiMaterialColor & color,
    GcGiMaterialMap & map) const = 0;
  virtual void specular(GcGiMaterialColor & color,
    GcGiMaterialMap & map,
    double & dGloss) const = 0;
  virtual void reflection(GcGiMaterialMap & map) const = 0;
  virtual void opacity(double & dPercentage,
    GcGiMaterialMap & map) const = 0;
  virtual void bump(GcGiMaterialMap & map) const = 0;
  virtual void refraction(double & dIndex,
    GcGiMaterialMap & map) const = 0;
  virtual double translucence() const = 0;
  virtual double selfIllumination() const = 0;
  virtual double reflectivity() const = 0;
  virtual IlluminationModel illuminationModel() const = 0;
  virtual ChannelFlags channelFlags() const = 0;
  virtual Mode mode() const = 0;

  virtual void setColorBleedScale(double value) = 0;
  virtual void setIndirectBumpScale(double value) = 0;
  virtual void setReflectanceScale(double value) = 0;
  virtual void setTransmittanceScale(double value) = 0;
  virtual void setTwoSided(bool value) = 0;
  virtual void setLuminanceMode(LuminanceMode value) = 0;
  virtual void setLuminance(double value) = 0;
  virtual void setNormalMap(const GcGiMaterialMap & map,
    NormalMapMethod method,
    double strength) = 0;
  virtual void setGlobalIllumination(GlobalIlluminationMode mode) = 0;
  virtual void setFinalGather(FinalGatherMode mode) = 0;

  virtual double colorBleedScale() const = 0;
  virtual double indirectBumpScale() const = 0;
  virtual double reflectanceScale() const = 0;
  virtual double transmittanceScale() const = 0;
  virtual bool   twoSided() const = 0;
  virtual LuminanceMode luminanceMode() const = 0;
  virtual double luminance() const = 0;
  virtual void normalMap(GcGiMaterialMap & map,
    NormalMapMethod &method,
    double &strength) const = 0;
  virtual GlobalIlluminationMode globalIllumination() const = 0;
  virtual FinalGatherMode finalGather() const = 0;
};

class GcGiImpMaterialColor;

class GCGIMAT_IMPEXP GcGiMaterialColor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiMaterialColor);

  enum Method {
    kInherit = 0,
    kOverride,
  };

  static const GcGiMaterialColor kNull;

  GcGiMaterialColor(void);
  ~GcGiMaterialColor(void);

  GcGiMaterialColor(const GcGiMaterialColor &matColor);
  GcGiMaterialColor & operator= (const GcGiMaterialColor &matColor);
  bool                operator==(const GcGiMaterialColor &matColor)const;

  virtual void set(const GcGiMaterialColor &matColor);
  virtual void setMethod(Method method);
  virtual void setFactor(double dFactor);
  virtual void setColor(const GcCmEntityColor& color);

  virtual Method                  method(void) const;
  virtual double                  factor(void) const;
  virtual const GcCmEntityColor & color(void) const;

private:
  GcGiImpMaterialColor * mpGcGiImpMaterialColor;
};

class GCGIMAT_IMPEXP GcGiMaterialTexture : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiMaterialTexture);
  virtual bool operator==(const GcGiMaterialTexture & texture)const;
protected:
};

inline bool GcGiMaterialTexture::operator==(const GcGiMaterialTexture & texture) const {
  return (texture.isA() == isA());
}

class GCGIMAT_IMPEXP GcGiImageTexture : public GcGiMaterialTexture
{
public:
  GCRX_DECLARE_MEMBERS(GcGiImageTexture);
};

class GcGiImpImageFileTexture;

class GCGIMAT_IMPEXP GcGiImageFileTexture : public GcGiImageTexture
{
  friend class GcGiImpImageFileTexture;
public:
  GCRX_DECLARE_MEMBERS(GcGiImageFileTexture);

  GcGiImageFileTexture(void);
  ~GcGiImageFileTexture(void);
  GcGiImageFileTexture(const GcGiImageFileTexture &texture);

  GcGiImageFileTexture & operator= (const GcGiImageFileTexture &texture);
  bool                   operator==(const GcGiMaterialTexture & texture) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  virtual void                setSourceFileName(const GCHAR * fileName);
  virtual const GCHAR *       sourceFileName(void) const;
private:
  GcGiImpImageFileTexture * mpGcGiImpImageFileTexture;
};

class GCGIMAT_IMPEXP GcGiProceduralTexture : public GcGiMaterialTexture
{
public:
  GCRX_DECLARE_MEMBERS(GcGiProceduralTexture);

  enum Type
  {
    kWood = 0,
    kMarble,
    kGeneric,
  };
};

class GCGIMAT_IMPEXP GcGiGenericTexture : public GcGiProceduralTexture
{
public:
  GCRX_DECLARE_MEMBERS(GcGiGenericTexture);

  GcGiGenericTexture(void);
  ~GcGiGenericTexture(void);
  GcGiGenericTexture(const GcGiGenericTexture &texture);

  GcGiGenericTexture & operator=  (const GcGiGenericTexture &texture);
  bool                 operator== (const GcGiMaterialTexture &texture) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  void            setDefinition(const GcGiVariant& definition);
  GcGiVariant     definition(void) const;
  void            definition(GcGiVariant*& pDefinition);

protected:
  GcGiVariant     m_definition;
};

class GcGiImpWoodTexture;

class GCGIMAT_IMPEXP GcGiWoodTexture : public GcGiProceduralTexture
{
  friend class GcGiImpWoodTexture;
public:
  GCRX_DECLARE_MEMBERS(GcGiWoodTexture);

  GcGiWoodTexture(void);
  ~GcGiWoodTexture(void);

  GcGiWoodTexture(const GcGiWoodTexture &texture);
  GcGiWoodTexture & operator= (const GcGiWoodTexture &texture);
  bool              operator==(const GcGiMaterialTexture & texture) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  virtual void setColor1(const GcGiMaterialColor &woodColor1);
  virtual const GcGiMaterialColor & color1(void) const;

  virtual void setColor2(const GcGiMaterialColor &woodColor2);
  virtual const GcGiMaterialColor & color2(void) const;

  virtual void setRadialNoise(double radialNoise);
  virtual double radialNoise(void) const;

  virtual void setAxialNoise(double axialNoise);
  virtual double axialNoise(void) const;

  virtual void setGrainThickness(double grainThickness);
  virtual double grainThickness(void) const;

private:
  GcGiImpWoodTexture * mpGcGiImpWoodTexture;
};

class GcGiImpMarbleTexture;

class GCGIMAT_IMPEXP GcGiMarbleTexture : public GcGiProceduralTexture
{
  friend class GcGiImpMarbleTexture;
public:
  GCRX_DECLARE_MEMBERS(GcGiMarbleTexture);

  GcGiMarbleTexture(void);
  ~GcGiMarbleTexture(void);

  GcGiMarbleTexture(const GcGiMarbleTexture &texture);
  GcGiMarbleTexture & operator= (const GcGiMarbleTexture &texture);
  bool                operator==(const GcGiMaterialTexture & texture) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  virtual void setStoneColor(const GcGiMaterialColor &stoneColor);
  virtual const GcGiMaterialColor & stoneColor(void) const;

  virtual void setVeinColor(const GcGiMaterialColor &veinColor);
  virtual const GcGiMaterialColor & veinColor(void) const;

  virtual void setVeinSpacing(double veinSpacing);
  virtual double veinSpacing(void) const;

  virtual void setVeinWidth(double veinWidth);
  virtual double veinWidth(void) const;

private:
  GcGiImpMarbleTexture * mpGcGiImpMarbleTexture;
};

class GcGiMapper;
class GcGiImpMaterialMap;

class GCGIMAT_IMPEXP GcGiMaterialMap : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiMaterialMap);

  enum Source {
    kScene = 0,
    kFile,
    kProcedural
  };

  enum Filter
  {
    kFilterDefault = 0,
    kFilterNone
  };

  static const GcGiMaterialMap kNull;

  GcGiMaterialMap(void);
  ~GcGiMaterialMap(void);

  GcGiMaterialMap(const GcGiMaterialMap &matMap);
  GcGiMaterialMap & operator= (const GcGiMaterialMap &matMap);
  bool              operator==(const GcGiMaterialMap &matMap)const;

  virtual void set(const GcGiMaterialMap &matMap);
  virtual void setSource(Source source);
  GSOFT_DEPRECATED virtual void setSourceFileName(const GCHAR * fileName);
  virtual void setTexture(const GcGiMaterialTexture * pTexture);
  virtual void setBlendFactor(double blendFactor);
  virtual void setMapper(const GcGiMapper &mapper);

  virtual Source                  source(void) const;
  GSOFT_DEPRECATED virtual const GCHAR * sourceFileName(void) const;
  virtual const GcGiMaterialTexture *  texture(void) const;
  virtual double                  blendFactor(void) const;
  virtual const GcGiMapper &      mapper(void) const;

  Gcad::ErrorStatus   setFilter(Filter filter);
  Filter              filter(void) const;

protected:
  GcGiImpMaterialMap * mpGcGiImpMaterialMap;
};

class GcGiImpMapper;

class GCGIMAT_IMPEXP GcGiMapper : public GcGiParameter
{
public:
  GCRX_DECLARE_MEMBERS_READWRITE(GcGiMapper, GcGiImpMapper);

  enum Projection {
    kInheritProjection = 0,
    kPlanar,
    kBox,
    kCylinder,
    kSphere
  };

  enum Tiling {
    kInheritTiling = 0,
    kTile,
    kCrop,
    kClamp,
    kMirror,
  };

  enum AutoTransform {
    kInheritAutoTransform = 0x0,
    kNone = 0x1,
    kObject = 0x2,
    kModel = 0x4
  };

  static const GcGiMapper kIdentity;

  GcGiMapper(void);
  ~GcGiMapper(void);
  GcGiMapper(const GcGiMapper &mapper);
  GcGiMapper & operator= (const GcGiMapper &mapper);
  bool         operator==(const GcGiMapper &mapper) const;
  bool                         operator!=(const GcGiMapper &mapper) const
  {
    return !(*this == mapper);
  };

  virtual                  void set(const GcGiMapper &mapper);
  virtual                  void setProjection(Projection projection);
  virtual                  void setAutoTransform(AutoTransform autoTransform);
  virtual                  void setTransform(const GcGeMatrix3d &transform);
  virtual                  Projection             projection(void) const;
  virtual                  AutoTransform          autoTransform(void) const;
  virtual                  const GcGeMatrix3d&    transform(void) const;

  void        setUTiling(Tiling tiling);
  void        setVTiling(Tiling tiling);
  Tiling      uTiling(void) const;
  Tiling                      vTiling(void) const;
};

#pragma pack (pop)