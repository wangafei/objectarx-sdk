
#ifndef ZD_RXOBJECT_H
#define ZD_RXOBJECT_H 1

#include "zacbasedefs.h"
#include "zadesk.h"
#include "zrxdefs.h"
#include "zrxboiler.h"
#include "zacadstrc.h"
#include "zacdbport.h"
#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)

class ZCBASE_PORT ZSOFT_NO_VTABLE ZcRxObject
{
public:
    static const wchar_t* className() { return L"AcRxObject"; }
    virtual ~ZcRxObject();

    static ZcRxClass*         desc();

    static ZcRxObject * cast(const ZcRxObject * inPtr)
    {
        return const_cast<ZcRxObject *>(inPtr);
    }

    inline bool               isKindOf(const ZcRxClass * aClass) const;

    ZcRxObject*               queryX(const ZcRxClass* protocolClass) const;

    ZcRxObject*               x(const ZcRxClass* protocolClass) const;

    virtual ZcRxClass*        isA() const;

    virtual ZcRxObject*       clone() const;

    template<typename CloneType> Zcad::ErrorStatus cloneEx(CloneType * & pClone) const
    {
        pClone = nullptr;
        Zcad::ErrorStatus es = Zcad::eCopyFailed;
        ZcRxObject *pRxObj = this->clone();
        if (pRxObj != nullptr) {
            pClone = CloneType::cast(pRxObj);
            if (pClone != nullptr)
                es = Zcad::eOk;
            else {
                es = Zcad::eWrongObjectType;
                delete pRxObj;
            }
        }
        return es;
    }

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

    virtual bool    		  isEqualTo(const ZcRxObject * other) const;  
    virtual ZcRx::Ordering    comparedTo(const ZcRxObject * other) const;

protected:

    friend class                          ZcRxQueryXOverrule;
    virtual ZcRxObject*       subQueryX(const ZcRxClass* protocolClass) const;

    ZcRxObject();
};

inline ZcRxObject::~ZcRxObject()
{
}

#pragma pack (pop)

#include "zrxclass.h"

#define ZCRX_PE_PTR(RxObj,PEClass) PEClass::cast(RxObj-> \
                                            queryX(PEClass::desc()))

#define ZCRX_X_CALL(RxObj,PEClass) PEClass::cast(RxObj->x(PEClass::desc()))

#include "zrxdict.h"

#endif

