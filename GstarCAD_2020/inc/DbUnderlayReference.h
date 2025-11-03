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


#ifndef __OD_DB_UNDERLAY_REFERENCE__
#define __OD_DB_UNDERLAY_REFERENCE__

#include "TD_PackPush.h"
#include "DbEntity.h"
#include "Ge/GePoint2dArray.h"

/** Description:
    This class represents underlays, where OdDbUnderlayReference controls the placement of the
	underlay in the drawing and OdDbUnderlayDefinition links to the underlay content.
	
    {group:Other_Classes}
*/
class OdUnderlayLayer;

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbUnderlayReference : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbUnderlayReference);

  virtual ~OdDbUnderlayReference();
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual void subViewportDraw(
    OdGiViewportDraw* pVd);

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, const OdGePlane& projPlane, 
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, OdGePoint3dArray& points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  // method with wrong input parameters - must be removed in next release
  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode /*osnapMode*/, 
    OdGsMarker        /*gsSelectionMark*/, 
    const OdGePoint3d& /*pickPoint*/,
    const OdGePoint3d& /*lastPoint*/, 
    const OdGeMatrix3d& /*viewXform*/, 
    const OdGeMatrix3d& /*ucs*/, 
    OdGePoint3dArray& /*snapPoints*/ ) const { return Oda::eNotApplicable; }

  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& xWorldToEye,
    OdGePoint3dArray& snapPoints,
    OdDbIntArray&geomIds) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  OdGePoint3d position() const;
  OdResult setPosition(const OdGePoint3d& position);

  OdGeScale3d scaleFactors() const;
  OdResult setScaleFactors(const OdGeScale3d& scale);

  double rotation() const;
  OdResult setRotation(double rotation);

  OdGeVector3d normal() const;
  OdResult setNormal(const OdGeVector3d& normal);

  OdGeMatrix3d transform() const;
  OdResult setTransform(const OdGeMatrix3d& transform);

  OdDbObjectId definitionId() const;
  OdResult setDefinitionId(OdDbObjectId id);

  const OdGePoint2dArray& clipBoundary() const;
  OdResult setClipBoundary(const OdGePoint2d* clipBoundary, OdUInt32 nbPts);
  //TODO:....
  OdResult        setClipBoundary(const OdGePoint2dArray& clipBoundary);

  bool isClipped() const;
  OdResult setIsClipped(bool value);

  OdUInt8 contrast() const;
  OdResult setContrast(OdUInt8 value);

  OdUInt8 fade() const;
  OdResult setFade(OdUInt8 value);

  bool isOn() const;
  OdResult setIsOn(bool value);

  bool isMonochrome() const;
  OdResult setIsMonochrome(bool value);

  bool isAdjustedForBackground() const;
  OdResult setIsAdjustedForBackground(bool value);

  // must be overriden

  virtual bool isFrameVisible() const = 0;
  virtual bool isFramePlottable() const = 0;
  virtual bool subIsContentSnappable() const = 0;

  OdUInt32 underlayLayerCount() const;
  OdResult getUnderlayLayer(int index, OdUnderlayLayer& layer) const;
  OdResult setUnderlayLayer(int index, const OdUnderlayLayer& layer);

  static OdUInt8 contrastLowerLimit();
  static OdUInt8 contrastUpperLimit();
  static OdUInt8 contrastDefault();
  static OdUInt8 fadeLowerLimit();
  static OdUInt8 fadeUpperLimit();
  static OdUInt8 fadeDefault();

  bool isClipInverted() const;

  //TODO::
  OdResult setClipInverted(bool value);
  OdResult generateClipBoundaryFromPline(OdDbObjectId plId);

  OdResult subClose();

  virtual void setIsForceRegen(bool bForceRegen);
};

typedef OdSmartPtr<OdDbUnderlayReference> OdDbUnderlayReferencePtr;


/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDwfReference : public OdDbUnderlayReference
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDwfReference);

  OdDbDwfReference();

  virtual ~OdDbDwfReference();
  virtual bool isFrameVisible() const;
  virtual bool isFramePlottable() const;

  virtual bool subIsContentSnappable() const;
  virtual OdResult subGetClassID(CLSID* pClsid) const;
};

typedef OdSmartPtr<OdDbDwfReference> OdDbDwfReferencePtr;


/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDgnReference : public OdDbUnderlayReference
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDgnReference);

  OdDbDgnReference();
  virtual ~OdDbDgnReference();

  virtual bool isFrameVisible() const;
  virtual bool isFramePlottable() const;

  virtual bool subIsContentSnappable() const;
  virtual OdResult subGetClassID(CLSID* pClsid) const;

  void setXrefDepth(int depth);
};

typedef OdSmartPtr<OdDbDgnReference> OdDbDgnReferencePtr;

/** Description:

{group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPdfReference : public OdDbUnderlayReference
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPdfReference);

  OdDbPdfReference();
  virtual ~OdDbPdfReference();

  virtual bool isFrameVisible() const;
  virtual bool isFramePlottable() const;

  virtual bool subIsContentSnappable() const;
  virtual OdResult subGetClassID(CLSID* pClsid) const;

  virtual OdUInt32 subSetAttributes (OdGiDrawableTraits * traits);

  static OdUInt8 contrastDefault();
  static OdUInt8 fadeDefault();
};

typedef OdSmartPtr<OdDbPdfReference> OdDbPdfReferencePtr;

#include "TD_PackPop.h"

#endif // __OD_DB_UNDERLAY_REFERENCE__
