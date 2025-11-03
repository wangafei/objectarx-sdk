/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _OPMDRVR_H
#define _OPMDRVR_H

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
#define AXAUTOEXP __declspec(dllexport)
#else
#define AXAUTOEXP __declspec(dllimport)
#endif
#endif

HRESULT AXAUTOEXP GcOpmMapPropertyToCategory(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispid, PROPCAT* ppropcat);
HRESULT AXAUTOEXP GcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, PROPCAT propcat, LCID lcid, BSTR* pbstrName);

HRESULT AXAUTOEXP GcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrName);
HRESULT AXAUTOEXP GcOpmGetCategoryCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CATCMDBTN_VECTOR & arr, PROPCAT propcat, VARIANT *pCatCmdBtns);
HRESULT AXAUTOEXP GcOpmGetParentCategory(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, PROPCAT *pParentCatID);
HRESULT AXAUTOEXP GcOpmGetCategoryWeight(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, long *pCategoryWeight);
HRESULT AXAUTOEXP GcOpmGetCategoryDescription(IUnknown *pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrDesc);

HRESULT AXAUTOEXP GcOpmGetDisplayString(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT AXAUTOEXP GcOpmMapPropertyToPage(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CLSID *pClsid);
HRESULT AXAUTOEXP GcOpmGetPredefinedStrings(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut);
HRESULT AXAUTOEXP GcOpmGetPredefinedValue(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, DWORD dwCookie, VARIANT *pVarOut);

HRESULT AXAUTOEXP GcOpmGetDisplayName(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT AXAUTOEXP GcOpmEditable(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL __RPC_FAR *bEditable);
HRESULT AXAUTOEXP GcOpmShowProperty(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL *pShow);

HRESULT AXAUTOEXP GcOpmGetPropertyWeight(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, long *pPropertyWeight);
HRESULT AXAUTOEXP GcOpmIsPropFullView(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight);
HRESULT AXAUTOEXP GcOpmGetPropTextColor(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, OLE_COLOR *pTextColor);
HRESULT AXAUTOEXP GcOpmGetPropertyIcon(IUnknown *pUnk, HINSTANCE hResInstance, PROP_DISP_VECTOR & arr, VARIANT Id, IUnknown **ppIcon);
HRESULT AXAUTOEXP GcOpmGetCustomPropertyCtrl(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, LCID lcid, BSTR *psProdId);

HRESULT AXAUTOEXP GcOpmGetCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CMDBTN_VECTOR & arr, VARIANT *pCmdBtns);

#endif
