
#ifndef ZCDB_ANNOTATIONSCALE_H
#define ZCDB_ANNOTATIONSCALE_H

#pragma once
#pragma pack(push, 8)

#include "zdbObjContext.h"

class ZcDbImpAnnotationScale;

class ZCDBCORE2D_PORT ZcDbAnnotationScale : public ZcDbObjectContext, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAnnotationScale);
    ZcDbAnnotationScale ();
    virtual ~ZcDbAnnotationScale ();
	
    virtual Zcad::ErrorStatus getName (ZcString& name) const override;
    virtual Zcad::ErrorStatus setName (const ZcString& name) override;
    virtual ZSoft::LongPtr uniqueIdentifier () const override;
    virtual ZcString collectionName () const override;
    virtual Zcad::ErrorStatus copyFrom ( const ZcRxObject *pOther) override;
    virtual Zcad::ErrorStatus getPaperUnits (double& dPaperUnits) const;
    virtual Zcad::ErrorStatus setPaperUnits (double dPaperUnits);
    virtual Zcad::ErrorStatus getDrawingUnits (double&  dDrawingUnits) const;
    virtual Zcad::ErrorStatus setDrawingUnits (const double dDrawingUnits);
    virtual Zcad::ErrorStatus getScale (double& dScale) const;
    virtual Zcad::ErrorStatus  getIsTemporaryScale (bool& bTemporary) const;
    virtual bool matchScaleId(ZSoft::LongPtr id) const;
protected:
    ZcDbImpAnnotationScale* mpImp;
    friend class ZcDbSystemInternals;
    ZcDbAnnotationScale ( bool );

};

class ZCDBCORE2D_PORT ZcDbAnnotationScaleReactor: public ZcRxObject	
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAnnotationScaleReactor);

	virtual void annotationScaleChanged (const ZcDbDatabase* pDb,
		const ZcDbViewport* pVP, 
		const ZcDbAnnotationScale* pScale,
		const bool bInitializing);
};

ZCDBCORE2D_PORT bool zcdbAddAnnotationScaleReactor(ZcDbAnnotationScaleReactor *pReactor);	

ZCDBCORE2D_PORT bool zcdbRemoveAnnotationScaleReactor(ZcDbAnnotationScaleReactor *pReactor);		

#pragma pack(pop)

#endif
