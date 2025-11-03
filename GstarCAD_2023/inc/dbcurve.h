/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBCURVE_H
#define GD_DBCURVE_H

#include "dbmain.h"
#include "gept3dar.h"
#include "gedblar.h"
#include "geplane.h"
#include "dbptrar.h"

class GcDbSpline;

#pragma pack(push, 8)

class GSOFT_NO_VTABLE GCDB_PORT GcDbCurve : public GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDbCurve);

  ~GcDbCurve();

  virtual Gsoft::Boolean    isClosed() const;
  virtual Gsoft::Boolean    isPeriodic() const;

  virtual Gcad::ErrorStatus getStartParam(double&) const;
  virtual Gcad::ErrorStatus getEndParam(double&) const;
  virtual Gcad::ErrorStatus getStartPoint(GcGePoint3d&) const;
  virtual Gcad::ErrorStatus getEndPoint(GcGePoint3d&) const;

  virtual Gcad::ErrorStatus getPointAtParam(double, GcGePoint3d&) const;
  virtual Gcad::ErrorStatus getParamAtPoint(const GcGePoint3d&, double&)const;
  virtual Gcad::ErrorStatus getDistAtParam(double param, double& dist) const;
  virtual Gcad::ErrorStatus getParamAtDist(double dist, double& param) const;
  virtual Gcad::ErrorStatus getDistAtPoint(const GcGePoint3d&, double&)const;
  virtual Gcad::ErrorStatus getPointAtDist(double, GcGePoint3d&) const;

  virtual Gcad::ErrorStatus getFirstDeriv(double param, GcGeVector3d& firstDeriv) const;
  virtual Gcad::ErrorStatus getFirstDeriv(const GcGePoint3d&, GcGeVector3d& firstDeriv) const;
  virtual Gcad::ErrorStatus getSecondDeriv(double param, GcGeVector3d& secDeriv) const;
  virtual Gcad::ErrorStatus getSecondDeriv(const GcGePoint3d&, GcGeVector3d& secDeriv) const;

  virtual Gcad::ErrorStatus getClosestPointTo(const GcGePoint3d& givenPnt,
    GcGePoint3d& pointOnCurve,
    Gsoft::Boolean extend = Gsoft::kFalse) const;
  virtual Gcad::ErrorStatus getClosestPointTo(const GcGePoint3d& givenPnt,
    const GcGeVector3d& direction,
    GcGePoint3d& pointOnCurve,
    Gsoft::Boolean extend = Gsoft::kFalse) const;

  virtual Gcad::ErrorStatus getOrthoProjectedCurve(const GcGePlane&, GcDbCurve*& projCrv) const;
  virtual Gcad::ErrorStatus getProjectedCurve(const GcGePlane&,
    const GcGeVector3d& projDir,
    GcDbCurve*& projCrv) const;

  virtual Gcad::ErrorStatus getOffsetCurves(double offsetDist, GcDbVoidPtrArray& offsetCurves) const;
  virtual Gcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
    const GcGeVector3d& normal, double offsetDist,
    GcDbVoidPtrArray& offsetCurves) const;
  virtual Gcad::ErrorStatus getSpline(GcDbSpline*& spline) const;
  virtual Gcad::ErrorStatus getSplitCurves(const GcGeDoubleArray& params, GcDbVoidPtrArray& curveSegments) const;
  virtual Gcad::ErrorStatus getSplitCurves(const GcGePoint3dArray& points, GcDbVoidPtrArray& curveSegments) const;

  virtual Gcad::ErrorStatus extend(double newParam);
  virtual Gcad::ErrorStatus extend(Gsoft::Boolean extendStart, const GcGePoint3d& toPoint);

  virtual Gcad::ErrorStatus getArea(double&) const;
  virtual Gcad::ErrorStatus reverseCurve();

  virtual Gcad::ErrorStatus  getGcGeCurve(GcGeCurve3d*& pGeCurve, const GcGeTol& tol = GcGeContext::gTol) const;
  static  Gcad::ErrorStatus  createFromGcGeCurve(const GcGeCurve3d& geCurve, GcDbCurve*& pDbCurve,
    GcGeVector3d *normal = NULL,
    const GcGeTol& tol = GcGeContext::gTol);
  virtual Gcad::ErrorStatus  setFromGcGeCurve(const GcGeCurve3d& geCurve,
    GcGeVector3d *normal = NULL,
    const GcGeTol& tol = GcGeContext::gTol);

