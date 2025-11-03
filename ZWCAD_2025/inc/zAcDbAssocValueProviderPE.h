
#pragma once
#include "zacdb.h"
#include "zdbeval.h"
#include "zAcDbAssocGlobal.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocValueProviderPE : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocValueProviderPE);

    virtual bool canGetValue(const ZcDbObject* pObject, const ZcString& valueName) {
        ZSOFT_UNREFED_PARAM(pObject);
        ZSOFT_UNREFED_PARAM(valueName);
        return true;
    }

    virtual bool canSetValue(const ZcDbObject* pObject, const ZcString& valueName) {
        ZSOFT_UNREFED_PARAM(pObject);
        ZSOFT_UNREFED_PARAM(valueName);
        return false;
    }

    virtual Zcad::ErrorStatus getValue(const ZcDbObject* pObject,
                                       const ZcString&   valueName,
                                       ZcDbEvalVariant&  value) = 0;

    virtual Zcad::ErrorStatus setValue(ZcDbObject*            pObject,
                                       const ZcString&        valueName,
                                       const ZcDbEvalVariant& newValue)
    {
        ZSOFT_UNREFED_PARAM(pObject);
        ZSOFT_UNREFED_PARAM(valueName);
        ZSOFT_UNREFED_PARAM(newValue);
        return Zcad::eNotHandled;
    }

    static Zcad::ErrorStatus getObjectValue(const ZcDbObjectId&, const ZcString& valueName, ZcDbEvalVariant& value);
    static Zcad::ErrorStatus setObjectValue(const ZcDbObjectId&, const ZcString& valueName, const ZcDbEvalVariant& value);

};

#pragma pack (pop)
