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




#ifndef ODDBHANDLE
#define ODDBHANDLE /* {Secret} */

#include "TD_PackPush.h"

#include "DbRootExport.h"
#include "OdArrayPreDef.h"
#include "OdaDefs.h"
#include "OdString.h"

// Gcad(Add)
const OdUInt32 kBadUInt32Handle = 0xFFFFFFFF;

/** Description:
  Returns the decimal value of a hexadecimal digit.
  
  Arguments:
  hexDigit (I) Hex digit.
  
  Examples:  
  getHexValue('A') returns 10, etc.
*/
DBROOT_EXPORT int getHexValue(
  int hexDigit);

/** Returns the 64 bit integer value corresponding to the passed in string.
@param pStr (I) String representation of an integer.
*/
//TOOLKIT_EXPORT OdInt64 atoi64(const OdChar* pStr);
//TOOLKIT_EXPORT void    i64toA(const OdInt64 &val, OdChar* pStr);

/** Description:
    This class encapsulates the 64-bit integer handles associated with OdDbObject instances.
    
    Library: TD_Db
    
    Remarks:
    Handles are persistent and unique within a *database*. Handles are not, 
	however, unique between databases.
    
    {group:OdDb_Classes}
*/
class DBROOT_EXPORT OdDbHandle
{
public:
  // Gcad(Add) {{
  enum
  {
	kMaxValueBytes = 8,
  };

  OdDbHandle(int lo, int hi) { m_val = OD_MAKEQWORD(lo, hi); }
  // Gcad(Add) }}

  OdDbHandle() : m_val(0) {}

  OdDbHandle(const OdDbHandle& value) : m_val(value.m_val) {}

  OdDbHandle(OdUInt64 value) : m_val(value) {}
  
  OdDbHandle(const OdChar* value) { *this = value; }
  OdDbHandle(int value) : m_val(value) {}
#if  defined(_AFX) || defined(__ATLSTR_H__)  
#else
  OdDbHandle(const char* value) { *this = value; }
  OdDbHandle(const OdString& value) { *this = (const OdChar*)value; }
  OdDbHandle(const OdAnsiString& value) { *this = (const char*)value; }  
#endif

  OdDbHandle& operator=(OdUInt32 value) 
  {
    m_val = value;
    return *this;
  }
  OdDbHandle& operator=(OdUInt64 value) 
  {
    m_val = value;
    return *this;
  }
  
  OdDbHandle& operator=(const OdChar* value);
  OdDbHandle& operator=(const char* value);

  OdDbHandle& operator=(const OdDbHandle& value)
  {
    m_val = value.m_val;
    return *this;
  }
  
#if  defined(_AFX) || defined(__ATLSTR_H__)
  OdDbHandle& operator=(const CStringW &value)
  {
    *this = (const OdChar*)value;
    return *this;
  }
#endif

  operator OdInt()   const { return (OdInt)m_val; }
  operator OdInt32() const { return (OdInt32)m_val; }
  operator OdUInt64() const { return m_val; }

  /** Description:
    Returns the hexidecmal representation of this Handle object as a null terminated string.

    Arguments:
    pBuf (I) Pointer to the buffer to receive the string.

    Note:
    The buffer must be at least 17 bytes long.
  */
  bool getIntoAsciiBuffer(OdChar* pBuf, size_t nBufLen) const;

  enum { kStrSiz = 17 };
  template<size_t nBufLen> inline bool getIntoAsciiBuffer(wchar_t(&buf)[nBufLen]) const
  {
    return this->getIntoAsciiBuffer(buf, nBufLen);
  }

  void  getIntoAsciiBuffer(
    char* pBuf) const;

  /** Description:
    Returns the hexidecmal representation of this Handle object as an OdString.
  */
  OdString ascii() const;
  /** Description:
    Returns true and only if this Handle object is null.
  */
  bool isNull() const { return m_val == 0; }
  
  bool operator == (
    OdUInt64 value) const { return m_val == value; }
  
  bool operator != (
    OdUInt64 value) const { return m_val != value; }
  
  bool operator > (
    OdUInt64 value) const { return m_val > value; }
  
  bool operator < (
    OdUInt64 value) const { return m_val < value; }
  
  bool operator <= (
    OdUInt64 value) const { return m_val < value || m_val == value; }
  
  bool operator >= (
    OdUInt64 value) const { return m_val > value || m_val == value; }
  
  OdDbHandle& operator+=(
    const OdInt64& value)
  {
    m_val += value;
    ODA_ASSERT_ONCE(!isNull()); // check handle stuff overflow
    return *this;
  }
  OdDbHandle operator+(
    const OdInt64& value)
  {
    OdDbHandle res;
    res.m_val = m_val + value;
    return res;
  }

