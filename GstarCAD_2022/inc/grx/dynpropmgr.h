// The GcRxDynPropMgr class is used internally by GcRxArxApp to map
// dynamic property classes to GcRxClass instances. GRX Applications
// that do not use GcRxArxApp may use GcRxDynPropMgr by dynamically
// instantiating it in the gcrxEntryPoint method's GcRx::kInitAppMsg
// case, and deleting it in the GcRx::kUnloadAppMsg case.
//
// GcRxDynPropMgr uses the OPM_DYNPROP_OBJECT_ENTRY_AUTO macro for its
// mappings to classes. 
//
// Clients should declare one OPM_DYNPROP_OBJECT_ENTRY_AUTO macro for
// each class mapping, i.e.:
//
//    OPM_DYNPROP_OBJECT_ENTRY_AUTO(CMyDynProp, GcDbLine)
//    OPM_DYNPROP_OBJECT_ENTRY_AUTO(CMyDynProp, GcDbCircle)
//
// To instanciate zero selection mode properties attach properties to
// GcDbDatabase, I.e.:
//
//	OPM_DYNPROP_OBJECT_ENTRY_AUTO(CMyDynProp, GcDbDatabase)
//
// Use the OPM_DYNPROP_COMMAND_ENTRY_AUTO macro to map properties to
// a command, I.e.:
//
//  OPM_DYNPROP_COMMAND_ENTRY_AUTO(CMyDynProp, MyCommandName)
//
// These macros should appear in the dynamic property class header file
// after the class declaration.

//-----------------------------------------------------------------------------
#pragma once
#include <comdef.h>
#include "dynprops.h"

//-----------------------------------------------------------------------------
struct _OPM_DYNPROP_ENTRY {
    _ATL_CREATORFUNC *pfnCreateInstance ;
    const GCHAR *strCmd ;
    GcRxClass *pClass ;
    IDynamicProperty *pProp ;
    const CLSID* pclsid ;
    IPropertySource *pPropSrc ;
} ;

#pragma section("OPM_DYNPROP$__a", read, shared)
#pragma section("OPM_DYNPROP$__z", read, shared)
#pragma section("OPM_DYNPROP$__m", read, shared)

extern "C" {
    __declspec(selectany) __declspec(allocate("OPM_DYNPROP$__a")) _OPM_DYNPROP_ENTRY* __pOpmObjMapEntryFirst =NULL ;
    __declspec(selectany) __declspec(allocate("OPM_DYNPROP$__z")) _OPM_DYNPROP_ENTRY* __pOpmObjMapEntryLast =NULL ;
}

#ifdef _WIN64
#define OPM_DYNPROP_OBJECT_ENTRY_PRAGMA(classname, rxclass) __pragma(comment(linker, "/include:__pOpmObjMap_" #rxclass #classname)) ;
#else
#define OPM_DYNPROP_OBJECT_ENTRY_PRAGMA(classname, rxclass) __pragma(comment(linker, "/include:___pOpmObjMap_" #rxclass #classname)) ;
#endif

#define OPM_DYNPROP_OBJECT_ENTRY_MAKE(classname, rxclass, clsid) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY __OpmObjMap_##rxclass##classname = {classname::_CreatorClass::CreateInstance, NULL, rxclass::desc (), NULL, &clsid, NULL} ; \
    extern "C" __declspec(allocate("OPM_DYNPROP$__m")) __declspec(selectany) _OPM_DYNPROP_ENTRY* const __pOpmObjMap_##rxclass##classname = &__OpmObjMap_##rxclass##classname ; \
    OPM_DYNPROP_OBJECT_ENTRY_PRAGMA(classname, rxclass)

#define OPM_DYNPROP_OBJECT_ENTRY_AUTO(classname, rxclass) \
    OPM_DYNPROP_OBJECT_ENTRY_MAKE(classname, rxclass, __uuidof (IDynamicProperty2))

#define OPM_DYNPROP_OBJECT_LEGACY1ENTRY_AUTO(classname, rxclass) \
    OPM_DYNPROP_OBJECT_ENTRY_MAKE(classname, rxclass, __uuidof (IDynamicProperty))

#ifdef _WIN64
#define OPM_DYNPROP_COMMAND_ENTRY_PRAGMA(classname, cmdname) __pragma(comment(linker, "/include:__pOpmObjMap_" #cmdname #classname)) ;
#else
#define OPM_DYNPROP_COMMAND_ENTRY_PRAGMA(classname, cmdname) __pragma(comment(linker, "/include:___pOpmObjMap_" #cmdname #classname)) ;
#endif

