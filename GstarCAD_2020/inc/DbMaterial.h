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


#ifndef __ODDBMATERIAL_H__
#define __ODDBMATERIAL_H__

#include "TD_PackPush.h"

#include "Gi/GiMaterial.h"
#include "DbObject.h"

/** Description:
  This class represents Material properties for shaded entities.

  {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbMaterial : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbMaterial);

  OdDbMaterial();
  virtual ~OdDbMaterial();
  
  /** Description:
    Sets the *name* of this Material object.
    
    Arguments:
    name (I) Name.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setName(  //Gcad(Modify)
    const OdChar* pName);

  /** Description:
    Returns the *name* of this Material object.
  */
  virtual const OdChar* name() const;  //Gcad(Modify)

  virtual void setGsNode(OdGsNode* pNode);
  virtual OdGsNode* gsNode(void) const;

  /** Description:
    Sets the *description* of this Material object.
    
    Arguments:
    description (I) Description.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setDescription(  //Gcad(Modify)
    const OdChar* pDescription);

  /** Description:
    Returns the *description* of this Material object.
  */
  virtual const OdChar* description() const;  //Gcad(Modify)


  /** Description:
    Sets the *ambient* (shadow) component of this Material object.
    
    Arguments:
    ambientColor (I) Ambient color.

  */
  virtual void setAmbient(
    const OdGiMaterialColor& ambientColor);
    
  /** Description:
    Returns the *ambient* (shadow) component of this Material object.
    
    Arguments:
    ambientColor (O) Receives the *ambient* color.

  */
  virtual void ambient(
    OdGiMaterialColor& ambientColor) const;

  /** Description:
    Sets the *diffuse* (main) component of this Material object.
    
    Arguments:
    diffuseColor (I) Diffuse color.
    diffuseMap (I) Diffuse map.
  */
  virtual void setDiffuse(
    const OdGiMaterialColor& diffuseColor, 
    const OdGiMaterialMap& diffuseMap);
    
  /** Description:
    Returns the *diffuse* (main) component of this Material object.
    
    Arguments:
    diffuseColor (O) Receives the *diffuse* color.
    diffuseMap (O) Receives the *diffuse* map.

  */
  virtual void diffuse(
    OdGiMaterialColor& diffuseColor, 
    OdGiMaterialMap& diffuseMap) const;


  /** Description:
    Sets the *specular* (*reflection*) component of this Material object.
    
    Arguments:
    specularColor (I) Specular color.
    specularMap (I) Specular map.
    glossFactor (I) Gloss factor.
    
    Remarks:    
    The *specular* component is viewpoint dependent, and most apparent when the entity is highlighted.
  */
  virtual void setSpecular(
    const OdGiMaterialColor& specularColor, 
    const OdGiMaterialMap& specularMap, 
    double glossFactor);

  /** Description:
    Returns the *specular* (*reflection*) component of this Material object.
    
    Arguments:
    specularColor (O) Receives the *specular* color.
    specularMap (O) Receives the *specular* map.
    glossFactor (O) Receives the gloss factor.
    
    Remarks:    
    The *specular* component is viewpoint dependent, and most apparent when the entity is highlighted.
  */
  virtual void specular(
    OdGiMaterialColor& specularColor, 
    OdGiMaterialMap& specularMap, 
    double& glossFactor) const;

  /** Description:
    Sets the *reflection* component of this Material object.
    
    Arguments:
    reflectionMap (I) Reflection map.
    
    Remarks:    
    The *reflection* component creates a mirror finish on the entity.
  */
  virtual void setReflection(const OdGiMaterialMap& reflectionMap);

  /** Description:
    Returns the *reflection* component of this Material object.
    
    Arguments:
    reflectionMap (O) Receives the *reflection* map.
    
    Remarks:    
    The *reflection* component creates a mirror finish on the entity .
  */
  virtual void reflection(OdGiMaterialMap& reflectionMap) const;


  /** Description:
    Sets the *opacity* component of this Material object.
    
    Arguments:
    opacityPercentage (I) Opacity percentage.
    opacityMap (I) Opacity map.
  */
  virtual void setOpacity(
    double opacityPercentage, 
    const OdGiMaterialMap& opacityMap);

  /** Description:
    Returns the *opacity* component of this Material object.
    
    Arguments:
    opacityPercentage (O) Receives the *opacity* percentage.
    opacityMap (O) Receives the *opacity* map.
  */
  virtual void opacity(
    double& opacityPercentage, 
    OdGiMaterialMap& opacityMap) const;

  /** Description:
    Sets the *bump* component of this Material object.
    
    Arguments:
    bumpMap (I) Bump map.
  */
  virtual void setBump(const OdGiMaterialMap& bumpMap);

  /** Description:
    Returns the *bump* component of this Material object.
    
    Arguments:
    bumpMap (O) Receives the *bump* map.
  */
  virtual void bump(OdGiMaterialMap& map) const;

  /** Description:
    Sets the *refraction* component of this Material object.
    
    Arguments:
    refractionIndex (I) Refraction index.
    refractionMap (I) Refraction map.
  */
  virtual void setRefraction(
    double refractionIndex, 
    const OdGiMaterialMap& refractionMap);

  /** Description:
    Returns the *refraction* component of this Material object.
    
    Arguments:
    refractionIndex (O) Receives the *refraction* index.
    refractionMap (O) Receives the *refraction* map.
  */
  virtual void refraction(
    double& refractionIndex,
    OdGiMaterialMap& refractionMap) const;

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
    
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
    
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
    
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdGiDrawable* drawable();

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);


