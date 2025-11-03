#pragma once

#include "DbField.h"

GCDB_DLL_DECL Gcad::ErrorStatus gcdbConvertFieldsToText(GcDbDatabase* pDb,
  const GcStringArray* pEvalIds,
  GcFd::ConvertFieldToText nOption);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbConvertFieldsToText(const GcDbObjectIdArray& objIds,
  const GcStringArray* pEvalIds,
  GcFd::ConvertFieldToText nOption);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbMakeFieldCode(const GCHAR * pszFieldExpr,
  GCHAR*& pszFieldCode);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbMakeFieldCode(const GCHAR * pszFieldExpr,
  GCHAR*& pszFieldCode,
  const GCHAR * pszEvalId,
  const GCHAR * pszFormat,
  const OdHyperlink* pHyperlink);