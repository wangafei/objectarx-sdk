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



#ifndef OD_AVEMATERIAL_H
#define OD_AVEMATERIAL_H

#include "../TD_PackPush.h"

#include "../Ve/AveDefs.h"
#include "../RxObject.h"
#include "../DbEntity.h"
#include "../IdArrays.h"

class OdDbObjectId;
class OdDbDatabase;
class OdAveMaterialImpl;
class OdAveMaterial;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdAveMaterial object pointers.
*/
typedef OdSmartPtr<OdAveMaterial> OdAveMaterialPtr;

/** Description:
    This class represents AVE Material properties for shaded entities.

    Remarks:
    AVE Material properties may be attached to OdDbEntity and
    OdDbLayerTableRecord objects, and to *color* indicies (ACIs).
    
    Library: TD_Ave
    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveMaterial : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdAveMaterial);

  /** Description:
    Creates a Material object from the specified OdDbBlockReference.
    
    Arguments:
    blockRefId (I) Object ID of the block reference.
    
    Remarks:
    The new Material object is attached to the specified block reference.
     
    Returns a SmartPointer to the new Material object.
  */
  static OdAveMaterialPtr getMaterial(const OdDbObjectId& blockRefId);

  /** Description:
    Returns the Material *name* from the specified OdDbBlockReference.
    
    Arguments:
    blockRefId (I) Object ID of the block reference.
  */
  static OdString getMaterialName(const OdDbObjectId& blockRefId);

  /** Description:
    Saves the Material properties to the OdDbBlockReference to which this Material object is associated.

    Arguments:
    pDb (I) Pointer to the *database*.
      
    Remarks:
    If pDb is null, the *database* containing this Material object is used.
  */
  OdResult writeMaterial(OdDbDatabase* pDb = NULL, const OdDbHandle& holderHandle = 0);

  /** Description:
    Attaches this Material object to the specified OdDbEntity.
    Arguments:
    entityId (I) Object ID of the entity.
    Remarks:
    Returns true if and only if successful.
  */
  bool attachToObject(OdDbObjectId entityId);

  /** Description:
    Attaches this Material object to the specified OdDbLayerTableRecord.
    Arguments:
    layerId (I) Object ID of the layer table record.
    Remarks:
    Returns true if and only if successful.
  */
  bool attachToLayer(OdDbObjectId layerId);

  /** Description:
    Attaches this Material object to the specified *color* index (ACI).

    Arguments:
    colorIndex (I) *Color* index. [1..255]
    
    Remarks:
    Returns true if and only if successful.

    Remarks:
    The attachment is made in the *database* of the holder of this Material Object.
    See also:
    OdCmEntityColor
  */
  bool attachToACI(OdUInt16 colorIndex);
  
  /** Description:
    Detaches this Material object from the specified OdDbEntity.
    Arguments:
    entityId (I) Object ID of the entity.
  */
  static void detachFromObject(OdDbObjectId entityId);

  /** Description:
    Detaches this Material object from the specified OdDbLayerTableRecord.
    Arguments:
    layerId (I) Object ID of the layer table record.
  */
  static void detachFromLayer(OdDbObjectId layerId);

  /** Description:
    Detaches this Material object from the specified *color* index (ACI) for the specified *database*.

    Arguments:
    colorIndex (I) Color index. [1..255]
    pDb (I) Pointer to the *database* for the ACI.
      
    Remarks:
    See also:
    OdCmEntityColor
  */
  static void detachFromACI(OdDbDatabase* pDb, OdUInt16 colorIndex);
  
  /** Description:
    Returns the object ID of the OdDbBlockReference associated with the material to which 
    the specified OdDbEntity, OeDbLayerTableRecord or *color* index (ACI)is attached.

    Arguments
    sourceId (I) Object ID of the entity or layer table record.
    colorIndex (I) *Color* index. [1..255]
    blockRefId (O) Object ID of OdDbBlockReference associated with the material.
    pDb (I) Pointer to the *database* of the ACI.
    Remarks:
    Returns true if and only if a material is attached.
  */
  static bool getAttachedMaterial(const OdDbObjectId& sourceId, OdDbObjectId& blockRefId);
  static bool getAttachedMaterial(OdDbDatabase* pDb, OdUInt16 colorIndex, OdDbObjectId& blockRefId);

  /** Description:
    Returns the ACI Material Map for the specified OdDbDatabase. 

    Arguments
    blockRefIds (O) Receives an array[255] of block reference object IDs.
    pDb (I) Pointer to the *database* for the ACI.
    
    Note:
    The Object ID for ACI==n is in blockRefIds[n-1],
    
    Remarks:
    Returns an empty array if not successful.
    
    blockRefIds are the object IDs of the OdDbBlockReferences associated with the materials.
  */
  static void getAciMaterialMap(OdDbDatabase* pDb, OdDbObjectIdArray& blockRefIds);

  /** Description:
    Returns the *type* of this Material object.
    Remarks:
    type() returns one of the following:
    
    @table
    Name          Value
    kStandard     0
    kGranite      1
    kMarble       2
    kWood         3

  */
  virtual OdAve::MaterialType type();

  /** Description:
    Returns true if and only if any of the specified Material *attributes*
    are used in this Material object.
    Arguments:
    attributes (I) Material *attributes*.
    Remarks:
    attributes must be a combination of one or more of the following:

    @table
    Name              Value
    kAmbient          0x1  
    kDiffuse          0x2  
    kSpecular         0x4  
    kTransparency     0x8  
    kRoughness        0x20 
    kBumpMap          0x40 
    kReflectionProp   0x100
    kRefraction       0x200
    
  */
  bool isAttribUsed(OdAve::MaterialAttrib attributes);

  /** Description:
    Returns the *name* of this Material object.
    
  */
  OdString name() const;
  /** Description:
    Returns the *description* of this Material object.
  */
  OdString description() const;

  /** Description:
    Sets the *name* of this Material object.
    Arguments:
    name (I) Name.
    
    Remarks:
    Names are truncated to 16 characters.
  */
  void setName(const OdString& name);

  /** Description:
    Sets the *description* of this Material object.
    Arguments:
    description (I) Description.
  */
  void setDescription(const OdString& description);

  /** Description:
    Returns the ambient (shadow) factor of this Material object.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0].

  */
  double ambientFactor() const;

  /** Description:
    Returns the ambient (shadow) *color* of this Material object.
    
    Remarks:
    ambientColor() returns a 24-bit RGB *color*.

  */
  OdUInt32 ambientColor() const;
  /** Description:
    Returns true if and only if the ambient (shadow) *color* for this Material object
    is the current entity color, CECOLOR.
  */
  bool ambientColorCurrent() const;

  /** Description:
    Returns true if and only if the ambient lock flag has been set for this Material object.
  */
  bool ambientLock() const;

  /** Description:
    Sets the ambient (shadow) factor of this Material object.
    
    Arguments:
    ambientFactor (I) Ambient factor. [0.0 .. 1.0]
  */
  void setAmbientFactor(double ambientFactor);

  /** Description:
    Sets the ambient (shadow) *color* of this Material object.
    
    Arguments:
    ambientColor (I) 24-bit RGB *color*.
  */
  void setAmbientColor(OdUInt32 ambientColor);
  /** Description:
    Controls the use of the current entity color, CECOLOR,
    as the ambient (shadow) *color* of this Material object.
    Arguments:
    currentColor (I) Controls the use of CECOLOR.
  */
  void setAmbientColorCurrent(bool currentColor);
  /** Description:
    Controls the ambient lock flag of this Material object.
    Arguments:
    ambientLock (I) Controls ambient lock.
  */
  void setAmbientLock(bool ambientLock);

 
  /** Description:
    Returns the diffuse (main) factor of this Material object.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0].

  */
  double diffuseFactor() const;

  /** Description:
    Returns the diffuse (main) *color* of this Material object.
    
    Remarks:
    diffuseColor() returns a 24-bit RGB *color*.
  */
  OdUInt32 diffuseColor() const;
  
  /** Description:
    Returns true if and only if the diffuse (main) *color* for this Material object
    is the current entity color, CECOLOR.

  */
  bool diffuseColorCurrent() const;
  
  
  /** Description:
    Returns a reference to the diffuse (main) bitmap for this Material object.

  */
  OdAveBitmap& diffuseBitmap() const;

  /** Description:
    Sets the diffuse (main) factor of this Material object.
    
    Arguments:
    diffuseFactor () Diffuse factor. [0.0 .. 1.0]

  */
  void setDiffuseFactor(double diffuseFactor);
  /** Description:
    Sets the diffuse (main) *color* of this Material object.
    
    Arguments:
    diffuseColor (I) 24-bit RGB *color*.
  */
  void setDiffuseColor(OdUInt32 diffuseColor);

  /** Description:
    Controls the use of the current entity color, CECOLOR,
    as the diffuse (main) *color* of this Material object.
    Arguments:
    currentColor (I) Controls the use of CECOLOR.

  */
  void setDiffuseColorCurrent(bool currentColor);

  /** Description:
    Returns the specular (reflection) factor of this Material object.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0].

  */
  double specularFactor() const;
 
  /** Description:
    Returns the specular (reflection) *color* of this Material object.
    
    Remarks:
    specularColor() returns a 24-bit RGB *color*.

  */
  OdUInt32 specularColor() const;
  /** Description:
    Returns true if and only if the specular (reflection) *color* for this Material object
    is the current entity color, CECOLOR.

  */
  bool specularColorCurrent() const;
  /** Description:
    Returns true if and only if specular reflections are to be mirrored for this Material object.

 */
  bool specularMirror() const;
  
  /** Description:
    Returns true if and only if the specular lock flag has been set for this Material object.

  */
  bool specularLock() const;
  
  /** Description:
    Returns a reference to, or a copy of, the specular (reflection) bitmap of this Material object.
  */
  OdAveBitmap& specularBitmap();
  const OdAveBitmap& specularBitmap() const;


  /** Description:
    Sets the specular (reflection) factor of this Material object.
    
    Arguments:
    specularFactor (I) Specular factor. [0.0 .. 1.0]

  */
  void setSpecularFactor(double specularFactor);
  /** Description:
    Sets the specular (reflection) *color* of this Material object.
    
    Arguments:
    specularColor (I) 24-bit RGB *color*.

  */
  void setSpecularColor(OdUInt32 specularColor);

  /** Description:
    Controls the use of the current entity color, CECOLOR,
    as the specular (reflection) *color* of this Material object.
    Arguments:
    currentColor (I) Controls the use of CECOLOR.

  */
  void setSpecularColorCurrent(bool colorCurrrent);
  /** Description:
    Controls the mirroring of specular reflections for this Material object.
    Arguments:
    mirror (I) Controls mirroring.

  */
  void setSpecularMirror(bool mirror);

  /** Description:
    Controls the specular lock flag of this Material object.
    Arguments:
    specularLock (I) Controls specular lock

    Remarks:    
    The *specular* component is viewpoint dependent, and most apparent when the entity is highlighted.
  */
  void setSpecularLock(bool specularLock);

  /** Description:
    Returns the *roughness* of this Material.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0].
    
    Roughness controls the size of the material's reflective highlight.
    The higher the level of *roughness*, the greater the highlight. 
  */
  double roughness() const;
  /** Description:
    Sets the *roughness* of this Material object.
    
    Arguments:
    roughness (I) Roughness. [0.0 .. 1.0]
    
    Remarks:
    Roughness controls the size of the material's reflective highlight.
    The higher the level of *roughness*, the greater the highlight. 
  */
  void setRoughness(double);

  /** Description:
    Returns the *transparency* of this Material object.
    
    Remarks:
    @table
    Value      Renders
    0.0        Opaque.
    1.0        Totally transparent.
    
  */
  double transparency() const;
  /** Description:
    Returns a reference to the *transparency* bitmap of this Material object.
  */
  OdAveBitmap& transparencyBitmap() const;
  /** Description:
    Returns the *transparency* of this Material object.
    
    Arguments:
    transparency (I) Transparency. [0.0 .. 1.0]
    Remarks:
    Returns a value in the r1ange [0.0 .. 1.0].
    
    @table
    Value      Renders
    0.0        Opaque.
    1.0        Totally transparent.
  */
  void setTransparency(double transparency);

  /** Description:
    Returns the *refraction* index of this Material object.
    
  */
  double refraction() const;

  /** Description:
    Sets the *refraction* index of this Material object.
    
    Arguments:
    refraction (I) Refraction.
    
  */
  void setRefraction(double refraction) const;

  /** Description:
    Returns a reference to, or a copy of, the bump bitmap of this Material object.
    
    Remarks:
    The bump bitmap may be used as an opacity map for this Material object.
  */
  OdAveBitmap& bumpMap();
  const OdAveBitmap& bumpMap() const;

  /** Description:
    Returns the Object ID of the OdDbBlockReference associated with this Material object.
  */
  OdDbObjectId holderId() const;

  /** Description:
  Returns the handle of the DbMaterial to which has been converted AveMaterial in A2008.
  */
  OdString handleDbMaterial() const;

  /** Description:
  Sets the DbMaterial handle of this material in A2008.
  */
  void setHandleDbMaterial(const OdString& sDesc);

  ~OdAveMaterial();
