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




// MemoryStream.h: interface for the OdMemoryStreamImpl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_MEMORYSTREAM_H_INCLUDED_)
#define _MEMORYSTREAM_H_INCLUDED_



#include "OdStreamBuf.h"

#include "TD_PackPush.h"

class OdMemoryStream;
typedef OdSmartPtr<OdMemoryStream> OdMemoryStreamPtr;

/** Description:
    This class defines the interface for paged-memory I/O objects. 
    
    Library: TD_Root

    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdMemoryStream : public OdStreamBuf
{
protected:
  OdMemoryStream();
public:
  ODRX_DECLARE_MEMBERS(OdMemoryStream);
  
  /** Description:
    Creates a new MemoryStream object, and returns a SmartPointer to the new object.
    Arguments:
    pageSize (I) PageDataSize.
  */
  static OdMemoryStreamPtr createNew(OdUInt32 pageDataSize = 0x800);
  /** Description:
    Returns the PageDataSize for this MemoryStream object.
  */
  virtual OdUInt32 pageDataSize() const = 0;

  /** Description:
    Sets the PageDataSize for this MemoryStream object.
    Arguments:
    pageDataSize (I) PageDataSize.
  */
  virtual void setPageDataSize(OdUInt32 pageDataSize) = 0;

  /** Description:
    Reserves the specified number of bytes for this MemoryStream object.
  */
  virtual void reserve(OdUInt64 numBytes) = 0;

  /** Description:
    Returns a unique file name to be associated with this MemoryStream object.
  */
  OdString fileName();
};

#include "TD_PackPop.h"

#endif // !defined(_MEMORYSTREAM_H_INCLUDED_)

