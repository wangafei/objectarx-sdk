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


#ifndef __OD_DB_LIGHT__
#define __OD_DB_LIGHT__

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "Gi/GiLightTraits.h"

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLight : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLight);

  OdDbLight();

  enum PhysicalIntensityMethod
  {
    kPeakIntensity = 0,
    kFlux,
    kIlluminance
  };

  enum LampColorType
  {
    kKelvin = 0,
    kPreset
  };

  enum LampColorPreset
  {
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

  enum GlyphDisplayType
  {
    kGlyphDisplayAuto = 0,
    kGlyphDisplayOn,
    kGlyphDisplayOff
  };

  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDbLight();

  virtual OdResult subClose();

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  
  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*& replaceObj,
    OdDbObjectId& replaceId,
    OdBool& exchangeXData);
  
  //*/
 // Gcad(Add)
  /*/
  virtual OdResult	 subClose();

  virtual OdResult getGripPoints (OdDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, const OdGeVector3d &curViewDir, const int bitflags) const ;
  virtual OdResult moveGripPointsAt (const OdDbVoidPtrArray &gripAppData, const OdGeVector3d &offset, const int bitflags) ;

  virtual OdResult getTransformedCopy(const OdGeMatrix3d & xform,OdDbEntity *& pEnt) const;

  virtual OdResult highlight(const OdDbFullSubentPath& subId, 
					  const bool highlightAll) const;

  virtual OdResult unhighlight(const OdDbFullSubentPath& subId, 
					  const bool highlightAll) const;
  virtual void list() const;

  virtual bool castShadows() const;
  virtual void setCastShadows(bool newVal);
  virtual bool receiveShadows() const;
  virtual void setReceiveShadows(bool newVal);

  virtual OdResult deepClone(OdDbObject* pOwner,OdDbObject*& pClonedObject,
									  OdDbIdMapping& idMap,bool isPrimary = true) const;

  virtual OdResult wblockClone(OdRxObject* pOwnerObject, OdDbObject*& pClonedObject, 
									  OdDbIdMapping& idMap, bool isPrimary ) const;

  virtual OdResult copyFrom (const OdRxObject* other);

  /// <returns>
  /// Returns Acad::eOk if the extents are valid.
  /// </returns>
  virtual OdResult getGeomExtents(OdDbExtents3d& extents) const;
  //*/
  ////////////////////Gcad(Add)/////////////////////////////
  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual DrawableType drawableType() const;
  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);
  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  virtual bool castShadows() const;
  virtual void setCastShadows(bool newVal);
  virtual bool receiveShadows() const;
  virtual void setReceiveShadows(bool newVal);

  virtual OdResult copyFrom(const OdRxObject* other);

  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode     osnapMode,
    OdGsMarker          gsSelectionMark,
    const OdGePoint3d&  pickPoint,
    const OdGePoint3d&  lastPoint,
    const OdGeMatrix3d& viewXform,
    OdGePoint3dArray&   snapPoints,
    OdDbIntArray &   geomIds) const;

  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode     osnapMode,
    OdGsMarker          gsSelectionMark,
    const OdGePoint3d&  pickPoint,
    const OdGePoint3d&  lastPoint,
    const OdGeMatrix3d& viewXform,
    OdGePoint3dArray&   snapPoints,
    OdDbIntArray &   geomIds,
    const OdGeMatrix3d& insertionMat) const;

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d & xform, OdDbEntity *& pEnt) const;
  virtual void subList() const;
 
  virtual OdResult subGetGripPoints(OdDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, const OdGeVector3d &curViewDir, const int bitflags) const;
  
  virtual OdResult subMoveGripPointsAt(const OdDbVoidPtrArray &gripAppData, const OdGeVector3d &offset, const int bitflags);

  virtual OdResult subDeepClone(OdDbObject* pOwner, OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap, OdBool isPrimary = true) const;

  virtual OdResult subWblockClone(OdRxObject* pOwnerObject, OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap, OdBool isPrimary /* = true */) const;

  virtual OdResult subHighlight(const OdDbFullSubentPath& subId,
    const OdBool highlightAll) const;

  virtual OdResult subUnhighlight(const OdDbFullSubentPath& subId,
    const OdBool highlightAll) const;

  virtual OdResult subGetGeomExtents(OdDbExtents& extents) const;

  // Gcad(Modify)
  const OdString& name() const;
  // Gcad(Modify)
  OdResult setName(const OdString & name);

  OdGiDrawable::DrawableType lightType() const;
  // Gcad(Modify)
  OdResult setLightType(OdGiDrawable::DrawableType type);

  bool isOn() const;
  // Gcad(Modify)
  OdResult setOn(bool value);

  bool isPlottable() const;
  // Gcad(Modify)
  OdResult setIsPlottable(bool plot);

  const OdCmColor& lightColor() const;
  // Gcad(Modify)
  OdResult setLightColor(const OdCmColor& color);

  double intensity() const;
  // Gcad(Modify)
  OdResult setIntensity(double intensity);
  
  void setShadowParameters(const OdGiShadowParameters& params);
  const OdGiShadowParameters& shadowParameters() const;

  void setLightAttenuation(const OdGiLightAttenuation& params);
  const OdGiLightAttenuation& lightAttenuation() const;

  // Gcad(Modify)
  OdResult setPosition(const OdGePoint3d& pos);
  const OdGePoint3d& position() const;
  
  const OdGePoint3d& targetLocation() const;
  // Gcad(Modify)
  OdResult setTargetLocation(const OdGePoint3d& newVal);

  // Gcad(Modify)
  OdResult setHotspotAndFalloff(double hotspot, double falloff);
  double hotspotAngle() const;
  double falloffAngle() const;

  OdGeVector3d lightDirection() const;
  // Gcad(Modify)
  OdResult setLightDirection(const OdGeVector3d& lightvec);

  // Photometric properties

  PhysicalIntensityMethod physicalIntensityMethod() const;
  OdResult setPhysicalIntensityMethod(PhysicalIntensityMethod physIntMethod);

  double physicalIntensity() const;
  OdResult setPhysicalIntensity(double physIntensity);

  double illuminanceDistance() const;
  OdResult setIlluminanceDistance(double illumDistance);

  LampColorType lampColorType() const;
  OdResult setLampColorType(LampColorType colorType);

  double lampColorTemp() const;
  OdResult setLampColorTemp(double colorTemp);

  LampColorPreset lampColorPreset() const;
  OdResult setLampColorPreset(LampColorPreset colorPreset);

  OdResult lampColorRGB(OdGiColorRGB& rgbColor) const;
  OdResult setLampColorRGB(OdGiColorRGB color);
  OdResult resultingColor(OdCmColor& rgbColor) const;

  OdResult webFile(OdString& webFile) const;
  OdResult setWebFile(const OdChar* webFile);

  OdResult webRotation(OdGeVector3d& rotation) const;
  OdResult setWebRotation(OdGeVector3d rotation);

  bool hasTarget() const;
  OdResult setHasTarget(bool bTarget);

  OdResult shadowParameters(OdGiShadowParameters2& shadowParams) const;
  OdResult setShadowParameters(const OdGiShadowParameters2 &shadowParams);

  GlyphDisplayType glyphDisplay() const;
  void setGlyphDisplay(GlyphDisplayType type);
  virtual OdResult subGetClassID(
	  CLSID* pClsid) const;
};

typedef OdSmartPtr<OdDbLight> OdDbLightPtr;

#include "TD_PackPop.h"

#endif // __OD_DB_LIGHT__
