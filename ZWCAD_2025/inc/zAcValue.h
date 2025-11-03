

#pragma once

#include "zadesk.h"
#include "zAdAChar.h"
#include "zAcArray.h"  
#include "zacadstrc.h"  
#include "zrxobject.h"  

class ZcDbEvalVariant;
typedef struct tagVARIANT VARIANT;
typedef struct _SYSTEMTIME SYSTEMTIME;
class ZcDbObjectId;
class ZcGePoint2d;
class ZcGePoint3d;
class ZcCmColor;
struct resbuf;
class ZcDbDwgFiler;
class ZcDbDxfFiler;

Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);

class ZCDBCORE2D_PORT ZcValue : public ZcRxObject
{
public:
    enum DataType
    {
        kUnknown            = 0,
        kLong               = (0x1 << 0),
        kDouble             = (0x1 << 1),
        kString             = (0x1 << 2),
        kDate               = (0x1 << 3),
        kPoint              = (0x1 << 4),
        k3dPoint            = (0x1 << 5),
        kObjectId           = (0x1 << 6),
        kBuffer             = (0x1 << 7),
        kResbuf             = (0x1 << 8),
        kGeneral            = (0x1 << 9),
        kColor              = (0x1 << 10),
    };

    enum UnitType
    {
        kUnitless           = 0,
        kDistance           = (0x1 << 0),
        kAngle              = (0x1 << 1),
        kArea               = (0x1 << 2),
        kVolume             = (0x1 << 3),
        kCurrency           = (0x1 << 4),
        kPercentage         = (0x1 << 5),
		kAngleNotTransformed = (0x1 << 16),
    };

    enum ParseOption
    {
        kParseOptionNone        = 0,
        kSetDefaultFormat       = (0x1 << 0),
        kPreserveMtextFormat    = (0x1 << 1),
        kConvertTextToValue     = (0x1 << 2),
        kChangeDataType         = (0x1 << 3),
        kParseTextForFieldCode  = (0x1 << 4),
    };

    enum FormatOption
    {
        kFormatOptionNone       = 0,
        kForEditing             = (0x1 << 0),
        kForExpression          = (0x1 << 1),
        kUseMaximumPrecision    = (0x1 << 2),
        kIgnoreMtextFormat      = (0x1 << 3),
    };

public:
    static bool   isValidDataType         (const VARIANT& var); 

public:
    ZCRX_DECLARE_MEMBERS(ZcValue);

	ZcValue(void);
	ZcValue(ZcValue::DataType nDataType);
	ZcValue(const ZcValue& value);
	ZcValue(ZcValue && value);		
	ZcValue(const ZTCHAR * pszValue);
    explicit ZcValue(ZSoft::Int32 lValue);
    ZcValue(double fValue);
    explicit ZcValue(const ZSoft::Time64& date);
    ZcValue(const SYSTEMTIME& date);
	ZcValue(const std::tm& date);	
    ZcValue(const ZcGePoint2d& pt);
    ZcValue(double x, double y);
    ZcValue(const ZcGePoint3d& pt);
    ZcValue(double x, double y, double z);
    ZcValue(const ZcDbObjectId& id);
    ZcValue(const resbuf& rb);
    ZcValue(const ZcDbEvalVariant& evalVar);
    ZcValue(const VARIANT& var);
    ZcValue(const ZcCmColor& var);
    ZcValue(const void* pBuf, uint32_t dwBufSize);

    ~ZcValue(void);

    bool  reset                   (void);
    bool  reset                   (ZcValue::DataType nDataType);
    bool  resetValue              (void);
    ZcValue::DataType dataType     (void) const;
    ZcValue::UnitType unitType     (void) const;
    bool  setUnitType             (ZcValue::UnitType nUnitType);
    const ZTCHAR* getFormat        (void) const;
    bool  setFormat               (const ZTCHAR* pszFormat);

    bool  isValid                 (void) const;

    operator const ZTCHAR *  (void) const;
    operator ZSoft::Int32           (void) const;
    operator double         (void) const;
    explicit operator ZSoft::Time64     (void) const;
    operator ZcGePoint2d    (void) const;
    operator ZcGePoint3d    (void) const;
    operator ZcDbObjectId   (void) const;

    ZcValue& operator=            (const ZcValue& value);
	ZcValue& operator=            (ZcValue && value);  
	ZcValue& operator=            (const ZTCHAR * pszValue);
	ZcValue& operator=            (ZSoft::Int32 lValue);
    ZcValue& operator=            (double fValue);
    ZcValue& operator=            (ZSoft::Time64 date);
    ZcValue& operator=            (const ZcGePoint2d& pt);
    ZcValue& operator=            (const ZcGePoint3d& pt);
    ZcValue& operator=            (const ZcDbObjectId& objId);
    ZcValue& operator=            (const resbuf& rb);
    ZcValue& operator=            (const ZcDbEvalVariant& evalVar);
    ZcValue& operator=            (const VARIANT& var);
    ZcValue& operator=            (const ZcCmColor& clr);
    bool  operator==              (const ZcValue& val) const;
    bool  operator!=              (const ZcValue& val) const;

