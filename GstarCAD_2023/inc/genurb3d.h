/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GENURB3D_H
#define GC_GENURB3D_H

#include "gecurv3d.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gesent3d.h"
#include "geplin3d.h"
#include "gedblar.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#pragma pack (push, 8)

class GcGeEllipArc3d;
class GcGeLineSeg3d;

class GE_DLLDATAEXIMP GcGeNurbCurve3d : public GcGeSplineEnt3d
{
public:
  GcGeNurbCurve3d();
  GcGeNurbCurve3d(const GcGeNurbCurve3d& src);
  GcGeNurbCurve3d(int                     degree,
                                  const GcGeKnotVector&   knots,
                                  const GcGePoint3dArray& cntrlPnts,
                                  Gsoft::Boolean          isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve3d(int                     degree,
                                  const GcGeKnotVector&   knots,
                                  const GcGePoint3dArray& cntrlPnts,
                                  const GcGeDoubleArray&  weights,
                                  Gsoft::Boolean          isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve3d(int                   degree,
                                  const GcGePolyline3d& fitPolyline,
                                  Gsoft::Boolean        isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve3d(const GcGePoint3dArray& fitPoints,
                                  const GcGeVector3d&     startTangent,
                                  const GcGeVector3d&     endTangent,
                                  Gsoft::Boolean          startTangentDefined = Gsoft::kTrue,
                                  Gsoft::Boolean          endTangentDefined = Gsoft::kTrue,
                                  const GcGeTol&          fitTolerance = GcGeContext::gTol);
  GcGeNurbCurve3d(const GcGePoint3dArray&    fitPoints,
                                  const GcGeVector3d&        startTangent,
                                  const GcGeVector3d&        endTangent,
                                  Gsoft::Boolean             startTangentDefined,
                                  Gsoft::Boolean             endTangentDefined,
                                  GcGe::KnotParameterization knotParam,
                                  const GcGeTol&             fitTolerance = GcGeContext::gTol);
  GcGeNurbCurve3d(const GcGePoint3dArray& fitPoints,
                                  const GcGeTol&          fitTolerance = GcGeContext::gTol);
  GcGeNurbCurve3d(const GcGePoint3dArray&  fitPoints,
                                  const GcGeVector3dArray& fitTangents,
                                  const GcGeTol&           fitTolerance = GcGeContext::gTol,
                                  Gsoft::Boolean           isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve3d(const GcGeCurve3d& curve, double epsilon = GcGeContext::gTol.equalPoint());
  GcGeNurbCurve3d(const GcGeEllipArc3d&  ellipse);
  GcGeNurbCurve3d(const GcGeLineSeg3d& linSeg);

  int             numFitPoints() const;
  Gsoft::Boolean  getFitPointAt(int index, GcGePoint3d& point) const;
  Gsoft::Boolean  getFitTolerance(GcGeTol& fitTolerance) const;
  Gsoft::Boolean  getFitTangents(GcGeVector3d& startTangent, GcGeVector3d& endTangent) const;
  Gsoft::Boolean  getFitTangents(GcGeVector3d&   startTangent,
                                                 GcGeVector3d&   endTangent,
                                                 Gsoft::Boolean& startTangentDefined,
                                                 Gsoft::Boolean& endTangentDefined) const;
  Gsoft::Boolean  getFitKnotParameterization(KnotParameterization& knotParam) const;
  Gsoft::Boolean  getFitData(GcGePoint3dArray& fitPoints,
                                             GcGeTol&          fitTolerance,
                                             Gsoft::Boolean&   tangentsExist,
                                             GcGeVector3d&     startTangent,
                                             GcGeVector3d&     endTangent) const;
  Gsoft::Boolean  getFitData(GcGePoint3dArray&     fitPoints,
                                             GcGeTol&              fitTolerance,
                                             Gsoft::Boolean&       tangentsExist,
                                             GcGeVector3d&         startTangent,
                                             GcGeVector3d&         endTangent,
                                             KnotParameterization& knotParam) const;
  void            getDefinitionData(int&              degree,
                                                    Gsoft::Boolean&   rational,
                                                    Gsoft::Boolean&   periodic,
                                                    GcGeKnotVector&   knots,
                                                    GcGePoint3dArray& controlPoints,
                                                    GcGeDoubleArray&   weights) const;
  int             numWeights() const;
  double          weightAt(int idx) const;
  Gsoft::Boolean  evalMode() const;
  Gsoft::Boolean  getParamsOfC1Discontinuity(GcGeDoubleArray& params,
                                                             const GcGeTol&   tol = GcGeContext::gTol) const;
  Gsoft::Boolean  getParamsOfG1Discontinuity(GcGeDoubleArray& params,
                                                             const GcGeTol&   tol = GcGeContext::gTol) const;

  Gsoft::Boolean   setFitPointAt(int index, const GcGePoint3d& point);
  Gsoft::Boolean   addFitPointAt(int index, const GcGePoint3d& point);
  Gsoft::Boolean   deleteFitPointAt(int index);
  Gsoft::Boolean   setFitTolerance(const GcGeTol& fitTol = GcGeContext::gTol);
  Gsoft::Boolean   setFitTangents(const GcGeVector3d& startTangent, const GcGeVector3d& endTangent);
  Gsoft::Boolean   setFitTangents(const GcGeVector3d& startTangent,
                                                  const GcGeVector3d& endTangent,
                                                  Gsoft::Boolean      startTangentDefined,
                                                  Gsoft::Boolean      endTangentDefined) const;
  Gsoft::Boolean   setFitKnotParameterization(KnotParameterization knotParam);
  GcGeNurbCurve3d& setFitData(const GcGePoint3dArray& fitPoints,
                                              const GcGeVector3d&     startTangent,
                                              const GcGeVector3d&     endTangent,
                                              const GcGeTol&          fitTol = GcGeContext::gTol);
  GcGeNurbCurve3d& setFitData(const GcGePoint3dArray& fitPoints,
                                              const GcGeVector3d&     startTangent,
                                              const GcGeVector3d&     endTangent,
                                              KnotParameterization    knotParam,
                                              const GcGeTol&          fitTol = GcGeContext::gTol);
  GcGeNurbCurve3d& setFitData(const GcGeKnotVector&   fitKnots,
                                              const GcGePoint3dArray& fitPoints,
                                              const GcGeVector3d&     startTangent,
                                              const GcGeVector3d&     endTangent,
                                              const GcGeTol&          fitTol = GcGeContext::gTol,
                                              Gsoft::Boolean          isPeriodic = Gsoft::kFalse);
  GcGeNurbCurve3d&  setFitData(int                     degree,
                                               const GcGePoint3dArray& fitPoints,
                                               const GcGeTol&          fitTol = GcGeContext::gTol);
  Gsoft::Boolean    purgeFitData();
  Gsoft::Boolean    buildFitData();
  Gsoft::Boolean    buildFitData(KnotParameterization kp);
  GcGeNurbCurve3d&  addKnot(double newKnot);
  GcGeNurbCurve3d&  insertKnot(double newKnot);
  GcGeSplineEnt3d&  setWeightAt(int idx, double val);
  GcGeNurbCurve3d&  setEvalMode(Gsoft::Boolean evalMode = Gsoft::kFalse);
  GcGeNurbCurve3d&  joinWith(const GcGeNurbCurve3d& curve);
  GcGeNurbCurve3d&  hardTrimByParams(double newStartParam, double newEndParam);
  GcGeNurbCurve3d&  makeRational(double weight = 1.0);
  GcGeNurbCurve3d&  makeClosed();
  GcGeNurbCurve3d&  makePeriodic();
  GcGeNurbCurve3d&  makeNonPeriodic();
  GcGeNurbCurve3d&  makeOpen();
  GcGeNurbCurve3d&  elevateDegree(int plusDegree);

  Gsoft::Boolean    addControlPointAt(double newKnot, const GcGePoint3d& point, double weight = 1.0);
  Gsoft::Boolean    deleteControlPointAt(int index);

  GcGeNurbCurve3d&  operator =      (const GcGeNurbCurve3d& spline);
};

#pragma pack (pop)
#endif
