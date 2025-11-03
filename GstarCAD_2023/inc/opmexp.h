/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __OPMEXP_H_
#define __OPMEXP_H_

#include "geassign.h"
#include "dbxutil.h"

#define BEGIN_ELEMENT_SETGET(theComClass, theGrxClass)              \
    int theComClass::SetGetElementValue(int GetOrSet, DISPID dispid, DWORD cookie, VARIANT *val, GcDbObject *pObj) \
    {                                                               \
        theGrxClass *TheGrxClass;                                   \
                                                                    \
        if ((TheGrxClass = theGrxClass::cast(pObj)) == NULL)        \
            return 0;

#define ELEMENT_GET_ENTRY(DID, GCGEType, getelement, vtype)         \
        if (dispid == DID)                                          \
        {                                                           \
            GCGEType GcGeType = TheGrxClass->##getelement();        \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                GCGEType GcGeTypeUCS;                               \
                gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
                V_R8(val) = GcGeTypeUCS[cookie];                    \
                V_VT(val) = VT_R8;                                  \
                return 1;                                           \
            }                                                       \
        }

#define COM_ELEMENT_GET_ENTRY(DID, comclass, getfunc, objID)        \
        if (dispid == DID)                                          \
        {                                                           \
            VARIANT dumVar;                                         \
            VariantInit(&dumVar);                                   \
            pObj->close();                                          \
            I##comclass *p = static_cast<I##comclass *>(this);      \
            if(FAILED(p->##getfunc(&dumVar)))                       \
                return 0;                                           \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                double dPt[3]; double dPtUCS[3];                    \
                if(FAILED(SafeArrayPointToDoubleArrayPoint(V_ARRAY(&dumVar), dPt))) \
                    return 0;                                       \
                gcdbWcs2Ucs(dPt, dPtUCS, 0);                        \
                V_R8(val) = dPtUCS[cookie];                         \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            gcdbOpenGcDbObject(pObj, objID, GcDb::kForRead);        \
            return 1;                                               \
        }

#define ELEMENT_SETGET_ENTRY(DID, GCGEType, setelement, getelement, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            GCGEType GcGeTypeUCS;                                   \
            GCGEType GcGeType = TheGrxClass->##getelement();        \
            gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = GcGeTypeUCS[cookie];                    \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                GcGeTypeUCS[cookie] = V_R8(val);                    \
                gcdbUcs2Wcs(asDblArray(GcGeTypeUCS), asDblArray(GcGeType), 0); \
                TheGrxClass->##setelement(GcGeType);                \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_SETGET_ENTRY_GEPNT2D(DID, setelement, getelement, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            GcGePoint3d GcGeTypeUCS;                                   \
            GcGePoint2d GcGeType_tmp = TheGrxClass->##getelement();        \
            GcGePoint3d GcGeType(GcGeType_tmp[0], GcGeType_tmp[1], 0.0); \
            gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = GcGeTypeUCS[cookie];                    \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                GcGeTypeUCS[cookie] = V_R8(val);                    \
                gcdbUcs2Wcs(asDblArray(GcGeTypeUCS), asDblArray(GcGeType), 0); \
                TheGrxClass->##setelement(GcGePoint2d(GcGeType[0], GcGeType[1])); \
            }                                                       \
            return 1;                                               \
        }

