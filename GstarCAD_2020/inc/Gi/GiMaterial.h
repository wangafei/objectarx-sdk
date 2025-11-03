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

#ifndef __ODGIMATERIAL_H__
#define __ODGIMATERIAL_H__

#include "../TD_PackPush.h"
#include "../RootExport.h"
#include "../Gi/GiExport.h"

#include "../CmColor.h"
#include "../Ge/GeMatrix3d.h"
#include "../Gi/GiDrawable.h"
#include "../Gi/GiVariant.h"

class OdGiMaterialColor;
class OdGiMaterialMap;

/** Description:
    This class defines the interface to *material* traits for the vectorization process.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdGiMaterialTraits : public OdGiDrawableTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiMaterialTraits);

  enum IlluminationModel {
	  kBlinnShader = 0,
	  kMetalShader
  };

  enum ChannelFlags
  {
	  kNone          = 0x00000,
	  kUseDiffuse    = 0x00001,
	  kUseSpecular   = 0x00002,
	  kUseReflection = 0x00004,
	  kUseOpacity    = 0x00008,
	  kUseBump       = 0x00010,
	  kUseRefraction = 0x00020,
    kUseNormalMap  = 0x00040,
	  kUseAll        = (kUseDiffuse | kUseSpecular | kUseReflection
	  | kUseOpacity | kUseBump | kUseRefraction
    | kUseNormalMap)
  };

  enum Mode {
	  kRealistic = 0,
	  kAdvanced
  };

  // Returned via subSetAttributes()
  enum
  {
    kByBlock    = (OdGiDrawable::kLastFlag << 1),
    kByLayer    = (OdGiDrawable::kLastFlag << 2)
  };

  // Extended material traits enumerations

  enum LuminanceMode
  {
    kSelfIllumination = 0,
    kLuminance
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

  /** Description:
    Returns the *ambient* color component of this MaterialTraits object.

    Arguments:
    ambientColor (O) Receives the *ambient* color.

    Remarks:
    The *ambient* component component is most apparent when there is no direct illumination on the entity.
  */
  virtual void ambient(OdGiMaterialColor& ambientColor) const = 0;

  /** Description:
    Returns the *diffuse* component of this MaterialTraits object.

    Arguments:
    diffuseColor (O) Receives the *diffuse* color.
    diffuseMap (O) Receives the *diffuse* map.

    Remarks:
    The *diffuse* component is most apparent when there is direct illumination on the entity.
  */
  virtual void diffuse(OdGiMaterialColor& diffuseColor, OdGiMaterialMap& diffuseMap) const = 0;

  /** Description:
    Returns the *specular* component of this MaterialTraits object.

    Arguments:
    specularColor (O) Receives the *specular* color.
    specularMap (O) Receives the *specular* map.
    glossFactor (O) Receives the gloss factor.

    Remarks:
    The *specular* component is viewpoint dependent, and most apparent when the entity is highlighted.
  */
  virtual void specular(OdGiMaterialColor& specularColor, OdGiMaterialMap& specularMap, double& glossFactor) const = 0;

  /** Description:
    Returns the *reflection* component of this MaterialTraits object.

    Arguments:
    reflectionMap (O) Receives the *reflection* map.

    Remarks:
    The *reflection* component creates a mirror finish on the entity .
  */
  virtual void reflection(OdGiMaterialMap& reflectionMap) const = 0;

  /** Description:
    Returns the *opacity* component of this MaterialTraits object.

    Arguments:
    opacityPercentage (O) Receives the *opacity* percentage.
    opacityMap (O) Receives the *opacity* map.
  */
  virtual void opacity(double& opacityPercentage, OdGiMaterialMap& opacityMap) const = 0;

  /** Description:
    Returns the *bump* component of this MaterialTraits object.

    Arguments:
    bumpMap (O) Receives the *bump* map.
  */
  virtual void bump(OdGiMaterialMap& bumpMap) const = 0;

  /** Description:
    Returns the *refraction* component of this MaterialTraits object.

    Arguments:
    refractionIndex (O) Receives the *refraction* index.
    refractionMap (O) Receives the *refraction* map.
  */
  virtual void refraction(double& refractionIndex, OdGiMaterialMap& refractionMap) const = 0;

  /** Description:
    Returns the *translucence* of this MaterialTraits object.
  */
  virtual double translucence() const = 0;

  /** Description:
    Returns the self illumination of this MaterialTraits object.
  */
  virtual double selfIllumination() const = 0;

  /** Description:
    Returns the *reflectivity* of this MaterialTraits object.
  */
  virtual double reflectivity() const = 0;

  /** Description:
    Returns the illumination model of this MaterialTraits object.
  */
  virtual IlluminationModel illuminationModel() const = 0;

  /** Description:
    Returns the channel flags of this MaterialTraits object.
  */
  virtual ChannelFlags channelFlags() const = 0;

  /** Description:
    Returns the *mode* of this MaterialTraits object.
  */
  virtual Mode mode() const = 0;

  /** Description:
    Sets the *ambient* color component of this MaterialTraits object.

    Arguments:
    ambientColor (I) Ambient color.

    Remarks:
    The *ambient* component component is most apparent when there is no direct illumination on the entity.
  */
  virtual void setAmbient(const OdGiMaterialColor& ambientColor) = 0;

  /** Description:
    Sets the *diffuse* component of this MaterialTraits object.

    Arguments:
    diffuseColor (I) Diffuse color.
    diffuseMap (I) Diffuse map.

    Remarks:
    The *diffuse* component is most apparent when there is direct illumination on the entity.
  */
  virtual void setDiffuse(const OdGiMaterialColor& diffuseColor, const OdGiMaterialMap& diffuseMap) = 0;

  /** Description:
    Sets the *specular* component of this MaterialTraits object.

    Arguments:
    specularColor (I) Specular color.
    specularMap (I) Specular map.
    glossFactor (I) Gloss factor.

    Remarks:
    The *specular* component is viewpoint dependent, and most apparent when the entity is highlighted.
  */
  virtual void setSpecular(const OdGiMaterialColor& specularColor, const OdGiMaterialMap& specularMap, double glossFactor) = 0;

  /** Description:
    Sets the *reflection* component of this MaterialTraits object.

    Arguments:
    reflectionMap (I) Reflection map.

    Remarks:
    The *reflection* component creates a mirror finish on the entity.
  */
  virtual void setReflection(const OdGiMaterialMap& reflectionMap) = 0;

  /** Description:
    Sets the *opacity* component of this MaterialTraits object.

    Arguments:
    opacityPercentage (I) Opacity percentage.
    opacityMap (I) Opacity map.
  */
  virtual void setOpacity(double opacityPercentage, const OdGiMaterialMap& opacityMap) = 0;

  /** Description:
    Sets the *bump* component of this MaterialTraits object.

    Arguments:
    bumpMap (I) Bump map.
  */
  virtual void setBump(const OdGiMaterialMap& bumpMap) = 0;

  /** Description:
    Sets the *refraction* component of this MaterialTraits object.

    Arguments:
    refractionIndex (I) Refraction index.
    refractionMap (I) Refraction map.
  */
  virtual void setRefraction(double refractionIndex, const OdGiMaterialMap& refractionMap) = 0;

  /** Description:
    Sets the *translucence* of this MaterialTraits object.

    Arguments:
    value (I) Translucence value.
  */
  virtual void setTranslucence(double value) = 0;

  /** Description:
    Sets the self illumination of this MaterialTraits object.

    Arguments:
    value (I) Self illumination level.
  */
  virtual void setSelfIllumination(double value) = 0;

  /** Description:
    Sets the *reflectivity* of this MaterialTraits object.

    Arguments:
    value (I) Reflectivity value.
  */
  virtual void setReflectivity(double value) = 0;

  /** Description:
    Sets the illumination model of this MaterialTraits object.

    Arguments:
    model (I) Illumination model.
  */
  virtual void setIlluminationModel(IlluminationModel model) = 0;

  /** Description:
    Sets the channel flags of this MaterialTraits object.

    Arguments:
    value (I) Channel flags.
  */
  virtual void setChannelFlags(ChannelFlags flags) = 0;

  /** Description:
    Sets the *mode* of this MaterialTraits object.

    Arguments:
    value (I) Mode value.
  */
  virtual void setMode(Mode value) = 0;

  // Extended material properties

  /** Description:
    Sets the color bleed scale of this MaterialTraits object.

    Arguments:
    scale (I) Color bleed scale.
  */
  virtual void setColorBleedScale(double scale) = 0;
  /** Description:
    Returns the color bleed scale of this MaterialTraits object.
  */
  virtual double colorBleedScale() const = 0;

  /** Description:
    Sets the indirect bump scale of this MaterialTraits object.

    Arguments:
    scale (I) Indirect bump scale.
  */
  virtual void setIndirectBumpScale(double scale) = 0;
  /** Description:
    Returns the indirect bump scale of this MaterialTraits object.
  */
  virtual double indirectBumpScale() const = 0;

  /** Description:
    Sets the reflectance scale of this MaterialTraits object.

    Arguments:
    scale (I) Reflectance scale.
  */
  virtual void setReflectanceScale(double scale) = 0;
  /** Description:
    Returns the reflectance scale of this MaterialTraits object.
  */
  virtual double reflectanceScale() const = 0;

  /** Description:
    Sets the transmittance scale of this MaterialTraits object.

    Arguments:
    scale (I) Transmittance scale.
  */
  virtual void setTransmittanceScale(double scale) = 0;
  /** Description:
    Returns the transmittance scale of this MaterialTraits object.
  */
  virtual double transmittanceScale() const = 0;

  /** Description:
    Sets the two sided mode of this MaterialTraits object.

    Arguments:
    flag (I) Two sided mode flag.
  */
  virtual void setTwoSided(bool flag) = 0;
  /** Description:
    Returns the two sided mode of this MaterialTraits object.
  */
  virtual bool twoSided() const = 0;

  /** Description:
    Sets the luminance mode of this MaterialTraits object.

    Arguments:
    mode (I) Luminance mode.
  */
  virtual void setLuminanceMode(LuminanceMode mode) = 0;
  /** Description:
    Returns the luminance mode of this MaterialTraits object.
  */
  virtual LuminanceMode luminanceMode() const = 0;

  /** Description:
    Sets the luminance of this MaterialTraits object.

    Arguments:
    value (I) Luminance value.
  */
  virtual void setLuminance(double value) = 0;
  /** Description:
    Returns the luminance of this MaterialTraits object.
  */
  virtual double luminance() const = 0;

  /** Description:
    Sets the *normalMap* component of this MaterialTraits object.

    Arguments:
    normalMap (I) Normal map.
    method (I) Normal map method.
    strength (I) Strength factor.
  */
  virtual void setNormalMap(const OdGiMaterialMap &normalMap, NormalMapMethod method, double strength) = 0;
  /** Description:
    Returns the *normalMap* component of this MaterialTraits object.

    Arguments:
    normalMap (O) Receives the normal map.
    method (O) Receives the normal map method.
    strength (O) Receives the normal map strength factor.
  */
  virtual void normalMap(OdGiMaterialMap &normalMap, NormalMapMethod &method, double &strength) const = 0;

  /** Description:
    Sets the global illumination mode of this MaterialTraits object.

    Arguments:
    mode (I) Global illumination mode.
  */
  virtual void setGlobalIllumination(GlobalIlluminationMode mode) = 0;
  /** Description:
    Returns the global illumination mode of this MaterialTraits object.
  */
  virtual GlobalIlluminationMode globalIllumination() const = 0;

  /** Description:
    Sets the final gather mode of this MaterialTraits object.

    Arguments:
    mode (I) Final gather mode.
  */
  virtual void setFinalGather(FinalGatherMode mode) = 0;
  /** Description:
    Returns the final gather mode of this MaterialTraits object.
  */
  virtual FinalGatherMode finalGather() const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMaterialTraits object pointers.
