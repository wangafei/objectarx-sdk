
#ifndef __AXTEMPL_H_
#define __AXTEMPL_H_

#include "axobjref.h"
#include "opmext.h"
#include "opmimp.h"
#include <axboiler.h>
#include "oleaprot.h"

#define GCAX_VARIANT_TRUE (VARIANT_BOOL) -1
#define GCAX_VARIANT_FALSE (VARIANT_BOOL) 0

template <class T>
class CProxy_GcadObjectEvents :
    public IConnectionPointImpl<T, &__uuidof(IGcadObjectEvents), CComDynamicUnkArray>
{
public:

    void Fire_Modified()
    {
        T* pT = static_cast<T*>(this);
        CComPtr<IGcadObject> pGcadObject;
        pT->QueryInterface(__uuidof(IGcadObject),(void**)&pGcadObject);
        pT->Lock();
        IUnknown** pp = m_vec.begin();
        while (pp < m_vec.end())
        {
            if (*pp != NULL)
            {
                IGcadObjectEvents* pGcadObjectEvents = reinterpret_cast<IGcadObjectEvents*>(*pp);
                _ASSERTE(pGcadObjectEvents != NULL);

                pGcadObjectEvents->Modified(pGcadObject);
            }
            pp++;
        }
        pT->Unlock();
    }

    STDMETHOD(Advise)(IUnknown* pUnkSink, DWORD* pdwCookie) 
    {
        HRESULT hr = IConnectionPointImpl<T, &__uuidof(IGcadObjectEvents), CComDynamicUnkArray>::Advise(pUnkSink,pdwCookie);
        CComObject<T> *pObj = (CComObject<T> *)(this);
        if(pObj)
        {
            GcDbObjectId objId;
            GcAxObjectRefPtr<GcDbObject> pObjPtr;

            pObj->GetObjectId(&objId);
            if (pObjPtr.open(objId, GcDb::kForRead) == Gcad::eOk ||
                pObjPtr.open(objId, GcDb::kForNotify) == Gcad::eOk)
            {
                IUnknownPtr pUnknown = NULL;
                if (SUCCEEDED(pObj->QueryInterface(IID_IUnknown, (void**)&pUnknown)))
                {
                    GcAxGetOleLinkManager()->SetIUnknown(pObjPtr, pUnknown);
                }
            }
        }
        return hr;
    }

    STDMETHOD(Unadvise)(DWORD dwCookie)
    {
        IConnectionPointImpl<T, &__uuidof(IGcadObjectEvents), CComDynamicUnkArray>::Unadvise(dwCookie);
        return S_OK;
    }
};

template <class T>
class CProxy_PropertyNotifySink :
    public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CComDynamicUnkArray>
{
public:

    void Fire_OnChanged()
    {
        Fire_OnChanged(DISPID_UNKNOWN);
    }

    void Fire_OnChanged(DISPID dispId)
    {
        T* pT = static_cast<T*>(this);
        pT->Lock();
        IUnknown** pp = m_vec.begin();
        while (pp < m_vec.end())
        {
            IPropertyNotifySink* pNotifySink = reinterpret_cast<IPropertyNotifySink*>(*pp);
            if(pNotifySink)
                pNotifySink->OnChanged(dispId);
            pp++;
        }
        pT->Unlock();
    }
};

