/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gsoft.h"
#include "GdGChar.h"
#include "gcarray.h"

class GcDbEvalVariant;
typedef struct tagVARIANT VARIANT;
typedef struct _SYSTEMTIME SYSTEMTIME;
class GcDbObjectId;
class GcGePoint2d;
class GcGePoint3d;
class GcCmColor;
struct resbuf;
class GcDbDwgFiler;
class GcDbDxfFiler;

class GCDB_PORT GcValue : public GcRxObject
{
public:
  enum DataType
  {
    kUnknown = 0,
    kLong = (0x1 << 0),
    kDouble = (0x1 << 1),
    kString = (0x1 << 2),
    kDate = (0x1 << 3),
    kPoint = (0x1 << 4),
    k3dPoint = (0x1 << 5),
    kObjectId = (0x1 << 6),
    kBuffer = (0x1 << 7),
    kResbuf = (0x1 << 8),
    kGeneral = (0x1 << 9),
    kColor = (0x1 << 10),
  };

  enum UnitType
  {
    kUnitless = 0,
    kDistance = (0x1 << 0),
    kAngle = (0x1 << 1),
    kArea = (0x1 << 2),
    kVolume = (0x1 << 3),
    kCurrency = (0x1 << 4),
    kPercentage = (0x1 << 5),
    kAngleNotTransformed = (0x1 << 16),
  };

  enum ParseOption
  {
    kParseOptionNone = 0,
    kSetDefaultFormat = (0x1 << 0),
    kPreserveMtextFormat = (0x1 << 1),
    kConvertTextToValue = (0x1 << 2),
    kChangeDataType = (0x1 << 3),
    kParseTextForFieldCode = (0x1 << 4),
  };

  enum FormatOption
  {
    kFormatOptionNone = 0,
    kForEditing = (0x1 << 0),
    kForExpression = (0x1 << 1),
    kUseMaximumPrecision = (0x1 << 2),
    kIgnoreMtextFormat = (0x1 << 3),
  };

public:
  static bool     isValidDataType(const VARIANT& var);

public:
  GCRX_DECLARE_MEMBERS(GcValue);

  GcValue(void);
  GcValue(GcValue::DataType nDataType);
  GcValue(const GcValue& value);
  GcValue(GcValue && value);
  GcValue(const GCHAR * pszValue);
  explicit GcValue(Gsoft::Int32 lValue);
  GcValue(double fValue);
  explicit GcValue(const Gsoft::Time64& date);
  GcValue(const SYSTEMTIME& date);
  GcValue(const std::tm& date);
  GcValue(const GcGePoint2d& pt);
  GcValue(double x, double y);
  GcValue(const GcGePoint3d& pt);
  GcValue(double x, double y, double z);
  GcValue(const GcDbObjectId& id);
  GcValue(const resbuf& rb);
  GcValue(const GcDbEvalVariant& evalVar);
  GcValue(const VARIANT& var);
  GcValue(const GcCmColor& var);
  GcValue(const void* pBuf, uint32_t dwBufSize);
  ~GcValue(void);

  bool  reset(void);
  bool  reset(GcValue::DataType nDataType);
  bool  resetValue(void);
  GcValue::DataType dataType(void) const;
  GcValue::UnitType unitType(void) const;
  bool  setUnitType(GcValue::UnitType nUnitType);
  const GCHAR* getFormat(void) const;
  bool  setFormat(const GCHAR* pszFormat);
  bool  isValid(void) const;
  operator const GCHAR *  (void) const;
  operator Gsoft::Int32(void) const;
  operator double(void) const;
  explicit operator Gsoft::Time64(void) const;
  operator GcGePoint2d    (void) const;
  operator GcGePoint3d    (void) const;
  operator GcDbObjectId   (void) const;

  GcValue& operator=            (const GcValue& value);
  GcValue& operator=            (GcValue && value);
  GcValue& operator=            (const GCHAR * pszValue);
  GcValue& operator=            (Gsoft::Int32 lValue);
  GcValue& operator=            (double fValue);
  GcValue& operator=            (Gsoft::Time64 date);
  GcValue& operator=            (const GcGePoint2d& pt);
  GcValue& operator=            (const GcGePoint3d& pt);
  GcValue& operator=            (const GcDbObjectId& objId);
  GcValue& operator=            (const resbuf& rb);
  GcValue& operator=            (const GcDbEvalVariant& evalVar);
  GcValue& operator=            (const VARIANT& var);
  GcValue& operator=            (const GcCmColor& clr);
  bool  operator==              (const GcValue& val) const;
  bool  operator!=              (const GcValue& val) const;