  OdDbHandle& operator += (const OdDbHandle& value)
  {
    m_val += value.m_val;
    ODA_ASSERT_ONCE(!isNull()); // check handle stuff overflow
    return *this;
  }

  OdDbHandle operator + (const OdDbHandle& value) const
  {
    OdDbHandle res;
    res.m_val = m_val + value.m_val;
    return res;
  }

  OdDbHandle operator + (OdULongPtr value) const
  {
    OdDbHandle res;
    res.m_val = m_val + value;
    return res;
  }

  /** Description:
    Returns the this Handle object as an array OdUInt8[8].

    Arguments:
    bytes (I) array of *bytes* to receive the handle.

    Remarks:
    The low order byte is returned in bytes[0].

    Note:
    The buffer must be at least 17 *bytes* long.
  */
  void bytes(
    OdUInt8 * bytes) const
  {
    OdUInt64 val = m_val;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes++ = (OdUInt8)(val & 0xFF);
    val >>= 8;
    *bytes = (OdUInt8)(val & 0xFF);
  }

  // Gcad(Add) {{

  /** Description:
    returns the bottom four bytes of the handle in this object.
  */
  OdUInt32 low() const
  {
    return OD_LODWORD(m_val);
  }

  /** Description:
    returns the top four bytes of the handle in this object.
  */
  OdUInt32 high() const
  {
    return OD_HIDWORD(m_val);
  }

  /** Description:
    copies the 4 bytes in low into the bottom four bytes of this object's 8-byte handle.
  */
  void setLow(OdUInt32 lo)
  {
    m_val = OD_MAKEQWORD(lo, high());
  }

  /** Description:
    copies the 4 bytes in high into the top four bytes of this object's 8-byte handle.
  */
  void setHigh(OdUInt32 hi)
  {
    m_val = OD_MAKEQWORD(low(), hi);
  }

  /** Description:
    This method sets all eight handle bytes to zero.
  */
  void setNull()
  {
    m_val = 0;
  }

  /** Description:
    Returns true and only if this object's value is one.
  */
  bool isOne() const
  {
    return (m_val == 1);
  }

  OdDbHandle& operator++()
  {
    m_val++;
    return *this;
  }
  OdDbHandle operator++(int)
  {
    OdDbHandle tempHandle = *this;
    ++(*this);
    return tempHandle;
  }

  void increment()
  {
    m_val++;
  }

  void decrement()
  {
    m_val--;
  }

  int byte(OdUInt32 i) const
  {
    return *((unsigned char *)&m_val + i);
  }

  OdDbHandle& operator-= (const OdInt64& value)
  {
    m_val -= value;
    return *this;
  }

  OdDbHandle operator - (const OdDbHandle& value) const
  {
    OdDbHandle res;
    res.m_val = m_val - value.m_val;
    return res;
  }

  OdDbHandle& operator -= (const OdDbHandle& value)
  {
    m_val -= value.m_val;
    return *this;
  }

  bool operator > (const OdDbHandle& value) const
  {
    return m_val > value.m_val;
  }

  bool operator >= (const OdDbHandle& value) const
  {
    return m_val >= value.m_val;
  }

  bool operator < (const OdDbHandle& value) const
  {
    return m_val < value.m_val;
  }

  bool operator <= (const OdDbHandle& value) const
  {
    return m_val <= value.m_val;
  }

  //operator OdUInt32 () const
  operator OdUInt32() const 
  {
    if (m_val > kBadUInt32Handle)
    {
      return kBadUInt32Handle;
    }
    else
    {
      return low();
    }
  }

  operator OdInt64 () const
  {
    return *((OdInt64*) (&m_val));
  }

  OdDbHandle operator- (const OdUInt64& value) const
  {
    return OdDbHandle(m_val - value);
  }

  int compare(const OdUInt64& value) const
  {
    if (m_val > value)
    {
      return -1;
    }
    else if (m_val == value)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  int compare(const OdDbHandle& value) const
  {
    if (m_val > value.m_val)
    {
      return -1;
    }
    else if (m_val == value.m_val)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  /** Description:
    These methods are for internal use only.
  */
  void copyToOldType(OdUInt8 hand[8]) const;

  void copyFromOldType(OdUInt8 hand[8]);

  void restZeros(int i);

  int restZeros(int i) const;

  OdDbHandle slowOperatorPlus(const OdDbHandle&) const;

  void getValueBytes(OdUInt8*, OdUInt8*) const;

  void setValueBytes(OdUInt8, const OdUInt8*);
  
  void print() const;

  // Gcad(Add) }}
private:
    OdUInt64  m_val;
};


/** Description:
  This template class is a specialization of the OdArray class for OdDbHandle objects.
*/
typedef OdArray<OdDbHandle> OdHandleArray;

#include "TD_PackPop.h"

#endif

