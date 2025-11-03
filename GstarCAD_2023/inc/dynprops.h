/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _DYNPROPS_H
#define _DYNPROPS_H
#include "gsoft.h"
#include "GdGChar.h"
#include "gcdbport.h"
#include "dynprops-GcFilterablePropertyContext.h"

#ifdef GCAX_EXPORTS
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

#ifdef _GSOFT_WINDOWS_
#define S_NOTIFYCMD MAKE_HRESULT(0,0,0x02)

interface IPropertyManager;
interface IDynamicProperty;
interface IPropertyManager2;
interface IDynamicProperty2;
interface IPropertySource;
class OPMPerInstancePropertySources : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(OPMPerInstancePropertySources, DLLAPI);
  ~OPMPerInstancePropertySources() {}

  virtual bool SetPropertySourceAt(const BSTR* pName, IPropertySource* pSource) = 0;
  virtual IPropertySource* GetPropertySourceAt(const BSTR* pName) = 0;
  virtual bool RemovePropertySourceAt(const BSTR* pName) = 0;
  virtual bool GetPropertySourceNames(VARIANT* pNames) = 0;
};

class OPMPerInstancePropertyExtension : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(OPMPerInstancePropertyExtension, DLLAPI);
  ~OPMPerInstancePropertyExtension() {};
  virtual bool AddObjectPropertySourceName(const BSTR* pName) = 0;
  virtual bool RemoveObjectPropertySourceName(const BSTR* pName) = 0;
  virtual bool GetObjectPropertySourceNames(VARIANT* pNames) = 0;
};

class OPMPerInstancePropertyExtensionFactory : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(OPMPerInstancePropertyExtensionFactory, DLLAPI);
  ~OPMPerInstancePropertyExtensionFactory() {};
  virtual OPMPerInstancePropertyExtension* CreateOPMPerInstancePropertyExtension(GcRxClass* pClass) = 0;
};

#define GET_OPM_PERINSTANCE_CREATE_PROTOCOL() \
OPMPerInstancePropertyExtensionFactory::cast(GcDbDatabase::desc()->queryX(OPMPerInstancePropertyExtensionFactory::desc()))

#define GET_OPM_PERINSTANCE_PROPERTY_SOURCES() \
OPMPerInstancePropertySources::cast(GcDbDatabase::desc()->queryX(OPMPerInstancePropertySources::desc()))

#define GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(pGcRxClass) \
GET_OPM_PERINSTANCE_CREATE_PROTOCOL()->CreateOPMPerInstancePropertyExtension(pGcRxClass)

class OPMPropertyExtension : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(OPMPropertyExtension, DLLAPI);
  ~OPMPropertyExtension() {}
  virtual IPropertyManager* GetPropertyManager() = 0;
  virtual void SetPropertyManager(IPropertyManager* pPropManager) = 0;
};

class OPMPropertyExtensionFactory : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(OPMPropertyExtensionFactory, DLLAPI);
  ~OPMPropertyExtensionFactory() {}

  virtual OPMPropertyExtension* CreateOPMObjectProtocol(GcRxClass* pClass,
                                                        LONG lReserved = 0) = 0;
  virtual OPMPropertyExtension* CreateOPMCommandProtocol(const GCHAR * pGlobalCommand,
                                                         LONG lReserved = 0) = 0;

  virtual BOOL GetOPMManager(const GCHAR * pGlobalCommand, IPropertyManager** pManager) = 0;
  virtual BOOL GetPropertyCount(GcRxClass* pClass, LONG* pPropCount) = 0;
  virtual LONG GetPropertyClassArray(GcRxClass* pClass,
                                     IDynamicProperty**  pPropertyArray) = 0;
  virtual BOOL GetPropertyCountEx(GcRxClass* pClass, LONG* pPropCount) = 0;
  virtual LONG GetPropertyClassArray(GcRxClass* pClass,
                                     IUnknown**  pPropertyArray) = 0;
};