  Gsoft::Boolean  isEqualTo(const GcRxObject* pOther) const override;
  bool  get(const GCHAR *& pszValue) const;
  bool  get(GcString & sValue) const;
  bool  get(GCHAR *& pszValue) const;
  bool  get(Gsoft::Int32& lValue) const;
  bool  get(double& fValue) const;
  bool  get(Gsoft::Time64& date) const;
  bool  get(std::tm& date) const;
  bool  get(SYSTEMTIME& date) const;
  bool  get(GcGePoint2d& pt) const;
  bool  get(double& x,
    double& y) const;
  bool  get(GcGePoint3d& pt) const;
  bool  get(double& x,
    double& y,
    double& z) const;
  bool  get(GcDbObjectId& objId) const;
  bool  get(resbuf** pRb) const;
  bool  get(GcDbEvalVariant& evalVar) const;
  bool  get(VARIANT& var) const;
  bool  get(GcCmColor& clr) const;
  bool  get(void*& pBuf,
    uint32_t& dwBufSize) const;

  bool  set(const GcValue& value);
  bool  set(const GCHAR* pszValue);
  bool  set(GcValue::DataType nDataType,
    const GCHAR* pszValue);
  bool  set(Gsoft::Int32 lValue);
  bool  set(double fValue);
  bool  set(const Gsoft::Time64& date);
  bool  set(const SYSTEMTIME& date);
  bool  set(const std::tm& date);
  bool  set(const GcGePoint2d& pt);
  bool  set(double x,
    double y);
  bool  set(const GcGePoint3d& pt);
  bool  set(double x,
    double y,
    double z);
  bool  set(const GcDbObjectId& objId);
  bool  set(const resbuf& rb);
  bool  set(const GcDbEvalVariant& evalVar);
  bool  set(const VARIANT& var);
  bool  set(const GcCmColor& clr);
  bool  set(const void* pBuf,
    uint32_t dwBufSize);

  bool  parse(const GCHAR* pszText,
    GcValue::DataType nDataType,
    GcValue::UnitType nUnitType,
    const GCHAR* pszFormat,
    GcValue::ParseOption nOption,
    const GcDbObjectId* pTextStyleId);

  const GCHAR* format(void) const;
  GcString format(const GCHAR* pszFormat) const;
  bool  format(GcString & sValue) const;
  bool  format(GCHAR*& pszValue) const;
  bool  format(const GCHAR* pszFormat, GcString & sValue) const;
  bool  format(const GCHAR* pszFormat,
    GCHAR*& pszValue) const;
  GcString format(GcValue::FormatOption nOption);
  GcString format(const GCHAR* pszFormat,
    GcValue::FormatOption nOption);

  bool  convertTo(GcValue::DataType nDataType,
    GcValue::UnitType nUnitType);
  bool  convertTo(GcValue::DataType nDataType,
    GcValue::UnitType nUnitType,
    bool bResetIfIncompatible);
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler);
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler);
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const;

protected:
  void * mpImpObj;

private:
  friend class GcSystemInternals;
  static bool GCharAllocHelper(const GcString & sValue, GCHAR *& pszValue, bool bRet)
  {
    pszValue = nullptr;
    if (bRet)
      ::gcutNewString(sValue.kwszPtr(), pszValue);
    return bRet;
  }
};

GCBASE_PORT Gcad::ErrorStatus gcutNewString(const GCHAR* pInput, GCHAR*& pOutput);
inline bool GcValue::get(GCHAR *& pszValue) const
{
  GcString sValue;
  return GCharAllocHelper(sValue, pszValue, this->get(sValue));
}
inline bool GcValue::format(GCHAR*& pszValue) const
{
  GcString sValue;
  return GCharAllocHelper(sValue, pszValue, this->format(sValue));
}

inline bool GcValue::format(const GCHAR* pszFormat, GCHAR*& pszValue) const
{
  GcString sValue;
  return GCharAllocHelper(sValue, pszValue, this->format(pszFormat, sValue));
}

typedef GcArray<GcValue, GcArrayObjectCopyReallocator<GcValue> > GcValueArray;