template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseObjectImpl :
    public IConnectionPointContainerImpl<T>,
    public CProxy_GcadObjectEvents<T>,
    public CProxy_PropertyNotifySink<T>,
    public IGcadBaseObject
{
public:
    IGcadBaseObjectImpl()
    {
    }

    virtual ~IGcadBaseObjectImpl()
    {
        GcAxSafeSetIUnknow(m_objId, NULL);
    }

    virtual HRESULT CreateNewObject(GcDbObjectId& objId,
        GcDbObjectId& ownerId, ACHAR* keyName) = 0;

    STDMETHOD(SetObjectId)(GcDbObjectId& objId,
        GcDbObjectId ownerId = GcDbObjectId::kNull,
        ACHAR* keyName = NULL)
    {
        if (!m_objId.isNull())
            return E_FAIL;

        if(objId == GcDbObjectId::kNull)
        {
            HRESULT hr;
            if(FAILED(hr = CreateNewObject(objId, ownerId, keyName)))
                return hr;
        }

        m_objId = objId;
        _ASSERTE(m_objId != GcDbObjectId::kNull);
        ObjectIdModified();

        return S_OK;
    }

    STDMETHOD(GetObjectId)(GcDbObjectId* objId)
    {
        *objId = m_objId;
        return S_OK;
    }

    STDMETHOD(Clone)(GcDbObjectId /*ownerId*/, LPUNKNOWN* /*pUnkClone*/)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(GetClassID)(CLSID& clsid)
    {
        clsid = *pclsid;
        return S_OK;
    }

    STDMETHOD(NullObjectId)(void)
    {
        m_objId = GcDbObjectId::kNull;
        ObjectIdModified();
        return S_OK;
    }

    STDMETHOD(OnModified)(void)
    {
        Fire_Modified();
        Fire_OnChanged();
        return S_OK;
    }

    // IConnectionPointContainerImpl
    BEGIN_CONNECTION_POINT_MAP(T)
        CONNECTION_POINT_ENTRY(__uuidof(IGcadObjectEvents))
        CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    END_CONNECTION_POINT_MAP()

protected:
    GcDbObjectId m_objId;

    virtual void ObjectIdModified()
    {};
};

#pragma warning(push)
#pragma warning(disable : 4100) // disable unreferenced formal paramter warning
template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseObject2Impl :
    public IGcadBaseObject2,
    public IGcadBaseObjectImpl<T, pclsid>
{
public:
    IGcadBaseObject2Impl()
    {
    };

    virtual ~IGcadBaseObject2Impl()
    {
    };

    STDMETHOD(SetObject)(GcDbObject*& pObj)
    {
        if (pObj->objectId().isNull())
        {
            NullObjectId();
            m_objRef.acquire(pObj);
            return S_OK;
        }
        else
        {
            GcDbObjectId tmpId = pObj->objectId();
            return SetObjectId(tmpId);
        }
    }

    STDMETHOD(GetObject)(GcDbObject*& pObj)
    {
        pObj = NULL;
        if (!m_objRef.objectId().isNull())
            return E_FAIL;

        GcDbObjectId tmpId;
        m_objRef.release(tmpId, pObj);
        _ASSERTE(m_objId.isNull());
        _ASSERTE(tmpId.isNull());
        return S_OK;
    }

    STDMETHOD(ForceDbResident)(VARIANT_BOOL *forceDbResident)
    {
        if (NULL == forceDbResident)
            return E_POINTER;

        *forceDbResident = VARIANT_TRUE;
        return S_OK;
    }

    STDMETHOD(AddToDb)(GcDbObjectId& objId,
        GcDbObjectId ownerId = GcDbObjectId::kNull,
        ACHAR* keyName = NULL)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(CreateObject)(GcDbObjectId ownerId = GcDbObjectId::kNull,
        ACHAR *keyName = NULL)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(ObjectExists)(VARIANT_BOOL *objectExists)
    {
        if (NULL == objectExists)
            return E_POINTER;

        *objectExists = m_objRef.isNull() ? VARIANT_FALSE : VARIANT_TRUE;
        return S_OK;
    }

    STDMETHOD(OnModified)(DISPID dispId = DISPID_UNKNOWN)
    {
        Fire_Modified();
        Fire_OnChanged(dispId);
        return S_OK;
    }


protected:
    GcAxObjectRef m_objRef;

    virtual void ObjectIdModified()
    {
        releaseReference();
        m_objRef.acquire(m_objId);
    }

    void Fire_Notification(DISPID dispId = DISPID_UNKNOWN)
    {
        if (m_objRef.objectId().isNull())
        {
            Fire_Modified();
            Fire_OnChanged(dispId);
        }
    }

    STDMETHOD(releaseReference)()
    {
        GcDbObjectId tmpId;
        GcDbObject*  pTmp = NULL;
        m_objRef.release(tmpId, pTmp);
        if (NULL != pTmp && pTmp->objectId().isNull())
            delete pTmp;
        return S_OK;
    }
};
#pragma warning(pop)

