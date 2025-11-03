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


#ifndef _ODSTORAGE_INCLUDED_
#define _ODSTORAGE_INCLUDED_

#include "RxObject.h"
#include "OdStreamBuf.h"
#include "DbSystemServices.h"
#include "OdErrorContext.h"

#include "TD_PackPush.h"

/** Description:
    This class is the base class for custom classes
    that implement unsigned ByteData storage.
    Library: TD_Db
    {group:Other_Classes} 
*/
class FIRSTDLL_EXPORT OdByteData : public OdRxObject
{
public:
  typedef OdUInt32 SizeType;

  ODRX_DECLARE_MEMBERS(OdByteData);
  /** Description:
    Copies the specified bytes from this ByteData object to the specified *buffer*.
    
    Arguments:
    start (I) Starting position.
    bufferSize (I) Number of bytes.
    buffer (O) Receives the bytes.
  */
  virtual SizeType readAt(SizeType start, OdUInt8 *buffer, SizeType bufferSize) const = 0;

  /** Description:
    Copies the specified bytes from the specified *buffer* to this ByteData object.
    
bufferSize  */
  virtual SizeType writeAt(SizeType start, const OdUInt8 *buffer, SizeType bufferSize) = 0;

  /** Description:
    Returns the number of bytes in this ByteData object.
  */
  virtual SizeType size() const = 0;
  /** Description:
    Resizes this ByteData object.
    Arguments:
    bufferSize (I) Number of bytes.
  */
  virtual void resize(SizeType bufferSize) = 0;

  /** Description:
    Empties this ByteData object.
  */
  virtual void flush() = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdByteData object pointers.
*/
typedef OdSmartPtr<OdByteData> OdByteDataPtr;


/** Description:
    This class implements OdError objects with access to their associated ErrorContext objects.
    
    Library: TD_Db
    {group:Error_Classes} 
*/
class OdOleStorageError : public OdError
{
public:
  /** Arguments:
    pErrorContext (I) Pointer to the ErrorContext.
  */
  OdOleStorageError(OdErrorContext* pErrorContext) : OdError(pErrorContext) { }
};

class OdOleStorage;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdOleStorage object pointers.
*/
typedef OdSmartPtr<OdOleStorage> OdOleStoragePtr;

/** Description:
    This class is the base class for custom classes that implement OLE storage.

    Library: TD_Db
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdOleStorage : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdOleStorage);

  /** Description:
    Initializes this OleStorage object.
    Arguments:
    pByteData (I) Pointer to the OdByteData for this OleStorage object.
    accessMode (I)  Mode in which to open this OleStorage object.
    
    Remarks:
    accessMode must be a combination of one or more of the following:
    
    @table
    Name                Value          Description
    Oda::kFileRead      0x80000000     Read access.
    Oda::kFileWrite     0x40000000     Write access.
  */
  virtual void init(OdByteData* pByteData, int accessMode = Oda::kFileRead) = 0;

  /** Description:
    Returns the raw OdByteData for this OleStorage object.
  */
  virtual OdByteDataPtr rawData() const = 0;

  /** Description:
    Opens an OdStreamBuf for this OleStorage object. For internal use only.
    
    Arguments:
    filename (I) Filename.
    accessMode (I)  Mode in which to open this OleStorage object.
    createIfNotFound (I) Controls the creation of the file if it does not exist.
    
    Remarks:
    Returns a SmartPointer for the newly created OdStreamBuf object.

    accessMode must be a combination of one or more of the following:
    
    @table
    Name                Value          Description
    Oda::kFileRead      0x80000000     Read access.
    Oda::kFileWrite     0x40000000     Write access.
    
    Note:
    createIfNotFound is for Teigha internal use only, and should always be false for Teigha applications.

  */
  virtual OdStreamBufPtr openStream(const OdString &filename,
                                    bool createIfNotFound = false,
                                    int accessMode = Oda::kFileRead) = 0;
                                    
  /** Description:
    Creates a service object for this OleStorage object.
    Arguments:
    pInitData (I) Pointer to the initial data.
  */
  static OdOleStoragePtr createServiceObject(OdByteData* pInitData);
};

#define ODRX_OLESTORAGE_SERVICE_NAME OdOleStorage::desc()->name()

#include "TD_PackPop.h"

#endif // _ODSTORAGE_INCLUDED_
