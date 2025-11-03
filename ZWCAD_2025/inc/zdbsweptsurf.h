
#pragma once

#ifndef ZDBSWEPTSURF_H
#define ZDBSWEPTSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)

class ZCDB_PORT ZcDbSweptSurface: public ZcDbSurface
{
public:
    ZcDbSweptSurface ();
    virtual ~ZcDbSweptSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbSweptSurface);
    virtual Zcad::ErrorStatus createSweptSurface ( ZcDbEntity* pSweepEnt,
        ZcDbEntity* pPathEnt, ZcDbSweepOptions& sweepOptions );
    ZcDbEntity*   getSweepEntity () const;
    ZcDbEntity*   getPathEntity () const;

	ZcDb3dProfile* sweepProfile () const;
	ZcDb3dProfile* pathProfile () const;

    void               getSweepOptions ( ZcDbSweepOptions& sweepOptions ) const;
    Zcad::ErrorStatus  setSweepOptions ( const ZcDbSweepOptions& sweepOptions );
    Zcad::ErrorStatus  getPathLength ( double& len ) const;

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
