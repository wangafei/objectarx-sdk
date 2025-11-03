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




#ifndef OD_DBPROXY_H
#define OD_DBPROXY_H

#include "TD_PackPush.h"

#include "DbObject.h"
#include "IntArray.h"

/** Description:
    This class is the abstract base class for Proxy objects in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbProxyObject : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbProxyObject);

  OdDbProxyObject();
  virtual ~OdDbProxyObject() {};

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields( // Gcad(Modify)
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields( // Gcad(Modify)
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfIn(OdDbDxfFiler* filer);

  /** Description:
    Returns the edit flags for the class contained in this Proxy object.
    Remarks:
    proxyFlags() returns a combination of one or more of the following:
    
    @table
    Name                     Value    Description
    kNoOperation             0x0      None
    kEraseAllowed            0x1      erase()
    kCloningAllowed          0x80     subDeepClone(), subWblockClone()
    kAllButCloningAllowed    0x1      erase()
    kAllAllowedBits          0x81     erase(), subDeepClone(), subWblockClone()
    kMergeIgnore             0x00     Keep orignal names.
    kMergeReplace            0x100    Use clone.
    kMergeMangleName         0x200    Create anonymous name.
  */
  int proxyFlags() const;

  /** Description:
    Returns the class name of the object represented by this Proxy object.
  */
  virtual const OdChar* originalClassName() const; // Gcad(Modify)

  /** Description:
    Returns the DXF name of the object represented by this Proxy object.
  */
  virtual const OdChar* originalDxfName() const; // Gcad(Modify)

  /** Description:
    Returns the application description of the object represented by this Proxy object.
  */
  virtual const OdChar* applicationDescription() const; // Gcad(Modify)

  /** Description:
    Returns an array of the Object IDs referenced by this Proxy object.

    Arguments:
    objectIds (O) Receives an array of the reference Object IDs.
  */
  OdResult getReferences( // Gcad(Modify)
    OdTypedIdsArray& objectIds) const;

  OdResult getReferences( // Gcad(Add)
	  OdDbObjectIdArray& objctIds,
	  OdIntArray& refTypes) const;

  OdDb::DuplicateRecordCloning mergeStyle() const;

    virtual OdResult subWblockClone(OdRxObject* pOwnerObject,OdDbObject*& pClonedObject,OdDbIdMapping& idMap,bool isPrimary = true) const;  
    virtual OdResult subDeepClone(OdDbObject* pOwnerObject,OdDbObject*& pClonedObject,OdDbIdMapping& idMap, bool isPrimary = true) const;

  enum
  {
    kNoOperation          = 0, 
    kEraseAllowed         = 0x1, 
    kCloningAllowed       = 0x80,
    kAllButCloningAllowed = 0x1, 
    kAllAllowedBits       = 0x81, 
    kMergeIgnore          = 0,      
    kMergeReplace         = 0x100,  
    kMergeMangleName      = 0x200,
    kDisableProxyWarning  = 0x400
  };

  /** Description:
    Returns true if and only if the erase() method is allowed for this Proxy entity. 
  */
  bool eraseAllowed() const               { return GETBIT(proxyFlags(), kEraseAllowed); }
  /** Description:
    Returns true if and only if all but the subDeepClone() and subWblockClone() methods are allowed for this Proxy object.
  */
  bool allButCloningAllowed() const       { return (proxyFlags() & kAllAllowedBits) == (kAllAllowedBits ^ kAllButCloningAllowed); }

  /** Description:
    Returns true if and only if the subDeepClone() and subWblockClone() methods are allowed for this Proxy object.
  */
  bool cloningAllowed() const             { return GETBIT(proxyFlags(), kCloningAllowed); }

  /** Description:
    Returns true if and only if all methods are allowed for this Proxy entity. 

    Remarks:
    The allowed methods are as follows
    
    @untitled table
    subDeepClone()
    erase()
    subWblockClone()
  */
  bool allOperationsAllowed() const       { return (proxyFlags() & kAllAllowedBits) == kAllAllowedBits; }

  /** Description:
    Returns true if and only this Proxy entity is a R13 format Proxy object. 
  */
  bool isR13FormatProxy() const           { return GETBIT(proxyFlags(), 32768); }

  virtual OdResult subErase(
    OdBool erasing);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbProxyObject object pointers.
*/
typedef OdSmartPtr<OdDbProxyObject> OdDbProxyObjectPtr;

#include "TD_PackPop.h"

#endif // OD_DBPROXY_H

