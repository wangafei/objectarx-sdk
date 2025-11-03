// AXBOILER.H
//
// Interface declarations for the AutoCAD Automation API +
// common object/entity manipulation functions.
//

#ifndef __GCAXBOILER_H_
#define __GCAXBOILER_H_

#ifdef GCAX_EXPORTS
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif

#include <comutil.h>
#include "axobjref.h"
#include "oleaprot.h"

//////////////////////////////////////////////////////////////////////////

//
// Utility functions
//
HRESULT GCADAXEXP RaiseGcAxException(REFGUID iid, HRESULT hRes, DWORD dwException, ...);
HRESULT GCADAXEXP RaiseArxException(REFGUID iid, HRESULT hRes, Gcad::ErrorStatus es);
/**********************************************************************************************
**********           data conversion                                                        */

inline BSTR GcGxToBSTR(const GCHAR* str)
{
    return _bstr_t(str).copy();
}

inline GcString GcGxToAcString(BSTR str)
{
    return GcString((const GCHAR*)_bstr_t(str));
}

bool IsLayerLocked(GcAxObjectRef &objRef);
bool IsLayerLocked(GcDbObjectId objId);
bool IsLayerTable(GcDbObjectId objId);

#define ISLayerLocked(objId) {if(IsLayerLocked(objId))return E_FAIL;}
#define ISLayerTable(objId) {if(IsLayerTable(objId))return E_FAIL;}

//////////////////////////////////////////////////////////////////////////
//
// Common object/entity helper functions
//
HRESULT GCADAXEXP GcAxErase(GcDbObjectId& objId);

HRESULT GCADAXEXP GcAxSetXData(GcDbObjectId& objId, VARIANT type, VARIANT data);

HRESULT GCADAXEXP GcAxGetXData(GcDbObjectId& objId, BSTR bstrName, VARIANT* type, VARIANT* data);

HRESULT GCADAXEXP GcAxGetObjectName(GcDbObjectId& objId, BSTR* pName);

HRESULT GCADAXEXP GcAxGetHandle(GcDbObjectId& objId, BSTR* pHandle);

HRESULT GCADAXEXP GcAxGetColor(GcDbObjectId& objId, GcColor* pColor);

HRESULT GCADAXEXP GcAxGetColor(GcAxObjectRef& objRef, GcColor* pColor);

HRESULT GCADAXEXP GcAxPutColor(GcDbObjectId& objId, GcColor color);

HRESULT GCADAXEXP GcAxGetTrueColor(GcDbObjectId& objId, IGcadAcCmColor** pColor);

HRESULT GCADAXEXP GcAxPutTrueColor(GcDbObjectId& objId, IGcadAcCmColor* color);

HRESULT GCADAXEXP GcAxGetLayer(GcDbObjectId& objId, BSTR* pLayer);

HRESULT GCADAXEXP GcAxPutLayer(GcDbObjectId& objId, BSTR layer);

HRESULT GCADAXEXP GcAxGetLinetype(GcDbObjectId& objId, BSTR* pLinetype);

HRESULT GCADAXEXP GcAxPutLinetype(GcDbObjectId& objId, BSTR linetype);


HRESULT GCADAXEXP GcAxGetShadowDisplay(GcDbObjectId& objId, GcShadowDisplayType* pShadowDisplay);

HRESULT GCADAXEXP GcAxPutShadowDisplay(GcDbObjectId& objId, GcShadowDisplayType shadowDisplay);

HRESULT GCADAXEXP GcAxGetMaterial(GcDbObjectId& objId, BSTR* pMaterial);

HRESULT GCADAXEXP GcAxPutMaterial(GcDbObjectId& objId, BSTR material);


HRESULT GCADAXEXP GcAxGetLinetypeScale(GcDbObjectId& objId, double* pLinetypeScale);

HRESULT GCADAXEXP GcAxPutLinetypeScale(GcDbObjectId& objId, double linetypeScale);

HRESULT GCADAXEXP GcAxGetVisible(GcDbObjectId& objId, VARIANT_BOOL* pVisible);

HRESULT GCADAXEXP GcAxPutVisible(GcDbObjectId& objId, VARIANT_BOOL visible);

HRESULT GCADAXEXP GcAxArrayPolar(GcDbObjectId& objId, LPDISPATCH pAppDisp, int numObjs, 
               double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);

HRESULT GCADAXEXP GcAxArrayRectangular(GcDbObjectId& objId, LPDISPATCH pAppDisp, int numRows, 
                     int numCols, int numLvls, double disRows, double disCols,
                     double disLvls, VARIANT* pArrayObjs);

HRESULT GCADAXEXP GcAxHighlight(GcDbObjectId& objId, VARIANT_BOOL bHighlight);

HRESULT GCADAXEXP GcAxCopy(GcDbObjectId& objId, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj, 
         GcDbObjectId ownerId = GcDbObjectId::kNull);

HRESULT GCADAXEXP GcAxMove(GcDbObjectId& objId, VARIANT fromPoint, VARIANT toPoint);

