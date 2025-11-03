/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELNSG2D_H
#define GC_GELNSG2D_H

#include "geline2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGeLineSeg2d : public GcGeLinearEnt2d
{
public:
  GcGeLineSeg2d();
  GcGeLineSeg2d(const GcGeLineSeg2d& line);
  GcGeLineSeg2d(const GcGePoint2d& pnt1, const GcGePoint2d& pnt2);
  GcGeLineSeg2d(const GcGePoint2d& pnt, const GcGeVector2d& vec);

  GcGeLineSeg2d& set(const GcGePoint2d& pnt, const GcGeVector2d& vec);
  GcGeLineSeg2d& set(const GcGePoint2d& pnt1, const GcGePoint2d& pnt2);
  GcGeLineSeg2d& set(const GcGeCurve2d& curve1,
                                     const GcGeCurve2d& curve2,
                                     double&            param1,
                                     double&            param2,
                                     Gsoft::Boolean&    success);
  GcGeLineSeg2d& set(const GcGeCurve2d& curve,
                                     const GcGePoint2d& point,
                                     double&            param,
                                     Gsoft::Boolean&    success);

  void           getBisector(GcGeLine2d& line) const;

  GcGePoint2d    baryComb(double blendCoeff) const;
  GcGePoint2d    startPoint() const;
  GcGePoint2d    midPoint() const;
  GcGePoint2d    endPoint() const;
  double         length() const;
  double         length(double fromParam,
                                        double toParam,
                                        double tol = GcGeContext::gTol.equalPoint()) const;
  GcGeLineSeg2d& operator =  (const GcGeLineSeg2d& line);
};

#pragma pack (pop)
#endif
