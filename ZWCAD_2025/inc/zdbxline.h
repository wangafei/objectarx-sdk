

#ifndef ZD_DBXLINE_H
#define ZD_DBXLINE_H 1

#include "zdbmain.h"
#include "zdbcurve.h"

#pragma pack(push, 8)

class ZcGePoint3d;
class ZcGeVector3d;

class ZCDBCORE2D_PORT ZcDbXline: public ZcDbCurve
{
public:
    ZcDbXline();
    ~ZcDbXline();
    ZCDB_DECLARE_MEMBERS(ZcDbXline);
    DBCURVE_METHODS

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const override;
    
    ZcGePoint3d  basePoint() const;
    void         setBasePoint(const ZcGePoint3d& pt); 

    ZcGeVector3d unitDir() const;
    void         setUnitDir(const ZcGeVector3d& vec);

	ZcGePoint3d               secondPoint() const;
	Zcad::ErrorStatus		setSecondPoint(ZcGePoint3d const & pt);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

    
};

inline ZSoft::Boolean ZcDbXline::isClosed() const
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbXline::isPeriodic() const
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbXline::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbXline::getStartParam(double&) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::getEndParam(double&) const
{
    
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::getStartPoint(ZcGePoint3d&) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::getEndPoint(ZcGePoint3d&) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::getSpline(ZcDbSpline*&) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::extend(double)
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::extend(ZSoft::Boolean, const ZcGePoint3d&)
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbXline::getArea(double&) const
{
    return Zcad::eNotApplicable;
}

#pragma pack(pop)

#endif