HRESULT GCADAXEXP GcAxRotate(GcDbObjectId& objId, VARIANT basePoint, double rotationAngle);

HRESULT GCADAXEXP GcAxRotate3D(GcDbObjectId& objId, VARIANT point1, VARIANT point2, 
             double rotationAngle);

HRESULT GCADAXEXP GcAxMirror(GcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1, 
           VARIANT point2, LPDISPATCH* pMirrorObj);

HRESULT GCADAXEXP GcAxMirror3D(GcDbObjectId& objId, LPDISPATCH pAppDisp,
    VARIANT point1, VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);

HRESULT GCADAXEXP GcAxScaleEntity(GcDbObjectId& objId, VARIANT basePoint, double scaleFactor);

HRESULT GCADAXEXP GcAxTransformBy(GcDbObjectId& objId, VARIANT transMatrix);

HRESULT GCADAXEXP GcAxUpdate(GcDbObjectId& objId);

HRESULT GCADAXEXP GcAxGetBoundingBox(GcDbObjectId& objId, VARIANT* minPoint, VARIANT* maxPoint);

HRESULT GCADAXEXP GcAxIntersectWith(GcDbObjectId& objId, LPDISPATCH pEntity, 
                  GcExtendOption  option, VARIANT* intPoints);

HRESULT GCADAXEXP GcAxGetPlotStyleName(GcDbObjectId& objId, BSTR* plotStyleName);

HRESULT GCADAXEXP GcAxPutPlotStyleName(GcDbObjectId& objId, BSTR plotStyleName);

HRESULT GCADAXEXP GcAxGetLineWeight(GcDbObjectId& objId, GCAD_LWEIGHT* lineWeight);

HRESULT GCADAXEXP GcAxPutLineWeight(GcDbObjectId& objId, GCAD_LWEIGHT lineWeight);

HRESULT GCADAXEXP GcAxGetEntityTransparency(GcDbObjectId& objId, BSTR* transparency);

HRESULT GCADAXEXP GcAxPutEntityTransparency(GcDbObjectId& objId, BSTR transparency);

HRESULT GCADAXEXP GcAxGetHyperlinks(GcDbObjectId& objId, LPDISPATCH pAppDisp, 
                  IGcadHyperlinks** pHyperlinks);

HRESULT GCADAXEXP GcAxHasExtensionDictionary(GcDbObjectId& objId, VARIANT_BOOL* bHasDictionary);

HRESULT GCADAXEXP GcAxGetExtensionDictionary(GcDbObjectId& objId, LPDISPATCH pAppDisp, 
                           IGcadDictionary** pExtDictionary);

HRESULT GCADAXEXP GcAxGetDatabase(GcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);

HRESULT GCADAXEXP GcAxGetOwnerId(GcDbObjectId& objId, Hccad::IntDbId* pOwnerId); 

#ifdef _WIN64
Hccad::Int32 GCADAXEXP GcAxGetObjectId32(const Hccad::IntDbId& objId);

Hccad::IntDbId GCADAXEXP GcAxGetObjectId64(const Hccad::Int32& objId);
#endif

//
// Utility functions
//
HRESULT GCADAXEXP RaiseGcAXException(REFGUID iid, HRESULT hRes, DWORD dwException, ...);

HRESULT  GCADAXEXP RaiseGrxException(REFGUID iid, HRESULT hRes, Gcad::ErrorStatus es);

HRESULT GCADAXEXP GcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, GcDbObjectId& objId, LPDISPATCH pApp);

HRESULT GCADAXEXP GcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, GcDbObject* pObj, LPDISPATCH pApp);


HRESULT GCADAXEXP GcAxErase(GcAxObjectRef& objRef);

HRESULT GCADAXEXP GcAxSetXData(GcAxObjectRef& objRef, VARIANT type, VARIANT data);

HRESULT GCADAXEXP GcAxGetXData(GcAxObjectRef& objRef, BSTR bstrName, VARIANT* type, VARIANT* data);

HRESULT GCADAXEXP GcAxGetObjectName(GcAxObjectRef& objRef, BSTR* pName);

HRESULT GCADAXEXP GcAxGetHandle(GcAxObjectRef& objRef, BSTR* pHandle);

HRESULT GCADAXEXP GcAxPutColor(GcAxObjectRef& objRef, GcColor color);

HRESULT GCADAXEXP GcAxGetTrueColor(GcAxObjectRef& objRef, IGcadAcCmColor** pColor);

HRESULT GCADAXEXP GcAxPutTrueColor(GcAxObjectRef& objRef, IGcadAcCmColor* color);

HRESULT GCADAXEXP GcAxGetTrueColor(GcDbObjectId& objid, IGcadAcCmColor** pColor);

HRESULT GCADAXEXP GcAxPutTrueColor(GcDbObjectId& objid, IGcadAcCmColor* color);

HRESULT GCADAXEXP GcAxGetLayer(GcAxObjectRef& objRef, BSTR* pLayer);

HRESULT GCADAXEXP GcAxPutLayer(GcAxObjectRef& objRef, BSTR layer);