*/
typedef OdSmartPtr<OdGiMaterialTraits> OdGiMaterialTraitsPtr;


/** Description:
    This class implements material colors by *color* *method* and value.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialColor
{
public:
  enum Method
  {
    kInherit  = 0, // Uses the current drawing *color*.
    kOverride = 1  // Uses the *color* set with setColor.
  };

  ODGI_EXPORT_STATIC static const OdGiMaterialColor kNull;

  OdGiMaterialColor();

  /** Description
    Sets the *color* *method* for this MaterialColor object.

    Arguments:
    method (I) *Color* *method*.

    Remarks:
    method must be one of the following:

    @table
    Name          Value    Description
    kInherit      0        Uses the current drawing *color*.
    kOverride     1        Uses the *color* set with setColor.
  */
  void setMethod(Method method);

  /** Description:
    Sets the *color* *factor* for this MaterialColor object.
    Arguments:
    factor (I) *Color* *factor*.
    Remarks:
    A *color* *factor* of 0.0 makes all colors black; a *color* *factor* of 1.0 leaves them unchanged.
  */
  void setFactor(double factor);

  /** Description:
    Returns a reference to, or a copy of, the *color* of this MaterialColor object as
    an OdCmEntityColor instance.
  */
  OdCmEntityColor& color();


  /** Description
    Returns the *color* *method* for this MaterialColor object.

    Remarks:
    method() returns one of the following:

    @table
    Name          Value    Description
    kInherit      0        Uses the current drawing *color*.
    kOverride     1        Uses the *color* set with setColor.
  */
  Method method() const;

  /** Description:
    Returns the *color* *factor* for this MaterialColor object.
    Arguments:

    Remarks:
    A *color* *factor* of 0.0 makes all colors black; a *color* *factor* of 1.0 leaves them unchanged.
  */
  double factor() const;

  /** Description:
    Returns a constant reference to, or a copy of, the *color* of this MaterialColor object as
    an constant OdCmEntityColor instance.
  */
  const OdCmEntityColor& color() const;

  /*/DD2ARX - xi hui - 2008-06-25 - OdGiMaterialColor::set&setColor
  /*/
  OdGiMaterialColor &operator =(const OdGiMaterialColor & matColor);

  void set(const OdGiMaterialColor & matColor);
  //*/

  bool operator ==(const OdGiMaterialColor &other) const
  {
    return (m_method == other.m_method) &&
           (m_factor == other.m_factor) &&
           (m_color  == other.m_color);      
  }
  bool operator != (const OdGiMaterialColor &other) const
  {
    return (m_method != other.m_method) ||
           (m_factor != other.m_factor) ||
           (m_color  != other.m_color);      
  }

  /** Description:
    Sets the *color* for this MaterialColor object.
    Arguments:
    color (I) New *color* for this MaterialColor object.
  */
  void setColor(const OdCmEntityColor &color);

