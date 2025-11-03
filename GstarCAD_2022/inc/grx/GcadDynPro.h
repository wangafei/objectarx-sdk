

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Jun 20 17:34:59 2011
 */
/* Compiler settings for ..\lib\IcadDynPro\IcadDynPro.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IcadDynPro_h__
#define __IcadDynPro_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDynamicProperty_FWD_DEFINED__
#define __IDynamicProperty_FWD_DEFINED__
typedef interface IDynamicProperty IDynamicProperty;
#endif 	/* __IDynamicProperty_FWD_DEFINED__ */


#ifndef __IDynamicProperty2_FWD_DEFINED__
#define __IDynamicProperty2_FWD_DEFINED__
typedef interface IDynamicProperty2 IDynamicProperty2;
#endif 	/* __IDynamicProperty2_FWD_DEFINED__ */


#ifndef __IDynamicEnumProperty_FWD_DEFINED__
#define __IDynamicEnumProperty_FWD_DEFINED__
typedef interface IDynamicEnumProperty IDynamicEnumProperty;
#endif 	/* __IDynamicEnumProperty_FWD_DEFINED__ */


#ifndef __IDynamicPropertyNotify_FWD_DEFINED__
#define __IDynamicPropertyNotify_FWD_DEFINED__
typedef interface IDynamicPropertyNotify IDynamicPropertyNotify;
#endif 	/* __IDynamicPropertyNotify_FWD_DEFINED__ */


#ifndef __IDynamicPropertyNotify2_FWD_DEFINED__
#define __IDynamicPropertyNotify2_FWD_DEFINED__
typedef interface IDynamicPropertyNotify2 IDynamicPropertyNotify2;
#endif 	/* __IDynamicPropertyNotify2_FWD_DEFINED__ */


#ifndef __IPropertyManager_FWD_DEFINED__
#define __IPropertyManager_FWD_DEFINED__
typedef interface IPropertyManager IPropertyManager;
#endif 	/* __IPropertyManager_FWD_DEFINED__ */


#ifndef __DynamicProperty_FWD_DEFINED__
#define __DynamicProperty_FWD_DEFINED__

#ifdef __cplusplus
typedef class DynamicProperty DynamicProperty;
#else
typedef struct DynamicProperty DynamicProperty;
#endif /* __cplusplus */

#endif 	/* __DynamicProperty_FWD_DEFINED__ */


#ifndef __DynamicProperty2_FWD_DEFINED__
#define __DynamicProperty2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DynamicProperty2 DynamicProperty2;
#else
typedef struct DynamicProperty2 DynamicProperty2;
#endif /* __cplusplus */

#endif 	/* __DynamicProperty2_FWD_DEFINED__ */


#ifndef __DynamicEnumProperty_FWD_DEFINED__
#define __DynamicEnumProperty_FWD_DEFINED__

#ifdef __cplusplus
typedef class DynamicEnumProperty DynamicEnumProperty;
#else
typedef struct DynamicEnumProperty DynamicEnumProperty;
#endif /* __cplusplus */

#endif 	/* __DynamicEnumProperty_FWD_DEFINED__ */


#ifndef __DynamicPropertyNotify_FWD_DEFINED__
#define __DynamicPropertyNotify_FWD_DEFINED__

#ifdef __cplusplus
typedef class DynamicPropertyNotify DynamicPropertyNotify;
#else
typedef struct DynamicPropertyNotify DynamicPropertyNotify;
#endif /* __cplusplus */

#endif 	/* __DynamicPropertyNotify_FWD_DEFINED__ */


#ifndef __DynamicPropertyNotify2_FWD_DEFINED__
#define __DynamicPropertyNotify2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DynamicPropertyNotify2 DynamicPropertyNotify2;
#else
typedef struct DynamicPropertyNotify2 DynamicPropertyNotify2;
#endif /* __cplusplus */

#endif 	/* __DynamicPropertyNotify2_FWD_DEFINED__ */


#ifndef __PropertyManager_FWD_DEFINED__
#define __PropertyManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropertyManager PropertyManager;
#else
typedef struct PropertyManager PropertyManager;
#endif /* __cplusplus */

#endif 	/* __PropertyManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IcadDynPro_0000_0000 */
/* [local] */ 

typedef int PROPCAT;