class ATL_NO_VTABLE IRetrieveApplicationImpl :
    public IRetrieveApplication
{
public:
    IRetrieveApplicationImpl()
    {
        m_App = NULL;
    }

    virtual ~IRetrieveApplicationImpl()
    {
        if(m_App != NULL)
            m_App->Release();
    }

    STDMETHOD(SetApplicationObject)(LPDISPATCH pApp)
    {
        if(m_App != NULL)
            return E_FAIL;
        m_App = pApp;

        if(m_App != NULL)
            m_App->AddRef();

        return S_OK;
    }

    STDMETHOD(GetApplicationObject)(LPDISPATCH* pApp)
    {
        *pApp = m_App;
        if(m_App == NULL)
            return E_FAIL;

        m_App->AddRef();
        return S_OK;
    }

protected:
    LPDISPATCH m_App;
};

template <class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
    WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IGcadObjectDispatchImpl :
    public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>,
    public IGcadBaseObject2Impl<C, pclsid>,
    public IRetrieveApplicationImpl
{
public:

    IGcadObjectDispatchImpl()
    {
        // TODO 这个函数系统未实行
        //_tih.EnsureTI(acrxProductLCID());
        _tih.EnsureTI(LOCALE_SYSTEM_DEFAULT);
    }

    virtual ~IGcadObjectDispatchImpl()
    {
    }

    STDMETHOD(get_Application)(LPDISPATCH* pVal)
    {
        return GetApplicationObject(pVal);
    }

    STDMETHOD(get_ObjectID)(Hccad::IntDbId *pVal)
    {
        *pVal = m_objRef.objectId().asOldId();
        return S_OK;
    }

    STDMETHOD(get_OwnerID)(Hccad::IntDbId *pVal)
    {
        return GcAxGetOwnerId(m_objRef, pVal);
    }

#ifdef _WIN64
    STDMETHOD(get_ObjectID32)(Hccad::Int32 *pVal)
    {
        if(pVal)
            *pVal = GcAxGetObjectId32(m_objRef.objectId().asOldId());
        return S_OK;
    }

    STDMETHOD(get_OwnerID32)(Hccad::Int32 *pVal)
    {
        Hccad::IntDbId objId;
        HRESULT hr = GcAxGetOwnerId(m_objRef, &objId);
        if(pVal)
            *pVal = GcAxGetObjectId32(objId);
        return hr;
    }
#endif

    STDMETHOD(Delete)()
    {
        return GcAxErase(m_objRef);
    }

    STDMETHOD(SetXData)(VARIANT type, VARIANT data)
    {
        return GcAxSetXData(m_objRef, type, data);
    }

    STDMETHOD(GetXData)(BSTR bstrName, VARIANT* type, VARIANT* data)
    {
        return GcAxGetXData(m_objRef, bstrName, type, data);
    }

    STDMETHOD(get_ObjectName)(BSTR *pVal)
    {
        return GcAxGetObjectName(m_objRef, pVal);
    }

    STDMETHOD(get_Handle)(BSTR *pVal)
    {
        return GcAxGetHandle(m_objRef, pVal);
    }

    STDMETHOD(get_HasExtensionDictionary)(VARIANT_BOOL* bHasDictionary)
    {
        return GcAxHasExtensionDictionary(m_objRef, bHasDictionary);
    }

    STDMETHOD(GetExtensionDictionary)(IGcadDictionary** pExtDictionary)
    {
        return GcAxGetExtensionDictionary(m_objRef, m_App, pExtDictionary);
    }

    STDMETHOD(get_Database)(IGcadDatabase** pDatabase)
    {
        if(m_objRef.objectId() == GcDbObjectId::kNull ||
            m_objRef.objectId().database() == NULL)
        {
            return RaiseArxException(*piid, 0, Acad::eNoDatabase);
        }

        CComPtr<IDispatch> pDispatch;
        HRESULT hr = GcAxGetDatabase(m_objRef.objectId().database(), m_App, &pDispatch);

        if(SUCCEEDED(hr))
        {
            hr = pDispatch->QueryInterface(__uuidof(IGcadDatabase),
                reinterpret_cast<LPVOID*>(pDatabase));
        }

        return hr;
    }

    STDMETHOD(get_Document)(LPDISPATCH* pDocument)
    {
        if(m_objRef.objectId() == GcDbObjectId::kNull ||
            m_objRef.objectId().database() == NULL)
        {
            return RaiseArxException(*piid, 0, Acad::eNoDatabase);
        }

        GcAxOleLinkManager* pOleLinkManager = GcAxGetOleLinkManager();
        _ASSERTE(pOleLinkManager != NULL);

        *pDocument = pOleLinkManager->GetDocIDispatch(m_objRef.objectId().database());
        if(*pDocument == NULL)
        {
            return RaiseArxException(*piid, 0, Acad::eNoDocument);
        }

        (*pDocument)->AddRef();

        return S_OK;
    }

    STDMETHOD(Erase)()
    {
        return Delete();
    }

};

