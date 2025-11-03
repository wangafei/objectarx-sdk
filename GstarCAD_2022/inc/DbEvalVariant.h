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

#ifndef OdDbEvalVariant_INCLUDED_
#define OdDbEvalVariant_INCLUDED_ /* {Secret} */

#include "DbExport.h"
#include "ResBuf.h"
#include "DbFiler.h"

#include "TD_PackPush.h"
#include "OdDb.h"

class OdDbEvalVariant;

typedef OdSmartPtr<OdDbEvalVariant> OdDbEvalVariantPtr;

class TOOLKIT_EXPORT OdDbEvalVariant : public OdResBuf
{
public:
  ODRX_DECLARE_MEMBERS(OdDbEvalVariant );

  OdDbEvalVariant();
  ~OdDbEvalVariant();

  static OdDbEvalVariantPtr init(const OdDbEvalVariant& other); 
  static OdDbEvalVariantPtr init(const OdDbEvalVariant* pOther);
  static OdDbEvalVariantPtr init(double       dVal);
  static OdDbEvalVariantPtr init(short        iVal);
//static OdDbEvalVariantPtr init(const ACHAR*  szVal);
  static OdDbEvalVariantPtr init(int         lVal);
  static OdDbEvalVariantPtr init(const OdDbObjectId& id);
  static OdDbEvalVariantPtr init(const OdGePoint2d&  pt);
  static OdDbEvalVariantPtr init(const OdGePoint3d&  pt);
  static OdDbEvalVariantPtr init(const OdResBuf& rb);

  OdDbEvalVariant(const OdResBuf& rb)
  {
	  *this = rb;
  }
  OdDbEvalVariant(double      dVal)
  {
	  *this = dVal;
  }
  OdDbEvalVariant(short       iVal)
  {
	  *this = iVal;
  }
  OdDbEvalVariant(int        lVal)
  {
	  *this = lVal;
  }
  OdDbEvalVariant(const OdDbEvalVariant& other)
  {
	  *this = other;
  }
  OdDbEvalVariant(const OdDbObjectId& id)
  {
	  *this = id;
  }
  OdDbEvalVariant(const OdGePoint2d&  pt)
  {
	  *this = pt;
  }
  OdDbEvalVariant(const OdGePoint3d&  pt)
  {
	  *this = pt;
  }

  OdDbEvalVariant(const OdChar* szVal)
  {
	  *this = szVal;
  }

  OdDbEvalVariant& operator=(const OdResBuf& rb);
  OdDbEvalVariant& operator=(double      dVal);
  OdDbEvalVariant& operator=(short       iVal);
  OdDbEvalVariant& operator=(int        lVal);
  OdDbEvalVariant& operator=(const OdChar* szVal);
  OdDbEvalVariant& operator=(const OdDbEvalVariant& other);
  OdDbEvalVariant& operator=(const OdDbObjectId& id);
  OdDbEvalVariant& operator=(const OdGePoint2d&  pt);
  OdDbEvalVariant& operator=(const OdGePoint3d&  pt);

  void clear();

  OdResult copyFrom(const OdRxObject* pOther);//eWrongObjectType 

  bool operator <  ( const OdDbEvalVariant& val ) const;
  bool operator >  ( const OdDbEvalVariant& val ) const;
  bool operator <= ( const OdDbEvalVariant& val ) const;
  bool operator >= ( const OdDbEvalVariant& val ) const;
  bool operator == ( const OdDbEvalVariant& val ) const;
  bool operator != ( const OdDbEvalVariant& val ) const;


  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dwgInFields(OdDbDwgFiler* pFiler);

  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);

  OdDb::DwgDataType getType() const;

  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const double value);
  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const short value);
  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const int value);
  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const OdString& value);
  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const OdDbObjectId value);
  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const OdGePoint3d& value);
  OdResult setValue(int /*AcDb::DxfCode*/ groupcode, const OdGePoint2d& value);

  OdResult getValue(double& value) const;
  OdResult getValue(short& value) const;
  OdResult getValue(int& value) const;
  OdResult getValue(OdString& value) const;
  OdResult getValue(OdDbObjectId& value, OdDbDatabase *pDb = NULL) const;
  OdResult getValue(OdGePoint3d& value) const;
  OdResult getValue(OdGePoint2d& value) const;