private:
  Method          m_method;
  double          m_factor;
  OdCmEntityColor m_color;
};


/** Description:
	  This class defines material textures.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdGiMaterialTexture : public OdRxObject
{
public:
	ODRX_DECLARE_MEMBERS(OdGiMaterialTexture);
	virtual bool operator==(const OdGiMaterialTexture & texture)const;
protected:
};

inline bool OdGiMaterialTexture::operator==(const OdGiMaterialTexture & texture) const {
	return (texture.isA() == isA());
}

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiMaterialTexture object pointers.
*/
typedef OdSmartPtr<OdGiMaterialTexture> OdGiMaterialTexturePtr;

/** Description:
     This class defines image based material textures.
	   Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdGiImageTexture : public OdGiMaterialTexture
{
public:
	ODRX_DECLARE_MEMBERS(OdGiImageTexture);
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiImageTexture object pointers.
*/
typedef OdSmartPtr<OdGiImageTexture> OdGiImageTexturePtr;

/** Description:
     This class defines image file based material texture.
	   Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiImageFileTexture : public OdGiImageTexture
{
public:
	ODRX_DECLARE_MEMBERS(OdGiImageFileTexture);

  virtual void setSourceFileName(const OdString& fileName);
  virtual const OdString sourceFileName() const;

	virtual bool operator==(const OdGiMaterialTexture & texture) const;
  OdGiImageFileTexture &operator =(const OdGiImageFileTexture &texture);

  // OdRxObject overrides
  OdResult copyFrom(const OdRxObject* pSource);
private:
	OdString m_sourceFileName;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiImageFileTexture object pointers.
*/
typedef OdSmartPtr<OdGiImageFileTexture> OdGiImageFileTexturePtr;

/** Description:
     This class defines procedural material textures.
	   Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdGiProceduralTexture : public OdGiMaterialTexture
{
public:
	ODRX_DECLARE_MEMBERS(OdGiProceduralTexture);

	enum Type
	{
		kWood    = 0,
		kMarble  = 1,
    kGeneric = 2
  };

  virtual Type type() const = 0;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiProceduralTexture object pointers.
*/
typedef OdSmartPtr<OdGiProceduralTexture> OdGiProceduralTexturePtr;

