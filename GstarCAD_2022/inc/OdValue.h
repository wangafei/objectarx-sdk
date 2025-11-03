/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////



#ifndef _ODVALUE_INCLUDED_
#define _ODVALUE_INCLUDED_
#include "Ge/GePoint3d.h"
#include "Ge/GePoint2d.h"

class OdDbEvalVariant; 


#include "TD_PackPush.h"
#include "StaticRxObject.h"

class OdValueImpl;
class OdValue;
typedef OdSmartPtr<OdValue> OdValuePtr;

/** Description:
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdValue : public OdStaticRxObject<OdRxObject>
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
//    static bool     isValidDataType         (const VARIANT& var);

public:
  ODRX_DECLARE_MEMBERS(OdValue);
    
  OdValue(void);
  ~OdValue(void);

  OdValue(const OdValue& value);
  OdValue(const OdChar* value);
  OdValue(OdInt32 value);
  OdValue(double value);
  OdValue(const OdInt64& date);
  OdValue(double x, double y);
  OdValue(double x, double y, double z);
  OdValue(const OdGePoint2d& pnt);
  OdValue(const OdGePoint3d& pnt);
  OdValue(const OdDbObjectId& objectId);
  OdValue(const OdResBufPtr& resBuf);
  OdValue(OdValue::DataType nDataType);
  OdValue(const OdCmColor& var);
  OdValue(const void* buffer, OdUInt32 bufferSize);

  /** Description:
  Sets the datatype of this FieldValue object to kUnknown.
  Remarks:
  This function always returns true.
  */
  bool reset();
  bool reset(OdValue::DataType nDataType);

  bool resetValue(void);

  /** Description:
  Returns the datatype of this FieldValue object.
  Remarks:
  dataType() returns one of the following:

  @table
  Name              Value
  kUnknown          0x00
  kLong             0x01
  kDouble           0x02
  kString           0x04
  kDate             0x08
  kPoint            0x10
  k3dPoint          0x20
  kObjectId         0x40
  kBuffer           0x80
  kResbuf           0x100
  */
  OdValue::DataType dataType () const;
  /** Description:
  Returns true if and only if the datatype of this FieldValue is not kUnknown.
  */
  bool isValid () const;

  /**
  Remarks:
  Returns this *object* as the specified type.

  Note:
  OdInt64 is used for *date* values.
  */
  operator const OdChar* () const;
  operator OdInt32() const;
  operator double() const;
  operator OdInt64() const;
  operator OdDbObjectId() const;  
  
  operator OdGePoint2d (void) const;
  operator OdGePoint3d (void) const;

  OdValue& operator=(const OdValue& value);
  OdValue& operator=(const OdChar* value);
  OdValue& operator=(OdInt32 value);
  OdValue& operator=(double value);
  OdValue& operator=(OdInt64 date);
  OdValue& operator=(const OdDbObjectId& objectId);

  OdValue& operator=(const OdGePoint2d& pt);
  OdValue& operator=(const OdGePoint3d& pt);

  OdValue& operator=(const OdResBufPtr& resBuf);
  //OdValue& operator=(const OdDbEvalVariant& evalVar);
  //OdValue& operator=(const VARIANT& var);

  //bool operator== (const OdValue& val) const;
  //bool operator!= (const OdValue& val) const;
  //bool isEqualTo  (const OdRxObject* pOther) const;
  OdValue& operator=(const OdCmColor& clr);

  /** Description:
  Returns the *value* of this FieldValue object.
  Arguments:
  value (O) Receives the *value*.
  date (O) Receives the *date* *value*
  x (O) Receives the X-coordinate of the point.
  y (O) Receives the Y-coordinate of the point.
  z (O) Receives the Z-coordinate of the point.
  resBuf (O) Receives the  ResBuf list.
  objectId (I) Object ID.
  Remarks:
  Returns true if and only if successful.
  */
  bool get(OdCmColor& clr) const;
  
  bool get(OdString& value) const;
  bool get(OdInt32& value) const;
  bool get(double& value) const;
  bool get(OdInt64& date) const;
  bool get(double& x, double& y) const;
  bool get(double& x, double& y, double& z) const;
  bool get(OdGePoint2d& pt) const;
  bool get(OdGePoint3d& pt) const;

  bool get(OdDbObjectId& objectId) const;
  bool get(OdResBufPtr& resBuf) const;
  bool get(void*& pBuf, OdUInt32& bufferSize) const;

  bool get(const OdChar *& pszValue) const;
  bool get(OdChar *& pszValue) const;

  //bool get(OdDbEvalVariant& evalVar) const;
  //bool get(VARIANT& var) const;
  //bool get(SYSTEMTIME& date) const;

  /** Description
  Sets the *value* for this FieldValue object according to the arguments.
  Arguments:
  value (I) Value.
  date (I) Date *value*
  x (I) X-coordinate of the point.
  y (I) Y-coordinate of the point.
  z (I) Z-coordinate of the point.
  buffer (I) Buffer.
  bufferSize (I) Buffer size.
  resBuf (I) ResBuf list.
  objectId (I) Object ID.
  Remarks:
  Returns true if and only if successful.
  */
  bool set(const OdValue& value);
  bool set(const OdChar* value);
  bool set(OdInt32 value);
  bool set(double value);
  bool set(const OdInt64& date);
  bool set(double x, double y);
  bool set(double x, double y, double z);
  bool set(const OdGePoint2d& pt);
  bool set(const OdGePoint3d& pt);

  bool set(const OdDbObjectId& objectId);
  bool set(const OdCmColor& clr);
  bool set(const OdResBufPtr& resBuf);
  bool set(const void* buffer, OdUInt32 bufferSize);

  //bool set(const OdDbEvalVariant& var);
  //bool set(OdValue::DataType nDataType, const OdChar* pszValue);
  //bool set(const SYSTEMTIME& date);
  //bool set(const VARIANT& var);


  OdValue::UnitType unitType (void) const;
  void  setUnitType (OdValue::UnitType nUnitType);
  const OdString& getFormat (void) const;
  void  setFormat (const OdString& pszFormat);

  bool  parse (const OdString& pszText, 
    OdValue::DataType nDataType, 
    OdValue::UnitType nUnitType, 
    const OdChar* pszFormat, 
    OdValue::ParseOption nOption, 
    const OdDbObjectId* pTextStyleId);
 

  const OdString& format() const;
  bool format(const OdString& pszFormat, OdString& pszValue) const;
  bool format(OdString& pszValue) const;

  OdString format               (OdValue::FormatOption nOption);
  OdString format               (const OdString& pszFormat, 
    OdValue::FormatOption nOption);

 
  bool  convertTo               (OdValue::DataType nDataType, 
                                          OdValue::UnitType nUnitType);
  bool  convertTo               (OdValue::DataType nDataType, 
                                          OdValue::UnitType nUnitType, 
                                          bool bResetIfIncompatible);

  virtual OdResult dwgInFields (
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields (
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

protected:
  OdValue(OdValueImpl* pValImpl);

  friend class OdDbSystemInternals;
  OdValueImpl* m_pImpl;
};

#include "TD_PackPop.h"

#endif // _ODVALUE_INCLUDED_