template <class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
    WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IGcadEntityDispatchImpl :
    public IGcadObjectDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>
{
public:

    STDMETHODIMP get_Color(GcColor* pVal)
    {
        return GcAxGetColor(m_objRef, pVal);
    }

    STDMETHODIMP put_Color(GcColor newVal)
    {
        return GcAxPutColor(m_objRef, newVal);
    }

    STDMETHOD(get_color)(GCAD_COLOR* pVal)
    {
        return GcAxGetColor(m_objRef, pVal);
    }
    STDMETHOD(put_color)(GCAD_COLOR newVal)
    {
        return GcAxPutColor(m_objRef, newVal);
    }

    STDMETHODIMP get_TrueColor(IGcadAcCmColor** pColor)
    {
        return GcAxGetTrueColor(m_objRef, pColor);
    }

    STDMETHODIMP put_TrueColor(IGcadAcCmColor* color)
    {
        return GcAxPutTrueColor(m_objRef, color);
    }

    STDMETHODIMP get_Layer(BSTR * pVal)
    {
        return GcAxGetLayer(m_objRef, pVal);
    }

    STDMETHODIMP put_Layer(BSTR newVal)
    {
        return GcAxPutLayer(m_objRef, newVal);
    }

    STDMETHODIMP get_Linetype(BSTR * pVal)
    {
        return GcAxGetLinetype(m_objRef, pVal);
    }

    STDMETHODIMP put_Linetype(BSTR newVal)
    {
        return GcAxPutLinetype(m_objRef, newVal);
    }

    STDMETHODIMP get_Material(BSTR * pVal)
    {
        return GcAxGetMaterial(m_objRef, pVal);
    }

    STDMETHODIMP put_Material(BSTR newVal)
    {
        return GcAxPutMaterial(m_objRef, newVal);
    }

    STDMETHODIMP get_LinetypeScale(double * pVal)
    {
        return GcAxGetLinetypeScale(m_objRef, pVal);
    }

    STDMETHODIMP put_LinetypeScale(double newVal)
    {
        return GcAxPutLinetypeScale(m_objRef, newVal);
    }

    STDMETHODIMP get_Visible(VARIANT_BOOL * pVal)
    {
        return GcAxGetVisible(m_objRef, pVal);
    }

    STDMETHODIMP put_Visible(VARIANT_BOOL newVal)
    {
        return GcAxPutVisible(m_objRef, newVal);
    }

    STDMETHODIMP ArrayPolar(int numObjs, double fillAngle, VARIANT basePoint, VARIANT * pArrayObjs)
    {
        return GcAxArrayPolar(m_objRef, m_App, numObjs, fillAngle, basePoint, pArrayObjs);
    }

    STDMETHODIMP ArrayRectangular(int numRows, int numCols, int numLvls, double disRows, double disCols, double disLvls, VARIANT * pArrayObjs)
    {
        return GcAxArrayRectangular(m_objRef, m_App, numRows, numCols, numLvls, disRows, disCols, disLvls, pArrayObjs);
    }

    STDMETHODIMP Highlight(VARIANT_BOOL bFlag)
    {
        return GcAxHighlight(m_objRef, bFlag);
    }

    STDMETHODIMP Copy(LPDISPATCH * pCopyObj)
    {
        return GcAxCopy(m_objRef, m_App, pCopyObj);
    }

    STDMETHODIMP Move(VARIANT fromPoint, VARIANT toPoint)
    {
        return GcAxMove(m_objRef, fromPoint, toPoint);
    }

    STDMETHODIMP Rotate(VARIANT basePoint, double rotationAngle)
    {
        return GcAxRotate(m_objRef, basePoint, rotationAngle);
    }

    STDMETHODIMP Rotate3D(VARIANT point1, VARIANT point2, double rotationAngle)
    {
        return GcAxRotate3D(m_objRef, point1, point2, rotationAngle);
    }

    STDMETHODIMP Mirror(VARIANT point1, VARIANT point2, LPDISPATCH * pMirrorObj)
    {
        return GcAxMirror(m_objRef, m_App, point1, point2, pMirrorObj);
    }

    STDMETHODIMP Mirror3D(VARIANT point1, VARIANT point2, VARIANT point3, LPDISPATCH * pMirrorObj)
    {
        return GcAxMirror3D(m_objRef, m_App, point1, point2, point3, pMirrorObj);
    }

    STDMETHODIMP ScaleEntity(VARIANT basePoint, double scaleFactor)
    {
        return GcAxScaleEntity(m_objRef, basePoint, scaleFactor);
    }

    STDMETHODIMP TransformBy(VARIANT transMatrix)
    {
        return GcAxTransformBy(m_objRef, transMatrix);
    }

    STDMETHODIMP Update()
    {
        return GcAxUpdate(m_objRef);
    }

    STDMETHODIMP GetBoundingBox(VARIANT * minPoint, VARIANT * maxPoint)
    {
        return GcAxGetBoundingBox(m_objRef, minPoint, maxPoint);
    }

    STDMETHODIMP IntersectWith(LPDISPATCH pEntity, GcExtendOption option, VARIANT * intPoints)
    {
        return GcAxIntersectWith(m_objRef, pEntity, option, intPoints);
    }

    STDMETHODIMP get_PlotStyleName(BSTR* plotStyleName)
    {
        return GcAxGetPlotStyleName(m_objRef, plotStyleName);
    }

    STDMETHODIMP put_PlotStyleName(BSTR plotStyleName)
    {
        return GcAxPutPlotStyleName(m_objRef, plotStyleName);
    }

    STDMETHODIMP get_Lineweight(ACAD_LWEIGHT* lineweight)
    {
        return GcAxGetLineWeight(m_objRef, lineweight);
    }

    STDMETHODIMP put_Lineweight(ACAD_LWEIGHT lineweight)
    {
        return GcAxPutLineWeight(m_objRef, lineweight);
    }

    STDMETHODIMP get_EntityTransparency(BSTR* transparency)
    {
      return GcAxGetEntityTransparency(m_objRef, transparency);
    }

    STDMETHODIMP put_EntityTransparency(BSTR transparency)
    {
      return GcAxPutEntityTransparency(m_objRef, transparency);
    }

    STDMETHODIMP get_Hyperlinks(IGcadHyperlinks** pHyperlinks)
    {
        return GcAxGetHyperlinks(m_objRef, m_App, pHyperlinks);
    }

    //
    // Provided for backwards compatibility; for future coding
    // use call ObjectName() instead of EntityName()
    //
    STDMETHOD(get_EntityName)(BSTR *pVal)
    {
        return GcAxGetObjectName(m_objRef, pVal);
    }

    STDMETHOD(get_EntityType)(GcEntityName* /*entType*/)
    {
        return E_NOTIMPL;
    }
};
template <const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseDatabaseImpl :
    public IGcadBaseDatabase
{
public:
    IGcadBaseDatabaseImpl()
    {
        m_Database = NULL;
    }

    // IGcadBaseDatabase
    STDMETHOD(SetDatabase)(GcDbDatabase*& pDb)
    {
        m_Database = pDb;
        return S_OK;
    }

    STDMETHOD(GetDatabase)(GcDbDatabase** pDb)
    {
        if(pDb == NULL)
            return E_POINTER;

        *pDb = m_Database;
        return S_OK;
    }

    STDMETHOD(GetClassID)(CLSID& clsid)
    {
        clsid = *pclsid;
        return S_OK;
    }

protected:
    GcDbDatabase* m_Database;
};

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl :
    public ICategorizeProperties,
    public IPerPropertyBrowsing,
    public IOPMPropertyExtension
{
public:
    IOPMPropertyExtensionImpl()
    {
    }

    virtual ~IOPMPropertyExtensionImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    // IGcadObject
#define DEFINEOBJNAME(IDS) \
    static UINT IDS_objectNameDisplay()\
    {return IDS;}

    // ICategorizeProperties methods
    STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmMapPropertyToCategory(pThis, T::GetOPMPropertyMap(), dispid, ppropcat);
    }

    STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmGetCategoryName(pThis, GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
    }

    // IPerPropertyBrowsing methods
    STDMETHODIMP GetDisplayString(DISPID dispID, BSTR *pBstr)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmGetDisplayString(pThis, T::GetOPMPropertyMap(), dispID, pBstr);
    }

    STDMETHODIMP MapPropertyToPage(DISPID dispID, CLSID *pClsid)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmMapPropertyToPage(pThis, T::GetOPMPropertyMap(), dispID, pClsid);
    }

    STDMETHODIMP GetPredefinedStrings(DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmGetPredefinedStrings(pThis, GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pCaStringsOut, pCaCookiesOut);
    }

    STDMETHODIMP GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT *pVarOut)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmGetPredefinedValue(pThis, T::GetOPMPropertyMap(), dispID, dwCookie, pVarOut);
    }

    // IOPMPropertyExtension methods
    STDMETHODIMP GetDisplayName(
        DISPID dispID,
        BSTR *pBstr)
    {
        __if_exists (T::IDS_objectNameDisplay)
        {
            if (0x401 == dispID)
            {
                CString str;
                if (str.LoadString(GetResourceInstance(), T::IDS_objectNameDisplay())
                    && !str.IsEmpty())
                {
                    *pBstr = str.AllocSysString();
                    return S_OK;
                }
            }
        }
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmGetDisplayName(pThis, GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pBstr);
    }

    STDMETHODIMP Editable(
        /* [in] */ DISPID dispID,
        /* [out] */ BOOL __RPC_FAR *bEditable)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmEditable(pThis, T::GetOPMPropertyMap(), dispID, bEditable);
    }

    STDMETHODIMP ShowProperty(
        /* [in] */ DISPID dispID,
        /* [out] */ BOOL *pShow)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<ICategorizeProperties*>(this));
        return GcOpmShowProperty(pThis, T::GetOPMPropertyMap(), dispID, pShow);
    }
};