/** Description:
	  This class defines wood procedural material textures.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiWoodTexture : public OdGiProceduralTexture
{
public:
	ODRX_DECLARE_MEMBERS(OdGiWoodTexture);

  OdGiWoodTexture();

  virtual Type type() const  {return kWood;}

	// wood properties

	virtual void setColor1(const OdGiMaterialColor &woodColor1);
	virtual const OdGiMaterialColor& color1(void) const;

	virtual void setColor2(const OdGiMaterialColor &woodColor2);
	virtual const OdGiMaterialColor& color2(void) const;

	virtual void setRadialNoise(double radialNoise);
	virtual double radialNoise(void) const;

	virtual void setAxialNoise(double axialNoise);
	virtual double axialNoise(void) const;

	virtual void setGrainThickness(double grainThickness);
	virtual double grainThickness(void) const;

	virtual bool operator==(const OdGiMaterialTexture & texture) const;
  OdGiWoodTexture &operator =(const OdGiWoodTexture &texture);

  // OdRxObject overrides
  OdResult copyFrom(const OdRxObject* pSource);
private:
	OdGiMaterialColor m_color1;
	OdGiMaterialColor m_color2;
	double						m_radialNoise;
	double						m_axialNoise;
	double						m_grainThickness;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiWoodTexture object pointers.
*/
typedef OdSmartPtr<OdGiWoodTexture> OdGiWoodTexturePtr;

/** Description:
    This class defines marble procedural material texture.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiMarbleTexture : public OdGiProceduralTexture
{
public:
	ODRX_DECLARE_MEMBERS(OdGiMarbleTexture);

  OdGiMarbleTexture();

  virtual Type type() const  {return kMarble;}

	virtual void setStoneColor(const OdGiMaterialColor &stoneColor);
	virtual const OdGiMaterialColor& stoneColor(void) const;

	virtual void setVeinColor(const OdGiMaterialColor &veinColor);
	virtual const OdGiMaterialColor& veinColor(void) const;

	virtual void setVeinSpacing(double veinSpacing);
	virtual double veinSpacing(void) const;

	virtual void setVeinWidth(double veinWidth);
	virtual double veinWidth(void) const;

	virtual bool operator==(const OdGiMaterialTexture & texture) const;
  OdGiMarbleTexture &operator =(const OdGiMarbleTexture &texture);

  // OdRxObject overrides
  OdResult copyFrom(const OdRxObject* pSource);
private:
	OdGiMaterialColor m_stoneColor;
	OdGiMaterialColor m_veinColor;
	double						m_veinSpacing;
	double						m_veinWidth;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiMarbleTexture object pointers.
*/
typedef OdSmartPtr<OdGiMarbleTexture> OdGiMarbleTexturePtr;

/** Description:
    This class defines generic procedural material texture.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiGenericTexture : public OdGiProceduralTexture
{
public:
	ODRX_DECLARE_MEMBERS(OdGiGenericTexture);

  OdGiGenericTexture();

  virtual Type type() const  {return kGeneric;}

  virtual void setDefinition(const OdGiVariant &definition);
  virtual OdGiVariantPtr definition() const;
  virtual void definition(OdGiVariantPtr &pDefinition) const;

	virtual bool operator==(const OdGiMaterialTexture & texture) const;
  OdGiGenericTexture &operator =(const OdGiGenericTexture &texture);

  // OdRxObject overrides
  OdResult copyFrom(const OdRxObject* pSource);
private:
  OdGiVariantPtr    m_definition;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiGenericTexture object pointers.
*/
typedef OdSmartPtr<OdGiGenericTexture> OdGiGenericTexturePtr;


