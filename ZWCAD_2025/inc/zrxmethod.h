
#pragma once

#include "zacbasedefs.h"
#include "zadesk.h"
#include "zacadstrc.h"
#include "zrxmember.h"

class ZcRxValue;
class ZcRxMethodImp;
class ZcRxMethodIteratorImp;

class ZcRxMethod : public ZcRxMember
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxMethod, ZCBASE_PORT);

    ZCBASE_PORT Zcad::ErrorStatus invoke(ZcRxObject* pO, ZcRxValue& param) const;

    ZCBASE_PORT Zcad::ErrorStatus isExecutable(const ZcRxObject* pO, const ZcRxValue& param) const;

protected:

    ZCBASE_PORT ~ZcRxMethod();

    ZCBASE_PORT ZcRxMethod(const ZTCHAR* name, const ZcRxValueType& type);

    virtual Zcad::ErrorStatus subInvoke(ZcRxObject* pO, ZcRxValue& param) const;

    virtual Zcad::ErrorStatus subIsExecutable(const ZcRxObject* pO, const ZcRxValue& param) const;

protected:
    friend class ZcRxMethodImp;
    ZCBASE_PORT ZcRxMethod(ZcRxMethodImp*);
};

