/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECURV3D_H
#define GC_GECURV3D_H

#include "gsoft.h"
#include "geent3d.h"
#include "geponc3d.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"
#pragma pack (push, 8)

class GcGeCurve2d;
class GcGeSurface;
class GcGePoint3d;
class GcGePlane;
class GcGeVector3d;
class GcGeLinearEnt3d;
class GcGeLine3d;
class GcGePointOnCurve3d;
class GcGePointOnSurface;
class GcGeInterval;
class GcGeMatrix3d;
class GcGePointOnCurve3dData;
class GcGeBoundBlock3d;

class
  GE_DLLDATAEXIMP
  GcGeCurve3d : public GcGeEntity3d
{
public:
  void           getInterval(GcGeInterval& intrvl) const;
  void           getInterval(GcGeInterval& intrvl, GcGePoint3d& start,
    GcGePoint3d& end) const;
  GcGeCurve3d&   reverseParam();
  GcGeCurve3d&   setInterval();
  Gsoft::Boolean setInterval(const GcGeInterval& intrvl);

  double       distanceTo(const GcGePoint3d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  double       distanceTo(const GcGeCurve3d& curve,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGePoint3d closestPointTo(const GcGePoint3d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGePoint3d closestPointTo(const GcGeCurve3d& curve3d,
    GcGePoint3d& pntOnOtherCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  void getClosestPointTo(const GcGePoint3d& pnt, GcGePointOnCurve3d& pntOnCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;
  void getClosestPointTo(const GcGeCurve3d& curve3d,
    GcGePointOnCurve3d& pntOnThisCrv,
    GcGePointOnCurve3d& pntOnOtherCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGePoint3d projClosestPointTo(const GcGePoint3d& pnt,
    const GcGeVector3d& projectDirection,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGePoint3d projClosestPointTo(const GcGeCurve3d& curve3d,
    const GcGeVector3d& projectDirection,
    GcGePoint3d& pntOnOtherCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  void getProjClosestPointTo(const GcGePoint3d& pnt,
    const GcGeVector3d& projectDirection,
    GcGePointOnCurve3d& pntOnCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;
  void getProjClosestPointTo(const GcGeCurve3d& curve3d,
    const GcGeVector3d& projectDirection,
    GcGePointOnCurve3d& pntOnThisCrv,
    GcGePointOnCurve3d& pntOnOtherCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean getNormalPoint(const GcGePoint3d& pnt,
    GcGePointOnCurve3d& pntOnCrv,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeBoundBlock3d  boundBlock() const;
  GcGeBoundBlock3d  boundBlock(const GcGeInterval& range) const;

  GcGeBoundBlock3d  orthoBoundBlock() const;
  GcGeBoundBlock3d  orthoBoundBlock(const GcGeInterval& range) const;

  GcGeEntity3d*  project(const GcGePlane& projectionPlane,
    const GcGeVector3d& projectDirection,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGeEntity3d*  orthoProject(const GcGePlane& projectionPlane,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isOn(const GcGePoint3d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(const GcGePoint3d& pnt, double& param,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(double param,
    const GcGeTol& tol = GcGeContext::gTol) const;

  double paramOf(const GcGePoint3d& pnt, const GcGeTol& tol = GcGeContext::gTol)const;

  void getTrimmedOffset(double distance,
    const GcGeVector3d& planeNormal,
    GcGeVoidPointerArray& offsetCurveList,
    GcGe::OffsetCrvExtType extensionType = GcGe::kFillet,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isClosed(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPlanar(GcGePlane& plane,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isLinear(GcGeLine3d& line,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isCoplanarWith(const GcGeCurve3d& curve3d,
    GcGePlane& plane,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPeriodic(double& period) const;

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
  Gsoft::Boolean isDegenerate(GcGeEntity3d*& pConvertedEntity,
    const GcGeTol& tol = GcGeContext::gTol) const;

  void getSplitCurves(double param, GcGeCurve3d* & piece1,
    GcGeCurve3d* & piece2) const;

  Gsoft::Boolean explode(GcGeVoidPointerArray& explodedCurves,
    GcGeIntArray& newExplodedCurves,
    const GcGeInterval* intrvl = NULL) const;

  void getLocalClosestPoints(const GcGePoint3d& point,
    GcGePointOnCurve3d& approxPnt,
    const GcGeInterval* nbhd = 0,
    const GcGeTol& tol = GcGeContext::gTol) const;
  void getLocalClosestPoints(const GcGeCurve3d& otherCurve,
    GcGePointOnCurve3d& approxPntOnThisCrv,
    GcGePointOnCurve3d& approxPntOnOtherCrv,
    const GcGeInterval* nbhd1 = 0,
    const GcGeInterval* nbhd2 = 0,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean hasStartPoint(GcGePoint3d& startPnt) const;
  Gsoft::Boolean hasEndPoint(GcGePoint3d& endPnt) const;

  GcGePoint3d    evalPoint(double param) const;
  GcGePoint3d    evalPoint(double param, int numDeriv,
    GcGeVector3dArray& derivArray) const;

  void           getSamplePoints(double fromParam, double toParam, double approxEps,
    GcGePoint3dArray& pointArray, GcGeDoubleArray& paramArray,
    bool forceResampling = false) const;
  void           getSamplePoints(int numSample, GcGePoint3dArray& pointArray) const;
  void           getSamplePoints(int numSample, GcGePoint3dArray& pointArray,
    GcGeDoubleArray& paramArray) const;

  GcGeCurve3d&   operator =  (const GcGeCurve3d& curve);

protected:
  GcGeCurve3d();
  GcGeCurve3d(const GcGeCurve3d&);
};

#pragma pack (pop)
#endif