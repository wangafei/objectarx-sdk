/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBRAY_H
#define GD_DBRAY_H 1

#include "dbmain.h"
#include "dbcurve.h"

#pragma pack(push, 8)

class GcGePoint3d;
class GcGeVector3d;

class GCDB_PORT GcDbRay : public GcDbCurve
{
public:
  GcDbRay();
  ~GcDbRay();
  GCDB_DECLARE_MEMBERS(GcDbRay);
  DBCURVE_METHODS

  Gcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
    const GcGeVector3d& normal, double offsetDist,
    GcDbVoidPtrArray& offsetCurves) const override;

  GcGePoint3d  basePoint() const;
  void         setBasePoint(const GcGePoint3d& pt);
  GcGeVector3d unitDir() const;
  void         setUnitDir(const GcGeVector3d& vec);

  GcGePoint3d         secondPoint() const;
  Gcad::ErrorStatus	setSecondPoint(GcGePoint3d const & pt);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbRay::isClosed() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbRay::isPeriodic() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbRay::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDbRay::getStartParam(double& startParam) const
{
  startParam = 0.0;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcDbRay::getEndParam(double&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbRay::getEndPoint(GcGePoint3d&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbRay::getSpline(GcDbSpline*&) const
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbRay::getArea(double&) const
{
  return Gcad::eNotApplicable;
}

#pragma pack(pop)

#endif