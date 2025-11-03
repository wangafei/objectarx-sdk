#pragma once

#include "grxdefs.h"
#include "gchar.h"
#include "hccad.h"

#ifdef GCAX_EXPORTS
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif

DEFINE_GUID(IID_IGcadBaseObject, 
  0x5f3c54c0, 0x49e1, 0x11cf, 0x93, 0xd5, 0x8, 0x0, 0x9, 0x9e, 0xb3, 0xb7);

/* Definition of interface: IGcadBaseObject */
#undef INTERFACE
#define INTERFACE IGcadBaseObject

interface DECLSPEC_UUID("5F3C54C0-49E1-11cf-93D5-0800099EB3B7") 
IGcadBaseObject : public IUnknown
{
  /* IUnknown methods */
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  /* IGcadBaseObject methods */
  STDMETHOD(SetObjectId)(THIS_ GcDbObjectId& objId, 
    GcDbObjectId ownerId = GcDbObjectId::kNull, 
    GCHAR* keyName = NULL) PURE;
  STDMETHOD(GetObjectId)(THIS_ GcDbObjectId* objId) PURE;
  STDMETHOD(Clone)(THIS_ GcDbObjectId ownerId, LPUNKNOWN* pUnkClone) PURE;
  STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
  STDMETHOD(NullObjectId)(THIS) PURE;
  STDMETHOD(OnModified)(THIS) PURE;
};

typedef IGcadBaseObject* LPGCADBASEOBJECT;

// {ADAAAEC4-C7FE-11d5-8D60-0010830243CE}
DEFINE_GUID(IID_IGcadBaseObject2,
  0xadaaaec4, 0xc7fe, 0x11d5, 0x8d, 0x60, 0x0, 0x10, 0x83, 0x2, 0x43, 0xce);

/* Definition of interface: IGcadBaseObject2 */

interface DECLSPEC_UUID("ADAAAEC4-C7FE-11d5-8D60-0010830243CE") 
IGcadBaseObject2 : public IUnknown       
{
  /* IUnknown methods */
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  /* IGcadBaseObject2 methods */
  STDMETHOD(ForceDbResident)(THIS_ VARIANT_BOOL* forceDbResident) PURE;
  STDMETHOD(AddToDb)(THIS_ GcDbObjectId& objId, 
    GcDbObjectId ownerId = GcDbObjectId::kNull,
    GCHAR* keyName = NULL) PURE;
  STDMETHOD(CreateObject)(THIS_ GcDbObjectId ownerId = GcDbObjectId::kNull,
    GCHAR* keyName = NULL) PURE;
  STDMETHOD(ObjectExists)(THIS_ VARIANT_BOOL* objectExists) PURE;
  STDMETHOD(SetObject)(THIS_ GcDbObject*& pObj) PURE;
  STDMETHOD(GetObject)(THIS_ GcDbObject*& pObj) PURE;
  STDMETHOD(OnModified)(THIS_ DISPID = DISPID_UNKNOWN) PURE;
};

typedef IGcadBaseObject2* LPGCADBASEOBJECT2;

DEFINE_GUID(IID_IRetrieveApplication, 
  0x765b4640, 0x664a, 0x11cf, 0x93, 0xf3, 0x8, 0x0, 0x9, 0x9e, 0xb3, 0xb7);

/* Definition of interface: IRetrieveApplication */
interface DECLSPEC_UUID("765B4640-664A-11cf-93F3-0800099EB3B7") 
IRetrieveApplication : public IUnknown
{
  /* IUnknown methods */
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  /* IRetrieveApplication methods */
  STDMETHOD(SetApplicationObject)(THIS_ LPDISPATCH pAppDisp) PURE;
  STDMETHOD(GetApplicationObject)(THIS_ LPDISPATCH* pAppDisp) PURE;
};

typedef IRetrieveApplication* LPRETRIEVEAPPLICATION;

DEFINE_GUID(IID_IGcadBaseDatabase, 
  0xcb1488c4, 0x2bec, 0x11d2, 0xb6, 0x7b, 0x0, 0x60, 0xb0, 0x87, 0xe2, 0x35);

