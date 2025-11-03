

#ifndef ZD_DBRAY_H
#define ZD_DBRAY_H 1

#include "zdbmain.h"
#include "zdbcurve.h"

#pragma pack(push, 8)

class ZcGePoint3d;
class ZcGeVector3d;

class ZCDBCORE2D_PORT ZcDbRay: public ZcDbCurve
{
public:
    ZcDbRay();
    ~ZcDbRay();
    ZCDB_DECLARE_MEMBERS(ZcDbRay);
    DBCURVE_METHODS

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const override;
    
    ZcGePoint3d  basePoint() const;
    void         setBasePoint(const ZcGePoint3d& pt); 

    ZcGeVector3d unitDir() const;
    void         setUnitDir(const ZcGeVector3d& vec);

    ZcGePoint3d           secondPoint() const;
    Zcad::ErrorStatus		setSecondPoint(ZcGePoint3d const & pt);

protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline ZSoft::Boolean ZcDbRay::isClosed() const      
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbRay::isPeriodic() const      
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbRay::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbRay::getStartParam(double& startParam) const
{
    startParam = 0.0;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbRay::getEndParam(double& ) const
{
    
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbRay::getEndPoint(ZcGePoint3d& ) const 
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbRay::getSpline(ZcDbSpline*& ) const 
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbRay::getArea(double& ) const 
{
    return Zcad::eNotApplicable;
}

#pragma pack(pop)

#endif
