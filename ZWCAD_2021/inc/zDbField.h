

#pragma once

#include "zAdAChar.h"
#include "zAcField.h"
#include "zAcString.h"


class ZcDbField;

typedef ZcArray<ZcDbField*> ZcDbFieldArray;

typedef struct ZcFd
{

    enum EvalFields
    {
        kEvalRecursive      = (0x1 << 0),       
    };

    enum ConvertFieldToText
    {
        kConvertFieldToTextNone         = 0,
        kEvaluateBeforeConversion       = (0x1 << 0),
        kExcludeEvaluatorsInList        = (0x1 << 1),
        kIgnoreEvaluatorVersion         = (0x1 << 2),
    };

} ZcFd;

typedef struct ZcHyperlink
{
    ZcString                msUrl;
    ZcString                msSubLocation;
    ZcString                msDescription;
    ZSoft::Int32            mlFlag;

} ZcHyperlink;

class ZCDBCORE2D_PORT ZcDbField : public ZcDbObject
{
public:
    enum State
    {
        kInitialized        = (0x1 << 0),       
        kCompiled           = (0x1 << 1),       
        kModified           = (0x1 << 2),       
        kEvaluated          = (0x1 << 3),       
        kHasCache           = (0x1 << 4),       
        kHasFormattedString = (0x1 << 5),       
    };

    enum EvalOption
    {
        kDisable            = 0,                
        kOnOpen             = (0x1 << 0),       
        kOnSave             = (0x1 << 1),       
        kOnPlot             = (0x1 << 2),       
        kOnEtransmit        = (0x1 << 3),       
        kOnRegen            = (0x1 << 4),       
        kOnDemand           = (0x1 << 5),       
        kAutomatic          = (kOnOpen | kOnSave | kOnPlot | 
                               kOnEtransmit | kOnRegen | kOnDemand),    
    };

    enum EvalContext
    {
        kOpen               = (0x1 << 0),       
        kSave               = (0x1 << 1),       
        kPlot               = (0x1 << 2),       
        kEtransmit          = (0x1 << 3),       
        kRegen              = (0x1 << 4),       
        kDemand             = (0x1 << 5),       
        kPreview            = (0x1 << 6),       
        kPlotPreview        = (0x1 << 7),
    };

    enum EvalStatus
    {
        kNotYetEvaluated    = (0x1 << 0),       
        kSuccess            = (0x1 << 1),       
        kEvaluatorNotFound  = (0x1 << 2),       
        kSyntaxError        = (0x1 << 3),       
        kInvalidCode        = (0x1 << 4),       
        kInvalidContext     = (0x1 << 5),       
        kOtherError         = (0x1 << 6),       
    };

    enum FieldCodeFlag
    {
        kFieldCode          = (0x1 << 0),       
        kEvaluatedText      = (0x1 << 1),       
        kEvaluatedChildren  = (0x1 << 2),       
        kObjectReference    = (0x1 << 3),       

        kAddMarkers         = (0x1 << 4),       
        kEscapeBackslash    = (0x1 << 5),       
        kStripOptions       = (0x1 << 6),       
        kPreserveFields     = (0x1 << 7),       
        kTextField          = (0x1 << 8),       
        kPreserveOptions    = (0x1 << 9),
        kDetachChildren     = (0x1 << 10),

        kChildObjectReference = (0x1 << 11),

        kForExpression      = (0x1 << 12),

    };

    enum FilingOption
    {
        kSkipFilingResult   = (0x1 << 0),       
    };

public:
    ZCDB_DECLARE_MEMBERS(ZcDbField);

    ZcDbField(void);
    ZcDbField(const ZTCHAR * pszFieldCode, bool bTextField = false);
    ~ZcDbField(void);

    Zcad::ErrorStatus setInObject (ZcDbObject* pObj, 
                                   const ZTCHAR * pszPropName);
    Zcad::ErrorStatus postInDatabase(ZcDbDatabase* pDb);
    ZcDbField::State state        (void) const;
    ZcDbField::EvalStatus evaluationStatus(int* pnErrCode , 
                                             ZcString * pszErrMsg ) const;	
	
