
#pragma once

#ifndef ZDBPLANESURF_H
#define ZDBPLANESURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)

class ZCDBCORE2D_PORT ZcDbPlaneSurface: public ZcDbSurface
{
public:
    ZcDbPlaneSurface ();
    virtual ~ZcDbPlaneSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbPlaneSurface);
    virtual Zcad::ErrorStatus createFromRegion ( ZcDbRegion *pRegion );

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
