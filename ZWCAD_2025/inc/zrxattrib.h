
#pragma once
#include "zacbasedefs.h"
#include "zadesk.h"
#include "zacadstrc.h"
#include "zpimplapi.h"
#include "zrxvalue.h"


class ZcRxAttributeImp;
class ZcRxAttributeCollectionImp;
class ZcRxMember;
class ZcRxPropertyBase;
class ZcDbObjectId;

class ZSOFT_NO_VTABLE ZcRxAttribute : public Pimpl::ApiPart<ZcRxObject, ZcRxAttributeImp>
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxAttribute, ZCBASE_PORT);

    ZCBASE_PORT virtual ~ZcRxAttribute() = 0;
protected:
    ZCBASE_PORT ZcRxAttribute(ZcRxAttributeImp*);
};

class ZCBASE_PORT ZcRxAttributeCollection : public Pimpl::ApiPart<void, ZcRxAttributeCollectionImp>
{
public:

    ZcRxAttributeCollection();

     int count() const;

     const ZcRxAttribute* getAt(int index) const;
     ZcRxAttribute* getAt(int index);

     const ZcRxAttribute* get(const ZcRxClass* type) const;
     ZcRxAttribute* get(const ZcRxClass* type);

     Zcad::ErrorStatus add(const ZcRxAttribute* attribute);

     Zcad::ErrorStatus override(const ZcRxAttribute* attribute);

     Zcad::ErrorStatus remove(const ZcRxAttribute* attribute);
};

class ZSOFT_NO_VTABLE ZcRxResourceLoader : public ZcRxObject
{

    virtual Zcad::ErrorStatus subLoadString(unsigned int id, unsigned int sourceHint, ZcString& result) = 0;
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxResourceLoader, ZCBASE_PORT);

    ZCBASE_PORT static Zcad::ErrorStatus loadString(const ZcRxObject* pClass,unsigned int id, unsigned int sourceHint, ZcString& result);
};

class ZcRxLocalizedNameAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxLocalizedNameAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxLocalizedNameAttribute(unsigned int id);

    ZCBASE_PORT ZcRxLocalizedNameAttribute(unsigned int id, unsigned int sourceHint);
    ZCBASE_PORT static ZcString getLocalizedName(const ZcRxObject* pO);

    ZCBASE_PORT unsigned int id() const;

    ZCBASE_PORT unsigned int sourceHint() const;

};

class ZcRxAlternateLocalizedNameAttribute : public ZcRxLocalizedNameAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxAlternateLocalizedNameAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxAlternateLocalizedNameAttribute(unsigned int id);

    ZCBASE_PORT ZcRxAlternateLocalizedNameAttribute(unsigned int id, unsigned int sourceHint);
};

class ZcRxUiPlacementAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxUiPlacementAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxUiPlacementAttribute(const ZTCHAR* category, unsigned int weight);

    ZCBASE_PORT static const ZTCHAR* getCategory(const ZcRxObject* member);

    ZCBASE_PORT static float getWeight(const ZcRxObject* member);
};

class ZcRxLMVAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxLMVAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxLMVAttribute();
};

class ZcRxDescriptionAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxDescriptionAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxDescriptionAttribute(const ZTCHAR* desc);

    ZCBASE_PORT ZcRxDescriptionAttribute(unsigned int id);

    ZCBASE_PORT ZcRxDescriptionAttribute(unsigned int id, unsigned int sourceHint);

    ZCBASE_PORT static ZcString getDescription(const ZcRxObject* pO);

    ZCBASE_PORT unsigned int id() const;

    ZCBASE_PORT unsigned int sourceHint() const;
};

typedef const ZcRxPropertyBase* (*FindPropertyCallback)(const ZcRxObject* pObject, const ZTCHAR* pszPropName);
typedef bool (*ConvertValueCallback)(const ZcRxPropertyBase* pProperty, ZcRxValue& value);

class ZcRxRefersToAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxRefersToAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxRefersToAttribute(const ZTCHAR* path);

    ZCBASE_PORT const ZTCHAR* path() const;

    ZCBASE_PORT static const ZcRxPropertyBase* parseReference(const ZTCHAR* path, const ZcRxObject* pObject, FindPropertyCallback find = NULL, ConvertValueCallback convert = NULL);
};

class ZcRxDisplayAsAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxDisplayAsAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxDisplayAsAttribute(const ZTCHAR* name);

    ZCBASE_PORT const ZTCHAR* path() const;

    ZCDBCORE2D_PORT static ZcString getDisplayValue(const ZcRxDisplayAsAttribute* pAttr, const ZcDbObjectId& id);
};

class ZcRxCOMAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxCOMAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxCOMAttribute(const ZTCHAR* name);

    ZCBASE_PORT const ZTCHAR* name() const;
};

class ZcRxFilePathAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxFilePathAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxFilePathAttribute();
};

class ZcRxFlagsAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxFlagsAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxFlagsAttribute();
};

class ZcRxUnitTypeAttribute : public ZcRxAttribute
{
public:
    enum UnitType
    {
        kUnitless           = 0,
        kDistance           = (0x1 << 0),
        kAngle              = (0x1 << 1),
        kArea               = (0x1 << 2),
        kVolume             = (0x1 << 3),
        kCurrency           = (0x1 << 4),
        kPercentage         = (0x1 << 5),
        kAngleNotTransformed = (0x1 << 16),
    };
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxUnitTypeAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxUnitTypeAttribute(UnitType unitType);

    ZCBASE_PORT UnitType unitType() const;
};

class ZcRxGenerateDynamicPropertiesAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxGenerateDynamicPropertiesAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxGenerateDynamicPropertiesAttribute();
};

class ZcRxUseDialogForReferredCollectionAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxUseDialogForReferredCollectionAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxUseDialogForReferredCollectionAttribute();
};

class ZcRxUiCascadingContextMenuAttribute: public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxUiCascadingContextMenuAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxUiCascadingContextMenuAttribute();
};

class ZcRxCumulativeAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxCumulativeAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxCumulativeAttribute(const ZTCHAR* type);

    ZCBASE_PORT const ZTCHAR* type() const;
};

class ZcRxAffinityAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxAffinityAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxAffinityAttribute(const ZTCHAR* name);

    ZCBASE_PORT const ZTCHAR* name() const;
};

class ZcRxTypePromotionAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxTypePromotionAttribute, ZCBASE_PORT);
    ZCBASE_PORT ZcRxTypePromotionAttribute(const ZTCHAR* properties);
    ZCBASE_PORT const ZTCHAR* properties() const;
};

class ZcRxDefaultValueAttribute : public ZcRxAttribute
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxDefaultValueAttribute, ZCBASE_PORT);

    ZCBASE_PORT ZcRxDefaultValueAttribute(const ZcRxValue& value);
    ZCBASE_PORT const ZcRxValue& value() const;
};