#define ICategorizeProperties2Impl IGcPiCategorizePropertiesImpl
template<class T>
class ATL_NO_VTABLE IGcPiCategorizePropertiesImpl :
    public IGcPiCategorizeProperties
{
public:
    CATEGORY_VECTOR  m_CategoryVector;
    CATCMDBTN_VECTOR m_CatCmdBtnVector;

    CATEGORY_VECTOR & GetCategoryVector()
    {
        return m_CategoryVector;
    }

    CATCMDBTN_VECTOR & GetCmdBtnVector()
    {
        return m_CatCmdBtnVector;
    }

    bool IsDefaultCategoryEntry(CATEGORY_ENTRY in)
    {
        if(in.m_CatID != -1)
            return false;

        if(in.m_nWeight != -1)
            return false;

        if(in.m_ParentCatID != -1)
            return false;

        if(in.m_nDescId != 0)
            return false;

        if(in.m_nNameId != 0)
            return false;

        return true;
    }

    bool IsDefaultCmdBtnEntry(CATCMDBTN_ENTRY in)
    {
        if(in.m_CatID != -1)
            return false;

        if(in.m_lpEnBtnBmpRes != NULL)
            return false;

        if(in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_lpDisBtnBmpRes != NULL)
            return false;

        if(in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_nStyle != NULL)
            return false;

        if(in.m_pfnBtnProc != NULL)
            return false;

        if(in.m_nBtnNameId != 0)
            return false;

        return true;
    }

    IGcPiCategorizePropertiesImpl()
    {
        m_CatCmdBtnVector.clear();
        m_CategoryVector.clear();
        int i=0;
        __if_exists(T::GetCmdBtnArray)
        {
            while(!IsDefaultCmdBtnEntry(T::GetCmdBtnArray()[i]))
            {
                m_CatCmdBtnVector.push_back(T::GetCmdBtnArray()[i]);
                i++;
            }
        }

        i=0;
        __if_exists(T::GetCatArray)
        {
            while(!IsDefaultCategoryEntry(T::GetCatArray()[i]))
            {
                m_CategoryVector.push_back(T::GetCatArray()[i]);
                i++;
            }
        }
    }

    virtual ~IGcPiCategorizePropertiesImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    // IGcPiCategorizeProperties methods
    STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<IGcPiCategorizeProperties*>(this));
        return GcOpmMapPropertyToCategory(pThis, T::GetOPMPropertyMap(), dispid, ppropcat);
    }

    STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<IGcPiCategorizeProperties*>(this));
        HRESULT hr;
        hr = GcOpmGetCategoryName(pThis, GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
        if(hr == S_FALSE) {
            hr = GcOpmGetCategoryName(pThis, GetResourceInstance(), GetCategoryVector(), propcat, lcid, pbstrName);
        }
        return hr;
    }

	STDMETHODIMP GetUniqueID(BSTR *)
	{
		return E_NOTIMPL;
	}

    STDMETHODIMP GetCategoryDescription(PROPCAT propcat, LCID lcid, BSTR* pbstrDesc)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<IGcPiCategorizeProperties*>(this));
        return GcOpmGetCategoryDescription(pThis, GetResourceInstance(), GetCategoryVector(), propcat, lcid, pbstrDesc);
    }

    STDMETHODIMP GetCategoryWeight(PROPCAT CatID, long *pCategoryWeight)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<IGcPiCategorizeProperties*>(this));
        return GcOpmGetCategoryWeight(pThis, GetCategoryVector(), CatID, pCategoryWeight);
    }

    STDMETHODIMP GetParentCategory(PROPCAT CatID, PROPCAT *pParentCatID)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<IGcPiCategorizeProperties*>(this));
        return GcOpmGetParentCategory(pThis, GetCategoryVector(), CatID, pParentCatID);
    }

    STDMETHODIMP GetCommandButtons(PROPCAT CatID, VARIANT *pCatCmdBtns)
    {
        IUnknown* pThis = static_cast<IUnknown*>(static_cast<IGcPiCategorizeProperties*>(this));
        return GcOpmGetCategoryCommandButtons(pThis, GetResourceInstance(), GetCmdBtnVector(), CatID, pCatCmdBtns);
    }
};

