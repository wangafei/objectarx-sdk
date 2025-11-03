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



#ifndef _ODDBPAGECONTROLLER_INCLUDED_
#define _ODDBPAGECONTROLLER_INCLUDED_

#include "RxObject.h"

class OdDbDatabase;
class OdDbObjectId;
class OdStreamBuf;
typedef OdSmartPtr<OdStreamBuf> OdStreamBufPtr;

/** Description:

    {group:TD_Namespaces}
*/
namespace OdDb
{
  /** Description:
      Flags that can be combined together (bit-wise) to describe a desired paging
      behavior.

      See Also:

      o OdDbPageController
      o odDbPageObjects
      o Paging Support
  */
  enum PagingType
  {
    /** Remarks
        Enables unloading of objects in a partially opened OdDbDatabase instance.  
        
        Closed objects will be unloaded from memory 
        during the next call to odDbPageObjects.  This behavior can be useful in environments
        with limited heap space (such as Windows CE).
    */
    kUnload  = 0x01,  
    /** Remarks:
        Enables paging of objects in an OdDbDatabase instance.

        Closed Objects will be paged out during the next call to OdDbPageObjects.  
        Paging will be implemented via a client-supplied OdDbPageController instance.
    */
    kPage    = 0x02   
  };
}

/** Description:
    This class controls the paging support for an OdDbDatabase instance.

    See Also:

    o Paging Support
    o odDbPageObjects

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPageController : public OdRxObject
{
public:
  typedef unsigned long Key;

  /** Description:
    Returns the paging type for this PageController object.
      
    Remarks:
    pagingType() returns a combination of zero or more of the following:
    
    @table
    Name            Value   Description
    OdDb::kUnload   0x01    Enable unloading for objects in a partially opened OdDbDatabase instance.  
    OdDb::kPage     0x02    Enable paging for objects in an OdDbDatabase instance.
    See Also:

    o Paging Support
  */
  virtual int pagingType() const = 0;

  /** Description:
    Pages in the specified data.
    
    Remarks:
    Returns a SmartPointer to an OdDbStreamBuf object containing the specified paged data from a client-supplied data source.
      
    Arguments:
    key (I) Paged data *key*, as returned by write().
  */
  virtual OdStreamBufPtr read(Key key) = 0;

  /** Description:
    Pages out data as required to a client-supplied data source.

    Arguments:
    key (O) Paged data *key*, as used by read().
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be written.

    Remarks:
    Returns true if and only if the PageController implementation has successfully paged the data.

    Note:
    Implementations of this function are expected to write the entire contents of pStreamBuf
    to an external data source, and to set assign a unique value to the *key* argument that 
    identifies this chunk of paged data.  This *key* value will be used in a subsequent calls
    to read() to retrieve this specific paged data.
  */
  virtual bool write(Key& key, OdStreamBuf* pStreamBuf) = 0;

  /** Description:
    Sets the OdDbDatabase instance served by this controller.

    Arguments:
    pDb (I) Pointer to the *database*.
    Remarks:
    The method is called by Teigha during initialization of *database* paging.
  */
  virtual void setDatabase(OdDbDatabase* pDb) = 0;

  /** Description:
      Returns the OdDbDatabase instance served by this controller.
  */
  virtual OdDbDatabase* database() = 0;

  /** Description:
    The method is called during unloading/paging of an object,
    before anything else is done.

    Arguments:
    objectId (I) Object ID.
    Remarks:
    subPage() returns one of the of the following:
    
    @table
    Name              Description
    eOk               Continue paging.
    eSkipObjPaging    Skip paging of the specified object.
    eStopPaging       Stop paging.
      
    Note:
    The default implementation does nothing but return eOk. This function can be
    overridden in custom classes.
  */
  virtual OdResult subPage(const OdDbObjectId& objectId);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPageController object pointers.
*/
typedef OdSmartPtr<OdDbPageController> OdDbPageControllerPtr;

/** Description:
    Pages the *database* objects for the specified OdDbDatabase instance that have been marked for 
    paging since the last call to this function.  
    
    Remarks:
    See Paging Support for details.
    
    Arguments:
    pDb (I) Pointer to the *database*.
*/
TOOLKIT_EXPORT void odDbPageObjects(OdDbDatabase* pDb);

#endif // _ODDBPAGECONTROLLER_INCLUDED_



