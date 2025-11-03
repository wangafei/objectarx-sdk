
#ifndef __ZOPMEXP_H_
#define __ZOPMEXP_H_

#include "zgeassign.h"  
#include "zdbxutil.h"   

#define BEGIN_ELEMENT_SETGET(theComClass, theZrxClass)              \
    int theComClass::SetGetElementValue(int GetOrSet, DISPID dispid, DWORD cookie, VARIANT *val, ZcDbObject *pObj) \
    {                                                               \
        theZrxClass *TheZrxClass;                                   \
                                                                    \
        if ((TheZrxClass = theZrxClass::cast(pObj)) == NULL)        \
            return 0;


#define ELEMENT_GET_ENTRY(DID, ZCGEType, getelement, vtype)         \
        if (dispid == DID)                                          \
        {                                                           \
            ZCGEType ZcGeType = TheZrxClass->##getelement();        \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                ZCGEType ZcGeTypeUCS;                               \
                zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
                V_R8(val) = ZcGeTypeUCS[cookie];                    \
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
                zcdbWcs2Ucs(dPt, dPtUCS, 0);                        \
                V_R8(val) = dPtUCS[cookie];                         \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            zcdbOpenZcDbObject(pObj, objID, ZcDb::kForRead);        \
            return 1;                                               \
        }

#define ELEMENT_SETGET_ENTRY(DID, ZCGEType, setelement, getelement, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            ZCGEType ZcGeTypeUCS;                                   \
            ZCGEType ZcGeType = TheZrxClass->##getelement();        \
            zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = ZcGeTypeUCS[cookie];                    \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                ZcGeTypeUCS[cookie] = V_R8(val);                    \
                zcdbUcs2Wcs(asDblArray(ZcGeTypeUCS), asDblArray(ZcGeType), 0); \
                TheZrxClass->##setelement(ZcGeType);                \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_SETGET_ENTRY_GEPNT2D(DID, setelement, getelement, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            ZcGePoint3d ZcGeTypeUCS;                                   \
            ZcGePoint2d ZcGeType_tmp = TheZrxClass->##getelement();        \
            ZcGePoint3d ZcGeType(ZcGeType_tmp[0], ZcGeType_tmp[1], 0.0); \
            zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = ZcGeTypeUCS[cookie];                    \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                ZcGeTypeUCS[cookie] = V_R8(val);                    \
                zcdbUcs2Wcs(asDblArray(ZcGeTypeUCS), asDblArray(ZcGeType), 0); \
                TheZrxClass->##setelement(ZcGePoint2d(ZcGeType[0], ZcGeType[1])); \
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
            zcdbWcs2Ucs(dPt, dPtUCS, 0);                            \
                                                                    \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = dPtUCS[cookie];                         \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                dPtUCS[cookie] = V_R8(val);                         \
                zcdbUcs2Wcs(dPtUCS, dPt, 0);                        \
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
            zcdbOpenZcDbObject(pObj, objID, ZcDb::kForRead);        \
            return 1;                                               \
        }

