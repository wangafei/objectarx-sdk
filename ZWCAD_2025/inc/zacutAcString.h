
#pragma once
#include "zAcDbCore2dDefs.h"
#include "zacadstrc.h"
#include "zAcString.h"

/*ZCDBCORE2D_PORT*/ Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);

template <class ObjType> inline Zcad::ErrorStatus zcutGetZcStringConvertToZTChar(
    const ObjType* pObj,
    Zcad::ErrorStatus(ObjType::* pFunc)(ZcString&) const,
    ZTCHAR*& pOutput)
{
    ZcString sOutput;
    const Zcad::ErrorStatus es = (pObj->*pFunc)(sOutput);
    if (es != Zcad::eOk) {
        pOutput = nullptr;
        return es;
    }
    return ::zcutNewString(sOutput.kwszPtr(), pOutput);
}

template <class ObjType> inline ZTCHAR* zcutGetZcStringConvertToZTChar(
    const ObjType* pObj,
    Zcad::ErrorStatus(ObjType::* pFunc)(ZcString&) const)
{
    ZcString sOutput;
    const Zcad::ErrorStatus es = (pObj->*pFunc)(sOutput);
    ZTCHAR* pRet = nullptr;
    if (es == Zcad::eOk)
        ::zcutNewString(sOutput.kwszPtr(), pRet);
    return pRet;
}

inline ZTCHAR* zcutZcStringToZTChar(const ZcString& s, Zcad::ErrorStatus es)
{
    ZTCHAR* pBuf = nullptr;
    if (es == Zcad::eOk)
        ::zcutNewString(s.kwszPtr(), pBuf);
    return pBuf;
}

inline Zcad::ErrorStatus zcutZcStringToZTChar(const ZcString& s, ZTCHAR*& pBuf,
    Zcad::ErrorStatus es)
{
    pBuf = nullptr;
    if (es != Zcad::eOk)
        return es;
    return ::zcutNewString(s.kwszPtr(), pBuf);
}