/* Definition of interface: IGcadBaseDatabase */
interface DECLSPEC_UUID("CB1488C4-2BEC-11d2-B67B-0060B087E235") 
IGcadBaseDatabase : public IUnknown
{
  /* IUnknown methods */
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  /* IGcadBaseObject methods */
  STDMETHOD(SetDatabase)(THIS_ GcDbDatabase*& pDb) PURE;
  STDMETHOD(GetDatabase)(THIS_ GcDbDatabase** pDb) PURE;
  STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
};

typedef IGcadBaseDatabase* LPGCADBASEDATABASE;

#if 0
DEFINE_GUID(IID_IIMetaColorSuppressor, 
  0xbd1c37b2, 0x9020, 0x43ad, 0x99, 0xd4, 0x25, 0x91, 0x6a, 0x4b, 0xfb, 0xc);

/* Definition of interface: IMetaColorSuppressor */
interface DECLSPEC_UUID("BD1C37B2-9020-43ad-99D4-25916A4BFB0C")
IMetaColorSuppressor : public IUnknown
{
  /* IGcadGcCmColorAccess methods */
  STDMETHOD(GetSuppressor)(THIS_ bool* val) PURE;
  STDMETHOD(SetSuppressor)(THIS_ bool val) PURE;
};

typedef IMetaColorSuppressor* LPMETACOLORSUPPRESSOR;

#endif

DEFINE_GUID(IID_IGcadGcCmColorAccess,
  0xf74f68db, 0x8f24, 0x4e74, 0xb1, 0x4d, 0x9b, 0xf4, 0xfe, 0x27, 0x7b, 0xd3);

/* Definition of interface: IAcadAcCmColorRetrieve */
#undef INTERFACE
#define INTERFACE IGcadGcCmColorAccess

interface DECLSPEC_UUID("F74F68DB-8F24-4e74-B14D-9BF4FE277BD3")
IGcadAcCmColorAccess : public IUnknown
{
  /* IGcadAcCmColorAccess methods */
  STDMETHOD(GetAcCmColor)(THIS_ GcCmColor* clr) PURE;
  STDMETHOD(SetAcCmColor)(THIS_ GcCmColor* clr) PURE;
};

typedef IGcadAcCmColorAccess* LPGCADACCMCOLORACCESS;

/* Definition of interface: IGcadBaseSubEntity */
DEFINE_GUID(IID_IGcadBaseSubEntity, 
  0xb374d885, 0xeece, 0x4138, 0x8c, 0x82, 0x3f, 0xb2, 0xc, 0x53, 0x87, 0x88);

#undef INTERFACE
#define INTERFACE IGcadBaseSubEntity

interface DECLSPEC_UUID("B374D885-EECE-4138-8C82-3FB20C538788") 
IGcadBaseSubEntity : public IUnknown
{
  /* IUnknown methods */
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  /* IGcadBaseSubEntity methods */
  STDMETHOD(OnModified)() PURE;
  STDMETHOD(SetFullSubEntPath)(THIS_ GcDbFullSubentPath& subentPath) PURE; 
  STDMETHOD(GetFullSubEntPath)(THIS_ GcDbFullSubentPath* subentPath) PURE;
  STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
};

typedef IGcadBaseSubEntity* LPGCADSUBENTITY;

class GCADAXEXP GcAxOleLinkManager
{
public:
    virtual IDispatch* GetDocIDispatch(GcDbDatabase* pDatabase) = 0;
    virtual IUnknown* GetIUnknown(GcDbDatabase* pDatabase) = 0;
    virtual IUnknown* GetIUnknown(GcDbObject* pObject) = 0;
    virtual IUnknown* GetIUnknown(GcDbObject* pObject, const GcDbSubentId & id) = 0;
    virtual Hccad::Boolean SetDocIDispatch(GcDbDatabase* pDatabase, IDispatch* pDispatch) = 0;
    virtual Hccad::Boolean SetIUnknown(GcDbDatabase* pDatabase, IUnknown* pUnknown) = 0;
    virtual Hccad::Boolean SetIUnknown(GcDbObject* pObject, const GcDbSubentId & id, IUnknown* pUnknown) = 0;
    virtual Hccad::Boolean SetIUnknown(GcDbObject* pObject, IUnknown* pUnknown) = 0;
};

GCADAXEXP GcAxOleLinkManager* GcAxGetOleLinkManager();
GCADAXEXP void GcAxSafeSetIUnknow(const GcDbObjectId&, IUnknown* pUnknown);
