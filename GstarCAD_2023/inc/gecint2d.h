/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECINT2D_H
#define GC_GECINT2D_H

#include "gsoft.h"
#include "gegbl.h"
#include "geent2d.h"
#include "geponc2d.h"
#include "geintrvl.h"
#pragma pack (push, 8)

class GcGeCurve2d;

class
  GE_DLLDATAEXIMP
  GcGeCurveCurveInt2d : public GcGeEntity2d
{
public:
  GcGeCurveCurveInt2d();
  GcGeCurveCurveInt2d(const GcGeCurve2d& curve1, const GcGeCurve2d& curve2,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveCurveInt2d(const GcGeCurve2d& curve1, const GcGeCurve2d& curve2,
    const GcGeInterval& range1, const GcGeInterval& range2,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveCurveInt2d(const GcGeCurveCurveInt2d& src);

  const GcGeCurve2d  *curve1() const;
  const GcGeCurve2d  *curve2() const;
  void               getIntRanges(GcGeInterval& range1,
    GcGeInterval& range2) const;
  GcGeTol            tolerance() const;
  int                numIntPoints() const;
  GcGePoint2d        intPoint(int intNum) const;
  void               getIntParams(int intNum,
    double& param1, double& param2) const;
  void               getPointOnCurve1(int intNum, GcGePointOnCurve2d&) const;
  void               getPointOnCurve2(int intNum, GcGePointOnCurve2d&) const;
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

  GcGeCurveCurveInt2d& orderWrt1();
  GcGeCurveCurveInt2d& orderWrt2();

  GcGeCurveCurveInt2d& set(const GcGeCurve2d& curve1,
    const GcGeCurve2d& curve2,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveCurveInt2d& set(const GcGeCurve2d& curve1,
    const GcGeCurve2d& curve2,
    const GcGeInterval& range1,
    const GcGeInterval& range2,
    const GcGeTol& tol = GcGeContext::gTol);

  GcGeCurveCurveInt2d& operator = (const GcGeCurveCurveInt2d& src);
};

#pragma pack (pop)
#endif