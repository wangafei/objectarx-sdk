/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GdGChar.h"
#include "GcValue.h"
#include "GcString.h"

class GcDbField;
class GcFdFieldEngine;

typedef GcArray<GcDbField*> GcDbFieldArray;

typedef struct GcFd
{
  enum EvalFields
  {
    kEvalRecursive = (0x1 << 0),
  };

  enum ConvertFieldToText
  {
    kConvertFieldToTextNone = 0,
    kEvaluateBeforeConversion = (0x1 << 0),
    kExcludeEvaluatorsInList = (0x1 << 1),
    kIgnoreEvaluatorVersion = (0x1 << 2),
  };
} GcFd;

typedef struct GcHyperlink
{
  GcString                msUrl;
  GcString                msSubLocation;
  GcString                msDescription;
  Gsoft::Int32            mlFlag;
} GcHyperlink;

class GCDB_PORT GcDbField : public GcDbObject
{
public:
  enum State
  {
    kInitialized = (0x1 << 0),
    kCompiled = (0x1 << 1),
    kModified = (0x1 << 2),
    kEvaluated = (0x1 << 3),
    kHasCache = (0x1 << 4),
    kHasFormattedString = (0x1 << 5),
  };

  enum EvalOption
  {
    kDisable = 0,
    kOnOpen = (0x1 << 0),
    kOnSave = (0x1 << 1),
    kOnPlot = (0x1 << 2),
    kOnEtransmit = (0x1 << 3),
    kOnRegen = (0x1 << 4),
    kOnDemand = (0x1 << 5),
    kAutomatic = (kOnOpen | kOnSave | kOnPlot |
    kOnEtransmit | kOnRegen | kOnDemand),
  };

  enum EvalContext
  {
    kOpen = (0x1 << 0),
    kSave = (0x1 << 1),
    kPlot = (0x1 << 2),
    kEtransmit = (0x1 << 3),
    kRegen = (0x1 << 4),
    kDemand = (0x1 << 5),
    kPreview = (0x1 << 6),
    kPlotPreview = (0x1 << 7),
  };

  enum EvalStatus
  {
    kNotYetEvaluated = (0x1 << 0),
    kSuccess = (0x1 << 1),
    kEvaluatorNotFound = (0x1 << 2),
    kSyntaxError = (0x1 << 3),
    kInvalidCode = (0x1 << 4),
    kInvalidContext = (0x1 << 5),
    kOtherError = (0x1 << 6),
  };

  enum FieldCodeFlag
  {
    kFieldCode = (0x1 << 0),
    kEvaluatedText = (0x1 << 1),
    kEvaluatedChildren = (0x1 << 2),
    kObjectReference = (0x1 << 3),
    kAddMarkers = (0x1 << 4),
    kEscapeBackslash = (0x1 << 5),
    kStripOptions = (0x1 << 6),
    kPreserveFields = (0x1 << 7),
    kTextField = (0x1 << 8),
    kPreserveOptions = (0x1 << 9),
    kDetachChildren = (0x1 << 10),
    kChildObjectReference = (0x1 << 11),
    kForExpression = (0x1 << 12),
  };

  enum FilingOption
  {
    kSkipFilingResult = (0x1 << 0),
  };

public:
  GCDB_DECLARE_MEMBERS(GcDbField);

  GcDbField(void);
  GcDbField(const GCHAR * pszFieldCode, bool bTextField = false);
  ~GcDbField(void);

  Gcad::ErrorStatus setInObject(GcDbObject* pObj, const GCHAR * pszPropName);
  Gcad::ErrorStatus postInDatabase(GcDbDatabase* pDb);
  GcDbField::State  state(void) const;
  GcDbField::EvalStatus evaluationStatus(int* pnErrCode, GcString * pszErrMsg) const;
  GcDbField::EvalStatus evaluationStatus(int* pnErrCode) const;
  GcDbField::EvalStatus evaluationStatus() const;
  GcDbField::EvalStatus evaluationStatus(int* pnErrCode, GCHAR ** pszErrMsg) const;
  GcDbField::EvalOption evaluationOption(void) const;
  Gcad::ErrorStatus setEvaluationOption(GcDbField::EvalOption nEvalOption);
  GcDbField::FilingOption filingOption(void) const;
  Gcad::ErrorStatus setFilingOption(GcDbField::FilingOption nOption);
  const GCHAR  *    evaluatorId(void) const;
  Gcad::ErrorStatus setEvaluatorId(const GCHAR * pszEvaluatorId);
  bool              isTextField(void) const;
  Gcad::ErrorStatus convertToTextField(void);
  const GCHAR *     getFieldCode(GcDbField::FieldCodeFlag nFlag,
    GcArray<GcDbField*>* pChildFields = NULL,
    GcDb::OpenMode mode = GcDb::kForRead) const;
  Gcad::ErrorStatus getFieldCode(GcString & sFieldCode,
    GcDbField::FieldCodeFlag nFlag,
    GcArray<GcDbField*>* pChildFields = nullptr,
    GcDb::OpenMode mode = GcDb::kForRead) const;
  Gcad::ErrorStatus getFieldCode(GCHAR*& pszFieldCode,
    GcDbField::FieldCodeFlag nFlag,
    GcArray<GcDbField*>* pChildFields = nullptr,
    GcDb::OpenMode mode = GcDb::kForRead) const;
  Gcad::ErrorStatus setFieldCode(const GCHAR* pszFieldCode,
    GcDbField::FieldCodeFlag nFlag = (GcDbField::FieldCodeFlag) 0,
    GcDbFieldArray* pChildFields = NULL);
  int               childCount(void) const;
  Gcad::ErrorStatus getChild(int iIndex, GcDbField*& pField, GcDb::OpenMode mode);

