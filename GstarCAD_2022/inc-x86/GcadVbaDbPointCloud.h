

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\..\..\..\..\Extensions\win\gcax\GcadVbaDbPointCloud.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
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

#ifndef __GcadVbaDbPointCloud_h__
#define __GcadVbaDbPointCloud_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGcadPointCloudEx_FWD_DEFINED__
#define __IGcadPointCloudEx_FWD_DEFINED__
typedef interface IGcadPointCloudEx IGcadPointCloudEx;

#endif 	/* __IGcadPointCloudEx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GcadVbaDefs.h"
#include "GcadVbaDbObjs.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_GcadVbaDbPointCloud_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_GcadVbaDbPointCloud_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GcadVbaDbPointCloud_0000_0000_v0_0_s_ifspec;

#ifndef __IGcadPointCloudEx_INTERFACE_DEFINED__
#define __IGcadPointCloudEx_INTERFACE_DEFINED__

/* interface IGcadPointCloudEx */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadPointCloudEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7726E3CE-7227-4121-B5BA-45A467444C69")
    IGcadPointCloudEx : public IGcadEntity
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Stylization( 
            /* [retval][out] */ GcPointCloudExStylizationType *Type) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Stylization( 
            /* [in] */ GcPointCloudExStylizationType Type) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ColorScheme( 
            /* [retval][out] */ BSTR *Type) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ColorScheme( 
            /* [in] */ BSTR Type) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_InsertionPoint( 
            /* [retval][out] */ VARIANT *EndPoint) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_InsertionPoint( 
            /* [in] */ VARIANT EndPoint) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ GCAD_ANGLE *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ GCAD_ANGLE val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Scale( 
            /* [retval][out] */ GCAD_NOUNITS *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Scale( 
            /* [in] */ GCAD_NOUNITS val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowCropped( 
            /* [retval][out] */ VARIANT_BOOL *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowCropped( 
            /* [in] */ VARIANT_BOOL val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Locked( 
            /* [retval][out] */ VARIANT_BOOL *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Locked( 
            /* [in] */ VARIANT_BOOL val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Geolocate( 
            /* [retval][out] */ VARIANT_BOOL *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Geolocate( 
            /* [in] */ VARIANT_BOOL val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Unit( 
            /* [retval][out] */ BSTR *val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UnitFactor( 
            /* [retval][out] */ double *val) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPointCloudExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPointCloudEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPointCloudEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPointCloudEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPointCloudEx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPointCloudEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPointCloudEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPointCloudEx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadPointCloudEx * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadPointCloudEx * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadAcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadPointCloudEx * This,
            /* [in] */ IGcadAcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadPointCloudEx * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadPointCloudEx * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadPointCloudEx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadPointCloudEx * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadPointCloudEx * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GcEntityName *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Stylization )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GcPointCloudExStylizationType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Stylization )( 
            IGcadPointCloudEx * This,
            /* [in] */ GcPointCloudExStylizationType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ColorScheme )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ColorScheme )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_InsertionPoint )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT *EndPoint);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_InsertionPoint )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT EndPoint);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_ANGLE *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_ANGLE val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Scale )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_NOUNITS *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Scale )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_NOUNITS val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowCropped )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowCropped )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Locked )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Locked )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Geolocate )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Geolocate )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Unit )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UnitFactor )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ double *val);
        
        END_INTERFACE
    } IGcadPointCloudExVtbl;

    interface IGcadPointCloudEx
    {
        CONST_VTBL struct IGcadPointCloudExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPointCloudEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPointCloudEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPointCloudEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPointCloudEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPointCloudEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPointCloudEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPointCloudEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPointCloudEx_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadPointCloudEx_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadPointCloudEx_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadPointCloudEx_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadPointCloudEx_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadPointCloudEx_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadPointCloudEx_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadPointCloudEx_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadPointCloudEx_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadPointCloudEx_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadPointCloudEx_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadPointCloudEx_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadPointCloudEx_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadPointCloudEx_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadPointCloudEx_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadPointCloudEx_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadPointCloudEx_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadPointCloudEx_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadPointCloudEx_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadPointCloudEx_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadPointCloudEx_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadPointCloudEx_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadPointCloudEx_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadPointCloudEx_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadPointCloudEx_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadPointCloudEx_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadPointCloudEx_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadPointCloudEx_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadPointCloudEx_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadPointCloudEx_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadPointCloudEx_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadPointCloudEx_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadPointCloudEx_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadPointCloudEx_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadPointCloudEx_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadPointCloudEx_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadPointCloudEx_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadPointCloudEx_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadPointCloudEx_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadPointCloudEx_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadPointCloudEx_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadPointCloudEx_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadPointCloudEx_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadPointCloudEx_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadPointCloudEx_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadPointCloudEx_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadPointCloudEx_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadPointCloudEx_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadPointCloudEx_get_color(This,color)	\
    ( (This)->lpVtbl -> get_color(This,color) ) 

#define IGcadPointCloudEx_put_color(This,color)	\
    ( (This)->lpVtbl -> put_color(This,color) ) 


#define IGcadPointCloudEx_get_Stylization(This,Type)	\
    ( (This)->lpVtbl -> get_Stylization(This,Type) ) 

#define IGcadPointCloudEx_put_Stylization(This,Type)	\
    ( (This)->lpVtbl -> put_Stylization(This,Type) ) 

#define IGcadPointCloudEx_get_ColorScheme(This,Type)	\
    ( (This)->lpVtbl -> get_ColorScheme(This,Type) ) 

#define IGcadPointCloudEx_put_ColorScheme(This,Type)	\
    ( (This)->lpVtbl -> put_ColorScheme(This,Type) ) 

#define IGcadPointCloudEx_get_InsertionPoint(This,EndPoint)	\
    ( (This)->lpVtbl -> get_InsertionPoint(This,EndPoint) ) 

#define IGcadPointCloudEx_put_InsertionPoint(This,EndPoint)	\
    ( (This)->lpVtbl -> put_InsertionPoint(This,EndPoint) ) 

#define IGcadPointCloudEx_get_Rotation(This,val)	\
    ( (This)->lpVtbl -> get_Rotation(This,val) ) 

#define IGcadPointCloudEx_put_Rotation(This,val)	\
    ( (This)->lpVtbl -> put_Rotation(This,val) ) 

#define IGcadPointCloudEx_get_Scale(This,val)	\
    ( (This)->lpVtbl -> get_Scale(This,val) ) 

#define IGcadPointCloudEx_put_Scale(This,val)	\
    ( (This)->lpVtbl -> put_Scale(This,val) ) 

#define IGcadPointCloudEx_get_Name(This,val)	\
    ( (This)->lpVtbl -> get_Name(This,val) ) 

#define IGcadPointCloudEx_put_Name(This,val)	\
    ( (This)->lpVtbl -> put_Name(This,val) ) 

#define IGcadPointCloudEx_get_Path(This,val)	\
    ( (This)->lpVtbl -> get_Path(This,val) ) 

#define IGcadPointCloudEx_get_ShowCropped(This,val)	\
    ( (This)->lpVtbl -> get_ShowCropped(This,val) ) 

#define IGcadPointCloudEx_put_ShowCropped(This,val)	\
    ( (This)->lpVtbl -> put_ShowCropped(This,val) ) 

#define IGcadPointCloudEx_get_Locked(This,val)	\
    ( (This)->lpVtbl -> get_Locked(This,val) ) 

#define IGcadPointCloudEx_put_Locked(This,val)	\
    ( (This)->lpVtbl -> put_Locked(This,val) ) 

#define IGcadPointCloudEx_get_Geolocate(This,val)	\
    ( (This)->lpVtbl -> get_Geolocate(This,val) ) 

#define IGcadPointCloudEx_put_Geolocate(This,val)	\
    ( (This)->lpVtbl -> put_Geolocate(This,val) ) 

#define IGcadPointCloudEx_get_Unit(This,val)	\
    ( (This)->lpVtbl -> get_Unit(This,val) ) 

#define IGcadPointCloudEx_get_UnitFactor(This,val)	\
    ( (This)->lpVtbl -> get_UnitFactor(This,val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPointCloudEx_INTERFACE_DEFINED__ */


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


