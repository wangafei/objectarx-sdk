/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _OPMEXT_H
#define _OPMEXT_H
#pragma pack (push, 8)

typedef struct  tagOPMLPOLESTR
{
  ULONG cElems;
  LPOLESTR __RPC_FAR *pElems;
} OPMLPOLESTR;

typedef struct tagOPMLPOLESTR __RPC_FAR *LPOPMLPOLESTR;

typedef struct  tagOPMDWORD
{
  ULONG cElems;
  DWORD __RPC_FAR *pElems;
} OPMDWORD;

typedef struct tagOPMDWORD __RPC_FAR *LPOPMDWORD;

DEFINE_GUID(IID_IOPMPropertyExtension,
  0x1236eaa4, 0x7715, 0x11d1, 0xa2, 0xda, 0x0, 0x60, 0xb0, 0x6b, 0x2d, 0x46);

interface DECLSPEC_UUID("BD2ECD8E-0233-44FF-A410-1B8AD65D3E57") IOPMPropertyExtension : public IUnknown
{
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  virtual HRESULT STDMETHODCALLTYPE GetDisplayName(DISPID dispID, BSTR * propName) = 0;
  virtual HRESULT STDMETHODCALLTYPE Editable(DISPID dispID, BOOL __RPC_FAR *bEditable) = 0;
  virtual HRESULT STDMETHODCALLTYPE ShowProperty(DISPID dispID, BOOL *pShow) = 0;
};

DEFINE_GUID(IID_IOPMPropertyExpander,
  0x5d535710, 0xd49a, 0x11d1, 0xb6, 0x16, 0x0, 0x60, 0xb0, 0x87, 0xe2, 0x35);

interface DECLSPEC_UUID("4BD84EC4-00CA-4F3C-B0F5-D206C02AB936") IOPMPropertyExpander : public IUnknown
{
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  virtual HRESULT STDMETHODCALLTYPE GetElementValue(DISPID dispID, DWORD dwCookie, VARIANT * pVarOut) = 0;
  virtual HRESULT STDMETHODCALLTYPE SetElementValue(DISPID dispID, DWORD dwCookie, VARIANT VarIn) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetElementStrings(DISPID dispID, OPMLPOLESTR __RPC_FAR *pCaStringsOut, OPMDWORD __RPC_FAR *pCaCookiesOut) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(DISPID dispID, short *groupingNumber) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetGroupCount(DISPID dispID, long *nGroupCnt) = 0;
};

DEFINE_GUID(IID_IOPMPropertyExpander2,
  0xd0f45feb, 0x71d5, 0x44ea, 0xb1, 0xa0, 0x6e, 0x2f, 0x27, 0xb2, 0x8, 0x5d);
interface DECLSPEC_UUID("84931618-7E1A-47DE-ADB2-D5603731C74E") IOPMPropertyExpander2 : public IUnknown
{
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  virtual HRESULT STDMETHODCALLTYPE GetElementValue(DISPID dispID, IUnknown * pUnk, DWORD dwCookie, VARIANT * pVarOut) = 0;
  virtual HRESULT STDMETHODCALLTYPE SetElementValue(DISPID dispID, IUnknown * pUnk, DWORD dwCookie, VARIANT VarIn) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetElementStrings(DISPID dispID, IUnknown * pUnk, OPMLPOLESTR __RPC_FAR *pCaStringsOut, OPMDWORD __RPC_FAR *pCaCookiesOut) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(DISPID dispID, IUnknown * pUnk, short *groupingNumber) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetGroupCount(DISPID dispID, IUnknown * pUnk, long *nGroupCnt) = 0;
};

DEFINE_GUID(IID_IOPMPropertyExpanderExpression,
  0x4197114d, 0x3cc4, 0x413b, 0x8a, 0xa3, 0x7c, 0x7a, 0x5, 0xb6, 0x2d, 0x3f);

interface DECLSPEC_UUID("C53A9535-EF52-458A-AD9E-5622CA0C1DED") IOPMPropertyExpanderExpression : public IUnknown
{
  STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG, AddRef)(THIS) PURE;
  STDMETHOD_(ULONG, Release)(THIS) PURE;

  virtual HRESULT STDMETHODCALLTYPE ExpressionAllowed(DISPID dispID, IUnknown * pUnk, DWORD dwCookie, BOOL* pAllowed) = 0;
  virtual HRESULT STDMETHODCALLTYPE put_Expression(DISPID dispID, IUnknown * pUnk, DWORD dwCookie, BSTR expression) = 0;
  virtual HRESULT STDMETHODCALLTYPE get_Expression(DISPID dispID, IUnknown * pUnk, DWORD dwCookie, BSTR* expression) = 0;
};

#pragma pack (pop)
#endif
