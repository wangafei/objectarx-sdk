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


#ifndef _ODDBBACKGROUND_INCLUDED_
#define _ODDBBACKGROUND_INCLUDED_

#include "TD_PackPush.h"

#include "DbObject.h"

#define ODDB_BACKGROUND_DICTIONARY ACAD_BACKGROUND

/** Description:
    This class is a base class for all background objects.

    Remarks:
    Database-resident background objects are stored in the NamedObjectsDictionary
    under ACAD_BACKGROUND.
    
    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbBackground : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBackground);

  OdDbBackground();
  virtual ~OdDbBackground();

  /** Description:
    Returns the OdGiDrawable for this Background object.
  */
  virtual OdGiDrawable* drawable();
};

typedef OdSmartPtr<OdDbBackground> OdDbBackgroundPtr;

/** Description:
    This class is for a solid background.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbSolidBackground : public OdDbBackground
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSolidBackground);

  OdDbSolidBackground();
  virtual ~OdDbSolidBackground();

  void setColorSolid(const OdCmEntityColor& color);
  OdCmEntityColor colorSolid() const;

  // OdDbObject overridden functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdRxObject overridden functions

  virtual OdResult copyFrom(const OdRxObject* pSource);

  // OdGiDrawable overridden functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdGiDrawable::DrawableType drawableType() const;
};

typedef OdSmartPtr<OdDbSolidBackground> OdDbSolidBackgroundPtr;

/** Description:
    This class is for a gradient background.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbGradientBackground : public OdDbBackground
{
public:
  ODDB_DECLARE_MEMBERS(OdDbGradientBackground);

  OdDbGradientBackground();
  virtual ~OdDbGradientBackground();

  void setColorTop(const OdCmEntityColor& color);
  OdCmEntityColor colorTop() const;
  void setColorMiddle(const OdCmEntityColor& color);
  OdCmEntityColor colorMiddle() const;
  void setColorBottom(const OdCmEntityColor& color);
  OdCmEntityColor colorBottom() const;
  void setHorizon(double horizon);
  double horizon() const;
  void setHeight(double height);
  double height() const ;
  void setRotation(double rotation);
  double rotation() const;

  // OdDbObject overridden functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdRxObject overridden functions

  virtual OdResult copyFrom(const OdRxObject* pSource);

  // OdGiDrawable overridden functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdGiDrawable::DrawableType drawableType() const;
};

typedef OdSmartPtr<OdDbGradientBackground> OdDbGradientBackgroundPtr;

/** Description:
    This class is for an image background.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbImageBackground : public OdDbBackground
{
public:

  ODDB_DECLARE_MEMBERS(OdDbImageBackground);

  OdDbImageBackground();
  virtual ~OdDbImageBackground();

  void setImageFilename(const OdChar* filename);
  const OdString& imageFilename() const;
  void setFitToScreen(bool bFitToScreen);
  bool fitToScreen() const;
  void setMaintainAspectRatio(bool bMaintainAspectRatio);
  bool maintainAspectRatio() const;
  void setUseTiling(bool bUseTiling);
  bool useTiling() const;
  void setXOffset(double xOffset);
  double xOffset() const;
  void setYOffset(double yOffset);
  double yOffset() const;
  void setXScale(double xScale);
  double xScale() const;
  void setYScale(double yScale);
  double yScale() const;

  // OdDbObject overridden functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdRxObject overridden functions

  virtual OdResult copyFrom(const OdRxObject* pSource);

  // OdGiDrawable overridden functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdGiDrawable::DrawableType drawableType() const;
};

typedef OdSmartPtr<OdDbImageBackground> OdDbImageBackgroundPtr;

/** Description:
    This class implements a ground plane for a background object in a viewport.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbGroundPlaneBackground : public OdDbBackground
{
public:
  ODDB_DECLARE_MEMBERS(OdDbGroundPlaneBackground);

  OdDbGroundPlaneBackground();
  virtual ~OdDbGroundPlaneBackground();

  void setColorSkyZenith(const OdCmEntityColor& color);
  OdCmEntityColor colorSkyZenith() const;
  void setColorSkyHorizon(const OdCmEntityColor& color);
  OdCmEntityColor colorSkyHorizon() const;
  void setColorUndergroundHorizon(const OdCmEntityColor& color);
  OdCmEntityColor colorUndergroundHorizon() const;
  void setColorUndergroundAzimuth(const OdCmEntityColor& color);
  OdCmEntityColor colorUndergroundAzimuth() const;
  void setColorGroundPlaneNear(const OdCmEntityColor& color);
  OdCmEntityColor colorGroundPlaneNear() const;
  void setColorGroundPlaneFar(const OdCmEntityColor& color);
  OdCmEntityColor colorGroundPlaneFar() const;

  // OdDbObject overridden functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdRxObject overridden functions

  virtual OdResult copyFrom(const OdRxObject* pSource);

  // OdGiDrawable overridden functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdGiDrawable::DrawableType drawableType() const;
};

typedef OdSmartPtr<OdDbGroundPlaneBackground> OdDbGroundPlaneBackgroundPtr;

/** Description:
    This class implements a sky for a background object in a viewport.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbSkyBackground : public OdDbBackground
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSkyBackground);

  OdDbSkyBackground();
  virtual ~OdDbSkyBackground();

  //Gcad(Modify):returns:void->OdResult
  OdResult setSunId(const OdDbObjectId& sunId);
  OdDbObjectId sunId() const;

  // OdDbObject overridden functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdRxObject overridden functions

  virtual OdResult copyFrom(const OdRxObject* pSource);

  // OdGiDrawable overridden functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdGiDrawable::DrawableType drawableType() const;
};

typedef OdSmartPtr<OdDbSkyBackground> OdDbSkyBackgroundPtr;

/** \details
    This class implements a image based lighting for a background object in a viewport.

    \sa
    TD_Db
    <group OdDb_Classes>
*/
class TOOLKIT_EXPORT OdDbIBLBackground : public OdDbBackground
{
public:
  ODDB_DECLARE_MEMBERS(OdDbIBLBackground);

