/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//

#ifndef __GXTEMPL_H_
#define __GXTEMPL_H_

#include "gsoft.h"
#include "gxobjref.h"
#include "gxboiler.h"
#include "oleaprot.h"

#ifdef _GSOFT_WINDOWS_
#include "opmext.h"
#include "opmimp.h"
#endif

#include "dbobjptr.h"

#ifdef _GSOFT_WINDOWS_
#include "rxregsvc.h"
#include "PAL/api/GcLocale.h"
#pragma pack (push, 8)

#pragma warning (disable : 4786)
interface IGcadShadowDisplay;
#endif
#define GCAX_VARIANT_TRUE (VARIANT_BOOL) -1
#define GCAX_VARIANT_FALSE (VARIANT_BOOL) 0

#ifdef _GSOFT_WINDOWS_
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

  STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
  {
    return GcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispid, ppropcat);
  }

  STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
  {
    return GcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
  }

  STDMETHODIMP GetDisplayString(DISPID dispID, BSTR *pBstr)
  {
    return GcOpmGetDisplayString(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pBstr);
  }

  STDMETHODIMP MapPropertyToPage(DISPID dispID, CLSID *pClsid)
  {
    return GcOpmMapPropertyToPage(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pClsid);
  }

  STDMETHODIMP GetPredefinedStrings(DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut)
  {
    return GcOpmGetPredefinedStrings(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pCaStringsOut, pCaCookiesOut);
  }

  STDMETHODIMP GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT *pVarOut)
  {
    return GcOpmGetPredefinedValue(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, dwCookie, pVarOut);
  }

  STDMETHODIMP GetDisplayName(DISPID dispID, BSTR *pBstr)
  {
    return GcOpmGetDisplayName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pBstr);
  }

  STDMETHODIMP Editable(DISPID dispID, BOOL __RPC_FAR *bEditable)
  {
    return GcOpmEditable(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, bEditable);
  }

  STDMETHODIMP ShowProperty(DISPID dispID, BOOL *pShow)
  {
    return GcOpmShowProperty(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pShow);
  }
};

template <class T>
class CProxy_GcadObjectEvents :
  public IConnectionPointImpl<T, &IID_IGcadObjectEvents, CComDynamicUnkArray>
{
public:
  virtual ~CProxy_GcadObjectEvents()
  {
  }
  void Fire_Modified()
  {
    T* pT = static_cast<T*>(this);
    CComPtr<IGcadObject> pGcadObject;
    pT->QueryInterface(__uuidof(IGcadObject), (void**)&pGcadObject);
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
};

template <class T>
class CProxy_PropertyNotifySink :
  public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CComDynamicUnkArray>
{
public:
  virtual ~CProxy_PropertyNotifySink()
  {
  }

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
      if (pNotifySink)
        pNotifySink->OnChanged(dispId);
      pp++;
    }
    pT->Unlock();
  }
};

