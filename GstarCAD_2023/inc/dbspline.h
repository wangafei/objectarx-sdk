/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBSPLINE_H
#define GCDB_DBSPLINE_H

#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"
#include "gekvec.h"

#pragma pack (push, 8)

static const unsigned int kPlineVerticesThrehold = 10000;

class GcDb2dPolyline;

enum SplineType { kFitPoints = 0, kControlPoints = 1 };

class GCDB_PORT GcDbSpline : public GcDbCurve
{
public:
  GCDB_DECLARE_MEMBERS(GcDbSpline);
  GcDbSpline();
  ~GcDbSpline();
  GcDbSpline(const GcGePoint3dArray& fitPoints,
    int                     order = 4,
    double                  fitTolerance = 0.0);
  GcDbSpline(const GcGePoint3dArray& fitPoints,
    const GcGeVector3d&     startTangent,
    const GcGeVector3d&     endTangent,
    int                     order = 4,
    double                  fitTolerance = 0.0);
  GcDbSpline(const GcGePoint3dArray& fitPoints,
    bool                    periodic,
    GcGe::KnotParameterization  knotParam = GcGe::kUniform,
    int                     degree = 3,
    double                  fitTolerance = 0.0);
  GcDbSpline(const GcGePoint3dArray& fitPoints,
    GcGe::KnotParameterization    knotParam,
    int                     degree = 3,
    double                  fitTolerance = 0.0);
  GcDbSpline(const GcGePoint3dArray& fitPoints,
    const GcGeVector3d&     startTangent,
    const GcGeVector3d&     endTangent,
    GcGe::KnotParameterization    knotParam,
    int                     degree = 3,
    double                  fitTolerance = 0.0);
  GcDbSpline(int                     degree,
    Gsoft::Boolean          rational,
    Gsoft::Boolean          closed,
    Gsoft::Boolean          periodic,
    const GcGePoint3dArray& controlPoints,
    const GcGeDoubleArray&  knots,
    const GcGeDoubleArray&  weights,
    double                  controlPtTol = 0.0,
    double                  knotTol = GcGeKnotVector::globalKnotTolerance);
  GcDbSpline(const GcGePoint3d&      center,
    const GcGeVector3d&     unitNormal,
    const GcGeVector3d&     majorAxis,
    double                  radiusRatio,
    double                  startAngle = 0.0,
    double                  endAngle = 6.28318530717958647692);

  Gsoft::Boolean    isNull() const;
  Gsoft::Boolean    isRational() const;
  int               degree() const;
  Gcad::ErrorStatus elevateDegree(int newDegree);
  int               numControlPoints() const;
  Gcad::ErrorStatus getControlPointAt(int index, GcGePoint3d& point) const;
  Gcad::ErrorStatus setControlPointAt(int index, const GcGePoint3d& point);
  int               numFitPoints() const;
  Gcad::ErrorStatus getFitPointAt(int index, GcGePoint3d& point) const;
  Gcad::ErrorStatus setFitPointAt(int index, const GcGePoint3d& point);

  Gcad::ErrorStatus insertFitPointAt(int index, const GcGePoint3d& point);
  Gcad::ErrorStatus removeFitPointAt(int index);
  double            fitTolerance() const;
  Gcad::ErrorStatus setFitTol(double tol);
  Gcad::ErrorStatus getFitTangents(GcGeVector3d& startTangent,
    GcGeVector3d& endTangent) const;
  Gcad::ErrorStatus setFitTangents(const GcGeVector3d& startTangent,
    const GcGeVector3d& endTangent);
  Gsoft::Boolean    hasFitData() const;
  Gcad::ErrorStatus getFitData(GcGePoint3dArray&  fitPoints,
    int&               degree,
    double&            fitTolerance,
    Gsoft::Boolean&    tangentsExist,
    GcGeVector3d&      startTangent,
    GcGeVector3d&      endTangent) const;
  Gcad::ErrorStatus setFitData(const GcGePoint3dArray&  fitPoints,
    int                   degree,
    double                fitTolerance,
    const GcGeVector3d&   startTangent,
    const GcGeVector3d&   endTangent);
  Gcad::ErrorStatus getFitData(GcGePoint3dArray&  fitPoints,
    Gsoft::Boolean&    tangentsExist,
    GcGeVector3d&      startTangent,
    GcGeVector3d&      endTangent,
    GcGe::KnotParameterization&  knotParam,
    int&               degree,
    double&            fitTolerance) const;
  Gcad::ErrorStatus setFitData(const GcGePoint3dArray&  fitPoints,
    const GcGeVector3d&   startTangent,
    const GcGeVector3d&   endTangent,
    GcGe::KnotParameterization  knotParam,
    int                   degree = 3,
    double                fitTolerance = 0.0);
  Gcad::ErrorStatus setFitData(const GcGePoint3dArray&  fitPoints,
    bool                     isPeriodic,
    GcGe::KnotParameterization  knotParam,
    int                   degree = 3,
    double                fitTolerance = 0.0);
  Gcad::ErrorStatus purgeFitData();
  Gcad::ErrorStatus updateFitData();
  Gcad::ErrorStatus getNurbsData(int&              degree,
    Gsoft::Boolean&   rational,
    Gsoft::Boolean&   closed,
    Gsoft::Boolean&   periodic,
    GcGePoint3dArray& controlPoints,
    GcGeDoubleArray&  knots,
    GcGeDoubleArray&  weights,
    double&           controlPtTol,
    double&           knotTol) const;
  Gcad::ErrorStatus setNurbsData(int                  degree,
    Gsoft::Boolean       rational,
    Gsoft::Boolean       closed,
    Gsoft::Boolean       periodic,
    const GcGePoint3dArray& controlPoints,
    const GcGeDoubleArray& knots,
    const GcGeDoubleArray& weights,
    double               controlPtTol = 0.0,
    double               knotTol = 0.0);
  double            weightAt(int index) const;
  Gcad::ErrorStatus setWeightAt(int index, double weight);
  Gcad::ErrorStatus insertKnot(double param);

  DBCURVE_METHODS

    Gcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
      const GcGeVector3d& normal, double offsetDist,
      GcDbVoidPtrArray& offsetCurves) const override;
  Gcad::ErrorStatus toPolyline(GcDbCurve*& pCurve, int precision = 10,
    int* maxSuggestedPrecision = NULL,
    unsigned int numOfVerticesThreshold = kPlineVerticesThrehold) const;
  Gcad::ErrorStatus toPolyline(GcDbCurve*& pCurve, bool bConvertAsArcs, bool bToLWPolyline,
    int precision = 10, int* maxSuggestedPrecision = NULL,
    unsigned int numOfVerticesThreshold = kPlineVerticesThrehold) const;
  Gcad::ErrorStatus insertControlPointAt(double knotParam, const GcGePoint3d& ctrlPt, double weight = 1.0);
  Gcad::ErrorStatus removeControlPointAt(int index);
  SplineType        type() const;
  Gcad::ErrorStatus setType(SplineType type);
  Gcad::ErrorStatus rebuild(int degree, int numCtrlPts);
  Gcad::ErrorStatus modifyPositionAndTangent(double param, const GcGePoint3d& point, const GcGeVector3d* deriv);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)

#endif