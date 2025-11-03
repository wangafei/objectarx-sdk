/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GENURB2d_H
#define GC_GENURB2d_H

#include "gecurv2d.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gept2dar.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "gesent2d.h"
#include "geplin2d.h"
#include "gedblar.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#pragma pack (push, 8)

class GcGeEllipArc2d;
class GcGeLineSeg2d;

class GE_DLLDATAEXIMP GcGeNurbCurve2d : public GcGeSplineEnt2d
{
public:
  GcGeNurbCurve2d();
  GcGeNurbCurve2d(const GcGeNurbCurve2d& src);
  GcGeNurbCurve2d(int                     degree,
                                  const GcGeKnotVector&   knots,
                                  const GcGePoint2dArray& cntrlPnts,
                                  Gsoft::Boolean          isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve2d(int                     degree,
                                  const GcGeKnotVector&   knots,
                                  const GcGePoint2dArray& cntrlPnts,
                                  const GcGeDoubleArray&  weights,
                                  Gsoft::Boolean          isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve2d(int                   degree,
                                  const GcGePolyline2d& fitPolyline,
                                  Gsoft::Boolean        isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve2d(const GcGePoint2dArray& fitPoints,
                                  const GcGeVector2d&     startTangent,
                                  const GcGeVector2d&     endTangent,
                                  Gsoft::Boolean          startTangentDefined = Gsoft::kTrue,
                                  Gsoft::Boolean          endTangentDefined = Gsoft::kTrue,
                                  const GcGeTol&          fitTolerance = GcGeContext::gTol);
  GcGeNurbCurve2d(const GcGePoint2dArray&    fitPoints,
                                  const GcGeVector2d&        startTangent,
                                  const GcGeVector2d&        endTangent,
                                  Gsoft::Boolean             startTangentDefined,
                                  Gsoft::Boolean             endTangentDefined,
                                  GcGe::KnotParameterization knotParam,
                                  const GcGeTol&             fitTolerance = GcGeContext::gTol);
  GcGeNurbCurve2d(const GcGePoint2dArray& fitPoints,
                                  const GcGeTol&          fitTolerance = GcGeContext::gTol);
  GcGeNurbCurve2d(const GcGePoint2dArray& fitPoints,
                                  const GcGeVector2dArray& fitTangents,
                                  const GcGeTol&           fitTolerance = GcGeContext::gTol,
                                  Gsoft::Boolean           isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve2d(const GcGeEllipArc2d&  ellipse);
  GcGeNurbCurve2d(const GcGeLineSeg2d& linSeg);
  GcGeNurbCurve2d(const GcGeCurve2d& curve,
                                  double             epsilon = GcGeContext::gTol.equalPoint());

  int             numFitPoints() const;
  Gsoft::Boolean  getFitPointAt(int index, GcGePoint2d& point) const;
  Gsoft::Boolean  getFitTolerance(GcGeTol& fitTolerance) const;
  Gsoft::Boolean  getFitTangents(GcGeVector2d& startTangent, GcGeVector2d& endTangent) const;
  Gsoft::Boolean  getFitKnotParameterization(KnotParameterization& knotParam) const;
  Gsoft::Boolean  getFitData(GcGePoint2dArray& fitPoints,
                                             GcGeTol&          fitTolerance,
                                             Gsoft::Boolean&   tangentsExist,
                                             GcGeVector2d&     startTangent,
                                             GcGeVector2d&     endTangent) const;
  Gsoft::Boolean  getFitData(GcGePoint2dArray&     fitPoints,
                                             GcGeTol&              fitTolerance,
                                             Gsoft::Boolean&       tangentsExist,
                                             GcGeVector2d&         startTangent,
                                             GcGeVector2d&         endTangent,
                                             KnotParameterization& knotParam) const;
  void            getDefinitionData(int&              degree,
                                                    Gsoft::Boolean&   rational,
                                                    Gsoft::Boolean&   periodic,
                                                    GcGeKnotVector&   knots,
                                                    GcGePoint2dArray& controlPoints,
                                                    GcGeDoubleArray&  weights) const;
  int             numWeights() const;
  double          weightAt(int idx) const;
  Gsoft::Boolean  evalMode() const;
  Gsoft::Boolean  getParamsOfC1Discontinuity(GcGeDoubleArray& params,
                                                             const GcGeTol&   tol = GcGeContext::gTol) const;
  Gsoft::Boolean  getParamsOfG1Discontinuity(GcGeDoubleArray& params,
                                                             const GcGeTol&   tol = GcGeContext::gTol) const;

  Gsoft::Boolean   setFitPointAt(int index, const GcGePoint2d& point);
  Gsoft::Boolean   addFitPointAt(int index, const GcGePoint2d& point);
  Gsoft::Boolean   deleteFitPointAt(int index);
  Gsoft::Boolean   setFitTolerance(const GcGeTol& fitTol = GcGeContext::gTol);
  Gsoft::Boolean   setFitTangents(const GcGeVector2d& startTangent,
                                                  const GcGeVector2d& endTangent);
  Gsoft::Boolean   setFitKnotParameterization(KnotParameterization knotParam);
  GcGeNurbCurve2d& setFitData(const GcGePoint2dArray& fitPoints,
                                              const GcGeVector2d&     startTangent,
                                              const GcGeVector2d&     endTangent,
                                              const GcGeTol&          fitTol = GcGeContext::gTol);
  GcGeNurbCurve2d& setFitData(const GcGePoint2dArray& fitPoints,
                                              const GcGeVector2d&     startTangent,
                                              const GcGeVector2d&     endTangent,
                                              KnotParameterization    knotParam,
                                              const GcGeTol&          fitTol = GcGeContext::gTol);
  GcGeNurbCurve2d& setFitData(const GcGeKnotVector&   fitKnots,
                                              const GcGePoint2dArray& fitPoints,
                                              const GcGeVector2d&     startTangent,
                                              const GcGeVector2d&     endTangent,
                                              const GcGeTol&          fitTol = GcGeContext::gTol,
                                              Gsoft::Boolean          isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve2d&  setFitData(int                     degree,
                                               const GcGePoint2dArray& fitPoints,
                                               const GcGeTol&          fitTol = GcGeContext::gTol);
  Gsoft::Boolean    purgeFitData();
  Gsoft::Boolean    buildFitData();
  Gsoft::Boolean    buildFitData(KnotParameterization kp);
  GcGeNurbCurve2d&  addKnot(double newKnot);
  GcGeNurbCurve2d&  insertKnot(double newKnot);
  GcGeSplineEnt2d&  setWeightAt(int idx, double val);
  GcGeNurbCurve2d&  setEvalMode(Gsoft::Boolean evalMode = Gsoft::kFalse);
  GcGeNurbCurve2d&  joinWith(const GcGeNurbCurve2d& curve);
  GcGeNurbCurve2d&  hardTrimByParams(double newStartParam, double newEndParam);
  GcGeNurbCurve2d&  makeRational(double weight = 1.0);
  GcGeNurbCurve2d&  makeClosed();
  GcGeNurbCurve2d&  makePeriodic();
  GcGeNurbCurve2d&  makeNonPeriodic();
  GcGeNurbCurve2d&  makeOpen();
  GcGeNurbCurve2d&  elevateDegree(int plusDegree);

  Gsoft::Boolean    addControlPointAt(double newKnot, const GcGePoint2d& point, double weight = 1.0);
  Gsoft::Boolean    deleteControlPointAt(int index);

  GcGeNurbCurve2d&  operator =      (const GcGeNurbCurve2d& spline);
};

#pragma pack (pop)
#endif
