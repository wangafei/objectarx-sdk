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




#ifndef _OD_DB_BLOCK_END_
#define _OD_DB_BLOCK_END_

#include "TD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class represents BlockEnd entities in an OdDbDatabase instance.  
    
    Remarks:
    OdDbBlockEnd entities are automatically created and handled by Teigha for
    each AcDbBlockTableRecord object.
     
    Client applications may add extended data or extension dictionaries to these 
    entities, but should not create or delete them.
    
    These entities have no associated geometries.

    Note:
    Do not derive from this class.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbBlockEnd : public OdDbEntity
{
public:
  
  ODDB_DECLARE_MEMBERS(OdDbBlockEnd);

  OdDbBlockEnd();
  ~OdDbBlockEnd();

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  /**
    Note:
    Always returns eInvalidExtents.
  */
  virtual OdResult subGetGeomExtents(// Gcad(Modify)
    OdDbExtents& extents) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBlockEnd object pointers.
*/
typedef OdSmartPtr<OdDbBlockEnd> OdDbBlockEndPtr;

#include "TD_PackPop.h"

#endif
