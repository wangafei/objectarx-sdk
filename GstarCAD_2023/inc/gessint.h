/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESSINT_H
#define GC_GESSINT_H

#include "gsoft.h"
#include "geent3d.h"
#include "gegbl.h"
#include "gegblabb.h"
#pragma pack (push, 8)

class GcGeCurve3d;
class GcGeCurve2d;
class GcGeSurface;

class GX_DLLEXPIMPORT GcGeSurfSurfInt : public GcGeEntity3d
{
public:
  GcGeSurfSurfInt();
  GcGeSurfSurfInt(const GcGeSurface& srf1, const GcGeSurface& srf2, const GcGeTol& tol = GcGeContext::gTol);
  GcGeSurfSurfInt(const GcGeSurfSurfInt& src);

  const GcGeSurface  *surface1() const;
  const GcGeSurface  *surface2() const;
  GcGeTol            tolerance() const;

  int           numResults(GcGe::GcGeIntersectError& err) const;
  GcGeCurve3d*  intCurve(int intNum, Gsoft::Boolean isExternal, GcGe::GcGeIntersectError& err) const;
  GcGeCurve2d*  intParamCurve(int num, Gsoft::Boolean isExternal, Gsoft::Boolean isFirst, GcGe::GcGeIntersectError& err) const;
  GcGePoint3d   intPoint(int intNum, GcGe::GcGeIntersectError& err) const;
  void          getIntPointParams(int intNum, GcGePoint2d& param1, GcGePoint2d& param2, GcGe::GcGeIntersectError& err) const;
  void          getIntConfigs(int intNum,
                              GcGe::ssiConfig& surf1Left,
                              GcGe::ssiConfig& surf1Right,
                              GcGe::ssiConfig& surf2Left,
                              GcGe::ssiConfig& surf2Right,
                              GcGe::ssiType& intType,
                              int& dim,
                              GcGe::GcGeIntersectError& err) const;
  int           getDimension(int intNum, GcGe::GcGeIntersectError& err) const;
  GcGe::ssiType getType(int intNum, GcGe::GcGeIntersectError& err) const;

  GcGeSurfSurfInt& set(const GcGeSurface& srf1,
                       const GcGeSurface& srf2,
                       const GcGeTol& tol = GcGeContext::gTol);

  GcGeSurfSurfInt& operator = (const GcGeSurfSurfInt& crvInt);
};
#pragma pack (pop)
#endif
