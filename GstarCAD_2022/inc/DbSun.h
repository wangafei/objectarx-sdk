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


#ifndef _OD_DBSUN_H_INCLUDED_
#define _OD_DBSUN_H_INCLUDED_

#include "TD_PackPush.h"

#include "Gi/GiLightTraits.h"
#include "DbLight.h"



/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSun : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSun);

  OdDbSun();

  ~OdDbSun();
  
  virtual DrawableType drawableType() const;
  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  
  OdGiDrawable* drawable();

  virtual void setGsNode(OdGsNode* gsnode);
  
  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*& replaceObj,
    OdDbObjectId& replaceId,
    OdBool& exchangeXData);
  
  virtual bool isOn() const;

  virtual OdGsNode* gsNode() const;

  virtual OdResult setOn(bool value);


  virtual double intensity() const;


  virtual OdResult setIntensity(double intensity);

 
  virtual const OdCmColor& sunColor() const;


  virtual OdResult setSunColor(const OdCmColor& color);


  virtual const OdGiShadowParameters& shadowParameters() const;


  virtual void setShadowParameters(const OdGiShadowParameters& params);


  virtual OdResult setDateTime(const OdDbDate& datetime);


  virtual const OdDbDate& dateTime() const;


  virtual OdResult setDayLightSavingsOn(bool value);


  virtual bool isDayLightSavingsOn() const;


  virtual OdResult setAzimuth(double azimuth);


  virtual double azimuth() const;


  virtual OdResult setAltitude(double altitude);


  virtual double altitude() const;


  virtual const OdGeVector3d& sunDirection() const;


  virtual void setSunDirection(const OdGeVector3d& sundir);


  virtual OdResult setSkyParameters(const OdGiSkyParameters& params);


  virtual OdResult skyParameters(OdGiSkyParameters& params) const;
};

typedef OdSmartPtr<OdDbSun> OdDbSunPtr;

#include "TD_PackPop.h"

#endif

