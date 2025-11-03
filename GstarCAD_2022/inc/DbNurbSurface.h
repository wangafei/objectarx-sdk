/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////


#ifndef _DbNurbSurface_h_Included_
#define _DbNurbSurface_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"
#include "DbCurve.h"



class OdGeKnotVector;

typedef OdArray<OdDbCurvePtr> OdDbCurvePtrArray;

/** Description:
    This class implements a three-dimensional nurb surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbNurbSurface : public OdDbSurface
{
public:
  OdDbNurbSurface ();
  OdDbNurbSurface(int uDegree, int vDegree, bool rational,
    int uNumControlPoints, int vNumControlPoints,
    const OdGePoint3dArray& ctrlPts,
    const OdGeDoubleArray& weights,
    const OdGeKnotVector& uKnots, const OdGeKnotVector& vKnots);
  //virtual ~OdDbNurbSurface();
  ODDB_DECLARE_MEMBERS(OdDbNurbSurface);

  // NURBS surface methods
  OdResult get (int& iUDegree, int& iVDegree, bool& bRational, int& iUNumControlPoints, int& iVNumControlPoints,
                OdGePoint3dArray& ctrlPtsArr, OdGeDoubleArray& weights, OdGeKnotVector& uKnots, OdGeKnotVector& vKnots) const;
  OdResult set (int iUDegree, int iVDegree, bool bRational, int iUNumControlPoints, int iVNumControlPoints,
                const OdGePoint3dArray& ctrlPtsArr, const OdGeDoubleArray& weights, const OdGeKnotVector& uKnots, const OdGeKnotVector& vKnots); 

  //OdDbObject methods
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(CLSID* pClsid) const;

  // get/set control points.
  OdResult getControlPoints(int& iUCount, int& iVCount, OdGePoint3dArray& points) const;
  OdResult setControlPoints(int iUCount, int iVCount, const OdGePoint3dArray& points);

  // get/set control point.
  OdResult getControlPointAt(int iUIndex, int iVIndex, OdGePoint3d& point) const;
  OdResult setControlPointAt(int iUIndex, int iVIndex, const OdGePoint3d& point);

  // get number of control points.
  OdResult getNumberOfControlPointsInU(int& iCount) const;
  OdResult getNumberOfControlPointsInV(int& iCount) const;

  // get knots
  OdResult getUKnots(OdGeKnotVector& knots) const;
  OdResult getVKnots(OdGeKnotVector& knots) const;

  // get number of knots.
  OdResult getNumberOfKnotsInU(int& iCount) const;
  OdResult getNumberOfKnotsInV(int& iCount) const;

  // get/set number of weight
  OdResult getWeight(int iUIndex, int iVIndex, double& weight ) const;
  OdResult setWeight(int iUIndex, int iVIndex, double weight );

  // Evaluate position, first and second derivatives
  OdResult evaluate(double dU, double dV, OdGePoint3d& pos) const;
  OdResult evaluate(double dU, double dV, OdGePoint3d& pos, OdGeVector3d& uDeriv, OdGeVector3d& vDeriv) const;
  OdResult evaluate(double dU, double dV, OdGePoint3d& pos, OdGeVector3d& uDeriv, OdGeVector3d& vDeriv,
                    OdGeVector3d& uuDeriv, OdGeVector3d& uvDeriv, OdGeVector3d& vvDeriv) const;
  OdResult evaluate(double dU, double dV, int iDerivDegree, OdGePoint3d& point, OdGeVector3dArray& derivatives) const;

  OdResult getDegreeInU(int& iDegree) const;
  OdResult getDegreeInV(int& iDegree) const;
  
  OdResult isClosedInU(bool& bIsClosed) const;
  OdResult isClosedInV(bool& bIsClosed) const;
  
  OdResult isPeriodicInU(bool& bIsPeriodic) const;
  OdResult isPeriodicInV(bool& bIsPeriodic) const;

  // get period
  OdResult getPeriodInU(double& dPeriod) const;
  OdResult getPeriodInV(double& dPeriod) const;

  OdResult isRational(bool& bIsRational) const;

  OdResult isPlanar(bool& bIsPlanar, OdGePoint3d& ptOnSurface, OdGeVector3d& normal) const;

  OdResult isPointOnSurface(const OdGePoint3d& point, bool& bOnSurface) const;

  // get normal
  OdResult getNormal(double dU, double dV, OdGeVector3d& normal) const;

  // get the simple patches in u v direction
  OdResult getNumberOfSpansInU(int& span) const;
  OdResult getNumberOfSpansInV(int& span) const;

  // get u and v isolines.
  OdResult getIsolineAtU(double dU, OdDbCurvePtrArray& lineSegments) const;
  OdResult getIsolineAtV(double dV, OdDbCurvePtrArray& lineSegments) const;

  // insert u and v knot 
  OdResult InsertKnotAtU(double dU);
  OdResult InsertKnotAtV(double dV);

  // add / remove control points
  OdResult InsertControlPointsAtU(double dU, const OdGePoint3dArray& vCtrlPts, const OdGeDoubleArray& vWeights);
  OdResult InsertControlPointsAtV(double dV, const OdGePoint3dArray& uCtrlPts, const OdGeDoubleArray& uWeights);
  OdResult RemoveControlPointsAtU(int iUDegree);
  OdResult RemoveControlPointsAtV(int iVDegree);

  // rebuild
  OdResult rebuild(int iUDegree, int iVDegree, int iNumUCtrlPts, int iNumVCtrlPts, bool bRestore = false);

  OdResult modifyPositionAndTangent(double dU, double dV, const OdGePoint3d& point, const OdGeVector3d* uDeriv = NULL, const OdGeVector3d* vDeriv = NULL);

  // get the u and v for a point
  OdResult getParameterOfPoint(const OdGePoint3d& point, double& dU, double& dV) const;

  OdResult convertFrom(OdDbSurface* pSource, OdDb::DwgVersion version, bool transferId = true);
  // Overridden methods from OdDbEntity
  void dragStatus(const OdDb::DragStat status);
};
  
typedef OdSmartPtr<OdDbNurbSurface> OdDbNurbSurfacePtr;

#include "TD_PackPop.h"
#endif //_DbNurbSurface_h_Included_
