/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gsoft.h"
#include "GdGChar.h"
#include "GcCell.h"

#ifdef  GCFD_API
# define GCFD_PORT __declspec(dllexport)
#else
# define GCFD_PORT
#endif

typedef Gsoft::UInt32 GcDbEvalNodeId;

namespace GcFdEval
{
  enum ObjectFieldOption
  {
    kObjFieldNone = 0,
    kObjFieldUnresolvedBlockRef = (0x1 << 0),
    kObjFieldApplyBlockTransform = (0x1 << 1),
    kObjFieldUnresolvedObjectRef = (0x1 << 2),
  };

  enum SheetSetFieldOption
  {
    kSheetSetNone = 0,
    kSheetSetHyperlink = (0x1 << 0),
    kSheetSetUnresolvedComponent = (0x1 << 1),
  };

  enum ExpressionFieldOption
  {
    kExprFieldNone = 0,
    kExprFieldSum = (0x1 << 0),
    kExprFieldAverage = (0x1 << 1),
    kExprFieldCount = (0x1 << 2),
    kExprFieldCell = (0x1 << 3),
    kExprFieldEquation = (0x1 << 4),
  };
};

struct IGcSmDatabase;
struct IGcSmSheetSet;
struct IGcSmComponent;
struct GcHyperlink;

GCAD_PORT bool   GcFdMakeFieldCode(const GcDbObjectId& objId,
  GcDbEvalNodeId blockParamId,
  const GCHAR * pszPropOrConnectionName,
  GcFdEval::ObjectFieldOption nOption,
  const GCHAR * pszFormat,
  GcHyperlink* pHyperlink,
  GcString & pszFieldCode);

GCBASE_PORT Gcad::ErrorStatus gcutNewString(const GCHAR* pInput, GCHAR*& pOutput);

inline bool   GcFdMakeFieldCode(const GcDbObjectId& objId,
  GcDbEvalNodeId blockParamId,
  const GCHAR * pszPropOrConnectionName,
  GcFdEval::ObjectFieldOption nOption,
  const GCHAR * pszFormat,
  GcHyperlink* pHyperlink,
  GCHAR*& pszFieldCode)
{
  GcString sFieldCode;
  const bool bRet = ::GcFdMakeFieldCode(objId, blockParamId, pszPropOrConnectionName,
    nOption, pszFormat, pHyperlink, sFieldCode);
  pszFieldCode = nullptr;
  if (bRet)
    ::gcutNewString(sFieldCode.kwszPtr(), pszFieldCode);
  return bRet;
}
GCAD_PORT bool   GcFdMakeFieldCode(IGcSmDatabase* pSmDb,
  IGcSmSheetSet* pSmSheetSet,
  IGcSmComponent* pSmComp,
  const GCHAR * pszCompName,
  const GCHAR * pszPropName,
  GcFdEval::SheetSetFieldOption nOption,
  const GCHAR * pszFormat,
  GcString & pszFieldCode);
inline bool   GcFdMakeFieldCode(IGcSmDatabase* pSmDb,
  IGcSmSheetSet* pSmSheetSet,
  IGcSmComponent* pSmComp,
  const GCHAR * pszCompName,
  const GCHAR * pszPropName,
  GcFdEval::SheetSetFieldOption nOption,
  const GCHAR * pszFormat,
  GCHAR*& pszFieldCode)
{
  GcString sFieldCode;
  const bool bRet = ::GcFdMakeFieldCode(pSmDb, pSmSheetSet, pSmComp,
    pszCompName, pszPropName, nOption,
    pszFormat, sFieldCode);
  pszFieldCode = nullptr;
  if (bRet)
    ::gcutNewString(sFieldCode.kwszPtr(), pszFieldCode);
  return bRet;
}
GCAD_PORT bool   GcFdMakeFieldCode(const GcDbObjectId& tableId,
  const GcDbObjectId& targetTableId,
  GcFdEval::ExpressionFieldOption nOption,
  const GcCellRangeArray& cellRanges,
  const GCHAR * pszFormat,
  GcHyperlink* pHyperlink,
  GcString & sFieldCode);
inline bool   GcFdMakeFieldCode(const GcDbObjectId& tableId,
  const GcDbObjectId& targetTableId,
  GcFdEval::ExpressionFieldOption nOption,
  const GcCellRangeArray& cellRanges,
  const GCHAR * pszFormat,
  GcHyperlink* pHyperlink,
  GCHAR*& pszFieldCode)
{
  GcString sFieldCode;
  const bool bRet = ::GcFdMakeFieldCode(tableId, targetTableId, nOption,
    cellRanges, pszFormat, pHyperlink, sFieldCode);
  pszFieldCode = nullptr;
  if (bRet)
    ::gcutNewString(sFieldCode.kwszPtr(), pszFieldCode);
  return bRet;
}
GCAD_PORT bool   GcFdExtractData(GcDbField* pField,
  GcString & sSheetSetFile,
  GcString & sSheetSetId,
  GcString & sCompName,
  GcString & sCompId,
  GcString & sPropName);
inline bool   GcFdExtractData(GcDbField* pField,
  GCHAR *& pszSheetSetFile,
  GCHAR *& pszSheetSetId,
  GCHAR *& pszCompName,
  GCHAR *& pszCompId,
  GCHAR *& pszPropName)
{
  GcString sSheetSetFile, sSheetSetId, sCompName, sCompId, sPropName;
  const bool bRet = ::GcFdExtractData(pField, sSheetSetFile, sSheetSetId,
    sCompName, sCompId, sPropName);
  if (!bRet)
    pszSheetSetFile = pszSheetSetId = pszCompName = pszCompId = pszPropName = nullptr;
  else {
    ::gcutNewString(sSheetSetFile, pszSheetSetFile);
    ::gcutNewString(sSheetSetId, pszSheetSetId);
    ::gcutNewString(sCompName, pszCompName);
    ::gcutNewString(sCompId, pszCompId);
    ::gcutNewString(sPropName, pszPropName);
  }
  return bRet;
}
GCAD_PORT bool   GcFdExtractData(GcDbField* pField,
  GcDbObjectId& objId,
  GcString & sPropName);
inline bool   GcFdExtractData(GcDbField* pField,
  GcDbObjectId& objId,
  GCHAR *& pszPropName)
{
  GcString sPropName;
  const bool bRet = ::GcFdExtractData(pField, objId, sPropName);
  pszPropName = nullptr;
  if (bRet)
    ::gcutNewString(sPropName.kwszPtr(), pszPropName);
  return bRet;
}