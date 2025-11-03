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




#ifndef ODDB_XRECORD_H
#define ODDB_XRECORD_H /* {Secret} */

#include "TD_PackPush.h"

#define ODDB_XRECORD_CLASS          "OdDbXrecord"

#include "DbObject.h"
#include "DbFiler.h"

class OdDbXrecordIteratorImpl;

/** Description:
    This class implements Iterators for the data lists in OdDbXrecord instances.  

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXrecordIterator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbXrecordIterator);
  OdDbXrecordIterator(const OdDbXrecord* pXrecord);
  virtual ~OdDbXrecordIterator();

  /** Description:
    Sets this Iterator object to reference the first ResBuf structure in the XRecord data list.
     
    Remarks:
    Allows multiple traversals of the data list.
  */  
  void start();

  /** Description:
    Returns true if and only if the traversal is complete.
  */  
  bool done() const;
 
  /** Description:
    Sets this Iterator object to reference the *next* ResBuf structure in the XRecord data list.

    Remarks:
    Returns true if and only if not at the end of the list.
 */ 
  OdResult next(); 
  
  /** Description:
    Returns the restype field of the current ResBuf structure in the XRecord data list.
  */
  int curRestype() const;
  
  /** Description:
    Returns a copy of the current ResBuf structure in the XRecord data list.
    Arguments:
    pDb (I) Pointer to the OdDbDatabase used for Object ID resolution when this XRecord object is not *database* resident.
  */
  OdResBufPtr getCurResbuf(OdDbDatabase* pDb = 0) const;

  OdResult getCurResbuf( 
	  resbuf& outItem,
	  OdDbDatabase* pDb = 0) const;
  
protected:
  OdDbXrecordIterator(
    OdDbXrecordIteratorImpl* pIterImpl);
  OdDbXrecordIteratorImpl* m_pImpl;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbXrecordIterator object pointers.
*/
typedef OdSmartPtr<OdDbXrecordIterator> OdDbXrecordIteratorPtr;


/** Description:
    This class implements XRecord objects in an OdDbDatabase, container objects
    used attach arbitrary data to other OdDb objects.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXrecord : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbXrecord);

  OdDbXrecord();
  virtual ~OdDbXrecord();
  
  /** Description:
    Returns a copy of the ResBuf list owned by the XRecord object.

    Arguments:
    pDb (I) Pointer to the OdDbDatabase used for Object ID resolution when this XRecord object is not *database* resident.
    pStatus (I) Pointer an OdResult to receive the status. 
    
    Remarks:
    If pStatus != NULL, returns eOk if successful, or an appropriate error code if not.
*/
  OdResBufPtr rbChain(
    OdDbDatabase* pDb = 0, 
    OdResult* pStatus = 0) const;

  OdResult rbChain( 
	resbuf** ppRb,  
  OdDbDatabase* pDb = 0);

  /** Description:
    Returns an Iterator object that can be used to traverse this XRecord object.


    Remarks:
    This method can be faster than using rbChain()

    Arguments:
    pDb (I) Pointer to the OdDbDatabase used for Object ID resolution when this XRecord object is not *database* resident.
  */
  OdDbXrecordIteratorPtr newIterator(
    OdDbDatabase* pDb = 0) const;

  /** Description:
    Sets the data in this XRecord object to the data in the specified ResBuf chain. 
    Arguments:
    pDb (I) Pointer to the OdDbDatabase used for Object ID resolution when this XRecord object is not *database* resident.
    pRb (I) Pointer to the first ResBuf in the ResBuf chain.
  */
  void setFromRbChain(const OdResBuf* pRb, OdDbDatabase* pDb = 0);

  OdResult setFromRbChain( 
	  const resbuf& pRb, OdDbDatabase* pDb = 0);

  /** Description:
    Appends the data in the specified ResBuf chain to the data in this XRecord.

    Arguments:
    pRb (I) Pointer to the first ResBuf in the ResBuf chain.
    pDb (I) Pointer to the OdDbDatabase used for Object ID resolution when this XRecord object is not *database* resident.
  */
  void appendRbChain(
    const OdResBuf* pRb, 
    OdDbDatabase* pDb = 0);

  /** Description:
    Returns true if and only if this XRecord object is set to translate 
    data chain Object IDs during subDeepClone() and subWblockClone() operations.
  */
  bool isXlateReferences() const;

  /** Description:
    Controls if this XRecord object is to translate 
    data chain Object IDs during subDeepClone() and subWblockClone() operations.

    Arguments:
    xlateReferences (I) Translate references, if and only if true. 
  */
  void setXlateReferences(
    bool isXlateReferences);
	
  virtual OdResult subClose();
  
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields( 
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  /** Description:
      Returns the merge *style* for this XRecord object (DXF 280).
  */
  virtual OdDb::DuplicateRecordCloning mergeStyle() const;

   /** Description:
      Sets the merge *style* for this XRecord object (DXF 280).
      
      Arguments:
      mergeStyle (I) Merge *style*.
  */
  virtual void setMergeStyle(
    OdDb::DuplicateRecordCloning mergeStyle);
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  enum
  {
    kOpenExisting     = 0,
    kCreateIfNotFound = 1
  };

  /** Description:
    Opens for writing the specified XRecord object of the specified OdDbObject. 
    Arguments:
    creationFlag (I) Creation flag. 
    pObject (I) Pointer to the Object.
    key (I) XRecord key.
    keys (I) Array of XRecord keys defining the path to the XRecord.
    mergeStyle (I) Merge *style*.
    Remarks:
    Returns a SmartPointer to the opened XRecord, or NULL if the specified XRecord object
    does not exist and creationFlag == kOpenExisting. 
    
    creationFlag must be one of the following:
    
    @table
    Name                  Value
    kOpenExisting         0
    kCreateIfNotFound     1
    
  */
  static OdDbXrecordPtr open(OdDbObject* pObject, const OdString &key,
    int creationFlag = kOpenExisting,
    OdDb::DuplicateRecordCloning mergeStyle = OdDb::kDrcIgnore);

  static OdDbXrecordPtr open(OdDbObject* pObject, const OdArray<OdString> &keys,
    int creationFlag = kOpenExisting,
    OdDb::DuplicateRecordCloning mergeStyle = OdDb::kDrcIgnore);
};

#include "TD_PackPop.h"

#endif //ODDB_XRECORD_H