protected:
  GcDbCurve();
};


#define DBCURVE_METHODS \
Gsoft::Boolean isClosed() const override; \
Gsoft::Boolean isPeriodic() const override; \
Gsoft::Boolean isPlanar() const override; \
Gcad::ErrorStatus getPlane(GcGePlane&, GcDb::Planarity&) const override; \
Gcad::ErrorStatus getStartParam(double&) const override; \
Gcad::ErrorStatus getEndParam(double&) const override; \
Gcad::ErrorStatus getStartPoint(GcGePoint3d&) const override; \
Gcad::ErrorStatus getEndPoint(GcGePoint3d&) const override; \
Gcad::ErrorStatus getPointAtParam(double, GcGePoint3d&) const override; \
Gcad::ErrorStatus getParamAtPoint(const GcGePoint3d&, double&) const override; \
Gcad::ErrorStatus getDistAtParam(double, double&) const override; \
Gcad::ErrorStatus getParamAtDist(double, double&) const override; \
Gcad::ErrorStatus getDistAtPoint(const GcGePoint3d&, double&) const override; \
Gcad::ErrorStatus getPointAtDist(double, GcGePoint3d&) const override; \
Gcad::ErrorStatus getFirstDeriv(double, GcGeVector3d&) const override; \
Gcad::ErrorStatus getFirstDeriv(const GcGePoint3d&,GcGeVector3d&)const override; \
Gcad::ErrorStatus getSecondDeriv(double, GcGeVector3d&) const override; \
Gcad::ErrorStatus getSecondDeriv(const GcGePoint3d&, GcGeVector3d&) const override; \
Gcad::ErrorStatus getClosestPointTo(const GcGePoint3d&, GcGePoint3d&, Gsoft::Boolean = Gsoft::kFalse) const override; \
Gcad::ErrorStatus getClosestPointTo(const GcGePoint3d&, const GcGeVector3d&, GcGePoint3d&, \
                                    Gsoft::Boolean = Gsoft::kFalse) const override; \
Gcad::ErrorStatus getOrthoProjectedCurve(const GcGePlane&, GcDbCurve*&) const override; \
Gcad::ErrorStatus getProjectedCurve(const GcGePlane&, const GcGeVector3d&, GcDbCurve*&) const override; \
Gcad::ErrorStatus getOffsetCurves(double, GcDbVoidPtrArray&) const override; \
Gcad::ErrorStatus getSpline(GcDbSpline*&) const override; \
Gcad::ErrorStatus getSplitCurves(const GcGeDoubleArray&, GcDbVoidPtrArray& curveSegments) const override; \
Gcad::ErrorStatus getSplitCurves(const GcGePoint3dArray&, GcDbVoidPtrArray&) const override; \
Gcad::ErrorStatus extend(double) override; \
Gcad::ErrorStatus extend(Gsoft::Boolean, const GcGePoint3d&) override; \
Gcad::ErrorStatus getArea(double&) const override; \
Gcad::ErrorStatus reverseCurve() override; \
Gcad::ErrorStatus getGcGeCurve (GcGeCurve3d*& pGeCurve, \
                                                const GcGeTol& tol = GcGeContext::gTol) const override; \
Gcad::ErrorStatus setFromGcGeCurve (const GcGeCurve3d& geCurve, \
                                                    GcGeVector3d *normal = NULL, \
                                                    const GcGeTol& tol = GcGeContext::gTol) override;

#pragma pack(pop)

#endif