#define ELEMENT_GROUP_SETGET_ENTRY(DID, CountFunc, ZCGEType, setAt, getAt, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            ZCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = TheZrxClass->##CountFunc();             \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            ZCGEType ZcGeType;                                      \
            long grouping = 1;                                      \
            for(int i = 0; pMap[i].pclsidPropPage != NULL; i++)     \
            {                                                       \
                if (pMap[i].dispid == dispid)                       \
                {                                                   \
                    grouping = pMap[i].grouping;                    \
                    break;                                          \
                }                                                   \
            }                                                       \
            ZCGEType ZcGeTypeUCS;                                   \
            TheZrxClass->##getAt(cookie/grouping, ZcGeType);        \
            zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = ZcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                ZcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                zcdbUcs2Wcs(asDblArray(ZcGeTypeUCS), asDblArray(ZcGeType), 0); \
                TheZrxClass->##setAt(cookie/grouping, ZcGeType);    \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_GROUP2_SETGET_ENTRY(DID, CountFunc, ZCGEType, setAt, getAt, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            ZCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = TheZrxClass->##CountFunc();             \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            ZCGEType ZcGeType;                                      \
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
            ZCGEType ZcGeTypeUCS;                                   \
            ZcGeType = TheZrxClass->##getAt(cookie/grouping);       \
            zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = ZcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                ZcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                zcdbUcs2Wcs(asDblArray(ZcGeTypeUCS), asDblArray(ZcGeType), 0); \
                TheZrxClass->##setAt(cookie/grouping, ZcGeType);    \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_GROUP3_SETGET_ENTRY(DID, Count, ZCGEType, setAt, getAt, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            ZCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = Count;                                  \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            ZCGEType ZcGeType;                                      \
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
            ZCGEType ZcGeTypeUCS;                                   \
            TheZrxClass->##getAt((ZSoft::UInt16)(cookie/grouping), ZcGeType); \
            zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                V_R8(val) = ZcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                ZcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                zcdbUcs2Wcs(asDblArray(ZcGeTypeUCS), asDblArray(ZcGeType), 0); \
                TheZrxClass->##setAt((ZSoft::UInt16)(cookie/grouping), ZcGeType); \
            }                                                       \
            return 1;                                               \
        }

#define ELEMENT_ZCDB_ITERATE_SETGET_ENTRY(DID, Iter, recordt, ZCGEType, setelem, getelem, vtype) \
        if (dispid == DID)                                          \
        {                                                           \
            ZcDbObjectIterator* pIter = NULL;                       \
            ZCAD_OPMPROPMAP_ENTRY *pMap = this->GetOPMPropertyMap();\
            if (GetOrSet == ELEMENTCOUNT)                           \
            {                                                       \
                ULONG cnt = 0;                                      \
                pIter = TheZrxClass-> Iter##();                     \
                for (pIter->start(); !pIter->done(); pIter->step())cnt++; \
                delete pIter;                                       \
                V_I4(val) = cnt;                                    \
                V_VT(val) = VT_I4;                                  \
                return 1;                                           \
            }                                                       \
                                                                    \
            ZCGEType ZcGeType;                                      \
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
            pIter = TheZrxClass->Iter();                            \
                                                                    \
            for (pIter->start(); !pIter->done(); pIter->step())     \
            {                                                       \
                if (j == vert)                                      \
                    break;                                          \
                else                                                \
                    j++;                                            \
            }                                                       \
            Zcad::ErrorStatus es;                                   \
            ZcDbObjectId objID = pIter->objectId();                 \
            recordt *record;                                        \
            ZcDbObject *pRecObj;                                    \
                                                                    \
            delete pIter;                                           \
                                                                    \
            if (j != vert)                                          \
                return 0;                                           \
                                                                    \
            if ((es = zcdbOpenZcDbObject(pRecObj, objID,            \
                         GetOrSet == ELEMENTGET ? ZcDb::kForRead :  \
                                     ZcDb::kForWrite)) != Zcad::eOk) \
                return 0;                                           \
                                                                    \
            if ((record = recordt##::cast(pRecObj)) == NULL)        \
            {                                                       \
                pRecObj->close();                                   \
                return 0;                                           \
            }                                                       \
                                                                    \
            ZCGEType ZcGeTypeUCS;                                   \
            ZcGeType = record-> getelem##();                        \
            zcdbWcs2Ucs(asDblArray(ZcGeType), asDblArray(ZcGeTypeUCS), 0); \
            if (GetOrSet == ELEMENTGET)                             \
            {                                                       \
                                                                    \
                V_R8(val) = ZcGeTypeUCS[cookie % grouping ];        \
                V_VT(val) = VT_R8;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                ZcGeTypeUCS[cookie % grouping] = V_R8(val);         \
                zcdbUcs2Wcs(asDblArray(ZcGeTypeUCS), asDblArray(ZcGeType), 0); \
                record-> setelem##(ZcGeType);                       \
            }                                                       \
                                                                    \
           record->close();                                         \
           return 1;                                                \
        }

#define END_ELEMENT_SETGET                                          \
    return 0;                                                       \
    }

#endif