template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseObjectImpl :
  public IGcadBaseObject,
  public IConnectionPointContainerImpl<T>,
  public CProxy_GcadObjectEvents<T>,
  public CProxy_PropertyNotifySink<T>
{
public:
  IGcadBaseObjectImpl()
  {
  }

  virtual ~IGcadBaseObjectImpl()
  {
    if (!m_objId.isValid())
      return;

    GcDbObjectPointer<GcDbObject> pObject(m_objId, GcDb::kForRead, Gsoft::kTrue);
    if (pObject.openStatus() != Gcad::eOk)
    {
      GcDbObject* pTemp;
      if (Gcad::eOk != gcdbOpenObject(pTemp, m_objId, GcDb::kForNotify, Gsoft::kTrue))
      {
        return;
      }
      pObject.acquire(pTemp);
    }

    GcAxOleLinkManager* pOleLinkManager = GcAxGetOleLinkManager();
    _ASSERTE(pOleLinkManager != NULL);

    pOleLinkManager->SetIUnknown(pObject.object(), NULL);
  }

  virtual HRESULT CreateNewObject(GcDbObjectId& objId, GcDbObjectId& ownerId, GCHAR* keyName) = 0;

  STDMETHOD(SetObjectId)(GcDbObjectId& objId,
    GcDbObjectId ownerId = GcDbObjectId::kNull,
    GCHAR* keyName = NULL)
  {
    if (!m_objId.isNull())
      return E_FAIL;

    if (objId == GcDbObjectId::kNull)
    {
      HRESULT hr;
      if (FAILED(hr = CreateNewObject(objId, ownerId, keyName)))
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

  STDMETHOD(Clone)(GcDbObjectId, LPUNKNOWN*)
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

  BEGIN_CONNECTION_POINT_MAP(T)
    CONNECTION_POINT_ENTRY(IID_IGcadObjectEvents)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
  END_CONNECTION_POINT_MAP()

protected:
  GcDbObjectId m_objId;

  virtual void ObjectIdModified()
  {};
};

#pragma warning(push)
#pragma warning(disable : 4100)
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

    *forceDbResident = GCAX_VARIANT_TRUE;
    return S_OK;
  }

  STDMETHOD(AddToDb)(GcDbObjectId& objId,
    GcDbObjectId ownerId = GcDbObjectId::kNull,
    GCHAR* keyName = NULL)
  {
    return E_NOTIMPL;
  }

  STDMETHOD(CreateObject)(GcDbObjectId ownerId = GcDbObjectId::kNull,
    GCHAR *keyName = NULL)
  {
    return E_NOTIMPL;
  }

  STDMETHOD(ObjectExists)(VARIANT_BOOL *objectExists)
  {
    if (NULL == objectExists)
      return E_POINTER;

    *objectExists = m_objRef.isNull() ? GCAX_VARIANT_FALSE : GCAX_VARIANT_TRUE;
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
    if (m_App != NULL)
      m_App->Release();
  }

  STDMETHOD(SetApplicationObject)(LPDISPATCH pApp)
  {
    if (m_App != NULL)
      return E_FAIL;
    m_App = pApp;

    if (m_App != NULL)
      m_App->AddRef();

    return S_OK;
  }
  STDMETHOD(GetApplicationObject)(LPDISPATCH* pApp)
  {
    *pApp = m_App;
    if (m_App == NULL)
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
    auto locale = gcrxProductLocale();

    GcLocale::LocaleId lcid = locale;

    _tih.EnsureTI(lcid);
  }

  virtual ~IGcadObjectDispatchImpl()
  {
  }

  STDMETHOD(get_Application)(LPDISPATCH* pVal)
  {
    return GetApplicationObject(pVal);
  }

  STDMETHOD(get_ObjectID)(LONG_PTR *pVal)
  {
    *pVal = m_objRef.objectId().asOldId();
    return S_OK;
  }

  STDMETHOD(get_OwnerID)(LONG_PTR *pVal)
  {
    Gsoft::IntDbId val;
    auto hr = GcAxGetOwnerId(m_objRef, &val);
    *pVal = val;
    return hr;
  }

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
    if (m_objRef.objectId() == GcDbObjectId::kNull || m_objRef.objectId().database() == NULL)
    {
      return RaiseGrxException(*piid, 0, Gcad::eNoDatabase);
    }

    CComPtr<IDispatch> pDispatch;
    HRESULT hr = GcAxGetDatabase(m_objRef.objectId().database(), m_App, &pDispatch);

    if (SUCCEEDED(hr))
    {
      hr = pDispatch->QueryInterface(IID_IGcadDatabase,
        reinterpret_cast<LPVOID*>(pDatabase));
    }

    return hr;
  }

  STDMETHOD(get_Document)(LPDISPATCH* pDocument)
  {
    if (m_objRef.objectId() == GcDbObjectId::kNull || m_objRef.objectId().database() == NULL)
    {
      return RaiseGrxException(*piid, 0, Gcad::eNoDatabase);
    }

    GcAxOleLinkManager* pOleLinkManager = GcAxGetOleLinkManager();
    _ASSERTE(pOleLinkManager != NULL);

    *pDocument = pOleLinkManager->GetDocIDispatch(m_objRef.objectId().database());
    if (*pDocument == NULL)
    {
      return RaiseGrxException(*piid, 0, Gcad::eNoDocument);
    }

    (*pDocument)->AddRef();

    return S_OK;
  }

  STDMETHOD(Erase)()
  {
    return Delete();
  }

  STDMETHOD(Invoke)(DISPID dispidMember, REFIID riid,
    LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult,
    EXCEPINFO* pexcepinfo, UINT* puArgErr)
  {
    HRESULT hr = _tih.Invoke((IDispatch*)this, dispidMember, riid, lcid,
      wFlags, pdispparams, pvarResult, pexcepinfo, puArgErr);
    if (hr == DISP_E_MEMBERNOTFOUND && wFlags == DISPATCH_PROPERTYPUTREF)
    {
      HRESULT hr2 = _tih.Invoke((IDispatch*)this, dispidMember, riid, lcid,
        DISPATCH_PROPERTYPUT, pdispparams, pvarResult, pexcepinfo, puArgErr);

      if (SUCCEEDED(hr2))
        return hr2;
    }
    return hr;
  }
};