/*-------------- New in AC21--------------------*/

  /** Description:
    Returns the *translucence* of this Material object.
  */
  virtual double translucence() const;

  /** Description:
    Sets the *translucence* of this Material object.
    Arguments:
    translucence (I) Translucense.
  */
  virtual OdResult setTranslucence(double translucence);  //Gcad(Modify)

  /** Description:
    Returns the self-illumination of this Material object.
  */
  virtual double selfIllumination() const;

  /** Description:
    Sets the self-illumination of this material object
    Arguments:
    selfIllumination (I) Self-illumination.
  */
  virtual OdResult setSelfIllumination(double selfIllumination);  //Gcad(Modify)

  /** Description:
    Returns the *refelectivity* of this Material object. 
  */
  virtual double reflectivity() const;

  /** Description:
    Sets the *reflectivity* of this Material object.
    Arguments:
    reflectivity (I) Reflectivity.
  */
  virtual OdResult setReflectivity(double reflectivity);  //Gcad(Modify)

  /** Description:
    Returns the *mode* of this Material object.
  */
  virtual OdGiMaterialTraits::Mode mode() const;

  /** Description:
    Sets the *mode* of this Material object.
    Arguments:
    mode (I) Mode.
  */
  virtual OdResult setMode(OdGiMaterialTraits::Mode mode);  //Gcad(Modify)

  /** Description:
    Returns the channel flags of this material object.
  */
  virtual OdGiMaterialTraits::ChannelFlags channelFlags() const;
  /** Description:
    Sets the channel flags for this material object.
    Remarks: 
    This allows multiple channels to be added to a material 
    and each channel to be enabled or disabled individually.
    Arguments:
    channelFlags (I) channel flags.
 */
  virtual OdResult setChannelFlags(OdGiMaterialTraits::ChannelFlags channelFlags);  //Gcad(Modify)

  /** Description:
    Returns the illumination model of this Material object.
    Remarks: 
    The illumination model determines the type of shader used to render this Material object.
  */
  virtual OdGiMaterialTraits::IlluminationModel illuminationModel() const;

  /** Description:
    Sets the illumination model of this Material object.
    Arguments:
    illuminationModel (I) Illumination model.
  */
  virtual OdResult setIlluminationModel(OdGiMaterialTraits::IlluminationModel illuminationMode);  //Gcad(Modify)

  /*---- Advanced material properties in AC21 XRec ----*/

  /** Description:
    Returns the color bleed scale of this Material object.
  */
  virtual double colorBleedScale() const;

  /** Description:
    Sets the color bleed scale of this Material object.
    Arguments:
    scale (I) Color bleed scale.
  */
  virtual OdResult setColorBleedScale(double scale);

  /** Description:
    Returns the indirect bump scale of this Material object.
  */
  virtual double indirectBumpScale() const;

  /** Description:
    Sets the indirect bump scale of this Material object.
    Arguments:
    scale (I) Indirect bump scale.
  */
  virtual OdResult setIndirectBumpScale(double scale);

  /** Description:
    Returns the reflectance scale of this Material object.
  */
  virtual double reflectanceScale() const;

  /** Description:
    Sets the reflectance scale of this Material object.
    Arguments:
    scale (I) Reflectance scale.
  */
  virtual OdResult setReflectanceScale(double scale);

  /** Description:
    Returns the transmittance scale of this Material object.
  */
  virtual double transmittanceScale() const;

  /** Description:
    Sets the transmittance scale of this Material object.
    Arguments:
    scale (I) Transmittance scale.
  */
  virtual OdResult setTransmittanceScale(double scale);

  /** Description:
    Returns the two sided mode of this Material object.
  */
  virtual OdBool twoSided() const;

  /** Description:
    Sets the two sided mode of this Material object.
    Arguments:
    flag (I) Two sided mode flag.
  */
  virtual OdResult setTwoSided(bool flag);

  /** Description:
    Returns the luminance mode of this Material object.
  */
  virtual OdGiMaterialTraits::LuminanceMode luminanceMode() const;

  /** Description:
    Sets the luminance mode of this Material object.
    Arguments:
    mode (I) Luminance mode.
  */
  virtual OdResult setLuminanceMode(OdGiMaterialTraits::LuminanceMode mode);

  /** Description:
    Returns the luminance of this Material object.
  */
  virtual double luminance() const;

  /** Description:
    Sets the luminance of this Material object.
    Arguments:
    value (I) Luminance value.
  */
  virtual OdResult setLuminance(double value);

  /** Description:
    Returns the shininess of this Material object.
    Remarks:
    See also *specular* gloss factor.
  */
  virtual double shininess() const;
  
  /** Description:
    Sets the shininess of this Material object.
    Remarks:
    See also *specular* gloss factor.
    Arguments:
    value (I) Shinincess value.
  */
  virtual OdResult setShininess(double value);

  /** Description:
    Returns the *normalMap* component of this Material object.
    Arguments:
    normalMap (O) Receives the *normalMap*.
    method (O) Receives normal map method.
    strength (O) Receives normal map strength factor.
  */
  virtual void normalMap(OdGiMaterialMap &normalMap, OdGiMaterialTraits::NormalMapMethod &method, double &strength) const;
  
  /** Description:
    Sets the *normalMap* component of this Material object.
    
    Arguments:
    normalMap (I) Normal map.
    method (I) Normal map method.
    strength (I) Normal map strength factor.
  */
  virtual OdResult setNormalMap(const OdGiMaterialMap &normalMap, OdGiMaterialTraits::NormalMapMethod method, double strength);

  /** Description:
    Returns the anonymous material mode of this Material object.
  */
  virtual OdBool isAnonymous() const;

  /** Description:
    Sets the anonymous material mode of this Material object.
    Arguments:
    flag (I) Anonymous mode flag.
  */
  virtual OdResult setAnonymous(bool flag);

  /** Description:
    Returns the global illumination mode of this Material object.
  */
  virtual OdGiMaterialTraits::GlobalIlluminationMode globalIllumination() const;

  /** Description:
    Sets the global illumination mode of this Material object.
    Arguments:
    mode (I) Global illumination mode.
  */
  virtual void setGlobalIllumination(OdGiMaterialTraits::GlobalIlluminationMode mode);

  /** Description:
    Returns the final gather mode of this Material object.
  */
  virtual OdGiMaterialTraits::FinalGatherMode finalGather() const;

  /** Description:
    Sets the final gather mode of this Material object.
    Arguments:
    mode (I) Final gather mode.
  */
  virtual void setFinalGather(OdGiMaterialTraits::FinalGatherMode mode);

  virtual OdResult subGetClassID(CLSID* pClsid) const;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbMaterial object pointers.
*/
typedef OdSmartPtr<OdDbMaterial> OdDbMaterialPtr;

#include "TD_PackPop.h"

#endif