HRESULT GCADAXEXP GcAxGetLinetype(GcAxObjectRef& objRef, BSTR* pLinetype);

HRESULT GCADAXEXP GcAxPutLinetype(GcAxObjectRef& objRef, BSTR linetype);

HRESULT GCADAXEXP GcAxGetMaterial(GcAxObjectRef& objRef, BSTR* pMaterial);

HRESULT GCADAXEXP GcAxPutMaterial(GcAxObjectRef& objRef, BSTR material);

HRESULT GCADAXEXP GcAxGetLinetypeScale(GcAxObjectRef& objRef, double* pLinetypeScale);

HRESULT GCADAXEXP GcAxPutLinetypeScale(GcAxObjectRef& objRef, double linetypeScale);


HRESULT GCADAXEXP GcAxGetShadowDisplay(GcAxObjectRef& objRef, GcShadowDisplayType* pShadowDisplay);

HRESULT GCADAXEXP GcAxPutShadowDisplay(GcAxObjectRef& objId, GcShadowDisplayType shadowDisplay);

HRESULT GCADAXEXP GcAxGetVisible(GcAxObjectRef& objRef, VARIANT_BOOL* pVisible);

HRESULT GCADAXEXP GcAxPutVisible(GcAxObjectRef& objRef, VARIANT_BOOL visible);

HRESULT GCADAXEXP GcAxArrayPolar(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numObjs, 
               double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);

HRESULT GCADAXEXP GcAxArrayRectangular(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numRows, 
                     int numCols, int numLvls, double disRows, double disCols,
                     double disLvls, VARIANT* pArrayObjs);

HRESULT GCADAXEXP GcAxHighlight(GcAxObjectRef& objRef, VARIANT_BOOL bHighlight);

HRESULT GCADAXEXP GcAxCopy(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj, 
         GcDbObjectId ownerId = GcDbObjectId::kNull);

HRESULT GCADAXEXP GcAxMove(GcAxObjectRef& objRef, VARIANT fromPoint, VARIANT toPoint);

HRESULT GCADAXEXP GcAxRotate(GcAxObjectRef& objRef, VARIANT basePoint, double rotationAngle);

HRESULT GCADAXEXP GcAxRotate3D(GcAxObjectRef& objRef, VARIANT point1, VARIANT point2, 
             double rotationAngle);

HRESULT GCADAXEXP GcAxMirror(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1, 
           VARIANT point2, LPDISPATCH* pMirrorObj);

HRESULT GCADAXEXP GcAxMirror3D(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1, 
             VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);

HRESULT GCADAXEXP GcAxScaleEntity(GcAxObjectRef& objRef, VARIANT basePoint, double scaleFactor);

HRESULT GCADAXEXP GcAxTransformBy(GcAxObjectRef& objRef, VARIANT transMatrix);

HRESULT GCADAXEXP GcAxUpdate(GcAxObjectRef& objRef);

HRESULT GCADAXEXP GcAxGetBoundingBox(GcAxObjectRef& objRef, VARIANT* minPoint, VARIANT* maxPoint);

HRESULT GCADAXEXP GcAxIntersectWith(GcAxObjectRef& objRef, LPDISPATCH pEntity, 
                  GcExtendOption option, VARIANT* intPoints);

HRESULT GCADAXEXP GcAxGetPlotStyleName(GcAxObjectRef& objRef, BSTR* plotStyleName);

HRESULT GCADAXEXP GcAxPutPlotStyleName(GcAxObjectRef& objRef, BSTR plotStyleName);

HRESULT GCADAXEXP GcAxGetLineWeight(GcAxObjectRef& objRef, GCAD_LWEIGHT* lineWeight);

HRESULT GCADAXEXP GcAxPutLineWeight(GcAxObjectRef& objRef, GCAD_LWEIGHT lineWeight);

HRESULT GCADAXEXP GcAxGetEntityTransparency(GcAxObjectRef& objRef, BSTR* transparency);

HRESULT GCADAXEXP GcAxPutEntityTransparency(GcAxObjectRef& objRef, BSTR transparency);

HRESULT GCADAXEXP GcAxGetHyperlinks(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, 
                  IGcadHyperlinks** pHyperlinks);

HRESULT GCADAXEXP GcAxHasExtensionDictionary(GcAxObjectRef& objRef, VARIANT_BOOL* bHasDictionary);

HRESULT GCADAXEXP GcAxGetExtensionDictionary(GcAxObjectRef& objRef, LPDISPATCH pAppDisp, 
                           IGcadDictionary** pExtDictionary);
HRESULT GCADAXEXP GcAxGetOwnerId(GcAxObjectRef& objRef, Hccad::IntDbId* pOwnerId);

HRESULT GCADAXEXP GcAxEnableShadowDisplay(GcDbObjectId& objRef, bool *);
HRESULT GCADAXEXP GcAxEnableShadowDisplay(GcAxObjectRef& objRef, bool *);

GCADAXEXP const wchar_t* getOPMType(const GcDbObjectId& id);

#endif
