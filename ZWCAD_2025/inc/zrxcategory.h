
#pragma once

#include "zacbasedefs.h"
#include "zadesk.h"
#include "zacadstrc.h"
#include "zpimplapi.h"

class ZcRxCategory : public ZcRxMember
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxCategory, ZCBASE_PORT);

    ZCBASE_PORT ZcRxCategory(const ZTCHAR* name, ZcRxCategory* pOwner) throw();

    ZCBASE_PORT Zcad::ErrorStatus removeChild(ZcRxCategory* pChildCategory);

    ZCBASE_PORT ZcRxCategory* findDescendant(const ZTCHAR* name) const;

    ZCBASE_PORT static ZcRxCategory* rootCategory();
private:

    ZCBASE_PORT virtual ~ZcRxCategory();
};

ZCBASE_PORT Zcad::ErrorStatus
zcdbGetLegacyCategoryId(const ZcRxCategory* pCategory, int& legacyId);

ZCBASE_PORT Zcad::ErrorStatus
zcdbSetLegacyCategoryId(ZcRxCategory* pCategory, int legacyId);