extern RPC_IF_HANDLE __MIDL_itf_IcadDynPro_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IcadDynPro_0000_0000_v0_0_s_ifspec;

#ifndef __IDynamicProperty_INTERFACE_DEFINED__
#define __IDynamicProperty_INTERFACE_DEFINED__

/* interface IDynamicProperty */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDynamicProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61DFD93C-DB73-4366-ADA8-5C55289D8FE6")
    IDynamicProperty : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGUID( 
            GUID *propGUID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDisplayName( 
            BSTR *bstrName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropertyEnabled( 
            LONG_PTR objectID,
            BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropertyReadOnly( 
            BOOL *pbReadonly) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            BSTR *bstrName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentValueName( 
            BSTR *pbstrName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentValueType( 
            VARTYPE *pVarType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentValueData( 
            LONG_PTR objectID,
            VARIANT *pvarData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCurrentValueData( 
            LONG_PTR objectID,
            const VARIANT varData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connect( 
            IDynamicPropertyNotify *pSink) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDynamicPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDynamicProperty * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDynamicProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDynamicProperty * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IDynamicProperty * This,
            GUID *propGUID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IDynamicProperty * This,
            BSTR *bstrName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropertyEnabled )( 
            IDynamicProperty * This,
            LONG_PTR objectID,
            BOOL *pbEnabled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropertyReadOnly )( 
            IDynamicProperty * This,
            BOOL *pbReadonly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IDynamicProperty * This,
            BSTR *bstrName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentValueName )( 
            IDynamicProperty * This,
            BSTR *pbstrName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentValueType )( 
            IDynamicProperty * This,
            VARTYPE *pVarType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentValueData )( 
            IDynamicProperty * This,
            LONG_PTR objectID,
            VARIANT *pvarData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCurrentValueData )( 
            IDynamicProperty * This,
            LONG_PTR objectID,
            const VARIANT varData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IDynamicProperty * This,
            IDynamicPropertyNotify *pSink);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IDynamicProperty * This);
        
        END_INTERFACE
    } IDynamicPropertyVtbl;

    interface IDynamicProperty
    {
        CONST_VTBL struct IDynamicPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDynamicProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDynamicProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDynamicProperty_GetGUID(This,propGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,propGUID) ) 

#define IDynamicProperty_GetDisplayName(This,bstrName)	\
    ( (This)->lpVtbl -> GetDisplayName(This,bstrName) ) 

#define IDynamicProperty_IsPropertyEnabled(This,objectID,pbEnabled)	\
    ( (This)->lpVtbl -> IsPropertyEnabled(This,objectID,pbEnabled) ) 

#define IDynamicProperty_IsPropertyReadOnly(This,pbReadonly)	\
    ( (This)->lpVtbl -> IsPropertyReadOnly(This,pbReadonly) ) 

#define IDynamicProperty_GetDescription(This,bstrName)	\
    ( (This)->lpVtbl -> GetDescription(This,bstrName) ) 

#define IDynamicProperty_GetCurrentValueName(This,pbstrName)	\
    ( (This)->lpVtbl -> GetCurrentValueName(This,pbstrName) ) 

#define IDynamicProperty_GetCurrentValueType(This,pVarType)	\
    ( (This)->lpVtbl -> GetCurrentValueType(This,pVarType) ) 

#define IDynamicProperty_GetCurrentValueData(This,objectID,pvarData)	\
    ( (This)->lpVtbl -> GetCurrentValueData(This,objectID,pvarData) ) 

#define IDynamicProperty_SetCurrentValueData(This,objectID,varData)	\
    ( (This)->lpVtbl -> SetCurrentValueData(This,objectID,varData) ) 

#define IDynamicProperty_Connect(This,pSink)	\
    ( (This)->lpVtbl -> Connect(This,pSink) ) 

#define IDynamicProperty_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDynamicProperty_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IcadDynPro_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_IcadDynPro_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IcadDynPro_0000_0001_v0_0_s_ifspec;

#ifndef __IDynamicProperty2_INTERFACE_DEFINED__
#define __IDynamicProperty2_INTERFACE_DEFINED__

/* interface IDynamicProperty2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDynamicProperty2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("57782A79-3355-4ef8-9CF6-CF8296D2CD3A")
    IDynamicProperty2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGUID( 
            GUID *propGUID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDisplayName( 
            BSTR *bstrName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropertyEnabled( 
            LONG_PTR objectID,
            BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropertyReadOnly( 
            BOOL *pbReadonly) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            BSTR *bstrName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentValueName( 
            BSTR *pbstrName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentValueType( 
            VARTYPE *pVarType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentValueData( 
            LONG_PTR objectID,
            VARIANT *pvarData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCurrentValueData( 
            LONG_PTR objectID,
            const VARIANT varData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Connect( 
            IDynamicPropertyNotify2 *pSink) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDynamicProperty2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDynamicProperty2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDynamicProperty2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDynamicProperty2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IDynamicProperty2 * This,
            GUID *propGUID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IDynamicProperty2 * This,
            BSTR *bstrName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropertyEnabled )( 
            IDynamicProperty2 * This,
            LONG_PTR objectID,
            BOOL *pbEnabled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropertyReadOnly )( 
            IDynamicProperty2 * This,
            BOOL *pbReadonly);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IDynamicProperty2 * This,
            BSTR *bstrName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentValueName )( 
            IDynamicProperty2 * This,
            BSTR *pbstrName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentValueType )( 
            IDynamicProperty2 * This,
            VARTYPE *pVarType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentValueData )( 
            IDynamicProperty2 * This,
            LONG_PTR objectID,
            VARIANT *pvarData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCurrentValueData )( 
            IDynamicProperty2 * This,
            LONG_PTR objectID,
            const VARIANT varData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IDynamicProperty2 * This,
            IDynamicPropertyNotify2 *pSink);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IDynamicProperty2 * This);
        
        END_INTERFACE
    } IDynamicProperty2Vtbl;

    interface IDynamicProperty2
    {
        CONST_VTBL struct IDynamicProperty2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicProperty2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDynamicProperty2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDynamicProperty2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDynamicProperty2_GetGUID(This,propGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,propGUID) ) 

#define IDynamicProperty2_GetDisplayName(This,bstrName)	\
    ( (This)->lpVtbl -> GetDisplayName(This,bstrName) ) 

#define IDynamicProperty2_IsPropertyEnabled(This,objectID,pbEnabled)	\
    ( (This)->lpVtbl -> IsPropertyEnabled(This,objectID,pbEnabled) ) 

#define IDynamicProperty2_IsPropertyReadOnly(This,pbReadonly)	\
    ( (This)->lpVtbl -> IsPropertyReadOnly(This,pbReadonly) ) 

#define IDynamicProperty2_GetDescription(This,bstrName)	\
    ( (This)->lpVtbl -> GetDescription(This,bstrName) ) 

#define IDynamicProperty2_GetCurrentValueName(This,pbstrName)	\
    ( (This)->lpVtbl -> GetCurrentValueName(This,pbstrName) ) 

#define IDynamicProperty2_GetCurrentValueType(This,pVarType)	\
    ( (This)->lpVtbl -> GetCurrentValueType(This,pVarType) ) 

#define IDynamicProperty2_GetCurrentValueData(This,objectID,pvarData)	\
    ( (This)->lpVtbl -> GetCurrentValueData(This,objectID,pvarData) ) 

#define IDynamicProperty2_SetCurrentValueData(This,objectID,varData)	\
    ( (This)->lpVtbl -> SetCurrentValueData(This,objectID,varData) ) 

#define IDynamicProperty2_Connect(This,pSink)	\
    ( (This)->lpVtbl -> Connect(This,pSink) ) 

#define IDynamicProperty2_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDynamicProperty2_INTERFACE_DEFINED__ */


#ifndef __IDynamicEnumProperty_INTERFACE_DEFINED__
#define __IDynamicEnumProperty_INTERFACE_DEFINED__

/* interface IDynamicEnumProperty */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDynamicEnumProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("78E3140A-A1E5-4B1B-B137-73C495C92BBB")
    IDynamicEnumProperty : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNumPropertyValues( 
            LONG *numValues) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropValueName( 
            LONG index,
            BSTR *valueName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropValueData( 
            LONG index,
            VARIANT *valueName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDynamicEnumPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDynamicEnumProperty * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDynamicEnumProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDynamicEnumProperty * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNumPropertyValues )( 
            IDynamicEnumProperty * This,
            LONG *numValues);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropValueName )( 
            IDynamicEnumProperty * This,
            LONG index,
            BSTR *valueName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropValueData )( 
            IDynamicEnumProperty * This,
            LONG index,
            VARIANT *valueName);
        
        END_INTERFACE
    } IDynamicEnumPropertyVtbl;

    interface IDynamicEnumProperty
    {
        CONST_VTBL struct IDynamicEnumPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicEnumProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDynamicEnumProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDynamicEnumProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDynamicEnumProperty_GetNumPropertyValues(This,numValues)	\
    ( (This)->lpVtbl -> GetNumPropertyValues(This,numValues) ) 

#define IDynamicEnumProperty_GetPropValueName(This,index,valueName)	\
    ( (This)->lpVtbl -> GetPropValueName(This,index,valueName) ) 

#define IDynamicEnumProperty_GetPropValueData(This,index,valueName)	\
    ( (This)->lpVtbl -> GetPropValueData(This,index,valueName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDynamicEnumProperty_INTERFACE_DEFINED__ */


#ifndef __IDynamicPropertyNotify_INTERFACE_DEFINED__
#define __IDynamicPropertyNotify_INTERFACE_DEFINED__

/* interface IDynamicPropertyNotify */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDynamicPropertyNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("023B1E0A-C4F2-4E23-8DE2-70FABF5E2936")
    IDynamicPropertyNotify : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChanged( 
            IDynamicProperty *pDynamicProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentSelectionSet( 
            VARIANT *pSelection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDynamicPropertyNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDynamicPropertyNotify * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDynamicPropertyNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDynamicPropertyNotify * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnChanged )( 
            IDynamicPropertyNotify * This,
            IDynamicProperty *pDynamicProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentSelectionSet )( 
            IDynamicPropertyNotify * This,
            VARIANT *pSelection);
        
        END_INTERFACE
    } IDynamicPropertyNotifyVtbl;

    interface IDynamicPropertyNotify
    {
        CONST_VTBL struct IDynamicPropertyNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicPropertyNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDynamicPropertyNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDynamicPropertyNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDynamicPropertyNotify_OnChanged(This,pDynamicProperty)	\
    ( (This)->lpVtbl -> OnChanged(This,pDynamicProperty) ) 

#define IDynamicPropertyNotify_GetCurrentSelectionSet(This,pSelection)	\
    ( (This)->lpVtbl -> GetCurrentSelectionSet(This,pSelection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDynamicPropertyNotify_INTERFACE_DEFINED__ */


#ifndef __IDynamicPropertyNotify2_INTERFACE_DEFINED__
#define __IDynamicPropertyNotify2_INTERFACE_DEFINED__

/* interface IDynamicPropertyNotify2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDynamicPropertyNotify2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A70EEB10-ADC8-4157-9B71-CAED48B50BA3")
    IDynamicPropertyNotify2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChanged( 
            IDynamicProperty2 *pDynamicProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentSelectionSet( 
            VARIANT *pSelection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDynamicPropertyNotify2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDynamicPropertyNotify2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDynamicPropertyNotify2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDynamicPropertyNotify2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnChanged )( 
            IDynamicPropertyNotify2 * This,
            IDynamicProperty2 *pDynamicProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentSelectionSet )( 
            IDynamicPropertyNotify2 * This,
            VARIANT *pSelection);
        
        END_INTERFACE
    } IDynamicPropertyNotify2Vtbl;

    interface IDynamicPropertyNotify2
    {
        CONST_VTBL struct IDynamicPropertyNotify2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDynamicPropertyNotify2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDynamicPropertyNotify2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDynamicPropertyNotify2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDynamicPropertyNotify2_OnChanged(This,pDynamicProperty)	\
    ( (This)->lpVtbl -> OnChanged(This,pDynamicProperty) ) 

#define IDynamicPropertyNotify2_GetCurrentSelectionSet(This,pSelection)	\
    ( (This)->lpVtbl -> GetCurrentSelectionSet(This,pSelection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDynamicPropertyNotify2_INTERFACE_DEFINED__ */


#ifndef __IPropertyManager_INTERFACE_DEFINED__
#define __IPropertyManager_INTERFACE_DEFINED__

/* interface IPropertyManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPropertyManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DFDF9AF-D380-4497-97B8-6B8FC5AD3A0C")
    IPropertyManager : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddProperty( 
            IDynamicProperty *pProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveProperty( 
            IDynamicProperty *pProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDynamicProperty( 
            LONG index,
            IDynamicProperty **pProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDynamicPropertyByName( 
            BSTR propName,
            IDynamicProperty **pProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDynamicPropertyCount( 
            LONG *count) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDynamicClassInfo( 
            IUnknown *pObj,
            ITypeInfo **pptiDynamic,
            DWORD *dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropertyManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropertyManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropertyManager * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddProperty )( 
            IPropertyManager * This,
            IDynamicProperty *pProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveProperty )( 
            IPropertyManager * This,
            IDynamicProperty *pProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDynamicProperty )( 
            IPropertyManager * This,
            LONG index,
            IDynamicProperty **pProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDynamicPropertyByName )( 
            IPropertyManager * This,
            BSTR propName,
            IDynamicProperty **pProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDynamicPropertyCount )( 
            IPropertyManager * This,
            LONG *count);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDynamicClassInfo )( 
            IPropertyManager * This,
            IUnknown *pObj,
            ITypeInfo **pptiDynamic,
            DWORD *dwCookie);
        
        END_INTERFACE
    } IPropertyManagerVtbl;

    interface IPropertyManager
    {
        CONST_VTBL struct IPropertyManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPropertyManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPropertyManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPropertyManager_AddProperty(This,pProperty)	\
    ( (This)->lpVtbl -> AddProperty(This,pProperty) ) 

#define IPropertyManager_RemoveProperty(This,pProperty)	\
    ( (This)->lpVtbl -> RemoveProperty(This,pProperty) ) 

#define IPropertyManager_GetDynamicProperty(This,index,pProperty)	\
    ( (This)->lpVtbl -> GetDynamicProperty(This,index,pProperty) ) 

#define IPropertyManager_GetDynamicPropertyByName(This,propName,pProperty)	\
    ( (This)->lpVtbl -> GetDynamicPropertyByName(This,propName,pProperty) ) 

#define IPropertyManager_GetDynamicPropertyCount(This,count)	\
    ( (This)->lpVtbl -> GetDynamicPropertyCount(This,count) ) 

#define IPropertyManager_GetDynamicClassInfo(This,pObj,pptiDynamic,dwCookie)	\
    ( (This)->lpVtbl -> GetDynamicClassInfo(This,pObj,pptiDynamic,dwCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyManager_INTERFACE_DEFINED__ */



#ifndef __ICADDYNPROLib_LIBRARY_DEFINED__
#define __ICADDYNPROLib_LIBRARY_DEFINED__

/* library ICADDYNPROLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ICADDYNPROLib;

EXTERN_C const CLSID CLSID_DynamicProperty;

#ifdef __cplusplus

class DECLSPEC_UUID("19BD0FA2-739C-4158-A34D-1DF16A4708C1")
DynamicProperty;
#endif

EXTERN_C const CLSID CLSID_DynamicProperty2;

#ifdef __cplusplus

class DECLSPEC_UUID("658182BD-3B62-4cb9-978D-487670D19F3C")
DynamicProperty2;
#endif

EXTERN_C const CLSID CLSID_DynamicEnumProperty;

#ifdef __cplusplus

class DECLSPEC_UUID("2082AA20-7D87-4E4D-B996-2B4E4A2F119F")
DynamicEnumProperty;
#endif

EXTERN_C const CLSID CLSID_DynamicPropertyNotify;

#ifdef __cplusplus

class DECLSPEC_UUID("53DEC183-FF64-43D4-B377-A6547B7B0944")
DynamicPropertyNotify;
#endif

EXTERN_C const CLSID CLSID_DynamicPropertyNotify2;

#ifdef __cplusplus

class DECLSPEC_UUID("039C9F38-B02C-4e69-A560-16EE91076E10")
DynamicPropertyNotify2;
#endif

EXTERN_C const CLSID CLSID_PropertyManager;

#ifdef __cplusplus

class DECLSPEC_UUID("D5950DE8-7B0A-4995-BCF7-1CF7FF4C9C21")
PropertyManager;
#endif
#endif /* __ICADDYNPROLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


