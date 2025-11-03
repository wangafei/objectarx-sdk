/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECURV2D_H
#define GC_GECURV2D_H

#include "gsoft.h"
#include "geent2d.h"
#include "geponc2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"
#pragma pack (push, 8)

class GcGePoint2d;
class GcGeVector2d;
class GcGePointOnCurve2d;
class GcGeInterval;
class GcGeMatrix2d;
class GcGeLine2d;
class GcGePointOnCurve2dData;
class GcGeBoundBlock2d;

class
  GE_DLLDATAEXIMP
  GcGeCurve2d : public GcGeEntity2d
{
public:
  void           getInterval(GcGeInterval& intrvl) const;
  void           getInterval(GcGeInterval& intrvl, GcGePoint2d& start,
    GcGePoint2d& end) const;
  GcGeCurve2d&   reverseParam();
  GcGeCurve2d&   setInterval();
  Gsoft::Boolean setInterval(const GcGeInterval& intrvl);

  double         distanceTo(const GcGePoint2d& pnt,
    const GcGeTol& = GcGeContext::gTol) const;
  double         distanceTo(const GcGeCurve2d&,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGePoint2d closestPointTo(const GcGePoint2d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGePoint2d closestPointTo(const GcGeCurve2d& curve2d,
    GcGePoint2d& pntOnOtherCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  void getClosestPointTo(const GcGePoint2d& pnt,
    GcGePointOnCurve2d& pntOnCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;
  void getClosestPointTo(const GcGeCurve2d& curve2d,
    GcGePointOnCurve2d& pntOnThisCrv,
    GcGePointOnCurve2d& pntOnOtherCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean getNormalPoint(const GcGePoint2d& pnt,
    GcGePointOnCurve2d& pntOnCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isOn(const GcGePoint2d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(const GcGePoint2d& pnt, double& param,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(double param,
    const GcGeTol& tol = GcGeContext::gTol) const;

  double         paramOf(const GcGePoint2d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  void           getTrimmedOffset(double distance,
    GcGeVoidPointerArray& offsetCurveList,
    GcGe::OffsetCrvExtType extensionType = GcGe::kFillet,
    const GcGeTol& = GcGeContext::gTol) const;

  Gsoft::Boolean isClosed(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPeriodic(double& period) const;
  Gsoft::Boolean isLinear(GcGeLine2d& line,
    const GcGeTol& tol = GcGeContext::gTol) const;

  double         length(double fromParam, double toParam,
    double tol = GcGeContext::gTol.equalPoint()) const;
  double         paramAtLength(double datumParam, double length,
    Gsoft::Boolean posParamDir = Gsoft::kTrue,
    double tol = GcGeContext::gTol.equalPoint()) const;
  Gsoft::Boolean area(double startParam, double endParam,
    double& value,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isDegenerate(GcGe::EntityId& degenerateType,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isDegenerate(GcGeEntity2d*& pConvertedEntity,
    const GcGeTol& tol = GcGeContext::gTol) const;

  void           getSplitCurves(double param, GcGeCurve2d* & piece1,
    GcGeCurve2d* & piece2) const;
  Gsoft::Boolean explode(GcGeVoidPointerArray& explodedCurves,
    GcGeIntArray& newExplodedCurve,
    const GcGeInterval* intrvl = NULL) const;
  void getLocalClosestPoints(const GcGePoint2d& point,
    GcGePointOnCurve2d& approxPnt,
    const GcGeInterval* nbhd = 0,
    const GcGeTol& = GcGeContext::gTol) const;
  void getLocalClosestPoints(const GcGeCurve2d& otherCurve,
    GcGePointOnCurve2d& approxPntOnThisCrv,
    GcGePointOnCurve2d& approxPntOnOtherCrv,
    const GcGeInterval* nbhd1 = 0,
    const GcGeInterval* nbhd2 = 0,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeBoundBlock2d  boundBlock() const;
  GcGeBoundBlock2d  boundBlock(const GcGeInterval& range) const;

  GcGeBoundBlock2d  orthoBoundBlock() const;
  GcGeBoundBlock2d  orthoBoundBlock(const GcGeInterval& range) const;

  Gsoft::Boolean hasStartPoint(GcGePoint2d& startPoint) const;
  Gsoft::Boolean hasEndPoint(GcGePoint2d& endPoint) const;

  GcGePoint2d    evalPoint(double param) const;
  GcGePoint2d    evalPoint(double param, int numDeriv,
    GcGeVector2dArray& derivArray) const;

  void     getSamplePoints(double fromParam, double toParam,
    double approxEps, GcGePoint2dArray& pointArray,
    GcGeDoubleArray& paramArray) const;
  void     getSamplePoints(int numSample, GcGePoint2dArray&) const;

  GcGeCurve2d&   operator =  (const GcGeCurve2d& curve);

protected:
  GcGeCurve2d();
  GcGeCurve2d(const GcGeCurve2d&);
};

#pragma pack (pop)
#endif