template <class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
  WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
  class ATL_NO_VTABLE IGcadEntityDispatchImpl :
  public IGcadObjectDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>
{
public:
  STDMETHODIMP get_Color(GCAD_COLOR* pVal)
  {
    return GcAxGetColor(m_objRef, pVal);
  }
  STDMETHODIMP put_Color(GCAD_COLOR newVal)
  {
    return GcAxPutColor(m_objRef, newVal);
  }

  STDMETHODIMP get_TrueColor(IGcadGcCmColor** pColor)
  {
    return GcAxGetTrueColor(m_objRef, pColor);
  }
  STDMETHODIMP put_TrueColor(IGcadGcCmColor* color)
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

  STDMETHODIMP get_Lineweight(GCAD_LWEIGHT* lineweight)
  {
    return GcAxGetLineWeight(m_objRef, lineweight);
  }
  STDMETHODIMP put_Lineweight(GCAD_LWEIGHT lineweight)
  {
    return GcAxPutLineWeight(m_objRef, lineweight);
  }

  STDMETHODIMP get_Hyperlinks(IGcadHyperlinks** pHyperlinks)
  {
    return GcAxGetHyperlinks(m_objRef, m_App, pHyperlinks);
  }

  STDMETHODIMP get_EntityTransparency(BSTR * pVal)
  {
    return GcAxGetTransparency(m_objRef, pVal);
  }
  STDMETHODIMP put_EntityTransparency(BSTR newVal)
  {
    return GcAxPutTransparency(m_objRef, newVal);
  }

  STDMETHOD(get_EntityName)(BSTR *pVal)
  {
    return GcAxGetObjectName(m_objRef, pVal);
  }

  STDMETHOD(get_EntityType)(long*)
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

  STDMETHOD(SetDatabase)(GcDbDatabase*& pDb)
  {
    m_Database = pDb;
    return S_OK;
  }
  STDMETHOD(GetDatabase)(GcDbDatabase** pDb)
  {
    if (pDb == NULL)
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

template <class C, const CLSID* pclsid, class T, const IID* piid,
  const GUID* plibid,
  WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
  class ATL_NO_VTABLE IGcadBaseSubEntityImpl :
  public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>,
  public IGcadBaseSubEntity,
  public IRetrieveApplicationImpl,
  public IConnectionPointContainerImpl<C>,
  public CProxy_GcadObjectEvents<C>,
  public CProxy_PropertyNotifySink<C>
{
public:
  IGcadBaseSubEntityImpl()
  {
  }
  virtual ~IGcadBaseSubEntityImpl()
  {
    if (!m_objId.isValid())
      return;

    GcDbObjectPointer<GcDbObject> pObject(m_objId, GcDb::kForRead,
      Gsoft::kTrue);
    if (pObject.openStatus() != Gcad::eOk)
    {
      GcDbObject* pTemp;
      if (Gcad::eOk != gcdbOpenObject(pTemp, m_objId, GcDb::kForNotify, Gsoft::kTrue))
      {
        return;
      }
      pObject.acquire(pTemp);
    }
    GcAxOleLinkManager* pOleLinkManager = GcAxGetOleLinkManager();
    _ASSERTE(pOleLinkManager != NULL);

    pOleLinkManager->SetIUnknown(pObject.object(), m_subentPath.subentId(), NULL);
  }

  STDMETHOD(OnModified)()
  {
    Fire_Modified();
    Fire_OnChanged();
    return S_OK;
  }

  STDMETHOD(SetFullSubEntPath)(GcDbFullSubentPath& subentPath)
  {
    m_subentPath = subentPath;
    GcDbObjectIdArray objectIds = m_subentPath.objectIds();
    if (0 != objectIds.length())
      m_objId = objectIds[objectIds.length() - 1];
    return S_OK;
  }
  STDMETHOD(GetFullSubEntPath)(GcDbFullSubentPath* subentPath)
  {
    *subentPath = m_subentPath;
    return S_OK;
  }

  STDMETHOD(GetClassID)(CLSID& clsid)
  {
    clsid = *pclsid;
    return S_OK;
  }

  STDMETHOD(get_ObjectName)(BSTR *pVal)
  {
    return GcAxGetObjectName(m_objId, pVal);
  }
  STDMETHODIMP get_Color(IGcadGcCmColor** pColor)
  {
    return GcAxGetTrueColor(m_objId, pColor);
  }
  STDMETHODIMP get_Layer(BSTR * pVal)
  {
    return GcAxGetLayer(m_objId, pVal);
  }
  STDMETHODIMP get_Linetype(BSTR * pVal)
  {
    return GcAxGetLinetype(m_objId, pVal);
  }
  STDMETHODIMP get_LinetypeScale(double * pVal)
  {
    return GcAxGetLinetypeScale(m_objId, pVal);
  }
  STDMETHODIMP get_PlotStyleName(BSTR* plotStyleName)
  {
    return GcAxGetPlotStyleName(m_objId, plotStyleName);
  }
  STDMETHODIMP get_Lineweight(GCAD_LWEIGHT* lineweight)
  {
    return GcAxGetLineWeight(m_objId, lineweight);
  }
  STDMETHODIMP get_Hyperlinks(IGcadHyperlinks** pHyperlinks)
  {
    return GcAxGetHyperlinks(m_objId, m_App, pHyperlinks);
  }

  BEGIN_CONNECTION_POINT_MAP(C)
    CONNECTION_POINT_ENTRY(IID_IGcadObjectEvents)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
  END_CONNECTION_POINT_MAP()

protected:
  STDMETHODIMP parentObjectId(GcDbObjectId &objID)
  {
    GcDbObjectIdArray objectIds = m_subentPath.objectIds();
    if (0 != objectIds.length())
    {
      objID = objectIds[objectIds.length() - 1];
      return S_OK;
    }
    return E_FAIL;
  }
  GcDbFullSubentPath m_subentPath;
  GcDbObjectId m_objId;
};

#define IPropCommandButtonsImpl IGcPiPropCommandButtonsImpl
template<class T>
class ATL_NO_VTABLE IGcPiPropCommandButtonsImpl :
  public IGcPiPropCommandButtons
{
public:
  CMDBTN_VECTOR m_CmdBtnVector;

  CMDBTN_VECTOR & GetCmdBtnVector()
  {
    return m_CmdBtnVector;
  }

  bool IsDefaultCmdBtnEntry(CMDBTN_ENTRY in)
  {
    if (in.m_lpEnBtnBmpRes != NULL)
      return false;

    if (in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
      return false;

    if (in.m_lpDisBtnBmpRes != NULL)
      return false;

    if (in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
      return false;

    if (in.m_pfnBtnProc != NULL)
      return false;

    if (in.m_nBtnNameId != NULL)
      return false;

    if (in.m_nStyle != NULL)
      return false;

    return true;
  }

  IGcPiPropCommandButtonsImpl()
  {
    m_CmdBtnVector.clear();
    int i = 0;
    while (!IsDefaultCmdBtnEntry(T::GetPropCmdBtnArray()[i]))
    {
      m_CmdBtnVector.push_back(T::GetPropCmdBtnArray()[i]);
      i++;
    }
  }

  virtual ~IGcPiPropCommandButtonsImpl()
  {
  }

  virtual HINSTANCE GetResourceInstance() = 0;

  STDMETHODIMP GetButtons(VARIANT *pCmdBtns)
  {
    return GcOpmGetCommandButtons(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCmdBtnVector(), pCmdBtns);
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
    if (in.m_bFullView != false)
      return false;

    if (in.m_ProgID != NULL)
      return false;

    if (in.m_dispid != -1)
      return false;

    if (in.m_dwIntegralHeight != -1)
      return false;

    if (in.m_lpEllipsisBmpRes != NULL)
      return false;

    if (in.m_nEllipsisBmpType != PICTYPE_UNINITIALIZED)
      return false;

    if (in.m_lpLeftIconRes != NULL)
      return false;

    if (in.m_nLeftIconType != PICTYPE_UNINITIALIZED)
      return false;

    if (in.m_nWeight != -1)
      return false;

    if (in.m_TextColor != 0x80000008)
      return false;

    return true;
  }

  IGcPiPropertyDisplayImpl()
  {
    m_PropDispVector.clear();
    int i = 0;
    while (!IsDefaultPerPropDispEntry(T::GetPerPropDisplayArray()[i]))
    {
      m_PropDispVector.push_back(T::GetPerPropDisplayArray()[i]);
      i++;
    }
  }

  virtual ~IGcPiPropertyDisplayImpl()
  {
  }

  virtual HINSTANCE GetResourceInstance() = 0;

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
    if (in.m_CatID != -1)
      return false;

    if (in.m_nWeight != -1)
      return false;

    if (in.m_ParentCatID != -1)
      return false;

    if (in.m_nDescId != 0)
      return false;

    if (in.m_nNameId != 0)
      return false;

    return true;
  }

  bool IsDefaultCmdBtnEntry(CATCMDBTN_ENTRY in)
  {
    if (in.m_CatID != -1)
      return false;

    if (in.m_lpEnBtnBmpRes != NULL)
      return false;

    if (in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
      return false;

    if (in.m_lpDisBtnBmpRes != NULL)
      return false;

    if (in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
      return false;

    if (in.m_nStyle != NULL)
      return false;

    if (in.m_pfnBtnProc != NULL)
      return false;

    if (in.m_nBtnNameId != 0)
      return false;

    return true;
  }

  IGcPiCategorizePropertiesImpl()
  {
    m_CatCmdBtnVector.clear();
    m_CategoryVector.clear();
    int i = 0;
    while (!IsDefaultCmdBtnEntry(T::GetCmdBtnArray()[i]))
    {
      m_CatCmdBtnVector.push_back(T::GetCmdBtnArray()[i]);
      i++;
    }

    i = 0;
    while (!IsDefaultCategoryEntry(T::GetCatArray()[i]))
    {
      m_CategoryVector.push_back(T::GetCatArray()[i]);
      i++;
    }
  }

  virtual ~IGcPiCategorizePropertiesImpl()
  {
  }

  virtual HINSTANCE GetResourceInstance() = 0;

  STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
  {
    return GcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispid, ppropcat);
  }

  STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
  {
    HRESULT hr;
    hr = GcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
    if (hr == S_FALSE)
    {
      hr = GcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCategoryVector(), propcat, lcid, pbstrName);
    }
    return hr;
  }

  STDMETHODIMP GetCategoryDescription(PROPCAT propcat, LCID lcid, BSTR* pbstrDesc)
  {
    return GcOpmGetCategoryDescription(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCategoryVector(), propcat, lcid, pbstrDesc);
  }

  STDMETHODIMP GetCategoryWeight(PROPCAT CatID, long *pCategoryWeight)
  {
    return GcOpmGetCategoryWeight(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), CatID, pCategoryWeight);
  }

  STDMETHODIMP GetParentCategory(PROPCAT CatID, PROPCAT *pParentCatID)
  {
    return GcOpmGetParentCategory(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), CatID, pParentCatID);
  }

  STDMETHODIMP GetCommandButtons(PROPCAT CatID, VARIANT *pCatCmdBtns)
  {
    return GcOpmGetCategoryCommandButtons(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCmdBtnVector(), CatID, pCatCmdBtns);
  }
};

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl2 :
  public IPerPropertyBrowsing,
  public IOPMPropertyExtension
{
public:
  IOPMPropertyExtensionImpl2()
  {
  }
  virtual ~IOPMPropertyExtensionImpl2()
  {
  }

  virtual HINSTANCE GetResourceInstance() = 0;

  STDMETHODIMP GetDisplayString(DISPID dispID, BSTR *pBstr)
  {
    return GcOpmGetDisplayString(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pBstr);
  }

  STDMETHODIMP MapPropertyToPage(DISPID dispID, CLSID *pClsid)
  {
    return GcOpmMapPropertyToPage(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pClsid);
  }

  STDMETHODIMP GetPredefinedStrings(DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut)
  {
    return GcOpmGetPredefinedStrings(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pCaStringsOut, pCaCookiesOut);
  }

  STDMETHODIMP GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT *pVarOut)
  {
    return GcOpmGetPredefinedValue(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, dwCookie, pVarOut);
  }

  STDMETHODIMP GetDisplayName(DISPID dispID, BSTR *pBstr)
  {
    return GcOpmGetDisplayName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pBstr);
  }

  STDMETHODIMP Editable(DISPID dispID, BOOL __RPC_FAR *bEditable)
  {
    return GcOpmEditable(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, bEditable);
  }

  STDMETHODIMP ShowProperty(DISPID dispID, BOOL *pShow)
  {
    return GcOpmShowProperty(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pShow);
  }
};

