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




#ifndef _ODDBSYMBOLTABLERECORD_INCLUDED
#define _ODDBSYMBOLTABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbObject.h"

class OdString;
class OdDbSymbolTable;

/** Description:
  This class is the base class for all SymbolTableRecord objects in an OdDbDatabase instance.
  
  Library: TD_Db
  
  {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSymbolTableRecord : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSymbolTableRecord);

protected:
  OdDbSymbolTableRecord();

public:
  virtual ~OdDbSymbolTableRecord();

  typedef OdDbSymbolTable TableType;
  /** Description:
    Returns the *name* of this Record object (DXF 2).
  */
  virtual OdString getName() const;

  OdResult getName ( // 派生类无需重新实现
    OdChar*& pName) const;
  OdResult getName ( // 派生类无需重新实现
    const OdChar*& pName) const;
  OdResult getName ( // 派生类无需重新实现
    OdString& sName) const;
  /** Description:
    Sets the *name* for this Record object (DXF 2).

    Arguments:
    name (I) Record *name*.
  */
  virtual OdResult setName(const OdChar* name);

  /** Description:
    Returns true if and only if this Record object is Xref dependent (DXF 70, bit 0x10).
  */
  bool isDependent() const;

  /** Description:
    Returns true if and only if this Record object is Xref dependent and resolved (DXF 70, bit 0x20).
  */
  bool isResolved() const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  void appendToOwner(
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  /** Description:
      Copies the contents of other into the messaged object, whenever feasible
  */
  virtual OdResult copyFrom(
    const OdRxObject* pSource);

  virtual OdResult subErase(
    OdBool erasing);

  virtual void subSwapIdWith(
    const OdDbObjectId& otherId, 
    bool swapXdata = false, 
    bool swapExtDict = false);
  //说明：用于refedit编辑外部参照
	virtual OdResult subWblockClone(OdRxObject* pOwnerObject,
	  OdDbObject*& pClonedObject,
	  OdDbIdMapping& idMap,
	  OdBool isPrimary) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSymbolTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbSymbolTableRecord> OdDbSymbolTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBSYMBOLTABLERECORD_INCLUDED

