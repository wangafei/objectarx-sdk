

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\..\..\..\..\Extensions\win\gcax\GcadVbaDbObjs3d.idl:
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

#ifndef __GcadVbaDbObjs3d_h__
#define __GcadVbaDbObjs3d_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGcadPlaneSurface_FWD_DEFINED__
#define __IGcadPlaneSurface_FWD_DEFINED__
typedef interface IGcadPlaneSurface IGcadPlaneSurface;

#endif 	/* __IGcadPlaneSurface_FWD_DEFINED__ */


#ifndef __IGcadExtrudedSurface_FWD_DEFINED__
#define __IGcadExtrudedSurface_FWD_DEFINED__
typedef interface IGcadExtrudedSurface IGcadExtrudedSurface;

#endif 	/* __IGcadExtrudedSurface_FWD_DEFINED__ */


#ifndef __IGcadRevolvedSurface_FWD_DEFINED__
#define __IGcadRevolvedSurface_FWD_DEFINED__
typedef interface IGcadRevolvedSurface IGcadRevolvedSurface;

#endif 	/* __IGcadRevolvedSurface_FWD_DEFINED__ */


#ifndef __IGcadSweptSurface_FWD_DEFINED__
#define __IGcadSweptSurface_FWD_DEFINED__
typedef interface IGcadSweptSurface IGcadSweptSurface;

#endif 	/* __IGcadSweptSurface_FWD_DEFINED__ */


#ifndef __IGcadLoftedSurface_FWD_DEFINED__
#define __IGcadLoftedSurface_FWD_DEFINED__
typedef interface IGcadLoftedSurface IGcadLoftedSurface;

#endif 	/* __IGcadLoftedSurface_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GcadVbaDefs.h"
#include "GcadVbaDbObjs.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_GcadVbaDbObjs3d_0000_0000 */
/* [local] */ 









extern RPC_IF_HANDLE __MIDL_itf_GcadVbaDbObjs3d_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GcadVbaDbObjs3d_0000_0000_v0_0_s_ifspec;

#ifndef __IGcadPlaneSurface_INTERFACE_DEFINED__
#define __IGcadPlaneSurface_INTERFACE_DEFINED__