#define GET_OPMEXTENSION_CREATE_PROTOCOL() \
OPMPropertyExtensionFactory::cast(GcDbDatabase::desc()->queryX(OPMPropertyExtensionFactory::desc()))

#define GET_OPMPROPERTY_MANAGER(pGcRxClass) \
GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(pGcRxClass)->GetPropertyManager() 

#define GET_OPM_COMMAND_PROPERTY_MANAGER(pCommandName) \
GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(pCommandName)->GetPropertyManager() 

typedef BOOL(*OPMDIALOGPROC)(void);

const int MAX_OPMSTRLEN = 256;

DEFINE_GUID(IID_IDynamicPropertyNotify, 0x8B384028, 0xACA8, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACA8-11d1-A2B4-080009DC639A")
  IDynamicPropertyNotify : public IUnknown
{
  BEGIN_INTERFACE
  
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(OnChanged)(THIS_ IDynamicProperty* pDynamicProperty) PURE;
  STDMETHOD(GetCurrentSelectionSet)(THIS_ VARIANT* pSelection) PURE;
};

typedef IDynamicPropertyNotify FAR* LPDYNAMICPROPERTYNOTIFY;

DEFINE_GUID(IID_IDynamicPropertyNotify2, 0x975112b5, 0x5403, 0x4197, 0xaf, 0xb8, 0x90, 0xc6, 0xca, 0x73, 0xb9, 0xe1);

interface DECLSPEC_UUID("975112B5-5403-4197-AFB8-90C6CA73B9E1")
  IDynamicPropertyNotify2 : public IUnknown
{
  BEGIN_INTERFACE

  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(OnChanged)(THIS_ IUnknown* pDynamicProperty) PURE;
  STDMETHOD(GetCurrentSelectionSet)(THIS_ VARIANT* pSelection) PURE;
};

typedef IDynamicPropertyNotify2 FAR* LPDYNAMICPROPERTYNOTIFY2;

DEFINE_GUID(IID_IDynamicProperty, 0x8B384028, 0xACA9, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACA9-11d1-A2B4-080009DC639A")
  IDynamicProperty : public IUnknown
{
  BEGIN_INTERFACE

  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetGUID)(THIS_ GUID* propGUID) PURE;
  STDMETHOD(GetDisplayName)(THIS_ BSTR* bstrName) PURE;
  STDMETHOD(IsPropertyEnabled)(THIS_ LONG_PTR objectID,
                               BOOL* pbEnabled) PURE;
  STDMETHOD(IsPropertyReadOnly)(THIS_ BOOL* pbReadonly) PURE;
  STDMETHOD(GetDescription)(THIS_ BSTR* bstrName) PURE;

  STDMETHOD(GetCurrentValueName)(THIS_ BSTR* pbstrName) PURE;
  STDMETHOD(GetCurrentValueType)(THIS_ VARTYPE* pVarType) PURE;
  STDMETHOD(GetCurrentValueData)(THIS_ LONG_PTR objectID,
                                 VARIANT* pvarData) PURE;
  STDMETHOD(SetCurrentValueData)(THIS_ LONG_PTR objectID,
                                 const VARIANT varData) PURE;

  STDMETHOD(Connect)(THIS_ IDynamicPropertyNotify* pSink) PURE;
  STDMETHOD(Disconnect)(THIS_) PURE;
};

typedef IDynamicProperty FAR* LPDYNAMICPROPERTY;

DEFINE_GUID(IID_IDynamicProperty2, 0x9caf41c2, 0xca86, 0x4ffb, 0xb0, 0x5a, 0xac, 0x43, 0xc4, 0x24, 0xd0, 0x76);

interface DECLSPEC_UUID("9CAF41C2-CA86-4ffb-B05A-AC43C424D076")
  IDynamicProperty2 : public IUnknown
{
  BEGIN_INTERFACE

  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetGUID)(THIS_ GUID* propGUID) PURE;
  STDMETHOD(GetDisplayName)(THIS_ BSTR* bstrName) PURE;
  STDMETHOD(IsPropertyEnabled)(THIS_ IUnknown *pUnk,
                               BOOL* pbEnabled) PURE;
  STDMETHOD(IsPropertyReadOnly)(THIS_ BOOL* pbReadonly) PURE;
  STDMETHOD(GetDescription)(THIS_ BSTR* bstrName) PURE;

  STDMETHOD(GetCurrentValueName)(THIS_ BSTR* pbstrName) PURE;
  STDMETHOD(GetCurrentValueType)(THIS_ VARTYPE* pVarType) PURE;
  STDMETHOD(GetCurrentValueData)(THIS_ IUnknown *pUnk,
                                 VARIANT* pvarData) PURE;
  STDMETHOD(SetCurrentValueData)(THIS_ IUnknown *pUnk,
                                 const VARIANT varData) PURE;

  STDMETHOD(Connect)(THIS_ IDynamicPropertyNotify2* pSink) PURE;
  STDMETHOD(Disconnect)(THIS_) PURE;
};

