/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gsoft.h"
#include "GdGChar.h"
#include "DbField.h"

class GcDbFieldCache;
class GcFdFieldResult;
class GcFdFieldEvaluator;
class GcFdFieldEvaluatorLoader;
class GcFdFieldEngine;
class GcFdFieldValue;
class GcFdImpFieldFormat;
class GcDbEvalVariant;

class GCDB_PORT GcFdFieldEvaluator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcFdFieldEvaluator);

  GcFdFieldEvaluator(void);
  ~GcFdFieldEvaluator(void);

  virtual const GCHAR * evaluatorId(void) const;
  virtual const GCHAR * evaluatorId(GcDbField* pField);

  virtual Gcad::ErrorStatus initialize(GcDbField* pField);
  virtual Gcad::ErrorStatus compile(GcDbField* pField,
    GcDbDatabase* pDb,
    GcFdFieldResult* pResult);
  virtual Gcad::ErrorStatus evaluate(GcDbField* pField,
    int nContext,
    GcDbDatabase* pDb,
    GcFdFieldResult* pResult);
  virtual Gcad::ErrorStatus format(GcDbField* pField,
    GcString & sValue);
  virtual Gcad::ErrorStatus format(GcDbField* pField,
    GCHAR *& pszValue) final;

protected:
  GcFdFieldEvaluator(void*);

protected:
  void *mpImpObj;

private:
  friend class GcFdSystemInternals;
};

inline Gcad::ErrorStatus GcFdFieldEvaluator::format(GcDbField* pField,
  GCHAR *& pszValue)
{
  GcString sValue;
  return ::gcutGcStringToGChar(sValue, pszValue, this->format(pField, sValue));
}

class GCDB_PORT GcFdFieldEvaluatorLoader : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcFdFieldEvaluatorLoader);

  GcFdFieldEvaluatorLoader(void);
  GcFdFieldEvaluatorLoader(void*);
  ~GcFdFieldEvaluatorLoader(void);

  virtual GcFdFieldEvaluator* getEvaluator(
    const GCHAR * pszEvalId);
  virtual GcFdFieldEvaluator * findEvaluator(GcDbField* pField,
    const GCHAR *& pszEvalId);

protected:
  void *mpImpObj;

private:
  friend class GcFdSystemInternals;
};

class GCDB_PORT GcFdFieldEngine : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcFdFieldEngine);

  GcFdFieldEngine();
  ~GcFdFieldEngine();

  Gcad::ErrorStatus registerEvaluatorLoader(GcFdFieldEvaluatorLoader* pLoader);
  Gcad::ErrorStatus unregisterEvaluatorLoader(GcFdFieldEvaluatorLoader* pLoader);
  int   evaluatorLoaderCount(void) const;
  GcFdFieldEvaluatorLoader * getEvaluatorLoader(int iIndex);
  GcFdFieldEvaluator * getEvaluator(const GCHAR * pszEvalId);
  GcFdFieldEvaluator * findEvaluator(GcDbField* pField,
    const GCHAR *& pszEvalId);
  GcDbField::EvalOption evaluationOption(void) const;
  Gcad::ErrorStatus setEvaluationOption(GcDbField::EvalOption nEvalOption);

protected:
  void *mpImpObj;

private:
  friend class GcFdSystemInternals;
};

class GCDB_PORT GcFdFieldResult : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcFdFieldResult);

  GcFdFieldResult(void);
  virtual Gcad::ErrorStatus setFieldValue(const GcValue* pValue);
  virtual Gcad::ErrorStatus setEvaluationStatus(int nStatus,
    int dwErrCode = 0,
    const GCHAR * pszMsg = NULL);
};

class GCDB_PORT GcFdFieldValue : public GcValue
{
public:
  GCRX_DECLARE_MEMBERS(GcFdFieldValue);

  GcFdFieldValue(void);
  GcFdFieldValue(GcFdFieldValue::DataType nDataType);
  GcFdFieldValue(const GcFdFieldValue& value);
  GcFdFieldValue(const GCHAR * pszValue);
  GcFdFieldValue(Gsoft::Int32 lValue);
  GcFdFieldValue(double fValue);
  GcFdFieldValue(const Gsoft::Time64& date);
  GcFdFieldValue(const std::tm& date);
  GcFdFieldValue(const GcGePoint2d& pt);
  GcFdFieldValue(double x, double y);
  GcFdFieldValue(const GcGePoint3d& pt);
  GcFdFieldValue(double x, double y, double z);
  GcFdFieldValue(const GcDbObjectId& id);
  GcFdFieldValue(const resbuf& rb);
  GcFdFieldValue(const GcDbEvalVariant& evalVar);
  GcFdFieldValue(const VARIANT& var);
  GcFdFieldValue(const void* pBuf, uint32_t dwBufSize);
};

class GCDB_PORT GcFdFieldReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcFdFieldReactor);

  virtual Gcad::ErrorStatus beginEvaluateFields(int nContext,
    GcDbDatabase* pDb);
  virtual Gcad::ErrorStatus endEvaluateFields(int nContext,
    GcDbDatabase* pDb);
};

typedef GcArray<GcFdFieldReactor*> FieldReactors;

GCCORE_PORT Gcad::ErrorStatus   gcdbAddFieldReactor(GcFdFieldReactor* pReactor);
GCCORE_PORT Gcad::ErrorStatus   gcdbRemoveFieldReactor(GcFdFieldReactor* pReactor);