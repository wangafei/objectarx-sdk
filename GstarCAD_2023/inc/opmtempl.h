/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __OPMTEMPL_H_
#define __OPMTEMPL_H_

#include "GdGChar.h"

#define ELEMENTGET 0
#define ELEMENTSET 1
#define ELEMENTCOUNT -1

template<class T>
class ATL_NO_VTABLE IOPMPropertyExpanderImpl : public IOPMPropertyExpander
{
public:
  IOPMPropertyExpanderImpl()
  {
  }
  virtual ~IOPMPropertyExpanderImpl()
  {
  }

  virtual HINSTANCE GetResourceInstance() = 0;
  virtual int SetGetElementValue(int GetOrSet, DISPID dispid, DWORD cookie, VARIANT *val, GcDbObject *pObj) = 0;

  STDMETHODIMP GetElementValue(DISPID dispID, DWORD dwCookie, VARIANT * pVarOut)
  {
    CComPtr<IGcadBaseObject> pGcadBaseObject;
    HRESULT hr = QueryInterface(IID_IGcadBaseObject, (LPVOID*)&pGcadBaseObject);
    if (FAILED(hr))
      return RAISEEXCEPTION1(IGcadObject, QueryInterfaceFail,
        _GCRX_T("IID_IGcadBaseObject"));

    GcDbObjectId objId;
    pGcadBaseObject->GetObjectId(&objId);

    hr = VariantClear(pVarOut);
    if (FAILED(hr))
      return hr;

    Gcad::ErrorStatus es;
    GcDbObject* pObj = NULL;

    if ((es = gcdbOpenGcDbObject(pObj, objId, GcDb::kForRead)) != Gcad::eOk)
      return RAISEGRXEXCEPTION(IGcadEntity, es);

    if (SetGetElementValue(ELEMENTGET, dispID, dwCookie, pVarOut, pObj) == FALSE)
    {
      pObj->close();
      return E_FAIL;
    }

    pObj->close();
    return S_OK;
  }
  STDMETHODIMP SetElementValue(DISPID dispID, DWORD dwCookie, VARIANT VarIn)
  {
    CComPtr<IGcadBaseObject> pGcadBaseObject;
    HRESULT hr = QueryInterface(IID_IGcadBaseObject, (LPVOID*)&pGcadBaseObject);
    if (FAILED(hr))
      return RAISEEXCEPTION1(IGcadObject, QueryInterfaceFail,
        _GCRX_T("IID_IGcadBaseObject"));

    GcDbObjectId objId;
    pGcadBaseObject->GetObjectId(&objId);

    AXEntityDocLock(objId);

    Gcad::ErrorStatus es;
    GcDbObject* pObj = NULL;
    GcDbLine* pLine = NULL;

    if (V_VT(&VarIn) != VT_R8 && V_VT(&VarIn) != VT_I4)
      return E_INVALIDARG;

    if ((es = gcdbOpenGcDbObject(pObj, objId, GcDb::kForWrite)) != Gcad::eOk)
      return RAISEGRXEXCEPTION(IGcadEntity, es);

    if (SetGetElementValue(ELEMENTSET, dispID, dwCookie, &VarIn, pObj) == FALSE)
    {
      pObj->close();
      return E_FAIL;
    }

    pObj->close();
    return S_OK;
  }

  STDMETHODIMP GetElementStrings(DISPID dispID, OPMLPOLESTR *pCaStringsOut, OPMDWORD *pCaCookiesOut)
  {
    CComPtr<IGcadBaseObject> pGcadBaseObject;
    HRESULT hr = QueryInterface(IID_IGcadBaseObject, (LPVOID*)&pGcadBaseObject);
    if (FAILED(hr))
      return RAISEEXCEPTION1(IGcadObject, QueryInterfaceFail,
        _GCRX_T("IID_IGcadBaseObject"));

    GcDbObjectId objId;
    pGcadBaseObject->GetObjectId(&objId);

    GCAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

    LPOLESTR pNames = NULL;
    int elemCnt = 0;

    for (unsigned int i = 0; pMap[i].pclsidPropPage != NULL; i++)
    {
      if (pMap[i].dispid == dispID)
      {
        if (pMap[i].nElementStrID == 0)
          return E_UNEXPECTED;

        GCHAR strBuf[2048];

        int nBytes = LoadString(GetResourceInstance(), pMap[i].nElementStrID, strBuf, sizeof(strBuf) / sizeof(GCHAR));
        if (nBytes == 0)
          return E_UNEXPECTED;

        USES_CONVERSION;
        pNames = T2W(strBuf);
        if (pNames == NULL)
          return E_FAIL;

        LPOLESTR token = NULL;
        TCHAR *ptrTemp = NULL;
        token = wcstok_s(pNames, OLESTR(";"), &ptrTemp);

        pCaStringsOut->pElems = NULL;
        pCaCookiesOut->pElems = NULL;

        while (token != NULL)
        {
          elemCnt++;

          pCaStringsOut->pElems = (LPOLESTR *)CoTaskMemRealloc(pCaStringsOut->pElems, sizeof(LPOLESTR) * elemCnt);
          pCaCookiesOut->pElems = (DWORD *)CoTaskMemRealloc(pCaCookiesOut->pElems, sizeof(DWORD) * elemCnt);
          pCaCookiesOut->pElems[elemCnt - 1] = elemCnt - 1;

          pCaStringsOut->pElems[elemCnt - 1] = SysAllocString(token);
          token = wcstok_s(NULL, OLESTR(";"), &ptrTemp);
        }

        pCaStringsOut->cElems = elemCnt;
        pCaCookiesOut->cElems = elemCnt;

        return NOERROR;
      }
    }
    return E_NOTIMPL;
  }

  STDMETHODIMP GetElementGrouping(DISPID dispID, short *groupingNumber)
  {
    GCAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

    *groupingNumber = 0;
    for (int i = 0; pMap[i].pclsidPropPage != NULL; i++)
    {
      if (pMap[i].dispid == dispID)
      {
        *groupingNumber = pMap[i].grouping;
        break;
      }
    }
    return NOERROR;
  }

  STDMETHODIMP GetGroupCount(DISPID dispID, long *nGroupCnt)
  {
    CComPtr<IGcadBaseObject> pGcadBaseObject;
    HRESULT hr = QueryInterface(IID_IGcadBaseObject, (LPVOID*)&pGcadBaseObject);
    if (FAILED(hr))
      return RAISEEXCEPTION1(IGcadObject, QueryInterfaceFail,
        _GCRX_T("IID_IGcadBaseObject"));

    GcDbObjectId objId;
    pGcadBaseObject->GetObjectId(&objId);

    GCAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

    Gcad::ErrorStatus es;
    for (unsigned int i = 0; pMap[i].pclsidPropPage != NULL; i++)
    {
      if (pMap[i].dispid == dispID)
      {
        if (pMap[i].grouping)
        {
          GcDbObject* pObj = NULL;
          VARIANT VarOut;

          if ((es = gcdbOpenGcDbObject(pObj, objId, GcDb::kForRead)) != Gcad::eOk)
            return RAISEGRXEXCEPTION(IGcadEntity, es);

          if (SetGetElementValue(ELEMENTCOUNT, dispID, 0, &VarOut, pObj) == FALSE)
          {
            pObj->close();
            return E_FAIL;
          }
          else
            *nGroupCnt = V_I4(&VarOut);

          pObj->close();

          return NOERROR;
        }
      }
    }
    return E_NOTIMPL;
  }
};

#endif
