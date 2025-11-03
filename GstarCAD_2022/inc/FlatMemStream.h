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




// FlatMemStream.h: interface for the OdMemoryStream class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_ODFLATMEMSTREAM_H_INCLUDED_)
#define _ODFLATMEMSTREAM_H_INCLUDED_

#include "TD_PackPush.h"

#include "OdStreamBuf.h"

class OdFlatMemStream;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdFlatMemStream object pointers.
*/
typedef OdSmartPtr<OdFlatMemStream> OdFlatMemStreamPtr;

/** Description:
    This class implements memory-resident I/O objects.
    Library: TD_Root
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdFlatMemStream : public OdStreamBuf
{
protected:
  void*     m_pMemData;
  OdUInt64  m_nEndPos;
  OdUInt64  m_nCurPos;
  /** Description:
    Returns the raw *data* associated with this FlatMemStream object.
  */
  inline OdUInt8* data();
  /** Description:
    Returns the number of unused bytes in this FlatMemStream object.
  */
  inline OdUInt64 left();
  /** Description:
    Appends the specified number of bytes to this FlatMemStream object.
    Arguments:
    numBytes (I) Number of *bytes*.
    Note:
    The default implementation of this function does nothing but throw an eNotOpenForWrite exception
  */
  virtual void append(OdUInt64 numBytes);

  /** 
    Arguments:
    buffer (I) Character *buffer*.
    numBytes (I) Number of *bytes*.
    curPosition (I) Initial position of the file pointer.
  */
  inline OdFlatMemStream(void* buffer, OdUInt64 numBytes, OdUInt64 curPosition);
  inline OdFlatMemStream() { init(0, 0, 0); }
public:
  /** Description:
    Creates a new FlatMemStream object, and returns a SmartPointer to the new object.
    Arguments:
    buffer (I) Character *buffer*.
    numBytes (I) Number of *bytes*.
    curPosition (I) Initial position of the file pointer of the new object.
  */
  static OdFlatMemStreamPtr createNew(void* buffer, OdUInt64 numBytes, OdUInt64 curPosition = 0);

  /** Description:
    Initializes this FlatMemStream object.
    Arguments:
    buffer (I) Character *buffer*.
    numBytes (I) Number of *bytes*.
    curPosition (I) Initial position of the file pointer of the new object.
  */
  inline void init(void* buffer, OdUInt64 numBytes, OdUInt64 curPosition = 0);

  OdUInt64 length();
  OdUInt64 tell();
  OdUInt64 seek(OdInt64 offset, int seekType);

  bool isEof();
  OdUInt8 getByte();
  void getBytes(void* buffer, OdUInt32 numBytes);
  void copyDataTo(OdStreamBuf* pDestination, OdUInt64 sourceStart, OdUInt64 sourceEnd);
  
  // overrides existing byte(s)
  void putByte(OdUInt8 value);
  void putBytes(const void* buffer, OdUInt32 numBytes);
};

inline OdFlatMemStream::OdFlatMemStream(void* pMemData, OdUInt64 nSize, OdUInt64 nCurPos)
{ init(pMemData, nSize, nCurPos); }

inline OdUInt8* OdFlatMemStream::data() { return (OdUInt8*)m_pMemData; }

inline OdUInt64 OdFlatMemStream::left() 
{
  return m_nEndPos - m_nCurPos; 
}

inline void OdFlatMemStream::init(void* pMemData, OdUInt64 nSize, OdUInt64 nCurPos)
{
  m_pMemData = pMemData;
  m_nEndPos = nCurPos + nSize;
  m_nCurPos = nCurPos;
}

#include "TD_PackPop.h"

#endif // !defined(_ODFLATMEMSTREAM_H_INCLUDED_)

