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




#if !defined(_ODVARIANT_H_INCLUDED_)
#define _ODVARIANT_H_INCLUDED_

#include "TD_PackPush.h"
#include "OdPlatformSettings.h"
#include "RxObject.h"

#include "StringArray.h"
#include "BoolArray.h"
#include "Int8Array.h"
#include "Int16Array.h"
#include "Int32Array.h"
#include "Int64Array.h"
#include "UInt8Array.h"
#include "UInt16Array.h"
#include "UInt32Array.h"
#include "UInt64Array.h"
#include "DoubleArray.h"
#include "OdString.h"
#include "OdAnsiString.h"

/** Description:
    This class implements OdError objects with Result codes of eInvalidVariantType.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_InvalidVariantType : public OdError
{
public:
  OdError_InvalidVariantType();
};

typedef bool OdVariantBool;
typedef OdArray<OdVariantBool,OdMemoryAllocator<OdVariantBool>> OdVariantBoolArray;

const int nOdVariantDataSize = 8;

/** Description:
    This class implements Variant objects within Teigha.
    Library: TD_Root
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdVariant
{
protected:
  int m_type;
#if defined(__hpux) || defined(sparc) || defined(_WIN32_WCE) || defined(sgi)
  double _padding;
#endif
  OdUInt8 m_data[nOdVariantDataSize];
  virtual void setVarType(int newType, int& type, void* data);
public:
  struct TypeFactory
  {
    virtual void construct(void* pData) const = 0;
    virtual void destroy(void* pData) const = 0;
  };
  static const TypeFactory* typeFactory(int type);
public:
  typedef enum
  {
    kVoid         = 0x0000,
    kString       = 0x0001,
    kBool         = 0x0002,
    kInt8         = 0x0003,
    kUInt8        = 0x0003,
    kInt16        = 0x0004,
    kUInt16       = 0x0004,
    kInt32        = 0x0005,
    kUInt32       = 0x0005,
    kInt64        = 0x0006,
    kUInt64       = 0x0006,
    kDouble       = 0x0007,
    kWString      = 0x0008,
    kAnsiString   = 0x0008,
    kRxObjectPtr  = 0x0009,
    kNextType     = 0x000A,
    kByRef        = 0x0040,
    kArray        = 0x0080
  } Type;

  OdVariant();
  OdVariant(const OdVariant& val);
  OdVariant& operator =(const OdVariant& val);
  virtual ~OdVariant();

  /** Description:
    Returns the *type* of this Variant object, including ByRef and Array flags.
  */
  int  varType() const { return m_type; }
  /** Description:
    Returns the *type* of this Variant object, excluding ByRef and Array flags.
  */
  Type type()    const { return Type(m_type & (0x3F)); }
  /** Description:
    Returns true if and only if this Variant object is an Array.
  */
  bool isArray() const { return (m_type & kArray)!=0; }
  /** Description:
    Returns true if and only if this Variant object is ByRef (read/write).
  */
  bool isByRef() const { return (m_type & kByRef)!=0; }

  OdVariant(const OdString& val);
  OdVariant(const OdAnsiString& val);
  OdVariant(const OdRxObjectPtr& val);
  OdVariant(bool val);
  OdVariant(OdInt8 val);
  OdVariant(OdUInt8 val);
  OdVariant(OdInt16 val);
  OdVariant(OdUInt16 val);
  OdVariant(OdInt32 val);
  OdVariant(OdUInt32 val);
  OdVariant(OdInt64 val);
  OdVariant(OdUInt64 val);
  OdVariant(double val);
#ifdef OD_INTPTR_UNIQUE
  OdVariant(OdIntPtr val);