protected:
  OdAveMaterial();
  OdAveMaterial(OdAveMaterialImpl* pImpl);
  
  OdAveMaterialImpl* m_pImpl;
  friend class OdAveMaterialImpl;
};

/** Description:
    This class represents AVE Granite Material properties for shaded entities.
    
    Remarks:
    AVE Granite Materials consist of a random distribution of four colors.
    Library: TD_Ave

    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveGraniteMaterial : public OdAveMaterial
{
public:
  ODRX_DECLARE_MEMBERS(OdAveGraniteMaterial);

  /** Description:
    Defines the *color* index for each of the four colors
    that are present in a Granite Material object.
  */
  enum GraniteColor
  {
    kFirst    = 0,
    kSecond   = 1,
    kThird    = 2,
    kFourth   = 3
  };

  virtual OdAve::MaterialType type();

  /** Description:
    Returns the *color* factor for the specified granite *color* of this Granite Material object.
   
    Arguments:
    graniteColor (I) Granite *color*.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0]. 
    
    There are four colors associated with a Granite Material object. 
    The *color* factors determine the relative amounts of the four granite colors.
    
    graniteColor must be one of the following:
    
    @table
    Name      Value
    kFirst    0
    kSecond   1
    kThird    2
    kFourth   3
    
  */
  double colorFactor(GraniteColor graniteColor);

  /** Description:
    Returns the *color* for the specified granite *color* of this Granite Material object.
   
    Arguments:
    graniteColor (I) Granite *color*.
    
    Remarks:
    color() returns a 24-bit RGB *color*.
    
    graniteColor must be one of the following:
    
    @table
    Name      Value
    kFirst    0
    kSecond   1
    kThird    2
    kFourth   3
  */
  OdUInt32 color(GraniteColor graniteColor);

  /** Description:
    Sets the *color* factor for the specified granite *color* of this Granite Material object.
   
    Arguments:
    graniteColor (I) Granite *color*.
    colorFactor (I) Color factor. [0.0 .. 1.0]
    
    Remarks:
    There are four colors associated with a Granite Material object. 
    The *color* factors determine the relative amounts of the four granite colors.

    graniteColor must be one of the following:
    
    @table
    Name      Value
    kFirst    0
    kSecond   1
    kThird    2
    kFourth   3
    
    There are four colors associated with a Granite Material object. 
    To use less than four materials, make two or more of them the same,
    or set one or more of them to 0.
  */
  void setColorFactor(GraniteColor graniteColor, double colorFactor);

  /** Description:
    Sets the *color* for the specified granite *color* for this Granite Material object.
   
    Arguments:
    graniteColor (I) Granite *color*.
    color (I) 24-bit RGB *color*.
    
    Remarks:
    graniteColor must be one of the following:
    
    @table
    Name      Value
    kFirst    0
    kSecond   1
    kThird    2
    kFourth   3
    
    There are four colors associated with a Granite Material object. 
    To use less than four materials, make two or more of them the same,
    or set one or more of them to 0.
  */
  void setColor(GraniteColor graniteColor, OdUInt32 color);

  /** Description:
    Returns the *sharpness* of this Material object.

    Remarks:
    Returns a value in the range [0.0 .. 1.0]

    @table
    Value      Renders
    0.0        Colors are melded.
    1.0        Colors are discrete.
  */
  double sharpness();
  /** Description:
    Sets the *sharpness* of this Granite Material object.

    Arguments:
    sharpness (I) Sharpness. [0.0 .. 1.0]
 
    Remarks:
    @table
    Value      Renders
    0.0        Colors are melded.
    1.0        Colors are discrete.
  */
  void setSharpness(double sharpness);

  /** Description:
    Returns the *scale* of this Granite Material object.
    
    Remarks:
    The *scale* is with respect to the objects to which this Granite Material object
    are attached. Larger values result in a coarser texture with more graininess.
  */
  double scale();
  /** Description:
    Sets the *scale* of this Granite Material object.
    
    Arguments:
    scale (I) Scale.
    
    Remarks:
    The *scale* is with respect to the objects to which this Granite Material object
    are attached. Larger values result in a coarser texture with more graininess.
  */
  void setScale(double scale);

