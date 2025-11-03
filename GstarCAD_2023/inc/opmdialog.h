/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _OPMDIALOG_H
#define _OPMDIALOG_H

DEFINE_GUID(IID_IOPMPropertyDialog, 0x8B384029, 0xACB0, 0x11d1, 0xA2, 0xB4, 0x08, 0x00, 0x09, 0xDC, 0x63, 0x9A);

interface DECLSPEC_UUID("98F2DE4F-848F-4CF7-A40C-9BFACE32C6DE") IOPMPropertyDialog : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(DoModal)(THIS_  BSTR* propValueString, GcDbObjectIdArray* ObjectIdArray) PURE;
};

typedef IOPMPropertyDialog FAR* LPPROPERTYDIALOG;

DEFINE_GUID(IID_IOPMPropertyDialog2, 0x9f82f13d, 0xc850, 0x444a, 0x98, 0xc, 0xb5, 0xed, 0xc6, 0x67, 0x9f, 0x4a);

interface DECLSPEC_UUID("0345D2E5-0473-4FB3-80AA-6063F7053C82")  IOPMPropertyDialog2 : public IUnknown
{
  BEGIN_INTERFACE
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  STDMETHOD(DoModal)(THIS_  BSTR* propValueString, VARIANT ObjectUnknownArray) PURE;
};

typedef IOPMPropertyDialog2 FAR* LPPROPERTYDIALOG2;

#endif