/** Description:
    This class implements mappers.


    Remarks:
    Mappers determine how an OdGiMaterialMap is mapped to an object surface.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMapper
{
public:
  enum Projection
  {
    kInheritProjection   = 0, // Inherits *projection* from the current material's mapper.
    kPlanar              = 1, // Maps directly to XY coordinates.
    kBox                 = 2, // Maps to planes perpendicular to major axes.
    kCylinder            = 3, // Maps to cylinder aligned with Z-axis.
    kSphere              = 4, // Maps to sphere aligned with Z-axis

    kDgnParametric       = 0x32, // Maps directly to surface coordinates. For dgn materials.
    kDgnPlanar           = 0x33, // Maps directly to surface coordinates. For dgn materials.
    kDgnCylinder         = 0x34, // Maps to cylinder aligned with Z-axis. For dgn materials.
    kDgnCylinderCapped   = 0x35, // Maps to cylinder aligned with Z-axis. If normal to surface same as Z-axis
                                 // then used planar mapping. For dgn materials.
    kDgnSphere           = 0x36  // Maps to sphere aligned with Z-axis. For dgn materials.
  };

  enum Tiling
  {
    kInheritTiling    = 0, // Inherits *tiling* from the current material's mapper.
    kTile             = 1, // Repeats map along image axes.
    kCrop             = 2, // Crops map < 0.0 or > 1.0 on image axes.
    kClamp            = 3, // Clamps (stretches) map between 0.0 and 1.0 on image axes.
    kMirror           = 4  // Mirror the material map at every integer boundary.
  };

  enum AutoTransform
  {
    kInheritAutoTransform = 0x0, // Inherits automatic *transform* from the current material/s mapper.
    kNone                 = 0x1, // No automatic *transform*.
    kObject               = 0x2, // Adjusts the mapper *transform* to align with and fit the current object.
    kModel                = 0x4  // Multiples the mapper *transform* by the current block *transform*.
  };

  ODGI_EXPORT_STATIC static const OdGiMapper kIdentity;

  OdGiMapper()
    : m_projection(kPlanar)
    , m_uTiling(kTile)
    , m_vTiling(kTile)
    , m_autoTransform(kNone)
  {
  }

  OdGiMapper (const OdGiMapper& mapper);
  OdGiMapper& operator=(const OdGiMapper& mapper);
  bool operator==(const OdGiMapper& mapper) const;
  bool operator!=(const OdGiMapper& mapper) const;

  /** Description:
    Sets the type of *projection* for this Mapper object.

    Arguments:
    projection (I) *Projection* type.

    Remarks:
    projection must be one of the following:

    @table
    Name                  Value   Description
    kInheritProjection    0       Inherits *projection* from the current material's mapper.
    kPlanar               1       Maps directly to XY coordinates.
    kBox                  2       Maps to planes perpendicular to major axes.
    kCylinder             3       Maps to cylinder aligned with Z-axis.
    kSphere               4       Maps to sphere aligned with Z-axis
  */
  void setProjection(Projection projection);

  /** Description:
    Sets the type of X-axis *tiling* for this Mapper object.

    Arguments:
    tiling (I) *Tiling* type.

    Remarks:
    tiling must be one of the following:

    @table
    Name                  Value   Description
    kInheritTiling        0       Inherits *tiling* from the current material's mapper.
    kTile                 1       Repeats map along image axes.
    kCrop                 2       Crops map < 0.0 or > 1.0 on image axes.
    kClamp                3       Clamps (stretches) map between 0.0 and 1.0 on image axes.
    kMirror               4       Mirror the material map at every integer boundary.
  */
  void setUTiling(Tiling tiling);

  /** Description:
    Sets the type of Y-axis *tiling* for this Mapper object.

    Arguments:
    tiling (I) *Tiling* type.

    Remarks:
    tiling must be one of the following:

    @table
    Name                  Value   Description
    kInheritTiling        0       Inherits *tiling* from the current material's mapper.
    kTile                 1       Repeats map along image axes.
    kCrop                 2       Crops map < 0.0 or > 1.0 on image axes.
    kClamp                3       Clamps (stretches) map between 0.0 and 1.0 on image axes.
    kMirror               4       Mirror the material map at every integer boundary.
  */
  void setVTiling(Tiling tiling);
  
  /*/DD2ARX - xi hui - 2008-06-25 - OdGiMapper::set&setTransform
  /*/
  void set(const OdGiMapper & mapper);
  //*/

  /** Description:
    Sets the type of automatic *transform* for this Mapper object.

    Arguments:
    autoTransform (I) Automatic *transform* type.

    Remarks:
    autoTransform must be a one of the following:

    @table
    Name                      Value   Description
    kInheritAutoTransform     0x0     Inherits automatic *transform* from the current material/s mapper.
    kNone                     0x1     No automatic *transform*.
    kObject                   0x2     Adjusts the mapper *transform* to align with and fit the current object.
    kModel                    0x4     Multiples the mapper *transform* by the current block *transform*.
  */
  void setAutoTransform(AutoTransform autoTransform);

  /** Description:
    Returns a reference to the transformation matrix for this Mapper object.

    Remarks:
    The transform matrix defines mapping of an OdGiMaterialMap image when applied to the surface of an object.
  */
  OdGeMatrix3d& transform();

  /** Description:
    Returns the type of *projection* for this Mapper object.

    Remarks:
    projection() returns one of the following:

    @table
    Name                  Value   Description
    kInheritProjection    0       Inherits *projection* from the current material's mapper.
    kPlanar               1       Maps directly to XY coordinates.
    kBox                  2       Maps to planes perpendicular to major axes.
    kCylinder             3       Maps to cylinder aligned with Z-axis.
    kSphere               4       Maps to sphere aligned with Z-axis
  */
  Projection projection() const;

  /** Description:
    Returns the type of X-axis *tiling* for this Mapper object.

    Remarks:
    tiling() returns one of the following:

    @table
    Name                  Value   Description
    kInheritTiling        0       Inherits *tiling* from the current material's mapper.
    kTile                 1       Repeats map along image axes.
    kCrop                 2       Crops map < 0.0 or > 1.0 on image axes.
    kClamp                3       Clamps (stretches) map between 0.0 and 1.0 on image axes.
    kMirror               4       Mirror the material map at every integer boundary.
  */
  Tiling uTiling() const;

  /** Description:
    Returns the type of Y-axis *tiling* for this Mapper object.

    Remarks:
    tiling() returns one of the following:

    @table
    Name                  Value   Description
    kInheritTiling        0       Inherits *tiling* from the current material's mapper.
    kTile                 1       Repeats map along image axes.
    kCrop                 2       Crops map < 0.0 or > 1.0 on image axes.
    kClamp                3       Clamps (stretches) map between 0.0 and 1.0 on image axes.
    kMirror               4       Mirror the material map at every integer boundary.
  */
  Tiling vTiling() const;

  /** Description:
    Returns the type of automatic *transform* for this Mapper object.

    Remarks:
    autoTransform() returns a combination of one or more of the following:

    @table
    Name                      Value   Description
    kInheritAutoTransform     0x0     Inherits automatic *transform* from the current material's mapper.
    kNone                     0x1     No automatic *transform*.
    kObject                   0x2     Adjusts the mapper *transform* to align with and fit the current object.
    kModel                    0x4     Multiples the mapper *transform* by the current block *transform*.
  */
  AutoTransform autoTransform() const;

  const OdGeMatrix3d& transform() const;

  void setTransform(const OdGeMatrix3d &tm);

private:
  Projection    m_projection;
  Tiling        m_uTiling;
  Tiling        m_vTiling;
  AutoTransform m_autoTransform;
  OdGeMatrix3d  m_transform;
};


