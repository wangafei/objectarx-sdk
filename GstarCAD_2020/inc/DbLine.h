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




#ifndef _OD_DB_LINE_
#define _OD_DB_LINE_

#include "TD_PackPush.h"

#include "DbCurve.h"

/** Description:
    This class represents Line entities in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLine : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLine);

  OdDbLine();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDbLine(const OdGePoint3d& start, const OdGePoint3d& end);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDbLine();

  /** Description:
    Returns the WCS start point of this curve (DXF 10).
  */
  OdGePoint3d startPoint() const;

  /** Description:
    Sets the WCS start point of this curve (DXF 10).
    
    Arguments:
    startPoint (I) Start point.	

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult  setStartPoint(
    const OdGePoint3d& startPoint);

  /** Description:
    Returns the WCS end point of this curve (DXF 11).
  */
  OdGePoint3d endPoint() const;

  /** Description:
    Sets the WCS end point of this curve (DXF 11).
    
    Arguments:
    endPoint (I) End point.

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setEndPoint(
    const OdGePoint3d& endPoint);

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

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subGetGeomExtents(
    OdDbExtents& extents) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  
  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

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

  /*
     void getOffsetCurvesGivenPlaneNormal(
       const OdGeVector3d& normal, double offsetDist,
       OdRxObjectPtrArray& offsetCurves) const;
  */

  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPoint,
    OdGePoint3d& pointOnCurve,
    OdBool extend = kFalse) const;

  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPoint,
    const OdGeVector3d& normal,
    OdGePoint3d& pointOnCurve,
    OdBool extend = kFalse) const;

  /**
  Gcad(Add):增加兼容接口
  */
  OdResult getOffsetCurvesGivenPlaneNormal(
        const OdGeVector3d& normal, double offsetDist,
        OdDbVoidPtrArray& offsetCurves) const;

  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);
  
  virtual int getUnknown(int type) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLine object pointers.
*/
typedef OdSmartPtr<OdDbLine> OdDbLinePtr;

#include "TD_PackPop.h"

#endif