template <class C>
class ATL_NO_VTABLE IGcadShadowDisplayImpl : public IGcadShadowDisplay
{
public:
  STDMETHODIMP get_ShadowDisplay(GcShadowDisplayType* pShadowDisplay)
  {
    CComPtr<IGcadBaseObject> pGcadBaseObject;
    HRESULT hr = QueryInterface(IID_IGcadBaseObject, (LPVOID*)&pGcadBaseObject);
    if (FAILED(hr))
      return S_FALSE;

    GcDbObjectId objId;
    pGcadBaseObject->GetObjectId(&objId);
    return GcAxGetShadowDisplay(objId, pShadowDisplay);
  }
  STDMETHODIMP put_ShadowDisplay(GcShadowDisplayType shadowDisplay)
  {
    CComPtr<IGcadBaseObject> pGcadBaseObject;
    HRESULT hr = QueryInterface(IID_IGcadBaseObject, (LPVOID*)&pGcadBaseObject);
    if (FAILED(hr))
      return S_FALSE;

    GcDbObjectId objId;
    pGcadBaseObject->GetObjectId(&objId);
    return GcAxPutShadowDisplay(objId, shadowDisplay);
  }
  STDMETHODIMP get_EnableShadowDisplay(BOOL* bEnabled)
  {
    *bEnabled = TRUE;
    return S_OK;
  }
};