#define IPerPropertyDisplayImpl IGcPiPropertyDisplayImpl
template<class T>
class ATL_NO_VTABLE IGcPiPropertyDisplayImpl :
    public IGcPiPropertyDisplay
{
public:
    PROP_DISP_VECTOR m_PropDispVector;

    PROP_DISP_VECTOR & GetPerPropDisplayVector()
    {
        return m_PropDispVector;
    }
    bool IsDefaultPerPropDispEntry(PER_PROP_DISP_ENTRY in)
    {
        if(in.m_bFullView != false)
            return false;

        if(in.m_ProgID != NULL)
            return false;

        if(in.m_dispid != -1)
            return false;

        if(in.m_dwIntegralHeight != -1)
            return false;

        if(in.m_lpEllipsisBmpRes != NULL)
            return false;

        if(in.m_nEllipsisBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_lpLeftIconRes != NULL)
            return false;

        if(in.m_nLeftIconType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_nWeight != -1)
            return false;

        if(in.m_TextColor != 0x80000008)
            return false;

        return true;
    }

    IGcPiPropertyDisplayImpl()
    {
        m_PropDispVector.clear();
        int i=0;
        while(!IsDefaultPerPropDispEntry(T::GetPerPropDisplayArray()[i]))
        {
            m_PropDispVector.push_back(T::GetPerPropDisplayArray()[i]);
            i++;
        }
    }

    virtual ~IGcPiPropertyDisplayImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    // IGcPiPropertyDisplay methods
    STDMETHODIMP GetCustomPropertyCtrl(VARIANT Id, LCID lcid, BSTR *psProgId)
    {
        return GcOpmGetCustomPropertyCtrl(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, lcid, psProgId);
    }

    STDMETHODIMP GetPropertyIcon(VARIANT Id, IUnknown **ppIcon)
    {
        return GcOpmGetPropertyIcon(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetPerPropDisplayVector(), Id, ppIcon);
    }

    STDMETHODIMP GetPropTextColor(VARIANT Id, OLE_COLOR *pTextColor)
    {
        return GcOpmGetPropTextColor(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pTextColor);
    }

    STDMETHODIMP IsFullView(VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight)
    {
        return GcOpmIsPropFullView(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pbVisible, pIntegralHeight);
    }

    STDMETHODIMP GetPropertyWeight(VARIANT Id, long *pPropertyWeight)
    {
        return GcOpmGetPropertyWeight(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pPropertyWeight);
    }
};

