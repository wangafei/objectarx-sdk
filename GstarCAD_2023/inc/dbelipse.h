/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GEOMENT_DBELIPSE_H
#define GEOMENT_DBELIPSE_H
#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbEllipse : public GcDbCurve
{
public:
  GcDbEllipse();
  GcDbEllipse(const GcGePoint3d&  center,
    const GcGeVector3d& unitNormal,
    const GcGeVector3d& majorAxis,
    double              radiusRatio,
    double              startAngle = 0.0,
    double              endAngle = 6.28318530717958647692);
  ~GcDbEllipse();
  GCDB_DECLARE_MEMBERS(GcDbEllipse);

  GcGePoint3d center() const;
  Gcad::ErrorStatus setCenter(const GcGePoint3d& center);
  GcGeVector3d normal() const;
  GcGeVector3d majorAxis() const;
  GcGeVector3d minorAxis() const;
  double majorRadius() const;
  Gcad::ErrorStatus setMajorRadius(double);
  double minorRadius() const;
  Gcad::ErrorStatus setMinorRadius(double);
  double radiusRatio() const;
  Gcad::ErrorStatus setRadiusRatio(double ratio);
  double startAngle() const;
  Gcad::ErrorStatus setStartAngle(double startAngle);
  double endAngle() const;
  Gcad::ErrorStatus setEndAngle(double endAngle);
  Gcad::ErrorStatus setStartParam(double startParam);
  Gcad::ErrorStatus setEndParam(double endParam);
  double paramAtAngle(double angle) const;
  double angleAtParam(double param) const;

  Gcad::ErrorStatus get(GcGePoint3d& center, GcGeVector3d& unitNormal,
    GcGeVector3d& majorAxis, double& radiusRatio, double& startAngle,
    double& endAngle) const;
  Gcad::ErrorStatus set(const GcGePoint3d& center,
    const GcGeVector3d& unitNormal, const GcGeVector3d& majorAxis,
    double radiusRatio, double startAngle = 0.0,
    double endAngle = 6.28318530717958647692);
  Gsoft::Boolean isNull() const;

  DBCURVE_METHODS

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif