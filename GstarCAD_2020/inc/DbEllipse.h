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




#ifndef _OD_DB_ELIPSE_H
#define _OD_DB_ELIPSE_H /* {Secret} */

#include "TD_PackPush.h"

#include "DbCurve.h"

/** Description:
    This class represents Ellipse entities in an OdDbDatabase instance.

    Library:
    TD_Db
    Remarks:
    All angles are expressed in radians.
    
    A closed Ellipse entity will have a startAngle of 0 and an endAngle of Oda2PI.

    (endAngle - startAngle) > 1e-6.

    The radiusRatio must be in the range [1e-6..1].

    The majorAxis must perpendicular to the *normal* within 1e-6.
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbEllipse : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbEllipse);

  OdDbEllipse();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDbEllipse(const OdGePoint3d&  center,
			  const OdGeVector3d& unitNormal,
			  const OdGeVector3d& majorAxis,
			  double              radiusRatio,
			  double              startAngle = 0.0,
			  double              endAngle   = 6.28318530717958647692);
  /** 
  Gcad(Add):增加兼容接口	
  */
  virtual ~OdDbEllipse();

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
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;

  /** Description:
     Returns the WCS major axis vector for this Ellipse entity.
  */
  OdGeVector3d majorAxis() const;

  /** Description:
    Returns the WCS minor axis vector for this Ellipse entity.
  */
  OdGeVector3d minorAxis() const;

  /** Description:
    Returns the ratio of the minor radius to the major radius of this Ellipse entity.
  */
  double radiusRatio() const;

  /** Description:
    Sets the ratio of the minor radius to the major radius of this Ellipse entity.
    Arguments:
    radiusRatio (I) Radius ratio.
    Note:
    All angles are expressed in radians.

    The radiusRatio must be in the range [1e-6..1].

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setRadiusRatio(
    double radiusRatio);

  /** Description:
    Returns the start *angle* of this curve (DXF 50).

    Remarks:
    The *angle* is measured counterclockwise from the major axis.

    Note:
    All angles are expressed in radians.
  */
  double startAngle() const;

  /** Description:
    Sets the start *angle* of this curve (DXF 50).
    
    Arguments:
    startAngle (I) Start *angle*.
    
    Remarks:
    The *angle* is measured counterclockwise from the major axis.

    Note:
    All angles are expressed in radians.

    A closed Ellipse entity will have a startAngle of 0 and an endAngle of Oda2PI.

    (endAngle - startAngle) > 1e-6.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setStartAngle(
    double startAngle);

  /** Description:
    Returns the end *angle* of this curve (DXF 51).

    Remarks:
    The *angle* is measured counterclockwise from the major axis.

    Note:
    All angles are expressed in radians.
  */
  double endAngle() const;

  /** Description:
    Sets the end *angle* of this curve (DXF 51).
    Arguments:
    endAngle (I) End *angle*.

    Remarks:
    The *angle* is measured counterclockwise from the major axis.

    Note:
    All angles are expressed in radians.

    A closed Ellipse entity will have a startAngle of 0 and an endAngle of Oda2PI.

    (endAngle - startAngle) > 1e-6.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setEndAngle(
    double endAngle);

  /** Description:
    Sets the start parameter for this curve (DXF 41).
    Arguments:
    startParam (I) Start parameter.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setStartParam(
    double startParam);

  /** Description:
    Sets the end parameter for this curve (DXF 42).
    Arguments:
    endParam (I) End parameter.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setEndParam(
    double endParam);

  /** Description:
    Returns the parameter value corresponding to the specified *angle*.
    Arguments:
    angle (I) Angle to be queried.
    Remarks:
    Can be used to retrieve the DXF 41 & 42 values.
    Note:
    All angles are expressed in radians.
  */
  double paramAtAngle(
    double angle) const;

  /** Description:
    Returns the *angle* corresponding to the specified parameter value.
    Arguments:
    param (I) Parameter value to be queried.
    Note:
    All angles are expressed in radians.
 */
  double angleAtParam(
    double param) const;

  /** Description:
    Returns the properties for this Ellipse entity.

    Arguments:
    center (O) Receives the WCS *center*.
    unitNormal (O) Receives the WCS unit *normal*.
    majorAxis (O) Receives the WCS major axis.
    radiusRatio (O) Receives the radius ratio.
    startAngle (O) Receives the start *angle*.
    endAngle (O) Receives the end *angle*.
    Note:
    All angles are expressed in radians.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult get(OdGePoint3d& center,
    OdGeVector3d& unitNormal,
    OdGeVector3d& majorAxis,
    double& radiusRatio,
    double& startAngle,
    double& endAngle) const;

  /** Description:
    Sets the properties for this Ellipse entity.

    Arguments:
    center (I) WCS *center*.
    unitNormal (I) WCS unit *normal*.
    majorAxis (I) WCS major axis.
    radiusRatio (I) Radius ratio.
    startAngle (I) Start *angle*.
    endAngle (I) End *angle*.    

    Note:
    All angles are expressed in radians.
    
    A closed Ellipse entity will have a startAngle of 0 and an endAngle of Oda2PI.

    (endAngle - startAngle) > 1e-6.

    The radiusRatio must be in the range [1e-6..1].

    The majorAxis must perpendicular to the *normal* within 1e-6.

	Gcad(Modify):returns:void->OdResult
    
  */
  OdResult set(const OdGePoint3d& center,
    const OdGeVector3d& unitNormal,
    const OdGeVector3d& majorAxis,
    double radiusRatio,
    double startAngle = 0.0,
    double endAngle = Oda2PI);

  /**
  Gcad(Add):增加兼容接口
  */
  OdBool isNull() const;

  /**
  Gcad(Add):增加兼容接口
  */
 // virtual  OdResult moveGripPointsAt(
//					const OdDbIntArray& indices, const OdGeVector3d& offset);

  /*/Gcad(Add):增加兼容接口
  
  virtual OdResult intersectWith(const OdDbEntity* pEnt,
						  OdDb::Intersect intType, OdGePoint3dArray& points,
						  GsMarker thisGsMarker = 0, GsMarker otherGsMarker = 0) const;

  virtual OdResult intersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
						  const OdGePlane& projPlane, OdGePoint3dArray& points,
						  GsMarker thisGsMarker = 0, GsMarker otherGsMarker = 0) const;
  /*/
  //*/
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

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

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

  virtual OdResult getEndParam(
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

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);
  /**
  Gcad(Add):增加兼容接口
  //arx2008 增加接口 
  virtual bool castShadows() const;
  virtual void setCastShadows(bool newVal);
  virtual bool receiveShadows() const;
  virtual void setReceiveShadows(bool newVal);
  */

};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEllipse object pointers.
*/
typedef OdSmartPtr<OdDbEllipse> OdDbEllipsePtr;

#include "TD_PackPop.h"

#endif //_OD_DB_ELIPSE_H