typedef IDynamicProperty2 FAR* LPDYNAMICPROPERTY2;

const int DISPID_DYNAMIC = -23;

DEFINE_GUID(IID_IDynamicEnumProperty, 0x8B384028, 0xACB1, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACB1-11d1-A2B4-080009DC639A")
  IDynamicEnumProperty : public IUnknown
{
  BEGIN_INTERFACE

  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetNumPropertyValues)(THIS_ LONG* numValues) PURE;
  STDMETHOD(GetPropValueName)(THIS_ LONG index,
                              BSTR* valueName) PURE;
  STDMETHOD(GetPropValueData)(THIS_ LONG index,
                              VARIANT* valueName) PURE;
};

typedef IDynamicEnumProperty FAR* LPDYNAMICENUMPROPERTY;

DEFINE_GUID(IID_IDynamicDialogProperty, 0x8B384028, 0xACB2, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACB2-11d1-A2B4-080009DC639A")
  IDynamicDialogProperty : public IUnknown
{
  BEGIN_INTERFACE

  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetCustomDialogProc)(THIS_ OPMDIALOGPROC* pDialogProc) PURE;
  STDMETHOD(GetMacroName)(THIS_ BSTR* bstrName) PURE;
};

typedef IDynamicDialogProperty FAR* LPDYNAMICDIALOGPROPERTY;

DEFINE_GUID(IID_IPropertyManager, 0x8B384028, 0xACA9, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("8B384028-ACA9-11d1-A2B4-080009DC639A")
  IPropertyManager : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(AddProperty)(THIS_ IDynamicProperty FAR* pProperty) PURE;
  STDMETHOD(RemoveProperty)(THIS_ IDynamicProperty FAR* pProperty) PURE;
  STDMETHOD(GetDynamicProperty)(THIS_ LONG index,
                                IDynamicProperty ** pProperty) PURE;
  STDMETHOD(GetDynamicPropertyByName)(THIS_ BSTR propName,
                                      IDynamicProperty ** pProperty) PURE;
  STDMETHOD(GetDynamicPropertyCount)(THIS_ LONG* count) PURE;
  STDMETHOD(GetDynamicClassInfo)(THIS_ IUnknown* pObj,
                                 ITypeInfo** pptiDynamic,
                                 DWORD* dwCookie) PURE;
};

typedef IPropertyManager FAR* LPPROPERTYMANAGER;

DEFINE_GUID(IID_IPropertyManager2, 0xfabc1c70, 0x1044, 0x4aa0, 0xbf, 0x8d, 0x91, 0xff, 0xf9, 0x5, 0x27, 0x15);

