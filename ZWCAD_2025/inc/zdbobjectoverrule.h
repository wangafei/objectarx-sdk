
#pragma once

#include "zrxoverrule.h"

#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbObjectOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectOverrule);

    ZcDbObjectOverrule();

    virtual Zcad::ErrorStatus open(ZcDbObject* pSubject, ZcDb::OpenMode mode);

    virtual Zcad::ErrorStatus close(ZcDbObject* pSubject);

    virtual Zcad::ErrorStatus cancel(ZcDbObject* pSubject);

    virtual Zcad::ErrorStatus erase(ZcDbObject* pSubject, ZSoft::Boolean erasing);

    virtual Zcad::ErrorStatus deepClone(const ZcDbObject* pSubject,
                                                  ZcDbObject* pOwnerObject,
                                                  ZcDbObject*& pClonedObject,
                                                  ZcDbIdMapping& idMap,
                                                  ZSoft::Boolean isPrimary = true);

    virtual Zcad::ErrorStatus wblockClone(const ZcDbObject* pSubject,
                                                    ZcRxObject* pOwnerObject,
                                                    ZcDbObject*& pClonedObject,
                                                    ZcDbIdMapping& idMap,
                                                    ZSoft::Boolean isPrimary = true);
};

#pragma pack (pop)