template<typename T>
class ATL_NO_VTABLE IOPMPropertyToolTipsImpl :
    public IOPMPropertyToolTips
{
public:
    virtual INT getToolTipResId(DISPID) const
    {
        return 0;
    }
    STDMETHOD(GetToolTip)(DISPID id, BSTR FAR* pToolTip)
    {
        id, pToolTip;
        CString str;
        __if_exists(T::GetOPMToolTipMap)
        {
            const Gcad_ProToolTipEntry *pToolTipMap = T::GetOPMToolTipMap();
            while (pToolTipMap && pToolTipMap->dispId)
            {
                if (pToolTipMap->dispId == id)
                {
                    if (str.LoadString(dynblockDll.ModuleHandle(), pToolTipMap->resId))
                    {
                        *pToolTip = str.AllocSysString();
                        return S_OK;
                    }
                    break;
                }
                pToolTipMap++;
            }
        }
        if(str.LoadString(dynblockDll.ModuleHandle(),
            static_cast<const T*const>(this)->getToolTipResId(id)))
        {
            *pToolTip = str.AllocSysString();
            return S_OK;
        }
        __if_exists(GcOpmGetToolTip)
        {
            if (SUCCEEDED(GcOpmGetToolTip(NULL, id, pToolTip)))
            {
                return S_OK;
            }
        }
        return E_NOTIMPL;
    }
};

#endif