#define COM_ELEMENT_SETGET_ENTRY(DID, comclass, setfunc, getfunc, objID) \
        if (dispid == DID)                                          \
        {                                                           \
            VARIANT dumVar;                                         \
            VariantInit(&dumVar);                                   \
            pObj->close();                                          \
                                                                    \
            I##comclass *p = static_cast<I##comclass *>(this);      \
            if(FAILED(p->##getfunc(&dumVar)))                       \
                return 0;                                           \
                                                                    \
            double dPt[3]; double dPtUCS[3];                        \
            if(FAILED(SafeArrayPointToDoubleArrayPoint(V_ARRAY(&dumVar), dPt))) \
                return 0;                                           \
            gcdbWcs2Ucs(dPt, dPtUCS, 0);                            \
                                                                    \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = dPtUCS[cookie];                         \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                dPtUCS[cookie] = V_R8(val);                         \
                gcdbUcs2Wcs(dPtUCS, dPt, 0);                        \
                                                                    \
                SAFEARRAY* pSafeArr;                                \
                if(FAILED(CreateSafeArray(VT_R8, 3, &pSafeArr)))    \
                    return 0;                                       \
                if(FAILED(DoubleArrayPointToSafeArrayPoint(dPt,pSafeArr))) \
                {                                                   \
                    SafeArrayDestroy(pSafeArr);                     \
                    return 0;                                       \
                }                                                   \
                VARIANT var;                                        \
                V_ARRAY(&var) = pSafeArr;                           \
                V_VT(&var) = VT_R8 | VT_ARRAY;                      \
                if(FAILED(p->##setfunc(var)))                       \
                {                                                   \
                    SafeArrayDestroy(pSafeArr);                     \
                    return 0;                                       \
                }                                                   \
                SafeArrayDestroy(pSafeArr);                         \
            }                                                       \
            gcdbOpenGcDbObject(pObj, objID, GcDb::kForRead);        \
            return 1;                                               \
        }

#define ELEMENT_GROUP_SETGET_ENTRY(DID, CountFunc, GCGEType, setAt, getAt, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            GCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = TheGrxClass->##CountFunc();             \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            GCGEType GcGeType;                                      \
            long grouping = 1;                                      \
            for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)     \
            {                                                       \
                if (pMap[i].dispid == dispid)                       \
                {                                                   \
                    grouping = pMap[i].grouping;                    \
                    break;                                          \
                }                                                   \
            }                                                       \
            GCGEType GcGeTypeUCS;                                   \
            TheGrxClass->##getAt(cookie/grouping, GcGeType);        \
            gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = GcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                GcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                gcdbUcs2Wcs(asDblArray(GcGeTypeUCS), asDblArray(GcGeType), 0); \
                TheGrxClass->##setAt(cookie/grouping, GcGeType);    \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_GROUP2_SETGET_ENTRY(DID, CountFunc, GCGEType, setAt, getAt, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            GCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = TheGrxClass->##CountFunc();             \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            GCGEType GcGeType;                                      \
            long grouping = 1;                                      \
            for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)     \
            {                                                       \
                if (pMap[i].dispid == dispid)                       \
                {                                                   \
                    grouping = pMap[i].grouping;                    \
                    break;                                          \
                }                                                   \
            }                                                       \
                                                                    \
            GCGEType GcGeTypeUCS;                                   \
            GcGeType = TheGrxClass->##getAt(cookie/grouping);       \
            gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = GcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                GcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                gcdbUcs2Wcs(asDblArray(GcGeTypeUCS), asDblArray(GcGeType), 0); \
                TheGrxClass->##setAt(cookie/grouping, GcGeType);    \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_GROUP3_SETGET_ENTRY(DID, Count, GCGEType, setAt, getAt, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            GCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = Count;                                  \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            GCGEType GcGeType;                                      \
            long grouping = 1;                                      \
            for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)     \
            {                                                       \
                if (pMap[i].dispid == dispid)                       \
                {                                                   \
                    grouping = pMap[i].grouping;                    \
                    break;                                          \
                }                                                   \
            }                                                       \
                                                                    \
            GCGEType GcGeTypeUCS;                                   \
            TheGrxClass->##getAt((Gsoft::UInt16)(cookie/grouping), GcGeType); \
            gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = GcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                GcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                gcdbUcs2Wcs(asDblArray(GcGeTypeUCS), asDblArray(GcGeType), 0); \
                TheGrxClass->##setAt((Gsoft::UInt16)(cookie/grouping), GcGeType); \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_GCDB_ITERATE_SETGET_ENTRY(DID, Iter, recordt, GCGEType, setelem, getelem, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            GcDbObjectIterator* pIter = NULL;                       \
            GCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = 0;                                      \
                pIter = TheGrxClass-> Iter##();                     \
                for (pIter->start(); !pIter->done(); pIter->step())cnt++; \
                delete pIter;                                       \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            GCGEType GcGeType;                                      \
            long grouping = 1;                                      \
            for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)     \
            {                                                       \
                if (pMap[i].dispid == dispid)                       \
                {                                                   \
                    grouping = pMap[i].grouping;                    \
                    break;                                          \
                }                                                   \
            }                                                       \
                                                                    \
            int j =  0;                                             \
            int vert = cookie/grouping;                             \
            pIter = TheGrxClass->Iter();                            \
                                                                    \
            for (pIter->start(); !pIter->done(); pIter->step())     \
            {                                                       \
                if (j == vert)                                      \
                    break;                                          \
                else                                                \
                    j++;                                            \
            }                                                       \
            Gcad::ErrorStatus es;                                   \
            GcDbObjectId objID = pIter->objectId();                 \
            recordt *record;                                        \
            GcDbObject *pRecObj;                                    \
                                                                    \
            delete pIter;                                           \
                                                                    \
            if (j != vert)                                          \
                return 0;                                           \
                                                                    \
            if ((es = gcdbOpenGcDbObject(pRecObj, objID,            \
                         GetOrSet == ELEMENTGET ? GcDb::kForRead :  \
                                     GcDb::kForWrite)) != Gcad::eOk) \
                return 0;                                           \
                                                                    \
            if ((record = recordt##::cast(pRecObj)) == NULL)        \
            {                                                       \
                pRecObj->close();                                   \
                return 0;                                           \
            }                                                       \
                                                                    \
            GCGEType GcGeTypeUCS;                                   \
            GcGeType = record-> getelem##();                        \
            gcdbWcs2Ucs(asDblArray(GcGeType), asDblArray(GcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                                                                    \
                V_R8(val) = GcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                GcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                gcdbUcs2Wcs(asDblArray(GcGeTypeUCS), asDblArray(GcGeType), 0); \
                record-> setelem##(GcGeType);                       \
            }                                                       \
                                                                    \
           record->close();                                         \
           return 1;                                                \
        }

#define END_ELEMENT_SETGET                                          \
    return 0;                                                       \
    }

#endif