template <class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid,
  WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
  class ATL_NO_VTABLE IGcadSurfaceDispatchImpl :
  public IGcadEntityDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>
{
public:
  STDMETHOD(get_UIsolineDensity)(long *density)
  {
    return GcAxGet_UIsolineDensity(m_objId, density);
  }
  STDMETHOD(put_UIsolineDensity)(long density)
  {
    return GcAxPut_UIsolineDensity(m_objId, density);
  }
  STDMETHOD(get_VIsolineDensity)(long *density)
  {
    return GcAxGet_VIsolineDensity(m_objId, density);
  }
  STDMETHOD(put_VIsolineDensity)(long density)
  {
    return GcAxPut_VIsolineDensity(m_objId, density);
  }

  STDMETHOD(get_WireframeType)(GcWireframeType *type)
  {
    return GcAxGet_WireframeType(m_objId, type);
  }
  STDMETHOD(put_WireframeType)(GcWireframeType type)
  {
    return GcAxPut_WireframeType(m_objId, type);
  }

  STDMETHOD(get_MaintainAssociativity)(int *maintainAssoc)
  {
    return GcAxGetMaintainAssociativity(m_objId, maintainAssoc);
  }
  STDMETHOD(put_MaintainAssociativity)(int maintainAssoc)
  {
    return GcAxPutMaintainAssociativity(m_objId, maintainAssoc);
  }

  STDMETHOD(get_ShowAssociativity)(VARIANT_BOOL *bEnabled)
  {
    return GcAxGetShowAssociativity(m_objId, bEnabled);
  }
  STDMETHOD(put_ShowAssociativity)(VARIANT_BOOL bEnabled)
  {
    return GcAxPutShowAssociativity(m_objId, bEnabled);
  }

  STDMETHOD(get_EdgeExtensionDistances)(VARIANT *extDistances)
  {
    return GcAxGetEdgeExtensionDistances(m_objId, extDistances);
  }
  STDMETHOD(put_EdgeExtensionDistances)(VARIANT extDistances)
  {
    return GcAxPutEdgeExtensionDistances(m_objId, extDistances);
  }

  STDMETHOD(get_SurfTrimAssociativity)(VARIANT *associative)
  {
    return GcAxGetSurfTrimAssociativity(m_objId, associative);
  }
  STDMETHOD(put_SurfTrimAssociativity)(VARIANT associative)
  {
    return GcAxPutSurfTrimAssociativity(m_objId, associative);
  }
};

