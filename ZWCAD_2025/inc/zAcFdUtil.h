
#pragma once
#include "zadesk.h"
#include "zAdAChar.h"
#include "zAcCell.h"

#ifdef  ZCFD_API
    # define ZCFD_PORT __declspec(dllexport)
#else
    # define ZCFD_PORT
#endif

typedef ZSoft::UInt32 ZcDbEvalNodeId;

namespace ZcFdEval
{

    enum ObjectFieldOption
    {
        kObjFieldNone                   = 0,
        kObjFieldUnresolvedBlockRef     = (0x1 << 0),
        kObjFieldApplyBlockTransform    = (0x1 << 1),
        kObjFieldUnresolvedObjectRef    = (0x1 << 2),
    };

    enum SheetSetFieldOption
    {
        kSheetSetNone                   = 0,
        kSheetSetHyperlink              = (0x1 << 0),
        kSheetSetUnresolvedComponent    = (0x1 << 1),
    };

    enum ExpressionFieldOption
    {

        kExprFieldNone                  = 0,
        kExprFieldSum                   = (0x1 << 0),
        kExprFieldAverage               = (0x1 << 1),
        kExprFieldCount                 = (0x1 << 2),
        kExprFieldCell                  = (0x1 << 3),
        kExprFieldEquation              = (0x1 << 4),
    };
};

struct IZcSmDatabase;
struct IZcSmSheetSet;
struct IZcSmComponent;
struct ZcHyperlink;

ZCFD_PORT bool   ZcFdMakeFieldCode  (const ZcDbObjectId& objId,
                                     ZcDbEvalNodeId blockParamId,
                                     const ZTCHAR * pszPropOrConnectionName,
                                     ZcFdEval::ObjectFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZcString & pszFieldCode);

Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);

inline bool   ZcFdMakeFieldCode  (const ZcDbObjectId& objId,
                                     ZcDbEvalNodeId blockParamId,
                                     const ZTCHAR * pszPropOrConnectionName,
                                     ZcFdEval::ObjectFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZTCHAR*& pszFieldCode)
{
    ZcString sFieldCode;
    const bool bRet = ::ZcFdMakeFieldCode(objId, blockParamId, pszPropOrConnectionName,
                                          nOption, pszFormat, pHyperlink, sFieldCode);
    pszFieldCode = nullptr;
    if (bRet)
        ::zcutNewString(sFieldCode.kwszPtr(), pszFieldCode);
    return bRet;
}
ZCFD_PORT bool   ZcFdMakeFieldCode  (IZcSmDatabase* pSmDb,
                                     IZcSmSheetSet* pSmSheetSet,
                                     IZcSmComponent* pSmComp,
                                     const ZTCHAR * pszCompName,
                                     const ZTCHAR * pszPropName,
                                     ZcFdEval::SheetSetFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZcString & pszFieldCode);

inline bool   ZcFdMakeFieldCode  (IZcSmDatabase* pSmDb,
                                     IZcSmSheetSet* pSmSheetSet,
                                     IZcSmComponent* pSmComp,
                                     const ZTCHAR * pszCompName,
                                     const ZTCHAR * pszPropName,
                                     ZcFdEval::SheetSetFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZTCHAR*& pszFieldCode)
{
    ZcString sFieldCode;
    const bool bRet = ::ZcFdMakeFieldCode(pSmDb, pSmSheetSet, pSmComp,
                                          pszCompName, pszPropName, nOption,
                                          pszFormat, sFieldCode);
    pszFieldCode = nullptr;
    if (bRet)
        ::zcutNewString(sFieldCode.kwszPtr(), pszFieldCode);
    return bRet;
}
ZCFD_PORT bool   ZcFdMakeFieldCode  (const ZcDbObjectId& tableId,
                                     const ZcDbObjectId& targetTableId,
                                     ZcFdEval::ExpressionFieldOption nOption,
                                     const ZcCellRangeArray& cellRanges,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZcString& sFieldCode);

inline bool   ZcFdMakeFieldCode  (const ZcDbObjectId& tableId,
                                     const ZcDbObjectId& targetTableId,
                                     ZcFdEval::ExpressionFieldOption nOption,
                                     const ZcCellRangeArray& cellRanges,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZTCHAR*& pszFieldCode)
{
    ZcString sFieldCode;
    const bool bRet = ::ZcFdMakeFieldCode(tableId, targetTableId, nOption,
                                     cellRanges, pszFormat, pHyperlink, sFieldCode);
    pszFieldCode = nullptr;
    if (bRet)
        ::zcutNewString(sFieldCode.kwszPtr(), pszFieldCode);
    return bRet;
}
ZCFD_PORT bool   ZcFdExtractData    (ZcDbField* pField,
                                     ZcString & sSheetSetFile,
                                     ZcString & sSheetSetId,
                                     ZcString & sCompName,
                                     ZcString & sCompId,
                                     ZcString & sPropName);

inline bool   ZcFdExtractData    (ZcDbField* pField,
                                     ZTCHAR *& pszSheetSetFile,
                                     ZTCHAR *& pszSheetSetId,
                                     ZTCHAR *& pszCompName,
                                     ZTCHAR *& pszCompId,
                                     ZTCHAR *& pszPropName)
{
    ZcString sSheetSetFile, sSheetSetId, sCompName, sCompId, sPropName;
    const bool bRet = ::ZcFdExtractData(pField, sSheetSetFile, sSheetSetId,
                                     sCompName, sCompId, sPropName);
    if (!bRet)
        pszSheetSetFile = pszSheetSetId = pszCompName = pszCompId = pszPropName = nullptr;
    else {
        ::zcutNewString(sSheetSetFile, pszSheetSetFile);
        ::zcutNewString(sSheetSetId, pszSheetSetId);
        ::zcutNewString(sCompName, pszCompName);
        ::zcutNewString(sCompId, pszCompId);
        ::zcutNewString(sPropName, pszPropName);
    }
    return bRet;
}
ZCFD_PORT bool   ZcFdExtractData    (ZcDbField* pField,
                                     ZcDbObjectId& objId,
                                     ZcString & sPropName);

inline bool   ZcFdExtractData    (ZcDbField* pField,
                                     ZcDbObjectId& objId,
                                     ZTCHAR *& pszPropName)
{
    ZcString sPropName;
    const bool bRet = ::ZcFdExtractData(pField, objId, sPropName);
    pszPropName = nullptr;
    if (bRet)
        ::zcutNewString(sPropName.kwszPtr(), pszPropName);
    return bRet;
}