	ZcDbField::EvalStatus evaluationStatus(int* pnErrCode) const;   
	ZcDbField::EvalStatus evaluationStatus() const;                 
	ZcDbField::EvalStatus evaluationStatus(int* pnErrCode, 
		ZTCHAR ** pszErrMsg) const;  
	
    ZcDbField::EvalOption evaluationOption(void) const;
    Zcad::ErrorStatus setEvaluationOption(ZcDbField::EvalOption nEvalOption);
    ZcDbField::FilingOption filingOption(void) const;
    Zcad::ErrorStatus setFilingOption(ZcDbField::FilingOption nOption);

    const ZTCHAR  * evaluatorId    (void) const;
    Zcad::ErrorStatus setEvaluatorId(const ZTCHAR * pszEvaluatorId);
    bool            isTextField             (void) const;
    Zcad::ErrorStatus convertToTextField    (void);

    const ZTCHAR * getFieldCode   (ZcDbField::FieldCodeFlag nFlag,
                                             ZcArray<ZcDbField*>* pChildFields = NULL, 
                                             ZcDb::OpenMode mode = ZcDb::kForRead) const;
    Zcad::ErrorStatus getFieldCode(ZcString & FieldCode,
                                             ZcDbField::FieldCodeFlag nFlag,
                                             ZcArray<ZcDbField*>* pChildFields = nullptr, 
                                             ZcDb::OpenMode mode = ZcDb::kForRead) const;
	Zcad::ErrorStatus getFieldCode(ZTCHAR*& pszFieldCode, 
		ZcDbField::FieldCodeFlag nFlag,
		ZcArray<ZcDbField*>* pChildFields = nullptr, 
		ZcDb::OpenMode mode = ZcDb::kForRead) const;	

    Zcad::ErrorStatus setFieldCode(const ZTCHAR* pszFieldCode,
                                             ZcDbField::FieldCodeFlag nFlag = (ZcDbField::FieldCodeFlag) 0,
                                             ZcDbFieldArray* pChildFields = NULL);

    int   childCount              (void) const;
    Zcad::ErrorStatus getChild    (int iIndex, 
                                             ZcDbField*& pField, 
                                             ZcDb::OpenMode mode);

    const ZTCHAR * getFormat       (void) const;
	Zcad::ErrorStatus getFormat   (ZcString & sFormat) const;	
    	Zcad::ErrorStatus getFormat   (ZTCHAR*& pszFormat) const;	
    Zcad::ErrorStatus setFormat   (const ZTCHAR* pszFormat);

    Zcad::ErrorStatus evaluate    (int nContext, 
                                             ZcDbDatabase* pDb, 
                                             int* pNumFound     = NULL,
                                             int* pNumEvaluated = NULL);
    ZcValue::DataType dataType    (void) const;

    const ZTCHAR * getValue        (void) const;
	Zcad::ErrorStatus getValue    (ZcString & sValue) const;	
    Zcad::ErrorStatus getValue    (ZTCHAR*& pszValue) const;
    Zcad::ErrorStatus getValue    (ZcValue& value) const;
    Zcad::ErrorStatus getValue    (ZcFdFieldValue& value) const;

    bool  hasHyperlink            (void) const;
    Zcad::ErrorStatus getHyperlink(ZcHyperlink& hlink) const;
    Zcad::ErrorStatus getHyperlink(ZcString * pszName,
                                             ZcString * pszDescription,
                                             ZcString * pszSubLocation,
                                             ZcString * pszDisplayString,
                                             ZSoft::Int32* pFlag) const;	
	Zcad::ErrorStatus getHyperlink(ZTCHAR** pszName,
								ZTCHAR** pszDescription,
								ZTCHAR** pszSubLocation,
								ZTCHAR** pszDisplayString,
								ZSoft::Int32* pFlag) const;	
    Zcad::ErrorStatus setHyperlink(const ZcHyperlink& hlink);
    Zcad::ErrorStatus setHyperlink(const ZTCHAR* pszName,
                                const ZTCHAR* pszDescription,
                                const ZTCHAR* pszSubLocation = NULL);
    Zcad::ErrorStatus setHyperlink(const ZTCHAR* pszName,
                                const ZTCHAR* pszDescription,
                                const ZTCHAR* pszSubLocation,
                                ZSoft::Int32 lFlag);
    Zcad::ErrorStatus removeHyperlink(void);
     