    ZSoft::Boolean  isEqualTo               (const ZcRxObject* pOther) const override;

    bool  get                     (const ZTCHAR *& pszValue) const;
	bool  get                     (ZcString & sValue) const;   
	bool  get					  (ZTCHAR *& pszValue) const;
    bool  get                     (ZSoft::Int32& lValue) const;
    bool  get                     (double& fValue) const;
	bool  get                     (ZSoft::Time64& date) const;

    bool  get                     (std::tm& date) const;  
    bool  get                     (SYSTEMTIME& date) const;
    bool  get                     (ZcGePoint2d& pt) const;
    bool  get                     (double& x, double& y) const;
    bool  get                     (ZcGePoint3d& pt) const;
    bool  get                     (double& x, double& y, double& z) const;
    bool  get                     (ZcDbObjectId& objId) const;
    bool  get                     (resbuf** pRb) const;
    bool  get                     (ZcDbEvalVariant& evalVar) const;
    bool  get                     (VARIANT& var) const;
    bool  get                     (ZcCmColor& clr) const;
    bool  get                     (void*& pBuf, uint32_t& dwBufSize) const;

    bool  set                     (const ZcValue& value);
    bool  set                     (const ZTCHAR* pszValue);
    bool  set                     (ZcValue::DataType nDataType,
												   const ZTCHAR* pszValue);
    bool  set                     (ZSoft::Int32 lValue);
    bool  set                     (double fValue);
    bool  set                     (const ZSoft::Time64& date);
    bool  set                     (const SYSTEMTIME& date);
	bool  set                     (const std::tm& date);   
    bool  set                     (const ZcGePoint2d& pt);
    bool  set                     (double x,
                                             double y);
    bool  set                     (const ZcGePoint3d& pt);
    bool  set                     (double x, double y, double z);
    bool  set                     (const ZcDbObjectId& objId);
    bool  set                     (const resbuf& rb);
    bool  set                     (const ZcDbEvalVariant& evalVar);
    bool  set                     (const VARIANT& var);
    bool  set                     (const ZcCmColor& clr);
    bool  set                     (const void* pBuf,uint32_t dwBufSize);

    bool  parse                   (const ZTCHAR* pszText,
												   ZcValue::DataType nDataType,
												   ZcValue::UnitType nUnitType,
												   const ZTCHAR* pszFormat,
												   ZcValue::ParseOption nOption,
												   const ZcDbObjectId* pTextStyleId);

    const ZTCHAR* format           (void) const;
    ZcString	  format           (const ZTCHAR* pszFormat) const;
	bool		  format           (ZcString & sValue) const;   

	bool		  format		   (ZTCHAR*& pszValue) const;
	bool		  format           (const ZTCHAR* pszFormat, ZcString & sValue) const; 
	bool          format           (const ZTCHAR* pszFormat,
													ZTCHAR*& pszValue) const;
    ZcString	  format           (ZcValue::FormatOption nOption);
    ZcString	  format           (const ZTCHAR* pszFormat,
                                             ZcValue::FormatOption nOption);

    bool  convertTo               (ZcValue::DataType nDataType,
												   ZcValue::UnitType nUnitType);
    bool  convertTo               (ZcValue::DataType nDataType,
												   ZcValue::UnitType nUnitType,
		                                           bool bResetIfIncompatible);
    Zcad::ErrorStatus dwgInFields           (ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus dwgOutFields          (ZcDbDwgFiler* pFiler) const;
    Zcad::ErrorStatus dxfInFields           (ZcDbDxfFiler* pFiler);
    Zcad::ErrorStatus dxfOutFields          (ZcDbDxfFiler* pFiler) const;

protected:
    void        *   mpImpObj;

private:
    friend class ZcSystemInternals;

	static bool ZTCharAllocHelper(const ZcString & sValue, ZTCHAR *& pszValue, bool bRet)
	{
		pszValue = nullptr;
		if (bRet)
			::zcutNewString(sValue.kwszPtr(), pszValue);
		return bRet;
	}

};

inline bool ZcValue::get(ZTCHAR*& pszValue) const
{
    ZcString sValue;
    return ZTCharAllocHelper(sValue, pszValue, this->get(sValue));
}

inline bool ZcValue::format(ZTCHAR*& pszValue) const
{
    ZcString sValue;
    return ZTCharAllocHelper(sValue, pszValue, this->format(sValue));
}

inline bool ZcValue::format(const ZTCHAR* pszFormat, ZTCHAR*& pszValue) const
{
    ZcString sValue;
    return ZTCharAllocHelper(sValue, pszValue, this->format(pszFormat, sValue));
}

typedef ZcArray<ZcValue, ZcArrayObjectCopyReallocator<ZcValue> > ZcValueArray;