#pragma pack (pop)

#else

template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseObjectImpl :
  public IGcadBaseObject
{
public:
  IGcadBaseObjectImpl() {}

  virtual ~IGcadBaseObjectImpl()
  {
    if (!m_objId.isValid())
      return;

    GcDbObjectPointer<GcDbObject> pObject(m_objId, GcDb::kForRead, Gsoft::kTrue);
    if (pObject.openStatus() != Gcad::eOk)
    {
      GcDbObject* pTemp;
      if (Gcad::eOk != gcdbOpenObject(pTemp, m_objId, GcDb::kForNotify, Gsoft::kTrue))
      {
        return;
      }
      pObject.acquire(pTemp);
    }
  }

  virtual HRESULT CreateNewObject(GcDbObjectId& objId,
                                  GcDbObjectId& ownerId, GCHAR* keyName)
  {
    return E_NOTIMPL;
  }

  STDMETHOD(SetObjectId(GcDbObjectId& objId,
                        GcDbObjectId ownerId = GcDbObjectId::kNull,
                        GCHAR* keyName = NULL))
  {
    if (!m_objId.isNull())
      return E_FAIL;

    if (objId == GcDbObjectId::kNull)
    {
      HRESULT hr;
      if (FAILED(hr = CreateNewObject(objId, ownerId, keyName)))
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

  STDMETHOD(Clone)(GcDbObjectId, LPUNKNOWN*)
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
    return S_OK;
  }

protected:
  GcDbObjectId m_objId;

  virtual void ObjectIdModified() {};
};


template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseObject2Impl :
  public IGcadBaseObject2,
  public IGcadBaseObjectImpl<T, pclsid>
{
public:
  IGcadBaseObject2Impl() {}
  virtual ~IGcadBaseObject2Impl() {}

  STDMETHOD(SetObject)(GcDbObject*& pObj)
  {
    if (pObj->objectId().isNull())
    {
      this->NullObjectId();
      m_objRef.acquire(pObj);
      return S_OK;
    }
    else
    {
      GcDbObjectId tmpId = pObj->objectId();
      return this->SetObjectId(tmpId);
    }
  }

  STDMETHOD(GetObject)(GcDbObject*& pObj)
  {
    pObj = NULL;
    if (!m_objRef.objectId().isNull())
      return E_FAIL;

    GcDbObjectId tmpId;
    m_objRef.release(tmpId, pObj);
    _ASSERTE(this->m_objId.isNull());
    _ASSERTE(tmpId.isNull());
    return S_OK;
  }

  STDMETHOD(ForceDbResident)(VARIANT_BOOL *forceDbResident)
  {
    if (NULL == forceDbResident)
      return E_POINTER;

    *forceDbResident = GCAX_VARIANT_TRUE;
    return S_OK;
  }

  STDMETHOD(AddToDb)(GcDbObjectId& objId,
                     GcDbObjectId ownerId = GcDbObjectId::kNull,
                     GCHAR* keyName = NULL)
  {
    return E_NOTIMPL;
  }

  STDMETHOD(CreateObject)(GcDbObjectId ownerId = GcDbObjectId::kNull,
                          GCHAR *keyName = NULL)
  {
    return E_NOTIMPL;
  }

  STDMETHOD(ObjectExists)(VARIANT_BOOL *objectExists)
  {
    if (NULL == objectExists)
      return E_POINTER;

    *objectExists = m_objRef.isNull() ? GCAX_VARIANT_FALSE : GCAX_VARIANT_TRUE;
    return S_OK;
  }

  STDMETHOD(OnModified)(DISPID dispId = DISPID_UNKNOWN)
  {
    return S_OK;
  }

protected:
  GcAxObjectRef m_objRef;

  virtual void ObjectIdModified()
  {
    releaseReference();
    m_objRef.acquire(this->m_objId);
  }

  void Fire_Notification(DISPID dispId = DISPID_UNKNOWN)
  {
    if (m_objRef.objectId().isNull())
    {
      this->Fire_Modified();
      this->Fire_OnChanged(dispId);
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

template <const CLSID* pclsid>
class ATL_NO_VTABLE IGcadBaseDatabaseImpl :
  public IGcadBaseDatabase
{
public:
  IGcadBaseDatabaseImpl()
  {
    m_Database = NULL;
  }

  STDMETHOD(SetDatabase)(GcDbDatabase*& pDb)
  {
    m_Database = pDb;
    return S_OK;
  }
  STDMETHOD(GetDatabase)(GcDbDatabase** pDb)
  {
    if (pDb == NULL)
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

#endif
#endif
