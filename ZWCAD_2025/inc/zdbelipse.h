

#ifndef ZGEOMENT_DBELIPSE_H
#define ZGEOMENT_DBELIPSE_H

#include "zgegbl.h"
#include "zdbmain.h"
#include "zdbcurve.h"

#pragma pack(push, 8)

class ZCDBCORE2D_PORT ZcDbEllipse: public  ZcDbCurve
{
public:
    ZcDbEllipse();
    ZcDbEllipse(const ZcGePoint3d&  center,
	        const ZcGeVector3d& unitNormal,
	        const ZcGeVector3d& majorAxis,
	        double              radiusRatio,
	        double              startAngle = 0.0,
	        double              endAngle   = 6.28318530717958647692);
    virtual ~ZcDbEllipse();
    ZCDB_DECLARE_MEMBERS(ZcDbEllipse);

    ZcGePoint3d center() const;
    Zcad::ErrorStatus setCenter(const ZcGePoint3d& center);

    ZcGeVector3d normal() const;
    ZcGeVector3d majorAxis() const;
    ZcGeVector3d minorAxis() const;
	double majorRadius() const;
	Zcad::ErrorStatus setMajorRadius(double);
	double minorRadius() const;
	Zcad::ErrorStatus setMinorRadius(double);

    double radiusRatio() const;
    Zcad::ErrorStatus setRadiusRatio(double ratio);

    double startAngle() const;
    Zcad::ErrorStatus setStartAngle(double startAngle);    

    double endAngle() const;
    Zcad::ErrorStatus setEndAngle(double endAngle);

    Zcad::ErrorStatus setStartParam(double startParam);
    Zcad::ErrorStatus setEndParam(double endParam);

    double paramAtAngle(double angle) const;
    double angleAtParam(double param) const;

    Zcad::ErrorStatus get(ZcGePoint3d& center, ZcGeVector3d& unitNormal,
	ZcGeVector3d& majorAxis, double& radiusRatio, double& startAngle,
	double& endAngle) const;
    Zcad::ErrorStatus set(const ZcGePoint3d& center,
	const ZcGeVector3d& unitNormal, const ZcGeVector3d& majorAxis,
	double radiusRatio, double startAngle = 0.0,
	double endAngle = 6.28318530717958647692);

    ZSoft::Boolean isNull() const;
				   
    DBCURVE_METHODS

protected:

	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif
