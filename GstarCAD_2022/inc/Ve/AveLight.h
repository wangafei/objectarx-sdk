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



#ifndef OD_AVELIGHT_H
#define OD_AVELIGHT_H

#include "../TD_PackPush.h"

#include "../RxObject.h"
#include "../DbObjectId.h"
#include "../IdArrays.h"
#include "../Ve/AveDefs.h"
#include "../Gs/GsLight.h"

class OdGePoint3d;
class OdGeVector3d;

class OdAveLightImpl;
class OdAveLight;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdAveLight object pointers.
*/
typedef OdSmartPtr<OdAveLight> OdAveLightPtr;


/** Description:
    This class represents AVE Light properties.

    Remarks:
    AVE Light properties may be attached to OdDbBlockReference objects.
    
    Library: TD_Ave
    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveLight : public OdGsLight
{
public:
  ODRX_DECLARE_MEMBERS(OdAveLight);

  /** Description:
    Creates a Light object from the specified OdDbBlockReference.
    
    Arguments:
    blockRefId (I) Object ID of the block reference.
    
    Remarks:
    The new Light object is associated with the specified block reference.
     
    Returns a SmartPointer to the new Light object.
  */
  static OdAveLightPtr getLight(const OdDbObjectId& blockRefId);
  /** Description:
    Returns the Light *name* from the specified OdDbBlockReference.
    
    Arguments:
    blockRefId (I) Object ID of the block reference.
  */
  static OdString getLightName(const OdDbObjectId& blockRefId);

  /** Description:
    Saves the Light properties to the OdDbBlockReference to which this Light object is associated.

    Arguments:
    pDb (I) Pointer to the *database*.
      
    Remarks:
    If pDb is null, the *database* containing this Light object is used.
  */
  OdResult writeLight(OdDbDatabase* pDb = 0, const OdDbHandle& holderHandle = 0, const OdDbObjectId& ownerId = OdDbObjectId::kNull);

  /** Description:
    Returns the *type* of this Light object.
    Remarks:
    type() returns one of the following:
    
    @table
    Name                        Value
    OdGsLight::kPointLight      0
    OdGsLight::kDistantLight    1
    OdGsLight::kSpotlight       2

  */
  OdGsLight::LightType type() const;
  /** Description:
    Sets the *type* of this Light object.
    Arguments:
    type (I) Light *type*.
    Remarks:
    type must be one of the following:
    
    @table
    Name                        Value
    OdGsLight::kPointLight      0
    OdGsLight::kDistantLight    1
    OdGsLight::kSpotlight       2
  */
  void setType(OdGsLight::LightType type);

  /** Description:
    Returns the *name* of this Light object.
    
  */
  OdString name() const;
  
  /** Description:
    Sets the *name* of this Light object.
    name (I) Name.
    Remarks:
    Names are truncated to 8 characters.
  */
  void setName(const OdString& name);

  /** Description:
    Returns the *intensity* of this Light object.
    Remarks:
    Returns a value in the range [0.0 .. 1.0].
  */
  double intensity() const;
  /** Description:
    Sets the *intensity* of this Light object.
    Remarks:
    intensity (I) Intensity. [0.0 .. 1.0]
  */
  void setIntensity(double intensity);

  /** Description:
    Returns the *color* of this Light object.
    
    Remarks:
    color() returns a 24-bit RGB *color*.
  */
  OdUInt32 color() const;
  
  /** Description:
    Sets the *color* of this Light object.
    
    Arguments:
    color (I) 24-bit RGB *color*.
  */
  void setColor(OdUInt32 color);

  /** Description:
    Returns the WCS *position* of this Light object. 
  */
  OdGePoint3d position() const;
  
  /** Description:
    Returns the WCS *target* of this Light object. 
  */
  OdGePoint3d target() const;

  /** Description:
    Returns the WCS *direction* of this Light object. 
  */
  OdGeVector3d direction() const;
  
  /** Description:
    Sets the WCS *position* of this Light object.
    
    Arguments:
    position (I) Position. 
  */
  void setPosition(const OdGePoint3d& position);
 
  /** Description:
    Sets the WCS *target* of this Light object.
    
    Arguments:
    target (I) Target. 
  */
  void setTarget(const OdGePoint3d& target);
  /** Description:
    Sets the WCS *direction* of this Light object.
    
    Arguments:
    fromPoint (I) From point.
    toPoint (I) To point. 
  */
  void setDirection(const OdGePoint3d& fromPoint, const OdGePoint3d& toPoint);

  /** Description:
    Returns the *attenuation* of this Light object. 
    
    Remarks:
    attenuation() returns one of the following:
    
    @table
    Name                             Value      
    OdGsLight::kAttenNone            0          
    OdGsLight::kAttenInverseLinear   1          
    OdGsLight::kAttenInverseSquare   2
  */
  OdGsLight::LightAttenuation attenuation() const;
  
  /** Description:
    Sets the *attenuation* of this Light object. 
    
    Arguments:
    attenuation (I) Attenuation.
    Remarks:
    attenuation must be one of the following:
    
    @table
    Name                             Value      
    OdGsLight::kAttenNone            0          
    OdGsLight::kAttenInverseLinear   1
    OdGsLight::kAttenInverseSquare   2
  */
  void setAttenuation(OdGsLight::LightAttenuation attenuation);

  /** Description:
      Specifies the cone angles for spotlight (OdAve::kSpotLight).
      Inner cone defines the brightest cone of light(hotspot, beam angle).
      Outer cone defines the full cone of light(falloff, field angle).
      These values can range from 0 to 80 degrees.
  */
  
  /** Description:
    Returns the inner cone angle for this kSpotLight Light object.
    
    Remarks:
    The inner cone angle is one-half the beam angle, which defines the hotspot 
    or brightest cone of light    

    innerConeAngle() has a range of [0..80].
    
    Note:
    All angles are expressed in degrees.
  */
  double innerConeAngle() const;
  /** Description:
    Returns the outer cone angle for this kSpotLight Light object.
    
    Remarks:
    The outer cone angle is one-half the field angle, which defines the 
    falloff or full cone of light.
    
    outerConeAngle() has a range of [0..80].
    
    Note:
    All angles are expressed in degrees.
  */
  double outerConeAngle() const;
  
  /** Description:
    Sets the cone angles for this kSpotLight Light object.
 
    Arguments:
    innerConeAngle (I) Inner cone angle. [0..80]
    outerConeAngle (I) Outer cone angle. [0..80]
    Remarks:
    The inner cone angle is one-half the beam angle, which defines the hotspot or brightest cone of light    
 
    The outer cone angle is one-half the field angle, which defines the falloff or full cone of light.

    Note:
    All angles are expressed in degrees.
   */
  void setConeAngle(double innerConeAngle, double outerConeAngle);

  /** Description:
    Returns true if and only if shadows are enabled for this Light object.
  */
  bool isShadowOn() const;
  /** Description:
    Controls shadows for this Light object.
    Arguments:
    shadowOn (I) Controls shadows.
  */
  void setShadowOn(bool shadowOn);

  /** Description:
    Returns true if and only if volumetric/raytraced shadows are 
    enabled for this Light object.
  */
  bool isShadowVolumes() const;
  /** Description:
    Controls volumetric/raytraced shadows for this Light object.
    Arguments:
    shadowVolumes (I) Controls shadows.
  */
  void setShadowVolumes(bool);

  /** Description:
    Accesses the size of the shadow map for this Light object.
    Arguments:
    MapSize (I) Shadow map size. [64..4096]
    Remarks:
    The shadow map size is the size, in pixels, of one edge of the shadow map.
    
    Remarks:
    shadowMapSize() has a domain and a range of [64..4096].     
    
    The smaller the size, the faster but less accurate the rendering.
  */
  OdInt16 shadowMapSize() const;

  void shadowMapSize(OdInt16 mapSize);

  /** Description:
    Returns the softness (fuzziness) of shadow-mapped shadows for this Light object.
    
    Remarks:
    shadowSoftness() has a range of [1..10].
    
    Shadow softness represents the number of shadow-edge pixels 
    blended into the image.
   */
  double shadowSoftness() const;
  /** Description:
    Sets the softness (fuzziness) of shadow-mapped shadows for this Light object.
    
    Arguments:
    shadowSoftness (I) Shadow softness. [1..10]
    
    Remarks:
    Shadow softness represents the number of shadow-edge pixels 
    blended into the image.
    
    Values in the range [2..4] typically give the best results.
   */
  void setShadowSoftness(double shadowSoftness);

  /** Description:
    Returns the shadow bounding objects for this Light object.
    Arguments:
    objectIds (O) Receives the array of Object IDs. 
    
  */
  void shadowBoundingObjects(OdDbObjectIdArray& objectIds) const;
  /** Description:
    Sets the shadow bounding objects for this Light object.
    Arguments:
    objectIds (I) Array of Object IDs. 
  */
  void setShadowBoundingObjects(const OdDbObjectIdArray& objectIds);
  /** Description:
    Adds the specified OdDbDatabase object to the shadow bounding objects for this Light object.
    Arguments:
    objectId (I) Object ID to add. 
  */
  void addShadowBoundingObject(const OdDbObjectId& objectId);

  /** Description:
    Returns the Object ID of the OdDbBlockReference associated with this Light object.
  */
  OdDbObjectId holderId() const;

protected:
  /** Description:
      Constructors
  */
  OdAveLight();
  OdAveLight(OdAveLightImpl* pImpl);
  
  OdAveLightImpl* m_pImpl;
};

/** Description:
  Returns an Iterator object that can be 
  used to traverse the OdAveLight objects in the specified *database*.
  
  Arguments:
  pDb (I) Pointer to the *database*.
*/
AVE_EXPORT OdRxIteratorPtr oddbGetLights(OdDbDatabase* pDb);

#include "../TD_PackPop.h"

#endif // OD_AVELIGHT_H