#define OPM_DYNPROP_COMMAND_ENTRY_MAKE(classname, cmdname, clsid) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY __OpmObjMap_##cmdname##classname = {classname::_CreatorClass::CreateInstance, _RXST(#cmdname), NULL, NULL, &clsid} ; \
    extern "C" __declspec(allocate("OPM_DYNPROP$__m")) __declspec(selectany) _OPM_DYNPROP_ENTRY* const __pOpmObjMap_##cmdname##classname = &__OpmObjMap_##cmdname##classname ; \
    OPM_DYNPROP_COMMAND_ENTRY_PRAGMA(classname, cmdname)

#define OPM_DYNPROP_COMMAND_ENTRY_AUTO(classname, cmdname) \
    OPM_DYNPROP_COMMAND_ENTRY_MAKE(classname, cmdname, __uuidof (IDynamicProperty2))

#define OPM_DYNPROP_COMMAND_LEGACY1ENTRY_AUTO(classname, cmdname) \
    OPM_DYNPROP_COMMAND_ENTRY_MAKE(classname, cmdname, __uuidof (IDynamicProperty))


#define OPM_DYNPROP_PERINSTANCE_ENTRY_AUTO(classname, rxclass) \
    OPM_DYNPROP_OBJECT_ENTRY_MAKE(classname, rxclass, __uuidof (IPropertySource))


