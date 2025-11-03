/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbsurf.h"
class GcGeKnotVector;
class GcGeNurbSurface;

#pragma pack(push, 8)

class GCDB_PORT GcDbNurbSurface : public GcDbSurface
{
public:
  GcDbNurbSurface();
  GcDbNurbSurface(int uDegree, int vDegree, bool rational,
    int uNumControlPoints, int vNumControlPoints,
    const GcGePoint3dArray& ctrlPts,
    const GcGeDoubleArray& weights,
    const GcGeKnotVector& uKnots, const GcGeKnotVector& vKnots);
  ~GcDbNurbSurface();
  GCDB_DECLARE_MEMBERS(GcDbNurbSurface);

  Gcad::ErrorStatus get(int& uDegree, int& vDegree, bool& rational,
    int& uNumControlPoints, int& vNumControlPoints,
    GcGePoint3dArray& ctrlPts,
    GcGeDoubleArray& weights,
    GcGeKnotVector& uKnots, GcGeKnotVector& vKnots) const;
  Gcad::ErrorStatus set(int uDegree, int vDegree, bool rational,
    int uNumControlPoints, int vNumControlPoints,
    const GcGePoint3dArray& ctrlPts,
    const GcGeDoubleArray& weights,
    const GcGeKnotVector& uKnots, const GcGeKnotVector& vKnots);

  Gcad::ErrorStatus getControlPoints(int& uCount, int& vCount, GcGePoint3dArray& points) const;
  Gcad::ErrorStatus setControlPoints(int uCount, int vCount, const GcGePoint3dArray& points);

  Gcad::ErrorStatus getControlPointAt(int uIndex, int vIndex, GcGePoint3d& point) const;
  Gcad::ErrorStatus setControlPointAt(int uIndex, int vIndex, const GcGePoint3d& point);

  Gcad::ErrorStatus getNumberOfControlPointsInU(int& count) const;
  Gcad::ErrorStatus getNumberOfControlPointsInV(int& count) const;

  Gcad::ErrorStatus getUKnots(GcGeKnotVector& knots) const;
  Gcad::ErrorStatus getVKnots(GcGeKnotVector& knots) const;

  Gcad::ErrorStatus getNumberOfKnotsInU(int& count) const;
  Gcad::ErrorStatus getNumberOfKnotsInV(int& count) const;

  Gcad::ErrorStatus getWeight(int uIndex, int vIndex, double& weight) const;
  Gcad::ErrorStatus setWeight(int uIndex, int vIndex, double weight);

  Gcad::ErrorStatus evaluate(double u, double v, GcGePoint3d& pos) const;
  Gcad::ErrorStatus evaluate(double u, double v, GcGePoint3d& pos, GcGeVector3d& uDeriv, GcGeVector3d& vDeriv) const;
  Gcad::ErrorStatus evaluate(double u, double v, GcGePoint3d& pos, GcGeVector3d& uDeriv, GcGeVector3d& vDeriv,
    GcGeVector3d& uuDeriv, GcGeVector3d& uvDeriv, GcGeVector3d& vvDeriv) const;
  Gcad::ErrorStatus evaluate(double u, double v, int derivDegree, GcGePoint3d& point, GcGeVector3dArray& derivatives) const;

  Gcad::ErrorStatus getDegreeInU(int& degree) const;
  Gcad::ErrorStatus getDegreeInV(int& degree) const;

  Gcad::ErrorStatus isClosedInU(bool& isClosed) const;
  Gcad::ErrorStatus isClosedInV(bool& isClosed) const;

  Gcad::ErrorStatus isPeriodicInU(bool& isPeriodic) const;
  Gcad::ErrorStatus isPeriodicInV(bool& isPeriodic) const;

  Gcad::ErrorStatus getPeriodInU(double& period) const;
  Gcad::ErrorStatus getPeriodInV(double& period) const;

  Gcad::ErrorStatus isRational(bool& isRational) const;
  Gcad::ErrorStatus isPlanar(bool& isPlanar, GcGePoint3d& ptOnSurface, GcGeVector3d& normal) const;
  Gcad::ErrorStatus isPointOnSurface(const GcGePoint3d& point, bool& onSurface) const;
  Gcad::ErrorStatus getNormal(double u, double v, GcGeVector3d& normal) const;

  Gcad::ErrorStatus getNumberOfSpansInU(int& span) const;
  Gcad::ErrorStatus getNumberOfSpansInV(int& span) const;

  Gcad::ErrorStatus getIsolineAtU(double u, GcArray<GcDbCurve*>& lineSegments) const;
  Gcad::ErrorStatus getIsolineAtV(double v, GcArray<GcDbCurve*>& lineSegments) const;

  Gcad::ErrorStatus InsertKnotAtU(double u);
  Gcad::ErrorStatus InsertKnotAtV(double v);

  Gcad::ErrorStatus InsertControlPointsAtU(double u, const GcGePoint3dArray& vCtrlPts, const GcGeDoubleArray& vWeights);
  Gcad::ErrorStatus InsertControlPointsAtV(double v, const GcGePoint3dArray& uCtrlPts, const GcGeDoubleArray& uWeights);
  Gcad::ErrorStatus RemoveControlPointsAtU(int uIndex);
  Gcad::ErrorStatus RemoveControlPointsAtV(int vIndex);
  Gcad::ErrorStatus rebuild(int uDegree, int vDegree, int numUCtrlPts, int numVCtrlPts, bool bRestore = false);
  Gcad::ErrorStatus modifyPositionAndTangent(double u, double v, const GcGePoint3d& point,
    const GcGeVector3d* uDeriv = NULL, const GcGeVector3d* vDeriv = NULL);
  Gcad::ErrorStatus getParameterOfPoint(const GcGePoint3d& point, double& u, double& v) const;
  void              dragStatus(const GcDb::DragStat status) override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)