    Zcad::ErrorStatus getData     (const ZTCHAR* pszKey,
                                ZcValue* pData) const;
    Zcad::ErrorStatus setData     (const ZTCHAR* pszKey,
                                const ZcValue* pData);
    Zcad::ErrorStatus setData     (const ZTCHAR* pszKey,
                                             const ZcValue* pData,
                                             bool bRecursive);

public:
    
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
    virtual Zcad::ErrorStatus subClose() override;
};

ZCDBCORE2D_PORT ZcFdFieldEngine* zcdbGetFieldEngine(void);
ZCDBCORE2D_PORT bool      zcdbGetFieldMarkers     (const ZTCHAR*& pszPrefix,
                                             const ZTCHAR*& pszSuffix);
ZCDBCORE2D_PORT bool      zcdbHasFields           (const ZTCHAR * pszText);
ZCDBCORE2D_PORT bool      zcdbFindField           (const ZTCHAR * pszText,
                                             int iSearchFrom, 
                                             int& nStartPos, 
                                             int& nEndPos);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectId& objId, 
                                             int nContext, 
                                             const ZTCHAR* pszPropName  = NULL,
                                             ZcDbDatabase* pDb          = NULL, 
                                             ZcFd::EvalFields nEvalFlag = ZcFd::kEvalRecursive,
                                             int* pNumFound             = NULL,
                                             int* pNumEvaluated         = NULL);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectId& objId,
                                             int nContext,
                                             const ZcDbObjectIdArray* pFieldsToEvaluate,
                                             const ZTCHAR* pszEvaluatorId,
                                             ZcDbDatabase* pDb,
                                             ZcFd::EvalFields nEvalFlag,
                                             int* pNumFound,
                                             int* pNumEvaluated);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectIdArray& objIds,
                                             int nContext,
                                             const ZTCHAR* pszPropName  = NULL,
                                             ZcDbDatabase* pDb          = NULL, 
                                             ZcFd::EvalFields nEvalFlag = ZcFd::kEvalRecursive,
                                             int* pNumFound             = NULL,
                                             int* pNumEvaluated         = NULL);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbEvaluateFields(const ZcDbObjectIdArray& objIds,
                                             int nContext,
                                             const ZcDbObjectIdArray* pFieldsToEvaluate,
                                             const ZTCHAR* pszEvaluatorId,
                                             ZcDbDatabase* pDb,
                                             ZcFd::EvalFields nEvalFlag,
                                             int* pNumFound,
                                             int* pNumEvaluated);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbConvertFieldsToText(ZcDbDatabase* pDb,
                                             const ZcStringArray* pEvalIds,
                                             ZcFd::ConvertFieldToText nOption);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbConvertFieldsToText(const ZcDbObjectIdArray& objIds,
                                             const ZcStringArray* pEvalIds,
                                             ZcFd::ConvertFieldToText nOption);
ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbMakeFieldCode(const ZTCHAR * pszFieldExpr,
											ZcString & sFieldCode, 
											const ZTCHAR * pszEvalId = nullptr,
											const ZTCHAR * pszFormat = nullptr,
											const ZcHyperlink* pHyperlink = nullptr);	

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbMakeFieldCode(const ZTCHAR * pszFieldExpr,
	ZTCHAR*& pszFieldCode,
	const ZTCHAR * pszEvalId,
	const ZTCHAR * pszFormat,
	const ZcHyperlink* pHyperlink);	
