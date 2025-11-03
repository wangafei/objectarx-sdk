

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Mar 05 17:08:46 2013
 */
/* Compiler settings for ..\..\src\gcvba\PlotSupport.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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

#ifndef __PlotSupport_h__
#define __PlotSupport_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIcadPlotterPen_FWD_DEFINED__
#define __IIcadPlotterPen_FWD_DEFINED__
typedef interface IIcadPlotterPen IIcadPlotterPen;
#endif 	/* __IIcadPlotterPen_FWD_DEFINED__ */


#ifndef __IIcadPlotterPens_FWD_DEFINED__
#define __IIcadPlotterPens_FWD_DEFINED__
typedef interface IIcadPlotterPens IIcadPlotterPens;
#endif 	/* __IIcadPlotterPens_FWD_DEFINED__ */


#ifndef __IIcadPlotDeviceConfig_FWD_DEFINED__
#define __IIcadPlotDeviceConfig_FWD_DEFINED__
typedef interface IIcadPlotDeviceConfig IIcadPlotDeviceConfig;
#endif 	/* __IIcadPlotDeviceConfig_FWD_DEFINED__ */


#ifndef __IIcadPlotProperties_FWD_DEFINED__
#define __IIcadPlotProperties_FWD_DEFINED__
typedef interface IIcadPlotProperties IIcadPlotProperties;
#endif 	/* __IIcadPlotProperties_FWD_DEFINED__ */


#ifndef __IIcadPlotManager_FWD_DEFINED__
#define __IIcadPlotManager_FWD_DEFINED__
typedef interface IIcadPlotManager IIcadPlotManager;
#endif 	/* __IIcadPlotManager_FWD_DEFINED__ */


#ifndef __IIcadPlotRegManager_FWD_DEFINED__
#define __IIcadPlotRegManager_FWD_DEFINED__
typedef interface IIcadPlotRegManager IIcadPlotRegManager;
#endif 	/* __IIcadPlotRegManager_FWD_DEFINED__ */


#ifndef __PlotterPen_FWD_DEFINED__
#define __PlotterPen_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlotterPen PlotterPen;
#else
typedef struct PlotterPen PlotterPen;
#endif /* __cplusplus */

#endif 	/* __PlotterPen_FWD_DEFINED__ */


#ifndef __PlotterPens_FWD_DEFINED__
#define __PlotterPens_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlotterPens PlotterPens;
#else
typedef struct PlotterPens PlotterPens;
#endif /* __cplusplus */

#endif 	/* __PlotterPens_FWD_DEFINED__ */


#ifndef __PlotDeviceConfig_FWD_DEFINED__
#define __PlotDeviceConfig_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlotDeviceConfig PlotDeviceConfig;
#else
typedef struct PlotDeviceConfig PlotDeviceConfig;
#endif /* __cplusplus */

#endif 	/* __PlotDeviceConfig_FWD_DEFINED__ */


#ifndef __PlotProperties_FWD_DEFINED__
#define __PlotProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlotProperties PlotProperties;
#else
typedef struct PlotProperties PlotProperties;
#endif /* __cplusplus */

#endif 	/* __PlotProperties_FWD_DEFINED__ */


#ifndef __PlotManager_FWD_DEFINED__
#define __PlotManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlotManager PlotManager;
#else
typedef struct PlotManager PlotManager;
#endif /* __cplusplus */

#endif 	/* __PlotManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIcadPlotterPen_INTERFACE_DEFINED__
#define __IIcadPlotterPen_INTERFACE_DEFINED__