/** Description:
  This class implements material maps.

  Remarks:
  Material maps define bitmapped images which are applied to object surfaces.

  {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMaterialMap
{
public:
  enum Source
  {
    kScene      = 0,  // Map is created from the current scene.
    kFile       = 1,  // Map is from a file.
    kProcedural = 2   // Map is procedural.
  };

  ODGI_EXPORT_STATIC static const OdGiMaterialMap kNull;

  OdGiMaterialMap();

  /** Description:
    Sets the image *source* for this MaterialMap object.

    Arguments:
    source (I) Image *source*.

    Remarks:
    source must be one of the following:

    @table
    Name      Value   Description
    kScene    0,      Image is created from the current scene.
    kFile     1       Image is from a file.
  */
  void setSource(Source source);

  /** Description:
    Sets the *source* filename for this MaterialMap object.
    Arguments:
    filename (I) Source filename.
  */
  void setSourceFileName(const OdString& filename);

  /** Description:
    Sets the blend factor for this MaterialMap object.
    Arguments:
    blendFactor (I) Blend factor.
    Remarks:
    A blend factor of 0.0 makes the MaterialMap invisible. A blend factor of 1.0 makes it opaque.
    In between, the MaterialMap is transparent.
  */
  void setBlendFactor(double blendFactor);

	/** Description:
	Sets the Material texture for this MaterialMap object.
	*/
	void setTexture(OdGiMaterialTexturePtr pTexture);

  /** Description:
    Returns a reference to, or a copy of, the OdGiMapper for this MaterialMap object.

    Remarks:
    The *transform* matrix defines mapping of an OdGiMaterialMap image when applied to the surface of an object.
  */
  OdGiMapper& mapper();

  /** Description:
    Returns the image *source* for this MaterialMap object.

    Remarks:
    source must be one of the following:

    @table
    Name      Value   Description
    kScene    0,      Image is created from the current scene.
    kFile     1       Image is from a file.
  */
  Source source() const;

  /** Description:
    Returns the *source* filename for this MaterialMap object.
  */
  OdString sourceFileName() const;

  /** Description:
    Returns the blend factor for this MaterialMap object.

    Remarks:
    A blend factor of 0.0 makes the MaterialMap invisible. A blend factor of 1.0 makes it opaque.
    In between, the MaterialMap is transparent.
  */
  double blendFactor() const;

  const OdGiMapper& mapper() const;

	/** Description:
	Returns the material texture for this MaterialMap object.
	*/
	const OdGiMaterialTexturePtr  texture(void) const;

  bool operator ==(const OdGiMaterialMap &other)
  {
    if ((m_source      == other.m_source)      &&
        (m_fileName    == other.m_fileName)    &&
        (m_blendFactor == other.m_blendFactor) &&
        (m_mapper      == other.m_mapper))
    {
      if (m_texture.isNull() && other.m_texture.isNull())
        return true;
      if (!m_texture.isNull() && !other.m_texture.isNull())
        return (*m_texture == *(other.m_texture));
    }
    return false;
  }
  bool operator !=(const OdGiMaterialMap &other)
  {
    return !(*this == other);
  }

  OdGiMaterialMap &operator =(const OdGiMaterialMap& mmap)
  {
    m_source = mmap.m_source;
    m_fileName = mmap.m_fileName;
    m_blendFactor = mmap.m_blendFactor;
    m_mapper = mmap.m_mapper;
    m_texture = mmap.m_texture;
    return *this;
  }
private:
  Source     m_source;
  OdString   m_fileName;
  double     m_blendFactor;
  OdGiMapper m_mapper;
	OdGiMaterialTexturePtr m_texture;
};

inline
OdGiMaterialColor::OdGiMaterialColor()
  : m_method(kInherit)
  , m_factor(1.0)
{
}

inline void
OdGiMaterialColor::setMethod(Method method)
{
  m_method = method;
}

inline void
OdGiMaterialColor::setFactor(double factor)
{
  m_factor = factor;
}

inline OdCmEntityColor&
OdGiMaterialColor::color()
{
  return m_color;
}

inline OdGiMaterialColor::Method
OdGiMaterialColor::method() const
{
  return m_method;
}

inline double
OdGiMaterialColor::factor() const
{
  return m_factor;
}

inline const OdCmEntityColor&
OdGiMaterialColor::color() const
{
  return m_color;
}

/*/DD2ARX - xi hui - 2008-06-25 - OdGiMaterialColor::set&setColor
/*/
inline OdGiMaterialColor &OdGiMaterialColor::operator =(const OdGiMaterialColor & matColor)
{
	if (&matColor != this)
	{
		m_method = matColor.m_method;
		m_factor = matColor.m_factor;
		m_color = matColor.m_color;
	}
	return *this;
}

inline void OdGiMaterialColor::set(const OdGiMaterialColor & matColor)
{
	m_method = matColor.m_method;
	m_factor = matColor.m_factor;
	m_color = matColor.m_color;
}
//*/

inline void OdGiMaterialColor::setColor(const OdCmEntityColor &color)
{
  m_color = color;
}


inline
OdGiMaterialMap::OdGiMaterialMap()
  : m_source(kFile)
  , m_blendFactor(1.0)
{
}

inline void
OdGiMaterialMap::setSource(Source source)
{
  m_source = source;
}

inline void
OdGiMaterialMap::setSourceFileName(const OdString& filename)
{
  m_fileName = filename;
}

inline void
OdGiMaterialMap::setBlendFactor(double blendFactor)
{
  m_blendFactor = blendFactor;
}

inline OdGiMapper&
OdGiMaterialMap::mapper()
{
  return m_mapper;
}

inline OdGiMaterialMap::Source
OdGiMaterialMap::source() const
{
  return m_source;
}

inline OdString
OdGiMaterialMap::sourceFileName() const
{
  return m_fileName;
}

inline double
OdGiMaterialMap::blendFactor() const
{
  return m_blendFactor;
}

inline const OdGiMapper&
OdGiMaterialMap::mapper() const
{
  return m_mapper;
}

inline void
OdGiMaterialMap::setTexture(OdGiMaterialTexturePtr pTexture)
{
	m_texture = pTexture;
}

inline const OdGiMaterialTexturePtr
OdGiMaterialMap::texture(void) const
{
	return m_texture;
}


