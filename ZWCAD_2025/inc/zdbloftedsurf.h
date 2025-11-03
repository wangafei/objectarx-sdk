
#pragma once

#ifndef ZDBLOFTEDSURF_H
#define ZDBLOFTEDSURF_H

#include "zdbsurf.h"
#include "zdb3dProfile.h"

#pragma pack(push, 8)

class ZCDB_PORT ZcDbLoftedSurface: public ZcDbSurface
{
public:
    ZcDbLoftedSurface ();
    virtual ~ZcDbLoftedSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbLoftedSurface);
    virtual Zcad::ErrorStatus createLoftedSurface (
        ZcArray<ZcDbEntity*>& crossSectionCurves,
        ZcArray<ZcDbEntity*>& guideCurves,
        ZcDbEntity* pPathCurve, ZcDbLoftOptions& loftOptions );
    int           numCrossSections () const;
    ZcDbEntity*   getCrossSection ( int idx ) const;
    int           numGuideCurves () const;
    ZcDbEntity*   getGuideCurve ( int idx ) const;
    ZcDbEntity*   getPathEntity () const;
    void          getLoftOptions ( ZcDbLoftOptions& loftOptions ) const;

	
	ZcDbLoftProfile*  crossSection ( int idx ) const;

	void              getCrossSections ( ZcArray<ZcDbLoftProfile*>& crossSections ) const;

	ZcDbLoftProfile*  guide ( int idx ) const;

	void              getGuides ( ZcArray<ZcDbLoftProfile*>& guides ) const;

	ZcDbLoftProfile*  path () const;

	int               startContinuity ( bool isCrossSection = true ) const;

	int               endContinuity ( bool isCrossSection = true ) const;

	double            startMagnitude ( bool isCrossSection = true ) const;

	double            endMagnitude ( bool isCrossSection = true ) const;

	Zcad::ErrorStatus setStartContinuity ( int val, bool isCrossSection = true );

	Zcad::ErrorStatus setEndContinuity ( int val, bool isCrossSection = true );

	Zcad::ErrorStatus setStartMagnitude ( double val, bool isCrossSection = true );

	Zcad::ErrorStatus setEndMagnitude ( double val, bool isCrossSection = true );

	Zcad::ErrorStatus setLoftOptions ( const ZcDbLoftOptions& loftOptions );


	enum LoftSurfaceType
	{
		kLoftSurf,
		kLoftBlendSurf,
		kLoftNetworkSurf
	}; 

	ZcDbLoftedSurface::LoftSurfaceType  loftSurfaceType () const;


	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override; 
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
    virtual bool isDependent() const;

protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;   
};

#pragma pack(pop)

#endif 
