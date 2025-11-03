#include "opmimp.h"
#include "opmext.h"

#ifndef _OPMDRVR_H
#define _OPMDRVR_H

#ifdef GCAX_EXPORTS
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif

// ICategorizeProperties methods
HRESULT GCADAXEXP GcOpmMapPropertyToCategory(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispid, PROPCAT* ppropcat);
HRESULT GCADAXEXP GcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, PROPCAT propcat, LCID lcid, BSTR* pbstrName);

// IAcPiCategorizeProperties methods
HRESULT GCADAXEXP GcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrName);
HRESULT GCADAXEXP GcOpmGetCategoryCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CATCMDBTN_VECTOR & arr, PROPCAT propcat, VARIANT *pCatCmdBtns);
HRESULT GCADAXEXP GcOpmGetParentCategory(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, PROPCAT *pParentCatID);
HRESULT GCADAXEXP GcOpmGetCategoryWeight(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, long *pCategoryWeight);
HRESULT GCADAXEXP GcOpmGetCategoryDescription(IUnknown *pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrDesc);

// IPerPropertyBrowsing methods
HRESULT GCADAXEXP GcOpmGetDisplayString(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT GCADAXEXP GcOpmMapPropertyToPage(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CLSID *pClsid);
HRESULT GCADAXEXP GcOpmGetPredefinedStrings(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut);
HRESULT GCADAXEXP GcOpmGetPredefinedValue(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, DWORD dwCookie, VARIANT *pVarOut);

 // IOPMPropertyExtension methods
HRESULT GCADAXEXP GcOpmGetDisplayName(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT GCADAXEXP GcOpmEditable(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL __RPC_FAR *bEditable);
HRESULT GCADAXEXP GcOpmShowProperty(IUnknown* pUnk, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL *pShow);


// IAcPiPropertyDisplay methods
HRESULT GCADAXEXP GcOpmGetPropertyWeight(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, long *pPropertyWeight);
HRESULT GCADAXEXP GcOpmIsPropFullView(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight);
HRESULT GCADAXEXP GcOpmGetPropTextColor(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, OLE_COLOR *pTextColor);
HRESULT GCADAXEXP GcOpmGetPropertyIcon(IUnknown *pUnk, HINSTANCE hResInstance, PROP_DISP_VECTOR & arr, VARIANT Id, IUnknown **ppIcon);
HRESULT GCADAXEXP GcOpmGetCustomPropertyCtrl(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, LCID lcid, BSTR *psProdId);

// IAcPiPropCommandButtons methods
HRESULT GCADAXEXP GcOpmGetCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CMDBTN_VECTOR & arr, VARIANT *pCmdBtns);

// IOPMPropertyExpander methods
HRESULT GCADAXEXP GcOpmGetElementGrouping(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, short* groupingNumber);
HRESULT GCADAXEXP GcOpmGetElementString(IUnknown* pUnk, HINSTANCE hResInstance, GCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, OPMLPOLESTR __RPC_FAR * pCaStringsOut, OPMDWORD __RPC_FAR * pCaCookiesOut);

// IGcadPropTips
HRESULT GCADAXEXP GcOpmGetToolTip(IUnknown* pUnk, DISPID dispID, BSTR *pBstr);

#define CLSID_PropertyEditorColor CLSID_GcPePropertyEditorColor

#endif // _OPMDRVR_H
