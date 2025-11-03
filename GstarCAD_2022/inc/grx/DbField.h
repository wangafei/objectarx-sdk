#pragma once
#include "gcadstd.h"
#include "../DbField.h"
#include "../DbFieldValue.h"


GCDB_DLL_DECL bool gcdbGetFieldMarkers(const GCHAR*& pszPrefix, const GCHAR*& pszSuffix);
GCDB_DLL_DECL bool gcdbHasFields(const GCHAR * pszText);
GCDB_DLL_DECL bool gcdbFindField(const GCHAR * pszText,int iSearchFrom,int& nStartPos,int& nEndPos);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectId& objId, 
                                             int nContext, 
                                             const GCHAR* pszPropName = NULL, 
                                             GcDbDatabase* pDb        = NULL, 
                                             GcFd::EvalFields nEvalFlag = GcFd::kEvalRecursive,
                                             int* pNumFound           = NULL,
                                             int* pNumEvaluated       = NULL);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectId& objId, 
                                             int nContext, 
                                             const GcDbObjectIdArray* pFieldsToEvaluate, 
                                             const GCHAR* pszEvaluatorId, 
                                             GcDbDatabase* pDb, 
                                             GcFd::EvalFields nEvalFlag, 
                                             int* pNumFound, 
                                             int* pNumEvaluated);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectIdArray& objIds, 
                                             int nContext, 
                                             const GCHAR* pszPropName  = NULL, 
                                             GcDbDatabase* pDb         = NULL, 
                                             GcFd::EvalFields nEvalFlag = GcFd::kEvalRecursive, 
                                             int* pNumFound            = NULL, 
                                             int* pNumEvaluated        = NULL);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectIdArray& objIds, 
                                             int nContext, 
                                             const GcDbObjectIdArray* pFieldsToEvaluate, 
                                             const GCHAR* pszEvaluatorId, 
                                             GcDbDatabase* pDb, 
                                             GcFd::EvalFields nEvalFlag, 
                                             int* pNumFound, 
                                             int* pNumEvaluated);