#endif

  /** Description:
    Returns a reference to the value of this Variant object as an OdString object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdString& getString() const;

  /** Description:
  Returns a reference to the value of this Variant object as an OdAnsiString object.
  Note:
  No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdAnsiString& getAnsiString() const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdRxObjectPtr object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdRxObjectPtr& getRxObjectPtr() const;

  /** Description:
    Returns the value of this Variant object as a bool object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  bool getBool()   const;

  /** Description:
    Returns the value of this Variant object as an OdInt8 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt8 getInt8()   const;

  /** Description:
    Returns the value of this Variant object as an OdUInt8 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt8 getUInt8()  const;

  /** Description:
    Returns the value of this Variant object as an OdInt16 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt16 getInt16()  const;

  /** Description:
    Returns the value of this Variant object as an OdUInt16 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt16 getUInt16() const;

  /** Description:
    Returns the value of this Variant object as an OdInt32 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt32 getInt32()  const;

  /** Description:
    Returns the value of this Variant object as an OdUInt32 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt32 getUInt32() const;

  /** Description:
    Returns the value of this Variant object as an OdInt64 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt64 getInt64()  const;

  /** Description:
    Returns the value of this Variant object as an OdUInt64 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt64 getUInt64() const;

  /** Description:
    Returns the value of this Variant object as an OdIntPtr object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdIntPtr getIntPtr() const;

  /** Description:
    Returns the value of this Variant object as an double object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  double getDouble() const;


  /** Description:
    Returns the value of this Variant object as a pointer to an OdString object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdString* getStringPtr() const;

  /** Description:
  Returns the value of this Variant object as a pointer to an OdAnsiString object.
  Note:
  No check is made to determine that this Variant object is of the specified *type*.
  */
  OdAnsiString* getAnsiStringPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdRxObjectPtr object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdRxObjectPtr* getRxObjectPtrPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to a bool object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  bool* getBoolPtr()   const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt8 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt8* getInt8Ptr()   const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt8 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt8* getUInt8Ptr()  const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt16 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt16* getInt16Ptr()  const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt16 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt16* getUInt16Ptr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt32 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt32* getInt32Ptr()  const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt32 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt32* getUInt32Ptr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt64 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt64* getInt64Ptr()  const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt64 object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt64* getUInt64Ptr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an double object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  double* getDoublePtr() const;


  /** Description:
    Returns a reference to the value of this Variant object as an OdStringArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdStringArray& getStringArray() const;

  /** Description:
  Returns a reference to the value of this Variant object as an OdAnsiStringArray object.
  Note:
  No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdAnsiStringArray& getAnsiStringArray() const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdRxObjectPtrArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdRxObjectPtrArray& getRxObjectPtrArray() const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdBoolArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdVariantBoolArray& getBoolArray  () const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdInt8Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdInt8Array& getInt8Array  () const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdUInt8Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdUInt8Array& getUInt8Array () const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdInt16Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdInt16Array& getInt16Array () const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdUInt16Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdUInt16Array& getUInt16Array() const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdInt32Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdInt32Array& getInt32Array () const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdUInt32Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdUInt32Array& getUInt32Array() const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdInt64Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdInt64Array& getInt64Array () const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdUInt64Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdUInt64Array& getUInt64Array() const;

  /** Description:
    Returns a reference to the value of this Variant object as an OdDoubleArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  const OdDoubleArray& getDoubleArray() const;

  /** Description:
    Sets the *type* of this Variant object to OdStringArray.
  */
  OdStringArray& asStringArray();

  /** Description:
  Sets the *type* of this Variant object to OdAnsiStringArray.

  Remarks: 
  Returns a reference to this Variant object.
  */
  OdAnsiStringArray& asAnsiStringArray();

  /** Description:
    Sets the *type* of this Variant object to OdRxObjectPtrArray.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdRxObjectPtrArray& asRxObjectPtrArray();
  
  /** Description:
    Sets the *type* of this Variant object to OdBoolArray.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariantBoolArray&   asBoolArray  ();
  
  /** Description:
    Sets the *type* of this Variant object to OdInt8Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdInt8Array&   asInt8Array  ();
  
  /** Description:
    Sets the *type* of this Variant object to OdUInt8Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdUInt8Array&  asUInt8Array ();
  
  /** Description:
    Sets the *type* of this Variant object to OdInt16Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdInt16Array&  asInt16Array ();
  
  /** Description:
    Sets the *type* of this Variant object to OdUInt16Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdUInt16Array& asUInt16Array();
  
  /** Description:
    Sets the *type* of this Variant object to OdInt32Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdInt32Array&  asInt32Array ();
  
  /** Description:
    Sets the *type* of this Variant object to OdUInt32Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdUInt32Array& asUInt32Array();
  
  /** Description:
    Sets the *type* of this Variant object to OdInt64Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdInt64Array&  asInt64Array ();
  
  /** Description:
    Sets the *type* of this Variant object to OdUInt64Array.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdUInt64Array& asUInt64Array();
  
  /** Description:
    Sets the *type* of this Variant object to OdDoubleArray.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdDoubleArray& asDoubleArray();

  /** Description:
    Returns the value of this Variant object as a pointer to an OdStringArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdStringArray* getStringArrayPtr() const;

  /** Description:
  Returns the value of this Variant object as a pointer to an OdAnsiStringArray object.
  Note:
  No check is made to determine that this Variant object is of the specified *type*.
  */
  OdAnsiStringArray* getAnsiStringArrayPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdRxObjectPtrArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdRxObjectPtrArray* getRxObjectPtrArrayPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdBoolArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdVariantBoolArray* getBoolArrayPtr  () const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt8Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt8Array* getInt8ArrayPtr  () const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt8Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt8Array* getUInt8ArrayPtr () const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt16Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt16Array* getInt16ArrayPtr () const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt16Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt16Array* getUInt16ArrayPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt32Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt32Array* getInt32ArrayPtr () const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt32Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt32Array* getUInt32ArrayPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdInt64Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdInt64Array* getInt64ArrayPtr () const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdUInt64Array object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdUInt64Array* getUInt64ArrayPtr() const;

  /** Description:
    Returns the value of this Variant object as a pointer to an OdDoubleArray object.
    Note:
    No check is made to determine that this Variant object is of the specified *type*.
  */
  OdDoubleArray* getDoubleArrayPtr() const;

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
  */
  OdVariant& setString(const OdString& val);

  /** Description:
  Sets the value of this Variant object.

  Arguments:
  val (I) Value.

  Remarks: 
  Returns a reference to this Variant object.
  */
  OdVariant& setAnsiString(const OdAnsiString& val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setRxObjectPtr( const OdRxObjectPtr& val );

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setBool  (bool val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt8  (OdInt8 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt8 (OdUInt8 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt16 (OdInt16 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt16(OdUInt16 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt32 (OdInt32 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt32(OdUInt32 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt64 (OdInt64 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt64(OdUInt64 val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setIntPtr (OdIntPtr val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setDouble(double val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setStringPtr(OdString* val);

  /** Description:
  Sets the value of this Variant object.

  Arguments:
  val (I) Value.

  Remarks: 
  Returns a reference to this Variant object.
  */
  OdVariant& setAnsiStringPtr(OdAnsiString* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setRxObjectPtrPtr(OdRxObjectPtr* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setBoolPtr  (bool* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt8Ptr  (OdInt8* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt8Ptr (OdUInt8* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt16Ptr (OdInt16* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt16Ptr(OdUInt16* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt32Ptr (OdInt32* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt32Ptr(OdUInt32* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt64Ptr (OdInt64* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt64Ptr(OdUInt64* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setDoublePtr(double* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setStringArray(const OdStringArray& val);

  /** Description:
  Sets the value of this Variant object.

  Arguments:
  val (I) Value.

  Remarks: 
  Returns a reference to this Variant object.
  */
  OdVariant& setAnsiStringArray(const OdAnsiStringArray& val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setRxObjectPtrArray(const OdRxObjectPtrArray& val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setBoolArray  (const OdVariantBoolArray&   val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt8Array  (const OdInt8Array&   val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt8Array (const OdUInt8Array&  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt16Array (const OdInt16Array&  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt16Array(const OdUInt16Array& val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt32Array (const OdInt32Array&  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt32Array(const OdUInt32Array& val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt64Array (const OdInt64Array&  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt64Array(const OdUInt64Array& val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setDoubleArray(const OdDoubleArray& val);


  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setStringArrayPtr(OdStringArray* val);

  /** Description:
  Sets the value of this Variant object.

  Arguments:
  val (I) Value.

  Remarks: 
  Returns a reference to this Variant object.
  */
  OdVariant& setAnsiStringArrayPtr(OdAnsiStringArray* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setRxObjectPtrArrayPtr(OdRxObjectPtrArray* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setBoolArrayPtr  (OdVariantBoolArray*   val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt8ArrayPtr  (OdInt8Array*   val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt8ArrayPtr (OdUInt8Array*  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt16ArrayPtr (OdInt16Array*  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt16ArrayPtr(OdUInt16Array* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt32ArrayPtr (OdInt32Array*  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt32ArrayPtr(OdUInt32Array* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setInt64ArrayPtr (OdInt64Array*  val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setUInt64ArrayPtr(OdUInt64Array* val);

  /** Description:
    Sets the value of this Variant object.
    
    Arguments:
    val (I) Value.
    
    Remarks: 
    Returns a reference to this Variant object.
  */
  OdVariant& setDoubleArrayPtr(OdDoubleArray* val);
};



#include "TD_PackPop.h"

#endif //_ODVARIANT_H_INCLUDED_

