

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\..\..\..\..\Drawing\Extensions\win\gcpi\gcpi.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __gcpi_h__
#define __gcpi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGcPiPropertyDisplay_FWD_DEFINED__
#define __IGcPiPropertyDisplay_FWD_DEFINED__
typedef interface IGcPiPropertyDisplay IGcPiPropertyDisplay;

#endif 	/* __IGcPiPropertyDisplay_FWD_DEFINED__ */


#ifndef __IGcPiCommandButton_FWD_DEFINED__
#define __IGcPiCommandButton_FWD_DEFINED__
typedef interface IGcPiCommandButton IGcPiCommandButton;

#endif 	/* __IGcPiCommandButton_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IGcPiPropertyDisplay_INTERFACE_DEFINED__
#define __IGcPiPropertyDisplay_INTERFACE_DEFINED__

/* interface IGcPiPropertyDisplay */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcPiPropertyDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F3D2407-1A17-4919-8D63-B168D09A4C37")
    IGcPiPropertyDisplay : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCustomPropertyCtrl( 
            /* [in] */ VARIANT Id,
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *pProgId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyIcon( 
            /* [in] */ VARIANT Id,
            /* [retval][out] */ IUnknown **pIcon) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropertyWeight( 
            /* [in] */ VARIANT Id,
            /* [retval][out] */ long *pPropertyWeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPropTextColor( 
            /* [in] */ VARIANT Id,
            /* [retval][out] */ OLE_COLOR *pTextColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsFullView( 
            /* [in] */ VARIANT Id,
            /* [out] */ VARIANT_BOOL *pbVisible,
            /* [retval][out] */ DWORD *pIntegralHeight) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcPiPropertyDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcPiPropertyDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcPiPropertyDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcPiPropertyDisplay * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCustomPropertyCtrl )( 
            IGcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *pProgId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyIcon )( 
            IGcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [retval][out] */ IUnknown **pIcon);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyWeight )( 
            IGcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [retval][out] */ long *pPropertyWeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPropTextColor )( 
            IGcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [retval][out] */ OLE_COLOR *pTextColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsFullView )( 
            IGcPiPropertyDisplay * This,
            /* [in] */ VARIANT Id,
            /* [out] */ VARIANT_BOOL *pbVisible,
            /* [retval][out] */ DWORD *pIntegralHeight);
        
        END_INTERFACE
    } IGcPiPropertyDisplayVtbl;

    interface IGcPiPropertyDisplay
    {
        CONST_VTBL struct IGcPiPropertyDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcPiPropertyDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcPiPropertyDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcPiPropertyDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcPiPropertyDisplay_GetCustomPropertyCtrl(This,Id,lcid,pProgId)	\
    ( (This)->lpVtbl -> GetCustomPropertyCtrl(This,Id,lcid,pProgId) ) 

#define IGcPiPropertyDisplay_GetPropertyIcon(This,Id,pIcon)	\
    ( (This)->lpVtbl -> GetPropertyIcon(This,Id,pIcon) ) 

#define IGcPiPropertyDisplay_GetPropertyWeight(This,Id,pPropertyWeight)	\
    ( (This)->lpVtbl -> GetPropertyWeight(This,Id,pPropertyWeight) ) 

#define IGcPiPropertyDisplay_GetPropTextColor(This,Id,pTextColor)	\
    ( (This)->lpVtbl -> GetPropTextColor(This,Id,pTextColor) ) 

#define IGcPiPropertyDisplay_IsFullView(This,Id,pbVisible,pIntegralHeight)	\
    ( (This)->lpVtbl -> IsFullView(This,Id,pbVisible,pIntegralHeight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcPiPropertyDisplay_INTERFACE_DEFINED__ */


#ifndef __IGcPiCommandButton_INTERFACE_DEFINED__
#define __IGcPiCommandButton_INTERFACE_DEFINED__

/* interface IGcPiCommandButton */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcPiCommandButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35CFD71A-ABDF-4096-A806-C3DB578F2C93")
    IGcPiCommandButton : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_EnabledPicture( 
            /* [retval][out] */ IUnknown **pPicture) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_DisabledPicture( 
            /* [retval][out] */ IUnknown **pPicture) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_Checked( 
            /* [retval][out] */ VARIANT_BOOL *bChecked) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Checked( 
            /* [in] */ VARIANT_BOOL bChecked) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_ButtonStyle( 
            /* [retval][out] */ long *style) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ VARIANT Objects) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcPiCommandButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcPiCommandButton * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcPiCommandButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcPiCommandButton * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IGcPiCommandButton * This,
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnabledPicture )( 
            IGcPiCommandButton * This,
            /* [retval][out] */ IUnknown **pPicture);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisabledPicture )( 
            IGcPiCommandButton * This,
            /* [retval][out] */ IUnknown **pPicture);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IGcPiCommandButton * This,
            /* [retval][out] */ VARIANT_BOOL *bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IGcPiCommandButton * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_Checked )( 
            IGcPiCommandButton * This,
            /* [retval][out] */ VARIANT_BOOL *bChecked);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *put_Checked )( 
            IGcPiCommandButton * This,
            /* [in] */ VARIANT_BOOL bChecked);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_ButtonStyle )( 
            IGcPiCommandButton * This,
            /* [retval][out] */ long *style);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IGcPiCommandButton * This,
            /* [in] */ VARIANT Objects);
        
        END_INTERFACE
    } IGcPiCommandButtonVtbl;

    interface IGcPiCommandButton
    {
        CONST_VTBL struct IGcPiCommandButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcPiCommandButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcPiCommandButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcPiCommandButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcPiCommandButton_GetName(This,lcid,name)	\
    ( (This)->lpVtbl -> GetName(This,lcid,name) ) 

#define IGcPiCommandButton_get_EnabledPicture(This,pPicture)	\
    ( (This)->lpVtbl -> get_EnabledPicture(This,pPicture) ) 

#define IGcPiCommandButton_get_DisabledPicture(This,pPicture)	\
    ( (This)->lpVtbl -> get_DisabledPicture(This,pPicture) ) 

#define IGcPiCommandButton_get_Enabled(This,bEnabled)	\
    ( (This)->lpVtbl -> get_Enabled(This,bEnabled) ) 

#define IGcPiCommandButton_put_Enabled(This,bEnabled)	\
    ( (This)->lpVtbl -> put_Enabled(This,bEnabled) ) 

#define IGcPiCommandButton_get_Checked(This,bChecked)	\
    ( (This)->lpVtbl -> get_Checked(This,bChecked) ) 

#define IGcPiCommandButton_put_Checked(This,bChecked)	\
    ( (This)->lpVtbl -> put_Checked(This,bChecked) ) 

#define IGcPiCommandButton_get_ButtonStyle(This,style)	\
    ( (This)->lpVtbl -> get_ButtonStyle(This,style) ) 

#define IGcPiCommandButton_Execute(This,Objects)	\
    ( (This)->lpVtbl -> Execute(This,Objects) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcPiCommandButton_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