protected:
  OdAveGraniteMaterial();
  OdAveGraniteMaterial(OdAveMaterialImpl* pImpl);
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdAveGraniteMaterial object pointers.
*/
typedef OdSmartPtr<OdAveGraniteMaterial> OdAveGraniteMaterialPtr;

/** Description:
    This class represents AVE Marble Material properties for shaded entities.
    
    Remarks:
    AVE Marble Materials consist of a stone *color* and a vein *color*. 
    Library: TD_Ave

    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveMarbleMaterial : public OdAveMaterial
{
public:
  ODRX_DECLARE_MEMBERS(OdAveMarbleMaterial);

  virtual OdAve::MaterialType type();

  /** Description:
      Accesses the stone *color* for this Marble Material object.
      
      Remarks:
      stoneColor() returns a 24-bit RGB *color*.
  */
  OdUInt32 stoneColor();
  /** Description:
      Accesses the vein *color* for this Marble Material object.
      
      Remarks:
      veinColor() returns a 24-bit RGB *color*.
  */
  OdUInt32 veinColor();
  
  /** Arguments:
      color (I) 24-bit RGB *color*.
  */
  void stoneColor(OdUInt32 color);
  /** Arguments:
      color (I) 24-bit RGB *color*.
  */
  void veinColor(OdUInt32 color);

  /** Description:
    Returns the vein *turbulance* of this Marble Material object. 
    
    Remarks:
    Higher values result in more swirling of the veins,
    and take longer to render. Values in the range [1..10] are recommended.
  */
  OdUInt32 turbulence();
  /** Description:
    Sets the vein *turbulance* of this Marble Material object. 
    Arguments:
    turbulence (I) Turbulence.
    Remarks:
    Higher values result in more swirling of the veins,
    and take longer to render. Values in the range [1..10] are recommended.
 */
  void setTurbulence(OdUInt32 turbulence);

  /** Description:
    Returns the *sharpness* of this Marble Material object.

    Remarks:
    Returns a value in the range [0.0 .. 1.0]
 
    @table
    Value      Renders
    0.0        Colors are melded.
    1.0        Colors are discrete.
  */
  double sharpness();
  /** Description:
    Sets the *sharpness* of this Marble Material object.

    Arguments:
    sharpness (I) Sharpness. [0.0 .. 1.0]
 
    @table
    Value      Renders
    0.0        Colors are melded.
    1.0        Colors are discrete.
  */
  void setSharpness(double sharpness);


  /** Description:
    Returns the *scale* of this Marble Material object.
    
    Remarks:    
    The *scale* is with respect to the objects to which this Marble Material object
    are attached. Smaller values result in less veins.
  */
  double scale();
  
  /** Description:
    Sets the *scale* of this Marble Material object.
        
    Arguments:
    scale (I) Scale.
    
    Remarks:    
    The *scale* is with respect to the objects to which this Marble Material object
    are attached. Smaller values result in less veins.
  */
  void setScale(double scale);

