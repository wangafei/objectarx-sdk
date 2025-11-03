
#pragma once
#include "zadesk.h"
#include "zAdAChar.h"
#include "zDbField.h"
#include "zacutAcString.h"

class ZcDbFieldCache;
class ZcFdFieldResult;
class ZcFdFieldEvaluator;
class ZcFdFieldEvaluatorLoader;
class ZcFdFieldEngine;
class ZcFdFieldValue;
class ZcFdImpFieldFormat;
class ZcDbEvalVariant;

class ZCDBCORE2D_PORT ZcFdFieldEvaluator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEvaluator);

	ZcFdFieldEvaluator(void);
	virtual ~ZcFdFieldEvaluator(void);

	virtual const ZTCHAR * evaluatorId(void) const;
	virtual const ZTCHAR * evaluatorId(ZcDbField* pField);

	virtual Zcad::ErrorStatus initialize(ZcDbField* pField);
	virtual Zcad::ErrorStatus compile(ZcDbField* pField,
                                             ZcDbDatabase* pDb,
                                             ZcFdFieldResult* pResult);
	virtual Zcad::ErrorStatus evaluate(ZcDbField* pField,
                                             int nContext,
                                             ZcDbDatabase* pDb,
                                             ZcFdFieldResult* pResult);
    virtual Zcad::ErrorStatus format(ZcDbField* pField,
                                             ZcString & sValue);
	virtual Zcad::ErrorStatus format(ZcDbField* pField,
                                             ZTCHAR *& pszValue) final;

protected:
    ZcFdFieldEvaluator(void*);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

inline Zcad::ErrorStatus ZcFdFieldEvaluator::format(ZcDbField* pField,
                                                    ZTCHAR *& pszValue)
{
    ZcString sValue;
    return ::zcutZcStringToZTChar(sValue, pszValue, this->format(pField, sValue));
}

class ZCDBCORE2D_PORT ZcFdFieldEvaluatorLoader : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEvaluatorLoader);

    ZcFdFieldEvaluatorLoader(void);
    ZcFdFieldEvaluatorLoader(void*);
    virtual ~ZcFdFieldEvaluatorLoader(void);

    virtual ZcFdFieldEvaluator* getEvaluator(const ZTCHAR * pszEvalId);
    virtual ZcFdFieldEvaluator * findEvaluator(ZcDbField* pField, const ZTCHAR *& pszEvalId);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZCDBCORE2D_PORT ZcFdFieldEngine : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEngine);

	ZcFdFieldEngine();
	virtual ~ZcFdFieldEngine();

	Zcad::ErrorStatus registerEvaluatorLoader(ZcFdFieldEvaluatorLoader* pLoader);
	Zcad::ErrorStatus unregisterEvaluatorLoader(ZcFdFieldEvaluatorLoader* pLoader);
	int   evaluatorLoaderCount(void) const;
	ZcFdFieldEvaluatorLoader * getEvaluatorLoader(int iIndex);
	ZcFdFieldEvaluator * getEvaluator(const ZTCHAR * pszEvalId);
	ZcFdFieldEvaluator * findEvaluator(ZcDbField* pField,
                                             const ZTCHAR *& pszEvalId);

    ZcDbField::EvalOption evaluationOption(void) const;

    Zcad::ErrorStatus setEvaluationOption(ZcDbField::EvalOption nEvalOption);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZCDBCORE2D_PORT ZcFdFieldResult : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldResult);

    ZcFdFieldResult(void);
    virtual Zcad::ErrorStatus setFieldValue(const ZcValue* pValue);
    virtual Zcad::ErrorStatus setEvaluationStatus(int nStatus, 
                                             int dwErrCode = 0,
                                             const ZTCHAR * pszMsg = NULL);
};

class ZCDBCORE2D_PORT ZcFdFieldValue : public ZcValue
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldValue);

    ZcFdFieldValue(void);
    ZcFdFieldValue(ZcFdFieldValue::DataType nDataType);
    ZcFdFieldValue(const ZcFdFieldValue& value);
    ZcFdFieldValue(const ZTCHAR * pszValue);
    ZcFdFieldValue(ZSoft::Int32 lValue);
    ZcFdFieldValue(double fValue);
    ZcFdFieldValue(const ZSoft::Time64& date);
    ZcFdFieldValue(const std::tm& date);
    ZcFdFieldValue(const ZcGePoint2d& pt);
    ZcFdFieldValue(double x, double y);
    ZcFdFieldValue(const ZcGePoint3d& pt);
    ZcFdFieldValue(double x, double y, double z);
    ZcFdFieldValue(const ZcDbObjectId& id);
    ZcFdFieldValue(const resbuf& rb);
    ZcFdFieldValue(const ZcDbEvalVariant& evalVar);
    ZcFdFieldValue(const VARIANT& var);
    ZcFdFieldValue(const void* pBuf, uint32_t dwBufSize);
};

class ZCDBCORE2D_PORT ZcFdFieldReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldReactor);
    virtual ~ZcFdFieldReactor();

    virtual Zcad::ErrorStatus beginEvaluateFields(int nContext,
                                             ZcDbDatabase* pDb)
    {
        return Zcad::eNotApplicable;
    }
    virtual Zcad::ErrorStatus endEvaluateFields(int nContext,
                                             ZcDbDatabase* pDb)
    {
        return Zcad::eNotApplicable;
    }
};

typedef ZcArray<ZcFdFieldReactor*> FieldReactors;

ZCDBCORE2D_PORT Zcad::ErrorStatus   zcdbAddFieldReactor     (ZcFdFieldReactor* pReactor);
ZCDBCORE2D_PORT Zcad::ErrorStatus   zcdbRemoveFieldReactor  (ZcFdFieldReactor* pReactor);
