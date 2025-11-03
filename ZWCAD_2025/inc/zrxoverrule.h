
#ifndef _ZRXOVERRULE_H
#define _ZRXOVERRULE_H

#include "zacbasedefs.h"
#include "zrxobject.h"
#include "zacarray.h"

#pragma pack (push, 8)

class ZcRxOverruleIteratorBase;

class ZSOFT_NO_VTABLE ZcRxOverruleBase : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxOverruleBase, ZCBASE_PORT);
private:
    mutable ZcRxOverruleIteratorBase* m_pIter;
    friend class ZcRxOverruleInternals;
};

#pragma warning( push )
#pragma warning( disable : 4275 )
class ZCBASE_PORT ZcRxOverrule : public ZcRxOverruleBase
{
public:

    ZCRX_DECLARE_MEMBERS(ZcRxOverrule);
    virtual ~ZcRxOverrule();

    virtual bool isApplicable(const ZcRxObject* pOverruledSubject) const = 0;

    static Zcad::ErrorStatus addOverrule(ZcRxClass* pClass, ZcRxOverrule* pOverrule, bool bAddAtLast = false);

    static Zcad::ErrorStatus removeOverrule(ZcRxClass* pClass, ZcRxOverrule* pOverrule);

    static void setIsOverruling(bool bIsOverruling);

    static bool isOverruling(void);

    static bool hasOverrule(const ZcRxObject* pSubject, ZcRxClass* pOverruleClass);
};

class ZCBASE_PORT ZcRxQueryXOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxQueryXOverrule);

    ZcRxQueryXOverrule();

    virtual ZcRxObject* queryX(const ZcRxObject* pSubject, const ZcRxClass* protocolClass) const;
};
#pragma warning( pop )

#pragma pack (pop)
#endif
