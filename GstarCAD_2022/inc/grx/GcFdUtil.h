#pragma once
#include "dbeval.h"
struct GcHyperlink;
typedef OdArray<OdCellRange> GcCellRangeArray;

namespace GcFdEval
{
  // Option bit flags for object property field
  enum ObjectFieldOption
  {
    kObjFieldNone = 0,
    kObjFieldUnresolvedBlockRef = (0x1 << 0),
    kObjFieldApplyBlockTransform = (0x1 << 1),
    kObjFieldUnresolvedObjectRef = (0x1 << 2),
  };

  // Option bit flags for sheet set field
  enum SheetSetFieldOption
  {
    kSheetSetNone = 0,
    kSheetSetHyperlink = (0x1 << 0),
    kSheetSetUnresolvedComponent = (0x1 << 1),
  };

  // Option bit flags for expression field
  enum ExpressionFieldOption
  {
    // Function types
    kExprFieldNone = 0,
    kExprFieldSum = (0x1 << 0),
    kExprFieldAverage = (0x1 << 1),
    kExprFieldCount = (0x1 << 2),
    kExprFieldCell = (0x1 << 3),
    kExprFieldEquation = (0x1 << 4),
  };
};

GCAP_DLL_DECL BOOL   GcFdMakeFieldCode(const GcDbObjectId& objId,
  GcDbEvalNodeId blockParamId,
  const GCHAR * pszPropOrConnectionName,
  GcFdEval::ObjectFieldOption nOption,
  const GCHAR * pszFormat,
  GcHyperlink* pHyperlink,
  GCHAR*& pszFieldCode);

GCAP_DLL_DECL BOOL   GcFdMakeFieldCode(const GcDbObjectId& tableId,
  const GcDbObjectId& targetTableId,
  GcFdEval::ExpressionFieldOption nOption,
  const GcCellRangeArray& cellRanges,
  const GCHAR * pszFormat,
  GcHyperlink* pHyperlink,
  GCHAR*& pszFieldCode);

#define AcFdExtractData  GcFdExtractData
GCAP_DLL_DECL BOOL   GcFdExtractData(GcDbField* pField,
  GCHAR *& pszSheetSetFile,
  GCHAR *& pszSheetSetId,
  GCHAR *& pszCompName,
  GCHAR *& pszCompId,
  GCHAR *& pszPropName);

GCAP_DLL_DECL BOOL   GcFdExtractData(GcDbField* pField,
  GcDbObjectId& objId,
  GCHAR *& pszPropName);