  const GCHAR *     getFormat(void) const;
  Gcad::ErrorStatus getFormat(GcString & sFormat) const;
  Gcad::ErrorStatus getFormat(GCHAR*& pszFormat) const;
  Gcad::ErrorStatus setFormat(const GCHAR* pszFormat);

  Gcad::ErrorStatus evaluate(int nContext,
    GcDbDatabase* pDb,
    int* pNumFound = NULL,
    int* pNumEvaluated = NULL);
  GcValue::DataType dataType(void) const;

  const GCHAR *     getValue(void) const;
  Gcad::ErrorStatus getValue(GcString & sValue) const;
  Gcad::ErrorStatus getValue(GCHAR*& pszValue) const;
  Gcad::ErrorStatus getValue(GcValue& value) const;
  Gcad::ErrorStatus getValue(GcFdFieldValue& value) const;

  bool  hasHyperlink(void) const;
  Gcad::ErrorStatus getHyperlink(GcHyperlink& hlink) const;
  Gcad::ErrorStatus getHyperlink(GcString * psName,
    GcString * psDescription,
    GcString * psSubLocation,
    GcString * psDisplayString,
    Gsoft::Int32* pFlag) const;
#if GCADV_RELMAJOR > 23
#error  getHyperlink(GCHAR**,GCHAR**,GCHAR**,GCHAR**,int) should not be ported anymore. Please remove the  below when we can change.
#else

#endif
  Gcad::ErrorStatus getHyperlink(GCHAR** pszName,
    GCHAR** pszDescription,
    GCHAR** pszSubLocation,
    GCHAR** pszDisplayString,
    Gsoft::Int32* pFlag) const;
  Gcad::ErrorStatus setHyperlink(const GcHyperlink& hlink);
  Gcad::ErrorStatus setHyperlink(const GCHAR* pszName,
    const GCHAR* pszDescription,
    const GCHAR* pszSubLocation = NULL);
  Gcad::ErrorStatus setHyperlink(const GCHAR* pszName,
    const GCHAR* pszDescription,
    const GCHAR* pszSubLocation,
    Gsoft::Int32 lFlag);
  Gcad::ErrorStatus removeHyperlink(void);
  Gcad::ErrorStatus getData(const GCHAR* pszKey, GcValue* pData) const;
  Gcad::ErrorStatus setData(const GCHAR* pszKey, const GcValue* pData);
  Gcad::ErrorStatus setData(const GCHAR* pszKey,
    const GcValue* pData,
    bool bRecursive);

public:
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus subClose() override;
};

inline GcDbField::EvalStatus GcDbField::evaluationStatus(int* pnErrCode) const
{
  GcString *pNullStr = nullptr;
  return this->evaluationStatus(pnErrCode, pNullStr);
}

inline GcDbField::EvalStatus GcDbField::evaluationStatus() const
{
  return this->evaluationStatus(nullptr);
}

inline GcDbField::EvalStatus GcDbField::evaluationStatus(int* pnErrCode, GCHAR ** pszErrMsg) const
{
  GcString sErrMsg;
  GcString * pErrMsgStr = pszErrMsg ? &sErrMsg : nullptr;
  const GcDbField::EvalStatus es = this->evaluationStatus(pnErrCode, pErrMsgStr);
  if (pszErrMsg != nullptr) {
    if (*pErrMsgStr == nullptr)
      *pszErrMsg = nullptr;
    else
      ::gcutNewString(sErrMsg.kwszPtr(), *pszErrMsg);
  }
  return es;
}

inline Gcad::ErrorStatus GcDbField::getFieldCode(GCHAR*& pszFieldCode,
  GcDbField::FieldCodeFlag nFlag,
  GcArray<GcDbField*>* pChildFields,
  GcDb::OpenMode mode) const
{
  GcString sFieldCode;
  return ::gcutGcStringToGChar(sFieldCode, pszFieldCode,
    this->getFieldCode(sFieldCode, nFlag, pChildFields, mode));
}

inline Gcad::ErrorStatus GcDbField::getFormat(GCHAR*& pszFormat) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbField::getFormat, pszFormat);
}

inline Gcad::ErrorStatus GcDbField::getValue(GCHAR*& pszValue) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbField::getValue, pszValue);
}

