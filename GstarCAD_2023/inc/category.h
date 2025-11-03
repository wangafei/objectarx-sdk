/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef OPM_CATEGORY_H
#define OPM_CATEGORY_H

#pragma once
#include "category-properties.h"

#ifdef _GSOFT_WINDOWS_
DEFINE_GUID(IID_ICategorizeProperties, 0x4d07fc10, 0xf931, 0x11ce, 0xb0, 0x1, 0x0, 0xaa, 0x0, 0x68, 0x84, 0xe5);

typedef int PROPCAT;

#undef  INTERFACE
#define INTERFACE  ICategorizeProperties
interface DECLSPEC_UUID("D7D55C01-92C4-4F45-BD27-29735AD70B00") ICategorizeProperties : public IUnknown
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
#endif