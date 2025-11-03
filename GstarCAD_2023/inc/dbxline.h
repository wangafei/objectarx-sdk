/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBXLINE_H
#define GD_DBXLINE_H 1

#include "dbmain.h"
#include "dbcurve.h"

#pragma pack(push, 8)

class GcGePoint3d;
class GcGeVector3d;

class GCDB_PORT GcDbXline : public GcDbCurve
{
public:
  GcDbXline();
  ~GcDbXline();
  GCDB_DECLARE_MEMBERS(GcDbXline);
  DBCURVE_METHODS

  Gcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
    const GcGeVector3d& normal, double offsetDist,
    GcDbVoidPtrArray& offsetCurves) const override;

  GcGePoint3d  basePoint() const;
  void         setBasePoint(const GcGePoint3d& pt);

  GcGeVector3d unitDir() const;
  void         setUnitDir(const GcGeVector3d& vec);

  GcGePoint3d         secondPoint() const;
  Gcad::ErrorStatus		setSecondPoint(GcGePoint3d const & pt);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbXline::isClosed() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbXline::isPeriodic() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbXline::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDbXline::getStartParam(double&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::getEndParam(double&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::getStartPoint(GcGePoint3d&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::getEndPoint(GcGePoint3d&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::getSpline(GcDbSpline*&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::extend(double)
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::extend(Gsoft::Boolean, const GcGePoint3d&)
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbXline::getArea(double&) const
{
  return Gcad::eNotApplicable;
}

#pragma pack(pop)

#endif