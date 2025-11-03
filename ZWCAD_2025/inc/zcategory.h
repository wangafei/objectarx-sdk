#ifndef ZOPM_CATEGORY_H
#define ZOPM_CATEGORY_H

#pragma once
#include "zcategory-properties.h"

#ifdef _ZSOFT_WINDOWS_
DEFINE_GUID(IID_ICategorizeProperties, 0x6dc29a56, 0xf5b9, 0x4ed1, 0xb7, 0xb9, 0xde, 0x76, 0xc2, 0x47, 0x20, 0xfa);
#endif

typedef int PROPCAT;

#undef  INTERFACE
#define INTERFACE  ICategorizeProperties
interface DECLSPEC_UUID("6DC29A56-F5B9-4ED1-B7B9-DE76C24720FA") ICategorizeProperties : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(MapPropertyToCategory)(THIS_ 
                                      DISPID dispid,
                                      PROPCAT* ppropcat) PURE;
    
    STDMETHOD(GetCategoryName)(THIS_
                                PROPCAT propcat, 
                                LCID lcid,
                                BSTR* pbstrName) PURE;
};

typedef ICategorizeProperties FAR* LPCATEGORIZEPROPERTIES;

#endif
