
#ifndef __ZOPMTEMPL_H_
#define __ZOPMTEMPL_H_

#include "zAdAChar.h"

#define ELEMENTGET 0
#define ELEMENTSET 1
#define ELEMENTCOUNT -1

template<class T>
class ATL_NO_VTABLE IOPMPropertyExpanderImpl :
    public IOPMPropertyExpander
{
public:

    IOPMPropertyExpanderImpl()
    {
    }

    virtual ~IOPMPropertyExpanderImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;
    virtual int SetGetElementValue(int GetOrSet, DISPID dispid, DWORD cookie, VARIANT *val, ZcDbObject *pObj) = 0;


	STDMETHODIMP GetElementValue(
		 DISPID dispID,
		 DWORD dwCookie,
		 VARIANT * pVarOut)
    {
        CComPtr<IZcadBaseObject> pZcadBaseObject; 
        HRESULT hr = QueryInterface(IID_IZcadBaseObject, (LPVOID*) &pZcadBaseObject);
        if(FAILED(hr))
            return RAISEEXCEPTION1(IZcadObject, QueryInterfaceFail,
                                   _ZCRX_T("IID_IZcadBaseObject"));
            
        ZcDbObjectId objId;
        pZcadBaseObject->GetObjectId(&objId);
     
        hr = VariantClear(pVarOut);
        if (FAILED(hr)) 
            return hr;

        Zcad::ErrorStatus es;
        ZcDbObject* pObj = NULL;

        if ((es = zcdbOpenZcDbObject(pObj, objId, ZcDb::kForRead)) != Zcad::eOk)
            return RAISEARXEXCEPTION(IZcadEntity, es);

        if (SetGetElementValue(ELEMENTGET, dispID, dwCookie, pVarOut, pObj) == FALSE)
        {                                                                 
            pObj->close();
            return E_FAIL;
        }

        pObj->close();
        return S_OK;
    }

	STDMETHODIMP SetElementValue(
		 DISPID dispID,
		 DWORD dwCookie,
		 VARIANT VarIn)
    {
        CComPtr<IZcadBaseObject> pZcadBaseObject; 
        HRESULT hr = QueryInterface(IID_IZcadBaseObject, (LPVOID*) &pZcadBaseObject);
        if(FAILED(hr))
            return RAISEEXCEPTION1(IZcadObject, QueryInterfaceFail,
                                   _ZCRX_T("IID_IZcadBaseObject"));
            
        ZcDbObjectId objId;
        pZcadBaseObject->GetObjectId(&objId);

        ZXEntityDocLock(objId);

        Zcad::ErrorStatus es;
        ZcDbObject* pObj = NULL;
        ZcDbLine* pLine = NULL;

        if (V_VT(&VarIn) != VT_R8 && V_VT(&VarIn) != VT_I4)
            return E_INVALIDARG;

        if ((es = zcdbOpenZcDbObject(pObj, objId, ZcDb::kForWrite)) != Zcad::eOk)
            return RAISEARXEXCEPTION(IZcadEntity, es);

        if (SetGetElementValue(ELEMENTSET, dispID, dwCookie, &VarIn, pObj) == FALSE)
        {
            pObj->close();
            return E_FAIL;
        }

        pObj->close();
        return S_OK;
    }

    STDMETHODIMP GetElementStrings(
         DISPID dispID,
         OPMLPOLESTR  *pCaStringsOut,
         OPMDWORD *pCaCookiesOut)
    {
        CComPtr<IZcadBaseObject> pZcadBaseObject; 
        HRESULT hr = QueryInterface(IID_IZcadBaseObject, (LPVOID*) &pZcadBaseObject);
        if(FAILED(hr))
            return RAISEEXCEPTION1(IZcadObject, QueryInterfaceFail,
                                   _ZCRX_T("IID_IZcadBaseObject"));
            
        ZcDbObjectId objId;
        pZcadBaseObject->GetObjectId(&objId);
        
        ZCAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

        LPOLESTR pNames = NULL;
        int elemCnt = 0;

        for(unsigned int i = 0; pMap[i].pclsidPropPage != NULL; i++)
        {
            if (pMap[i].dispid == dispID)
            {
                if (pMap[i].nElementStrID == 0)
                    return E_UNEXPECTED;

                ZTCHAR strBuf[2048];

                
                int nBytes = LoadString(GetResourceInstance(), pMap[i].nElementStrID, strBuf, sizeof(strBuf)/sizeof(ZTCHAR));
                if(nBytes == 0)
                    return E_UNEXPECTED;

                pNames = T2W(strBuf);
                if (pNames == NULL)
                    return E_FAIL;

                LPOLESTR token = NULL;
                TCHAR *ptrTemp = NULL;
                token = wcstok_s( pNames, OLESTR(";"), &ptrTemp);

                pCaStringsOut->pElems = NULL;
                pCaCookiesOut->pElems = NULL;

                while( token != NULL )
                {
                    elemCnt++;

                    pCaStringsOut->pElems = (LPOLESTR *)CoTaskMemRealloc(pCaStringsOut->pElems, sizeof(LPOLESTR) * elemCnt);
                    pCaCookiesOut->pElems = (DWORD *)CoTaskMemRealloc(pCaCookiesOut->pElems, sizeof(DWORD) * elemCnt);
                    pCaCookiesOut->pElems[elemCnt -1] = elemCnt -1;

                    pCaStringsOut->pElems[elemCnt -1 ] = SysAllocString(token);
                    token = wcstok_s( NULL, OLESTR(";"), &ptrTemp);
                }

                pCaStringsOut->cElems = elemCnt;
                pCaCookiesOut->cElems = elemCnt;

                return NOERROR;
            }
        }
        return E_NOTIMPL;
    }

    STDMETHODIMP GetElementGrouping(
		 DISPID dispID,
		 short *groupingNumber)
    {
        ZCAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

        *groupingNumber = 0;
        for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)
        {
            if (pMap[i].dispid == dispID)
            {
                *groupingNumber = pMap[i].grouping;
                break;
            }
        }

        return NOERROR;
    }

    STDMETHODIMP GetGroupCount(
		 DISPID dispID,
		 long  *nGroupCnt)
    {
        CComPtr<IZcadBaseObject> pZcadBaseObject; 
        HRESULT hr = QueryInterface(IID_IZcadBaseObject, (LPVOID*) &pZcadBaseObject);
        if(FAILED(hr))
            return RAISEEXCEPTION1(IZcadObject, QueryInterfaceFail,
                                   _ZCRX_T("IID_IZcadBaseObject"));
            
        ZcDbObjectId objId;
        pZcadBaseObject->GetObjectId(&objId);
        
        ZCAD_OPMPROPMAP_ENTRY* pMap = T::GetOPMPropertyMap();

        Zcad::ErrorStatus es;

        for(unsigned int i = 0; pMap[i].pclsidPropPage != NULL; i++)
        {
            if (pMap[i].dispid == dispID)
            {
                if (pMap[i].grouping)
                {
                    ZcDbObject* pObj = NULL;
                    VARIANT VarOut;

                    if ((es = zcdbOpenZcDbObject(pObj, objId, ZcDb::kForRead)) != Zcad::eOk)
                        return RAISEARXEXCEPTION(IZcadEntity, es);

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