  OdDbIBLBackground();
  virtual ~OdDbIBLBackground();

  virtual OdResult setEnable(const bool bEnable);
  virtual bool enable() const;
  virtual OdResult setIBLImageName(const OdString &filename);
  virtual const OdString &IBLImageName() const;
  virtual OdResult setRotation(const double rotation);
  virtual double rotation() const;
  virtual OdResult setDisplayImage(const bool bDisplay);
  virtual bool displayImage() const;
  virtual OdResult setSecondaryBackground(const OdDbObjectId &bgId);
  virtual OdDbObjectId secondaryBackground() const;

  virtual void setDataFrom(const OdDbIBLBackground *pBkgnd);

  // OdDbObject overridden functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdRxObject overridden functions

  //virtual void copyFrom(const OdRxObject* pSource);

  // OdGiDrawable overridden functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdGiDrawable::DrawableType drawableType() const;
};

typedef OdSmartPtr<OdDbIBLBackground> OdDbIBLBackgroundPtr;

TOOLKIT_EXPORT OdDbObjectId oddbGetBackgroundDictionaryId(OdDbDatabase* pDb, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbDictionaryPtr oddbGetBackgroundDictionary(OdDbDatabase* pDb, OdDb::OpenMode mode, bool createIfNotFound = false);

TOOLKIT_EXPORT OdResult getBackgroundDictionary(OdDbDatabase* pDb,
  OdDbDictionary*& pDict,
  OdDb::OpenMode mode,
  bool createIfNonExist);
TOOLKIT_EXPORT OdResult getBackgroundDictionary(OdDbDatabase* pDb,
  OdDbDictionary*& pDict,
  OdDb::OpenMode mode);

#include "TD_PackPop.h"

#endif // _ODDBBACKGROUND_INCLUDED_
