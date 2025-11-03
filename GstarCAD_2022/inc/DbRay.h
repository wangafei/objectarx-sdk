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




#ifndef OD_DBRAY_H
#define OD_DBRAY_H

#include "TD_PackPush.h"

#include "DbCurve.h"

class OdGePoint3d;
class OdGeVector3d;

/** Description:
    This class represents Ray entities in an OdDbDatabase instance.

    Library:
    TD_Db

    Remarks:
    A Ray is a semi-infinite line.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRay : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRay);

  OdDbRay();
  
  ~OdDbRay();
  
  OdResult getOffsetCurvesGivenPlaneNormal(
  const OdGeVector3d& normal, double offsetDist,
  OdDbVoidPtrArray& offsetCurves) const; //Replace OdRxObjectPtrArray
  
  /** Description:
    Returns the WCS base point of this curve (DXF 10).
  */
  OdGePoint3d basePoint() const;

  /** Description:
    Sets the WCS base point of this curve (DXF 10).
    Arguments:
    basePoint (I) Base point.
  */
  void setBasePoint(
    const OdGePoint3d& basePoint); 
  
  /** Description:
    Returns the WCS unit direction vector of this curve (DXF 11).
  */
  OdGeVector3d unitDir() const;

  /** Description:
    Sets the WCS unit direction vector of this curve (DXF 11).
    Arguments:
    unitDir (I) Unit direction vector.
  */
  void setUnitDir(
    const OdGeVector3d& unitDir);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  /**
    Note:
    Always returns eInvalidExtents.
  */
  OdResult subGetGeomExtents(
    OdDbExtents& extents) const;

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

  virtual OdResult getDistAtParam( double param, double& dist ) const;

  virtual OdResult getParamAtDist( double dist, double& param ) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);
  OdResult getSpline(OdDbSpline*&) const;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRay object pointers.
*/
typedef OdSmartPtr<OdDbRay> OdDbRayPtr;

#include "TD_PackPop.h"

#endif