inline Gcad::ErrorStatus GcDbField::getHyperlink(GCHAR** pszName,
  GCHAR** pszDescription,
  GCHAR** pszSubLocation,
  GCHAR** pszDisplayString,
  Gsoft::Int32* pFlag) const
{
  GcString sName, sDescription, sSubLocation, sDisplayString;
  const Gcad::ErrorStatus es = this->getHyperlink(
    pszName == nullptr ? nullptr : &sName,
    pszDescription == nullptr ? nullptr : &sDescription,
    pszSubLocation == nullptr ? nullptr : &sSubLocation,
    pszDisplayString == nullptr ? nullptr : &sDisplayString,
    pFlag);
  if (pszName != nullptr) {
    *pszName = nullptr;
    if (es == Gcad::eOk)
      ::gcutNewString(sName.kwszPtr(), *pszName);
  }
  if (pszDescription != nullptr) {
    *pszDescription = nullptr;
    if (es == Gcad::eOk)
      ::gcutNewString(sDescription.kwszPtr(), *pszDescription);
  }
  if (pszSubLocation != nullptr) {
    *pszSubLocation = nullptr;
    if (es == Gcad::eOk)
      ::gcutNewString(sSubLocation.kwszPtr(), *pszSubLocation);
  }
  if (pszDisplayString != nullptr) {
    *pszDisplayString = nullptr;
    if (es == Gcad::eOk)
      ::gcutNewString(sDisplayString.kwszPtr(), *pszDisplayString);
  }
  return es;
}

GCDB_PORT GcFdFieldEngine* gcdbGetFieldEngine(void);
GCCORE_PORT bool      gcdbGetFieldMarkers(const GCHAR*& pszPrefix, const GCHAR*& pszSuffix);
GCCORE_PORT bool      gcdbHasFields(const GCHAR * pszText);
GCCORE_PORT bool      gcdbFindField(const GCHAR * pszText,
  int iSearchFrom,
  int& nStartPos,
  int& nEndPos);
GCCORE_PORT Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectId& objId,
  int nContext,
  const GCHAR* pszPropName = NULL,
  GcDbDatabase* pDb = NULL,
  GcFd::EvalFields nEvalFlag = GcFd::kEvalRecursive,
  int* pNumFound = NULL,
  int* pNumEvaluated = NULL);
GCCORE_PORT Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectId& objId,
  int nContext,
  const GcDbObjectIdArray* pFieldsToEvaluate,
  const GCHAR* pszEvaluatorId,
  GcDbDatabase* pDb,
  GcFd::EvalFields nEvalFlag,
  int* pNumFound,
  int* pNumEvaluated);
GCCORE_PORT Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectIdArray& objIds,
  int nContext,
  const GCHAR* pszPropName = NULL,
  GcDbDatabase* pDb = NULL,
  GcFd::EvalFields nEvalFlag = GcFd::kEvalRecursive,
  int* pNumFound = NULL,
  int* pNumEvaluated = NULL);
GCCORE_PORT Gcad::ErrorStatus gcdbEvaluateFields(const GcDbObjectIdArray& objIds,
  int nContext,
  const GcDbObjectIdArray* pFieldsToEvaluate,
  const GCHAR* pszEvaluatorId,
  GcDbDatabase* pDb,
  GcFd::EvalFields nEvalFlag,
  int* pNumFound,
  int* pNumEvaluated);
GCCORE_PORT Gcad::ErrorStatus gcdbConvertFieldsToText(GcDbDatabase* pDb,
  const GcStringArray* pEvalIds,
  GcFd::ConvertFieldToText nOption);
GCCORE_PORT Gcad::ErrorStatus gcdbConvertFieldsToText(const GcDbObjectIdArray& objIds,
  const GcStringArray* pEvalIds,
  GcFd::ConvertFieldToText nOption);
GCCORE_PORT Gcad::ErrorStatus gcdbMakeFieldCode(const GCHAR * pszFieldExpr,
  GcString & sFieldCode,
  const GCHAR * pszEvalId = nullptr,
  const GCHAR * pszFormat = nullptr,
  const GcHyperlink* pHyperlink = nullptr);

inline Gcad::ErrorStatus gcdbMakeFieldCode(const GCHAR * pszFieldExpr,
  GCHAR*& pszFieldCode,
  const GCHAR * pszEvalId,
  const GCHAR * pszFormat,
  const GcHyperlink* pHyperlink)
{
  GcString sFieldCode;
  return ::gcutGcStringToGChar(sFieldCode, pszFieldCode,
    ::gcdbMakeFieldCode(pszFieldExpr, sFieldCode,
      pszEvalId, pszFormat, pHyperlink));
}

GCCORE_PORT GcDbField::EvalOption gcdbGlobalFieldEvaluationOption();
GCCORE_PORT Gcad::ErrorStatus gcdbSetGlobalFieldEvaluationOption(GcDbField::EvalOption nEvalOption);