interface DECLSPEC_UUID("FABC1C70-1044-4aa0-BF8D-91FFF9052715")
  IPropertyManager2 : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(AddProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
  STDMETHOD(RemoveProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
  STDMETHOD(GetDynamicProperty)(THIS_ LONG index,
                                IUnknown ** pDynPropObj) PURE;
  STDMETHOD(GetDynamicPropertyByName)(THIS_ BSTR propName,
                                      IUnknown ** pDynPropObj) PURE;
  STDMETHOD(GetDynamicPropertyCountEx)(THIS_ LONG* count) PURE;
  STDMETHOD(GetDynamicClassInfo)(THIS_ IUnknown* pObj,
                                 ITypeInfo** pptiDynamic,
                                 DWORD* dwCookie) PURE;
};

typedef IPropertyManager2 FAR* LPPROPERTYMANAGER2;

DEFINE_GUID(IID_IPropertySource, 0x61d0a8e3, 0xc792, 0x4956, 0x8e, 0x96, 0x59, 0x43, 0x15, 0xb9, 0x59, 0x2);

interface DECLSPEC_UUID("61D0A8E3-C792-4956-8E96-594315B95902")
  IPropertySource : public IUnknown
{
  BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(get_Name)(THIS_ BSTR* pName) PURE;
  STDMETHOD(GetProperties)(THIS_ IUnknown* pObject, VARIANT *pPropertyArray) PURE;
};

typedef IPropertySource FAR* LPPROPERTYSOURCE;

DEFINE_GUID(IID_IFilterableProperty, 0xc93b89f1, 0x794a, 0x458e, 0x8b, 0x49, 0x7c, 0xe8, 0xec, 0x7f, 0x6d, 0xd8);

interface DECLSPEC_UUID("c93b89f1-794a-458e-8b49-7ce8ec7f6dd8")
  IFilterableProperty : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(ShowFilterableProperty)(THIS_ DISPID dispID,
                                    GcFilterablePropertyContext context,
                                    BOOL* pbShow) PURE;
};

typedef IFilterableProperty FAR* LPFILTERABLEPROPERTY;

DEFINE_GUID(IID_IFilterablePropertySource, 0x79bbcf7a, 0x9b42, 0x4c83, 0x80, 0x2f, 0xde, 0xaf, 0xc4, 0x5d, 0x1b, 0x9e);

interface DECLSPEC_UUID("79bbcf7a-9b42-4c83-802f-deafc45d1b9e")
  IFilterablePropertySource : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetFilterableProperties)(THIS_ VARIANT *pPropertyArray) PURE;
};

typedef IFilterablePropertySource FAR* LPFILTERABLEPROPERTYSOURCE;

DEFINE_GUID(IID_IFilterableMultiplePropertySource, 0x59f3c133, 0xc394, 0x4606, 0xb1, 0x7f, 0x79, 0xbe, 0xd2, 0x07, 0x61, 0xcf);

interface DECLSPEC_UUID("59f3c133-c394-4606-b17f-79bed20761cf")
  IFilterableMultiplePropertySource : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetMultipleProperties)(THIS_ VARIANT *pPropertyArray) PURE;
};

typedef IFilterableMultiplePropertySource FAR* LPFILTERABLEMULTIPLEPROPERTYSOURCE;

DEFINE_GUID(IID_IFilterableSubtypePropertySource, 0xa441627c, 0xd20f, 0x429f, 0x82, 0x75, 0x86, 0xb9, 0x54, 0x70, 0x29, 0xf7);

interface DECLSPEC_UUID("a441627c-d20f-429f-8275-86b9547029f7")
  IFilterableSubtypePropertySource : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(GetSubtypes)(THIS_ VARIANT *pSubtypeGUIDsArray) PURE;

  STDMETHOD(GetSubtypeName)(THIS_ BSTR bstrSubtypeGUID,
                            BSTR* bstrSubtypeName) PURE;

  STDMETHOD(GetSubtypeProperties)(THIS_ BSTR bstrSubtypeGUID,
                                  VARIANT *pPropertyArray) PURE;

  STDMETHOD(GetObjectSubtype)(THIS_ IUnknown* pObject,
                              BSTR* bstrSubtypeGUID) PURE;
};

typedef IFilterableSubtypePropertySource FAR* LPFILTERABLESUBTYPEPROPERTYSOURCE;
#endif
#endif 