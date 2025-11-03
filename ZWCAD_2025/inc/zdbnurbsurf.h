
#pragma once

#include "zdbsurf.h"
class ZcGeKnotVector;
class ZcGeNurbSurface;

#pragma pack(push, 8)

class ZCDB_PORT ZcDbNurbSurface: public ZcDbSurface
{
public:

    ZcDbNurbSurface();
    ZcDbNurbSurface(int uDegree, int vDegree, bool rational,
                    int uNumControlPoints, int vNumControlPoints,
                    const ZcGePoint3dArray& ctrlPts,
                    const ZcGeDoubleArray& weights,
                    const ZcGeKnotVector& uKnots, const ZcGeKnotVector& vKnots );

    virtual ~ZcDbNurbSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbNurbSurface);

    Zcad::ErrorStatus get (int& uDegree, int& vDegree, bool& rational,
                            int& uNumControlPoints, int& vNumControlPoints,
                            ZcGePoint3dArray& ctrlPts, 
                            ZcGeDoubleArray& weights,
                            ZcGeKnotVector& uKnots, ZcGeKnotVector& vKnots) const;
    Zcad::ErrorStatus set (int uDegree, int vDegree, bool rational,
                            int uNumControlPoints, int vNumControlPoints,
                            const ZcGePoint3dArray& ctrlPts,
                            const ZcGeDoubleArray& weights,
                            const ZcGeKnotVector& uKnots, const ZcGeKnotVector& vKnots);    

    Zcad::ErrorStatus getControlPoints(int& uCount, int& vCount, ZcGePoint3dArray& points) const;
    Zcad::ErrorStatus setControlPoints(int uCount, int vCount, const ZcGePoint3dArray& points);

    Zcad::ErrorStatus getControlPointAt(int uIndex, int vIndex, ZcGePoint3d& point) const;
    Zcad::ErrorStatus setControlPointAt(int uIndex, int vIndex, const ZcGePoint3d& point);
    
    Zcad::ErrorStatus getNumberOfControlPointsInU(int& count) const;
    Zcad::ErrorStatus getNumberOfControlPointsInV(int& count) const;
    
    Zcad::ErrorStatus getUKnots(ZcGeKnotVector& knots) const;
    Zcad::ErrorStatus getVKnots(ZcGeKnotVector& knots) const;
    
    Zcad::ErrorStatus getNumberOfKnotsInU(int& count) const;
    Zcad::ErrorStatus getNumberOfKnotsInV(int& count) const;

    Zcad::ErrorStatus getWeight(int uIndex, int vIndex, double& weight ) const;
    Zcad::ErrorStatus setWeight(int uIndex, int vIndex, double weight );
    
    Zcad::ErrorStatus evaluate(double u, double v, ZcGePoint3d& pos) const;
    Zcad::ErrorStatus evaluate(double u, double v, ZcGePoint3d& pos, ZcGeVector3d& uDeriv, ZcGeVector3d& vDeriv) const;
    Zcad::ErrorStatus evaluate(double u, double v, ZcGePoint3d& pos, ZcGeVector3d& uDeriv, ZcGeVector3d& vDeriv,
                                ZcGeVector3d& uuDeriv, ZcGeVector3d& uvDeriv, ZcGeVector3d& vvDeriv) const;
    Zcad::ErrorStatus evaluate(double u, double v, int derivDegree, ZcGePoint3d& point, ZcGeVector3dArray& derivatives) const;
    
    Zcad::ErrorStatus getDegreeInU(int& degree) const;
    Zcad::ErrorStatus getDegreeInV(int& degree) const;
    
    Zcad::ErrorStatus isClosedInU(bool& isClosed) const;
    Zcad::ErrorStatus isClosedInV(bool& isClosed) const;
    
    Zcad::ErrorStatus isPeriodicInU(bool& isPeriodic) const;
    Zcad::ErrorStatus isPeriodicInV(bool& isPeriodic) const;
    
    Zcad::ErrorStatus getPeriodInU(double& period) const;
    Zcad::ErrorStatus getPeriodInV(double& period) const;
    
    Zcad::ErrorStatus isRational(bool& isRational) const;

    Zcad::ErrorStatus isPlanar(bool& isPlanar, ZcGePoint3d& ptOnSurface, ZcGeVector3d& normal) const;

    Zcad::ErrorStatus isPointOnSurface(const ZcGePoint3d& point, bool& onSurface) const;

    Zcad::ErrorStatus getNormal(double u, double v, ZcGeVector3d& normal) const;
    
    Zcad::ErrorStatus getNumberOfSpansInU(int& span) const;
    Zcad::ErrorStatus getNumberOfSpansInV(int& span) const;
    
    Zcad::ErrorStatus getIsolineAtU(double u, ZcArray<ZcDbCurve*>& lineSegments) const;
    Zcad::ErrorStatus getIsolineAtV(double v, ZcArray<ZcDbCurve*>& lineSegments) const;
    
    Zcad::ErrorStatus InsertKnotAtU(double u);
    Zcad::ErrorStatus InsertKnotAtV(double v);
    
    Zcad::ErrorStatus InsertControlPointsAtU(double u, const ZcGePoint3dArray& vCtrlPts, const ZcGeDoubleArray& vWeights);
    Zcad::ErrorStatus InsertControlPointsAtV(double v, const ZcGePoint3dArray& uCtrlPts, const ZcGeDoubleArray& uWeights);
    Zcad::ErrorStatus RemoveControlPointsAtU(int uIndex);
    Zcad::ErrorStatus RemoveControlPointsAtV(int vIndex);
    
    Zcad::ErrorStatus rebuild(int uDegree, int vDegree, int numUCtrlPts, int numVCtrlPts, bool bRestore = false);
    
    Zcad::ErrorStatus modifyPositionAndTangent(double u, double v, const ZcGePoint3d& point,
                                 const ZcGeVector3d* uDeriv = NULL, const ZcGeVector3d* vDeriv = NULL);
    
    Zcad::ErrorStatus getParameterOfPoint(const ZcGePoint3d& point, double& u, double& v) const;
   
    void              dragStatus         (const ZcDb::DragStat status) override;
protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