/* interface IGcadPlaneSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadPlaneSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEC784E6-1392-4C72-8437-08590A0158AB")
    IGcadPlaneSurface : public IGcadSurface
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPlaneSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPlaneSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPlaneSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPlaneSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPlaneSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPlaneSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPlaneSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPlaneSurface * This,
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
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadPlaneSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadPlaneSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadAcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadPlaneSurface * This,
            /* [in] */ IGcadAcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadPlaneSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadPlaneSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadPlaneSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadPlaneSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadPlaneSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadPlaneSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadPlaneSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GcEntityName *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IGcadPlaneSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadPlaneSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadPlaneSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        END_INTERFACE
    } IGcadPlaneSurfaceVtbl;

    interface IGcadPlaneSurface
    {
        CONST_VTBL struct IGcadPlaneSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPlaneSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPlaneSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPlaneSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPlaneSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPlaneSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPlaneSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPlaneSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPlaneSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadPlaneSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadPlaneSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadPlaneSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadPlaneSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadPlaneSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadPlaneSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadPlaneSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadPlaneSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadPlaneSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadPlaneSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadPlaneSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadPlaneSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadPlaneSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadPlaneSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadPlaneSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadPlaneSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadPlaneSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadPlaneSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadPlaneSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadPlaneSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadPlaneSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadPlaneSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadPlaneSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadPlaneSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadPlaneSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadPlaneSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadPlaneSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadPlaneSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadPlaneSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadPlaneSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadPlaneSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadPlaneSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadPlaneSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadPlaneSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadPlaneSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadPlaneSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadPlaneSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadPlaneSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadPlaneSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadPlaneSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadPlaneSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadPlaneSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadPlaneSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadPlaneSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadPlaneSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadPlaneSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadPlaneSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadPlaneSurface_get_color(This,color)	\
    ( (This)->lpVtbl -> get_color(This,color) ) 

#define IGcadPlaneSurface_put_color(This,color)	\
    ( (This)->lpVtbl -> put_color(This,color) ) 


#define IGcadPlaneSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadPlaneSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadPlaneSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadPlaneSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadPlaneSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadPlaneSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadPlaneSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPlaneSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadExtrudedSurface_INTERFACE_DEFINED__
#define __IGcadExtrudedSurface_INTERFACE_DEFINED__

/* interface IGcadExtrudedSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadExtrudedSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A4D93D5-9558-4023-8A6E-EE17601A975B")
    IGcadExtrudedSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ double *Height) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ double Height) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TaperAngle( 
            /* [retval][out] */ GCAD_ANGLE *TaperAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TaperAngle( 
            /* [in] */ GCAD_ANGLE TaperAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Direction( 
            /* [retval][out] */ VARIANT *Direction) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadExtrudedSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadExtrudedSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadExtrudedSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadExtrudedSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadExtrudedSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadExtrudedSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadExtrudedSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadExtrudedSurface * This,
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
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadExtrudedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadExtrudedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadAcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadExtrudedSurface * This,
            /* [in] */ IGcadAcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadExtrudedSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadExtrudedSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadExtrudedSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadExtrudedSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadExtrudedSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GcEntityName *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ double *Height);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IGcadExtrudedSurface * This,
            /* [in] */ double Height);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TaperAngle )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *TaperAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TaperAngle )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_ANGLE TaperAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Direction )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT *Direction);
        
        END_INTERFACE
    } IGcadExtrudedSurfaceVtbl;

    interface IGcadExtrudedSurface
    {
        CONST_VTBL struct IGcadExtrudedSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadExtrudedSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadExtrudedSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadExtrudedSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadExtrudedSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadExtrudedSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadExtrudedSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadExtrudedSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadExtrudedSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadExtrudedSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadExtrudedSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadExtrudedSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadExtrudedSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadExtrudedSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadExtrudedSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadExtrudedSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadExtrudedSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadExtrudedSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadExtrudedSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadExtrudedSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadExtrudedSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadExtrudedSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadExtrudedSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadExtrudedSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadExtrudedSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadExtrudedSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadExtrudedSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadExtrudedSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadExtrudedSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadExtrudedSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadExtrudedSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadExtrudedSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadExtrudedSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadExtrudedSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadExtrudedSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadExtrudedSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadExtrudedSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadExtrudedSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadExtrudedSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadExtrudedSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadExtrudedSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadExtrudedSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadExtrudedSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadExtrudedSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadExtrudedSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadExtrudedSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadExtrudedSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadExtrudedSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadExtrudedSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadExtrudedSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadExtrudedSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadExtrudedSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadExtrudedSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadExtrudedSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadExtrudedSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadExtrudedSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadExtrudedSurface_get_color(This,color)	\
    ( (This)->lpVtbl -> get_color(This,color) ) 

#define IGcadExtrudedSurface_put_color(This,color)	\
    ( (This)->lpVtbl -> put_color(This,color) ) 


#define IGcadExtrudedSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadExtrudedSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadExtrudedSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadExtrudedSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadExtrudedSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadExtrudedSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadExtrudedSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadExtrudedSurface_get_Height(This,Height)	\
    ( (This)->lpVtbl -> get_Height(This,Height) ) 

#define IGcadExtrudedSurface_put_Height(This,Height)	\
    ( (This)->lpVtbl -> put_Height(This,Height) ) 

#define IGcadExtrudedSurface_get_TaperAngle(This,TaperAngle)	\
    ( (This)->lpVtbl -> get_TaperAngle(This,TaperAngle) ) 

#define IGcadExtrudedSurface_put_TaperAngle(This,TaperAngle)	\
    ( (This)->lpVtbl -> put_TaperAngle(This,TaperAngle) ) 

#define IGcadExtrudedSurface_get_Direction(This,Direction)	\
    ( (This)->lpVtbl -> get_Direction(This,Direction) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadExtrudedSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadRevolvedSurface_INTERFACE_DEFINED__
#define __IGcadRevolvedSurface_INTERFACE_DEFINED__

/* interface IGcadRevolvedSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadRevolvedSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B8C6F7D-ADB5-4CF1-B21D-A0E5EBA58010")
    IGcadRevolvedSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RevolutionAngle( 
            /* [retval][out] */ GCAD_ANGLE *revAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RevolutionAngle( 
            /* [in] */ GCAD_ANGLE revAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AxisPosition( 
            /* [retval][out] */ VARIANT *AxisPosition) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AxisPosition( 
            /* [in] */ VARIANT AxisPosition) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AxisDirection( 
            /* [retval][out] */ VARIANT *AxisDirection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadRevolvedSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadRevolvedSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadRevolvedSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadRevolvedSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadRevolvedSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadRevolvedSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadRevolvedSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadRevolvedSurface * This,
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
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadRevolvedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadRevolvedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadAcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadRevolvedSurface * This,
            /* [in] */ IGcadAcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadRevolvedSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadRevolvedSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadRevolvedSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadRevolvedSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadRevolvedSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GcEntityName *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RevolutionAngle )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *revAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_RevolutionAngle )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_ANGLE revAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AxisPosition )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT *AxisPosition);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AxisPosition )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT AxisPosition);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AxisDirection )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT *AxisDirection);
        
        END_INTERFACE
    } IGcadRevolvedSurfaceVtbl;

    interface IGcadRevolvedSurface
    {
        CONST_VTBL struct IGcadRevolvedSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadRevolvedSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadRevolvedSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadRevolvedSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadRevolvedSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadRevolvedSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadRevolvedSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadRevolvedSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadRevolvedSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadRevolvedSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadRevolvedSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadRevolvedSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadRevolvedSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadRevolvedSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadRevolvedSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadRevolvedSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadRevolvedSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadRevolvedSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadRevolvedSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadRevolvedSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadRevolvedSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadRevolvedSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadRevolvedSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadRevolvedSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadRevolvedSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadRevolvedSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadRevolvedSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadRevolvedSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadRevolvedSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadRevolvedSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadRevolvedSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadRevolvedSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadRevolvedSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadRevolvedSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadRevolvedSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadRevolvedSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadRevolvedSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadRevolvedSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadRevolvedSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadRevolvedSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadRevolvedSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadRevolvedSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadRevolvedSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadRevolvedSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadRevolvedSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadRevolvedSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadRevolvedSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadRevolvedSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadRevolvedSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadRevolvedSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadRevolvedSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadRevolvedSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadRevolvedSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadRevolvedSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadRevolvedSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadRevolvedSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadRevolvedSurface_get_color(This,color)	\
    ( (This)->lpVtbl -> get_color(This,color) ) 

#define IGcadRevolvedSurface_put_color(This,color)	\
    ( (This)->lpVtbl -> put_color(This,color) ) 


#define IGcadRevolvedSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadRevolvedSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadRevolvedSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadRevolvedSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadRevolvedSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadRevolvedSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadRevolvedSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadRevolvedSurface_get_RevolutionAngle(This,revAngle)	\
    ( (This)->lpVtbl -> get_RevolutionAngle(This,revAngle) ) 

#define IGcadRevolvedSurface_put_RevolutionAngle(This,revAngle)	\
    ( (This)->lpVtbl -> put_RevolutionAngle(This,revAngle) ) 

#define IGcadRevolvedSurface_get_AxisPosition(This,AxisPosition)	\
    ( (This)->lpVtbl -> get_AxisPosition(This,AxisPosition) ) 

#define IGcadRevolvedSurface_put_AxisPosition(This,AxisPosition)	\
    ( (This)->lpVtbl -> put_AxisPosition(This,AxisPosition) ) 

#define IGcadRevolvedSurface_get_AxisDirection(This,AxisDirection)	\
    ( (This)->lpVtbl -> get_AxisDirection(This,AxisDirection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadRevolvedSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadSweptSurface_INTERFACE_DEFINED__
#define __IGcadSweptSurface_INTERFACE_DEFINED__

/* interface IGcadSweptSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadSweptSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F92E110-61C5-4356-BE5F-7B28765158CA")
    IGcadSweptSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProfileRotation( 
            /* [retval][out] */ GCAD_ANGLE *profileRotationAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProfileRotation( 
            /* [in] */ GCAD_ANGLE profileRotationAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Bank( 
            /* [retval][out] */ VARIANT_BOOL *bBank) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Bank( 
            /* [in] */ VARIANT_BOOL bBank) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Twist( 
            /* [retval][out] */ GCAD_ANGLE *TwistAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Twist( 
            /* [in] */ GCAD_ANGLE TwistAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_scale( 
            /* [retval][out] */ double *scale) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_scale( 
            /* [in] */ double scale) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double *Length) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadSweptSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadSweptSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadSweptSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadSweptSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadSweptSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadSweptSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadSweptSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadSweptSurface * This,
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
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadSweptSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadSweptSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadAcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadSweptSurface * This,
            /* [in] */ IGcadAcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadSweptSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadSweptSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadSweptSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadSweptSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadSweptSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GcEntityName *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadSweptSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadSweptSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProfileRotation )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_ANGLE *profileRotationAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProfileRotation )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_ANGLE profileRotationAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Bank )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bBank);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Bank )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL bBank);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Twist )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_ANGLE *TwistAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Twist )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_ANGLE TwistAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_scale )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ double *scale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_scale )( 
            IGcadSweptSurface * This,
            /* [in] */ double scale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ double *Length);
        
        END_INTERFACE
    } IGcadSweptSurfaceVtbl;

    interface IGcadSweptSurface
    {
        CONST_VTBL struct IGcadSweptSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadSweptSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadSweptSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadSweptSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadSweptSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadSweptSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadSweptSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadSweptSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadSweptSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadSweptSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadSweptSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadSweptSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadSweptSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadSweptSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadSweptSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadSweptSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadSweptSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadSweptSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadSweptSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadSweptSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadSweptSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadSweptSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadSweptSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadSweptSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadSweptSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadSweptSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadSweptSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadSweptSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadSweptSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadSweptSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadSweptSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadSweptSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadSweptSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadSweptSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadSweptSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadSweptSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadSweptSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadSweptSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadSweptSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadSweptSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadSweptSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadSweptSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadSweptSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadSweptSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadSweptSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadSweptSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadSweptSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadSweptSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadSweptSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadSweptSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadSweptSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadSweptSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadSweptSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadSweptSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadSweptSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadSweptSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadSweptSurface_get_color(This,color)	\
    ( (This)->lpVtbl -> get_color(This,color) ) 

#define IGcadSweptSurface_put_color(This,color)	\
    ( (This)->lpVtbl -> put_color(This,color) ) 


#define IGcadSweptSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadSweptSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadSweptSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadSweptSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadSweptSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadSweptSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadSweptSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadSweptSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadSweptSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadSweptSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadSweptSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadSweptSurface_get_ProfileRotation(This,profileRotationAngle)	\
    ( (This)->lpVtbl -> get_ProfileRotation(This,profileRotationAngle) ) 

#define IGcadSweptSurface_put_ProfileRotation(This,profileRotationAngle)	\
    ( (This)->lpVtbl -> put_ProfileRotation(This,profileRotationAngle) ) 

#define IGcadSweptSurface_get_Bank(This,bBank)	\
    ( (This)->lpVtbl -> get_Bank(This,bBank) ) 

#define IGcadSweptSurface_put_Bank(This,bBank)	\
    ( (This)->lpVtbl -> put_Bank(This,bBank) ) 

#define IGcadSweptSurface_get_Twist(This,TwistAngle)	\
    ( (This)->lpVtbl -> get_Twist(This,TwistAngle) ) 

#define IGcadSweptSurface_put_Twist(This,TwistAngle)	\
    ( (This)->lpVtbl -> put_Twist(This,TwistAngle) ) 

#define IGcadSweptSurface_get_scale(This,scale)	\
    ( (This)->lpVtbl -> get_scale(This,scale) ) 

#define IGcadSweptSurface_put_scale(This,scale)	\
    ( (This)->lpVtbl -> put_scale(This,scale) ) 

#define IGcadSweptSurface_get_Length(This,Length)	\
    ( (This)->lpVtbl -> get_Length(This,Length) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadSweptSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadLoftedSurface_INTERFACE_DEFINED__
#define __IGcadLoftedSurface_INTERFACE_DEFINED__

/* interface IGcadLoftedSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadLoftedSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFE1D681-BE59-4EC7-A016-741819AC8112")
    IGcadLoftedSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumCrossSections( 
            /* [retval][out] */ long *NumCrossSections) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumGuidePaths( 
            /* [retval][out] */ long *NumGuidePaths) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SurfaceNormals( 
            /* [retval][out] */ GcLoftedSurfaceNormalType *surfaceNormal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SurfaceNormals( 
            /* [in] */ GcLoftedSurfaceNormalType surfaceNormal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StartDraftAngle( 
            /* [retval][out] */ GCAD_ANGLE *StartDraftAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StartDraftAngle( 
            /* [in] */ GCAD_ANGLE StartDraftAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StartDraftMagnitude( 
            /* [retval][out] */ double *startDraftMag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StartDraftMagnitude( 
            /* [in] */ double startDraftMag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EndDraftAngle( 
            /* [retval][out] */ GCAD_ANGLE *EndDraftAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EndDraftAngle( 
            /* [in] */ GCAD_ANGLE EndDraftAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EndDraftMagnitude( 
            /* [retval][out] */ double *endDraftMag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EndDraftMagnitude( 
            /* [in] */ double endDraftMag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Closed( 
            /* [retval][out] */ VARIANT_BOOL *bClosed) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Closed( 
            /* [in] */ VARIANT_BOOL bClosed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadLoftedSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadLoftedSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadLoftedSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadLoftedSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadLoftedSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadLoftedSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadLoftedSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadLoftedSurface * This,
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
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadLoftedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadLoftedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadAcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadLoftedSurface * This,
            /* [in] */ IGcadAcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadLoftedSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadLoftedSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadLoftedSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadLoftedSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadLoftedSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GcEntityName *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_color )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_color )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadLoftedSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadLoftedSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumCrossSections )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *NumCrossSections);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumGuidePaths )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *NumGuidePaths);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceNormals )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GcLoftedSurfaceNormalType *surfaceNormal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SurfaceNormals )( 
            IGcadLoftedSurface * This,
            /* [in] */ GcLoftedSurfaceNormalType surfaceNormal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StartDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *StartDraftAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_StartDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_ANGLE StartDraftAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StartDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ double *startDraftMag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_StartDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [in] */ double startDraftMag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *EndDraftAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EndDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_ANGLE EndDraftAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ double *endDraftMag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EndDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [in] */ double endDraftMag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Closed )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bClosed);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Closed )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL bClosed);
        
        END_INTERFACE
    } IGcadLoftedSurfaceVtbl;

    interface IGcadLoftedSurface
    {
        CONST_VTBL struct IGcadLoftedSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadLoftedSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadLoftedSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadLoftedSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadLoftedSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadLoftedSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadLoftedSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadLoftedSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadLoftedSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadLoftedSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadLoftedSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadLoftedSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadLoftedSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadLoftedSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadLoftedSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadLoftedSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadLoftedSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadLoftedSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadLoftedSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadLoftedSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadLoftedSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadLoftedSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadLoftedSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadLoftedSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadLoftedSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadLoftedSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadLoftedSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadLoftedSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadLoftedSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadLoftedSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadLoftedSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadLoftedSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadLoftedSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadLoftedSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadLoftedSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadLoftedSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadLoftedSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadLoftedSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadLoftedSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadLoftedSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadLoftedSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadLoftedSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadLoftedSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadLoftedSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadLoftedSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadLoftedSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadLoftedSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadLoftedSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadLoftedSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadLoftedSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadLoftedSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadLoftedSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadLoftedSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadLoftedSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadLoftedSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadLoftedSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadLoftedSurface_get_color(This,color)	\
    ( (This)->lpVtbl -> get_color(This,color) ) 

#define IGcadLoftedSurface_put_color(This,color)	\
    ( (This)->lpVtbl -> put_color(This,color) ) 


#define IGcadLoftedSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadLoftedSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadLoftedSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadLoftedSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadLoftedSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadLoftedSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadLoftedSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadLoftedSurface_get_NumCrossSections(This,NumCrossSections)	\
    ( (This)->lpVtbl -> get_NumCrossSections(This,NumCrossSections) ) 

#define IGcadLoftedSurface_get_NumGuidePaths(This,NumGuidePaths)	\
    ( (This)->lpVtbl -> get_NumGuidePaths(This,NumGuidePaths) ) 

#define IGcadLoftedSurface_get_SurfaceNormals(This,surfaceNormal)	\
    ( (This)->lpVtbl -> get_SurfaceNormals(This,surfaceNormal) ) 

#define IGcadLoftedSurface_put_SurfaceNormals(This,surfaceNormal)	\
    ( (This)->lpVtbl -> put_SurfaceNormals(This,surfaceNormal) ) 

#define IGcadLoftedSurface_get_StartDraftAngle(This,StartDraftAngle)	\
    ( (This)->lpVtbl -> get_StartDraftAngle(This,StartDraftAngle) ) 

#define IGcadLoftedSurface_put_StartDraftAngle(This,StartDraftAngle)	\
    ( (This)->lpVtbl -> put_StartDraftAngle(This,StartDraftAngle) ) 

#define IGcadLoftedSurface_get_StartDraftMagnitude(This,startDraftMag)	\
    ( (This)->lpVtbl -> get_StartDraftMagnitude(This,startDraftMag) ) 

#define IGcadLoftedSurface_put_StartDraftMagnitude(This,startDraftMag)	\
    ( (This)->lpVtbl -> put_StartDraftMagnitude(This,startDraftMag) ) 

#define IGcadLoftedSurface_get_EndDraftAngle(This,EndDraftAngle)	\
    ( (This)->lpVtbl -> get_EndDraftAngle(This,EndDraftAngle) ) 

#define IGcadLoftedSurface_put_EndDraftAngle(This,EndDraftAngle)	\
    ( (This)->lpVtbl -> put_EndDraftAngle(This,EndDraftAngle) ) 

#define IGcadLoftedSurface_get_EndDraftMagnitude(This,endDraftMag)	\
    ( (This)->lpVtbl -> get_EndDraftMagnitude(This,endDraftMag) ) 

#define IGcadLoftedSurface_put_EndDraftMagnitude(This,endDraftMag)	\
    ( (This)->lpVtbl -> put_EndDraftMagnitude(This,endDraftMag) ) 

#define IGcadLoftedSurface_get_Closed(This,bClosed)	\
    ( (This)->lpVtbl -> get_Closed(This,bClosed) ) 

#define IGcadLoftedSurface_put_Closed(This,bClosed)	\
    ( (This)->lpVtbl -> put_Closed(This,bClosed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadLoftedSurface_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


