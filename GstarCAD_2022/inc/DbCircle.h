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




#ifndef _OD_DB_CIRCLE_
#define _OD_DB_CIRCLE_

#include "TD_PackPush.h"

#include "DbCurve.h"

class OdDbCircleImpl;

/** Description:
    This class represents Circle entities in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbCircle : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbCircle);

  OdDbCircle();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDbCircle(const OdGePoint3d& cntr, const OdGeVector3d& nrm, double radius);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDbCircle();

  /** Description:
    Returns the WCS *center* of this curve (DXF 10 in WCS).
  */
  OdGePoint3d center() const;

  /** Description:
    Sets the WCS *center* of this curve (DXF 10 in WCS).
    Arguments:
    center (I) Center.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setCenter(
    const OdGePoint3d& center);

  /** Description:
    Returns the *radius* of this curve (DXF 40).
  */
  double radius() const;

  /** Description:
    Sets the *radius* of this curve (DXF 40).
    Arguments:
    radius (I) Radius.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setRadius(
    double radius);

  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;

  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setThickness(
    double thickness);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdBool isPlanar() const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual OdBool isClosed() const;

  virtual OdBool isPeriodic() const;

  virtual OdResult getStartParam(
    double& startParam) const;

  virtual OdResult getEndParam (
    double& endParam) const;


  virtual OdResult getStartPoint(
    OdGePoint3d& startPoint) const;

  virtual OdResult getEndPoint(
    OdGePoint3d& endPoint) const;

  virtual OdResult getPointAtParam(
    double param, 
    OdGePoint3d& pointOnCurve) const;

  virtual OdResult getParamAtPoint(
    const OdGePoint3d& pointOnCurve, 
    double& param) const;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm, 
    OdDbEntity*& pCopy) const;

  virtual OdResult getDistAtParam( double param, double& dist ) const;

  virtual OdResult getParamAtDist( double dist, double& param ) const;

  virtual OdResult getFirstDeriv (
    double param,
    OdGeVector3d& firstDeriv) const;

  virtual OdResult getSecondDeriv (
    double param,
    OdGeVector3d& secondDeriv) const;

  virtual OdResult getArea(
    double& area) const;

  TD_USING(OdDbCurve::getFirstDeriv);
  TD_USING(OdDbCurve::getSecondDeriv);

  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);

  double     circumference() const;
  OdResult   setCircumference(double);
  double     diameter() const;
  OdResult   setDiameter(double);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbCircle object pointers.
*/
typedef OdSmartPtr<OdDbCircle> OdDbCirclePtr;

#include "TD_PackPop.h"

#endif
