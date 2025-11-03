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




#ifndef ODSTREAMBUF_DEFINED
#define ODSTREAMBUF_DEFINED

#include "RxObject.h"

#include "TD_PackPush.h"

class OdString;

/** Description: 
  
    {group:TD_Namespaces}
*/

#include "OdDb.h"

/** Description:
    This class is the base class for classes that provide platform-dependent I/O for Teigha.
    
    Library: TD_Root
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdStreamBuf : public OdRxObject
{
protected:
  OdStreamBuf();
public:
  ODRX_DECLARE_MEMBERS(OdStreamBuf);

  /** Description:
    Returns the name of the file associated with this StreamBuf object.
  */
  virtual OdString  fileName();

  /** Description:
    Returns true if and only if the current position of the file pointer for
    this StreamBuf object is at the end of file.
  */
  virtual bool      isEof();
  /** Description:
    Returns the current position of the file pointer for
    this StreamBuf object.
  */
  virtual OdUInt64  tell();
  /** Description:
    Returns the *length* in bytes of the file associated with
    this StreamBuf object.
  */
  virtual OdUInt64  length();

  /** Description:
    Sets the *length* of the file associated with
    this StreamBuf object to zero.
  */
  virtual void      truncate();
  /** Description:
    Sets the current position of the file pointer for
    this StreamBuf object to zero.
  */
  virtual void      rewind();
  /** Description:
    Moves the current position of the file pointer for
    this StreamBuf object to the specified location.

    Arguments:
    offset (I) Number of *bytes*.
    seekType (I) Seek type.
    
    Remarks:
    seekType must be one of the following:
    
    @table
    Name                    Value       Description.
    OdDb::kSeekFromStart    SEEK_SET    Start of file.
    OdDb::kSeekFromCurrent  SEEK_CUR    Current position of file pointer.
    OdDb::kSeekFromEnd      SEEK_END    End of file.
  */
  virtual OdUInt64  seek(OdInt64 offset, int seekType);

  /** Description:
    Returns the byte at the current position of the file pointer
    for this StreamBuf object, and increments the pointer.
  */
  virtual OdUInt8   getByte();
  /** Description:
    Returns the specified number of bytes, starting at the current position of the file pointer
    for this StreamBuf object, and increments the pointer by numBytes.
    Arguments:
    buffer (I) Character *buffer*.
    numBytes (I) Number of *bytes*.
  */
  virtual void      getBytes(void* buffer, OdUInt32 numBytes);

  /** Description:
    Writes the byte to the current position of the file pointer
    for this StreamBuf object, and increments the pointer.
    Arguments:
    value (I) Byte to write. 
  */
  virtual void      putByte(OdUInt8 value);
  /** Description:
    Writes the specified number of bytes, starting at the current position of the file pointer
    for this StreamBuf object, and increments the pointer by numBytes.
    Arguments:
    buffer (I) Character *buffer*.
    numBytes (I) Number of *bytes*.
  */
  virtual void      putBytes(const void* buffer, OdUInt32 numBytes);

  /** Description:
    Copies the specified bytes from this StreamBuf object to the specified StreamBuf object.
    Arguments:
    pDestination (I) Pointer to the StreamBuf object to receive the *data*.
    sourceStart (I) Starting position of the file pointer of this StreamBuf object.
    sourceEnd (I) Ending position of the file pointer of this StreamBuf object.
    Remarks:
    Bytes are copied from sourceStart to sourceEnd inclusive.
  */
  virtual void      copyDataTo(OdStreamBuf* pDestination, OdUInt64 sourceStart = 0, OdUInt64 sourceEnd = 0);
  virtual void      copyDataFrom(OdStreamBuf* pSource , OdUInt64 sourceStart = 0,  OdUInt64 sourceEnd = 0);
  /** Description:
    Returns the share mode for this StreamBuf object.
    
    Remarks:
    getShareMode returns one of the following:
    
    @table
    Name                         Value       Description
    Oda::kShareDenyReadWrite     0x10        deny read/write mode
    Oda::kShareDenyWrite         0x20        deny write mode
    Oda::kShareDenyRead          0x30        deny read mode
    Oda::kShareDenyNo            0x40        deny none mode
  */
  virtual OdUInt32  getShareMode();
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdStreamBuf object pointers.
*/
typedef OdSmartPtr<OdStreamBuf> OdStreamBufPtr;

#include "TD_PackPop.h"

#endif //ODSTREAMBUF_DEFINED

