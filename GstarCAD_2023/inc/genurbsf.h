/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GENURBSF_H
#define GC_GENURBSF_H

#include "gegbl.h"
#include "gesurf.h"
#include "gept3dar.h"
#include "gedblar.h"
#pragma pack (push, 8)

class GcGeKnotVector;

class GE_DLLDATAEXIMP GcGeNurbSurface : public GcGeSurface
{
public:
  GcGeNurbSurface();
  GcGeNurbSurface(int degreeU,
                  int degreeV,
                  int propsInU,
                  int propsInV,
                  int numControlPointsInU,
                  int numControlPointsInV,
                  const GcGePoint3d controlPoints[],
                  const double weights[],
                  const GcGeKnotVector& uKnots,
                  const GcGeKnotVector& vKnots,
                  const GcGeTol& tol = GcGeContext::gTol);
  GcGeNurbSurface(const GcGeNurbSurface& nurb);

  GcGeNurbSurface& operator = (const GcGeNurbSurface& nurb);

  Gsoft::Boolean   isRationalInU() const;
  Gsoft::Boolean   isPeriodicInU(double&) const;
  Gsoft::Boolean   isRationalInV() const;
  Gsoft::Boolean   isPeriodicInV(double&) const;

  int singularityInU() const;
  int singularityInV() const;

  int            degreeInU() const;
  int            numControlPointsInU() const;
  int            degreeInV() const;
  int            numControlPointsInV() const;
  void           getControlPoints(GcGePoint3dArray& points) const;
  Gsoft::Boolean getWeights(GcGeDoubleArray& weights) const;

  int       numKnotsInU() const;
  void      getUKnots(GcGeKnotVector& uKnots) const;
  int       numKnotsInV() const;
  void      getVKnots(GcGeKnotVector& vKnots) const;

  void      getDefinition(int& degreeU,
                          int& degreeV,
                          int& propsInU,
                          int& propsInV,
                          int& numControlPointsInU,
                          int& numControlPointsInV,
                          GcGePoint3dArray& controlPoints,
                          GcGeDoubleArray& weights,
                          GcGeKnotVector& uKnots,
                          GcGeKnotVector& vKnots) const;

  GcGeNurbSurface& set(int degreeU,
                       int degreeV,
                       int propsInU,
                       int propsInV,
                       int numControlPointsInU,
                       int numControlPointsInV,
                       const GcGePoint3d controlPoints[],
                       const double weights[],
                       const GcGeKnotVector& uKnots,
                       const GcGeKnotVector& vKnots,
                       const GcGeTol& tol = GcGeContext::gTol);
};

#pragma pack (pop)
#endif
