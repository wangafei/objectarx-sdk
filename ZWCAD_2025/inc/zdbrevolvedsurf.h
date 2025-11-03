#pragma once

#ifndef ZDBREVOLVEDSURF_H
#define ZDBREVOLVEDSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)
class ZCDB_PORT ZcDbRevolvedSurface: public ZcDbSurface
{
public:
    ZcDbRevolvedSurface ();
    virtual ~ZcDbRevolvedSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbRevolvedSurface);
    virtual Zcad::ErrorStatus createRevolvedSurface ( ZcDbEntity* pRevEnt,
        const ZcGePoint3d& axisPnt, const ZcGeVector3d& axisDir,
        double revAngle, double startAngle,
        ZcDbRevolveOptions& revolveOptions );
    ZcDbEntity*   getRevolveEntity () const;

    ZcDb3dProfile* revolveProfile () const;

    ZcGePoint3d        getAxisPnt () const;
    Zcad::ErrorStatus  setAxisPnt ( const ZcGePoint3d& pnt );
    ZcGeVector3d       getAxisVec () const;
    Zcad::ErrorStatus  setAxisVec ( const ZcGeVector3d& vec );
    double             getRevolveAngle () const;
    Zcad::ErrorStatus  setRevolveAngle ( double ang );
    double             getStartAngle () const;
    void               getRevolveOptions ( ZcDbRevolveOptions& revolveOptions ) const;
    Zcad::ErrorStatus  setRevolveOptions ( const ZcDbRevolveOptions& revolveOptions );
    Zcad::ErrorStatus  setRevolve ( const ZcGePoint3d& axisPnt, const ZcGeVector3d& axisVec,
                                    double revAngle, const ZcDbRevolveOptions& revolveOptions );

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

     virtual bool isDependent() const;

protected:
    
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};
#pragma pack(pop)

#endif 
