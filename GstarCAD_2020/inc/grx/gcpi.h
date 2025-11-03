#pragma once

#include "rpc.h"
#include "rpcndr.h"

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

DEFINE_GUID(IID_IGcPiCategorizeProperties, 
    0xDA4337F2, 0x2DEF, 0x489D, 0xBF, 0xF4, 0x01, 0xAF, 0x83, 0xA1, 0xEB, 0x3B);

interface DECLSPEC_UUID("DA4337F2-2DEF-489D-BFF4-01AF83A1EB3B") 
IGcPiCategorizeProperties: public IUnknown
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS_) PURE;
    STDMETHOD_(ULONG, Release)(THIS_) PURE;

    /* IGcPiCategorizeProperties methods */
    STDMETHOD(MapPropertyToCategory)(THIS_ DISPID dispID, int *pCatID) PURE;
    STDMETHOD(GetCategoryName)(THIS_ int CatID, LCID lCid, BSTR *pCategoryName) PURE;
    STDMETHOD(GetCategoryDescription)(THIS_ int CatID, LCID lCid, BSTR *pCategoryDescription) PURE;
    STDMETHOD(GetCategoryWeight)(THIS_ int CatID, long *pCategoryWeight) PURE;
    STDMETHOD(GetParentCategory)(THIS_ int CatID, int *pParentCatID) PURE;
    STDMETHOD(GetUniqueID)(THIS_ BSTR *pVal) PURE;
    STDMETHOD(GetCommandButtons)(THIS_ int CatID, VARIANT *pCatCmdBtns) PURE;
};

DEFINE_GUID(IID_IGcPiPropertyDisplay, 
    0x13CC000C, 0x2E5E, 0x4F27, 0x88, 0xF2, 0x80, 0xA9, 0x61, 0x7C, 0xD7, 0x37);
interface DECLSPEC_UUID("13CC000C-2E5E-4F27-88F2-80A9617CD737") 
IGcPiPropertyDisplay: public IUnknown
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS_) PURE;
    STDMETHOD_(ULONG, Release)(THIS_) PURE;

    /* IGcPiPropertyDisplay methods */
    STDMETHOD(GetCustomPropertyCtrl)(THIS_ VARIANT Id, LCID lcid, BSTR *pProgId) PURE;
    STDMETHOD(GetPropertyIcon)(THIS_ VARIANT Id, IUnknown **pIcon) PURE;
    STDMETHOD(GetPropTextColor)(THIS_ VARIANT Id, OLE_COLOR *pTextColor) PURE;
    STDMETHOD(IsFullView)(THIS_ VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight) PURE;
    STDMETHOD(GetPropertyWeight)(THIS_ VARIANT Id, long *pPropertyWeight) PURE;
};