protected:
  OdAveMarbleMaterial();
  OdAveMarbleMaterial(OdAveMaterialImpl* pImpl);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdAveMarbleMaterial object pointers.
*/
typedef OdSmartPtr<OdAveMarbleMaterial> OdAveMarbleMaterialPtr;

/** Description:
    This class represents Wood Material properties for shaded entities.
    Remarks:
    Wood materials consist of a bicolor woodgrain pattern.
    
    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveWoodMaterial : public OdAveMaterial
{
public:
  ODRX_DECLARE_MEMBERS(OdAveWoodMaterial);

  virtual OdAve::MaterialType type();

  /** Description:
    Returns the light *color* of this Material object.
    Remarks:
    lightColor() returns a 24-bit RGB *color*.
  */
  OdUInt32 lightColor();
  /** Description:
    Returns the dark *color* of this Wood Material object.
    Remarks:
    darkColor() returns a 24-bit RGB *color*.
  */
  OdUInt32 darkColor();
  /** Description:
    Sets the light *color* of this Wood Material object.
    Arguments:
    lightColor (I) 24-bit RGB *color*.
  */
  void setLightColor(OdUInt32 lightColor);
  /** Description:
    Sets the dark *color* of this Wood Material object.
    Arguments:
    darkColor (I) 24-bit RGB *color*.
  */
  void setDarkColor(OdUInt32 darkColor);

  /** Description:
    Returns the mixture of light vs. dark rings in this Wood Material object.
    Remarks:
    Returns a value in the range [0.0 .. 1.0].
    
    @table
    Value      Renders
    0.0        Mostly dark.
    1.0        Mostly light.
    
  */
  double lightDark();
  /** Description:
    Sets the mixture of light vs. dark rings in this Wood Material object.
    Arguments:
    lightDark (I) Light/Dark mixture.  [0.0 .. 1.0]
    
    @table
    Value      Renders
    0.0        Mostly dark.
    1.0        Mostly light.
  */
  void setLightDark(double lightDark);

  /** Description:
    Returns the ring density of this Wood Material object.
    
    Remarks: 
    The ring density is with respect to the objects to which this Wood Material object
    are attached. Smaller values result in a coarser texture with less rings.
  */
  double ringDensity();
  /** Description:
    Sets the ring density of this Wood Material object.
    Arguments:
    ringDensity (I) Ring Density. 
    Remarks: 
    The ring density is with respect to the objects to which this Wood Material object
    are attached. Smaller values result in a coarser texture with less rings.
  */
  void setRingDensity(double ringDensity);

  /** Description:
    Returns the ring width variation for this Wood Material object.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0].

    @table
    Value      Renders
    0.0        Rings are uniform.
    1.0        Rings have greatest variation.

  */
  double ringWidth();
  /** Description:
    Sets the ring width parameter for this Wood Material object.
    
    Arguments:
    ringWidth (I) Ring width parameter. [0.0 .. 1.0]
    Remarks:

    @table
    Value      Renders
    0.0        Rings are uniform.
    1.0        Rings have greatest variation.
  */
  void setRingWidth(double ringWidth);

  /** Description:
    Returns the ring shape parameters for this Wood Material object.
    
    Remarks:
    Returns a value in the range [0.0 .. 1.0].

    @table
    Value      Renders
    0.0        Circular rings.
    1.0        Most irregular rings.
  */ 
  double ringShape();
  /** Description:
    Sets the ring shape parameters for this Wood Material object.
    
    Arguments:
    ringShape (I) Ring shape parameter. [0.0 .. 1.0]
    Remarks:
    
    @table
    Value      Renders
    0.0        Circular rings.
    1.0        Most irregular rings.F
  */ 
  void setRingShape(double ringShape) ;

  /** Description:
    Returns the *scale* of this Wood Material object.
    
    Remarks:    
    The *scale* is with respect to the objects to which this Wood Material object
    are attached. Smaller values result in a finer texture with more rings.
  */
  double scale();
  
  /** Description:
    Sets the *scale* of this Wood Material object.
        
    Arguments:
    scale (I) Scale.
    
    Remarks:    
    The *scale* is with respect to the objects to which this Wood Material object
    are attached. Smaller values result in a finer texture with rings.
  */
  void setScale(double scale);

protected:
  OdAveWoodMaterial();
  OdAveWoodMaterial(OdAveMaterialImpl* pImpl);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdAveWoodMaterial object pointers.
*/
typedef OdSmartPtr<OdAveWoodMaterial> OdAveWoodMaterialPtr;

/** Description:
  Returns an Iterator object that can be 
  used to traverse the OdAveMaterial objects in the specified *database* or material library.
  
  Arguments:
  pDb (I) Pointer to the *database*.
  pStreamBuf (I) Pointer to the stream buffer.
*/
AVE_EXPORT OdRxIteratorPtr oddbGetMaterials(OdDbDatabase* pDb);

AVE_EXPORT void oddbGetMaterialIds(OdDbDatabase* pDb, OdDbObjectIdArray& ids);

AVE_EXPORT OdRxIteratorPtr oddbGetMaterials(OdStreamBuf* pStreamBuf);

#include "../TD_PackPop.h"

#endif // OD_AVEMATERIAL_H

