
#pragma once

#include "zadesk.h"
#include "zAdAChar.h"
#include "zAcCell.h"


#ifdef  ZCFD_API
#  define   ZCFD_PORT  __declspec(dllexport)
#else
#  define   ZCFD_PORT  
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
                                     ZcString& pszFieldCode);

Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);

ZCFD_PORT bool   ZcFdMakeFieldCode(const ZcDbObjectId& objId,
	ZcDbEvalNodeId blockParamId,
	const ZTCHAR * pszPropOrConnectionName,
	ZcFdEval::ObjectFieldOption nOption,
	const ZTCHAR * pszFormat,
	ZcHyperlink* pHyperlink,
	ZTCHAR*& pszFieldCode);

ZCFD_PORT bool   ZcFdMakeFieldCode  (IZcSmDatabase* pSmDb,
                                     IZcSmSheetSet* pSmSheetSet,
                                     IZcSmComponent* pSmComp,
                                     const ZTCHAR * pszCompName,
                                     const ZTCHAR * pszPropName,
                                     ZcFdEval::SheetSetFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZcString& sFieldCode);

ZCFD_PORT bool   ZcFdMakeFieldCode(IZcSmDatabase* pSmDb,
	IZcSmSheetSet* pSmSheetSet,
	IZcSmComponent* pSmComp,
	const ZTCHAR * pszCompName,
	const ZTCHAR * pszPropName,
	ZcFdEval::SheetSetFieldOption nOption,
	const ZTCHAR * pszFormat,
	ZTCHAR*& pszFieldCode);

ZCFD_PORT bool   ZcFdMakeFieldCode  (const ZcDbObjectId& tableId,
                                     const ZcDbObjectId& targetTableId,
                                     ZcFdEval::ExpressionFieldOption nOption,
                                     const ZcCellRangeArray& cellRanges,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZcString& sFieldCode);

ZCFD_PORT bool   ZcFdMakeFieldCode(const ZcDbObjectId& tableId,
	const ZcDbObjectId& targetTableId,
	ZcFdEval::ExpressionFieldOption nOption,
	const ZcCellRangeArray& cellRanges,
	const ZTCHAR * pszFormat,
	ZcHyperlink* pHyperlink,
	ZTCHAR*& pszFieldCode);

ZCFD_PORT bool   ZcFdExtractData    (ZcDbField* pField,
                                     ZcString& sSheetSetFile,
                                     ZcString& sSheetSetId,
                                     ZcString& sCompName,
                                     ZcString& sCompId,
                                     ZcString& sPropName);

ZCFD_PORT bool   ZcFdExtractData(ZcDbField* pField,
	ZTCHAR *& pszSheetSetFile,
	ZTCHAR *& pszSheetSetId,
	ZTCHAR *& pszCompName,
	ZTCHAR *& pszCompId,
	ZTCHAR *& pszPropName);

ZCFD_PORT bool   ZcFdExtractData    (ZcDbField* pField,
                                     ZcDbObjectId& objId,
									 ZcString& sPropName);

ZCFD_PORT bool   ZcFdExtractData(ZcDbField* pField,
	ZcDbObjectId& objId,
	ZTCHAR *& pszPropName);

