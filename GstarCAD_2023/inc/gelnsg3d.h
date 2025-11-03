/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELNSG3D_H
#define GC_GELNSG3D_H

#include "geline3d.h"
#include "geplane.h"
#pragma pack (push, 8)

class GcGeLineSeg2d;

class GE_DLLDATAEXIMP GcGeLineSeg3d : public GcGeLinearEnt3d
{
public:
  GcGeLineSeg3d();
  GcGeLineSeg3d(const GcGeLineSeg3d& line);
  GcGeLineSeg3d(const GcGePoint3d& pnt, const GcGeVector3d& vec);
  GcGeLineSeg3d(const GcGePoint3d& pnt1, const GcGePoint3d& pnt2);

  void           getBisector(GcGePlane& plane) const;

  GcGePoint3d    baryComb(double blendCoeff) const;
  GcGePoint3d    startPoint() const;
  GcGePoint3d    midPoint() const;
  GcGePoint3d    endPoint() const;
  double         length() const;
  double         length(double fromParam,
                                        double toParam,
                                        double tol = GcGeContext::gTol.equalPoint()) const;
  GcGeLineSeg3d& set(const GcGePoint3d& pnt, const GcGeVector3d& vec);
  GcGeLineSeg3d& set(const GcGePoint3d& pnt1, const GcGePoint3d& pnt2);
  GcGeLineSeg3d& set(const GcGeCurve3d& curve1,
                                     const GcGeCurve3d& curve2,
                                     double&            param1,
                                     double&            param2,
                                     Gsoft::Boolean&    success);
  GcGeLineSeg3d& set(const GcGeCurve3d& curve,
                                     const GcGePoint3d& point,
                                     double&            param,
                                     Gsoft::Boolean&    success);

  GcGeLineSeg3d& operator =   (const GcGeLineSeg3d& line);
};

#pragma pack (pop)
#endif
