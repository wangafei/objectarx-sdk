/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECINT3D_H
#define GC_GECINT3D_H

#include "gsoft.h"
#include "geent3d.h"
#include "geponc3d.h"
#include "geintrvl.h"
#pragma pack (push, 8)

class GcGeCurve3d;

class
  GE_DLLDATAEXIMP
  GcGeCurveCurveInt3d : public GcGeEntity3d
{
public:
  GcGeCurveCurveInt3d();
  GcGeCurveCurveInt3d(const GcGeCurve3d& curve1, const GcGeCurve3d& curve2,
    const GcGeVector3d& planeNormal =
    GcGeVector3d::kIdentity,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveCurveInt3d(const GcGeCurve3d& curve1, const GcGeCurve3d& curve2,
    const GcGeInterval& range1, const GcGeInterval& range2,
    const GcGeVector3d& planeNormal = GcGeVector3d::kIdentity,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveCurveInt3d(const GcGeCurveCurveInt3d& src);

  const GcGeCurve3d  *curve1() const;
  const GcGeCurve3d  *curve2() const;
  void               getIntRanges(GcGeInterval& range1,
    GcGeInterval& range2) const;
  GcGeVector3d	   planeNormal() const;
  GcGeTol            tolerance() const;
  int                numIntPoints() const;
  GcGePoint3d        intPoint(int intNum) const;
  void               getIntParams(int intNum,
    double& param1, double& param2) const;
  void               getPointOnCurve1(int intNum, GcGePointOnCurve3d& pntOnCrv) const;
  void               getPointOnCurve2(int intNum, GcGePointOnCurve3d& pntOnCrv) const;
  void			   getIntConfigs(int intNum, GcGe::GcGeXConfig& config1wrt2,
    GcGe::GcGeXConfig& config2wrt1) const;
  Gsoft::Boolean     isTangential(int intNum) const;
  Gsoft::Boolean     isTransversal(int intNum) const;
  double             intPointTol(int intNum) const;
  int                overlapCount() const;
  Gsoft::Boolean	   overlapDirection() const;
  void               getOverlapRanges(int overlapNum,
    GcGeInterval& range1,
    GcGeInterval& range2) const;
  void               changeCurveOrder();

  GcGeCurveCurveInt3d& orderWrt1();
  GcGeCurveCurveInt3d& orderWrt2();

  GcGeCurveCurveInt3d& set(const GcGeCurve3d& curve1,
    const GcGeCurve3d& curve2,
    const GcGeVector3d& planeNormal =
    GcGeVector3d::kIdentity,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveCurveInt3d& set(const GcGeCurve3d& curve1,
    const GcGeCurve3d& curve2,
    const GcGeInterval& range1,
    const GcGeInterval& range2,
    const GcGeVector3d& planeNormal =
    GcGeVector3d::kIdentity,
    const GcGeTol& tol = GcGeContext::gTol);

  GcGeCurveCurveInt3d& operator = (const GcGeCurveCurveInt3d& src);
};

#pragma pack (pop)
#endif