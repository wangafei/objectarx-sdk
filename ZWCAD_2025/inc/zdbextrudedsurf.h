
#pragma once

#ifndef ZDBEXTRUDEDSURF_H
#define ZDBEXTRUDEDSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)
class ZCDB_PORT ZcDbExtrudedSurface: public ZcDbSurface
{
public:
    ZcDbExtrudedSurface ();
    virtual ~ZcDbExtrudedSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbExtrudedSurface);
    virtual Zcad::ErrorStatus createExtrudedSurface ( ZcDbEntity* pSweepEnt,
        const ZcGeVector3d& directionVec, ZcDbSweepOptions& sweepOptions );
    ZcDbEntity*   getSweepEntity () const;
	ZcDb3dProfile* sweepProfile () const;		

    ZcGeVector3d       getSweepVec () const;
    Zcad::ErrorStatus  setSweepVec ( const ZcGeVector3d& sweepVec );
    double             getHeight () const;
    Zcad::ErrorStatus  setHeight ( double height );
    void               getSweepOptions ( ZcDbSweepOptions& sweepOptions ) const;
    Zcad::ErrorStatus  setSweepOptions ( const ZcDbSweepOptions& sweepOptions );
    Zcad::ErrorStatus  setExtrude ( const ZcGeVector3d& sweepVec,
                                    const ZcDbSweepOptions& sweepOptions );

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
