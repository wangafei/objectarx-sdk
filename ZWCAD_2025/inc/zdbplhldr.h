

#ifndef ZD_DBPLACEHOLDER_H
#define ZD_DBPLACEHOLDER_H

#include "zdbmain.h"

#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbPlaceHolder : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbPlaceHolder);
	ZcDbPlaceHolder();
    virtual ~ZcDbPlaceHolder();
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;

protected:
    virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwnerObject,
					  ZcDbObject*& pClonedObject,
					  ZcDbIdMapping& idMap,
					  ZSoft::Boolean isPrimary
					  = ZSoft::kTrue) const override;

};

#pragma pack (pop)

#endif