/* interface IIcadPlotterPen */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIcadPlotterPen;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8011c1c4-7e36-11d1-bc5a-0060089608a4")
    IIcadPlotterPen : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BGRColor( 
            /* [retval][out] */ COLORREF *color) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BGRColor( 
            /* [in] */ COLORREF color) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ACIColor( 
            /* [in] */ int index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Weight( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Weight( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Number( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Number( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dummy( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dummy( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LineType( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LineType( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Screening( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Screening( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Speed( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Speed( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dither( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dither( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Grayscale( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Grayscale( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Adaptive( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Adaptive( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_End( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_End( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Join( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Join( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Fill( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Fill( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pen( 
            /* [retval][out] */ VARIANT *pen) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ACI2BGR( 
            /* [in] */ int index,
            /* [retval][out] */ COLORREF *color) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIcadPlotterPenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIcadPlotterPen * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIcadPlotterPen * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIcadPlotterPen * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIcadPlotterPen * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIcadPlotterPen * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIcadPlotterPen * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIcadPlotterPen * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BGRColor )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ COLORREF *color);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BGRColor )( 
            IIcadPlotterPen * This,
            /* [in] */ COLORREF color);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ACIColor )( 
            IIcadPlotterPen * This,
            /* [in] */ int index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Weight )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Weight )( 
            IIcadPlotterPen * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Number )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Number )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dummy )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dummy )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineType )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineType )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Screening )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Screening )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Speed )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Speed )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dither )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dither )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Grayscale )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Grayscale )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Adaptive )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Adaptive )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_End )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_End )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Join )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Join )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fill )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fill )( 
            IIcadPlotterPen * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pen )( 
            IIcadPlotterPen * This,
            /* [retval][out] */ VARIANT *pen);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ACI2BGR )( 
            IIcadPlotterPen * This,
            /* [in] */ int index,
            /* [retval][out] */ COLORREF *color);
        
        END_INTERFACE
    } IIcadPlotterPenVtbl;

    interface IIcadPlotterPen
    {
        CONST_VTBL struct IIcadPlotterPenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIcadPlotterPen_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIcadPlotterPen_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIcadPlotterPen_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIcadPlotterPen_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIcadPlotterPen_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIcadPlotterPen_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIcadPlotterPen_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIcadPlotterPen_get_BGRColor(This,color)	\
    ( (This)->lpVtbl -> get_BGRColor(This,color) ) 

#define IIcadPlotterPen_put_BGRColor(This,color)	\
    ( (This)->lpVtbl -> put_BGRColor(This,color) ) 

#define IIcadPlotterPen_put_ACIColor(This,index)	\
    ( (This)->lpVtbl -> put_ACIColor(This,index) ) 

#define IIcadPlotterPen_get_Weight(This,pVal)	\
    ( (This)->lpVtbl -> get_Weight(This,pVal) ) 

#define IIcadPlotterPen_put_Weight(This,newVal)	\
    ( (This)->lpVtbl -> put_Weight(This,newVal) ) 

#define IIcadPlotterPen_get_Number(This,pVal)	\
    ( (This)->lpVtbl -> get_Number(This,pVal) ) 

#define IIcadPlotterPen_put_Number(This,newVal)	\
    ( (This)->lpVtbl -> put_Number(This,newVal) ) 

#define IIcadPlotterPen_get_Dummy(This,pVal)	\
    ( (This)->lpVtbl -> get_Dummy(This,pVal) ) 

#define IIcadPlotterPen_put_Dummy(This,newVal)	\
    ( (This)->lpVtbl -> put_Dummy(This,newVal) ) 

#define IIcadPlotterPen_get_LineType(This,pVal)	\
    ( (This)->lpVtbl -> get_LineType(This,pVal) ) 

#define IIcadPlotterPen_put_LineType(This,newVal)	\
    ( (This)->lpVtbl -> put_LineType(This,newVal) ) 

#define IIcadPlotterPen_get_Screening(This,pVal)	\
    ( (This)->lpVtbl -> get_Screening(This,pVal) ) 

#define IIcadPlotterPen_put_Screening(This,newVal)	\
    ( (This)->lpVtbl -> put_Screening(This,newVal) ) 

#define IIcadPlotterPen_get_Speed(This,pVal)	\
    ( (This)->lpVtbl -> get_Speed(This,pVal) ) 

#define IIcadPlotterPen_put_Speed(This,newVal)	\
    ( (This)->lpVtbl -> put_Speed(This,newVal) ) 

#define IIcadPlotterPen_get_Dither(This,pVal)	\
    ( (This)->lpVtbl -> get_Dither(This,pVal) ) 

#define IIcadPlotterPen_put_Dither(This,newVal)	\
    ( (This)->lpVtbl -> put_Dither(This,newVal) ) 

#define IIcadPlotterPen_get_Grayscale(This,pVal)	\
    ( (This)->lpVtbl -> get_Grayscale(This,pVal) ) 

#define IIcadPlotterPen_put_Grayscale(This,newVal)	\
    ( (This)->lpVtbl -> put_Grayscale(This,newVal) ) 

#define IIcadPlotterPen_get_Adaptive(This,pVal)	\
    ( (This)->lpVtbl -> get_Adaptive(This,pVal) ) 

#define IIcadPlotterPen_put_Adaptive(This,newVal)	\
    ( (This)->lpVtbl -> put_Adaptive(This,newVal) ) 

#define IIcadPlotterPen_get_End(This,pVal)	\
    ( (This)->lpVtbl -> get_End(This,pVal) ) 

#define IIcadPlotterPen_put_End(This,newVal)	\
    ( (This)->lpVtbl -> put_End(This,newVal) ) 

#define IIcadPlotterPen_get_Join(This,pVal)	\
    ( (This)->lpVtbl -> get_Join(This,pVal) ) 

#define IIcadPlotterPen_put_Join(This,newVal)	\
    ( (This)->lpVtbl -> put_Join(This,newVal) ) 

#define IIcadPlotterPen_get_Fill(This,pVal)	\
    ( (This)->lpVtbl -> get_Fill(This,pVal) ) 

#define IIcadPlotterPen_put_Fill(This,newVal)	\
    ( (This)->lpVtbl -> put_Fill(This,newVal) ) 

#define IIcadPlotterPen_get_pen(This,pen)	\
    ( (This)->lpVtbl -> get_pen(This,pen) ) 

#define IIcadPlotterPen_get_ACI2BGR(This,index,color)	\
    ( (This)->lpVtbl -> get_ACI2BGR(This,index,color) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIcadPlotterPen_INTERFACE_DEFINED__ */


#ifndef __IIcadPlotterPens_INTERFACE_DEFINED__
#define __IIcadPlotterPens_INTERFACE_DEFINED__

/* interface IIcadPlotterPens */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIcadPlotterPens;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8011c1c3-7e36-11d1-bc5a-0060089608a4")
    IIcadPlotterPens : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT index,
            /* [retval][out] */ IIcadPlotterPen **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Item( 
            /* [in] */ VARIANT index,
            /* [in] */ IIcadPlotterPen *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mode( 
            /* [retval][out] */ VARIANT *mode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_mode( 
            /* [in] */ VARIANT mode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIcadPlotterPensVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIcadPlotterPens * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIcadPlotterPens * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIcadPlotterPens * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIcadPlotterPens * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIcadPlotterPens * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIcadPlotterPens * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIcadPlotterPens * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IIcadPlotterPens * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IIcadPlotterPens * This,
            /* [in] */ VARIANT index,
            /* [retval][out] */ IIcadPlotterPen **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Item )( 
            IIcadPlotterPens * This,
            /* [in] */ VARIANT index,
            /* [in] */ IIcadPlotterPen *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mode )( 
            IIcadPlotterPens * This,
            /* [retval][out] */ VARIANT *mode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mode )( 
            IIcadPlotterPens * This,
            /* [in] */ VARIANT mode);
        
        END_INTERFACE
    } IIcadPlotterPensVtbl;

    interface IIcadPlotterPens
    {
        CONST_VTBL struct IIcadPlotterPensVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIcadPlotterPens_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIcadPlotterPens_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIcadPlotterPens_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIcadPlotterPens_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIcadPlotterPens_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIcadPlotterPens_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIcadPlotterPens_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIcadPlotterPens_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IIcadPlotterPens_get_Item(This,index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,index,pVal) ) 

#define IIcadPlotterPens_put_Item(This,index,pVal)	\
    ( (This)->lpVtbl -> put_Item(This,index,pVal) ) 

#define IIcadPlotterPens_get_mode(This,mode)	\
    ( (This)->lpVtbl -> get_mode(This,mode) ) 

#define IIcadPlotterPens_put_mode(This,mode)	\
    ( (This)->lpVtbl -> put_mode(This,mode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIcadPlotterPens_INTERFACE_DEFINED__ */


#ifndef __IIcadPlotDeviceConfig_INTERFACE_DEFINED__
#define __IIcadPlotDeviceConfig_INTERFACE_DEFINED__

/* interface IIcadPlotDeviceConfig */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIcadPlotDeviceConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8011c1c2-0000-11d1-bc5a-0000089608a4")
    IIcadPlotDeviceConfig : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportPC3( 
            BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportPC3( 
            BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDriverData( 
            BYTE *data,
            int size,
            int driverVersion,
            int specVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Driver( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlotName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DriverString( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DriverString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StyleFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GdiTextOut( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GdiTextOut( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TTFTextFill( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TTFTextFill( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DriverData( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DriverData( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrintQuality( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetScale( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDefaultSource( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetColor( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLogPixels( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTTOption( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDitherType( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMediaType( 
            int v) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetYResolution( 
            int v) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PortName( 
            /* [in] */ BSTR v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PortName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BaudRate( 
            unsigned long v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaudRate( 
            /* [retval][out] */ unsigned long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Input( 
            unsigned long v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Input( 
            /* [retval][out] */ unsigned long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Output( 
            unsigned long v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Output( 
            /* [retval][out] */ unsigned long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Protocol( 
            /* [in] */ BSTR v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Protocol( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FlowControl( 
            /* [in] */ BSTR v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FlowControl( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Overwrite( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Overwrite( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpfile( 
            /* [in] */ BSTR v) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpfile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpsheet( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpsheet( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmporiginX( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmporiginX( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmporiginY( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmporiginY( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpscaleX( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpscaleX( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpscaleY( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpscaleY( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpsheetCustom( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpsheetCustom( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpsheetModify( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpsheetModify( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_pmpsheetFilter( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_pmpsheetFilter( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_rasterAndrenderDPI( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_rasterAndrenderDPI( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_oleDPI( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_oleDPI( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_globalDPI( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_globalDPI( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_colorDepth( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_colorDepth( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_colorMode( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_colorMode( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_vectorDPI( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_vectorDPI( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_dithering( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_dithering( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_mediaType( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mediaType( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_mediaSource( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mediaSource( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_mediaWidth( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mediaWidth( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_mediaDestination( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mediaDestination( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_mediaCutting( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mediaCutting( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportPMP( 
            BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportPMP( 
            BSTR filename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIcadPlotDeviceConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIcadPlotDeviceConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIcadPlotDeviceConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIcadPlotDeviceConfig * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportPC3 )( 
            IIcadPlotDeviceConfig * This,
            BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportPC3 )( 
            IIcadPlotDeviceConfig * This,
            BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDriverData )( 
            IIcadPlotDeviceConfig * This,
            BYTE *data,
            int size,
            int driverVersion,
            int specVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Driver )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlotName )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DriverString )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DriverString )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StyleFile )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GdiTextOut )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GdiTextOut )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TTFTextFill )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TTFTextFill )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DriverData )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DriverData )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPrintQuality )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetScale )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDefaultSource )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetColor )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLogPixels )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTTOption )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDitherType )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetYResolution )( 
            IIcadPlotDeviceConfig * This,
            int v);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PortName )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PortName )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BaudRate )( 
            IIcadPlotDeviceConfig * This,
            unsigned long v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaudRate )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ unsigned long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Input )( 
            IIcadPlotDeviceConfig * This,
            unsigned long v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Input )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ unsigned long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Output )( 
            IIcadPlotDeviceConfig * This,
            unsigned long v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Output )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ unsigned long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Protocol )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Protocol )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FlowControl )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FlowControl )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Overwrite )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Overwrite )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpfile )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpfile )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpsheet )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpsheet )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmporiginX )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmporiginX )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmporiginY )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmporiginY )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpscaleX )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpscaleX )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpscaleY )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpscaleY )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpsheetCustom )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpsheetCustom )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpsheetModify )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpsheetModify )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_pmpsheetFilter )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_pmpsheetFilter )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rasterAndrenderDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rasterAndrenderDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_oleDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_oleDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_globalDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_globalDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_colorDepth )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_colorDepth )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_colorMode )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_colorMode )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_vectorDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_vectorDPI )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_dithering )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_dithering )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mediaType )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mediaType )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mediaSource )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mediaSource )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mediaWidth )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mediaWidth )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mediaDestination )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mediaDestination )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mediaCutting )( 
            IIcadPlotDeviceConfig * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mediaCutting )( 
            IIcadPlotDeviceConfig * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportPMP )( 
            IIcadPlotDeviceConfig * This,
            BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportPMP )( 
            IIcadPlotDeviceConfig * This,
            BSTR filename);
        
        END_INTERFACE
    } IIcadPlotDeviceConfigVtbl;

    interface IIcadPlotDeviceConfig
    {
        CONST_VTBL struct IIcadPlotDeviceConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIcadPlotDeviceConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIcadPlotDeviceConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIcadPlotDeviceConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIcadPlotDeviceConfig_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIcadPlotDeviceConfig_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIcadPlotDeviceConfig_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIcadPlotDeviceConfig_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIcadPlotDeviceConfig_ImportPC3(This,filename)	\
    ( (This)->lpVtbl -> ImportPC3(This,filename) ) 

#define IIcadPlotDeviceConfig_ExportPC3(This,filename)	\
    ( (This)->lpVtbl -> ExportPC3(This,filename) ) 

#define IIcadPlotDeviceConfig_SetDriverData(This,data,size,driverVersion,specVersion)	\
    ( (This)->lpVtbl -> SetDriverData(This,data,size,driverVersion,specVersion) ) 

#define IIcadPlotDeviceConfig_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_Description(This,newVal)	\
    ( (This)->lpVtbl -> put_Description(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_Driver(This,pVal)	\
    ( (This)->lpVtbl -> get_Driver(This,pVal) ) 

#define IIcadPlotDeviceConfig_get_PlotName(This,pVal)	\
    ( (This)->lpVtbl -> get_PlotName(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_DriverString(This,newVal)	\
    ( (This)->lpVtbl -> put_DriverString(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_DriverString(This,pVal)	\
    ( (This)->lpVtbl -> get_DriverString(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_StyleFile(This,newVal)	\
    ( (This)->lpVtbl -> put_StyleFile(This,newVal) ) 

#define IIcadPlotDeviceConfig_put_GdiTextOut(This,newVal)	\
    ( (This)->lpVtbl -> put_GdiTextOut(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_GdiTextOut(This,pVal)	\
    ( (This)->lpVtbl -> get_GdiTextOut(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_TTFTextFill(This,newVal)	\
    ( (This)->lpVtbl -> put_TTFTextFill(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_TTFTextFill(This,pVal)	\
    ( (This)->lpVtbl -> get_TTFTextFill(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_DriverData(This,newVal)	\
    ( (This)->lpVtbl -> put_DriverData(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_DriverData(This,pVal)	\
    ( (This)->lpVtbl -> get_DriverData(This,pVal) ) 

#define IIcadPlotDeviceConfig_SetPrintQuality(This,v)	\
    ( (This)->lpVtbl -> SetPrintQuality(This,v) ) 

#define IIcadPlotDeviceConfig_SetScale(This,v)	\
    ( (This)->lpVtbl -> SetScale(This,v) ) 

#define IIcadPlotDeviceConfig_SetDefaultSource(This,v)	\
    ( (This)->lpVtbl -> SetDefaultSource(This,v) ) 

#define IIcadPlotDeviceConfig_SetColor(This,v)	\
    ( (This)->lpVtbl -> SetColor(This,v) ) 

#define IIcadPlotDeviceConfig_SetLogPixels(This,v)	\
    ( (This)->lpVtbl -> SetLogPixels(This,v) ) 

#define IIcadPlotDeviceConfig_SetTTOption(This,v)	\
    ( (This)->lpVtbl -> SetTTOption(This,v) ) 

#define IIcadPlotDeviceConfig_SetDitherType(This,v)	\
    ( (This)->lpVtbl -> SetDitherType(This,v) ) 

#define IIcadPlotDeviceConfig_SetMediaType(This,v)	\
    ( (This)->lpVtbl -> SetMediaType(This,v) ) 

#define IIcadPlotDeviceConfig_SetYResolution(This,v)	\
    ( (This)->lpVtbl -> SetYResolution(This,v) ) 

#define IIcadPlotDeviceConfig_put_PortName(This,v)	\
    ( (This)->lpVtbl -> put_PortName(This,v) ) 

#define IIcadPlotDeviceConfig_get_PortName(This,pVal)	\
    ( (This)->lpVtbl -> get_PortName(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_BaudRate(This,v)	\
    ( (This)->lpVtbl -> put_BaudRate(This,v) ) 

#define IIcadPlotDeviceConfig_get_BaudRate(This,pVal)	\
    ( (This)->lpVtbl -> get_BaudRate(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_Input(This,v)	\
    ( (This)->lpVtbl -> put_Input(This,v) ) 

#define IIcadPlotDeviceConfig_get_Input(This,pVal)	\
    ( (This)->lpVtbl -> get_Input(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_Output(This,v)	\
    ( (This)->lpVtbl -> put_Output(This,v) ) 

#define IIcadPlotDeviceConfig_get_Output(This,pVal)	\
    ( (This)->lpVtbl -> get_Output(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_Protocol(This,v)	\
    ( (This)->lpVtbl -> put_Protocol(This,v) ) 

#define IIcadPlotDeviceConfig_get_Protocol(This,pVal)	\
    ( (This)->lpVtbl -> get_Protocol(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_FlowControl(This,v)	\
    ( (This)->lpVtbl -> put_FlowControl(This,v) ) 

#define IIcadPlotDeviceConfig_get_FlowControl(This,pVal)	\
    ( (This)->lpVtbl -> get_FlowControl(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_Overwrite(This,newVal)	\
    ( (This)->lpVtbl -> put_Overwrite(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_Overwrite(This,pVal)	\
    ( (This)->lpVtbl -> get_Overwrite(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpfile(This,v)	\
    ( (This)->lpVtbl -> put_pmpfile(This,v) ) 

#define IIcadPlotDeviceConfig_get_pmpfile(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpfile(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpsheet(This,newVal)	\
    ( (This)->lpVtbl -> put_pmpsheet(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmpsheet(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpsheet(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmporiginX(This,newVal)	\
    ( (This)->lpVtbl -> put_pmporiginX(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmporiginX(This,pVal)	\
    ( (This)->lpVtbl -> get_pmporiginX(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmporiginY(This,newVal)	\
    ( (This)->lpVtbl -> put_pmporiginY(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmporiginY(This,pVal)	\
    ( (This)->lpVtbl -> get_pmporiginY(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpscaleX(This,newVal)	\
    ( (This)->lpVtbl -> put_pmpscaleX(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmpscaleX(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpscaleX(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpscaleY(This,newVal)	\
    ( (This)->lpVtbl -> put_pmpscaleY(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmpscaleY(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpscaleY(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpsheetCustom(This,newVal)	\
    ( (This)->lpVtbl -> put_pmpsheetCustom(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmpsheetCustom(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpsheetCustom(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpsheetModify(This,newVal)	\
    ( (This)->lpVtbl -> put_pmpsheetModify(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmpsheetModify(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpsheetModify(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_pmpsheetFilter(This,newVal)	\
    ( (This)->lpVtbl -> put_pmpsheetFilter(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_pmpsheetFilter(This,pVal)	\
    ( (This)->lpVtbl -> get_pmpsheetFilter(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_rasterAndrenderDPI(This,newVal)	\
    ( (This)->lpVtbl -> put_rasterAndrenderDPI(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_rasterAndrenderDPI(This,pVal)	\
    ( (This)->lpVtbl -> get_rasterAndrenderDPI(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_oleDPI(This,newVal)	\
    ( (This)->lpVtbl -> put_oleDPI(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_oleDPI(This,pVal)	\
    ( (This)->lpVtbl -> get_oleDPI(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_globalDPI(This,newVal)	\
    ( (This)->lpVtbl -> put_globalDPI(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_globalDPI(This,pVal)	\
    ( (This)->lpVtbl -> get_globalDPI(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_colorDepth(This,newVal)	\
    ( (This)->lpVtbl -> put_colorDepth(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_colorDepth(This,pVal)	\
    ( (This)->lpVtbl -> get_colorDepth(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_colorMode(This,newVal)	\
    ( (This)->lpVtbl -> put_colorMode(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_colorMode(This,pVal)	\
    ( (This)->lpVtbl -> get_colorMode(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_vectorDPI(This,newVal)	\
    ( (This)->lpVtbl -> put_vectorDPI(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_vectorDPI(This,pVal)	\
    ( (This)->lpVtbl -> get_vectorDPI(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_dithering(This,newVal)	\
    ( (This)->lpVtbl -> put_dithering(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_dithering(This,pVal)	\
    ( (This)->lpVtbl -> get_dithering(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_mediaType(This,newVal)	\
    ( (This)->lpVtbl -> put_mediaType(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_mediaType(This,pVal)	\
    ( (This)->lpVtbl -> get_mediaType(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_mediaSource(This,newVal)	\
    ( (This)->lpVtbl -> put_mediaSource(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_mediaSource(This,pVal)	\
    ( (This)->lpVtbl -> get_mediaSource(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_mediaWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_mediaWidth(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_mediaWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_mediaWidth(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_mediaDestination(This,newVal)	\
    ( (This)->lpVtbl -> put_mediaDestination(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_mediaDestination(This,pVal)	\
    ( (This)->lpVtbl -> get_mediaDestination(This,pVal) ) 

#define IIcadPlotDeviceConfig_put_mediaCutting(This,newVal)	\
    ( (This)->lpVtbl -> put_mediaCutting(This,newVal) ) 

#define IIcadPlotDeviceConfig_get_mediaCutting(This,pVal)	\
    ( (This)->lpVtbl -> get_mediaCutting(This,pVal) ) 

#define IIcadPlotDeviceConfig_ImportPMP(This,filename)	\
    ( (This)->lpVtbl -> ImportPMP(This,filename) ) 

#define IIcadPlotDeviceConfig_ExportPMP(This,filename)	\
    ( (This)->lpVtbl -> ExportPMP(This,filename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIcadPlotDeviceConfig_INTERFACE_DEFINED__ */


#ifndef __IIcadPlotProperties_INTERFACE_DEFINED__
#define __IIcadPlotProperties_INTERFACE_DEFINED__

/* interface IIcadPlotProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIcadPlotProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8011c1c2-7e36-11d1-bc5a-0060089608a4")
    IIcadPlotProperties : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StyleSheet( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlotFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pens( 
            /* [retval][out] */ IIcadPlotterPens **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginX( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginX( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginY( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OriginY( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Units( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Units( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OptimizeLevel( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OptimizeLevel( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotate( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotate( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Scale( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Scale( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PenWidth( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PenWidth( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIcadPlotPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIcadPlotProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIcadPlotProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIcadPlotProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIcadPlotProperties * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIcadPlotProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIcadPlotProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIcadPlotProperties * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StyleSheet )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlotFile )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pens )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ IIcadPlotterPens **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginX )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginX )( 
            IIcadPlotProperties * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginY )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OriginY )( 
            IIcadPlotProperties * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Units )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Units )( 
            IIcadPlotProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OptimizeLevel )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OptimizeLevel )( 
            IIcadPlotProperties * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rotate )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rotate )( 
            IIcadPlotProperties * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Scale )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Scale )( 
            IIcadPlotProperties * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PenWidth )( 
            IIcadPlotProperties * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PenWidth )( 
            IIcadPlotProperties * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IIcadPlotPropertiesVtbl;

    interface IIcadPlotProperties
    {
        CONST_VTBL struct IIcadPlotPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIcadPlotProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIcadPlotProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIcadPlotProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIcadPlotProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIcadPlotProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIcadPlotProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIcadPlotProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIcadPlotProperties_get_StyleSheet(This,pVal)	\
    ( (This)->lpVtbl -> get_StyleSheet(This,pVal) ) 

#define IIcadPlotProperties_get_PlotFile(This,pVal)	\
    ( (This)->lpVtbl -> get_PlotFile(This,pVal) ) 

#define IIcadPlotProperties_get_Pens(This,pVal)	\
    ( (This)->lpVtbl -> get_Pens(This,pVal) ) 

#define IIcadPlotProperties_get_OriginX(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginX(This,pVal) ) 

#define IIcadPlotProperties_put_OriginX(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginX(This,newVal) ) 

#define IIcadPlotProperties_get_OriginY(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginY(This,pVal) ) 

#define IIcadPlotProperties_put_OriginY(This,newVal)	\
    ( (This)->lpVtbl -> put_OriginY(This,newVal) ) 

#define IIcadPlotProperties_get_Units(This,pVal)	\
    ( (This)->lpVtbl -> get_Units(This,pVal) ) 

#define IIcadPlotProperties_put_Units(This,newVal)	\
    ( (This)->lpVtbl -> put_Units(This,newVal) ) 

#define IIcadPlotProperties_get_Version(This,pVal)	\
    ( (This)->lpVtbl -> get_Version(This,pVal) ) 

#define IIcadPlotProperties_get_OptimizeLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_OptimizeLevel(This,pVal) ) 

#define IIcadPlotProperties_put_OptimizeLevel(This,newVal)	\
    ( (This)->lpVtbl -> put_OptimizeLevel(This,newVal) ) 

#define IIcadPlotProperties_get_Rotate(This,pVal)	\
    ( (This)->lpVtbl -> get_Rotate(This,pVal) ) 

#define IIcadPlotProperties_put_Rotate(This,newVal)	\
    ( (This)->lpVtbl -> put_Rotate(This,newVal) ) 

#define IIcadPlotProperties_get_Scale(This,pVal)	\
    ( (This)->lpVtbl -> get_Scale(This,pVal) ) 

#define IIcadPlotProperties_put_Scale(This,newVal)	\
    ( (This)->lpVtbl -> put_Scale(This,newVal) ) 

#define IIcadPlotProperties_get_PenWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_PenWidth(This,pVal) ) 

#define IIcadPlotProperties_put_PenWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_PenWidth(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIcadPlotProperties_INTERFACE_DEFINED__ */


#ifndef __IIcadPlotManager_INTERFACE_DEFINED__
#define __IIcadPlotManager_INTERFACE_DEFINED__

/* interface IIcadPlotManager */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [uuid] */  DECLSPEC_UUID("8011c0db-7e36-11d1-bc5a-0060089608a4") 
enum PrintArea
    {	CurrentView	= 0,
	Extents	= ( CurrentView + 1 ) ,
	Limits	= ( Extents + 1 ) ,
	Window	= ( Limits + 1 ) ,
	SavedView	= ( Window + 1 ) 
    } 	PrintArea;


EXTERN_C const IID IID_IIcadPlotManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8011c1c1-7e36-11d1-bc5a-0060089608a4")
    IIcadPlotManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportPlotProperties( 
            BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportPlotProperties( 
            BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportRegPlotProperties( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportRegPlotProperties( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Preview( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWindow( 
            double *fromX,
            double *fromY,
            double *toX,
            double *toY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindow( 
            double fromX,
            double fromY,
            double toX,
            double toY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPaperSize( 
            int *size,
            int *length,
            int *width) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPaperSize( 
            int size,
            int length,
            int width) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPaperTSize( 
            BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPaperTSize( 
            BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPaperYSize( 
            /* [out] */ BSTR *pName,
            /* [out] */ int *length,
            /* [out] */ int *width,
            /* [out] */ int *paper) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPrinterSettings( 
            /* [out] */ LONG *phDevMode,
            /* [out] */ LONG *phDevNames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDefault( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrinterNotVBA( 
            BSTR printerName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrinter( 
            BSTR printerName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWorking( 
            int mode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotProperties( 
            /* [retval][out] */ IIcadPlotProperties **pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Area( 
            /* [retval][out] */ PrintArea *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Area( 
            /* [in] */ PrintArea newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PaperOrientation( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PaperOrientation( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Header( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Header( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Footer( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Footer( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CenterOnPage( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CenterOnPage( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Shade( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Shade( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotNames( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotDeviceConfig( 
            /* [retval][out] */ IIcadPlotDeviceConfig **pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UseStyle( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_UseStyle( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UseOLW( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_UseOLW( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPlotConifg( 
            /* [retval][out] */ BYTE **pPlotCfg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [retval][out] */ IIcadPlotProperties **pProperties) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDeviceConifg( 
            /* [retval][out] */ IIcadPlotDeviceConfig **pConfig) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_VbaSetPrinter( 
            /* [retval][out] */ BOOL *bSetPrinter) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_VbaSetPrinter( 
            /* [in] */ BOOL bSetPrinter) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrinterA( 
            BSTR printerName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIcadPlotManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIcadPlotManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIcadPlotManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIcadPlotManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIcadPlotManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIcadPlotManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIcadPlotManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIcadPlotManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportPlotProperties )( 
            IIcadPlotManager * This,
            BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportPlotProperties )( 
            IIcadPlotManager * This,
            BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportRegPlotProperties )( 
            IIcadPlotManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportRegPlotProperties )( 
            IIcadPlotManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Print )( 
            IIcadPlotManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Preview )( 
            IIcadPlotManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IIcadPlotManager * This,
            double *fromX,
            double *fromY,
            double *toX,
            double *toY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindow )( 
            IIcadPlotManager * This,
            double fromX,
            double fromY,
            double toX,
            double toY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPaperSize )( 
            IIcadPlotManager * This,
            int *size,
            int *length,
            int *width);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPaperSize )( 
            IIcadPlotManager * This,
            int size,
            int length,
            int width);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPaperTSize )( 
            IIcadPlotManager * This,
            BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPaperTSize )( 
            IIcadPlotManager * This,
            BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPaperYSize )( 
            IIcadPlotManager * This,
            /* [out] */ BSTR *pName,
            /* [out] */ int *length,
            /* [out] */ int *width,
            /* [out] */ int *paper);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPrinterSettings )( 
            IIcadPlotManager * This,
            /* [out] */ LONG *phDevMode,
            /* [out] */ LONG *phDevNames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDefault )( 
            IIcadPlotManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPrinterNotVBA )( 
            IIcadPlotManager * This,
            BSTR printerName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPrinter )( 
            IIcadPlotManager * This,
            BSTR printerName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWorking )( 
            IIcadPlotManager * This,
            int mode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotProperties )( 
            IIcadPlotManager * This,
            /* [retval][out] */ IIcadPlotProperties **pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Area )( 
            IIcadPlotManager * This,
            /* [retval][out] */ PrintArea *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Area )( 
            IIcadPlotManager * This,
            /* [in] */ PrintArea newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PaperOrientation )( 
            IIcadPlotManager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PaperOrientation )( 
            IIcadPlotManager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Header )( 
            IIcadPlotManager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Header )( 
            IIcadPlotManager * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Footer )( 
            IIcadPlotManager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Footer )( 
            IIcadPlotManager * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CenterOnPage )( 
            IIcadPlotManager * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CenterOnPage )( 
            IIcadPlotManager * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Shade )( 
            IIcadPlotManager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Shade )( 
            IIcadPlotManager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotNames )( 
            IIcadPlotManager * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotDeviceConfig )( 
            IIcadPlotManager * This,
            /* [retval][out] */ IIcadPlotDeviceConfig **pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UseStyle )( 
            IIcadPlotManager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UseStyle )( 
            IIcadPlotManager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UseOLW )( 
            IIcadPlotManager * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UseOLW )( 
            IIcadPlotManager * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPlotConifg )( 
            IIcadPlotManager * This,
            /* [retval][out] */ BYTE **pPlotCfg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IIcadPlotManager * This,
            /* [retval][out] */ IIcadPlotProperties **pProperties);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeviceConifg )( 
            IIcadPlotManager * This,
            /* [retval][out] */ IIcadPlotDeviceConfig **pConfig);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VbaSetPrinter )( 
            IIcadPlotManager * This,
            /* [retval][out] */ BOOL *bSetPrinter);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VbaSetPrinter )( 
            IIcadPlotManager * This,
            /* [in] */ BOOL bSetPrinter);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPrinterA )( 
            IIcadPlotManager * This,
            BSTR printerName);
        
        END_INTERFACE
    } IIcadPlotManagerVtbl;

    interface IIcadPlotManager
    {
        CONST_VTBL struct IIcadPlotManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIcadPlotManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIcadPlotManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIcadPlotManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIcadPlotManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIcadPlotManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIcadPlotManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIcadPlotManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIcadPlotManager_ImportPlotProperties(This,filename)	\
    ( (This)->lpVtbl -> ImportPlotProperties(This,filename) ) 

#define IIcadPlotManager_ExportPlotProperties(This,filename)	\
    ( (This)->lpVtbl -> ExportPlotProperties(This,filename) ) 

#define IIcadPlotManager_ImportRegPlotProperties(This)	\
    ( (This)->lpVtbl -> ImportRegPlotProperties(This) ) 

#define IIcadPlotManager_ExportRegPlotProperties(This)	\
    ( (This)->lpVtbl -> ExportRegPlotProperties(This) ) 

#define IIcadPlotManager_Print(This)	\
    ( (This)->lpVtbl -> Print(This) ) 

#define IIcadPlotManager_Preview(This)	\
    ( (This)->lpVtbl -> Preview(This) ) 

#define IIcadPlotManager_GetWindow(This,fromX,fromY,toX,toY)	\
    ( (This)->lpVtbl -> GetWindow(This,fromX,fromY,toX,toY) ) 

#define IIcadPlotManager_SetWindow(This,fromX,fromY,toX,toY)	\
    ( (This)->lpVtbl -> SetWindow(This,fromX,fromY,toX,toY) ) 

#define IIcadPlotManager_GetPaperSize(This,size,length,width)	\
    ( (This)->lpVtbl -> GetPaperSize(This,size,length,width) ) 

#define IIcadPlotManager_SetPaperSize(This,size,length,width)	\
    ( (This)->lpVtbl -> SetPaperSize(This,size,length,width) ) 

#define IIcadPlotManager_GetPaperTSize(This,pVal)	\
    ( (This)->lpVtbl -> GetPaperTSize(This,pVal) ) 

#define IIcadPlotManager_SetPaperTSize(This,newVal)	\
    ( (This)->lpVtbl -> SetPaperTSize(This,newVal) ) 

#define IIcadPlotManager_GetPaperYSize(This,pName,length,width,paper)	\
    ( (This)->lpVtbl -> GetPaperYSize(This,pName,length,width,paper) ) 

#define IIcadPlotManager_GetPrinterSettings(This,phDevMode,phDevNames)	\
    ( (This)->lpVtbl -> GetPrinterSettings(This,phDevMode,phDevNames) ) 

#define IIcadPlotManager_GetDefault(This)	\
    ( (This)->lpVtbl -> GetDefault(This) ) 

#define IIcadPlotManager_SetPrinterNotVBA(This,printerName)	\
    ( (This)->lpVtbl -> SetPrinterNotVBA(This,printerName) ) 

#define IIcadPlotManager_SetPrinter(This,printerName)	\
    ( (This)->lpVtbl -> SetPrinter(This,printerName) ) 

#define IIcadPlotManager_SetWorking(This,mode)	\
    ( (This)->lpVtbl -> SetWorking(This,mode) ) 

#define IIcadPlotManager_get_PlotProperties(This,pVal)	\
    ( (This)->lpVtbl -> get_PlotProperties(This,pVal) ) 

#define IIcadPlotManager_get_Area(This,pVal)	\
    ( (This)->lpVtbl -> get_Area(This,pVal) ) 

#define IIcadPlotManager_put_Area(This,newVal)	\
    ( (This)->lpVtbl -> put_Area(This,newVal) ) 

#define IIcadPlotManager_get_PaperOrientation(This,pVal)	\
    ( (This)->lpVtbl -> get_PaperOrientation(This,pVal) ) 

#define IIcadPlotManager_put_PaperOrientation(This,newVal)	\
    ( (This)->lpVtbl -> put_PaperOrientation(This,newVal) ) 

#define IIcadPlotManager_get_Header(This,pVal)	\
    ( (This)->lpVtbl -> get_Header(This,pVal) ) 

#define IIcadPlotManager_put_Header(This,newVal)	\
    ( (This)->lpVtbl -> put_Header(This,newVal) ) 

#define IIcadPlotManager_get_Footer(This,pVal)	\
    ( (This)->lpVtbl -> get_Footer(This,pVal) ) 

#define IIcadPlotManager_put_Footer(This,newVal)	\
    ( (This)->lpVtbl -> put_Footer(This,newVal) ) 

#define IIcadPlotManager_get_CenterOnPage(This,pVal)	\
    ( (This)->lpVtbl -> get_CenterOnPage(This,pVal) ) 

#define IIcadPlotManager_put_CenterOnPage(This,newVal)	\
    ( (This)->lpVtbl -> put_CenterOnPage(This,newVal) ) 

#define IIcadPlotManager_get_Shade(This,pVal)	\
    ( (This)->lpVtbl -> get_Shade(This,pVal) ) 

#define IIcadPlotManager_put_Shade(This,newVal)	\
    ( (This)->lpVtbl -> put_Shade(This,newVal) ) 

#define IIcadPlotManager_get_PlotNames(This,pVal)	\
    ( (This)->lpVtbl -> get_PlotNames(This,pVal) ) 

#define IIcadPlotManager_get_PlotDeviceConfig(This,pVal)	\
    ( (This)->lpVtbl -> get_PlotDeviceConfig(This,pVal) ) 

#define IIcadPlotManager_get_UseStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_UseStyle(This,pVal) ) 

#define IIcadPlotManager_put_UseStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_UseStyle(This,newVal) ) 

#define IIcadPlotManager_get_UseOLW(This,pVal)	\
    ( (This)->lpVtbl -> get_UseOLW(This,pVal) ) 

#define IIcadPlotManager_put_UseOLW(This,newVal)	\
    ( (This)->lpVtbl -> put_UseOLW(This,newVal) ) 

#define IIcadPlotManager_GetPlotConifg(This,pPlotCfg)	\
    ( (This)->lpVtbl -> GetPlotConifg(This,pPlotCfg) ) 

#define IIcadPlotManager_GetProperties(This,pProperties)	\
    ( (This)->lpVtbl -> GetProperties(This,pProperties) ) 

#define IIcadPlotManager_GetDeviceConifg(This,pConfig)	\
    ( (This)->lpVtbl -> GetDeviceConifg(This,pConfig) ) 

#define IIcadPlotManager_get_VbaSetPrinter(This,bSetPrinter)	\
    ( (This)->lpVtbl -> get_VbaSetPrinter(This,bSetPrinter) ) 

#define IIcadPlotManager_put_VbaSetPrinter(This,bSetPrinter)	\
    ( (This)->lpVtbl -> put_VbaSetPrinter(This,bSetPrinter) ) 

#define IIcadPlotManager_SetPrinterA(This,printerName)	\
    ( (This)->lpVtbl -> SetPrinterA(This,printerName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIcadPlotManager_INTERFACE_DEFINED__ */


#ifndef __IIcadPlotRegManager_INTERFACE_DEFINED__
#define __IIcadPlotRegManager_INTERFACE_DEFINED__

/* interface IIcadPlotRegManager */
/* [unique][helpstring][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IIcadPlotRegManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8011c1c5-7e36-11d1-bc5a-0060089608a4")
    IIcadPlotRegManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportRegPlotProperties( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportRegPlotProperties( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RegPlotProperties( 
            /* [retval][out] */ IIcadPlotProperties **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIcadPlotRegManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIcadPlotRegManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIcadPlotRegManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIcadPlotRegManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportRegPlotProperties )( 
            IIcadPlotRegManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportRegPlotProperties )( 
            IIcadPlotRegManager * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RegPlotProperties )( 
            IIcadPlotRegManager * This,
            /* [retval][out] */ IIcadPlotProperties **pVal);
        
        END_INTERFACE
    } IIcadPlotRegManagerVtbl;

    interface IIcadPlotRegManager
    {
        CONST_VTBL struct IIcadPlotRegManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIcadPlotRegManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIcadPlotRegManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIcadPlotRegManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIcadPlotRegManager_ImportRegPlotProperties(This)	\
    ( (This)->lpVtbl -> ImportRegPlotProperties(This) ) 

#define IIcadPlotRegManager_ExportRegPlotProperties(This)	\
    ( (This)->lpVtbl -> ExportRegPlotProperties(This) ) 

#define IIcadPlotRegManager_get_RegPlotProperties(This,pVal)	\
    ( (This)->lpVtbl -> get_RegPlotProperties(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIcadPlotRegManager_INTERFACE_DEFINED__ */



#ifndef __GcadPlotSupportLib_LIBRARY_DEFINED__
#define __GcadPlotSupportLib_LIBRARY_DEFINED__

/* library GcadPlotSupportLib */
/* [helpstring][lcid][version][uuid] */ 


EXTERN_C const IID LIBID_GcadPlotSupportLib;

EXTERN_C const CLSID CLSID_PlotterPen;

#ifdef __cplusplus

class DECLSPEC_UUID("8011c1e4-7e36-11d1-bc5a-0060089608a4")
PlotterPen;
#endif

EXTERN_C const CLSID CLSID_PlotterPens;

#ifdef __cplusplus

class DECLSPEC_UUID("8011c1e3-7e36-11d1-bc5a-0060089608a4")
PlotterPens;
#endif

EXTERN_C const CLSID CLSID_PlotDeviceConfig;

#ifdef __cplusplus

class DECLSPEC_UUID("8011c1e2-0000-11d1-bc5a-0000089608a4")
PlotDeviceConfig;
#endif

EXTERN_C const CLSID CLSID_PlotProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("8011c1e2-7e36-11d1-bc5a-0060089608a4")
PlotProperties;
#endif

EXTERN_C const CLSID CLSID_PlotManager;

#ifdef __cplusplus

class DECLSPEC_UUID("8011c1e1-7e36-11d1-bc5a-0060089608a4")
PlotManager;
#endif
#endif /* __GcadPlotSupportLib_LIBRARY_DEFINED__ */

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