inline
OdGiMapper::OdGiMapper(const OdGiMapper& mapper)
  : m_projection(mapper.m_projection)
  , m_uTiling(mapper.m_uTiling)
  , m_vTiling(mapper.m_vTiling)
  , m_autoTransform(mapper.m_autoTransform)
  , m_transform(mapper.m_transform)
{
}

inline OdGiMapper&
OdGiMapper::operator=(const OdGiMapper& mapper)
{
  if (&mapper != this)
  {
    m_projection = mapper.m_projection;
    m_uTiling = mapper.m_uTiling;
    m_vTiling = mapper.m_vTiling;
    m_autoTransform = mapper.m_autoTransform;
    m_transform = mapper.m_transform;
  }
  return *this;
}

inline bool
OdGiMapper::operator==(const OdGiMapper& mapper) const
{
  return m_projection == mapper.m_projection
    && m_uTiling == mapper.m_uTiling
    && m_vTiling == mapper.m_vTiling
    && m_autoTransform == mapper.m_autoTransform
    && m_transform == mapper.m_transform;
}

inline bool
OdGiMapper::operator!=(const OdGiMapper& mapper) const
{
  return !(*this == mapper);
}

/*/DD2ARX - xi hui - 2008-06-25 - OdGiMapper::set&setTransform
/*/
inline void OdGiMapper::set(const OdGiMapper & mapper)
{
	m_projection = mapper.m_projection;
	m_uTiling = mapper.m_uTiling;
	m_vTiling = mapper.m_vTiling;
	m_autoTransform = mapper.m_autoTransform;
	m_transform = mapper.m_transform;
}
//*/

inline void
OdGiMapper::setProjection(Projection projection)
{
  m_projection = projection;
}

inline void
OdGiMapper::setUTiling(Tiling tiling)
{
  m_uTiling = tiling;
}

inline void
OdGiMapper::setVTiling(Tiling tiling)
{
  m_vTiling = tiling;
}

inline void
OdGiMapper::setAutoTransform(AutoTransform autoTransform)
{
  m_autoTransform = autoTransform;
}

inline OdGiMapper::Projection
OdGiMapper::projection() const
{
  return m_projection;
}

inline OdGiMapper::Tiling
OdGiMapper::uTiling() const
{
  return m_uTiling;
}

inline OdGiMapper::Tiling
OdGiMapper::vTiling() const
{
  return m_vTiling;
}

inline OdGiMapper::AutoTransform
OdGiMapper::autoTransform() const
{
  return m_autoTransform;
}

inline const OdGeMatrix3d&
OdGiMapper::transform() const
{
  return m_transform;
}

inline OdGeMatrix3d&
OdGiMapper::transform()
{
  return m_transform;
}

inline void
OdGiMapper::setTransform(const OdGeMatrix3d &tm)
{
  transform() = tm;
}

inline void
OdGiImageFileTexture::setSourceFileName(const OdString& fileName)
{
	m_sourceFileName = fileName;
}

inline const OdString
OdGiImageFileTexture::sourceFileName(void) const
{
	return m_sourceFileName;
}

inline bool
OdGiImageFileTexture::operator==(const OdGiMaterialTexture & texture) const
{
  if (!(texture.isA() == isA()))
    return false;
  const OdGiImageFileTexture &refTexture = static_cast<const OdGiImageFileTexture&>(texture);
  return m_sourceFileName == refTexture.m_sourceFileName;
}

inline OdGiImageFileTexture &
OdGiImageFileTexture::operator =(const OdGiImageFileTexture &texture)
{
  m_sourceFileName = texture.m_sourceFileName;
  return *this;
}

inline OdResult OdGiImageFileTexture::copyFrom(const OdRxObject* pSource)
{
  OdGiImageFileTexturePtr pSrcTex = OdGiImageFileTexture::cast(pSource);
  if (!pSrcTex.isNull())
  {
    setSourceFileName(pSrcTex->sourceFileName());
  }
  else
  {
    return Oda::eNotApplicable;
  }
  return Oda::eOk;
}

inline
OdGiWoodTexture::OdGiWoodTexture()
  : m_radialNoise(0.)
  , m_axialNoise(0.)
  , m_grainThickness(0.)
{
}

inline void
OdGiWoodTexture::setColor1(const OdGiMaterialColor &woodColor1)
{
	m_color1 = woodColor1;
}

inline const OdGiMaterialColor&
OdGiWoodTexture::color1(void) const
{
	return m_color1;
}

inline void
OdGiWoodTexture::setColor2(const OdGiMaterialColor &woodColor2)
{
	m_color2 = woodColor2;
}

inline const OdGiMaterialColor&
OdGiWoodTexture::color2(void) const
{
	return m_color2;
}

inline void
OdGiWoodTexture::setRadialNoise(double radialNoise)
{
	m_radialNoise = radialNoise;
}

inline double
OdGiWoodTexture::radialNoise(void) const
{
	return m_radialNoise;
}

inline void
OdGiWoodTexture::setAxialNoise(double axialNoise)
{
	m_axialNoise = axialNoise;
}

inline double
OdGiWoodTexture::axialNoise(void) const
{
	return m_axialNoise;
}

inline void
OdGiWoodTexture::setGrainThickness(double grainThickness)
{
	m_grainThickness = grainThickness;
}

inline double
OdGiWoodTexture::grainThickness(void) const
{
	return m_grainThickness;
}

inline bool
OdGiWoodTexture::operator==(const OdGiMaterialTexture & texture) const
{
  if (!(texture.isA() == isA()))
    return false;
  const OdGiWoodTexture &refTexture = static_cast<const OdGiWoodTexture&>(texture);
  return (m_color1 == refTexture.m_color1) &&
         (m_color2 == refTexture.m_color2) &&
         (m_radialNoise == refTexture.m_radialNoise) &&
         (m_axialNoise == refTexture.m_axialNoise) &&
         (m_grainThickness == refTexture.m_grainThickness);
}

