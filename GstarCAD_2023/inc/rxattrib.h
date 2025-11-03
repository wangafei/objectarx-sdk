/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcbasedefs.h"
#include "gsoft.h"
#include "gcadstrc.h"
#include "pimplapi.h"
#include "rxvalue.h"
#include "dbid.h"

class GcRxAttributeImp;
class GcRxAttributeCollectionImp;
class GcRxMember;
class GcRxPropertyBase;
class GSOFT_NO_VTABLE GcRxAttribute : public Pimpl::ApiPart<GcRxObject, GcRxAttributeImp>
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxAttribute, GCBASE_PORT);
  GCBASE_PORT ~GcRxAttribute() = 0;
protected:
  GCBASE_PORT GcRxAttribute(GcRxAttributeImp*);
};

class GcRxAttributeCollection : public Pimpl::ApiPart<void, GcRxAttributeCollectionImp>
{
public:
  GCBASE_PORT GcRxAttributeCollection();
  GCBASE_PORT int count() const;

  GCBASE_PORT const GcRxAttribute* getAt(int index) const;
  GCBASE_PORT GcRxAttribute*       getAt(int index);
  GCBASE_PORT const GcRxAttribute* get(const GcRxClass* type) const;
  GCBASE_PORT GcRxAttribute*       get(const GcRxClass* type);
  GCBASE_PORT Gcad::ErrorStatus    add(const GcRxAttribute* attribute);
  GCBASE_PORT Gcad::ErrorStatus    override(const GcRxAttribute* attribute);
  GCBASE_PORT Gcad::ErrorStatus    remove(const GcRxAttribute* attribute);
};

class GSOFT_NO_VTABLE GcRxResourceLoader : public GcRxObject
{
  virtual Gcad::ErrorStatus subLoadString(unsigned int id, unsigned int sourceHint, GcString& result) = 0;
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxResourceLoader, GCBASE_PORT);
  GCBASE_PORT static Gcad::ErrorStatus loadString(const GcRxObject* pClass, unsigned int id, unsigned int sourceHint, GcString& result);
};

class GcRxLocalizedNameAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxLocalizedNameAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxLocalizedNameAttribute(unsigned int id);
  GCBASE_PORT GcRxLocalizedNameAttribute(unsigned int id, unsigned int sourceHint);

  GCBASE_PORT static GcString getLocalizedName(const GcRxObject* pO);
  GCBASE_PORT unsigned int id() const;
  GCBASE_PORT unsigned int sourceHint() const;
};

class GcRxAlternateLocalizedNameAttribute : public GcRxLocalizedNameAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxAlternateLocalizedNameAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxAlternateLocalizedNameAttribute(unsigned int id);
  GCBASE_PORT GcRxAlternateLocalizedNameAttribute(unsigned int id, unsigned int sourceHint);
};

class GcRxUiPlacementAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxUiPlacementAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxUiPlacementAttribute(const GCHAR* category, unsigned int weight);
  GCBASE_PORT static const GCHAR* getCategory(const GcRxObject* member);
  GCBASE_PORT static float getWeight(const GcRxObject* member);
};

class GcRxLMVAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxLMVAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxLMVAttribute();
};

class GcRxDescriptionAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxDescriptionAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxDescriptionAttribute(const GCHAR* desc);
  GCBASE_PORT GcRxDescriptionAttribute(unsigned int id);
  GCBASE_PORT GcRxDescriptionAttribute(unsigned int id, unsigned int sourceHint);

  GCBASE_PORT static GcString getDescription(const GcRxObject* pO);
  GCBASE_PORT unsigned int id() const;
  GCBASE_PORT unsigned int sourceHint() const;
};

typedef const GcRxPropertyBase* (*FindPropertyCallback)(const GcRxObject* pObject, const GCHAR* pszPropName);
typedef bool(*ConvertValueCallback)(const GcRxPropertyBase* pProperty, GcRxValue& value);

class GcRxRefersToAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxRefersToAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxRefersToAttribute(const GCHAR* path);
  GCBASE_PORT const GCHAR* path() const;
  GCBASE_PORT static const GcRxPropertyBase* parseReference(const GCHAR* path, const GcRxObject* pObject, FindPropertyCallback find = NULL, ConvertValueCallback convert = NULL);
};

class GcRxDisplayAsAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxDisplayAsAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxDisplayAsAttribute(const GCHAR* name);
  GCBASE_PORT const GCHAR* path() const;
  GCBASE_PORT static GcString getDisplayValue(const GcRxDisplayAsAttribute* pAttr, const GcDbObjectId& id);
};

class GcRxCOMAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxCOMAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxCOMAttribute(const GCHAR* name);
  GCBASE_PORT const GCHAR* name() const;
};

class GcRxFilePathAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxFilePathAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxFilePathAttribute();
};

class GcRxFlagsAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxFlagsAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxFlagsAttribute();
};

class GcRxUnitTypeAttribute : public GcRxAttribute
{
public:
  enum UnitType
  {
    kUnitless            = 0,
    kDistance            = (0x1 << 0),
    kAngle               = (0x1 << 1),
    kArea                = (0x1 << 2),
    kVolume              = (0x1 << 3),
    kCurrency            = (0x1 << 4),
    kPercentage          = (0x1 << 5),
    kAngleNotTransformed = (0x1 << 16),
  };
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxUnitTypeAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxUnitTypeAttribute(UnitType unitType);

  GCBASE_PORT UnitType unitType() const;
};

class GcRxGenerateDynamicPropertiesAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxGenerateDynamicPropertiesAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxGenerateDynamicPropertiesAttribute();
};

class GcRxUseDialogForReferredCollectionAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxUseDialogForReferredCollectionAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxUseDialogForReferredCollectionAttribute();
};

class GcRxUiCascadingContextMenuAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxUiCascadingContextMenuAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxUiCascadingContextMenuAttribute();
};

class GcRxCumulativeAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxCumulativeAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxCumulativeAttribute(const GCHAR* type);
  GCBASE_PORT const GCHAR* type() const;
};

class GcRxAffinityAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxAffinityAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxAffinityAttribute(const GCHAR* name);
  GCBASE_PORT const GCHAR* name() const;
};

class GcRxTypePromotionAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxTypePromotionAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxTypePromotionAttribute(const GCHAR* properties);
  GCBASE_PORT const GCHAR* properties() const;
};

class GcRxDefaultValueAttribute : public GcRxAttribute
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxDefaultValueAttribute, GCBASE_PORT);
  GCBASE_PORT GcRxDefaultValueAttribute(const GcRxValue& value);
  GCBASE_PORT const GcRxValue& value() const;
};