protected:
  int m_groupCode;
  OdDb::DwgDataType m_type;

};

typedef OdArray<OdDbEvalVariant> OdDbEvalVariantArray;

class TOOLKIT_EXPORT GcDbEvalVariant : public resbuf, public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(GcDbEvalVariant);

  GcDbEvalVariant();
  GcDbEvalVariant(const GcDbEvalVariant& other);
  GcDbEvalVariant(const GcDbEvalVariant* pOther);

  GcDbEvalVariant(const OdDbEvalVariant& other);
  GcDbEvalVariant(const OdDbEvalVariant* pOther);

  ~GcDbEvalVariant();

  GcDbEvalVariant(double dVal);
  GcDbEvalVariant(short iVal);
  GcDbEvalVariant(const OdChar* szVal);
  GcDbEvalVariant(OdInt32 lVal);
  GcDbEvalVariant(const OdDbObjectId& id);
  GcDbEvalVariant(const OdGePoint2d& pt);
  GcDbEvalVariant(const OdGePoint3d& pt);
  GcDbEvalVariant(const resbuf& rb);

  GcDbEvalVariant& operator=(const resbuf& rb);
  GcDbEvalVariant& operator=(double dVal);
  GcDbEvalVariant& operator=(short iVal);
  GcDbEvalVariant& operator=(OdInt32 lVal);
  GcDbEvalVariant& operator=(const OdChar* szVal);
  GcDbEvalVariant& operator=(const GcDbEvalVariant& other);
  GcDbEvalVariant& operator=(const OdDbObjectId& id);
  GcDbEvalVariant& operator=(const OdGePoint2d&  pt);
  GcDbEvalVariant& operator=(const OdGePoint3d&  pt);

  void clear();

  virtual OdResult copyFrom(const OdRxObject* pOther);

  bool operator < (const GcDbEvalVariant& val) const;
  bool operator > (const GcDbEvalVariant& val) const;
  bool operator <= (const GcDbEvalVariant& val) const;
  bool operator >= (const GcDbEvalVariant& val) const;

  bool operator == (const GcDbEvalVariant& val) const;
  bool operator != (const GcDbEvalVariant& val) const;
  
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);

  OdDb::DwgDataType getType() const;

  OdResult setValue(OdDb::DxfCode groupcode, const double value);
  OdResult setValue(OdDb::DxfCode groupcode, const short value);
  OdResult setValue(OdDb::DxfCode groupcode, const OdInt32 value);
  OdResult setValue(OdDb::DxfCode groupcode, const OdString& value);
  OdResult setValue(OdDb::DxfCode groupcode, const OdDbObjectId value);
  OdResult setValue(OdDb::DxfCode groupcode, const OdGePoint3d& value);
  OdResult setValue(OdDb::DxfCode groupcode, const OdGePoint2d& value);

  OdResult getValue(double& value) const;
  OdResult getValue(short& value) const;
  OdResult getValue(OdInt32& value) const;
  OdResult getValue(OdString& value) const;
  OdResult getValue(OdDbObjectId& value, OdDbDatabase *pDb = NULL) const;
  OdResult getValue(OdGePoint3d& value) const;
  OdResult getValue(OdGePoint2d& value) const;

  //OdResult toOdRxValue(const OdRxValueType& type, OdRxValue& value) const;
  //OdResult fromOdRxValue(const OdRxValue& value);

  operator OdDbEvalVariant() const;

  GcDbEvalVariant& operator = (const OdDbEvalVariant& value);

protected:
  void init();
};

#include "TD_PackPop.h"

#endif