inline OdGiWoodTexture &
OdGiWoodTexture::operator =(const OdGiWoodTexture &texture)
{
  m_color1 = texture.m_color1;
  m_color2 = texture.m_color2;
  m_radialNoise = texture.m_radialNoise;
  m_axialNoise = texture.m_axialNoise;
  m_grainThickness = texture.m_grainThickness;
  return *this;
}

inline OdResult OdGiWoodTexture::copyFrom(const OdRxObject* pSource)
{
  OdGiWoodTexturePtr pSrcTex = OdGiWoodTexture::cast(pSource);
  if (!pSrcTex.isNull())
  {
    setColor1(pSrcTex->color1());
    setColor2(pSrcTex->color2());
    setRadialNoise(pSrcTex->radialNoise());
    setAxialNoise(pSrcTex->axialNoise());
    setGrainThickness(pSrcTex->grainThickness());
  }
  else
  {
    return Oda::eNotApplicable;
  }
  return Oda::eOk;
}

inline
OdGiMarbleTexture::OdGiMarbleTexture()
  : m_veinSpacing(0.)
  , m_veinWidth(0.)
{
}

inline void
OdGiMarbleTexture::setStoneColor(const OdGiMaterialColor &stoneColor)
{
	m_stoneColor = stoneColor;
}

inline const OdGiMaterialColor&
OdGiMarbleTexture::stoneColor(void) const
{
	return m_stoneColor;
}

inline void
OdGiMarbleTexture::setVeinColor(const OdGiMaterialColor &veinColor)
{
	m_veinColor = veinColor;
}

inline const OdGiMaterialColor&
OdGiMarbleTexture::veinColor(void) const
{
	return m_veinColor;
}

inline void
OdGiMarbleTexture::setVeinSpacing(double veinSpacing)
{
	m_veinSpacing = veinSpacing;
}

inline double
OdGiMarbleTexture::veinSpacing(void) const
{
	return m_veinSpacing;
}

inline void
OdGiMarbleTexture::setVeinWidth(double veinWidth)
{
	m_veinWidth = veinWidth;
}

inline double
OdGiMarbleTexture::veinWidth(void) const
{
	return m_veinWidth;
}

inline bool
OdGiMarbleTexture::operator==(const OdGiMaterialTexture & texture) const
{
  if (!(texture.isA() == isA()))
    return false;
  const OdGiMarbleTexture &refTexture = static_cast<const OdGiMarbleTexture&>(texture);
  return (m_stoneColor == refTexture.m_stoneColor) &&
         (m_veinColor == refTexture.m_veinColor) &&
         (m_veinSpacing == refTexture.m_veinSpacing) &&
         (m_veinWidth == refTexture.m_veinWidth);
}

inline OdGiMarbleTexture &
OdGiMarbleTexture::operator =(const OdGiMarbleTexture &texture)
{
  m_stoneColor = texture.m_stoneColor;
  m_veinColor = texture.m_veinColor;
  m_veinSpacing = texture.m_veinSpacing;
  m_veinWidth = texture.m_veinWidth;
  return *this;
}

inline OdResult OdGiMarbleTexture::copyFrom(const OdRxObject* pSource)
{
  OdGiMarbleTexturePtr pSrcTex = OdGiMarbleTexture::cast(pSource);
  if (!pSrcTex.isNull())
  {
    setStoneColor(pSrcTex->stoneColor());
    setVeinColor(pSrcTex->veinColor());
    setVeinSpacing(pSrcTex->veinSpacing());
    setVeinWidth(pSrcTex->veinWidth());
  }
  else
  {
    return Oda::eNotApplicable;
  }
  return Oda::eOk;
}

inline
OdGiGenericTexture::OdGiGenericTexture()
{
}

inline void
OdGiGenericTexture::setDefinition(const OdGiVariant &definition)
{
  if (m_definition.isNull())
  {
    m_definition = OdGiVariant::createObject(definition);
  }
  else
  {
    *m_definition = definition;
  }
}

inline OdGiVariantPtr
OdGiGenericTexture::definition() const
{
  return m_definition;
}

inline void
OdGiGenericTexture::definition(OdGiVariantPtr &pDefinition) const
{
  if (m_definition.isNull())
  {
    pDefinition = OdGiVariant::createObject();
  }
  else
  {
    pDefinition = OdGiVariant::createObject(*m_definition);
  }
}

inline bool
OdGiGenericTexture::operator==(const OdGiMaterialTexture & texture) const
{
  if (!(texture.isA() == isA()))
    return false;
  const OdGiGenericTexture &refTexture = static_cast<const OdGiGenericTexture&>(texture);
  if (m_definition.isNull() && refTexture.m_definition.isNull())
    return true;
  if (!m_definition.isNull() && !refTexture.m_definition.isNull())
    return (*m_definition == *(refTexture.m_definition));
  return false;
}

inline OdGiGenericTexture &
OdGiGenericTexture::operator =(const OdGiGenericTexture &texture)
{
  if (!texture.m_definition.isNull())
    m_definition = OdGiVariant::createObject(*(texture.m_definition));
  else
    m_definition.release();
  return *this;
}

inline OdResult OdGiGenericTexture::copyFrom(const OdRxObject* pSource)
{
  OdGiGenericTexturePtr pSrcTex = OdGiGenericTexture::cast(pSource);
  if (!pSrcTex.isNull())
  {
    setDefinition(*(pSrcTex->definition()));
  }
  else
  {
    return Oda::eNotApplicable;
  }
  return Oda::eOk;
}

#include "../TD_PackPop.h"

#endif //#ifndef __ODGIMATERIAL_H__