//-----------------------------------------------------------------------------
class GcRxDynPropManager {

public:
    GcRxDynPropManager () {
        _OPM_DYNPROP_ENTRY **m_ppOpmObjMapEntryFirst =&__pOpmObjMapEntryFirst + 1 ;
        _OPM_DYNPROP_ENTRY **m_ppOpmObjMapEntryLast =&__pOpmObjMapEntryLast ;
        for ( _OPM_DYNPROP_ENTRY **ppEntry =m_ppOpmObjMapEntryFirst ; ppEntry < m_ppOpmObjMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                if ( *((*ppEntry)->pclsid) == __uuidof (IDynamicProperty2) || *((*ppEntry)->pclsid) == __uuidof (IDynamicProperty) ) {
                    //- Dynamic properties via the Property Manager
                    CComPtr<IPropertyManager> pPropMan ;
                    ATLASSERT( !((*ppEntry)->pClass && (*ppEntry)->strCmd) ) ;
                    ATLASSERT( (*ppEntry)->pClass || (*ppEntry)->strCmd ) ;
                    if ( (*ppEntry)->pClass != NULL && (*ppEntry)->pClass == GcDbDatabase::desc () ) {
                        //- Zero Selection property
                        if ( (pPropMan =GET_OPMEXTENSION_CREATE_PROTOCOL ()->CreateOPMObjectProtocol (NULL, 2)->GetPropertyManager ()) == NULL )
                            _com_issue_error (E_FAIL) ;
                    } else if ( (*ppEntry)->pClass != NULL ) {
                        //- Class property
                        if ( (pPropMan =GET_OPMPROPERTY_MANAGER ((*ppEntry)->pClass)) == NULL )
                            _com_issue_error (E_FAIL) ;
                    } else {
                        //- Command property
                        if ( GET_OPMEXTENSION_CREATE_PROTOCOL ()->GetOPMManager ((*ppEntry)->strCmd, &pPropMan) == FALSE ) {
                            if ( (pPropMan =GET_OPM_COMMAND_PROPERTY_MANAGER ((*ppEntry)->strCmd)) == NULL )
                                _com_issue_error (E_FAIL) ;
                        }
                        OPMPropertyExtension *pOPMExt =GET_OPMEXTENSION_CREATE_PROTOCOL ()->CreateOPMCommandProtocol ((*ppEntry)->strCmd) ;
                        if(NULL == pOPMExt)
                           ATLASSERT(FALSE);
                        else
                        pOPMExt->SetPropertyManager (pPropMan) ;
                    }
                    // 注意这里的可能问题：以为创建的有可能是一个IDynamicProperty2接口coclasss对象，而复制给了IDynamicProperty指针
                    if(NULL == (*ppEntry)->pfnCreateInstance || (_ATL_CREATORFUNC *)-1 ==  (*ppEntry)->pfnCreateInstance || 0 ==  (*ppEntry)->pfnCreateInstance)
                    {
                        ATLASSERT(FALSE);
                    }
                    else
                    {
                      _com_util::CheckError ((*ppEntry)->pfnCreateInstance (NULL, *((*ppEntry)->pclsid), (void **)&((*ppEntry)->pProp))) ;
                    }
                    // 经过测试，这里不应该增加计数，Acad上增加了计数结果就是没有释放
                    //(*ppEntry)->pProp->AddRef () ;
                    _com_util::CheckError (pPropMan->AddProperty ((*ppEntry)->pProp)) ;
                } else if ( *((*ppEntry)->pclsid) == __uuidof (IPropertySource) ) {
                    //- Per Instance Property
                    ATLASSERT( (*ppEntry)->pClass ) ;
                    _com_util::CheckError ((*ppEntry)->pfnCreateInstance (NULL, *((*ppEntry)->pclsid), (void **)&((*ppEntry)->pPropSrc))) ;
                    CComBSTR propName ;
                    (*ppEntry)->pPropSrc->get_Name (&propName) ;
                    IPropertySource *pPropSrc =GET_OPM_PERINSTANCE_PROPERTY_SOURCES ()->GetPropertySourceAt (&propName) ;
                    if ( pPropSrc == NULL ) {
                        if ( GET_OPM_PERINSTANCE_PROPERTY_SOURCES ()->SetPropertySourceAt (&propName, (*ppEntry)->pPropSrc) == false )
                            _com_issue_error (E_FAIL) ;
                    } else {
                        (*ppEntry)->pPropSrc->Release () ;
                        (*ppEntry)->pPropSrc =pPropSrc ;
                        pPropSrc =NULL ; //- Don't call release
                    }
                    if( GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL ((*ppEntry)->pClass)->AddObjectPropertySourceName (&propName) == false )
                        _com_issue_error (E_FAIL) ;
                }
            }
        }
    }
    virtual ~GcRxDynPropManager () {
        _OPM_DYNPROP_ENTRY **m_ppOpmObjMapEntryFirst =&__pOpmObjMapEntryFirst + 1 ;
        _OPM_DYNPROP_ENTRY **m_ppOpmObjMapEntryLast =&__pOpmObjMapEntryLast ;
        for ( _OPM_DYNPROP_ENTRY **ppEntry =m_ppOpmObjMapEntryFirst ; ppEntry < m_ppOpmObjMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                if ( *((*ppEntry)->pclsid) == __uuidof (IDynamicProperty2) || *((*ppEntry)->pclsid) == __uuidof (IDynamicProperty) ) {
                    //- Dynamic properties via the Property Manager
                    ATLASSERT( !((*ppEntry)->pClass && (*ppEntry)->strCmd) ) ;
                    ATLASSERT( (*ppEntry)->pClass || (*ppEntry)->strCmd ) ;
                    CComPtr<IPropertyManager> pPropMan ;
                    if ( (*ppEntry)->pClass != NULL && (*ppEntry)->pClass == GcDbDatabase::desc () ) {
                        //- Zero Selection property
                        if ( (pPropMan =GET_OPMEXTENSION_CREATE_PROTOCOL ()->CreateOPMObjectProtocol (NULL, 2)->GetPropertyManager ()) == NULL )
                            _com_issue_error (E_FAIL) ;
                    } else if ( (*ppEntry)->pClass != NULL ) {
                        //- Class property
                        if ( (pPropMan =GET_OPMPROPERTY_MANAGER ((*ppEntry)->pClass)) == NULL )
                            _com_issue_error (E_FAIL) ;
                    } else {
                        //- Command property
                        if ( GET_OPMEXTENSION_CREATE_PROTOCOL ()->GetOPMManager ((*ppEntry)->strCmd, &pPropMan) == FALSE ) {
                            if ( (pPropMan =GET_OPM_COMMAND_PROPERTY_MANAGER ((*ppEntry)->strCmd)) == NULL )
                                _com_issue_error (E_FAIL) ;
                        }
                    }
                    if ( (*ppEntry)->pProp != NULL ) {
                        _com_util::CheckError (pPropMan->RemoveProperty ((*ppEntry)->pProp)) ;
                        (*ppEntry)->pProp->Release () ;
                    }
                } else if ( *((*ppEntry)->pclsid) == __uuidof (IPropertySource) ) {
                    //- Per Instance Property
                    ATLASSERT( (*ppEntry)->pClass ) ;
                    CComBSTR propName ;
                    (*ppEntry)->pPropSrc->get_Name (&propName) ;
                    if ( GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL ((*ppEntry)->pClass)->RemoveObjectPropertySourceName (&propName) == false )
                        _com_issue_error (E_FAIL) ;
                    if ( (*ppEntry)->pPropSrc->Release () <= 1 ) {
                        if ( GET_OPM_PERINSTANCE_PROPERTY_SOURCES()->RemovePropertySourceAt (&propName) == false )
                            _com_issue_error (E_FAIL) ;
                    }
                }
            }
        }
    }
} ;
